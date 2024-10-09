#pragma once
#include <Windows.h>
#include "Utils/ProcessManager.hpp"
#include "Utils/Helpers.h"

#include "a2x/offsets.hpp"
#include "a2x/client_dll.hpp"
#include "a2x/buttons.hpp"
/*
We using a2x header for quick PoC while develop & to figure out type of data
In the end, we use our own offset system by reading offset.yaml for release version.
*/
class CGlobalVarsBase
{
public:
	float m_realtime; //0x0000
	int32_t m_framecount; //0x0004
	float m_frametime; //0x0008
	float m_abs_frametime; //0x000C
	int32_t m_maxclients; //0x0010
	char pad_0014[28]; //0x0014
	float m_frametime2; //0x0030
	float m_curtime; //0x0034
	float m_curtime2; //0x0038
	char pad_003C[20]; //0x003C
	int32_t m_tickcount; //0x0050
	char pad_0054[292]; //0x0054
	uint64_t m_current_map; //0x0178
	uint64_t m_current_mapname; //0x0180
};
namespace Offset
{

	inline DWORD ForceJump = cs2_dumper::buttons::jump;
	inline DWORD ForceCrouch = cs2_dumper::buttons::duck;
	inline DWORD ForceForward = cs2_dumper::buttons::forward;
	inline DWORD ForceLeft = cs2_dumper::buttons::left;
	inline DWORD ForceRight = cs2_dumper::buttons::right;

	inline DWORD EntityList = cs2_dumper::offsets::client_dll::dwEntityList;
	inline DWORD Matrix = cs2_dumper::offsets::client_dll::dwViewMatrix;
	inline DWORD ViewAngle = cs2_dumper::offsets::client_dll::dwViewAngles;
	inline DWORD LocalPlayerController = cs2_dumper::offsets::client_dll::dwLocalPlayerController;
	inline DWORD LocalPlayerPawn = cs2_dumper::offsets::client_dll::dwLocalPlayerPawn;
	inline DWORD GlobalVars = cs2_dumper::offsets::client_dll::dwGlobalVars;
	inline DWORD CSGOInput = cs2_dumper::offsets::client_dll::dwCSGOInput;
	inline DWORD InventoryServices;
	inline DWORD PlantedC4 = cs2_dumper::offsets::client_dll::dwPlantedC4;
	inline DWORD InputSystem = cs2_dumper::offsets::client_dll::dwCSGOInput;
	inline DWORD Sensitivity = cs2_dumper::offsets::client_dll::dwSensitivity;
	inline DWORD Pointer;
//cvar stuff
	struct
	{
		DWORD mp_teammates_are_enemies = 0x19BA550;
	} Cvar;//put hardcoded offsets here.but should can be updated via yaml(need manual dump tho)
//entity stuff
	struct
	{
		DWORD m_flGravityScale = cs2_dumper::schemas::client_dll::C_BaseEntity::m_flGravityScale;
		DWORD m_iMaxHealth = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iMaxHealth;				// C_BaseEntity::m_iMaxHealth
		DWORD m_iHealth = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iHealth;						// C_BaseEntity::m_iHealth
		DWORD m_pGameSceneNode = cs2_dumper::schemas::client_dll::C_BaseEntity::m_pGameSceneNode;		// C_BaseEntity::m_pGameSceneNode
		DWORD m_vecAbsVelocity = cs2_dumper::schemas::client_dll::C_BaseEntity::m_vecAbsVelocity;
		DWORD m_fFlags = cs2_dumper::schemas::client_dll::C_BaseEntity::m_fFlags;
		DWORD m_iTeamNum = cs2_dumper::schemas::client_dll::C_BaseEntity::m_iTeamNum;
	} C_BaseEntity;//依旧使用匿名结构体，避免日后对变量类型命名规范化导致的冲突

