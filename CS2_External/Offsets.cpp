#include "Offsets.h"
#include "MenuConfig.hpp"
#include "Utils/ConfigSaver.hpp"
#include <filesystem>

namespace fs = std::filesystem;

DWORD64 SearchOffsets(std::string Signature, DWORD64 ModuleAddress)
{
	std::vector<DWORD64> TempAddressList;
	DWORD64 Address = 0;
	DWORD Offsets = 0;

	TempAddressList = ProcessMgr.SearchMemory(Signature, ModuleAddress, ModuleAddress + 0x4000000);

	if (TempAddressList.size() <= 0)
		return 0;

	if (!ProcessMgr.ReadMemory<DWORD>(TempAddressList.at(0) + 3, Offsets))
		return 0;

	Address = TempAddressList.at(0) + Offsets + 7;
	return Address;
}

bool Offset::UpdateOffsets()
{
	using namespace Updater;

	std::string offsetPath = MenuConfig::path + "\\Offsets\\offsets.yaml";

	if (!fs::exists(offsetPath)) {
		std::cerr << "Failed to locate offsets directory: " << offsetPath << std::endl;
		return false;
	}

	YAML::Node offset = YAML::LoadFile(offsetPath);

	Offset::EntityList = MyConfigSaver::ReadData(offset["client.dll"]["dwEntityList"], 0);
	Offset::LocalPlayerController = MyConfigSaver::ReadData(offset["client.dll"]["dwLocalPlayerController"], 0);
	Offset::Matrix = MyConfigSaver::ReadData(offset["client.dll"]["dwViewMatrix"], 0);
	Offset::GlobalVars = MyConfigSaver::ReadData(offset["client.dll"]["dwGlobalVars"], 0);
	Offset::ViewAngle = MyConfigSaver::ReadData(offset["client.dll"]["dwViewAngles"], 0);
	Offset::LocalPlayerPawn = MyConfigSaver::ReadData(offset["client.dll"]["dwLocalPlayerPawn"], 0);
	Offset::PlantedC4 = MyConfigSaver::ReadData(offset["client.dll"]["dwPlantedC4"], 0);
	Offset::Sensitivity = MyConfigSaver::ReadData(offset["client.dll"]["dwSensitivity"], 0);
	Offset::InputSystem = MyConfigSaver::ReadData(offset["inputsystem.dll"]["dwInputSystem"], 0);
	Offset::ForceJump = MyConfigSaver::ReadData(offset["client.dll"]["jump"], 0);
	Offset::ForceCrouch = MyConfigSaver::ReadData(offset["client.dll"]["duck"], 0);
	Offset::ForceForward = MyConfigSaver::ReadData(offset["client.dll"]["forward"], 0);
	Offset::ForceLeft = MyConfigSaver::ReadData(offset["client.dll"]["left"], 0);
	Offset::ForceRight = MyConfigSaver::ReadData(offset["client.dll"]["right"], 0);

	Offset::Entity.IsAlive = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerController"]["m_bPawnIsAlive"], 0);
	Offset::Entity.PlayerPawn = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerController"]["m_hPlayerPawn"], 0);
	Offset::Entity.iszPlayerName = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerController"]["m_iszPlayerName"], 0);
	Offset::Entity.GravityScale = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_flGravityScal"], 0);

	Offset::Pawn.MovementServices = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_pMovementServices"], 0);
	Offset::Pawn.WeaponServices = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_pWeaponServices"], 0);
	Offset::Pawn.BulletServices = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_pBulletServices"], 0);
	Offset::Pawn.CameraServices = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_pCameraServices"], 0);
	Offset::Pawn.ViewModelServices = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawnBase"]["m_pViewModelServices"], 0);

	Offset::Pawn.pClippingWeapon = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawnBase"]["m_pClippingWeapon"], 0);
	Offset::Pawn.ViewModel = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayer_ViewModelServices"]["m_hViewModel"], 0);
	Offset::Pawn.CrouchState = MyConfigSaver::ReadData(offset["client.dll"]["CPlayer_MovementServices_Humanoid"]["m_nCrouchState"], 0);
	Offset::Pawn.isScoped = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_bIsScoped"], 0);
	Offset::Pawn.isDefusing = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_bIsDefusing"], 0);
	Offset::Pawn.TotalHit = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayer_BulletServices"]["m_totalHitsOnServer"], 0);
	Offset::Pawn.Pos = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_vOldOrigin"], 0);
	Offset::Pawn.CurrentArmor = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_ArmorValue"], 0);
	Offset::Pawn.MaxHealth = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_iMaxHealth"], 0);
	Offset::Pawn.CurrentHealth = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_iHealth"], 0);
	Offset::Pawn.GameSceneNode = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_pGameSceneNode"], 0);

	Offset::PlayerController.m_hPawn = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerController"]["m_hPawn"], 0);
	Offset::PlayerController.m_pObserverServices = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_pObserverServices"], 0);
	Offset::PlayerController.m_hObserverTarget = MyConfigSaver::ReadData(offset["client.dll"]["CPlayer_ObserverServices"]["m_hObserverTarget"], 0);
	Offset::PlayerController.m_hController = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_hController"], 0);
	Offset::PlayerController.PawnArmor = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_iPawnArmor"], 0);
	Offset::PlayerController.HasDefuser = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_bPawnHasDefuser"], 0);
	Offset::PlayerController.HasHelmet = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_bPawnHasHelmet"], 0);

	return true;
}
