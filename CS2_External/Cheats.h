#pragma once
#include "Game.h"
#include "Entity.h"
#include "Features\Aimbot\Legitbot.hpp"
#include "Features\Aimbot\Ragebot.hpp"
#include "Radar/Radar.h"
#include "TriggerBot.h"

#include "Features/Glow.h"
#include "Features/Misc.h"
#include "Features/HUD.h"

namespace Cheats
{
	void KeyCheckThread() noexcept;

	void RenderCrossHair(ImDrawList* drawList) noexcept;

	void SignatureMutation() noexcept;

	void FastBypass() noexcept;

	bool AntiTKMAC(const INT64 hash) noexcept;

	void RenderESP(CEntity Entity, DWORD64 EntityAddress, CEntity LocalEntity, int LocalPlayerControllerIndex, int index) noexcept;

	void RadarSetting(Base_Radar& Radar) noexcept;

	void Run() noexcept;
}

struct {
	ImFont* normal15px = nullptr;
} fonts;