	struct
	{
		DWORD GlowFunction = cs2_dumper::schemas::client_dll::C_BaseModelEntity::m_Glow + cs2_dumper::schemas::client_dll::CGlowProperty::m_bGlowing;
		DWORD GlowColorOverride = cs2_dumper::schemas::client_dll::C_BaseModelEntity::m_Glow + cs2_dumper::schemas::client_dll::CGlowProperty::m_glowColorOverride;
	} C_BaseModelEntity;
//gamescenenode stuff
	struct
	{
		DWORD m_vecOrigin = cs2_dumper::schemas::client_dll::CGameSceneNode::m_vecOrigin;
	} CGameSceneNode;
//contoller stuff
	struct
	{
		DWORD m_hPawn = cs2_dumper::schemas::client_dll::CBasePlayerController::m_hPawn;
		DWORD m_iszPlayerName = cs2_dumper::schemas::client_dll::CBasePlayerController::m_iszPlayerName;
		DWORD m_iDesiredFOV = cs2_dumper::schemas::client_dll::CBasePlayerController::m_iDesiredFOV;
		DWORD m_steamID = cs2_dumper::schemas::client_dll::CBasePlayerController::m_steamID;
	} CBasePlayerController;

	struct
	{
		DWORD m_bPawnIsAlive = cs2_dumper::schemas::client_dll::CCSPlayerController::m_bPawnIsAlive;
		DWORD m_bControllingBot = cs2_dumper::schemas::client_dll::CCSPlayerController::m_bControllingBot;
		DWORD m_bEverPlayedOnTeam = cs2_dumper::schemas::client_dll::CCSPlayerController::m_bEverPlayedOnTeam;
		DWORD m_hPlayerPawn = cs2_dumper::schemas::client_dll::CCSPlayerController::m_hPlayerPawn;
		DWORD m_sSanitizedPlayerName = cs2_dumper::schemas::client_dll::CCSPlayerController::m_sSanitizedPlayerName;
		DWORD m_iPawnArmor = cs2_dumper::schemas::client_dll::CCSPlayerController::m_iPawnArmor;
		DWORD m_bPawnHasDefuser = cs2_dumper::schemas::client_dll::CCSPlayerController::m_bPawnHasDefuser;
		DWORD m_bPawnHasHelmet = cs2_dumper::schemas::client_dll::CCSPlayerController::m_bPawnHasHelmet;
		DWORD m_iPing = cs2_dumper::schemas::client_dll::CCSPlayerController::m_iPing;
		DWORD m_pInGameMoneyServices = cs2_dumper::schemas::client_dll::CCSPlayerController::m_pInGameMoneyServices;
	} CCSPlayerController;
//pawn stuff
	struct
	{
		DWORD m_pMovementServices = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_pMovementServices;		// CPlayer_MovementServices*
		DWORD m_pWeaponServices = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_pWeaponServices;			// CPlayer_WeaponServices*
		DWORD m_pCameraServices = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_pCameraServices;			// CPlayer_CameraServices*
		DWORD m_pObserverServices = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_pObserverServices;
		DWORD m_vOldOrigin = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_vOldOrigin;							// C_BasePlayerPawn::m_vOldOrigin
		DWORD m_hController = cs2_dumper::schemas::client_dll::C_BasePlayerPawn::m_hController;
	} C_BasePlayerPawn;

	struct
	{
		DWORD m_pViewModelServices = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_pViewModelServices;		// CPlayer_ViewModelServices*
		DWORD m_pClippingWeapon = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_pClippingWeapon;			// C_CSWeaponBase*
		DWORD m_angEyeAngles = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_angEyeAngles;
		DWORD m_vecLastClipCameraPos = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_vecLastClipCameraPos;
		DWORD m_flFlashMaxAlpha = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_flFlashMaxAlpha;
		DWORD m_flFlashDuration = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_flFlashDuration;
		DWORD m_iIDEntIndex = cs2_dumper::schemas::client_dll::C_CSPlayerPawnBase::m_iIDEntIndex;
	} C_CSPlayerPawnBase;
	
	struct
	{

