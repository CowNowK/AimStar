#pragma once
#include <chrono>
#include <thread>

#include "Game.h"
#include "Entity.h"
#include "MenuConfig.hpp"

namespace TriggerBot
{
	inline int TriggerDelay = 90; // ms
	inline int FakeShotDelay = 200; // ms
	inline bool ScopeOnly = false;
	inline bool IgnoreFlash = false;
	inline int HotKey = VK_LMENU;
	inline std::vector<int> HotKeyList{VK_LMENU, VK_RBUTTON, VK_XBUTTON1, VK_XBUTTON2, VK_CAPITAL, VK_LSHIFT, VK_LCONTROL};

	inline void SetHotKey(int Index)
	{
		HotKey = HotKeyList.at(Index);
	}

	// Triggerbot
	void ReleaseMouseButton();
	void Run(const CEntity& LocalEntity);
	void TargetCheck(const CEntity& LocalEntity) noexcept;
}