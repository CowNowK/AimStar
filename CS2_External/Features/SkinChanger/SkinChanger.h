#pragma once
#include "..\..\Entity.h"
#include "..\..\MenuConfig.hpp"
#include "..\..\OS-ImGui\imgui\imgui.h"

/*
Not working at all.
I'm not sure what this is supposed to do.
And not interested in fixing it.
--Ukia 10/09/2024
*/

namespace SkinChanger
{
	inline DWORD64 GetWeaponServices(const CEntity& LocalPlayer)
	{
		DWORD64 WeaponServices;
		ProcessMgr.ReadMemory(LocalPlayer.Pawn.Address + Offset::C_BasePlayerPawn.m_pWeaponServices, WeaponServices);

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
		DWORD64 WeaponHandle;
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
		ProcessMgr.ReadMemory(Weapons + Offset::EconEntity.AttributeManager + Offset::WeaponBaseData.Item + Offset::WeaponBaseData.ItemDefinitionIndex, WeaponID);
		
		return WeaponID;
	}

	inline DWORD64 GameSenceNode(DWORD64 CHandle)
	{
		DWORD64 GameSenceNode;
		ProcessMgr.ReadMemory(CHandle + Offset::C_BaseEntity.m_pGameSceneNode, GameSenceNode);

		return GameSenceNode;
	}

	inline int SetMaskGroup(DWORD64 GameSenceNode)
	{
		int GroupMask;
		ProcessMgr.ReadMemory(GameSenceNode + Offset::WeaponBaseData.m_MeshGroupMask, GroupMask);

		return GroupMask;
	}

	inline DWORD64 GetViewModelServices(const CEntity& LocalPlayer)
	{
		DWORD64 ViewModelServices;
		ProcessMgr.ReadMemory(LocalPlayer.Pawn.Address + Offset::C_CSPlayerPawnBase.m_pViewModelServices, ViewModelServices);

		return ViewModelServices;
	}

	inline DWORD64 GetViewHandle(DWORD64 ViewModelServices)
	{
		DWORD64 ViewHandle;
		ProcessMgr.ReadMemory(ViewModelServices + Offset::CCSPlayer_ViewModelServices.m_hViewModel, ViewHandle);

		return ViewHandle;
	}

	inline void SetWeaponSkin(int weaponID, DWORD64 weapon, DWORD64 weaponGameSceneNode, int MeshGroupMask);
	extern void Run(const CEntity& LocalPlayer, CGame Game);
}