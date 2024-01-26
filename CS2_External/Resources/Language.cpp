#include "Language.h"

#include "Languages/Danish.h"
#include "Languages/Dutch.h"
#include "Languages/Francais.h"
#include "Languages/German.h"
#include "Languages/Hungarian.h"
#include "Languages/Korean.h"
#include "Languages/Polish.h"
#include "Languages/Portuguese.h"
#include "Languages/Ruassian.h"
#include "Languages/SimplifiedChinese.h"
#include "Languages/Slovak.h"
#include "Languages/Turkish.h"
#include "Languages/Czech.h"
#include "Languages/Spanish.h"
#include "Languages/Romanian.h"

namespace Lang
{
	void ChangeLang(int LangIndex)
	{
		switch (LangIndex)
		{
		case 0:
			English();
			break;
		case 1:
			Danish();
			break;
		case 2:
			German();
			break;
		case 3:
			Polish();
			break;
		case 4:
			Portuguese();
			break;
		case 5:
			Russian();
			break;
		case 6:
			SimplifiedChinese();
			break;
		case 7:
			Slovak();
			break;
		case 8:
			French();
			break;
			//case 9:
				//Korean();
				//break;
		case 9:
			Turkish();
			break;
		case 10:
			Hungarian();
			break;
		case 11:
			Dutch();
			break;
		case 12:
			Czech();
			break;
		case 13:
			Spanish();
			break;
		case 14:
			Romanian();
			break;
		default:
			English();
			break;
		}
	}
}