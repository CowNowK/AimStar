#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <Tlhelp32.h>
#include <atlconv.h>
#define _is_invalid(v) if(v==NULL) return false
#define _is_invalid(v,n) if(v==NULL) return n
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

typedef struct _CLIENT_ID
{
	PVOID UniqueProcess;
	PVOID UniqueThread;
} CLIENT_ID, * PCLIENT_ID;

typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PWCH   Buffer;
} UNICODE_STRING, *UNICODE_STRING_Ptr;

typedef struct _SYSTEM_HANDLE_TABLE_ENTRY_INFO
{
	ULONG ProcessId;
	BYTE ObjectTypeNumber;
	BYTE Flags;
	USHORT Handle;
	PVOID Object;
	ACCESS_MASK GrantedAccess;
} SYSTEM_HANDLE_TABLE_ENTRY_INFO, * PSYSTEM_HANDLE_TABLE_ENTRY_INFO;


typedef struct _OBJECT_ATTRIBUTES {
	ULONG           Length;
	HANDLE          RootDirectory;
	UNICODE_STRING_Ptr ObjectName;
	ULONG           Attributes;
	PVOID           SecurityDescriptor;
	PVOID           SecurityQualityOfService;
}  OBJECT_ATTRIBUTES, * OBJECT_ATTRIBUTES_Ptr;

typedef struct _SYSTEM_HANDLE_INFORMATION
{
	ULONG HandleCount;
	SYSTEM_HANDLE_TABLE_ENTRY_INFO Handles[1];
} SYSTEM_HANDLE_INFORMATION, * PSYSTEM_HANDLE_INFORMATION;
typedef NTSYSAPI NTSTATUS(NTAPI* FUNC_NtOpenProcess)(PHANDLE ProcessHandle,ACCESS_MASK DesiredAccess,OBJECT_ATTRIBUTES_Ptr ObjectAttributes,PCLIENT_ID ClientId);
typedef NTSTATUS(NTAPI* FUNC_NtQuerySystemInformation)(ULONG SystemInformationClass,PVOID SystemInformation,ULONG SystemInformationLength,PULONG ReturnLength);
typedef NTSTATUS(NTAPI* FUNC_RtlAdjustPrivilege)(ULONG Privilege,BOOLEAN Enable,BOOLEAN CurrentThread,PBOOLEAN Enabled);
typedef NTSTATUS(NTAPI* FUNC_NtDuplicateObject)(HANDLE SourceProcessHandle,HANDLE SourceHandle,HANDLE TargetProcessHandle,PHANDLE TargetHandle,ACCESS_MASK DesiredAccess,ULONG Attributes,ULONG Options);

/// <summary>
/// 进程状态码
/// </summary>
enum StatusCode
{
	SUCCEED,
	FAILE_PROCESSID,
	FAILE_HPROCESS,
	FAILE_MODULE,
};

/// <summary>
/// 进程管理
/// </summary>
class ProcessManager 
{
private:
	bool   Attached = false;

public:

