#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Hungarian()
	{
		Global.Author = u8"djsacred";
		Global.Date = u8"2023/12/03";

		Global.SwitchButton = u8"Kitiltási eszköz";
		Global.FeatureSettings = u8"Beállítások";

		// ESP
		ESPtext.FeatureName = u8"Extraszenzoros észlelés";
		ESPtext.Box = u8"Doboz";
		ESPtext.BoxRounding = u8"Doboz kerekítés";
		ESPtext.FilledBox = u8"Megtöltött doboz";
		ESPtext.FilledAlpha = u8"Megtöltött Alfa doboz";
		ESPtext.Skeleton = u8"Csontváz";
		ESPtext.HeadBox = u8"Fej doboz";
		ESPtext.EyeRay = u8"Szem sáv";
		ESPtext.HealthBar = u8"Egészségügyi bár";
		ESPtext.Weapon = u8"Deshi oncsel meg";
		ESPtext.Distance = u8"Bombayt a koktelba";
		ESPtext.PlayerName = u8"Név";
		ESPtext.SnapLine = u8"Csattan vonal";
		ESPtext.LinePosList = u8"Vonal pozicio";
		ESPtext.VisCheck = u8"Látható ellenőrzés";
		ESPtext.Preview = u8"Előnézet ablak";
		ESPtext.CollapseHead = u8"Szexi Extraszenzoros észlelés";
		ESPtext.Penis = u8"Pénisz megjelenítése";
		ESPtext.PenisLength = u8"Pénisz hossza";
		ESPtext.PenisSize = u8"Pénisz mérete";
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
		AimbotText.FeatureName = u8" Célzozzon robot";
		AimbotText.HotKeyList = u8"Kulcs";
		AimbotText.Toggle = u8"Mód váltása";
		AimbotText.DrawFov = u8"Rajzolja meg a látómezőt";
		AimbotText.VisCheck = u8"Csak látható";
		AimbotText.JumpCheck = u8"Csak a földön";
		AimbotText.FovSlider = u8"Látómegő";
		AimbotText.SmoothSlider = u8"Kurva anyád";
		AimbotText.BoneList = u8"Buta zsidó";
		AimbotText.Tip = u8"A Célozzon Robot nem fog működni, amíg a menü meg van nyitva, te fasz";

		// Radar
		RadarText.FeatureName = u8" Madár";
		RadarText.StyleList = u8"Kipattantba van stiló";
		RadarText.CustomCheck = u8"Egyedi";
		RadarText.CrossLine = u8"Kereszt vonale";
		RadarText.SizeSlider = u8"Pontméret";
		RadarText.ProportionSlider = u8"Hányad";
		RadarText.RangeSlider = u8"Sor";
		RadarText.AlphaSlider = u8"Ablak háttér Alpha";

		// Triggerbot
		TriggerText.FeatureName = u8" Néger robot";
		TriggerText.HotKeyList = u8"Forró kulcs";
		TriggerText.Toggle = u8"Mindig aktív";
		TriggerText.DelaySlider = u8"Lövés késleltetése";
		TriggerText.FakeShotSlider = u8"Lövés időtartama";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Szájkeresztek";
		CrosshairsText.PresetList = u8"Előbeállítások";
		CrosshairsText.ColorEditor = u8"Célkereszt színe";
		CrosshairsText.Dot = u8"Közép pont";
		CrosshairsText.DotSizeSlider = u8"Pont méret";
		CrosshairsText.Outline = u8"Vázlat";
		CrosshairsText.Crossline = u8"kereszt vonal";
		CrosshairsText.hLengthSlider = u8"Vízszintes hossz";
		CrosshairsText.vLengthSilder = u8"Függőleges hossz";
		CrosshairsText.GapSlider = u8"Rés";
		CrosshairsText.ThicknessSlider = u8"Vastagság mérés";
		CrosshairsText.tStyle = u8"Pattintott stiló";
		CrosshairsText.Circle = u8"Kör";
		CrosshairsText.RadiusSlider = u8"Kör sugara";
		CrosshairsText.TargetCheck = u8"Cél kereszt";
		CrosshairsText.TeamCheck = u8"Csapatellenőrzés";

		// Misc
		MiscText.FeatureName = u8" Különféle";
		MiscText.ThemeList = u8"Téma";
		MiscText.StyleList = u8"Pattintott stiló";
		MiscText.HeadshotLine = u8"Fej lövés vonal";
		MiscText.SpecCheck = u8"Csalás a Nézésben";
		MiscText.NoFlash = u8"Nincs villanás";
		MiscText.HitSound = u8"Ütés hang";
		MiscText.bmbTimer = u8"Bomba időzítő";
		MiscText.SpecList = u8"Specifikációs lista";
		MiscText.Bhop = u8"Nyuszi ugrás";
		MiscText.Watermark = u8"Vízpiac";
		MiscText.CheatList = u8"Csal lista";
		MiscText.TeamCheck = u8"Csapat fene";
		MiscText.AntiRecord = u8"Kerülje meg az OBS-t";

		MiscText.LanguageList = u8"Beszélt nyelv";

		// Config Menu
		ConfigText.FeatureName = u8" Konfigurációt";
		ConfigText.Load = u8"Betöltés a kiválaszt";
		ConfigText.Save = u8"Kijelöltek mentése";
		ConfigText.Delete = u8"Apád halott";
		ConfigText.Reset = u8"Anyád baszom";
		ConfigText.Create = u8"Te meg buzi";
		ConfigText.OpenFolder = u8"Nyitott mappa";
		ConfigText.SeparateLine = u8"Konfiguráció mentése";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" Olvassa el te geci";
		ReadMeText.LastUpdate = u8"Utoljára lemásolva: ";
		ReadMeText.SourceButton = u8" Szar kód";
		ReadMeText.DiscordButton = u8" Ne lépj be a Discordba";
		ReadMeText.OffsetsTitle = u8"Ellentételezések:";
	}
}