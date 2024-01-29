#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Romanian()
	{
		Global.Date = u8"2024/01/23";
		Global.Author = u8"JannesBonk :3";

		Global.SwitchButton = u8"Activează";
		Global.FeatureSettings = u8"Setări";

		// ESP
		ESPtext.Toggle = u8"Activează";
		ESPtext.FeatureName = u8"ESP";
		ESPtext.Box = u8"Ramă";
		ESPtext.BoxRounding = u8"Rotunjirea cadrului";
		ESPtext.FilledBox = u8"Umplerea cadrului";
		ESPtext.FilledAlpha = u8"Alpha Umplerea cadrului";
		ESPtext.Skeleton = u8"Schelet";
		ESPtext.HeadBox = u8"Rama capului";
		ESPtext.EyeRay = u8"Raza oculară";
		ESPtext.HealthBar = u8"Bara de HP";
		ESPtext.Weapon = u8"Armă";
		ESPtext.Distance = u8"Distanță";
		ESPtext.PlayerName = u8"Nume";
		ESPtext.SnapLine = u8"Linie snap";
		ESPtext.LinePosList = u8"Poziția linei snap";
		ESPtext.VisCheck = u8"Verificarea vizibilități";
		ESPtext.Preview = u8"Previzualizare";
		ESPtext.CollapseHead = u8"ESP barbos";
		ESPtext.Penis = u8"Pulă";
		ESPtext.PenisLength = u8"Lungimea pulii";
		ESPtext.PenisSize = u8"Mărimea pulii";
		ESPtext.MultiColor = u8"Culori multiple";
		ESPtext.MultiColTip = u8"Merge numai când rama n-are rotunjire";
		ESPtext.Outline = u8"Contur";
		ESPtext.BoxType = u8"Tipul ramei:";
		ESPtext.HealthNum = u8"Număr HP";
		ESPtext.Ammo = u8"Muniție";

		ESPtext.BoxType_Normal = u8"Normal";
		ESPtext.BoxType_Edge = u8"Dinamic";
		ESPtext.BoxType_Corner = u8"Colțuri";
		ESPtext.LinePos_1 = u8"Top";
		ESPtext.LinePos_2 = u8"Centru";
		ESPtext.LinePos_3 = u8"Jos";

		// Aimbot
		AimbotText.Enable = u8"Activează Aimbot";
		AimbotText.FeatureName = u8"Aimbot";
		AimbotText.HotKeyList = u8"Cheița";
		AimbotText.Toggle = u8"Mod toggle";
		AimbotText.DrawFov = u8"Arată FOV";
		AimbotText.VisCheck = u8"Verificarea vizibilități";
		AimbotText.JumpCheck = u8"Verificarea saltului";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Finețe";
		AimbotText.BoneList = u8"Hitbox-uri";
		AimbotText.Tip = u8"Aimbot-ul merge numai când meniul este închis";

		// Radar
		RadarText.Toggle = u8"Radar";
		RadarText.FeatureName = u8"Radar";
		RadarText.StyleList = u8"Stiluri";
		RadarText.CustomCheck = u8"Customizat";
		RadarText.CrossLine = u8"Linie cross";
		RadarText.SizeSlider = u8"Mărimea";
		RadarText.ProportionSlider = u8"Proporție";
		RadarText.RangeSlider = u8"Rază";
		RadarText.AlphaSlider = u8"Alpha fereastră";

		// Triggerbot
		TriggerText.Enable = u8"Activeză Triggerbot";
		TriggerText.FeatureName = u8"Triggerbot";
		TriggerText.HotKeyList = u8"Cheița";
		TriggerText.Toggle = u8"Mereu activ";
		TriggerText.DelaySlider = u8"Întârziere";
		TriggerText.FakeShotSlider = u8"Atac fals";

		// Crosshairs
		CrosshairsText.Toggle = u8"Arată crosshair";
		CrosshairsText.FeatureName = u8"Crosshairs";
		CrosshairsText.PresetList = u8"Presetări";
		CrosshairsText.ColorEditor = u8"Culoare";
		CrosshairsText.Dot = u8"Punct centrat";
		CrosshairsText.DotSizeSlider = u8"Mărime punct";
		CrosshairsText.Outline = u8"Contur";
		CrosshairsText.Crossline = u8"Linie cross";
		CrosshairsText.hLengthSlider = u8"Mărime orizontală";
		CrosshairsText.vLengthSilder = u8"Mărime verticală";
		CrosshairsText.GapSlider = u8"Mărime gaură";
		CrosshairsText.ThicknessSlider = u8"Grosime";
		CrosshairsText.tStyle = u8"Stil T";
		CrosshairsText.Circle = u8"Cerc";
		CrosshairsText.RadiusSlider = u8"Rază cerc:";
		CrosshairsText.TargetCheck = u8"Previzualizare țintă";
		CrosshairsText.TeamCheck = u8"Verificarea echipei";

		// Misc
		MiscText.FeatureName = u8"Různé";
		MiscText.ThemeList = u8"Temă";
		MiscText.StyleList = u8"Stil";
		MiscText.HeadshotLine = u8"Linie headshot";
		MiscText.SpecCheck = u8"Verificare spectator";
		MiscText.NoFlash = u8"Fără flash";
		MiscText.HitSound = u8"Hitsound";
		MiscText.bmbTimer = u8"Cronometru bombă";
		MiscText.SpecList = u8"Listă spectatori";
		MiscText.Bhop = u8"Bunnyhop";
		MiscText.Watermark = u8"Filigran";
		MiscText.CheatList = u8"Listă hackuri";
		MiscText.TeamCheck = u8"Verificarea echipei";
		MiscText.AntiRecord = u8"Anti captură";
		MiscText.MoneyService = u8"Serviciu bani";
		MiscText.ShowCashSpent = u8"Arată banii cheltuiți";
		MiscText.EnemySensor = u8"Senzor inamic";
		MiscText.RadarHack = u8"Radar hack";
		MiscText.FastStop = u8"Stop rapid";
		MiscText.VisCheckDisable = u8"Verificarea vizibilități oprită";
		MiscText.NoSmoke = u8"Fără fum";
		MiscText.SmokeColor = u8"Culoare fum";
		MiscText.FakeDuck = u8"Chrouch fals";

		MiscText.LanguageList = u8"Limba";

		// Konfigurační menu
		ConfigText.FeatureName = u8"Configurări";
		ConfigText.MyConfigs = u8"Configurări";
		ConfigText.Load = u8"Încarcă";
		ConfigText.Save = u8"Salvează";
		ConfigText.Delete = u8"Șterge";
		ConfigText.Reset = u8"Restează";
		ConfigText.Create = u8"Crează";
		ConfigText.OpenFolder = u8"Deschide folderul";
		ConfigText.SeparateLine = u8"Nou";
		ConfigText.AuthorName = u8"Autor";
		ConfigText.ConfigName = u8"Configurare";

		// Menu s informacemi
		ReadMeText.FeatureName = u8"Citeștemă";
		ReadMeText.LastUpdate = u8"Ultimul update: ";
		ReadMeText.SourceButton = u8"Sursă cod";
		ReadMeText.DiscordButton = u8"Discord server";
		ReadMeText.OffsetsTitle = u8"Offset-uri:";
	}
}
