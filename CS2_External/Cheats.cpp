#include <string>
#include <thread>
#include <future>
#include <iostream>

#include "Cheats.h"
#include "Render.hpp"
#include "MenuConfig.hpp"

#include "Features/ESP.h"
#include "Features/GUI.h"
#include "Features/RCS.H"
#include "Features/BombTimer.h"
#include "Features/SpectatorList.h"

int PreviousTotalHits = 0;

// Does not work and not use it for now
void Cheats::KeyCheckThread()
{
	try
	{
		if ((GetAsyncKeyState(VK_INSERT) & 0x8000))
		{
			MenuConfig::ShowMenu = !MenuConfig::ShowMenu;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Cheats::RadarSetting(Base_Radar& Radar)
{
	// Radar window
	ImGui::SetNextWindowBgAlpha(MenuConfig::Radar.RadarBgAlpha);
	ImGui::Begin("Radar", 0, ImGuiWindowFlags_NoResize);
	ImGui::SetWindowSize({ MenuConfig::Radar.RadarRange * 2,MenuConfig::Radar.RadarRange * 2 });
	
	if (!MenuConfig::Radar.customRadar)
	{
		ImGui::SetWindowPos(ImVec2(0, 0));
		MenuConfig::Radar.ShowRadarCrossLine = false;
		MenuConfig::Radar.Proportion = 3300.f;
		MenuConfig::Radar.RadarPointSizeProportion = 1.f;
		MenuConfig::Radar.RadarRange = 150.f;
		MenuConfig::Radar.RadarBgAlpha = 0.1f;
	}
		

	// Radar.SetPos({ Gui.Window.Size.x / 2,Gui.Window.Size.y / 2 });
	Radar.SetDrawList(ImGui::GetWindowDrawList());
	Radar.SetPos({ ImGui::GetWindowPos().x + MenuConfig::Radar.RadarRange, ImGui::GetWindowPos().y + MenuConfig::Radar.RadarRange });
	Radar.SetProportion(MenuConfig::Radar.Proportion);
	Radar.SetRange(MenuConfig::Radar.RadarRange);
	Radar.SetSize(MenuConfig::Radar.RadarRange * 2);
	Radar.SetCrossColor(MenuConfig::Radar.RadarCrossLineColor);

	Radar.ArcArrowSize *= MenuConfig::Radar.RadarPointSizeProportion;
	Radar.ArrowSize *= MenuConfig::Radar.RadarPointSizeProportion;
	Radar.CircleSize *= MenuConfig::Radar.RadarPointSizeProportion;

	Radar.ShowCrossLine = MenuConfig::Radar.ShowRadarCrossLine;
	Radar.Opened = true;
}

void Cheats::RenderCrossHair(ImDrawList* drawList) noexcept
{
	if (!MenuConfig::Crosshairs.ShowCrossHair)
		return;

	if(MenuConfig::Crosshairs.isAim && MenuConfig::Crosshairs.showTargeting)
		Render::DrawCrossHair(drawList, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGui::ColorConvertFloat4ToU32(MenuConfig::Crosshairs.TargetedColor));
	else
		Render::DrawCrossHair(drawList, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGui::ColorConvertFloat4ToU32(MenuConfig::Crosshairs.CrossHairColor));
}

void Cheats::Run()
{	
	// Show menu
	static DWORD lastTick = 0; 
	DWORD currentTick = GetTickCount(); 
	if ((GetAsyncKeyState(VK_INSERT) & 0x8000) && currentTick - lastTick >= 150) {
		MenuConfig::ShowMenu = !MenuConfig::ShowMenu;
		lastTick = currentTick;
	}
//	std::thread keyCheckThread(KeyCheckThread);
//  std::future<void> Thread_PlayerESP = std::async(ESP::RenderPlayerESP, std::ref(Entity), std::ref(Rect));
	if (MenuConfig::ShowMenu)
	{
		if (!MenuConfig::WindowStyle)
		{
			GUI::RenderMenu();
			ESP::PreviewWindow();
		}
		else {
			GUI::NewGui();
		}
		
		
	}
		

	// Update matrix
	if(!ProcessMgr.ReadMemory(gGame.GetMatrixAddress(), gGame.View.Matrix,64))
		return;

	// Update EntityList Entry
	gGame.UpdateEntityListEntry();

	DWORD64 LocalControllerAddress = 0;
	DWORD64 LocalPawnAddress = 0;
	DWORD64 ServerPawnAddress = 0;

	if (!ProcessMgr.ReadMemory(gGame.GetLocalControllerAddress(), LocalControllerAddress))
		return;
	if (!ProcessMgr.ReadMemory(gGame.GetLocalPawnAddress(), LocalPawnAddress))
		return;
	if (!ProcessMgr.ReadMemory(gGame.GetServerPawnAddress(), ServerPawnAddress))
		return;

	// LocalEntity
	CEntity LocalEntity, ServerEntity;
	static int LocalPlayerControllerIndex = 1;
	if (!LocalEntity.UpdateController(LocalControllerAddress))
		return;
	if (!LocalEntity.UpdatePawn(LocalPawnAddress) && !MenuConfig::Misc.WorkInSpec)
		return;
	if (!ServerEntity.UpdateServerPawn(ServerPawnAddress) && !MenuConfig::Misc.WorkInSpec)
		return;

	// HealthBar Map
	static std::map<DWORD64, Render::HealthBar> HealthBarMap;

	// AimBot data
	float DistanceToSight = 0;
	float MaxAimDistance = 100000;
	Vec3  HeadPos{ 0,0,0 };
	Vec3  AimPos{ 0,0,0 };
	Vec2  Angles{ 0,0 };

	// Radar Data
	Base_Radar Radar;
	if (MenuConfig::Radar.ShowRadar)
		RadarSetting(Radar);

	for (int i = 0; i < 64; i++)
	{
		CEntity Entity;
		DWORD64 EntityAddress = 0;
		if (!ProcessMgr.ReadMemory<DWORD64>(gGame.GetEntityListEntry() + (i + 1) * 0x78, EntityAddress))
			continue;
		if (EntityAddress == LocalEntity.Controller.Address)
		{
			LocalPlayerControllerIndex = i;
			continue;
		}
		if (!Entity.UpdateController(EntityAddress))
			continue;
		if (!Entity.UpdatePawn(Entity.Pawn.Address))
			continue;

		if (MenuConfig::TeamCheck && Entity.Controller.TeamID == LocalEntity.Controller.TeamID)
			continue;
		if (!Entity.IsAlive())
			continue;
//		if (MenuConfig::VisibleCheck && (!Entity.Pawn.bSpottedByMask > 0))
//			continue;


		// Add entity to radar
		if (MenuConfig::Radar.ShowRadar)
			Radar.AddPoint(LocalEntity.Pawn.Pos, LocalEntity.Pawn.ViewAngle.y, Entity.Pawn.Pos, ImColor(237, 85, 106, 200), MenuConfig::Radar.RadarType, Entity.Pawn.ViewAngle.y);

		if (!Entity.IsInScreen())
			continue;

		// Bone Debug
	/*	for (int BoneIndex = 0; BoneIndex < Entity.BoneData.BonePosList.size(); BoneIndex++)
		{
			Vec2 ScreenPos{};
			if (gGame.View.WorldToScreen(Entity.BoneData.BonePosList[BoneIndex].Pos, ScreenPos))
			{
				Gui.Text(std::to_string(BoneIndex), ScreenPos, ImColor(255, 255, 255, 255));
			}
		}*/
		DistanceToSight = Entity.GetBone().BonePosList[BONEINDEX::head].ScreenPos.DistanceTo({ Gui.Window.Size.x / 2,Gui.Window.Size.y / 2 });


		if (DistanceToSight < MaxAimDistance)
		{
			MaxAimDistance = DistanceToSight;

			if (!MenuConfig::VisibleCheck ||
				Entity.Pawn.bSpottedByMask & (DWORD64(1) << (LocalPlayerControllerIndex)) ||
				LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << (i)))
			{
				AimPos = Entity.GetBone().BonePosList[MenuConfig::AimPositionIndex].Pos;
				if (MenuConfig::AimPositionIndex == BONEINDEX::head)
					AimPos.z -= 1.f;
			}
		}

		if (ESPConfig::ESPenbled)
		{
			ImVec4 Rect = ESP::GetBoxRect(Entity, MenuConfig::BoxType);
			ESP::RenderPlayerESP(LocalEntity, Entity, Rect, LocalPlayerControllerIndex, i);
			
				
			// Draw HealthBar
			if (ESPConfig::ShowHealthBar)
			{
				ImVec2 HealthBarPos, HealthBarSize;
				switch (MenuConfig::HealthBarType == 0)
				{
				case 0:
					HealthBarPos = { Rect.x + Rect.z / 2 - 70 / 2,Rect.y - 13 };
					HealthBarSize = { 70,8 };
					break;
				case 1:
					HealthBarPos = { Rect.x - 10.f,Rect.y };
					HealthBarSize = { 7 ,Rect.w };
					break;
				case 2:
					HealthBarPos = { Rect.x, Rect.y + Rect.w + 2 };
					HealthBarSize = { Rect.z, 4 };
					break;
				}
				Render::DrawHealthBar(EntityAddress, 100, Entity.Pawn.Health, HealthBarPos, HealthBarSize, MenuConfig::HealthBarType);
			}

			// Draw Distance
			Render::DrawDistance(LocalEntity, Entity, Rect);
		}
		Glow::Run(Entity);
		SpecList::GetSpectatorList(Entity, LocalEntity, EntityAddress);
	}
	
	// Radar render
	if(MenuConfig::Radar.ShowRadar)
	{
		Radar.Render();
		ImGui::End();
	}

	// TriggerBot
	if (MenuConfig::TriggerBot && (GetAsyncKeyState(TriggerBot::HotKey) || MenuConfig::TriggerAlways))
		TriggerBot::Run(LocalEntity);	

	Misc::HitSound(LocalEntity, PreviousTotalHits);
	Misc::NoFlash(LocalEntity);
	Misc::Watermark();
	Misc::CheatList();

	// Fov line
	Render::DrawFov(LocalEntity, MenuConfig::FovLineSize, MenuConfig::FovLineColor, 1);

	// HeadShoot Line
	Render::HeadShootLine(LocalEntity, MenuConfig::HeadShootLineColor);
	
	// CrossHair
	TriggerBot::TargetCheck(LocalEntity);
	Bunnyhop::AirCheck(LocalEntity);
	RenderCrossHair(ImGui::GetBackgroundDrawList());

	// Bhop
	Bunnyhop::Run(LocalEntity);

	bmb::RenderWindow();

	// RCS
	if (MenuConfig::RCS)
	{
		RCS::GetAngles(LocalEntity, Angles);
		std::cout << "(" << Angles.x << ", " << Angles.y << ")" << std::endl;
		RCS::Run(LocalEntity, Angles, MenuConfig::AimBot);
	}
	// Aimbot
	if (MenuConfig::AimBot)
	{
		Render::DrawFovCircle(LocalEntity);

		if (MenuConfig::AimAlways)
		{
			if (AimPos != Vec3(0, 0, 0))
			{
				AimControl::AimBot(LocalEntity, LocalEntity.Pawn.CameraPos, AimPos);
			}
		}
		else
		{
			if (GetAsyncKeyState(AimControl::HotKey))
			{
				if (AimPos != Vec3(0, 0, 0))
				{
					AimControl::AimBot(LocalEntity, LocalEntity.Pawn.CameraPos, AimPos);
				}
			}
		}

		if (MenuConfig::AimToggleMode && (GetAsyncKeyState(AimControl::HotKey) & 0x8000) && currentTick - lastTick >= 200)
		{
			AimControl::switchToggle();
			lastTick = currentTick;
		}
			
			
	}
		
}
