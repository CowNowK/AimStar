#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Czech()
	{
		Global.Date = u8"2024/01/19";
		Global.Author = u8"Morfeusk";

		Global.SwitchButton = u8"Aktivovat";
		Global.FeatureSettings = u8"Nastavení";

		// ESP
		ESPtext.Toggle = u8"Toggle";
		ESPtext.FeatureName = u8"RÁMEČEK";
		ESPtext.Box = u8"Rámec";
		ESPtext.BoxRounding = u8"Zaoblení rámu";
		ESPtext.FilledBox = u8"Plný rámec";
		ESPtext.FilledAlpha = u8"Průhlednost plného rámu";
		ESPtext.Skeleton = u8"Kostlivec";
		ESPtext.HeadBox = u8"Hlavní rámec";
		ESPtext.EyeRay = u8"Ray očí";
		ESPtext.HealthBar = u8"Zdravotní stav";
		ESPtext.Weapon = u8"Zbraň";
		ESPtext.Distance = u8"Vzdálenost";
		ESPtext.PlayerName = u8"Jméno";
		ESPtext.SnapLine = u8"Směrovka";
		ESPtext.LinePosList = u8"Pozice čar";
		ESPtext.VisCheck = u8"Viditelnost kontrola";
		ESPtext.Preview = u8"Náhled okna rámce";
		ESPtext.CollapseHead = u8"SexyRámec";
		ESPtext.Penis = u8"UkázatPenis";
		ESPtext.PenisLength = u8"Délka";
		ESPtext.PenisSize = u8"Velikost";
		ESPtext.MultiColor = u8"Více barev";
		ESPtext.MultiColTip = u8"Funguje pouze pokud má rámeček nezaoblené rohy.";
		ESPtext.Outline = u8"Outline";
		ESPtext.BoxType = u8"Box Type:";
		ESPtext.HealthNum = u8"Health Number";
		ESPtext.Ammo = u8"Ammo";

		ESPtext.BoxType_Normal = u8"Normal";
		ESPtext.BoxType_Edge = u8"Dynamic";
		ESPtext.BoxType_Corner = u8"Corner";
		ESPtext.LinePos_1 = u8"Top";
		ESPtext.LinePos_2 = u8"Center";
		ESPtext.LinePos_3 = u8"Bottom";

		// Aimbot
		AimbotText.Enable = u8"Enable Aimbot";
		AimbotText.FeatureName = u8"Automatické zaměřování";
		AimbotText.HotKeyList = u8"Klávesa";
		AimbotText.Toggle = u8"Zůstat zapnutý";
		AimbotText.DrawFov = u8"Kreslit zorné pole";
		AimbotText.VisCheck = u8"Pouze viditelný";
		AimbotText.JumpCheck = u8"Pouze na zemi";
		AimbotText.FovSlider = u8"Zorné pole";
		AimbotText.SmoothSlider = u8"Hladkost";
		AimbotText.BoneList = u8"Kost";
		AimbotText.Tip = u8"Automatické zaměřování nefunguje s otevřeným oknem";

		// Radar
		RadarText.Toggle = u8"Show Radar";
		RadarText.FeatureName = u8"Radar";
		RadarText.StyleList = u8"Styl";
		RadarText.CustomCheck = u8"Vlastní nastavení";
		RadarText.CrossLine = u8"Křížová čára";
		RadarText.SizeSlider = u8"Velikost bodů";
		RadarText.ProportionSlider = u8"Poměr";
		RadarText.RangeSlider = u8"Rozsah";
		RadarText.AlphaSlider = u8"Průhlednost pozadí okna";

		// Triggerbot
		TriggerText.Enable = u8"Enable Triggerbot";
		TriggerText.FeatureName = u8"Spouštěč střelby";
		TriggerText.HotKeyList = u8"Zkratka";
		TriggerText.Toggle = u8"Vždy aktivní";
		TriggerText.DelaySlider = u8"Zpoždění střelby";
		TriggerText.FakeShotSlider = u8"Délka střelby";

		// Crosshairs
		CrosshairsText.Toggle = u8"Show Crosshairs";
		CrosshairsText.FeatureName = u8"Vlastní zaměřovač";
		CrosshairsText.PresetList = u8"Předvolby";
		CrosshairsText.ColorEditor = u8"Barva zaměřovače";
		CrosshairsText.Dot = u8"Středový bod";
		CrosshairsText.DotSizeSlider = u8"Velikost bodu";
		CrosshairsText.Outline = u8"Obrys";
		CrosshairsText.Crossline = u8"Křížová linka";
		CrosshairsText.hLengthSlider = u8"Horizontální velikost";
		CrosshairsText.vLengthSilder = u8"Vertikální velikost";
		CrosshairsText.GapSlider = u8"Rozestup";
		CrosshairsText.ThicknessSlider = u8"Tloušťka";
		CrosshairsText.tStyle = u8"Styl T";
		CrosshairsText.Circle = u8"Kruh";
		CrosshairsText.RadiusSlider = u8"Poloměr kruhu";
		CrosshairsText.TargetCheck = u8"Cílit na zaměřovač";
		CrosshairsText.TeamCheck = u8"Kontrola týmu";

		// Misc
		MiscText.FeatureName = u8"Různé";
		MiscText.ThemeList = u8"Téma";
		MiscText.StyleList = u8"Styl";
		MiscText.HeadshotLine = u8"Čáry na headshoty";
		MiscText.SpecCheck = u8"Seznam3";
		MiscText.NoFlash = u8"Bez blesku";
		MiscText.HitSound = u8"Zvuk zásahu";
		MiscText.bmbTimer = u8"Časový odpočet bomby";
		MiscText.SpecList = u8"Seznam diváků";
		MiscText.Bhop = u8"Skočit neustále";
		MiscText.Watermark = u8"Zobrazit FPS";
		MiscText.CheatList = u8"Seznam podvodů";
		MiscText.TeamCheck = u8"Kontrola týmu";
		MiscText.AntiRecord = u8"Neviditelný OBS Studio";
		MiscText.MoneyService = u8"Money Services";
		MiscText.ShowCashSpent = u8"Show Cash Spent";
		MiscText.EnemySensor = u8"Enemy Sensor";
		MiscText.RadarHack = u8"Radar Hack";
		MiscText.FastStop = u8"Fast Stop";
		MiscText.VisCheckDisable = u8"Visible Check DISABLED";

		MiscText.FakeDuck = u8"Fake Duck";

		MiscText.LanguageList = u8"Jazyk";

		// Konfigurační menu
		ConfigText.FeatureName = u8"Konfigurace(y)";
		ConfigText.MyConfigs = u8"Config List";
		ConfigText.Load = u8"Načíst výběr";
		ConfigText.Save = u8"Uložit výběr";
		ConfigText.Delete = u8"Smazat výběr";
		ConfigText.Reset = u8"Obnovit konfigurace";
		ConfigText.Create = u8"Vytvořit konfiguraci";
		ConfigText.OpenFolder = u8"Otevřít složku";
		ConfigText.SeparateLine = u8"Uložit konfiguraci";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Menu s informacemi
		ReadMeText.FeatureName = u8"Přečtěte si mě";
		ReadMeText.LastUpdate = u8"Poslední aktualizace: ";
		ReadMeText.SourceButton = u8"Zdrojový kód";
		ReadMeText.DiscordButton = u8"Připojit se k DISCORDU";
		ReadMeText.OffsetsTitle = u8"Kompensace:";
	}
}