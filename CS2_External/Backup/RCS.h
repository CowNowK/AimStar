#pragma once
#include <math.h>
#include "..\Entity.h"
#include "..\View.hpp"
#include "..\MenuConfig.hpp"

namespace RCS
{
	inline int RCSBullet = 1;

	inline void GetAngles(const CEntity& Local, Vec2& Angles)
	{
		auto oldPunch = Vec2{ };
		auto shotsFired = Local.Pawn.ShotsFired;

		int ScreenCenterX = Gui.Window.Size.x / 2;
		int ScreenCenterY = Gui.Window.Size.y / 2;

		if (shotsFired)
		{
			uintptr_t clientState;
			auto viewAngles = Local.Pawn.ViewAngle;
			auto aimPunch = Local.Pawn.AimPunchAngle;

			auto newAngles = Vec2
			{
				viewAngles.x + oldPunch.x - aimPunch.x * 2.f,
				viewAngles.y + oldPunch.y - aimPunch.y * 2.f,
			};

			if (newAngles.x > 89.f)
				newAngles.x = 89.f;

			if (newAngles.x < -89.f)
				newAngles.x = -89.f;

			while (newAngles.y > 180.f)
				newAngles.y -= 360.f;

			while (newAngles.y < -180.f)
				newAngles.y += 360.f;

			newAngles.x += ScreenCenterX;
			newAngles.y += ScreenCenterY;
			Angles = newAngles;
		}
		else
		{
			oldPunch.x = oldPunch.y = 0.f;
		}
	}

	inline void SetAngles(const CEntity& Local, Vec2& AimAngles, bool isAimbotWorking)
	{
		if (Local.Pawn.ShotsFired > RCSBullet)
		{
			Vec2 PunchAngle;
			if (Local.Pawn.AimPunchCache.Count <= 0 && Local.Pawn.AimPunchCache.Count > 0xFFFF)
				return;
			if (!ProcessMgr.ReadMemory<Vec2>(Local.Pawn.AimPunchCache.Data + (Local.Pawn.AimPunchCache.Count - 1) * sizeof(Vec3), PunchAngle))
				return;

			AimAngles.x = PunchAngle.x;
			AimAngles.y = PunchAngle.y;
		}
	}
}