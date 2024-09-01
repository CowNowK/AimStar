#pragma once
#include "..\..\Entity.h"
#include "..\..\Game.h"
#include "..\..\Utils\BytesManager.h"

namespace SilentAim
{
	inline DWORD64 offset = 0x25FF;
	inline DWORD64 AngleAddress = 0;
	inline DWORD64 NewMemAddress = 0;
	inline DWORD64 HookAddress = 0;
	inline DWORD64 OpenAddress = 0;
	inline bool IsEnable = false;
	inline Bytes OriginCode{ 0xF3, 0x41, 0x0F, 0x10, 0x46, 0x18, 0x89, 0x41, 0x10, 0xF3, 0x0F, 0x11, 0x41, 0x20 };

	inline void Enable()
	{
		int on = 1;

		if (OpenAddress == 0)
			return;
		if (!IsEnable)
		{
			ProcessMgr.WriteMemory(OpenAddress, on);
			IsEnable = true;
		}
	}

	inline void Disable()
	{
		int off = 0;

		if (OpenAddress == 0)
			return;
		if (IsEnable)
		{
			ProcessMgr.WriteMemory(OpenAddress, off);
			IsEnable = false;
		}
	}

	inline bool Hook()
	{
		HookAddress = gGame.GetClientDLLAddress() + offset;
		DWORD64 ReturnAddress = HookAddress + 14;

		if (HookAddress == 0)
			return false;

		Bytes JmpCode;

		if (NewMemAddress == 0)
		{
			NewMemAddress = (DWORD64)VirtualAllocEx(ProcessMgr.hProcess, NULL, 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			AngleAddress = NewMemAddress + 0x50;
			OpenAddress = NewMemAddress + 0x70;
		}

		if (NewMemAddress == 0)
			return false;

		/*
		client.dll+85519C - FF25 00000000 00004B1695020000 - jmp 295164B0000
		*/
		JmpCode = Bytes{ 0xFF,0x25,0x00,0x00 ,0x00 ,0x00 } + Bytes((long long)NewMemAddress);

		/*
		83 3D 69000000 00     - cmp dword ptr [29D77F40070],00
		0F84 22000000         - je 29D77F4002F
		F3 41 0F10 4F 08      - movss xmm1,[r15+08]
		F3 0F11 41 18         - movss [rcx+18],xmm0
		F3 0F11 49 1C         - movss [rcx+1C],xmm1
		4D 31 FF              - xor r15,r15
		F3 41 0F10 46 18      - movss xmm0,[r14+18]
		89 41 10              - mov [rcx+10],eax
		F3 0F11 41 20         - movss [rcx+20],xmm0
		FF25 00000000 AA51B5B2FB7F0000 - jmp client.dll+8551AA
		*/

		Bytes ShellCode;
		ShellCode = Bytes{ 0x83,0x3D,0x69,0x00,0x00,0x00,0x00,0x0F,0x84,0x22,0x00,0x00,0x00 };
		ShellCode += Bytes{ 0x49,0xBF } + Bytes((long long)AngleAddress);
		ShellCode += Bytes{ 0xF3, 0x41, 0x0F, 0x10, 0x07 };
		ShellCode += Bytes{ 0xF3, 0x41, 0x0F, 0x10, 0x4F, 0x08 };
		ShellCode += Bytes{ 0xF3, 0x0F, 0x11, 0x41, 0x18 };
		ShellCode += Bytes{ 0xF3, 0x0F, 0x11, 0x49, 0x1C };
		ShellCode += Bytes{ 0x4D, 0x31, 0xFF };
		ShellCode += Bytes{ 0xF3, 0x41, 0x0f, 0x10, 0x46, 0X18 };
		ShellCode += Bytes{ 0x89, 0x41, 0x10 };
		ShellCode += Bytes{ 0xF3, 0x0F, 0x11, 0x41, 0x20 };
		ShellCode += Bytes{ 0xFF, 0x25, 0x00, 0x00, 0x00, 0x00 } + Bytes((long long)ReturnAddress);

		byte* Data;

		Data = ShellCode.GetData();
		WriteProcessMemory(ProcessMgr.hProcess, (LPVOID)NewMemAddress, Data, ShellCode.Length(), 0);
		delete[] Data;

		Data = JmpCode.GetData();
		WriteProcessMemory(ProcessMgr.hProcess, (LPVOID)HookAddress, Data, JmpCode.Length(), 0);
		delete[] Data;

		return true;
	}

	inline bool UnHook()
	{
		if (HookAddress == 0 || NewMemAddress == 0)
			return true;

		byte* Data = OriginCode.GetData();
		if (!WriteProcessMemory(ProcessMgr.hProcess, (LPVOID)HookAddress, Data, OriginCode.Length(), 0))
			return false;
		delete[] Data;

		return true;
	}

	inline bool ReleaseHook()
	{
		if (!UnHook())
			return false;
		if (!VirtualFreeEx(ProcessMgr.hProcess, (LPVOID)NewMemAddress, 0x100, MEM_DECOMMIT))
			return false;

		NewMemAddress = 0;
		AngleAddress = 0;

		return true;
	}

	inline void Aim(Vec2 AimAngle)
	{
		if (AngleAddress == 0)
			return;
		ProcessMgr.WriteMemory<float>(AngleAddress, AimAngle.x);
		ProcessMgr.WriteMemory<float>(AngleAddress + 8, AimAngle.y);
	}

}

namespace AimControl
{
	inline bool silent = false;
}