#pragma once
#include <math.h>
#include "..\Entity.h"
#include "..\View.hpp"
#include "..\MenuConfig.hpp"

namespace RCS
{
	inline int RCSBullet = 1;
	inline Vec2 RCSScale = { 1.f,1.f };

	inline void UpdateAngles(const CEntity& Local, Vec2& Angles)
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
			oldPunch = aimPunch;
		}
		else
		{
			oldPunch.x = oldPunch.y = 0.f;
		}

		if (true/*Local.Pawn.ShotsFired > RCSBullet*/)
		{
			Vec2 PunchAngle;
			if (Local.Pawn.AimPunchCache.Count <= 0 && Local.Pawn.AimPunchCache.Count > 0xFFFF)
				return;
			if (!ProcessMgr.ReadMemory<Vec2>(Local.Pawn.AimPunchCache.Data + (Local.Pawn.AimPunchCache.Count - 1) * sizeof(Vec3), PunchAngle))
				return;

			Angles.x = PunchAngle.x;
			Angles.y = PunchAngle.y;
		}
	}

	inline void RecoilControl(CEntity LocalPlayer)
	{
		if (!MenuConfig::RCS)
			return;

		static Vec2 OldPunch;

		if (LocalPlayer.Pawn.ShotsFired > RCSBullet)
		{
			Vec2 viewAngles = LocalPlayer.Pawn.ViewAngle;
			Vec2 delta = viewAngles - (viewAngles + (OldPunch - (LocalPlayer.Pawn.AimPunchAngle * 2.f)));

			int MouseX = (int)(delta.y / (LocalPlayer.Client.Sensitivity * 0.011f) * RCSScale.x);
			int MouseY = (int)(delta.x / (LocalPlayer.Client.Sensitivity * 0.011f) * RCSScale.y);

			mouse_event(MOUSEEVENTF_MOVE, MouseX, -MouseY, 0, 0);

			OldPunch = LocalPlayer.Pawn.AimPunchAngle * 2.0f;
		}
		else
		{
			OldPunch = Vec2{ 0,0 };
		}
	}
}