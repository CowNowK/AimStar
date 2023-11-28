#pragma once
#include "..\Utils\Style.h"

namespace StyleChanger
{
	inline void UpdateSkin(int Skin) noexcept
	{
		switch (Skin) {
		case 0:
			Styles::Style_EnemyMouse();
			break;
		case 1:
			Styles::Style_Hacker();
			break;
		case 2:
			Styles::Style_Classic();
			break;
		//case 3:
			//Styles::Style_Vape();
			//break;
		case 3:
			Styles::ModernDarkTheme();
			break;
		case 4:
			Styles::DeepDark();
			break;
		case 5:
			Styles::RoundGray();
			break;
		default:
			break;
		}
	}
}