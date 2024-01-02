#pragma once
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h> 
#include <comdef.h>
using namespace std;

namespace Handles
{
	long GetProcessIdFromName(const char* name)
	{
		HANDLE hsnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hsnapshot == INVALID_HANDLE_VALUE)
		{
			cout << "Create TlHelp32 Error!" << endl;
			return -1;
		}

		PROCESSENTRY32 processer;
		processer.dwSize = sizeof(PROCESSENTRY32);

		int flag = Process32First(hsnapshot, &processer);
		while (flag != 0)
		{
			_bstr_t processName(processer.szExeFile);  
			if (strcmp(processName, name) == 0)
			{
				return processer.th32ProcessID;        
			}
			flag = Process32Next(hsnapshot, &processer);
		}

		CloseHandle(hsnapshot);
		return -2;
	}

	int Handle_Close(DWORD Handle)
	{
		HANDLE hHandle = (HANDLE)Handle;
		if (!CloseHandle(hHandle))
		{
			cout << "Close handle failed: " << GetLastError() << endl;
		}
	}

	int Handle_Close(HANDLE hProcess)
	{
		if (!CloseHandle(hProcess))
		{
			cout << "Close handle failed: " << GetLastError() << endl;
		}
	}

	int CloseQueryInfoCheck()
	{
		// Get steam handle
		long pid = GetProcessIdFromName("steam.exe");
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		if (hProcess == NULL)
		{
			cout << "Open process failed: " << GetLastError() << endl;
			return 1;
		}

		// 
		
	}
}

