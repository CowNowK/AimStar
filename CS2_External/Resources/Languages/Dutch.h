#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Dutch()
	{
		Global.Author = u8"Toepas";
		Global.Date = u8"2023/12/11";

		Global.SwitchButton = u8"Activeer";
		Global.FeatureSettings = u8"Instellingen";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Omlijning";
		ESPtext.BoxRounding = u8"Omlijning Afronding";
		ESPtext.FilledBox = u8"Gevulde Omlijning";
		ESPtext.FilledAlpha = u8"Gevulde Omlijning zichtbaarheid";
		ESPtext.Skeleton = u8"Skelet";
		ESPtext.HeadBox = u8"Hoofd Omlijning";
		ESPtext.EyeRay = u8"Oogstraal";
		ESPtext.HealthBar = u8"Levensbalk";
		ESPtext.Weapon = u8"Wapon";
		ESPtext.Distance = u8"Afstand";
		ESPtext.PlayerName = u8"Naam";
		ESPtext.SnapLine = u8"SnapLine";
		ESPtext.LinePosList = u8"LinePos";
		ESPtext.VisCheck = u8"Zichtbaarheid Check";
		ESPtext.Preview = u8"Voorbeeldvenster";
		ESPtext.CollapseHead = u8"SexyESP";
		ESPtext.Penis = u8"Laat Penis zien";
		ESPtext.PenisLength = u8"Lengte";
		ESPtext.PenisSize = u8"Grootte";
		ESPtext.MultiColor = u8"Veelkleurig";
		ESPtext.MultiColTip = u8"Werkt alleen als de omlijning niet-afgeronde hoeken heeft.";
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
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Knop";
		AimbotText.Toggle = u8"Schakelmodus";
		AimbotText.DrawFov = u8"Teken Fov";
		AimbotText.VisCheck = u8"Alleen zichtbaar";
		AimbotText.JumpCheck = u8"Alleen op de grond";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Zachtheid";
		AimbotText.BoneList = u8"Bot";
		AimbotText.Tip = u8"Aimbot werkt niet terwijl het menu geopend is";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Aangepast";
		RadarText.CrossLine = u8"Kruis lijn";
		RadarText.SizeSlider = u8"Puntgrootte";
		RadarText.ProportionSlider = u8"Proportie";
		RadarText.RangeSlider = u8"Afstand";
		RadarText.AlphaSlider = u8"Vensterachtergrond Zichtbaarheid";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Sneltoets";
		TriggerText.Toggle = u8"Altijd Actief";
		TriggerText.DelaySlider = u8"Schot Vertraging";
		TriggerText.FakeShotSlider = u8"Schot Duur";

		// Crosshairs
		CrosshairsText.FeatureName = u8"Richtpunt";
		CrosshairsText.PresetList = u8"Voorinstellingen";
		CrosshairsText.ColorEditor = u8"Richtpunt Kleur";
		CrosshairsText.Dot = u8"Middel punt";
		CrosshairsText.DotSizeSlider = u8"Punt Grootte";
		CrosshairsText.Outline = u8"Omlijning";
		CrosshairsText.Crossline = u8"Kruis lijn";
		CrosshairsText.hLengthSlider = u8"Horizontale Lengte";
		CrosshairsText.vLengthSilder = u8"Verticale Lengte";
		CrosshairsText.GapSlider = u8"Gat";
		CrosshairsText.ThicknessSlider = u8"Dikte";
		CrosshairsText.tStyle = u8"T Style";
		CrosshairsText.Circle = u8"Cirkel";
		CrosshairsText.RadiusSlider = u8"Cirkel Straal";
		CrosshairsText.TargetCheck = u8"Richtpunt";
		CrosshairsText.TeamCheck = u8"Teamcontrole";

		// Misc
		MiscText.FeatureName = u8" Gemengd";
		MiscText.ThemeList = u8"Thema";
		MiscText.StyleList = u8"Stijl";
		MiscText.HeadshotLine = u8"Headshot Lijn";
		MiscText.SpecCheck = u8"Cheat in Toeschouwen";
		MiscText.NoFlash = u8"Geen Flash";
		MiscText.HitSound = u8"Raakgeluid";
		MiscText.bmbTimer = u8"Bom Timer";
		MiscText.SpecList = u8"Toeschouwe Lijst";
		MiscText.Bhop = u8"Bunny Hop";
		MiscText.Watermark = u8"Watermark";
		MiscText.CheatList = u8"Cheat Lijst";
		MiscText.TeamCheck = u8"TeamCcontrole";
		MiscText.AntiRecord = u8"Omzeil OBS";

		MiscText.LanguageList = u8"Taal";

		// Config Menu
		ConfigText.FeatureName = u8"Configuratie";
		ConfigText.Load = u8"Laad Geselecteerde";
		ConfigText.Save = u8"Sla Geselecteerde Op";
		ConfigText.Delete = u8"Verwijder Geselecteerde";
		ConfigText.Reset = u8"Stel Configuratie opnieuw in";
		ConfigText.Create = u8"Maak Configuratie";
		ConfigText.OpenFolder = u8"Open Folder";
		ConfigText.SeparateLine = u8"Sla Configuratie Op";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" Leesmij";
		ReadMeText.LastUpdate = u8" Laatste update: ";
		ReadMeText.SourceButton = u8" Broncode";
		ReadMeText.DiscordButton = u8" Kom In De Discord";
		ReadMeText.OffsetsTitle = u8" Compensaties:";
	}
}