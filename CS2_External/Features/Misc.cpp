#include "Misc.h"
#include "..\Resources\Language.h"
#include <iostream>
#include <Shellapi.h>

namespace Misc
{
	bool aKeyPressed = false;
	bool dKeyPressed = false;
	bool wKeyPressed = false;
	bool sKeyPressed = false;

	void JoinDiscord() noexcept
	{
		if (!MiscCFG::mother)
			return;

		ShellExecuteA(NULL, "open", "https://discord.com/invite/VgRrxwesPz", NULL, NULL, SW_SHOWNORMAL);
		MiscCFG::mother = !MiscCFG::mother;
	}

	void SourceCode() noexcept
	{
		if (!MiscCFG::fucker)
			return;

		ShellExecuteA(NULL, "open", "https://github.com/CowNowK/AimStar", NULL, NULL, SW_SHOWNORMAL);
		MiscCFG::fucker = !MiscCFG::fucker;
	}

	void CheatList() noexcept
	{
		if (!MiscCFG::CheatList)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::SetNextWindowSize(ImVec2(200, 0));
		ImGui::Begin("Cheats List", nullptr, windowFlags);

		CheatText("ESP", ESPConfig::ESPenabled);
		if (MenuConfig::AimBot && (MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)))
			ImGui::Text("Aimbot [Toggle]");
		CheatText("RCS", MenuConfig::RCS);
		CheatText("Glow", MiscCFG::EnemySensor);
		CheatText("Radar", RadarCFG::ShowRadar);
		if (MenuConfig::TriggerBot && (MenuConfig::TriggerAlways || GetAsyncKeyState(MenuConfig::TriggerHotKey)))
			ImGui::Text("TriggerBot [Toggle]");

		CheatText("Crosshair", CrosshairsCFG::ShowCrossHair);
		CheatText("Headshot Line", MenuConfig::ShowHeadShootLine);
		CheatText("No Flash", MiscCFG::NoFlash);
		CheatText("Fast Stop", MiscCFG::FastStop);
		CheatText("Bhop", MiscCFG::BunnyHop);
		CheatText("HitSound", MiscCFG::HitSound);
		CheatText("Bomb Timer", MiscCFG::bmbTimer);
		CheatText("Spec List", MiscCFG::SpecList);

		ImGui::End();
	}

	void Watermark() noexcept
	{
		if (!MiscCFG::WaterMark)
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
		if (!MiscCFG::HitSound)
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
		if (!MiscCFG::NoFlash)
			return;

		float duration = 0.0f;
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.flFlashDuration, duration);
	}

	void FastStop() noexcept
	{
		if (!MiscCFG::FastStop)
			return;
		// Disable when bhopping
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			return;
		// Disable when slow walking
		if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
			return;

		Misc::StopKeyEvent('A', &aKeyPressed, 'D', 50.f);
		Misc::StopKeyEvent('D', &dKeyPressed, 'A', 50.f);
		Misc::StopKeyEvent('W', &wKeyPressed, 'S', 50.f);
		Misc::StopKeyEvent('S', &sKeyPressed, 'W', 50.f);
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
