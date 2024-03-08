#pragma once
#include <thread>
#include <mutex>
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

	void espThread(CEntity Entity, CEntity LocalEntity, int LocalPlayerControllerIndex, DWORD64 EntityAddress, int LoopIndex);
	void AimbotThread(CEntity& LocalEntity, std::vector<Vec3>& AimPosList);
	void MiscThread(CEntity& LocalEntity);
}

struct {
	ImFont* normal15px = nullptr;
} fonts;