	HANDLE hProcess = 0;
	DWORD  ProcessID = 0;
	DWORD64  ModuleAddress = 0;

public:
	~ProcessManager()
	{
		//if (hProcess)
			//CloseHandle(hProcess);
	}
	SYSTEM_HANDLE_INFORMATION* t_SYSTEM_HANDLE_INFORMATION;
	HANDLE Source_Process = NULL;
	HANDLE target_handle = NULL;
	/// <summary>
	/// 附加
	/// </summary>
	/// <param name="ProcessName">进程名</param>
	/// <returns>进程状态码</returns>
	StatusCode Attach(std::string ProcessName)
	{
		ProcessID = this->GetProcessID(ProcessName);
		_is_invalid(ProcessID, FAILE_PROCESSID);
		ModuleAddress = reinterpret_cast<DWORD64>(this->GetProcessModuleHandle(ProcessName));
		_is_invalid(ModuleAddress, FAILE_MODULE);
		auto ObjectAttributes = [](UNICODE_STRING_Ptr ObjectName, HANDLE RootDirectory, ULONG Attributes, PSECURITY_DESCRIPTOR SecurityDescriptor)->_OBJECT_ATTRIBUTES {
			OBJECT_ATTRIBUTES object;
			object.Length = sizeof(OBJECT_ATTRIBUTES);
			object.Attributes = Attributes;
			object.RootDirectory = RootDirectory;
			object.SecurityDescriptor = SecurityDescriptor;
			object.ObjectName = ObjectName;
			return object;
		};

		FUNC_RtlAdjustPrivilege f_RtlAdjustPrivilege = (FUNC_RtlAdjustPrivilege)GetProcAddress(GetModuleHandleA("ntdll"), "RtlAdjustPrivilege");
		FUNC_NtDuplicateObject f_NtDuplicateObject = (FUNC_NtDuplicateObject)GetProcAddress(GetModuleHandleA("ntdll"), "NtDuplicateObject");
		FUNC_NtOpenProcess f_NtOpenProcess = (FUNC_NtOpenProcess)GetProcAddress(GetModuleHandleA("ntdll"), "NtOpenProcess");
		FUNC_NtQuerySystemInformation f_NtQuerySystemInformation = (FUNC_NtQuerySystemInformation)GetProcAddress(GetModuleHandleA("ntdll"), "NtQuerySystemInformation");




		_OBJECT_ATTRIBUTES R_Attributes = ObjectAttributes(NULL,NULL,NULL,NULL);
		CLIENT_ID t_CLIENT_ID= { 0 };
		boolean OldPriv;

		f_RtlAdjustPrivilege(20, TRUE, FALSE, &OldPriv);

		DWORD Sizeof_SYSTEM_HANDLE_INFORMATION = sizeof(SYSTEM_HANDLE_INFORMATION);

		NTSTATUS NTAPIReturn = NULL;
		
		do {
			delete[] t_SYSTEM_HANDLE_INFORMATION;

			Sizeof_SYSTEM_HANDLE_INFORMATION *= 1.5;

			try
			{
				t_SYSTEM_HANDLE_INFORMATION = (PSYSTEM_HANDLE_INFORMATION) new byte[Sizeof_SYSTEM_HANDLE_INFORMATION];
			}
			catch (std::bad_alloc)
			{

				return FAILE_HPROCESS;
				break;
			}
			Sleep(1);

		} while ((NTAPIReturn = f_NtQuerySystemInformation(16, t_SYSTEM_HANDLE_INFORMATION, Sizeof_SYSTEM_HANDLE_INFORMATION, NULL)) == (NTSTATUS)0xC0000004);

		if (!NT_SUCCESS(NTAPIReturn))
		{
			return FAILE_HPROCESS;
		}

		for (int i = 0; i < t_SYSTEM_HANDLE_INFORMATION->HandleCount; ++i) {
			static int n = i;
			if (n > 100) {
				return FAILE_HPROCESS;
			}

			if (t_SYSTEM_HANDLE_INFORMATION->Handles[i].ObjectTypeNumber != 0x7)
				continue;
			if ((HANDLE)t_SYSTEM_HANDLE_INFORMATION->Handles[i].Handle == INVALID_HANDLE_VALUE)
				continue;

			t_CLIENT_ID.UniqueProcess = (DWORD*)t_SYSTEM_HANDLE_INFORMATION->Handles[i].ProcessId;

			NTAPIReturn = f_NtOpenProcess(&Source_Process,PROCESS_DUP_HANDLE,&R_Attributes,&t_CLIENT_ID);

			if (Source_Process == INVALID_HANDLE_VALUE || !NT_SUCCESS(NTAPIReturn))
				continue;
			NTAPIReturn = f_NtDuplicateObject(Source_Process,(HANDLE)t_SYSTEM_HANDLE_INFORMATION->Handles[i].Handle, (HANDLE)(LONG_PTR)-1,&target_handle,PROCESS_ALL_ACCESS,0,0);
			
			if (target_handle == INVALID_HANDLE_VALUE || !NT_SUCCESS(NTAPIReturn))
				continue;
			
			if (GetProcessId(target_handle) == ProcessID) {
				hProcess = target_handle;
				Attached = true;
				delete[] t_SYSTEM_HANDLE_INFORMATION;
				break;
			}
			else
			{
				CloseHandle(target_handle);
				CloseHandle(Source_Process);
				continue;
			}
			

		}

		return SUCCEED;
	}

	/// <summary>
	/// 取消附加
	/// </summary>
	void Detach()
	{
		if (hProcess)
			CloseHandle(hProcess);
		hProcess = 0;
		ProcessID = 0;
		ModuleAddress = 0;
		Attached = false;
	}

	/// <summary>
	/// 判断进程是否激活状态
	/// </summary>
	/// <returns>是否激活状态</returns>
	bool IsActive()
	{
		if (!Attached)
			return false;
		DWORD ExitCode{};
		GetExitCodeProcess(hProcess, &ExitCode);
		return ExitCode == STILL_ACTIVE;
	}

