#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Danish()
	{
		Global.Author = u8"5mmod";
		Global.Date = u8"2023/11/29";

		Global.SwitchButton = u8"Slå til";
		Global.FeatureSettings = u8"Indstillinger";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Boks";
		ESPtext.BoxRounding = u8"Boks Runding";
		ESPtext.FilledBox = u8"Fyldet Boks";
		ESPtext.FilledAlpha = u8"Fyldet Boks Alfa";
		ESPtext.Skeleton = u8"Skelet";
		ESPtext.HeadBox = u8"Hoved Boks";
		ESPtext.EyeRay = u8"Øjenståle";
		ESPtext.HealthBar = u8"Liv Bar";
		ESPtext.Weapon = u8"Våben";
		ESPtext.Distance = u8"Distance";
		ESPtext.PlayerName = u8"Navn";
		ESPtext.SnapLine = u8"SnapLinje";
		ESPtext.LinePosList = u8"LinjePos";
		ESPtext.VisCheck = u8"Synlig Tjek";
		ESPtext.Preview = u8"Visnings Vindue";
		ESPtext.CollapseHead = u8"Sexet ESP";
		ESPtext.Penis = u8"Vis Pik";
		ESPtext.PenisLength = u8"Længde";
		ESPtext.PenisSize = u8"Størrelse";
		ESPtext.MultiColor = u8"Multi-farvet";
		ESPtext.MultiColTip = u8"Virker kun, når boksen ikke har afrundede hjørner.";
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
		AimbotText.HotKeyList = u8"Nøgle";
		AimbotText.Toggle = u8"Skift tilstand";
		AimbotText.DrawFov = u8"Tegn Fov";
		AimbotText.VisCheck = u8"Synlig Kun";
		AimbotText.JumpCheck = u8"På jorden kun";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Glat";
		AimbotText.BoneList = u8"Knogle";
		AimbotText.Tip = u8"Aimbot vil ikke virke i mens menuen er åbent";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Stil";
		RadarText.CustomCheck = u8"Brugerdefineret";
		RadarText.CrossLine = u8"Krydslinje";
		RadarText.SizeSlider = u8"Point Størrelse";
		RadarText.ProportionSlider = u8"Del";
		RadarText.RangeSlider = u8"Afstand";
		RadarText.AlphaSlider = u8"Vindue Bagground Alfa";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"HotNøgle";
		TriggerText.Toggle = u8"Altid Aktiv";
		TriggerText.DelaySlider = u8"Skud forsinkelse";
		TriggerText.FakeShotSlider = u8"Skud Varighed";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Crosshairs";
		CrosshairsText.PresetList = u8"Forudindstillinger";
		CrosshairsText.ColorEditor = u8"Crosshairs Farvet";
		CrosshairsText.Dot = u8"Centrum Prik";
		CrosshairsText.DotSizeSlider = u8"Prik Størrelse";
		CrosshairsText.Outline = u8"Udelinje";
		CrosshairsText.Crossline = u8"Kryds Linje";
		CrosshairsText.hLengthSlider = u8"Vandret Længte";
		CrosshairsText.vLengthSilder = u8"Lodret Længte";
		CrosshairsText.GapSlider = u8"Mellemrum";
		CrosshairsText.ThicknessSlider = u8"Tykhed";
		CrosshairsText.tStyle = u8"T Stil";
		CrosshairsText.Circle = u8"Cirkel";
		CrosshairsText.RadiusSlider = u8"Cirkel Radius";
		CrosshairsText.TargetCheck = u8"Rettet Mod Crosshairs";
		CrosshairsText.TeamCheck = u8"Holdtjek";

		// Misc
		MiscText.FeatureName = u8" Diverse";
		MiscText.ThemeList = u8"Tema";
		MiscText.StyleList = u8"Stil";
		MiscText.HeadshotLine = u8"Hovedskud Linje";
		MiscText.SpecCheck = u8"Snyd i Spec";
		MiscText.NoFlash = u8"Ingen Flash";
		MiscText.HitSound = u8"Skud Lyd";
		MiscText.bmbTimer = u8"Bombe Timer";
		MiscText.SpecList = u8"Spec Liste";
		MiscText.Bhop = u8"Kanin Hop";
		MiscText.Watermark = u8"Vandmærke";
		MiscText.CheatList = u8"Snyd Liste";
		MiscText.TeamCheck = u8"HoldTjek";
		MiscText.AntiRecord = u8"Bypass OBS";

		MiscText.LanguageList = u8"Sprog";

		// Config Menu
		ConfigText.FeatureName = u8" Config";
		ConfigText.Load = u8"Load Valgt";
		ConfigText.Save = u8"Gem Valgt";
		ConfigText.Delete = u8"Slet Valgt";
		ConfigText.Reset = u8"Nulstil Config";
		ConfigText.Create = u8"Lav Config";
		ConfigText.OpenFolder = u8"Åben Mappe";
		ConfigText.SeparateLine = u8"Gem Config";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" LÆSMIG";
		ReadMeText.LastUpdate = u8"Sidste opdatering: ";
		ReadMeText.SourceButton = u8" Source Code";
		ReadMeText.DiscordButton = u8" Join Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}
}
