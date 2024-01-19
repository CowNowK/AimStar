#pragma once
#include "..\Font\IconsFontAwesome5.h"

namespace Lang
{
	struct
	{
		const char* Date;
		const char* Author;

		const char* SwitchButton;
		const char* FeatureSettings;
	} Global;

	struct
	{
		const char* FeatureName;
		const char* Box;
		const char* BoxRounding;
		const char* FilledBox;
		const char* FilledAlpha;
		const char* Skeleton;
		const char* HeadBox;
		const char* EyeRay;
		const char* HealthBar;
		const char* Weapon;
		const char* Distance;
		const char* PlayerName;
		const char* SnapLine;
		const char* LinePosList;
		const char* VisCheck;
		const char* Preview;
		const char* CollapseHead;
		const char* Penis;
		const char* PenisLength;
		const char* PenisSize;
		const char* MultiColor;
		const char* MultiColTip;

		const char* BoxType_Normal;
		const char* BoxType_Edge;
		const char* BoxType_Corner1;
		const char* BoxType_Corner2;
		const char* BarType_Top;
		const char* BarType_Vertical;
		const char* HeadBoxType_Normal;
		const char* HeadBoxType_Flat;
		const char* LinePos_1;
		const char* LinePos_2;
		const char* LinePos_3;
	} ESPtext;

	struct
	{
		const char* FeatureName;
		const char* HotKeyList;
		const char* Toggle;
		const char* DrawFov;
		const char* VisCheck;
		const char* JumpCheck;
		const char* FovSlider;
		const char* SmoothSlider;
		const char* BoneList;
		const char* Tip;

		const char* Bone_1;
		const char* Bone_2;
		const char* Bone_3;
		const char* Bone_4;
	} AimbotText;

	struct
	{
		const char* FeatureName;
	} GlowText;

	struct
	{
		const char* FeatureName;
		const char* StyleList;
		const char* CustomCheck;
		const char* CrossLine;
		const char* SizeSlider;
		const char* ProportionSlider;
		const char* RangeSlider;
		const char* AlphaSlider;

		const char* Style_1;
		const char* Style_2;
		const char* Style_3;
	} RadarText;

	struct
	{
		const char* FeatureName;
		const char* HotKeyList;
		const char* Toggle;
		const char* DelaySlider;
		const char* FakeShotSlider;
	} TriggerText;

	struct
	{
		const char* FeatureName;
		const char* PresetList;
		const char* ColorEditor;
		const char* Dot;
		const char* DotSizeSlider;
		const char* Outline;
		const char* Crossline;
		const char* hLengthSlider;
		const char* vLengthSilder;
		const char* GapSlider;
		const char* ThicknessSlider;
		const char* tStyle;
		const char* Circle;
		const char* RadiusSlider;
		const char* TargetCheck;
		const char* TeamCheck;
	} CrosshairsText;

	struct
	{
		const char* FeatureName;
		const char* ThemeList;
		const char* StyleList;
		const char* HeadshotLine;
		const char* SpecCheck;
		const char* NoFlash;
		const char* FastStop;
		const char* HitSound;
		const char* bmbTimer;
		const char* SpecList;
		const char* Bhop;
		const char* Watermark;
		const char* CheatList;
		const char* TeamCheck;
		const char* AntiRecord;

		const char* LanguageList;
	} MiscText;

	struct
	{
		const char* FeatureName;
		const char* Load;
		const char* Save;
		const char* Delete;
		const char* Reset;
		const char* Create;
		const char* OpenFolder;
		const char* SeparateLine;
	} ConfigText;

	struct
	{
		const char* FeatureName;
		const char* LastUpdate;
		const char* SourceButton;
		const char* DiscordButton;
		const char* OffsetsTitle;
	} ReadMeText;

	inline void ChangeLang(int LangIndex);

