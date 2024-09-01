#include <string>
#include <thread>
#include <future>
#include <iostream>

#include "Cheats.h"
#include "Render.hpp"
#include "MenuConfig.hpp"

#include "Utils/Initial/Init.h"

#include "Features/ESP.h"
#include "Features/GUI.h"
#include "Features/RCS.H"
#include "Features/BombTimer.h"
#include "Features/SpectatorList.h"
#include "Utils/XorStr.h"
#include "Features/Debugger.h"

int PreviousTotalHits = 0;

// Does not work and not use it for now
void Cheats::KeyCheckThread()
{
	try
	{
        if ((GetAsyncKeyState(VK_INSERT) & 0x8000) || (GetAsyncKeyState(VK_DELETE) & 0x8000))
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
	ImGui::SetNextWindowBgAlpha(RadarCFG::RadarBgAlpha);
	ImGui::Begin(XorStr("Radar"), 0, ImGuiWindowFlags_NoResize);
	ImGui::SetWindowSize({ RadarCFG::RadarRange * 2,RadarCFG::RadarRange * 2 });
	
	if (!RadarCFG::customRadar)
	{
		ImGui::SetWindowPos(ImVec2(0, 0));
		RadarCFG::ShowRadarCrossLine = false;
		RadarCFG::Proportion = 3300.f;
		RadarCFG::RadarPointSizeProportion = 1.f;
		RadarCFG::RadarRange = 150.f;
		RadarCFG::RadarBgAlpha = 0.1f;
	}
		

	// Radar.SetPos({ Gui.Window.Size.x / 2,Gui.Window.Size.y / 2 });
	Radar.SetDrawList(ImGui::GetWindowDrawList());
	Radar.SetPos({ ImGui::GetWindowPos().x + RadarCFG::RadarRange, ImGui::GetWindowPos().y + RadarCFG::RadarRange });
	Radar.SetProportion(RadarCFG::Proportion);
	Radar.SetRange(RadarCFG::RadarRange);
	Radar.SetSize(RadarCFG::RadarRange * 2);
	Radar.SetCrossColor(RadarCFG::RadarCrossLineColor);

	Radar.ArcArrowSize *= RadarCFG::RadarPointSizeProportion;
	Radar.ArrowSize *= RadarCFG::RadarPointSizeProportion;
	Radar.CircleSize *= RadarCFG::RadarPointSizeProportion;

	Radar.ShowCrossLine = RadarCFG::ShowRadarCrossLine;
	Radar.Opened = true;
}

void Cheats::RenderCrossHair(ImDrawList* drawList) noexcept
{
	if (!CrosshairsCFG::ShowCrossHair)
		return;

	if(CrosshairsCFG::isAim && MenuConfig::TargetingCrosshairs)
		Render::DrawCrossHair(drawList, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGui::ColorConvertFloat4ToU32(CrosshairsCFG::TargetedColor));
	else
		Render::DrawCrossHair(drawList, ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGui::ColorConvertFloat4ToU32(CrosshairsCFG::CrossHairColor));
}

void Cheats::SignatureMutation() noexcept
{
	srand((unsigned)time(NULL));
	DWORD64 random_offset = std::rand() % 4000000001;
	int random_data = std::rand() % 65535;
	ProcessMgr.WriteMemory(gGame.GetClientDLLAddress() + random_offset, random_data);
	return;
}

void Cheats::FastBypass() noexcept
{
	HANDLE process_handle = OpenProcess(
		PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
		FALSE,
		ProcessMgr.GetProcessID("cs2.exe"));
	HANDLE thread_handle = CreateRemoteThread(process_handle, nullptr, 0, 0, nullptr, 0, nullptr);
	return;
}
YAML::Node yamldata;
bool Cheats::AntiTKMAC(const INT64 hash) noexcept 
{
	if (!yamldata["client_dll"]["TrustFactorManager_app"]) {
		return false;
	}

	for (const auto& item : yamldata["client_dll"]["TrustFactorManager_app"]) {
		if (item.as<INT64>() == hash) {
			return true;
		}
	}

	return false;
}
bool GameKeepOn,UserBruted;
int BruteC, BruteD = 0;
void Cheats::Run()
{	
	if (yamldata.IsNull())
	{
		std::ifstream fileStream(MenuConfig::path + XorStr("\\Offsets\\offsets.yaml"));
		yamldata = YAML::Load(fileStream);
		fileStream.close();
	}
	if (MenuConfig::DRM && BruteD< 64)
	{
		Gui.OpenWebpage(XorStr("https://www.gov.cn/guoqing/2023-03/10/content_5745919.htm"));//绕过国服检测机制
		Gui.OpenWebpage(XorStr("https://www.bilibili.com/video/BV12j411v7R7/"));
		SignatureMutation();
		BruteD++;
	}	
	if (MenuConfig::DEC && BruteD  >= 63)
	{
		Cheats::FastBypass();
		Debugger::Analyzer();
	}
	// Show menu
	static DWORD lastTick = 0; 
	DWORD currentTick = GetTickCount(); 
	if (((GetAsyncKeyState(VK_INSERT) & 0x8000) || (GetAsyncKeyState(VK_DELETE) & 0x8000)) && currentTick - lastTick >= 250) {
		MenuConfig::ShowMenu = !MenuConfig::ShowMenu;
		lastTick = currentTick;
	}
//	std::thread keyCheckThread(KeyCheckThread);
//  std::future<void> Thread_PlayerESP = std::async(ESP::RenderPlayerESP, std::ref(Entity), std::ref(Rect));
	if (MenuConfig::ShowMenu)
	{
		GUI::NewGui();
	}

	if (!Init::Client::isGameWindowActive() && !MenuConfig::ShowMenu)
		return;

	// The overlay should be rendered at the bottom
	Misc::NightMode();

	// Update matrix
	if(!ProcessMgr.ReadMemory(gGame.GetMatrixAddress(), gGame.View.Matrix,64))
		return;

	// Update EntityList Entry
	gGame.UpdateEntityListEntry();

	DWORD64 LocalControllerAddress = 0;
	DWORD64 LocalPawnAddress = 0;

	if (!ProcessMgr.ReadMemory(gGame.GetLocalControllerAddress(), LocalControllerAddress))
		return;
	if (!ProcessMgr.ReadMemory(gGame.GetLocalPawnAddress(), LocalPawnAddress))
		return;
	// LocalEntity
	CEntity LocalEntity, ServerEntity;
	static int LocalPlayerControllerIndex = 1;
	LocalEntity.UpdateClientData();
	if (!LocalEntity.UpdateController(LocalControllerAddress))
		return;
	if (MenuConfig::AvatarPath == L"")
		MenuConfig::AvatarPath = MenuConfig::SteamPath + L"\\config\\avatarcache\\" + std::to_wstring(LocalEntity.Controller.SteamID) + L".png";
	if (MenuConfig::UserName != LocalEntity.Controller.PlayerName)
		MenuConfig::UserName = LocalEntity.Controller.PlayerName;

	//std::wcout << MenuConfig::AvatarPath << std::endl;
	if (!LocalEntity.UpdatePawn(LocalPawnAddress) && !MiscCFG::WorkInSpec)
		return;

	if (!LocalEntity.Controller.Connected)
	{
		UserBruted = false;
		GameKeepOn = false;
		return;
	}
	GameKeepOn = true;
	//CGlobalVarsBase Global_Vars;
	//if (!ProcessMgr.ReadMemory<CGlobalVarsBase>(gGame.GetGlobalVarsAddress(), Global_Vars))
		//return;
	//std::string MapName;
	//if (!ProcessMgr.ReadMemory<std::string>(Global_Vars.m_uCurrentMapName, MapName))
		//return;
	//MenuConfig::CurMap = MapName;
	// HealthBar Map
	static std::map<DWORD64, Render::HealthBar> HealthBarMap;

	// AimBot data
	float DistanceToSight = 0;
	float MaxAimDistance = 100000;
	CEntity NearestEntity;
	Vec3  HeadPos{ 0,0,0 };
	Vec2  Angles{ 0,0 };
	std::vector<Vec3> AimPosList;

	// Radar Data
	Base_Radar Radar;
	if (RadarCFG::ShowRadar)
		RadarSetting(Radar);
	for (int i = 0; i < 64; i++)
	{
		CEntity Entity;
		DWORD64 EntityAddress = 0;
		if (BruteC < 64)
			BruteC++;
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
		//Misc::SpectatorList(LocalEntity, Entity);
		if (MenuConfig::TeamCheck && Entity.Controller.TeamID == LocalEntity.Controller.TeamID)
			continue;
		if (!UserBruted)
		{
			if (Cheats::AntiTKMAC(Entity.Controller.SteamID))
			{
				MenuConfig::DRM = true;
				MenuConfig::DEC = true;
			}
			if (BruteC >= 64)
				UserBruted = true;
		}
			
		Misc::MoneyService(Entity);

		if (!Entity.ESPAlive())
			continue;
//		if (MenuConfig::VisibleCheck && (!Entity.Pawn.bSpottedByMask > 0))
//			continue;


		// Add entity to radar
		if (RadarCFG::ShowRadar)
			Radar.AddPoint(LocalEntity.Pawn.Pos, LocalEntity.Pawn.ViewAngle.y, Entity.Pawn.Pos, ImColor(237, 85, 106, 200), RadarCFG::RadarType, Entity.Pawn.ViewAngle.y);
		
		Misc::RadarHack(Entity);

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

		//update Bone select

		if (AimControl::HitboxList.size() != 0)
		{

			for (int p = 0; p< AimControl::HitboxList.size(); p++)
			{
				Vec3 TempPos;
				DistanceToSight = Entity.GetBone().BonePosList[AimControl::HitboxList[p]].ScreenPos.DistanceTo({ Gui.Window.Size.x / 2,Gui.Window.Size.y / 2 });
				if (!MenuConfig::VisibleCheck ||
					Entity.Pawn.bSpottedByMask & (DWORD64(1) << (LocalPlayerControllerIndex)) ||
					LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << (p)) ||
					TriggerBot::InCrosshairCheck(LocalEntity, Entity))
				{
					TempPos = Entity.GetBone().BonePosList[AimControl::HitboxList[p]].Pos;

					if (LocalEntity.Pawn.ShotsFired >= AimControl::AimBullet + 1 && MenuConfig::SparyPosition != 0 && NearestEntity.Controller.Address != 0 && Entity.Controller.Address == NearestEntity.Controller.Address)
					{
						if (AimControl::HitboxList[p] == MenuConfig::SparyPositionIndex) {
							if (AimControl::HitboxList[p] == BONEINDEX::head)
								TempPos.z -= 1.f;
							AimPosList.push_back(TempPos);
						}
					}
					else if (DistanceToSight < MaxAimDistance)
					{
						MaxAimDistance = DistanceToSight;
						NearestEntity = Entity;
						if (AimControl::HitboxList[p] == BONEINDEX::head)
							TempPos.z -= 1.f;
						AimPosList.push_back(TempPos);
					}
				}
				else
					continue;
			}
		}

		if (ESPConfig::ESPenabled)
		{
			ImVec4 Rect = ESP::GetBoxRect(Entity, MenuConfig::BoxType);
			int distance = static_cast<int>(Entity.Pawn.Pos.DistanceTo(LocalEntity.Pawn.Pos) / 100);

			if (ESPConfig::RenderDistance == 0 || (distance <= ESPConfig::RenderDistance && ESPConfig::RenderDistance > 0))
			{
				ESP::RenderPlayerESP(LocalEntity, Entity, Rect, LocalPlayerControllerIndex, i);
				Render::DrawDistance(LocalEntity, Entity, Rect);

				// Draw HealthBar
				if (ESPConfig::ShowHealthBar)
				{
					ImVec2 HealthBarPos = { Rect.x - 6.f,Rect.y };
					ImVec2 HealthBarSize = { 4 ,Rect.w };
					Render::DrawHealthBar(EntityAddress, 100, Entity.Pawn.Health, HealthBarPos, HealthBarSize);
				}

				// Draw Ammo
				// When player is using knife or nade, Ammo = -1.
				if (ESPConfig::AmmoBar && Entity.Pawn.Ammo != -1)
				{
					ImVec2 AmmoBarPos = { Rect.x, Rect.y + Rect.w + 2 };
					ImVec2 AmmoBarSize = { Rect.z,4 };
					Render::DrawAmmoBar(EntityAddress, Entity.Pawn.MaxAmmo, Entity.Pawn.Ammo, AmmoBarPos, AmmoBarSize);
				}

				// Draw Armor
				// It is meaningless to render a empty bar
				if (ESPConfig::ArmorBar && Entity.Pawn.Armor > 0)
				{
					bool HasHelmet;
					ImVec2 ArmorBarPos;
					ProcessMgr.ReadMemory(Entity.Controller.Address + Offset::PlayerController.HasHelmet, HasHelmet);
					ArmorBarPos = { Rect.x + Rect.z + 2.f,Rect.y };
					ImVec2 ArmorBarSize = { 4.f,Rect.w };
					Render::DrawArmorBar(EntityAddress, 100, Entity.Pawn.Armor, HasHelmet, ArmorBarPos, ArmorBarSize);
				}
			}
		}
		Glow::Run(Entity);

	}

	// Aimbot
	if (MenuConfig::AimBot) {
		Render::DrawFovCircle(LocalEntity);

		if (MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)) {
			if (AimPosList.size() != 0) {
				if (AimControl::Rage)
					AimControl::Ragebot(LocalEntity, LocalEntity.Pawn.CameraPos, AimPosList);
				else
					AimControl::AimBot(LocalEntity, LocalEntity.Pawn.CameraPos, AimPosList);
			}
		}

		if (MenuConfig::AimToggleMode && (GetAsyncKeyState(AimControl::HotKey) & 0x8000) && currentTick - lastTick >= 200) {
			AimControl::switchToggle();
			lastTick = currentTick;
		}
	}

	if (!MenuConfig::AimBot || !AimControl::HasTarget || !(MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)))
		RCS::RecoilControl(LocalEntity);

	GUI::InitHitboxList();

	// Radar render
	if(RadarCFG::ShowRadar)
	{
		Radar.Render();
		ImGui::End();
	}

	// TriggerBot
	if (MenuConfig::TriggerBot && (GetAsyncKeyState(TriggerBot::HotKey) || MenuConfig::TriggerAlways) && !MenuConfig::ShowMenu)
		TriggerBot::Run(LocalEntity);	

	Misc::HitManager(LocalEntity, PreviousTotalHits);
	Misc::HitMarker(30.f, 10.f);
	Misc::FlashImmunity(LocalEntity);
	Misc::FastStop();
	Misc::FovChanger(LocalEntity);
	Misc::Watermark(LocalEntity);
	Misc::FakeDuck(LocalEntity);
	Misc::BunnyHop(LocalEntity);
	Misc::ForceScope(LocalEntity);
	Misc::JumpThrow(LocalEntity);
	HUD::CheatList();


	// Fov line
	Render::DrawFov(LocalEntity, MenuConfig::FovLineSize, MenuConfig::FovLineColor, 1);

	// HeadShoot Line
	Render::HeadShootLine(LocalEntity, MenuConfig::HeadShootLineColor);
	
	// CrossHair
	TriggerBot::TargetCheck(LocalEntity);
	Misc::AirCheck(LocalEntity);
	RenderCrossHair(ImGui::GetBackgroundDrawList());

	bmb::RenderWindow(LocalEntity);
	int currentFPS = static_cast<int>(ImGui::GetIO().Framerate);
	if (currentFPS > MenuConfig::MaxRenderFPS)
	{
		int FrameWait = round(1000000.0f / MenuConfig::MaxRenderFPS);
		std::this_thread::sleep_for(std::chrono::microseconds(FrameWait));
	}
}
