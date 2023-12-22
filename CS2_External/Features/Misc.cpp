#include "Misc.h"
#include "..\Resources\Language.h"
#include <iostream>

namespace Misc
{
	void CheatList() noexcept
	{
		if (!MenuConfig::Misc.CheatList)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::SetNextWindowSize(ImVec2(200, 0));
		ImGui::Begin("Cheats List", nullptr, windowFlags);

		CheatText("ESP", ESPConfig::ESPenbled);
		if (MenuConfig::AimBot && (MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)))
			ImGui::Text("Aimbot [Toggle]");
		CheatText("RCS", MenuConfig::RCS);
		CheatText("Glow", MenuConfig::Misc.Glow);
		CheatText("Radar", MenuConfig::Radar.ShowRadar);
		if (MenuConfig::TriggerBot && (MenuConfig::TriggerAlways || GetAsyncKeyState(MenuConfig::TriggerHotKey)))
			ImGui::Text("TriggerBot [Toggle]");

		CheatText("Crosshair", MenuConfig::Crosshairs.ShowCrossHair);
		CheatText("Headshot Line", MenuConfig::ShowHeadShootLine);
		CheatText("No Flash", MenuConfig::Misc.NoFlash);
		CheatText("Bhop", MenuConfig::Misc.BunnyHop);
		CheatText("HitSound", MenuConfig::Misc.HitSound);
		CheatText("Bomb Timer", MenuConfig::Misc.bmbTimer);
		CheatText("Spec List", MenuConfig::Misc.SpecList);

		ImGui::End();
	}

	void Watermark() noexcept
	{
		if (!MenuConfig::Misc.WaterMark)
			return;

		//	globalvars GV;
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::Begin("Watermark", nullptr, windowFlags);

		static auto FrameRate = 1.0f;
		struct tm ptm;
		//	FrameRate = 0.9f * FrameRate + 0.1f * GV.GetFrameCount();
		FrameRate = ImGui::GetIO().Framerate;
		getCurrentTime(&ptm);

		ImGui::Text("AimStar | %d fps | %02d:%02d:%02d",
			FrameRate != 0.0f ? static_cast<int>(FrameRate) : 0,
			ptm.tm_hour, ptm.tm_min, ptm.tm_sec);
		ImGui::End();
	}

	void HitSound(const CEntity& aLocalPlayer, int& PreviousTotalHits) noexcept
	{
		if (!MenuConfig::Misc.HitSound)
			return;

		std::string soundDir = MenuConfig::SoundPath + "\\Hit.wav";
		std::wstring sound = Misc::STR2LPCWSTR(soundDir);

		uintptr_t pBulletServices;
		int totalHits;
		ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.BulletServices, pBulletServices);
		ProcessMgr.ReadMemory(pBulletServices + Offset::Pawn.TotalHit, totalHits);

		if (totalHits != PreviousTotalHits) {
			if (totalHits == 0 && PreviousTotalHits != 0)
			{
				// `totalHits` changed from non-zero to zero, do not play hitsound
			}
			else
			{
				// Play the HitSound
				PlaySoundW(sound.c_str(), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
		PreviousTotalHits = totalHits;
	}

	void NoFlash(const CEntity& aLocalPlayer) noexcept
	{
		if (!MenuConfig::Misc.NoFlash)
			return;

		float duration = 0.0f;
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.flFlashDuration, duration);
	}

	void EdgeJump(const CEntity& aLocalPlayer) noexcept
	{
		// Unfinished
		float Gravity;
		ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Entity.GravityScale, Gravity);
		std::cout << Gravity << std::endl;
	}

	void NoSmoke(const DWORD64 EntityAddress) noexcept
	{
		uintptr_t entbase;
		bool SmokeStatus = false;
		int SmokeTime;
		ProcessMgr.ReadMemory(EntityAddress, entbase);
		ProcessMgr.WriteMemory<bool>(entbase + Offset::SmokeGrenadeProjectile.bDidSmokeEffect, SmokeStatus);
	}

	void SmokeColor(const DWORD64 EntityAddress) noexcept
	{
		uintptr_t entbase, adrr;
		char toread[32];
		std::string classname;
		ProcessMgr.ReadMemory<uintptr_t>((uintptr_t)EntityAddress, entbase);
		ProcessMgr.ReadMemory<uintptr_t>(entbase + 0x10, adrr);
		ProcessMgr.ReadMemory<uintptr_t>(adrr + 0x20, adrr);
		ProcessMgr.ReadMemory<char[32]>(adrr, toread);
		classname = toread;
		if (classname == "smokegrenade_projectile")
		{
			Vector3 RED_COLOR = { 1.f, 0.f, 0.f };
			ProcessMgr.WriteMemory<Vector3>(entbase + Offset::SmokeGrenadeProjectile.vSmokeColor, RED_COLOR);
		}
	}
}
