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

	void CheatList() noexcept
	{
		if (!MiscCFG::CheatList)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::SetNextWindowSize(ImVec2(200, 0));
		ImGui::Begin("Cheats List", nullptr, windowFlags);

		if (MenuConfig::AimBot && (MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)))
			ImGui::Text("Aimbot [Toggle]");
		CheatText("Anti Record", MenuConfig::BypassOBS);
		CheatText("Bhop", MiscCFG::BunnyHop);
		CheatText("Bomb Timer", MiscCFG::bmbTimer);
		CheatText("Crosshair", CrosshairsCFG::ShowCrossHair);
		CheatText("Enemy Sensor", MiscCFG::EnemySensor);
		CheatText("ESP", ESPConfig::ESPenabled);
		CheatText("External Radar", RadarCFG::ShowRadar);
		CheatText("Fake Duck", MiscCFG::Jitter);
		CheatText("Fast Stop", MiscCFG::FastStop);
		if (MiscCFG::FlashImmunity != 0)
			ImGui::Text("Flash Immunity");
		CheatText("Force Scope", MiscCFG::ForceScope);
		if (MiscCFG::Fov != 90)
			ImGui::Text("Fov Changer");
		CheatText("Headshot Line", MenuConfig::ShowHeadShootLine);
		CheatText("HitSound", MiscCFG::HitSound);
		CheatText("Money Service", MiscCFG::MoneyService);
		CheatText("No Smoke", MiscCFG::NoSmoke);
		CheatText("Radar Hack", MiscCFG::RadarHack);
		CheatText("RCS", MenuConfig::RCS);
		CheatText("Smoke Color", MiscCFG::SmokeColored);
		CheatText("Spec List", MiscCFG::SpecList);
		if (MenuConfig::TriggerBot && (MenuConfig::TriggerAlways || GetAsyncKeyState(MenuConfig::TriggerHotKey)))
			ImGui::Text("TriggerBot [Toggle]");

		ImGui::End();
	}

	void Watermark(const CEntity& LocalPlayer) noexcept
	{
		if (!MiscCFG::WaterMark)
			return;

		//	globalvars GV;
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::Begin("Watermark", nullptr, windowFlags);

		// Cheat FPS
		static auto FrameRate = 1.0f;
		FrameRate = ImGui::GetIO().Framerate;

		// Current Time
		struct tm ptm;
		getCurrentTime(&ptm);

		// Player Ping
		int playerPing;
		ProcessMgr.ReadMemory(LocalPlayer.Controller.Address + 0x718, playerPing);

		// Player Pos
		Vec3 Pos = LocalPlayer.Pawn.Pos;

		// Player Angle
		Vec2 Angle = LocalPlayer.Pawn.ViewAngle;

		ImGui::Text("AimStar");
		ImGui::Text("%d FPS | %d ms | %02d:%02d:%02d",
			FrameRate != 0.0f ? static_cast<int>(FrameRate) : 0,
			playerPing,
			ptm.tm_hour, ptm.tm_min, ptm.tm_sec);
		ImGui::Text("Pos: %.2f, %.2f, %.2f", Pos.x, Pos.y, Pos.z);
		ImGui::Text("Angel: %.2f, %.2f", Angle.x, Angle.y);
		ImGui::Text("Vel: %.2f", LocalPlayer.Pawn.Speed);

		ImGui::End();
	}

	void HitSound(const CEntity& aLocalPlayer, int& PreviousTotalHits) noexcept
	{
		if (!MiscCFG::HitSound)
			return;

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
				switch (MiscCFG::HitSound)
				{
				case 1:
					PlaySoundA(reinterpret_cast<char*>(neverlose_sound), NULL, SND_ASYNC | SND_MEMORY);
					break;
				case 2:
					PlaySoundA(reinterpret_cast<char*>(skeet_sound), NULL, SND_ASYNC | SND_MEMORY);
					break;
				case 3:
					PlaySoundA(reinterpret_cast<char*>(Fuck), NULL, SND_ASYNC | SND_MEMORY);
					break;
				case 4:
					PlaySoundA(reinterpret_cast<char*>(Senpai), NULL, SND_ASYNC | SND_MEMORY);
					break;
				default:
					break;
				}
				
			}
		}
		PreviousTotalHits = totalHits;
	}

	// doesnt check if its enabled just changes "opacity"
	void FlashImmunity(const CEntity& aLocalPlayer) noexcept
	{
		if (MenuConfig::SafeMode)
			return;

		float MaxAlpha = 255.f - MiscCFG::FlashImmunity;
		SafeMgr.SafeWrite(aLocalPlayer.Pawn.Address + Offset::Pawn.flFlashMaxAlpha, MaxAlpha);
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
		if (MenuConfig::SafeMode)
			return;

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

				SafeMgr.SafeWrite<bool>(ent_base + Offset::SmokeGrenadeProjectile.bDidSmokeEffect, begin);
				SafeMgr.SafeWrite<bool>(ent_base + Offset::SmokeGrenadeProjectile.bSmokeEffectSpawned, begin);
				SafeMgr.SafeWrite<int>(ent_base + Offset::SmokeGrenadeProjectile.nSmokeEffectTickBegin, uf);
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
						SafeMgr.SafeWrite<Vector3>(ent_base + Offset::SmokeGrenadeProjectile.vSmokeColor, COLOR);
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
		if (MenuConfig::SafeMode)
			return;

		if (!MiscCFG::RadarHack)
			return;

		bool SpottedStatus = true;
		SafeMgr.SafeWrite(EntityList.Pawn.Address + Offset::Pawn.bSpottedByMask, SpottedStatus);
	}

	void FovChanger(const CEntity& aLocalPlayer) noexcept
	{
		if (MenuConfig::SafeMode)
			return;

		DWORD64 CameraServices = 0;
		if (Zoom)
			return;

		if (!ProcessMgr.ReadMemory<DWORD64>(aLocalPlayer.Pawn.Address + Offset::Pawn.CameraServices, CameraServices))
			return;

		UINT Desiredfov = static_cast<UINT>(MiscCFG::Fov);
		SafeMgr.SafeWrite<UINT>(aLocalPlayer.Controller.Address + Offset::Pawn.DesiredFov, Desiredfov);

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

	// doesnt check enabled or safe mode so writes on loop even if cheat/safemode disabled but fd doesnt work on cs2 so u dont realise
	void FakeDuck(const CEntity& aLocalPlayer) noexcept
	{

		DWORD64 MovementServices;
		float Tick;
		bool Ducking = 1, unDuck = 0;
		ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.MovementServices, MovementServices);
		if (!MiscCFG::Jitter)
		{
			SafeMgr.SafeWrite(MovementServices + 0x1E4, unDuck);
		}
		else {
			SafeMgr.SafeWrite(MovementServices + 0x1E4, Ducking);
		}
	}

	// setforcejump writes to mem no safe mode check tho
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
			std::this_thread::sleep_for(std::chrono::milliseconds(17));
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

	std::string OldWeaponCache;
	void ForceScope(const CEntity& aLocalPlayer) noexcept
	{
		if (MenuConfig::SafeMode)
			return;

		if (!MiscCFG::ForceScope)
			return;

		// When player switching weapon, cancel Scope
		const std::string PlayerWeapon = aLocalPlayer.Pawn.WeaponName;
		if (OldWeaponCache != PlayerWeapon)
		{
			Zoom = false;
			OldWeaponCache = PlayerWeapon;
		}

		// When players hold these weapons, don't Scope
		std::vector<std::string> WeaponNames = {
		"smokegrenade", "flashbang", "hegrenade", "molotov", "decoy", "incgrenade", 
		"awp", "ssg08", "aug", "sg556", 
		"knife", "c4"
		};
		if (std::find(WeaponNames.begin(), WeaponNames.end(), PlayerWeapon) != WeaponNames.end())
			return;

		// When player reloading their weapon, cancel Scope
		DWORD64 WeaponService;
		bool inReload;
		ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.pClippingWeapon, WeaponService);
		ProcessMgr.ReadMemory(WeaponService + Offset::WeaponBaseData.inReload, inReload);
		if (inReload)
		{
			Zoom = false;
		}

		// Avoid scope loop
		static DWORD lastTick = 0;
		DWORD currentTick = GetTickCount();
		if (!MenuConfig::ShowMenu)
		{
			if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000) && currentTick - lastTick >= 500)
			{
				Zoom = !Zoom;
				lastTick = currentTick;
			}
		}

		if (Zoom)
		{
			UINT Scopefov = 45;
			SafeMgr.SafeWrite<UINT>(aLocalPlayer.Controller.Address + Offset::Pawn.DesiredFov, Scopefov);
		}
			
	}

	// @Phillip
	void NightMode() noexcept
	{
		if (!MiscCFG::NightMode)
			return;

		ImGui::SetNextWindowPos({ 0, 0 }, ImGuiCond_Always);
		ImGui::SetNextWindowSize({ Gui.Window.Size.x, Gui.Window.Size.y }, ImGuiCond_Always);
		ImGui::SetNextWindowBgAlpha(0.f);
		ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 0));
		ImGui::Begin("##background", nullptr, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoDecoration);

		ImVec2 windowPos = ImGui::GetWindowPos();
		ImVec2 windowSize = ImGui::GetWindowSize();
		ImGui::TextColored(ImColor(255, 255, 255, 200), "Night Mode Overlay");

		if (MiscCFG::NightModeAlpha)
		{
			ImGui::GetBackgroundDrawList()->
				AddRectFilled(windowPos, ImVec2(windowPos.x + windowSize.x, windowPos.y + windowSize.y), IM_COL32(0, 0, 0, MiscCFG::NightModeAlpha));
		}

		ImGui::End();
		ImGui::PopStyleColor();
			
	}
}
