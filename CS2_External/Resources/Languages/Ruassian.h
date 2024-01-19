#pragma once
#include "..\Language.h"

namespace Lang 
{
	inline void Russian()
	{
		Global.Author = "gScream";
		Global.Date = u8"2023/11/19";

		Global.SwitchButton = u8"§£§Ü§Ý§ð§é§Ú§ä§î";
		Global.FeatureSettings = u8"§¯§Ñ§ã§ä§â§à§Û§Ü§Ú";

		// ESP
		ESPtext.FeatureName = u8" ESP (WH)";
		ESPtext.Box = u8"§°§Ò§Ó§à§Õ§Ü§Ñ";
		ESPtext.BoxRounding = u8"§°§Ü§â§å§Ô§Ý§Ö§ß§Ú§Ö §à§Ò§Ó§à§Õ§Ü§Ú";
		ESPtext.FilledBox = u8"§©§Ñ§á§à§Ý§ß§Ö§ß§ß§Ñ§ñ §à§Ò§Ó§à§Õ§Ü§Ñ";
		ESPtext.FilledAlpha = u8"§±§â§à§Ù§â§Ñ§é§ß§à§ã§ä§î §Ù§Ñ§á§à§Ý§ß§Ö§ß§ß§à§Û §à§Ò§Ó§à§Õ§Ü§Ú";
		ESPtext.Skeleton = u8"§³§Ü§Ö§Ý§Ö§ä §è§Ö§Ý§Ú";
		ESPtext.HeadBox = u8"§¢§à§Ü§ã §Ô§à§Ý§à§Ó§í §è§Ö§Ý§Ú";
		ESPtext.EyeRay = u8"§¯§Ñ§á§â§Ñ§Ó§Ý§Ö§ß§Ú§Ö §Ù§â§Ö§ß§Ú§ñ §è§Ö§Ý§Ú";
		ESPtext.HealthBar = u8"§±§à§Ý§à§ã§Ü§Ñ §Ù§Õ§à§â§à§Ó§î§ñ §è§Ö§Ý§Ú";
		ESPtext.Weapon = u8"§°§â§å§Ø§Ú§Ö §è§Ö§Ý§Ú";
		ESPtext.Distance = u8"§¥§Ú§ã§ä§Ñ§ß§è§Ú§ñ §Õ§à §è§Ö§Ý§Ú";
		ESPtext.PlayerName = u8"§ª§Þ§ñ §è§Ö§Ý§Ú";
		ESPtext.SnapLine = u8"§­§Ú§ß§Ú§ñ §Ü §á§â§à§ä§Ú§Ó§ß§Ú§Ü§å";
		ESPtext.LinePosList = u8"§±§à§Ù§Ú§è§Ú§ñ §Ý§Ú§ß§Ú§Ú";
		ESPtext.VisCheck = u8"§´§à§Ý§î§Ü§à §Ö§ã§Ý§Ú §è§Ö§Ý§î §Ó §á§à§Ý§Ö §Ù§â§Ö§ß§Ú§ñ";
		ESPtext.Preview = u8"§°§ä§à§Ò§â§Ñ§Ù§Ú§ä§î §á§â§Ö§Õ§á§â§à§ã§Þ§à§ä§â WH";
		ESPtext.CollapseHead = u8"§³§Ö§Ü§ã WH";
		ESPtext.Penis = u8"§±§à§Ü§Ñ§Ù§Ñ§ä§î §á§Ö§ß§Ú§ã";
		ESPtext.PenisLength = u8"§¥§Ý§Ú§ß§Ñ";
		ESPtext.PenisSize = u8"§²§Ñ§Ù§Þ§Ö§â";
		ESPtext.MultiColor = u8"§®§å§Ý§î§ä§Ú-§è§Ó§Ö§ä";
		ESPtext.MultiColTip = u8"§²§Ñ§Ò§à§ä§Ñ§Ö§ä §ä§à§Ý§î§Ü§à §Ü§à§Ô§Õ§Ñ §à§Ò§Ó§à§Õ§Ü§Ñ §ß§Ö §Ú§Þ§Ö§Ö§ä §Ù§Ñ§Ü§â§å§Ô§Ý§Ö§ß§ß§í§Ö §Ü§â§Ñ§ñ.";

		// Aimbot
		AimbotText.FeatureName = u8" §¡§Ú§Þ§Ò§à§ä";
		AimbotText.HotKeyList = u8"§¤§à§â§ñ§é§Ñ§ñ §Ü§Ý§Ñ§Ó§Ú§ê§Ñ";
		AimbotText.Toggle = u8"§²§Ö§Ø§Ú§Þ §á§Ö§â§Ö§Ü§Ý§ð§é§Ö§ß§Ú§ñ";
		AimbotText.DrawFov = u8"§°§ä§à§Ò§â§Ñ§Ù§Ú§ä§î §á§à§Ý§Ö §Ù§â§Ö§ß§Ú§Ö";
		AimbotText.VisCheck = u8"§´§à§Ý§î§Ü§à §Ö§ã§Ý§Ú §è§Ö§Ý§î §Ó §á§à§Ý§Ö §Ù§â§Ö§ß§Ú§ñ";
		AimbotText.JumpCheck = u8"§´§à§Ý§î§Ü§à §ß§Ñ §Ù§Ö§Þ§Ý§Ö ";
		AimbotText.FovSlider = u8"§²§Ñ§Õ§Ú§å§ã §á§à§Ý§ñ §Ù§â§Ö§ß§Ú§ñ";
		AimbotText.SmoothSlider = u8"§³§Ô§Ý§Ñ§Ø§Ú§Ó§Ñ§ß§Ú§Ö";
		AimbotText.BoneList = u8"§³§Ü§Ö§Ý§Ö§ä";
		AimbotText.Tip = u8"§¥§Ý§ñ §â§Ñ§Ò§à§ä§í §¡§Ú§Þ§Ò§à§ä§Ñ §ß§å§Ø§ß§à §Ù§Ñ§Ü§â§í§ä§î §Þ§Ö§ß§ð (Insert)";

		// Glow
		GlowText.FeatureName = u8" §³§Ó§Ö§é§Ö§ß§Ú§Ö";

		// Radar
		RadarText.FeatureName = u8" §²§Ñ§Õ§Ñ§â";
		RadarText.StyleList = u8"§³§ä§Ú§Ý§î";
		RadarText.CustomCheck = u8"§¬§Ñ§ã§ä§à§Þ§ß§í§Û";
		RadarText.CrossLine = u8"§±§Ö§â§Ö§Ü§â§Ö§ã§ä§î§Ö";
		RadarText.SizeSlider = u8"§²§Ñ§Ù§Þ§Ö§â §ä§à§é§Ü§Ú";
		RadarText.ProportionSlider = u8"§±§â§à§á§à§â§è§Ú§Ú";
		RadarText.RangeSlider = u8"§²§Ñ§Õ§Ú§å§ã";
		RadarText.AlphaSlider = u8"§±§â§à§Ù§â§Ñ§é§ß§à§ã§ä§î §â§Ñ§Õ§Ñ§â§Ñ";

		// Triggerbot
		TriggerText.FeatureName = u8" §´§â§Ú§Ô§Ô§Ö§â§Ò§à§ä";
		TriggerText.HotKeyList = u8"§¤§à§â§ñ§é§Ñ§ñ §Ü§Ý§Ñ§Ó§Ú§ê§Ñ";
		TriggerText.Toggle = u8"§£§ã§Ö§Ô§Õ§Ñ §Ñ§Ü§ä§Ú§Ó§Ö§ß";
		TriggerText.DelaySlider = u8"§©§Ñ§Õ§Ö§â§Ø§Ü§Ñ §á§Ö§â§Ö§Õ §Ó§í§ã§ä§â§Ö§Ý§à§Þ";
		TriggerText.FakeShotSlider = u8"§±§â§à§Õ§à§Ý§Ø§Ú§ä§Ö§Ý§î§ß§à§ã§ä§î §Ó§í§ã§ä§â§Ö§Ý§Ñ";

		// Crosshairs
		CrosshairsText.FeatureName = u8" §±§â§Ú§è§Ö§Ý§í";
		CrosshairsText.PresetList = u8"§±§â§Ö§ã§Ö§ä§í";
		CrosshairsText.ColorEditor = u8"§¸§Ó§Ö§ä§Ñ §á§â§Ú§è§Ö§Ý§Ñ";
		CrosshairsText.Dot = u8"§´§à§é§Ü§Ñ §Ó §è§Ö§ß§ä§â§Ö";
		CrosshairsText.DotSizeSlider = u8"§²§Ñ§Ù§Þ§Ö§â §ä§à§é§Ü§Ú";
		CrosshairsText.Outline = u8"§¬§à§ß§ä§å§â";
		CrosshairsText.Crossline = u8"§±§Ö§â§Ö§Ü§â§Ö§ã§ä§î§Ö";
		CrosshairsText.hLengthSlider = u8"§¤§à§â§Ú§Ù§à§ß§ä§Ñ§Ý§î§ß§Ñ§ñ §Õ§Ý§Ú§ß§Ñ";
		CrosshairsText.vLengthSilder = u8"§£§Ö§â§ä§Ú§Ü§Ñ§Ý§î§ß§Ñ§ñ §Õ§Ý§Ú§ß§Ñ";
		CrosshairsText.GapSlider = u8"§±§â§à§Ò§Ö§Ý";
		CrosshairsText.ThicknessSlider = u8"§º§Ú§â§à§ä§Ñ";
		CrosshairsText.tStyle = u8"§±§â§Ú§è§Ö§Ý §Ó §ã§ä§Ú§Ý§Ö §Ò§å§Ü§Ó§í §´";
		CrosshairsText.Circle = u8"§¬§â§å§Ô";
		CrosshairsText.RadiusSlider = u8"§²§Ñ§Õ§Ú§å§ã §Ü§â§å§Ô§Ñ";
		CrosshairsText.TargetCheck = u8"§¯§Ñ§è§Ö§Ý§Ú§Ó§Ñ§ß§Ú§Ö §á§â§Ú§è§Ö§Ý§Ñ";
		CrosshairsText.TeamCheck = u8"§²§Ö§Ø§Ú§Þ §ã§Ó§à§Ú§ç §ß§Ñ§á§Ñ§â§ß§Ú§Ü§à§Ó";

		// Misc
		MiscText.FeatureName = u8" §¥§à§á§à§Ý§ß§Ú§ä§Ö§Ý§î§ß§à";
		MiscText.ThemeList = u8"§´§Ö§Þ§Ñ";
		MiscText.StyleList = u8"§³§ä§Ú§Ý§î";
		MiscText.HeadshotLine = u8"§£§í§ã§à§ä§ß§Ñ§ñ §Ý§Ú§ß§Ú§ñ §Ô§à§Ý§à§Ó§í";
		MiscText.SpecCheck = u8"§°§ä§à§Ò§â§Ñ§Ø§Ö§ß§Ú§Ö §á§â§Ú §ß§Ñ§Ò§Ý§ð§Õ§Ö§ß§Ú§Ú";
		MiscText.NoFlash = u8"§¡§ß§ä§Ú-§ã§Ý§Ö§á§à§ä§Ñ";
		MiscText.HitSound = u8"§©§Ó§å§Ü §á§à§á§Ñ§Õ§Ñ§ß§Ú§ñ";
		MiscText.bmbTimer = u8"§´§Ñ§Û§Þ§Ö§â §Õ§à §Ó§Ù§â§í§Ó§Ñ C4";
		MiscText.SpecList = u8"§³§á§Ú§ã§à§Ü §ß§Ñ§Ò§Ý§ð§Õ§Ñ§ä§Ö§Ý§Ö§Û";
		MiscText.Bhop = u8"§¢§ç§à§á";
		MiscText.Watermark = u8"§£§à§Õ§ñ§ß§à§Û §Ù§ß§Ñ§Ü";
		MiscText.CheatList = u8"§³§á§Ú§ã§à§Ü §Ñ§Ü§ä§Ú§Ó§ß§í§ç §é§Ú§ä§à§Ó";
		MiscText.TeamCheck = u8"§²§Ö§Ø§Ú§Þ §ã§Ó§à§Ú§ç §ß§Ñ§á§Ñ§â§ß§Ú§Ü§à§Ó";
		MiscText.AntiRecord = u8"§°§Ò§ç§à§Õ §Ù§Ñ§á§Ú§ã§Ú/§Õ§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§Ú";

		MiscText.LanguageList = u8"§Á§Ù§í§Ü";

		// Config Menu
		ConfigText.FeatureName = u8" §¬§à§ß§æ§Ú§Ô§å§â§Ñ§è§Ú§ñ";
		ConfigText.Load = u8"§©§Ñ§Ô§â§å§Ù§Ú§ä§î §Ó§í§Õ§Ö§Ý§Ö§ß§ß§à§Ö";
		ConfigText.Save = u8"§³§à§ç§â§Ñ§ß§Ú§ä§î §Ó§í§Õ§Ö§Ý§Ö§ß§ß§à§Ö";
		ConfigText.Delete = u8"§µ§Õ§Ñ§Ý§Ú§ä§î §Ó§í§Õ§Ö§Ý§Ö§ß§ß§à§Ö";
		ConfigText.Reset = u8"§£§à§ã§ã§ä§Ñ§ß§à§Ó§Ú§ä§î §ã§ä§Ñ§ß§Õ§Ñ§â§ä§ß§í§Ö §ß§Ñ§ã§ä§â§à§Û§Ü§Ú";
		ConfigText.Create = u8"§³§à§Ù§Õ§Ñ§ä§î §Ü§à§ß§æ§Ú§Ô§å§â§Ñ§è§Ú§ð";
		ConfigText.OpenFolder = u8"§°§ä§Ü§â§í§ä§î §á§Ñ§á§Ü§å §ã §Ü§à§ß§æ§Ú§Ô§å§â§Ñ§è§Ú§ñ§Þ§Ú";
		ConfigText.SeparateLine = u8"§³§à§ç§â§Ñ§ß§Ú§ä§î §Ü§à§ß§æ§Ú§Ô§å§â§Ñ§è§Ú§ð";

		// Readme Menu
		ReadMeText.FeatureName = u8" §°§´§¬§²§°§«";
		ReadMeText.LastUpdate = u8"§±§à§ã§Ý§Ö§Õ§ß§Ö§Ö §à§Ò§ß§à§Ó§Ý§Ö§ß§Ú§Ö: ";
		ReadMeText.SourceButton = u8" §ª§ã§ç§à§Õ§ß§í§Û §Ü§à§Õ";
		ReadMeText.DiscordButton = u8" §±§â§Ú§ã§à§Ö§Õ§Ú§ß§Ú§ä§î§ã§ñ §Ü §Õ§Ú§ã§Ü§à§â§Õ §ã§Ö§â§Ó§Ö§â§å";
		ReadMeText.OffsetsTitle = u8"§°§æ§æ§ã§Ö§ä§í:";
	}
}