#pragma once
#include <Windows.h>
#include "Utils/ProcessManager.hpp"
#include "Utils/Helpers.h"

namespace Offset
{
	inline DWORD ForceJump;
	inline DWORD ForceCrouch;
	inline DWORD ForceForward;
	inline DWORD ForceLeft;
	inline DWORD ForceRight;

	inline DWORD EntityList;
	inline DWORD Matrix;
	inline DWORD ViewAngle;
	inline DWORD LocalPlayerController;
	inline DWORD LocalPlayerPawn;
	inline DWORD GlobalVars;
	inline DWORD InventoryServices;
	inline DWORD PlantedC4;
	inline DWORD InputSystem;
	inline DWORD Sensitivity;
	inline DWORD Pointer;

	struct
	{
		DWORD Health = 0x334;
		DWORD TeamID = 0x3CB;
		DWORD IsAlive = 0x7EC;
		DWORD PlayerPawn = 0x7E4;
		DWORD iszPlayerName = 0x638;
		DWORD EnemySensor = 0x1440;
		DWORD GravityScale = 0x444;
	}Entity;

	struct
	{
		DWORD MovementServices = 0x1140;		// CPlayer_MovementServices*
		DWORD WeaponServices = 0x1100;			// CPlayer_WeaponServices*
		DWORD BulletServices = 0x1718;			// CCSPlayer_BulletServices*
		DWORD CameraServices = 0x1138;			// CPlayer_CameraServices*
		DWORD ViewModelServices = 0x12C8;		// CPlayer_ViewModelServices*
		DWORD pClippingWeapon = 0x1308;			// C_CSWeaponBase*

		DWORD ViewModel = 0x40;				// CCSPlayer_ViewModelServices::m_hViewModel
		DWORD StartAccount = 0x1490;
		DWORD isScoped = 0x1400;
		DWORD TotalHit = 0x40;
		DWORD Pos = 0x127C;						// C_BasePlayerPawn::m_vOldOrigin
		DWORD MaxHealth = 0x330;				// C_BaseEntity::m_iMaxHealth
		DWORD CurrentHealth = 0x334;			// C_BaseEntity::m_iHealth
		DWORD GameSceneNode = 0x318;			// C_BaseEntity::m_pGameSceneNode
		DWORD BoneArray = 0x1E0;				// CSkeletonInstance_::m_modelState + CGameSceneNode_::m_vecOrigin
		DWORD angEyeAngles = 0x1578;
		DWORD vecLastClipCameraPos = 0x12EC;
		DWORD iShotsFired = 0x147C;
		DWORD flFlashMaxAlpha = 0x14C8;
		DWORD flFlashDuration = 0x14CC;
		DWORD aimPunchAngle = 0x177C;			// C_CSPlayerPawn::m_aimPunchAngle
		DWORD aimPunchCache = 0x17A0;
		DWORD iIDEntIndex = 0x15A4;
		DWORD iTeamNum = 0x3CB;
		DWORD DesiredFov = 0x6CC;
		DWORD iFovStart = 0x214;
		DWORD fFlags = 0x3D4;
		DWORD bSpottedByMask = 0x1698 + 0xC;	// C_CSPlayerPawnBase::entitySpottedState + EntitySpottedState_t::bSpottedByMask
	} Pawn;

	struct
	{
		DWORD RealTime = 0x00;
		DWORD FrameCount = 0x04;
		DWORD MaxClients = 0x10;
		DWORD IntervalPerTick = 0x14;
		DWORD CurrentTime = 0x2C;
		DWORD CurrentTime2 = 0x30;
		DWORD TickCount = 0x40;
		DWORD IntervalPerTick2 = 0x44;
		DWORD CurrentNetchan = 0x0048;
		DWORD CurrentMap = 0x0180;
		DWORD CurrentMapName = 0x0188;
	} GlobalVar;

	struct
	{
		DWORD m_hPawn = 0x604;
		DWORD m_pObserverServices = 0x1118;
		DWORD m_hObserverTarget = 0x44;
		DWORD m_hController = 0x1294;
		DWORD PawnArmor = 0x7F4;
		DWORD HasDefuser = 0x7F8;
		DWORD HasHelmet = 0x7F9;
	} PlayerController;

	struct
	{
		DWORD AttributeManager = 0x1098;		// C_AttributeContainer
		DWORD FallbackPaintKit = 0x1548;
		DWORD FallbackSeed = 0x154C;
		DWORD FallbackWear = 0x1550;
		DWORD FallbackStatTrak = 0x1554;
		DWORD szCustomName = 0x2D0;

