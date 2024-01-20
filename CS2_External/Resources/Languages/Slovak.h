#pragma once
#pragma once
#include "..\Language.h"
namespace Lang
{
	// Translated by @faster_bbc
	inline void Slovak()
	{
		Global.Author = u8"faster_bbc";
		Global.Date = u8"2023/11/29";

		Global.SwitchButton = u8"Zapnúť";
		Global.FeatureSettings = u8"Nastavenia";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Zaoblenie Boxu";
		ESPtext.FilledBox = u8"Vyplnený box";
		ESPtext.FilledAlpha = u8"Prehliadnosť vyplneného boxu";
		ESPtext.Skeleton = u8"Kostra";
		ESPtext.HeadBox = u8"Box na hlavu";
		ESPtext.EyeRay = u8"Čiara videnia hráča";
		ESPtext.HealthBar = u8"Hrubá čiara života";
		ESPtext.Weapon = u8"Zbraň";
		ESPtext.Distance = u8"Zdialenosť";
		ESPtext.PlayerName = u8"Meno";
		ESPtext.SnapLine = u8"Čiara ku hráčovy";
		ESPtext.LinePosList = u8"Lokácia čiary";
		ESPtext.VisCheck = u8"Skontrolovať viditelnosť";
		ESPtext.Preview = u8"Náhľad";
		ESPtext.CollapseHead = u8"Sex ESP";
		ESPtext.Penis = u8"Penis/Pipik/Bakuľa";
		ESPtext.PenisLength = u8"Dĺžka";
		ESPtext.PenisSize = u8"Velkosť";
		ESPtext.MultiColor = u8"Viacfarebné";
		ESPtext.MultiColTip = u8"Funguje len vtedy, keď má rámček nezaoblené rohy.";
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
		AimbotText.FeatureName = u8" Aimbo";
		AimbotText.HotKeyList = u8"Tlačítko";
		AimbotText.Toggle = u8"Prepínaci mód";
		AimbotText.DrawFov = u8"Ukázať FOV";
		AimbotText.VisCheck = u8"Skontrolovať viditelnosť";
		AimbotText.JumpCheck = u8"Iba na zemy";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Hladkosť";
		AimbotText.BoneList = u8"Kosť";
		AimbotText.Tip = u8"Aimbot nebude fungovať pokiaľ je menu otvorené";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Štýl";
		RadarText.CustomCheck = u8"Vlastné";
		RadarText.CrossLine = u8"Kríž";
		RadarText.SizeSlider = u8"Velkosť bodky";
		RadarText.ProportionSlider = u8"Proporcia";
		RadarText.RangeSlider = u8"Rozsah";
		RadarText.AlphaSlider = u8"Prehliadnosť pozadia okna";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Tlačítko";
		TriggerText.Toggle = u8"Vždy aktívne";
		TriggerText.DelaySlider = u8"Oneskorenie výstrelu";
		TriggerText.FakeShotSlider = u8"Trvanie výstrelu";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Crosshair";
		CrosshairsText.PresetList = u8"Predvoľby";
		CrosshairsText.ColorEditor = u8"Farba crosshairu";
		CrosshairsText.Dot = u8"Stredová bodka";
		CrosshairsText.DotSizeSlider = u8"Velkosť bodky";
		CrosshairsText.Outline = u8"Obrys";
		CrosshairsText.Crossline = u8"Kríž";
		CrosshairsText.hLengthSlider = u8"Horizontálna dĺžka";
		CrosshairsText.vLengthSilder = u8"Vertikálna dĺžka";
		CrosshairsText.GapSlider = u8"Medzera";
		CrosshairsText.ThicknessSlider = u8"Hrubosť";
		CrosshairsText.tStyle = u8"T štýl";
		CrosshairsText.Circle = u8"Kruh";
		CrosshairsText.RadiusSlider = u8"Velkosť Kruhu";
		CrosshairsText.TargetCheck = u8"Zameriavanie Crosshairu";
		CrosshairsText.TeamCheck = u8"Kontrola tímu";

		// Misc
		MiscText.FeatureName = u8" Ostatné";
		MiscText.ThemeList = u8"Téma";
		MiscText.StyleList = u8"Štýl";
		MiscText.HeadshotLine = u8"Čiara strely do hlavy";
		MiscText.SpecCheck = u8"Cheat keď si divák";
		MiscText.NoFlash = u8"Žiadny flash";
		MiscText.HitSound = u8"Zvuk udretia";
		MiscText.bmbTimer = u8"Časovač bomby";
		MiscText.SpecList = u8"List divákov";
		MiscText.Bhop = u8"Automatické skákanie";
		MiscText.Watermark = u8"Vodný znak";
		MiscText.CheatList = u8"List cheatov";
		MiscText.TeamCheck = u8"Kontrola tímu";
		MiscText.AntiRecord = u8"Bypass OBS";

		MiscText.LanguageList = u8"Jazyk";

		// Config Menu
		ConfigText.FeatureName = u8" Nastavenie";
		ConfigText.Load = u8"Načítať vybraté";
		ConfigText.Save = u8"Uložiť vybraté";
		ConfigText.Delete = u8"Vymazať vybraté";
		ConfigText.Reset = u8"Obnoviť vybraté";
		ConfigText.Create = u8"Vytvoriť nastavenie";
		ConfigText.OpenFolder = u8"Otvoriť priečinok";
		ConfigText.SeparateLine = u8"Uložiť nastavenie";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" Prečítaj ma";
		ReadMeText.LastUpdate = u8"Posledná aktulizácia: ";
		ReadMeText.SourceButton = u8" Zdrojový Kód";
		ReadMeText.DiscordButton = u8" Pripoj sa na Discord";
		ReadMeText.OffsetsTitle = u8"Offsety:";
	}
}