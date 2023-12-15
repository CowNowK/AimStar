#pragma once
#include "MenuConfig.hpp"
#include "Entity.h"
#include <thread>
#include <chrono>

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

		int ForceJump;
		bool spacePressed = GetAsyncKeyState(VK_SPACE);
		bool isInAir = AirCheck(Local);
		gGame.GetForceJump(ForceJump);

		if (spacePressed && isInAir) // AirCheck = 1, is on ground
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(15));
			gGame.SetForceJump(65537);
		}
		else if (spacePressed && !isInAir) // AirCheck = 0, isn't on ground
		{
			gGame.SetForceJump(256);
		}
		else if (!spacePressed && ForceJump == 65537)
		{
			gGame.SetForceJump(256);
		}
		std::cout << ForceJump << std::endl;
	}
}
