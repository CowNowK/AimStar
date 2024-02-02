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

	void NadeManager(CGame Game) noexcept
	{
		std::vector<std::string> EntityNames = {
		"smokegrenade_projectile", "weapon_glock", "weapon_smokegrenade", "basemodelentity",
		"c_cs_player_for_precache", "info_particle_system", "prop_dynamic", "post_processing_volume",
		"env_player_visibility", "team_intro_terrorist", "c_cs_observer_for_precache",
		"team_intro_counterterrorist", "point_camera", "sky_camera", "env_sky", "team_select_terrorist",
		"team_select_counterterrorist", "point_camera", "func_bomb_target", "env_cubemap_fog",
		"csgo_viewmodel", "cs_minimap_boundary", "cs_gamerules", "cs_player_manager", "vote_controller",
		"weapon_incgrenade", "molotov_projectile"
		};

		if (!MiscCFG::NoSmoke && !MiscCFG::SmokeColored)
			return;

		for (int i_smoke = 64; i_smoke < 1024; i_smoke++) {
			uintptr_t SmokeEntity = GetSmokeEntity(i_smoke, Game.GetEntityListEntry());

			uintptr_t ent_base, addr;
			ProcessMgr.ReadMemory<uintptr_t>(SmokeEntity, ent_base);

			// No Smoke
			if (MiscCFG::NoSmoke)
			{
				bool begin = false;
				int uf = 0;

				ProcessMgr.WriteMemory<bool>(ent_base + Offset::SmokeGrenadeProjectile.bDidSmokeEffect, begin);
				ProcessMgr.WriteMemory<bool>(ent_base + Offset::SmokeGrenadeProjectile.bSmokeEffectSpawned, begin);
				ProcessMgr.WriteMemory<int>(ent_base + Offset::SmokeGrenadeProjectile.nSmokeEffectTickBegin, uf);
			}

			// Smoke Color
			if (MiscCFG::SmokeColored || MiscCFG::FireColored)
			{
				char toread[32];
				std::string classname;
				Vector3 COLOR = { MiscCFG::SmokeColor.Value.x, MiscCFG::SmokeColor.Value.y ,MiscCFG::SmokeColor.Value.z };
				ProcessMgr.ReadMemory<uintptr_t>(ent_base + 0x10, addr);
				ProcessMgr.ReadMemory<uintptr_t>(addr + 0x20, addr);
				ProcessMgr.ReadMemory<char[32]>(addr, toread);
				classname = toread;

				/* 
				* Filter id to find id
				if (std::find(EntityNames.begin(), EntityNames.end(), classname) == EntityNames.end())
					std::cout << classname << std::endl;
				*/

				if (classname == "smokegrenade_projectile")
				{
					if (MiscCFG::SmokeColored)
						ProcessMgr.WriteMemory<Vector3>(ent_base + Offset::SmokeGrenadeProjectile.vSmokeColor, COLOR);
				}
				/* Disabled
				if (classname == "molotov_projectile")
				{
					Vector3 FireColor = { 0,0,0 };
					ProcessMgr.ReadMemory<Vector3>(ent_base + 0x112C, FireColor);
					std::cout << FireColor.x << ", " << FireColor.y << ", " << FireColor.z << std::endl;
						
				}*/
			}
		}
	}

	void RadarHack(const CEntity& EntityList) noexcept
	{
		if (!MiscCFG::RadarHack)
			return;

		bool SpottedStatus = true;
		ProcessMgr.WriteMemory(EntityList.Pawn.Address + Offset::Pawn.bSpottedByMask, SpottedStatus);
	}

	void FovChanger(const CEntity& aLocalPlayer) noexcept
	{
		if (!MiscCFG::FovHacker)
			return;

		DWORD64 CameraServices = 0;
		UINT CurrentFOV;
		bool isScoped;
		if (!ProcessMgr.ReadMemory<DWORD64>(aLocalPlayer.Pawn.Address + Offset::Pawn.CameraServices, CameraServices))
			return;

		// UINT Desiredfov = static_cast<UINT>(MiscCFG::Fov);
		UINT Desiredfov = 0x8C;
		ProcessMgr.ReadMemory<UINT>(CameraServices + Offset::Pawn.iFov, CurrentFOV);
		// std::cout << CurrentFOV << std::endl;

		ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.isScoped, isScoped);
		if (!isScoped)
		{
			ProcessMgr.WriteMemory<UINT>(CameraServices + Offset::Pawn.iFov, Desiredfov);
		}
	}

	void MoneyService(const CEntity& EntityList) noexcept
	{
		if (!MiscCFG::MoneyService)
			return;

		ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize;

		ImGui::Begin("Money Services", nullptr, flags);
		{
			if (ImGui::TreeNode(EntityList.Controller.PlayerName.c_str()))
			{
				std::stringstream ss;
				ss << "Account: $" << EntityList.Controller.Money;
				ImGui::TextColored(ImColor(0, 255, 0, 255), ss.str().c_str());
				if (MiscCFG::ShowCashSpent)
				{
					std::stringstream sss;
					sss << "ThisRound/Total: " << EntityList.Controller.CashSpent << "/" << EntityList.Controller.CashSpentTotal;
					ImGui::TextColored(ImColor(255, 0, 0, 255), sss.str().c_str());
				}
				
				ImGui::TreePop();
			}
		}
	}

	void FakeDuck(const CEntity& aLocalPlayer) noexcept
	{

		DWORD64 MovementServices;
		float Tick;
		bool Ducking = 1, unDuck = 0;
		ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.MovementServices, MovementServices);
		if (!MiscCFG::Jitter)
		{
			ProcessMgr.WriteMemory(MovementServices + 0x1E4, unDuck);
		}
		else {
			ProcessMgr.WriteMemory(MovementServices + 0x1E4, Ducking);
		}
	}

	void BunnyHop(const CEntity& Local) noexcept
	{
		if (!MiscCFG::BunnyHop)
			return;

		int ForceJump;
		bool spacePressed = GetAsyncKeyState(VK_SPACE);
		bool isInAir = AirCheck(Local);
		gGame.GetForceJump(ForceJump);

		if (spacePressed && isInAir) // AirCheck = 1, is on ground
		{
			// As of the latest update (11/8/2023) bhop doesn't work at all with sendinput,
			// if +jump is sent on the same tick that you land on the ground, the jump won't register.
			// But you can add 15ms of delay right before your sendinput to fix this problem temporarily
			std::this_thread::sleep_for(std::chrono::milliseconds(15));
			// Refer to -> https://www.unknowncheats.me/forum/counter-strike-2-a/609480-sendinput-bhop-inconsistency.html
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
	}
}
