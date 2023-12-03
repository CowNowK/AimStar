#pragma once
#include "MenuConfig.hpp"
#include "Entity.h"

namespace Bunnyhop
{
	inline bool AirCheck(const CEntity& Local)
	{
	const bool hasFlagInAir = Local.Pawn.HasFlag(PlayerPawn::Flags::IN_AIR);
	return hasFlagInAir;
	}

	inline void Run(const CEntity& Local)
	{
		if (!MenuConfig::Misc.BunnyHop)
			return;

		if (GetAsyncKeyState(VK_SPACE) && AirCheck(Local))
		{
			gGame.SetForceJump(65537);
		}
		else if (GetAsyncKeyState(VK_SPACE) && !AirCheck(Local))
		{
			gGame.SetForceJump(256);
			gGame.SetForceJump(65537);
			gGame.SetForceJump(256);
		}
		else
		{
			gGame.SetForceJump(256);
		}
	}
}
