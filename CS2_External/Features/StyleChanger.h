#pragma once
#include "..\Utils\Style.h"

namespace StyleChanger
{
	inline void UpdateSkin(int Skin) noexcept
	{
		switch (Skin) {
		case 0:
			Styles::Style_AimStar();
			break;
		case 1:
			Styles::NiggaLose();
			break;
		default:
			break;
		}
	}
}