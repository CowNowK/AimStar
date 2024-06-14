#include "Misc.h"
#include "..\Resources\Language.h"
#include <iostream>
#include <Shellapi.h>
#include "../Utils/XorStr.h"

namespace Misc
{
	Hitmarker hitmarker;

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
		ImGui::Begin(XorStr("Cheats List"), nullptr, windowFlags);

		if (MenuConfig::AimBot && (MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)))
			ImGui::Text(XorStr("Aimbot [Toggle]"));
		CheatText(XorStr("Anti Record"), MenuConfig::BypassOBS);
		CheatText(XorStr("Bhop"), MiscCFG::BunnyHop);
		CheatText(XorStr("Bomb Timer"), MiscCFG::bmbTimer);
		CheatText(XorStr("Crosshair"), CrosshairsCFG::ShowCrossHair);
		CheatText(XorStr("Enemy Sensor"), MiscCFG::EnemySensor);
		CheatText(XorStr("ESP"), ESPConfig::ESPenabled);
		CheatText(XorStr("External Radar"), RadarCFG::ShowRadar);
		CheatText(XorStr("Fake Duck"), MiscCFG::Jitter);
		CheatText(XorStr("Fast Stop"), MiscCFG::FastStop);
		if (MiscCFG::FlashImmunity != 0)
			ImGui::Text(XorStr("Flash Immunity"));
		CheatText(XorStr("Force Scope"), MiscCFG::ForceScope);
		if (MiscCFG::Fov != 90)
			ImGui::Text(XorStr("Fov Changer"));
		CheatText(XorStr("Headshot Line"), MenuConfig::ShowHeadShootLine);
		CheatText(XorStr("HitSound"), MiscCFG::HitSound);
		CheatText(XorStr("Money Service"), MiscCFG::MoneyService);
		CheatText(XorStr("No Smoke"), MiscCFG::NoSmoke);
		CheatText(XorStr("Radar Hack"), MiscCFG::RadarHack);
		CheatText(XorStr("RCS"), MenuConfig::RCS);
		CheatText(XorStr("Smoke Color"), MiscCFG::SmokeColored);
		CheatText(XorStr("Spec List"), MiscCFG::SpecList);
		if (MenuConfig::TriggerBot && (MenuConfig::TriggerAlways || GetAsyncKeyState(MenuConfig::TriggerHotKey)))
			ImGui::Text(XorStr("TriggerBot [Toggle]"));

		ImGui::End();
	}

	void Watermark(const CEntity& LocalPlayer) noexcept
	{
		if (!MiscCFG::WaterMark)
			return;

		//	globalvars GV;
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize;
		ImGui::SetNextWindowBgAlpha(0.5f);
		ImGui::Begin(XorStr("Watermark"), nullptr, windowFlags);

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

		ImGui::Text(XorStr("AimStar"));
		ImGui::Text(XorStr("%d FPS | %d ms | %02d:%02d:%02d"),
			FrameRate != 0.0f ? static_cast<int>(FrameRate) : 0,
			playerPing,
			ptm.tm_hour, ptm.tm_min, ptm.tm_sec);
		ImGui::Text(XorStr("Pos: %.2f, %.2f, %.2f"), Pos.x, Pos.y, Pos.z);
		ImGui::Text(XorStr("Angle: %.2f, %.2f"), Angle.x, Angle.y);
		ImGui::Text(XorStr("Vel: %.2f"), LocalPlayer.Pawn.Speed);

		ImGui::End();
	}

	void HitManager(const CEntity& aLocalPlayer, int& PreviousTotalHits) noexcept
	{
		if (MiscCFG::HitMarker || MiscCFG::HitSound)
		{
			uintptr_t pBulletServices;
			int totalHits;
			ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.BulletServices, pBulletServices);
			ProcessMgr.ReadMemory(pBulletServices + Offset::Pawn.TotalHit, totalHits);

			if (totalHits != PreviousTotalHits) {
				if (totalHits == 0 && PreviousTotalHits != 0)
				{
					// `totalHits` changed from non-zero to zero, do nothing
				}
				else
				{
					// Hit Marker
					if (MiscCFG::HitMarker)
					{
						hitmarker.alpha = 255.f;
						hitmarker.startTime = std::chrono::steady_clock::now();
					}

					// Hit Sound
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

		// Update Hit Marker
		if (hitmarker.alpha > 0.f)
		{
			// std::cout << hitmarker.alpha << std::endl;
			auto now = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - hitmarker.startTime).count();
			if (duration >= 500.f)
				hitmarker.alpha = 0;
			else
				hitmarker.alpha = 1.f - duration / 500.f;
		}
	}

	void HitMarker(float Size, float Gap)
	{
		ImGuiIO& io = ImGui::GetIO();
		ImVec2 center = ImVec2(Gui.Window.Size.x / 2, Gui.Window.Size.y / 2);

		if (hitmarker.alpha > 0.f)
		{
			ImColor col = ImColor(255.f, 255.f, 255.f, hitmarker.alpha);

			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x - Size, center.y - Size), ImVec2(center.x - Gap, center.y - Gap), col & IM_COL32_A_MASK, 2.4f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x - Size, center.y + Size), ImVec2(center.x - Gap, center.y + Gap), col & IM_COL32_A_MASK, 2.4f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x + Size, center.y - Size), ImVec2(center.x + Gap, center.y - Gap), col & IM_COL32_A_MASK, 2.4f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x + Size, center.y + Size), ImVec2(center.x + Gap, center.y + Gap), col & IM_COL32_A_MASK, 2.4f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x - Size, center.y - Size), ImVec2(center.x - Gap, center.y - Gap), col, 1.4f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x - Size, center.y + Size), ImVec2(center.x - Gap, center.y + Gap), col, 1.4f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x + Size, center.y - Size), ImVec2(center.x + Gap, center.y - Gap), col, 1.4f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x + Size, center.y + Size), ImVec2(center.x + Gap, center.y + Gap), col, 1.4f);
		}
	}

	void FlashImmunity(const CEntity& aLocalPlayer) noexcept
	{
		if (MenuConfig::SafeMode)
			return;

		float MaxAlpha = 255.f - MiscCFG::FlashImmunity;
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.flFlashMaxAlpha, MaxAlpha);
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
	/*
	// This feature was removed temporarily from Cheats.hpp, because it may crash the game
	void NadeManager(CGame Game) noexcept
	{
		if (MenuConfig::SafeMode)
			return;

		std::vector<std::string> EntityNames = {
		XorStr("smokegrenade_projectile"), XorStr("weapon_glock"), XorStr("weapon_smokegrenade"), XorStr("basemodelentity"),
		XorStr("c_cs_player_for_precache"), XorStr("info_particle_system"), XorStr("prop_dynamic"), XorStr("post_processing_volume"),
		XorStr("env_player_visibility"), XorStr("team_intro_terrorist"), XorStr("c_cs_observer_for_precache"),
		XorStr("team_intro_counterterrorist"), XorStr("point_camera"), XorStr("sky_camera"), XorStr("env_sky"), XorStr("team_select_terrorist"),
		XorStr("team_select_counterterrorist"), XorStr("point_camera"), XorStr("func_bomb_target"), XorStr("env_cubemap_fog"),
		XorStr("csgo_viewmodel"), XorStr("cs_minimap_boundary"), XorStr("cs_gamerules"), XorStr("cs_player_manager"), XorStr("vote_controller"),
		XorStr("weapon_incgrenade"), XorStr("molotov_projectile")
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

				
				// Filter id to find id
				if (std::find(EntityNames.begin(), EntityNames.end(), classname) == EntityNames.end())
					std::cout << classname << std::endl;
				

				if (classname == XorStr("smokegrenade_projectile"))
				{
					if (MiscCFG::SmokeColored)
						ProcessMgr.WriteMemory<Vector3>(ent_base + Offset::SmokeGrenadeProjectile.vSmokeColor, COLOR);
				}
				 Disabled
				if (classname == "molotov_projectile")
				{
					Vector3 FireColor = { 0,0,0 };
					ProcessMgr.ReadMemory<Vector3>(ent_base + 0x112C, FireColor);
					std::cout << FireColor.x << ", " << FireColor.y << ", " << FireColor.z << std::endl;
						
				}
			}
		}
	}
	*/
	void RadarHack(const CEntity& EntityList) noexcept
	{
		if (MenuConfig::SafeMode)
			return;

		if (!MiscCFG::RadarHack)
			return;

		bool SpottedStatus = true;
		ProcessMgr.WriteMemory(EntityList.Pawn.Address + Offset::Pawn.bSpottedByMask, SpottedStatus);
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
		ProcessMgr.WriteMemory<UINT>(aLocalPlayer.Controller.Address + Offset::Pawn.DesiredFov, Desiredfov);

	}

	void MoneyService(const CEntity& EntityList) noexcept
	{
		if (!MiscCFG::MoneyService)
			return;

		ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize;

		ImGui::Begin(XorStr("Money Services"), nullptr, flags);
		{
			if (ImGui::TreeNode(EntityList.Controller.PlayerName.c_str()))
			{
				std::stringstream ss;
				ss << XorStr("Account: $") << EntityList.Controller.Money;
				ImGui::TextColored(ImColor(0, 255, 0, 255), ss.str().c_str());
				if (MiscCFG::ShowCashSpent)
				{
					std::stringstream sss;
					sss << XorStr("ThisRound/Total: ") << EntityList.Controller.CashSpent << XorStr("/") << EntityList.Controller.CashSpentTotal;
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
			ProcessMgr.WriteMemory(MovementServices + Offset::Pawn.CrouchState, unDuck);
		}
		else {
			ProcessMgr.WriteMemory(MovementServices + Offset::Pawn.CrouchState, Ducking);
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
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
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
		XorStr("smokegrenade"), XorStr("flashbang"), XorStr("hegrenade"), XorStr("molotov"), XorStr("decoy"), XorStr("incgrenade"),
		XorStr("awp"), XorStr("ssg08"), XorStr("aug"), XorStr("sg556"),
		XorStr("knife"), XorStr("c4")
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
			ProcessMgr.WriteMemory<UINT>(aLocalPlayer.Controller.Address + Offset::Pawn.DesiredFov, Scopefov);
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
		ImGui::Begin(XorStr("##background"), nullptr, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoDecoration);

		ImVec2 windowPos = ImGui::GetWindowPos();
		ImVec2 windowSize = ImGui::GetWindowSize();
		ImGui::TextColored(ImColor(255, 255, 255, 200), XorStr("Night Mode Overlay"));

		if (MiscCFG::NightModeAlpha)
		{
			ImGui::GetBackgroundDrawList()->
				AddRectFilled(windowPos, ImVec2(windowPos.x + windowSize.x, windowPos.y + windowSize.y), IM_COL32(0, 0, 0, MiscCFG::NightModeAlpha));
		}

		ImGui::End();
		ImGui::PopStyleColor();
			
	}

	void JumpThrow(const CEntity& Local) noexcept
	{
		if (!MiscCFG::jumpthrow)
			return;

		std::string PlayerWeapon = Local.Pawn.WeaponName;
		if (std::find(Nades.begin(), Nades.end(), PlayerWeapon) == Nades.end())
			return;

		bool isOnGround = AirCheck(Local);
		if (!isOnGround)
		{
			Vec3 Velocity;
			ProcessMgr.ReadMemory<Vec3>(Local.Pawn.Address + Offset::Pawn.AbsVelocity, Velocity);

			if (Velocity.z > 250.f || Velocity.z < 200.f)
				return;

			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
	}

	void SpectatorList(const CEntity& Local, const CEntity& Entity) {
		if (!MiscCFG::SpecList)
			return;

		std::vector<std::string> spectators;

		DWORD64 l_pawn, l_observe, l_spec;
		ProcessMgr.ReadMemory(Entity.Controller.Address + Offset::PlayerController.m_pObserverServices, l_pawn);
		ProcessMgr.ReadMemory(l_pawn + Offset::PlayerController.m_hObserverTarget, l_observe);
		ProcessMgr.ReadMemory(l_observe + Offset::PlayerController.m_hController, l_spec);

		if (l_observe == Local.Pawn.Address) {
			spectators.push_back(Entity.Controller.PlayerName);
		}

		if (spectators.empty())
			return;

		for (size_t i{}; i < spectators.size(); ++i) {
			auto msg = spectators[i];
			Gui.StrokeText(msg.substr(0, 24), ImVec2(Gui.Window.Size.x / 2, Gui.Window.Size.y / 2), 18.f, true);
		}
	}
}
