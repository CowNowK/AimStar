#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void English()
	{
		Global.Date = u8"None";
		Global.Author = u8"None";

		Global.SwitchButton = u8"Enable";
		Global.FeatureSettings = u8"Settings";

		// ESP
		ESPtext.Toggle = u8"Toggle";
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Frame";
		ESPtext.BoxRounding = u8"Box Rounding: ";
		ESPtext.FilledBox = u8"Filled Box";
		ESPtext.FilledAlpha = u8"Filled Box Alpha";
		ESPtext.Skeleton = u8"Skeleton";
		ESPtext.HeadBox = u8"Head Box";
		ESPtext.EyeRay = u8"Eye Ray";
		ESPtext.HealthBar = u8"Health Bar";
		ESPtext.Weapon = u8"Weapon";
		ESPtext.Distance = u8"Distance";
		ESPtext.PlayerName = u8"Name";
		ESPtext.SnapLine = u8"Snap Line";
		ESPtext.LinePosList = u8"Line Position: ";
		ESPtext.VisCheck = u8"Visible Check";
		ESPtext.Preview = u8"Preview Window";
		ESPtext.CollapseHead = u8"SexyESP";
		ESPtext.Penis = u8"Show Penis";
		ESPtext.PenisLength = u8"Length";
		ESPtext.PenisSize = u8"Size";
		ESPtext.MultiColor = u8"Multi-Color";
		ESPtext.MultiColTip = u8"Only work when the box has non-rounded corners.";
		ESPtext.Outline = u8"Outline";
		ESPtext.BoxType = u8"Box Type:";
		ESPtext.HealthNum = u8"Health Number";
		ESPtext.Ammo = u8"Ammo";
		ESPtext.ScopedESP = u8"Show Scoped";
		ESPtext.ShowArmorBar = u8"Armor Bar";
		ESPtext.ArmorNum = u8"Armor Number";
		ESPtext.RenderDistance = u8"Maximum Render Distance: ";

		ESPtext.BoxType_Normal = u8"Normal";
		ESPtext.BoxType_Edge = u8"Dynamic";
		ESPtext.BoxType_Corner = u8"Corner";
		ESPtext.LinePos_1 = u8"Top";
		ESPtext.LinePos_2 = u8"Center";
		ESPtext.LinePos_3 = u8"Bottom";

		// Aimbot
		AimbotText.Enable = u8"Enable Aimbot";
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Hotkey   ";
		AimbotText.Toggle = u8"Toggle Mode";
		AimbotText.DrawFov = u8"Draw Fov";
		AimbotText.VisCheck = u8"Visible Only";
		AimbotText.JumpCheck = u8"On Ground Only";
		AimbotText.FovSlider = u8"FOV: ";
		AimbotText.FovMinSlider = u8"MinFOV: ";
		AimbotText.SmoothSlider = u8"Smooth: ";
		AimbotText.BoneList = u8"Hitbox";
		AimbotText.Tip = u8"Aimbot will not work while the menu is opened";
		AimbotText.ScopeOnly = u8"Scope Only";
		AimbotText.AimLock = u8"Aim Lock";
		AimbotText.AutoShot = u8"Auto Shot";
		AimbotText.BulletSlider = u8"Start Bullet: ";
		AimbotText.IgnoreFlash = u8"Ignore Flash";

		// RCS
		RCStext.Toggle = u8"Recoil Control";
		RCStext.Yaw = u8"Yaw: ";
		RCStext.Pitch = u8"Pitch: ";

		// Radar
		RadarText.Toggle = u8"Show Radar";
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Custom";
		RadarText.CrossLine = u8"Cross Line";
		RadarText.SizeSlider = u8"Point Size:";
		RadarText.ProportionSlider = u8"Proportion:";
		RadarText.RangeSlider = u8"Range:";
		RadarText.AlphaSlider = u8"Window Background Alpha:";

		// Triggerbot
		TriggerText.Enable = u8"Enable Triggerbot";
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Hotkey   ";
		TriggerText.Toggle = u8"Always Active";
		TriggerText.ScopeOnly = u8"Scope Only";
		TriggerText.DelaySlider = u8"Shot Delay:";
		TriggerText.FakeShotSlider = u8"Shot Duration:";

		// Crosshairs
		CrosshairsText.Toggle = u8"Show Crosshairs";
		CrosshairsText.FeatureName = u8" Crosshairs";
		CrosshairsText.PresetList = u8"Presets";
		CrosshairsText.ColorEditor = u8"Crosshairs Color";
		CrosshairsText.Dot = u8"Center Dot";
		CrosshairsText.DotSizeSlider = u8"Dot Size:";
		CrosshairsText.Outline = u8"Outline";
		CrosshairsText.Crossline = u8"Crossline";
		CrosshairsText.hLengthSlider = u8"Horizontal Length:";
		CrosshairsText.vLengthSilder = u8"Vertical Length:";
		CrosshairsText.GapSlider = u8"Gap:";
		CrosshairsText.ThicknessSlider = u8"Thickness:";
		CrosshairsText.tStyle = u8"T Style";
		CrosshairsText.Circle = u8"Circle";
		CrosshairsText.RadiusSlider = u8"Circle Radius:";
		CrosshairsText.TargetCheck = u8"Targeting Crosshairs";
		CrosshairsText.TeamCheck = u8"TeamCheck";

		// Misc
		MiscText.FeatureName = u8" Misc";
		MiscText.ThemeList = u8"Theme     ";
		MiscText.StyleList = u8"Style";
		MiscText.HeadshotLine = u8"Headshot Line";
		MiscText.SpecCheck = u8"Cheat in Spec";
		MiscText.NoFlash = u8"No Flash";
		MiscText.FastStop = u8"Fast Stop";
		MiscText.HitSound = u8"Hit Sound";
		MiscText.bmbTimer = u8"Bomb Timer";
		MiscText.SpecList = u8"Spec List";
		MiscText.Bhop = u8"Auto Jump";
		MiscText.Watermark = u8"Watermark";
		MiscText.CheatList = u8"Cheat List";
		MiscText.TeamCheck = u8"Team Check";
		MiscText.AntiRecord = u8"Anti Record";
		MiscText.MoneyService = u8"Money Services";
		MiscText.ShowCashSpent = u8"Show Cash Spent";
		MiscText.EnemySensor = u8"Enemy Sensor";
		MiscText.RadarHack = u8"Radar Hack";
		MiscText.FastStop = u8"Fast Stop";
		MiscText.VisCheckDisable = u8"Visible Check DISABLED";
		MiscText.NoSmoke = u8"No Smoke";
		MiscText.SmokeColor = u8"Smoke Color";
		MiscText.fovchanger = u8"Fov Changer: ";
		MiscText.ForceScope = u8"Force Scope";
		MiscText.FlashImmunity = u8"Flash Immunity: ";
		MiscText.NightMode = u8"Night Mode";
		MiscText.Alpha = u8"Alpha: ";

		MiscText.FakeDuck = u8"Fake Duck";

		MiscText.LanguageList = u8"Language";

		// Config Menu
		ConfigText.FeatureName = u8"Config Loader";
		ConfigText.MyConfigs = u8"Config List";
		ConfigText.Load = u8"Load Selected";
		ConfigText.Save = u8"Save Selected";
		ConfigText.Delete = u8"Delete Selected";
		ConfigText.Reset = u8"Reset Config";
		ConfigText.Create = u8"Create";
		ConfigText.OpenFolder = u8"Open Folder";
		ConfigText.SeparateLine = u8"Create Config";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		ConfigText.SafeMode = u8"Safe Mode";
		ConfigText.SafeModeHoveredTip = u8"Disable all unsafe functions that modify game's memory";

		// Readme Menu
		ReadMeText.FeatureName = u8" README";
		ReadMeText.LastUpdate = u8"Last update: ";
		ReadMeText.SourceButton = u8"Source Code";
		ReadMeText.DiscordButton = u8"Join Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}
}