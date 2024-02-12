#include "SkinChanger.h"

namespace SkinChanger
{

	inline void Run(const CEntity& LocalPlayer, DWORD64 EntityList)
	{
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

			// Get Group Mask
			auto WeaponGameSenceNode = GameSenceNode(weapon);
			auto WeaponGroupMask = SetMaskGroup(WeaponGameSenceNode);
		}
	}
}