		DWORD m_pBulletServices = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_pBulletServices;			// CCSPlayer_BulletServices*
		DWORD m_bIsScoped = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_bIsScoped;
		DWORD m_bIsDefusing = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_bIsDefusing;
		DWORD m_ArmorValue = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_ArmorValue;// C_CSPlayerPawn::m_ArmorValue
		DWORD m_iShotsFired = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_iShotsFired;
		DWORD m_aimPunchAngle = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_aimPunchAngle;			// C_CSPlayerPawn::m_aimPunchAngle
		DWORD m_aimPunchCache = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_aimPunchCache;
		DWORD m_bIsBuyMenuOpen = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_bIsBuyMenuOpen;
		DWORD m_bWaitForNoAttack = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_bWaitForNoAttack;
		DWORD m_bSpottedByMask = cs2_dumper::schemas::client_dll::C_CSPlayerPawn::m_entitySpottedState + cs2_dumper::schemas::client_dll::EntitySpottedState_t::m_bSpottedByMask;	// C_CSPlayerPawn::entitySpottedState + EntitySpottedState_t::bSpottedByMask
	} C_CSPlayerPawn;
//C4 stuff
	struct
	{
		DWORD m_flC4Blow = cs2_dumper::schemas::client_dll::C_PlantedC4::m_flC4Blow;
		DWORD m_bC4Activated = cs2_dumper::schemas::client_dll::C_PlantedC4::m_bC4Activated;
		DWORD m_bBeingDefused = cs2_dumper::schemas::client_dll::C_PlantedC4::m_bBeingDefused;
		DWORD m_flDefuseCountDown = cs2_dumper::schemas::client_dll::C_PlantedC4::m_flDefuseCountDown;
		DWORD m_nBombSite = cs2_dumper::schemas::client_dll::C_PlantedC4::m_nBombSite;
	} C_PlantedC4;
//services stuff
	struct
	{
		DWORD m_hObserverTarget = cs2_dumper::schemas::client_dll::CPlayer_ObserverServices::m_hObserverTarget;
	} CPlayer_ObserverServices;
	struct
	{
		DWORD m_hViewModel = cs2_dumper::schemas::client_dll::CCSPlayer_ViewModelServices::m_hViewModel;				// CCSPlayer_ViewModelServices::m_hViewModel
	} CCSPlayer_ViewModelServices;
	struct
	{
		DWORD m_nCrouchState = cs2_dumper::schemas::client_dll::CPlayer_MovementServices_Humanoid::m_nCrouchState;
	} CPlayer_MovementServices_Humanoid;
	struct
	{
		DWORD m_iFOVStart = cs2_dumper::schemas::client_dll::CCSPlayerBase_CameraServices::m_iFOVStart;
	} CCSPlayerBase_CameraServices;
	struct
	{
		DWORD m_totalHitsOnServer = cs2_dumper::schemas::client_dll::CCSPlayer_BulletServices::m_totalHitsOnServer;
	} CCSPlayer_BulletServices;
	
	
//random misc stuff
	struct
	{
		DWORD AttributeManager = cs2_dumper::schemas::client_dll::C_EconEntity::m_AttributeManager;		// C_AttributeContainer
		DWORD FallbackPaintKit = cs2_dumper::schemas::client_dll::C_EconEntity::m_nFallbackPaintKit;
		DWORD FallbackSeed = cs2_dumper::schemas::client_dll::C_EconEntity::m_nFallbackSeed;
		DWORD FallbackWear = cs2_dumper::schemas::client_dll::C_EconEntity::m_flFallbackWear;
		DWORD FallbackStatTrak = cs2_dumper::schemas::client_dll::C_EconEntity::m_nFallbackStatTrak;
		DWORD szCustomName = cs2_dumper::schemas::client_dll::C_EconItemView::m_szCustomName;
		DWORD EntityQuality = cs2_dumper::schemas::client_dll::C_EconItemView::m_iEntityQuality;			// EconItemView::m_iEntityQuality
		DWORD ItemIDHigh = cs2_dumper::schemas::client_dll::C_EconItemView::m_iItemIDHigh;				// EconItemView::m_iItemIDHigh
	} EconEntity;

