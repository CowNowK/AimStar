#include "SkinChanger.h"

// not used "yet"
void SkinChanger::SetWeaponSkin(int weaponID, DWORD64 weapon, DWORD64 weaponGameSceneNode, int MeshGroupMask)
{
	//Set Mask
	if (MeshGroupMask != 2)
	{
		int Mask = 2;
		SafeMgr.SafeWrite<int>(weaponGameSceneNode + 0x160 + Offset::WeaponBaseData.m_MeshGroupMask, Mask);
	}

	// Test
	if (weaponID == 7)
	{
		int Paint = 180;
		SafeMgr.SafeWrite(weapon + Offset::EconEntity.FallbackPaintKit, Paint);
	}

	int seed = 0, stat = 100, quality = 2, high = -1;
	float wear = 0.00001f;
	std::string CustomName = "Test Weapon";
	//set global fallback values
	SafeMgr.SafeWrite(weapon + Offset::EconEntity.FallbackSeed, seed);
	SafeMgr.SafeWrite(weapon + Offset::EconEntity.FallbackStatTrak, stat);
	SafeMgr.SafeWrite(weapon + Offset::EconEntity.AttributeManager + Offset::WeaponBaseData.Item + Offset::EconEntity.szCustomName, CustomName);
	SafeMgr.SafeWrite(weapon + Offset::EconEntity.AttributeManager + Offset::WeaponBaseData.Item + Offset::EconEntity.EntityQuality, quality);
	// Set item id high
	SafeMgr.SafeWrite(weapon + Offset::EconEntity.AttributeManager + Offset::WeaponBaseData.Item + Offset::EconEntity.ItemIDHigh, high);
	
	}

void SkinChanger::Run(const CEntity& LocalPlayer, CGame Game)
{
	auto EntityList = Game.GetEntityListAddress();
	auto WeaponService = GetWeaponServices(LocalPlayer);
	auto WeaponSize = GetWeaponSize(WeaponService);

	for (int i = 0; i < WeaponSize; i++)
	{
		// Get Weapon Handle
		auto WeaponHandle = GetWeaponHandle(WeaponService, i);
		if (!WeaponHandle)
			continue;

		// Get Controller From Handle
		auto weapon = GetControllerFromHandle(EntityList, WeaponHandle);
		if (!weapon)
			continue;

		// Get Weapon ID
		auto WeaponID = GetWeaponID(weapon);

		// Get Weapon MeshGroupMask
		auto WeaponGameSenceNode = GameSenceNode(weapon);
		auto WeaponGroupMask = SetMaskGroup(WeaponGameSenceNode);
		SetWeaponSkin(WeaponID, weapon, WeaponGameSenceNode, WeaponGroupMask);

			// Get View MeshGroupMask
		auto ViewModelServices = GetViewModelServices(LocalPlayer);
		auto ViewModelHandle = GetViewHandle(ViewModelServices);
		auto ViewModel = GetControllerFromHandle(EntityList, ViewModelHandle);
		auto ViewGameSenceNode = GameSenceNode(ViewModel);
		auto ViewGroupMask = SetMaskGroup(ViewGameSenceNode);

		int Mask = 2;
		SafeMgr.SafeWrite(ViewGameSenceNode + 0x160 + Offset::WeaponBaseData.m_MeshGroupMask, Mask);
	}
}