		DWORD EntityQuality = 0x1BC;			// EconItemView::m_iEntityQuality
		DWORD ItemIDHigh = 0x1D0;				// EconItemView::m_iItemIDHigh
	} EconEntity;

	struct
	{
		DWORD ClippingWeapon = 0x1308;			// WeaponBase
		DWORD WeaponDataPTR = 0x368;
		DWORD szName = 0xC20;
		DWORD Clip1 = 0x15C8;					// C_BasePlayerWeapon::m_iClip1
		DWORD MaxClip = 0x1FC;					// CBasePlayerWeaponVData::m_iMaxClip1
		DWORD CycleTime = 0xC44;
		DWORD Penetration = 0xD4C;
		DWORD WeaponType = 0x248;
		DWORD Inaccuracy = 0xC8C;				// CCSWeaponBaseVData::m_flInaccuracyMove
		DWORD inReload = 0x1744;

		DWORD WeaponSize = 0x50;
		DWORD ActiveWeapon = 0x58;
		DWORD Item = 0x50;						// C_AttributeContainer::m_Item
		DWORD ItemDefinitionIndex = 0x1BA;
		DWORD m_MeshGroupMask = 0x180;			// CModelState::m_MeshGroupMask
	} WeaponBaseData;

	struct
	{
		DWORD m_bBeingDefused = 0xF14;
		DWORD m_flDefuseCountDown = 0xF28;
		DWORD m_nBombSite = 0xEDC;
	} C4;

	struct
	{
		DWORD MoneyServices = 0x6F8;
		DWORD Account = 0x40;
		DWORD TotalCashSpent = 0x48;
		DWORD CashSpentThisRound = 0x4C;
	} InGameMoneyServices;

	struct // C_BaseCSGrenadeProjectile
	{ 
		DWORD nSmokeEffectTickBegin = 0x1160; // int32_t
		DWORD bDidSmokeEffect = 0x1164; // bool
		DWORD nRandomSeed = 1; // int32_t
		DWORD vSmokeColor = 0x116C; // Vector
		DWORD vSmokeDetonationPos = 0x1178; // Vector
		DWORD VoxelFrameData = 0x1188; // CUtlVector<uint8_t>
		DWORD bSmokeVolumeDataReceived = 0x11A0; // bool
		uintptr_t bSmokeEffectSpawned = 0x11A1; // bool
	} SmokeGrenadeProjectile; 

	namespace Signatures
	{
		const std::string ForceForward = "48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 4C 6B E3";
		const std::string ForceLeft = "48 8D 05 ?? ?? ?? ?? 48 89 45 ? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 4C 6B E3";
		const std::string ForceRight = "48 8D 05 ?? ?? ?? ?? 48 89 45 ? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 4C 6B E3";
		const std::string ForceJump = "48 8D 05 ?? ?? ?? ?? 48 89 4D ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 4C 6B E3";
		const std::string ForceCrouch = "48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 48 8D 05 ?? ?? ?? ?? 48 89 45 ?? 4C 6B E3";

		const std::string InventoryServices = "E8 ?? ?? ?? ?? 8B 45 D0 48 8B 55 D8";
		const std::string GlobalVars = "48 89 0D ?? ?? ?? ?? 48 89 41";
		const std::string EntityList = "48 8B 0D ?? ?? ?? ?? 48 89 7C 24 ?? 8B FA C1 EB";
		const std::string LocalPlayerController = "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 4F";
		const std::string ViewAngles = "4C 8B 0D ?? ?? ?? ?? 48 8D 04 5B";
		const std::string ViewMatrix = "48 8D 0D ?? ?? ?? ?? 48 C1 E0 06";
		const std::string LocalPlayerPawn = "48 8D 05 ?? ?? ?? ?? C3 CC CC CC CC CC CC CC CC 48 83 EC ?? 8B 0D";
		const std::string PlantedC4 = "48 8B 15 ?? ?? ?? ?? FF C0 48 8D 4C 24 40";
		const std::string InputSystem = "48 89 05 ?? ?? ?? ?? 48 8D 05";
		const std::string dwSensitivity = "48 8B 05 ?? ?? ?? ?? 48 8B 40 ?? F3 0F 10 00 F3 0F 59 86";
	}

	bool UpdateOffsets();
}
