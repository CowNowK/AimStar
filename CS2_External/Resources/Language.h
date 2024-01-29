#pragma once
#include "..\Font\IconsFontAwesome5.h"

namespace Lang
{
	inline struct Global
	{
		inline static const char* Date;
		inline static const char* Author;

		inline static const char* SwitchButton;
		inline static const char* FeatureSettings;
	} Global;

	inline struct ESPtext
	{
		inline static const char* Toggle;
		inline static const char* FeatureName;
		inline static const char* Box;
		inline static const char* BoxRounding;
		inline static const char* FilledBox;
		inline static const char* FilledAlpha;
		inline static const char* Skeleton;
		inline static const char* HeadBox;
		inline static const char* EyeRay;
		inline static const char* HealthBar;
		inline static const char* Weapon;
		inline static const char* Distance;
		inline static const char* PlayerName;
		inline static const char* SnapLine;
		inline static const char* LinePosList;
		inline static const char* VisCheck;
		inline static const char* Preview;
		inline static const char* CollapseHead;
		inline static const char* Penis;
		inline static const char* PenisLength;
		inline static const char* PenisSize;
		inline static const char* MultiColor;
		inline static const char* MultiColTip;
		inline static const char* Outline;
		inline static const char* BoxType;
		inline static const char* HealthNum;
		inline static const char* Ammo;

		inline static const char* BoxType_Normal;
		inline static const char* BoxType_Edge;
		inline static const char* BoxType_Corner;
		inline static const char* BarType_Top;
		inline static const char* BarType_Vertical;
		inline static const char* HeadBoxType_Normal;
		inline static const char* HeadBoxType_Flat;
		inline static const char* LinePos_1;
		inline static const char* LinePos_2;
		inline static const char* LinePos_3;
	} ESPtext;

	inline struct AimbotText
	{
		inline static const char* Enable;
		inline static const char* FeatureName;
		inline static const char* HotKeyList;
		inline static const char* Toggle;
		inline static const char* DrawFov;
		inline static const char* VisCheck;
		inline static const char* JumpCheck;
		inline static const char* FovSlider;
		inline static const char* SmoothSlider;
		inline static const char* BoneList;
		inline static const char* Tip;

		inline static const char* Bone_1;
		inline static const char* Bone_2;
		inline static const char* Bone_3;
		inline static const char* Bone_4;
	} AimbotText;

	inline struct RadarText
	{
		inline static const char* Toggle;
		inline static const char* FeatureName;
		inline static const char* StyleList;
		inline static const char* CustomCheck;
		inline static const char* CrossLine;
		inline static const char* SizeSlider;
		inline static const char* ProportionSlider;
		inline static const char* RangeSlider;
		inline static const char* AlphaSlider;

		inline static const char* Style_1;
		inline static const char* Style_2;
		inline static const char* Style_3;
	} RadarText;

	inline struct TriggerText
	{
		inline static const char* Enable;
		inline static const char* FeatureName;
		inline static const char* HotKeyList;
		inline static const char* Toggle;
		inline static const char* DelaySlider;
		inline static const char* FakeShotSlider;
	} TriggerText;

	inline struct CrosshairsText
	{
		inline static const char* Toggle;
		inline static const char* FeatureName;
		inline static const char* PresetList;
		inline static const char* ColorEditor;
		inline static const char* Dot;
		inline static const char* DotSizeSlider;
		inline static const char* Outline;
		inline static const char* Crossline;
		inline static const char* hLengthSlider;
		inline static const char* vLengthSilder;
		inline static const char* GapSlider;
		inline static const char* ThicknessSlider;
		inline static const char* tStyle;
		inline static const char* Circle;
		inline static const char* RadiusSlider;
		inline static const char* TargetCheck;
		inline static const char* TeamCheck;
	} CrosshairsText;

	inline struct MiscText
	{
		inline static const char* FeatureName;
		inline static const char* ThemeList;
		inline static const char* StyleList;
		inline static const char* HeadshotLine;
		inline static const char* SpecCheck;
		inline static const char* NoFlash;
		inline static const char* FastStop;
		inline static const char* HitSound;
		inline static const char* bmbTimer;
		inline static const char* SpecList;
		inline static const char* Bhop;
		inline static const char* Watermark;
		inline static const char* CheatList;
		inline static const char* TeamCheck;
		inline static const char* AntiRecord;
		inline static const char* MoneyService;
		inline static const char* ShowCashSpent;
		inline static const char* EnemySensor;
		inline static const char* RadarHack;
		inline static const char* NoSmoke;
		inline static const char* SmokeColor;
		
		inline static const char* FakeDuck;

		inline static const char* LanguageList;

		inline static const char* VisCheckDisable;
	} MiscText;

	inline struct ConfigText
	{
		inline static const char* FeatureName;
		inline static const char* Load;
		inline static const char* Save;
		inline static const char* Delete;
		inline static const char* Reset;
		inline static const char* Create;
		inline static const char* OpenFolder;
		inline static const char* SeparateLine;
		inline static const char* MyConfigs;
		inline static const char* AuthorName;
		inline static const char* ConfigName;
	} ConfigText;

	inline struct ReadMeText
	{
		inline static const char* FeatureName;
		inline static const char* LastUpdate;
		inline static const char* SourceButton;
		inline static const char* DiscordButton;
		inline static const char* OffsetsTitle;
	} ReadMeText;

	void ChangeLang(int LangIndex);

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
		AimbotText.SmoothSlider = u8"Smooth: ";
		AimbotText.BoneList = u8"Bone       ";
		AimbotText.Tip = u8"Aimbot will not work while the menu is opened";

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
		MiscText.Bhop = u8"Bunny Hop";
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

		MiscText.FakeDuck = u8"Fake Duck";

		MiscText.LanguageList = u8"Language";

		// Config Menu
		ConfigText.FeatureName = u8"Config";
		ConfigText.MyConfigs = u8"Config List";
		ConfigText.Load = u8"Load Selected";
		ConfigText.Save = u8"Save Selected";
		ConfigText.Delete = u8"Delete Selected";
		ConfigText.Reset = u8"Reset Config";
		ConfigText.Create = u8"Create Config";
		ConfigText.OpenFolder = u8"Open Folder";
		ConfigText.SeparateLine = u8"New Config";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" README";
		ReadMeText.LastUpdate = u8"Last update: ";
		ReadMeText.SourceButton = u8"Source Code";
		ReadMeText.DiscordButton = u8"Join Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}
}