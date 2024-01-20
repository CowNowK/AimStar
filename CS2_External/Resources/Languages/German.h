#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void German()
	{
		Global.Author = u8"styx";
		Global.Date = u8"Unknown";
		Global.SwitchButton = u8"Aktivieren";
		Global.FeatureSettings = u8"Settings";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Kasten rundung";
		ESPtext.FilledBox = u8"Gefüllte Kiste";
		ESPtext.FilledAlpha = u8"Gefülltes Feld Alpha";
		ESPtext.Skeleton = u8"Skelett";
		ESPtext.HeadBox = u8"Kopf kasten";
		ESPtext.EyeRay = u8"Auge Strahl";
		ESPtext.HealthBar = u8"Gesundheitsbar";
		ESPtext.Weapon = u8"Waffe";
		ESPtext.Distance = u8"Distanz";
		ESPtext.PlayerName = u8"Name";
		ESPtext.SnapLine = u8"Schnapp Linie";
		ESPtext.LinePosList = u8"Linie Pos";
		ESPtext.VisCheck = u8"Sichtbarer Scheck";
		ESPtext.Preview = u8"Vorschaufenster";
		ESPtext.CollapseHead = u8"SexyESP";
		ESPtext.Penis = u8"Penis Zeigen";
		ESPtext.PenisLength = u8"Länge";
		ESPtext.PenisSize = u8"Größe";
		ESPtext.MultiColor = u8"Multi-Color";
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
		AimbotText.HotKeyList = u8"Key";
		AimbotText.Toggle = u8"Toggle Modus";
		AimbotText.DrawFov = u8"Draw Fov";
		AimbotText.VisCheck = u8"Nur sichtbar";
		AimbotText.JumpCheck = u8"Nur am Boden";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Smooth";
		AimbotText.BoneList = u8"Bone";
		AimbotText.Tip = u8"Aimbot funktioniert nicht, während das menü geöffnet ist.";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Custom";
		RadarText.CrossLine = u8"Cross Line";
		RadarText.SizeSlider = u8"Punktgröße";
		RadarText.ProportionSlider = u8"Proportion";
		RadarText.RangeSlider = u8"Range";
		RadarText.AlphaSlider = u8"Fensterhintergrund Alpha";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"HotKey";
		TriggerText.Toggle = u8"Immer aktiv";
		TriggerText.DelaySlider = u8"Shot Delay";
		TriggerText.FakeShotSlider = u8"Shot Duration";

		// Crosshair
		CrosshairsText.FeatureName = u8" Crosshairs";
		CrosshairsText.PresetList = u8"Presets";
		CrosshairsText.ColorEditor = u8"Crosshairs Color";
		CrosshairsText.Dot = u8"Center Dot";
		CrosshairsText.DotSizeSlider = u8"Punktgröße";
		CrosshairsText.Outline = u8"Outline";
		CrosshairsText.Crossline = u8"Cross Line";
		CrosshairsText.hLengthSlider = u8"Horizontale Länge";
		CrosshairsText.vLengthSilder = u8"Vertikale Länge";
		CrosshairsText.GapSlider = u8"Gap";
		CrosshairsText.ThicknessSlider = u8"Thickness";
		CrosshairsText.tStyle = u8"T Style";
		CrosshairsText.Circle = u8"Circle";
		CrosshairsText.RadiusSlider = u8"Kreisradius";
		CrosshairsText.TargetCheck = u8"Ziel Fadenkreuz";
		CrosshairsText.TeamCheck = u8"TeamCheck";

		// Misc
		MiscText.FeatureName = u8" Misc";
		MiscText.ThemeList = u8"Theme";
		MiscText.StyleList = u8"Style";
		MiscText.HeadshotLine = u8"Headshot Line";
		MiscText.SpecCheck = u8"Cheat in Spec";
		MiscText.NoFlash = u8"Kein Flash";
		MiscText.HitSound = u8"Hit Sound";
		MiscText.bmbTimer = u8"Bomben-Timer";
		MiscText.SpecList = u8"Spec List";
		MiscText.Bhop = u8"Bunny Hop";
		MiscText.Watermark = u8"Watermark";
		MiscText.CheatList = u8"Cheat Liste";
		MiscText.TeamCheck = u8"TeamCheck";
		MiscText.AntiRecord = u8"OBS umgehen";

		MiscText.LanguageList = u8"Sprache";

		// Config Menu
		ConfigText.FeatureName = u8" Config";
		ConfigText.Load = u8"Ausgewählte laden";
		ConfigText.Save = u8"Ausgewählte speichern";
		ConfigText.Delete = u8"Ausgewählte löschen";
		ConfigText.Reset = u8"Konfiguration zurücksetzen";
		ConfigText.Create = u8"Konfiguration erstellen";
		ConfigText.OpenFolder = u8"Ordner öffnen";
		ConfigText.SeparateLine = u8"Konfiguration speichern";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme menu
		ReadMeText.FeatureName = u8" README";
		ReadMeText.LastUpdate = u8"Letzte Aktualisierung: ";
		ReadMeText.SourceButton = u8" Quellcode";
		ReadMeText.DiscordButton = u8" Discord beitreten";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}
}