	inline void English()
	{
		Global.Date = u8"None";
		Global.Author = u8"None";

		Global.SwitchButton = u8"Enable";
		Global.FeatureSettings = u8"Settings";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Box Rounding";
		ESPtext.FilledBox = u8"Filled Box";
		ESPtext.FilledAlpha = u8"Filled Box Alpha";
		ESPtext.Skeleton = u8"Skeleton";
		ESPtext.HeadBox = u8"Head Box";
		ESPtext.EyeRay = u8"Eye Ray";
		ESPtext.HealthBar = u8"Health Bar";
		ESPtext.Weapon = u8"Weapon";
		ESPtext.Distance = u8"Distance";
		ESPtext.PlayerName = u8"Name";
		ESPtext.SnapLine = u8"SnapLine";
		ESPtext.LinePosList = u8"LinePos";
		ESPtext.VisCheck = u8"Visible Check";
		ESPtext.Preview = u8"Preview Window";
		ESPtext.CollapseHead = u8"SexyESP";
		ESPtext.Penis = u8"Show Penis";
		ESPtext.PenisLength = u8"Length";
		ESPtext.PenisSize = u8"Size";
		ESPtext.MultiColor = u8"Multi-Color";
		ESPtext.MultiColTip = u8"Only work when the box has non-rounded corners.";

		// Aimbot
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Key";
		AimbotText.Toggle = u8"Toggle Mode";
		AimbotText.DrawFov = u8"Draw Fov";
		AimbotText.VisCheck = u8"Visible Only";
		AimbotText.JumpCheck = u8"On Ground Only";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Smooth";
		AimbotText.BoneList = u8"Bone";
		AimbotText.Tip = u8"Aimbot will not work while the menu is opened";

		// Glow
		GlowText.FeatureName = u8" Glow";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Custom";
		RadarText.CrossLine = u8"Cross Line";
		RadarText.SizeSlider = u8"Point Size";
		RadarText.ProportionSlider = u8"Proportion";
		RadarText.RangeSlider = u8"Range";
		RadarText.AlphaSlider = u8"Window Background Alpha";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"HotKey";
		TriggerText.Toggle = u8"Always Active";
		TriggerText.DelaySlider = u8"Shot Delay";
		TriggerText.FakeShotSlider = u8"Shot Duration";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Crosshairs";
		CrosshairsText.PresetList = u8"Presets";
		CrosshairsText.ColorEditor = u8"Crosshairs Color";
		CrosshairsText.Dot = u8"Center Dot";
		CrosshairsText.DotSizeSlider = u8"Dot Size";
		CrosshairsText.Outline = u8"Outline";
		CrosshairsText.Crossline = u8"Cross Line";
		CrosshairsText.hLengthSlider = u8"Horizontal Length";
		CrosshairsText.vLengthSilder = u8"Vertical Length";
		CrosshairsText.GapSlider = u8"Gap";
		CrosshairsText.ThicknessSlider = u8"Thickness";
		CrosshairsText.tStyle = u8"T Style";
		CrosshairsText.Circle = u8"Circle";
		CrosshairsText.RadiusSlider = u8"Circle Radius";
		CrosshairsText.TargetCheck = u8"Targeting Crosshairs";
		CrosshairsText.TeamCheck = u8"TeamCheck";

		// Misc
		MiscText.FeatureName = u8" Misc";
		MiscText.ThemeList = u8"Theme";
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
		MiscText.TeamCheck = u8"TeamCheck";
		MiscText.AntiRecord = u8"Bypass OBS";

		MiscText.LanguageList = u8"Language";

		// Config Menu
		ConfigText.FeatureName = u8" Config";
		ConfigText.Load = u8"Load Selected";
		ConfigText.Save = u8"Save Selected";
		ConfigText.Delete = u8"Delete Selected";
		ConfigText.Reset = u8"Reset Config";
		ConfigText.Create = u8"Create Config";
		ConfigText.OpenFolder = u8"Open Folder";
		ConfigText.SeparateLine = u8"Save Config";

		// Readme Menu
		ReadMeText.FeatureName = u8" README";
		ReadMeText.LastUpdate = u8"Last update: ";
		ReadMeText.SourceButton = u8" Source Code";
		ReadMeText.DiscordButton = u8" Join Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}
}