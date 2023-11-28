#pragma once
#include <Windows.h>
#include <string>
#include <time.h>

#include "..\OS-ImGui\imgui\imgui.h"
#include "..\Utils\GlobalVars.h"
#include "..\MenuConfig.hpp"
#include "..\AimBot.hpp"
#include "..\Entity.h"

#pragma comment(lib, "winmm.lib")

namespace Misc
{
	// Convert std::string into std::wstring
	static inline std::wstring STR2LPCWSTR(const std::string& str)
	{
		int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
		std::wstring result(size, L'\0');
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &result[0], size);
		return result;
	}

	static inline void CheatText(const char* Cheat, bool config)
	{
		if (config)
			ImGui::Text(Cheat);
	}

	static inline void getCurrentTime(struct tm* ptm) {
		time_t now = time(NULL);
		localtime_s(ptm, &now);
	}

	void CheatList() noexcept;
	void Watermark() noexcept;
	void HitSound(const CEntity& aLocalPlayer, int& PreviousTotalHits) noexcept;
	void NoFlash(const CEntity& aLocalPlayer) noexcept;
	void EdgeJump(const CEntity& aLocalPlayer) noexcept;

	void Invincible(const CEntity& Player) noexcept;
}