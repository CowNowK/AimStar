#pragma once
#include <chrono>
#include <thread>

#include "Game.h"
#include "Entity.h"
#include "MenuConfig.hpp"

namespace TriggerBot
{
	inline int TriggerDelay = 90; // ms
	inline int ShotDuration = 200; // ms
	inline bool ScopeOnly = false;
	inline bool IgnoreFlash = false;
	inline unsigned int HotKey = VK_XBUTTON2;
	inline std::chrono::time_point<std::chrono::system_clock> timepoint = std::chrono::system_clock::now();
	inline std::chrono::time_point<std::chrono::system_clock> startTime = std::chrono::system_clock::now();
	inline bool recorded = false;

	// Triggerbot
	void ReleaseMouseButton();
	void Run(const CEntity& LocalEntity);
	void TargetCheck(const CEntity& LocalEntity) noexcept;
	bool InCrosshairCheck(const CEntity& LocalEntity, const CEntity& TargetEntity) noexcept;
}