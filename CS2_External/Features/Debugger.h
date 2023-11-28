#pragma once

#include "..\OS-ImGui\imgui\imgui.h"
#include "..\MenuConfig.hpp"

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
}
