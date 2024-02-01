#pragma once

#include <algorithm>
#include <chrono>
#include <sstream>
#include <string>
#include <thread>
#include <time.h>
#include <Windows.h>

#include "..\AimBot.hpp"
#include "..\Entity.h"
#include "..\MenuConfig.hpp"
#include "..\OS-ImGui\imgui\imgui.h"
#include "..\Utils\GlobalVars.h"

#pragma comment(lib, "winmm.lib")

namespace Misc
{
	struct Vector3
	{
		float x, y, z;
		Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	};

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

	// Thanks @PedroGoncalves for the suggestion
	static inline void StopKeyEvent(int WalkKey, bool* KeyStatus, int StopKey, float duration) {
		if (GetAsyncKeyState(WalkKey) & 0x8000) {
			*KeyStatus = true;
		}
		else {
			if (*KeyStatus) {
				keybd_event(StopKey, MapVirtualKey(StopKey, 0), KEYEVENTF_SCANCODE, 0);
				Sleep(50);
				keybd_event(StopKey, MapVirtualKey(StopKey, 0), KEYEVENTF_KEYUP, 0);
				*KeyStatus = false;
			}
		}
	}

	static inline uintptr_t GetSmokeEntity(int i, uintptr_t EntityListEntry) {
		uintptr_t Entity = EntityListEntry + 0x78 * (i + 1);
		return Entity;
	}

	inline bool AirCheck(const CEntity& Local)
	{
		const bool hasFlagInAir = Local.Pawn.HasFlag(PlayerPawn::Flags::IN_AIR);
		return hasFlagInAir;
	}

	void CheatList() noexcept;
	void Watermark() noexcept;
	void HitSound(const CEntity& aLocalPlayer, int& PreviousTotalHits) noexcept;
	void NoFlash(const CEntity& aLocalPlayer) noexcept;
	void FastStop() noexcept;
	void NadeManager(CGame Game) noexcept;
	void RadarHack(const CEntity& EntityList) noexcept;
	void FovChanger(const CEntity& aLocalPlayer) noexcept;
	void MoneyService(const CEntity& EntityList) noexcept;
	void FakeDuck(const CEntity& EntityList) noexcept;
	void BunnyHop(const CEntity& aLocalPlayer) noexcept;

	void JoinDiscord() noexcept;
	void SourceCode() noexcept;
}