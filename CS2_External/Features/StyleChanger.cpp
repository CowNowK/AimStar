#include "StyleChanger.h"

namespace StyleChanger 
{
	void UpdateSkin(int Skin) noexcept
	{
		switch (Skin) {
		case 0:
			Styles::Style_AimStar();
			break;
		case 1:
			Styles::NiggaLose();
			break;
		case 2:
			Styles::aimwaste();
			break;
		default:
			break;
		}
	}
}
