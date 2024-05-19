#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <Tlhelp32.h>
#include <atlconv.h>
#include "driver.hpp"

#define _is_invalid(v) if(v==NULL) return false
#define _is_invalid(v,n) if(v==NULL) return n
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

namespace MenuConfig {
    extern bool SafeMode;
}
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
		driver.initdriver(ProcessID);
		std::cout << (uintptr_t)driver.client_address();

		hProcess = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_CREATE_THREAD, TRUE, ProcessID);
		_is_invalid(hProcess, FAILE_HPROCESS);

		Attached = true;

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
		ReadType buffer;
		driver.readsize((uintptr_t)Address, &Value, sizeof(ReadType));
		return true;
	}

	template <typename ReadType>
	bool ReadMemory(DWORD64 Address, ReadType& Value)
	{
		ReadType buffer;
		driver.readsize((uintptr_t)Address, &Value, sizeof(ReadType));
		return true;
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
		driver.write((uintptr_t)Address, Value);
		return true;
	}

	template <typename ReadType>
	bool WriteMemory(DWORD64 Address, ReadType& Value)
	{
		driver.write((uintptr_t)Address, Value);
		return true;
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
		if (ModuleName == "client.dll") {
			return (HMODULE)driver.client_address();
		}
		else if (ModuleName == "engine2.dll" || ModuleName == "engine.dll") {
			return (HMODULE)driver.engine_address();
		}
		else {
			return (HMODULE)driver.client_address();
		}
	}

};

inline ProcessManager ProcessMgr;
