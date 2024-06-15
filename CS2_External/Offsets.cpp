#include "Offsets.h"
#include "MenuConfig.hpp"
#include "Utils/ConfigSaver.hpp"
#include <filesystem>
#include "Utils/XorStr.h"

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

	std::string offsetPath = MenuConfig::path + XorStr("\\Offsets\\offsets.yaml");

	if (!fs::exists(offsetPath)) {
		if (fs::create_directories(MenuConfig::path + XorStr("\\Offsets")))
		{
			std::cout << XorStr("[Info] offsets folder created: ") << MenuConfig::path + XorStr("\\Offsets") << std::endl;
			std::cout << XorStr("       please visit https://aimstar.tkm.icu/updater to get the latest offset file.") << std::endl;
		}
		else
		{
			std::cerr << XorStr("Failed to locate offsets file: ") << offsetPath << std::endl;
			return false;
		}

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

	Offset::Entity.IsAlive = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_bPawnIsAlive"], 0);
	Offset::Entity.m_bControllingBot = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_bControllingBot"], 0); 
	Offset::Entity.PlayerPawn = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_hPlayerPawn"], 0);
	Offset::Entity.iszPlayerName = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerController"]["m_iszPlayerName"], 0);
	Offset::Entity.m_sSanitizedPlayerName = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_sSanitizedPlayerName"], 0);
	Offset::Entity.GravityScale = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_flGravityScal"], 0);
	Offset::Entity.GlowFunction = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseModelEntity"]["m_Glow"], 0) + MyConfigSaver::ReadData(offset["client.dll"]["CGlowProperty"]["m_bGlowing"], 0);
	Offset::Entity.GlowColorOverride = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseModelEntity"]["m_Glow"], 0) + MyConfigSaver::ReadData(offset["client.dll"]["CGlowProperty"]["m_glowColorOverride"], 0);

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
	Offset::Pawn.angEyeAngles = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawnBase"]["m_angEyeAngles"], 0);
	Offset::Pawn.vecLastClipCameraPos = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawnBase"]["m_vecLastClipCameraPos"], 0);
	Offset::Pawn.iShotsFired = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_iShotsFired"], 0);
	Offset::Pawn.flFlashMaxAlpha = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawnBase"]["m_flFlashMaxAlpha"], 0);
	Offset::Pawn.flFlashDuration = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawnBase"]["m_flFlashDuration"], 0);
	Offset::Pawn.aimPunchAngle = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_aimPunchAngle"], 0);
	Offset::Pawn.aimPunchCache = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_aimPunchCache"], 0);
	Offset::Pawn.iIDEntIndex = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawnBase"]["m_iIDEntIndex"], 0);
	Offset::Pawn.iTeamNum = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_iTeamNum"], 0);
	Offset::Pawn.DesiredFov = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerController"]["m_iDesiredFOV"], 0);
	Offset::Pawn.iFovStart = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerBase_CameraServices"]["m_iFOVStart"], 0);
	Offset::Pawn.fFlags = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_fFlags;"], 0);
	Offset::Pawn.bSpottedByMask = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_entitySpottedState"], 0) + MyConfigSaver::ReadData(offset["client.dll"]["EntitySpottedState_t"]["m_bSpottedByMask"], 0);
	Offset::Pawn.AbsVelocity = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_vecAbsVelocity"], 0);
	Offset::Pawn.IsBuying = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_bIsBuyMenuOpen"], 0);
	Offset::Pawn.m_bWaitForNoAttack = MyConfigSaver::ReadData(offset["client.dll"]["C_CSPlayerPawn"]["m_bWaitForNoAttack"], 0);

	Offset::WeaponBaseData.WeaponDataPTR = MyConfigSaver::ReadData(offset["client.dll"]["C_BaseEntity"]["m_nSubclassID"],0) + 0x08;
	Offset::WeaponBaseData.szName = MyConfigSaver::ReadData(offset["client.dll"]["CCSWeaponBaseVData"]["m_szName"], 0);
	Offset::WeaponBaseData.Clip1 = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerWeapon"]["m_iClip1"], 0);
	Offset::WeaponBaseData.MaxClip = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerWeaponVData"]["m_iMaxClip1"], 0);
	Offset::WeaponBaseData.CycleTime = MyConfigSaver::ReadData(offset["client.dll"]["CCSWeaponBaseVData"]["m_flCycleTime"], 0);
	Offset::WeaponBaseData.Penetration = MyConfigSaver::ReadData(offset["client.dll"]["CCSWeaponBaseVData"]["m_flPenetration"], 0);
	Offset::WeaponBaseData.WeaponType = MyConfigSaver::ReadData(offset["client.dll"]["CCSWeaponBaseVData"]["m_WeaponType"], 0);
	Offset::WeaponBaseData.Inaccuracy = MyConfigSaver::ReadData(offset["client.dll"]["CCSWeaponBaseVData"]["m_flInaccuracyMove"], 0);
	Offset::WeaponBaseData.inReload = MyConfigSaver::ReadData(offset["client.dll"]["C_CSWeaponBase"]["m_bInReload"], 0);
	Offset::WeaponBaseData.m_nNumBullets = MyConfigSaver::ReadData(offset["client.dll"]["CCSWeaponBaseVData"]["m_nNumBullets"], 0);
	Offset::WeaponBaseData.ActiveWeapon = MyConfigSaver::ReadData(offset["client.dll"]["CPlayer_WeaponServices"]["m_hActiveWeapon"], 0);
	Offset::WeaponBaseData.Item = MyConfigSaver::ReadData(offset["client.dll"]["C_AttributeContainer"]["m_Item"], 0);
	Offset::WeaponBaseData.ItemDefinitionIndex = MyConfigSaver::ReadData(offset["client.dll"]["C_EconItemView"]["m_iItemDefinitionIndex"], 0);
	Offset::WeaponBaseData.m_MeshGroupMask = MyConfigSaver::ReadData(offset["client.dll"]["CModelState"]["m_MeshGroupMask"], 0);

	Offset::PlayerController.m_hPawn = MyConfigSaver::ReadData(offset["client.dll"]["CBasePlayerController"]["m_hPawn"], 0);
	Offset::PlayerController.m_pObserverServices = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_pObserverServices"], 0);
	Offset::PlayerController.m_hObserverTarget = MyConfigSaver::ReadData(offset["client.dll"]["CPlayer_ObserverServices"]["m_hObserverTarget"], 0);
	Offset::PlayerController.m_hController = MyConfigSaver::ReadData(offset["client.dll"]["C_BasePlayerPawn"]["m_hController"], 0);
	Offset::PlayerController.PawnArmor = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_iPawnArmor"], 0);
	Offset::PlayerController.HasDefuser = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_bPawnHasDefuser"], 0);
	Offset::PlayerController.HasHelmet = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_bPawnHasHelmet"], 0);

	Offset::C4.m_bBeingDefused = MyConfigSaver::ReadData(offset["client.dll"]["C_PlantedC4"]["m_bBeingDefused"], 0);
	Offset::C4.m_flDefuseCountDown = MyConfigSaver::ReadData(offset["client.dll"]["C_PlantedC4"]["m_flDefuseCountDown"], 0);
	Offset::C4.m_nBombSite = MyConfigSaver::ReadData(offset["client.dll"]["C_PlantedC4"]["m_nBombSite"], 0);

	Offset::InGameMoneyServices.MoneyServices = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController"]["m_pInGameMoneyServices"], 0);
	Offset::InGameMoneyServices.Account = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController_InGameMoneyServices"]["m_iAccount"], 0);
	Offset::InGameMoneyServices.TotalCashSpent = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController_InGameMoneyServices"]["m_iTotalCashSpent"], 0);
	Offset::InGameMoneyServices.CashSpentThisRound = MyConfigSaver::ReadData(offset["client.dll"]["CCSPlayerController_InGameMoneyServices"]["m_iCashSpentThisRound"], 0);

	Offset::SmokeGrenadeProjectile.nSmokeEffectTickBegin = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_nSmokeEffectTickBegin"], 0);
	Offset::SmokeGrenadeProjectile.bDidSmokeEffect = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_bDidSmokeEffect"], 0);
	Offset::SmokeGrenadeProjectile.nRandomSeed = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_nRandomSeed"], 0);
	Offset::SmokeGrenadeProjectile.vSmokeColor = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_vSmokeColor"], 0);
	Offset::SmokeGrenadeProjectile.vSmokeDetonationPos = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_vSmokeDetonationPos"], 0);
	Offset::SmokeGrenadeProjectile.VoxelFrameData = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_VoxelFrameData"], 0);
	Offset::SmokeGrenadeProjectile.bSmokeVolumeDataReceived = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_bSmokeVolumeDataReceived"], 0);
	Offset::SmokeGrenadeProjectile.bSmokeEffectSpawned = MyConfigSaver::ReadData(offset["client.dll"]["C_SmokeGrenadeProjectile"]["m_bSmokeEffectSpawned"], 0);

	Offset::EconEntity.AttributeManager = MyConfigSaver::ReadData(offset["client.dll"]["C_EconEntity"]["m_AttributeManager"], 0);
	Offset::EconEntity.FallbackPaintKit = MyConfigSaver::ReadData(offset["client.dll"]["C_EconEntity"]["m_nFallbackPaintKit"], 0);
	Offset::EconEntity.FallbackSeed = MyConfigSaver::ReadData(offset["client.dll"]["C_EconEntity"]["m_nFallbackSeed"], 0);
	Offset::EconEntity.FallbackWear = MyConfigSaver::ReadData(offset["client.dll"]["C_EconEntity"]["m_flFallbackWear"], 0);
	Offset::EconEntity.FallbackStatTrak = MyConfigSaver::ReadData(offset["client.dll"]["C_EconEntity"]["m_nFallbackStatTrak"], 0);
	Offset::EconEntity.szCustomName = MyConfigSaver::ReadData(offset["client.dll"]["C_EconItemView"]["m_szCustomName"], 0);
	Offset::EconEntity.EntityQuality = MyConfigSaver::ReadData(offset["client.dll"]["C_EconItemView"]["m_iEntityQuality"], 0);
	Offset::EconEntity.ItemIDHigh = MyConfigSaver::ReadData(offset["client.dll"]["C_EconItemView"]["m_iItemIDHigh"], 0);

	return true;
}
