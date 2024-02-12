#pragma once
#include "..\..\Entity.h"
#include "..\..\MenuConfig.hpp"
#include "..\..\OS-ImGui\imgui\imgui.h"

namespace SkinChanger
{
	inline DWORD64 GetWeaponServices(const CEntity& LocalPlayer)
	{
		DWORD64 WeaponServices;
		ProcessMgr.ReadMemory(LocalPlayer.Pawn.Address + Offset::Pawn.WeaponServices, WeaponServices);

		return WeaponServices;
	}

	inline int GetWeaponSize(DWORD64 WeaponServices)
	{
		int WeaponSize;
		ProcessMgr.ReadMemory(WeaponServices + Offset::WeaponBaseData.WeaponSize, WeaponSize);

		return WeaponSize;
	}

	inline DWORD64 GetWeaponHandle(DWORD64 WeaponServices, int WeaponIndex)
	{
		int WeaponHandle;
		ProcessMgr.ReadMemory((WeaponServices + Offset::WeaponBaseData.ActiveWeapon) + 0x4 * WeaponIndex, WeaponHandle);
		
		return WeaponHandle;
	}

	inline DWORD64 GetControllerFromHandle(DWORD64 EntityList, int CHandle)
	{
		CHandle = CHandle & 0x7FFF;

		DWORD64 List;
		ProcessMgr.ReadMemory(EntityList + 0x8 * (CHandle >> 0x9) + 0x10, List);
		auto ControllerAddress = List + 0x78 * (CHandle & 0x1FF);

		DWORD64 Controller;
		ProcessMgr.ReadMemory(ControllerAddress, Controller);

		return Controller;
	}

	inline int GetWeaponID(DWORD64 Weapons) noexcept
	{
		int WeaponID;
		ProcessMgr.ReadMemory(Weapons + Offset::WeaponBaseData.AttributeManager + Offset::WeaponBaseData.Item + Offset::WeaponBaseData.ItemDefinitionIndex, WeaponID);
		
		return WeaponID;
	}

	inline DWORD64 GameSenceNode(DWORD64 CHandle)
	{
		DWORD64 GameSenceNode;
		ProcessMgr.ReadMemory(CHandle + Offset::Pawn.GameSceneNode, GameSenceNode);

		return GameSenceNode;
	}

	inline int SetMaskGroup(DWORD64 GameSenceNode)
	{
		int GroupMask;
		ProcessMgr.ReadMemory(GameSenceNode + Offset::WeaponBaseData.m_MeshGroupMask, GroupMask);

		return GroupMask;
	}

	inline void SetWeaponSkin(int weaponID, int steamID, uintptr_t weapon, uintptr_t weaponGameSceneNode, int MeshGroupMask, int itemIDHigh);
	inline void Run(const CEntity& LocalPlayer, DWORD64 EntityList);
}