	/// <summary>
	/// 读取进程内存
	/// </summary>
	/// <typeparam name="ReadType">读取类型</typeparam>
	/// <param name="Address">读取地址</param>
	/// <param name="Value">返回数据</param>
	/// <param name="Size">读取大小</param>
	/// <returns>是否读取成功</returns>
	template <typename ReadType>
	bool ReadMemory(DWORD64 Address, ReadType& Value, int Size)
	{
		_is_invalid(hProcess,false);
		_is_invalid(ProcessID, false);

		if (ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(Address), &Value, Size, 0))
			return true;
		return false;
	}

	template <typename ReadType>
	bool ReadMemory(DWORD64 Address, ReadType& Value)
	{
		_is_invalid(hProcess, false);
		_is_invalid(ProcessID, false);

		if (ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(Address), &Value, sizeof(ReadType), 0))
			return true;
		return false;
	}

	/// <summary>
	/// 写入进程内存
	/// </summary>
	/// <typeparam name="ReadType">写入类型</typeparam>
	/// <param name="Address">写入地址</param>
	/// <param name="Value">写入数据</param>
	/// <param name="Size">写入大小</param>
	/// <returns>是否写入成功</returns>
	template <typename ReadType>
	bool WriteMemory(DWORD64 Address, ReadType& Value, int Size)
	{
		_is_invalid(hProcess, false);
		_is_invalid(ProcessID, false);

		if (WriteProcessMemory(hProcess, reinterpret_cast<LPCVOID>(Address), &Value, Size, 0))
			return true;
		return false;
	}

	template <typename ReadType>
	bool WriteMemory(DWORD64 Address, ReadType& Value)
	{
		_is_invalid(hProcess, false);
		_is_invalid(ProcessID, false);

		if (WriteProcessMemory(hProcess, reinterpret_cast<LPVOID>(Address), &Value, sizeof(ReadType), 0))
			return true;
		return false;
	}

	/// <summary>
	/// 特征码搜索
	/// </summary>
	/// <param name="Signature">特征码</param>
	/// <param name="StartAddress">起始地址</param>
	/// <param name="EndAddress">结束地址</param>
	/// <returns>匹配特征结果</returns>
	std::vector<DWORD64> SearchMemory(const std::string& Signature, DWORD64 StartAddress, DWORD64 EndAddress, int SearchNum = 1);

	DWORD64 TraceAddress(DWORD64 BaseAddress, std::vector<DWORD> Offsets)
	{
		_is_invalid(hProcess,0);
		_is_invalid(ProcessID,0);
		DWORD64 Address = 0;

		if (Offsets.size() == 0)
			return BaseAddress;

		if (!ReadMemory<DWORD64>(BaseAddress, Address))
			return 0;
	
		for (int i = 0; i < Offsets.size() - 1; i++)
		{
			if (!ReadMemory<DWORD64>(Address + Offsets[i], Address))
				return 0;
		}
		return Address == 0 ? 0 : Address + Offsets[Offsets.size() - 1];
	}

public:

	DWORD GetProcessID(std::string ProcessName)
	{
		PROCESSENTRY32 ProcessInfoPE;
		ProcessInfoPE.dwSize = sizeof(PROCESSENTRY32);
		HANDLE hSnapshot = CreateToolhelp32Snapshot(15, 0);
		Process32First(hSnapshot, &ProcessInfoPE);
		USES_CONVERSION;
		do {
			if (strcmp(W2A(ProcessInfoPE.szExeFile), ProcessName.c_str()) == 0)
			{
				CloseHandle(hSnapshot);
				return ProcessInfoPE.th32ProcessID;
			}
		} while (Process32Next(hSnapshot, &ProcessInfoPE));
		CloseHandle(hSnapshot);
		return 0;
	}

	HMODULE GetProcessModuleHandle(std::string ModuleName)
	{
		MODULEENTRY32 ModuleInfoPE;
		ModuleInfoPE.dwSize = sizeof(MODULEENTRY32);
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->ProcessID);
		Module32First(hSnapshot, &ModuleInfoPE);
		USES_CONVERSION;
		do {
			if (strcmp(W2A(ModuleInfoPE.szModule), ModuleName.c_str()) == 0)
			{
				CloseHandle(hSnapshot);
				return ModuleInfoPE.hModule;
			}
		} while (Module32Next(hSnapshot, &ModuleInfoPE));
		CloseHandle(hSnapshot);
		return 0;
	}

};

inline ProcessManager ProcessMgr;