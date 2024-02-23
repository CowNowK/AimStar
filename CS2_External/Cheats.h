#pragma once
#include "Game.h"
#include "Entity.h"
#include "Features\Aimbot\Legitbot.hpp"
#include "Features\Aimbot\Ragebot.hpp"
#include "Radar/Radar.h"
#include "TriggerBot.h"

#include "Features/Glow.h"
#include "Features/Misc.h"

namespace Cheats
{
	void KeyCheckThread();

	void RenderCrossHair(ImDrawList* drawList) noexcept;

	void RadarSetting(Base_Radar& Radar);

	void Run();
}

struct {
	ImFont* normal15px = nullptr;
} fonts;