	struct
	{
		DWORD WeaponDataPTR = cs2_dumper::schemas::client_dll::C_BaseEntity::m_nSubclassID + 0x08;
		DWORD szName = cs2_dumper::schemas::client_dll::CCSWeaponBaseVData::m_szName;
		DWORD Clip1 = cs2_dumper::schemas::client_dll::C_BasePlayerWeapon::m_iClip1;					// C_BasePlayerWeapon::m_iClip1
		DWORD MaxClip = cs2_dumper::schemas::client_dll::CBasePlayerWeaponVData::m_iMaxClip1;					// CBasePlayerWeaponVData::m_iMaxClip1
		DWORD CycleTime = cs2_dumper::schemas::client_dll::CCSWeaponBaseVData::m_flCycleTime;
		DWORD Penetration = cs2_dumper::schemas::client_dll::CCSWeaponBaseVData::m_flPenetration;
		DWORD WeaponType = cs2_dumper::schemas::client_dll::CCSWeaponBaseVData::m_WeaponType;
		DWORD Inaccuracy = cs2_dumper::schemas::client_dll::CCSWeaponBaseVData::m_flInaccuracyMove;				// CCSWeaponBaseVData::m_flInaccuracyMove
		DWORD inReload = cs2_dumper::schemas::client_dll::C_CSWeaponBase::m_bInReload;
		DWORD m_nNumBullets = cs2_dumper::schemas::client_dll::CCSWeaponBaseVData::m_nNumBullets;
		DWORD WeaponSize = 0x50;
		DWORD ActiveWeapon = cs2_dumper::schemas::client_dll::CPlayer_WeaponServices::m_hActiveWeapon;
		DWORD Item = cs2_dumper::schemas::client_dll::C_AttributeContainer::m_Item;						// C_AttributeContainer::m_Item
		DWORD ItemDefinitionIndex = cs2_dumper::schemas::client_dll::C_EconItemView::m_iItemDefinitionIndex;
		DWORD m_MeshGroupMask = cs2_dumper::schemas::client_dll::CModelState::m_MeshGroupMask;			// CModelState::m_MeshGroupMask
	} WeaponBaseData;

	struct
	{
		DWORD Account = cs2_dumper::schemas::client_dll::CCSPlayerController_InGameMoneyServices::m_iAccount;
		DWORD TotalCashSpent = cs2_dumper::schemas::client_dll::CCSPlayerController_InGameMoneyServices::m_iTotalCashSpent;
		DWORD CashSpentThisRound = cs2_dumper::schemas::client_dll::CCSPlayerController_InGameMoneyServices::m_iCashSpentThisRound;
	} InGameMoneyServices;

	struct // C_BaseCSGrenadeProjectile
	{ 
		DWORD nSmokeEffectTickBegin = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_nSmokeEffectTickBegin; // int32_t
		DWORD bDidSmokeEffect = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_bDidSmokeEffect; // bool
		DWORD nRandomSeed = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_nRandomSeed; // int32_t
		DWORD vSmokeColor = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_vSmokeColor; // Vector
		DWORD vSmokeDetonationPos = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_vSmokeDetonationPos; // Vector
		DWORD VoxelFrameData = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_VoxelFrameData; // CUtlVector<uint8_t>
		DWORD bSmokeVolumeDataReceived = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_bSmokeVolumeDataReceived; // bool
		uintptr_t bSmokeEffectSpawned = cs2_dumper::schemas::client_dll::C_SmokeGrenadeProjectile::m_bSmokeEffectSpawned; // bool
	} SmokeGrenadeProjectile; 
	
	struct 
	{
		DWORD BoneArray = 0x1F0; // NO NO NO... Just a hard coding. // cs2_dumper::schemas::client_dll::CSkeletonInstance::m_modelState + cs2_dumper::schemas::client_dll::CGameSceneNode::m_vecOrigin;//cs2_dumper::schemas::client_dll::CGameSceneNode::m_vecOrigin;				// CSkeletonInstance_::m_modelState + CGameSceneNode_::m_vecOrigin
	} Pawn;
	
	bool UpdateOffsets();
}
