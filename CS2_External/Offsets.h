#pragma once
#include <Windows.h>
#include "Utils/ProcessManager.hpp"
#include "Utils/Helpers.h"

namespace Offset
{
	inline DWORD EntityList;
	inline DWORD Matrix;
	inline DWORD ViewAngle;
	inline DWORD LocalPlayerController;
	inline DWORD LocalPlayerPawn;
	inline DWORD ForceJump;
	inline DWORD GlobalVars;
	inline DWORD InventoryServices;
	inline DWORD PlantedC4;

	struct
	{
		DWORD Health = 0x32C;
		DWORD TeamID = 0x3BF;
		DWORD IsAlive = 0x7F4;
		DWORD PlayerPawn = 0x7EC;
		DWORD iszPlayerName = 0x640;
		DWORD EnemySensor = 0x13E4;
		DWORD GravityScale = 0x434;
	}Entity;

	struct
	{
		DWORD isScoped = 0x13A8;
		DWORD WeaponServices = 0x10A8;			// C_BasePlayerPawn::m_pWeaponServices
		DWORD BulletServices = 0x16B8;			// C_CSPlayerPawn::m_pBulletServices
		DWORD TotalHit = 0x40;
		DWORD Pos = 0x1224;						// C_BasePlayerPawn::m_vOldOrigin
		DWORD MaxHealth = 0x328;				// C_BaseEntity::m_iMaxHealth
		DWORD CurrentHealth = 0x32C;			// C_BaseEntity::m_iHealth
		DWORD GameSceneNode = 0x310;			// C_BaseEntity::m_pGameSceneNode
		DWORD BoneArray = 0x1E0;				// CSkeletonInstance_::m_modelState + CGameSceneNode_::m_vecOrigin
		DWORD angEyeAngles = 0x1518;
		DWORD vecLastClipCameraPos = 0x1294;
		DWORD pClippingWeapon = 0x12B0;
		DWORD iShotsFired = 0x1420;
		DWORD flFlashDuration = 0x1470;
		DWORD aimPunchAngle = 0x171C;			// C_CSPlayerPawn::m_aimPunchAngle
		DWORD aimPunchCache = 0x1740;
		DWORD iIDEntIndex = 0x1544;
		DWORD iTeamNum = 0x3BF;
		DWORD CameraServices = 0x10E0;			// C_BasePlayerPawn::m_pCameraServices
		DWORD iFov = 0x210;
		DWORD iFovStart = 0x214;
		DWORD fFlags = 0x3C8;
		DWORD bSpottedByMask = 0x1644;			// C_CSPlayerPawnBase::entitySpottedState + EntitySpottedState_t::bSpottedByMask
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
		DWORD m_hPawn = 0x60C;
		DWORD m_pObserverServices = 0x10C0;
		DWORD m_hObserverTarget = 0x44;
		DWORD m_hController = 0x123C;
	} PlayerController;

	struct
	{
		DWORD ClippingWeapon = 0x12B0;
		DWORD WeaponDataPTR = 0x360;
		DWORD szName = 0xC18;
		DWORD Clip1 = 0x1570;					// C_BasePlayerWeapon::m_iClip1
		DWORD MaxClip = 0x1FC;					// CBasePlayerWeaponVData::m_iMaxClip1
		DWORD CycleTime = 0xC34;
		DWORD Penetration = 0xD3C;
		DWORD WeaponType = 0x240;
		DWORD Inaccuracy = 0xC7C;				// CCSWeaponBaseVData::m_flInaccuracyMove
	} WeaponBaseData;

	struct
	{
		DWORD m_bBeingDefused = 0xEBC;
		DWORD m_flDefuseCountDown = 0xED0;
		DWORD m_nBombSite = 0xE84;
	} C4;

	struct // C_BaseCSGrenadeProjectile
	{ 
		DWORD nSmokeEffectTickBegin = 0x1108; // int32_t
		DWORD bDidSmokeEffect = 0x110C; // bool
		DWORD nRandomSeed = 0x1110; // int32_t
		DWORD vSmokeColor = 0x1114; // Vector
		DWORD vSmokeDetonationPos = 0x1120; // Vector
		DWORD VoxelFrameData = 0x1130; // CUtlVector<uint8_t>
		DWORD bSmokeVolumeDataReceived = 0x1148; // bool
		uintptr_t bSmokeEffectSpawned = 0x1149; // bool
	} SmokeGrenadeProjectile; 

	namespace Signatures
	{
		const std::string InventoryServices = "E8 ?? ?? ?? ?? 8B 45 D0 48 8B 55 D8";
		const std::string GlobalVars = "48 89 0D ?? ?? ?? ?? 48 89 41";
		const std::string EntityList = "48 8B 0D ?? ?? ?? ?? 48 89 7C 24 ?? 8B FA C1 EB";
		const std::string LocalPlayerController = "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 4F";
		const std::string ViewAngles = "48 8B 0D ?? ?? ?? ?? E9 ?? ?? ?? ?? CC CC CC CC 40 55";
		const std::string ViewMatrix = "48 8D 0D ?? ?? ?? ?? 48 C1 E0 06";
		const std::string LocalPlayerPawn = "48 8D 05 ?? ?? ?? ?? C3 CC CC CC CC CC CC CC CC 48 83 EC ?? 8B 0D";
		const std::string ForceJump = "48 8B 05 ?? ?? ?? ?? 48 8D 1D ?? ?? ?? ?? 48 89 45";
		const std::string PlantedC4 = "48 8B 15 ?? ?? ?? ?? FF C0 48 8D 4C 24 40";
	}

	bool UpdateOffsets();
}
