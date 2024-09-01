#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma once
#include "..\Font\IconsFontAwesome5.h"
#include <iostream>
#include <string>
#include <windows.h>

namespace Lang
{
	inline static void GetCountry(std::string& Country)
	{
		LCID lcid = GetUserDefaultLCID();
		wchar_t CountryW[256];
		GetUserDefaultGeoName(CountryW, sizeof(CountryW) / sizeof(CountryW[0]));

		int len = WideCharToMultiByte(CP_UTF8, 0, CountryW, -1, nullptr, 0, nullptr, nullptr);
		char* String = new char[len];
		WideCharToMultiByte(CP_UTF8, 0, CountryW, -1, String, len, nullptr, nullptr);
		std::string utf8String(String);
		Country = String;

		delete[] String;
		return;
	}
	
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
		inline static const char* ScopedESP;
		inline static const char* ShowArmorBar;
		inline static const char* ArmorNum;
		inline static const char* RenderDistance;

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
		inline static const char* FovMinSlider;
		inline static const char* SmoothSlider;
		inline static const char* BoneList;
		inline static const char* SprayBoneList;
		inline static const char* Tip;
		inline static const char* ScopeOnly;
		inline static const char* AimLock;
		inline static const char* AutoShot;
		inline static const char* BulletSlider;
		inline static const char* IgnoreFlash;
		inline static const char* Ragebot;

		inline static const char* Bone_1;
		inline static const char* Bone_2;
		inline static const char* Bone_3;
		inline static const char* Bone_4;
	} AimbotText;

	inline struct RCStext
	{
		inline static const char* Toggle;
		inline static const char* Yaw;
		inline static const char* Pitch;
	} RCStext;

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
		inline static const char* ScopeOnly;
		inline static const char* IgnoreFlash;
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
		inline static const char* fovchanger;
		inline static const char* ForceScope;
		inline static const char* FlashImmunity;
		inline static const char* NightMode;
		inline static const char* Alpha;
		inline static const char* JumpThrow;
		
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

		inline static const char* SafeMode;
		inline static const char* fpsCap;
		inline static const char* SafeModeHoveredTip;
	} ConfigText;

	inline struct ReadMeText
	{
		inline static const char* FeatureName;
		inline static const char* LastUpdate;
		inline static const char* SourceButton;
		inline static const char* DiscordButton;
		inline static const char* OffsetsTitle;
	} ReadMeText;

	inline void English()
	{
		Global.Date ="None";
		Global.Author ="None";

		Global.SwitchButton ="Enable";
		Global.FeatureSettings ="Settings";

		// ESP
		ESPtext.Toggle ="Toggle";
		ESPtext.FeatureName =" ESP";
		ESPtext.Box ="Frame";
		ESPtext.BoxRounding ="Box Rounding: ";
		ESPtext.FilledBox ="Filled Box";
		ESPtext.FilledAlpha ="Filled Box Alpha";
		ESPtext.Skeleton ="Skeleton";
		ESPtext.HeadBox ="Head Box";
		ESPtext.EyeRay ="Eye Ray";
		ESPtext.HealthBar ="Health Bar";
		ESPtext.Weapon ="Weapon";
		ESPtext.Distance ="Distance";
		ESPtext.PlayerName ="Name";
		ESPtext.SnapLine ="Snap Line";
		ESPtext.LinePosList ="Line Position: ";
		ESPtext.VisCheck ="Visible Check";
		ESPtext.Preview ="Preview Window";
		ESPtext.CollapseHead ="SexyESP";
		ESPtext.Penis ="Show Penis";
		ESPtext.PenisLength ="Length";
		ESPtext.PenisSize ="Size";
		ESPtext.MultiColor ="Multi-Color";
		ESPtext.MultiColTip ="Only work when the box has non-rounded corners.";
		ESPtext.Outline ="Outline";
		ESPtext.BoxType ="Box Type:";
		ESPtext.HealthNum ="Health Number";
		ESPtext.Ammo ="Ammo";
		ESPtext.ScopedESP ="Show Scoped";
		ESPtext.ShowArmorBar ="Armor Bar";
		ESPtext.ArmorNum ="Armor Number";
		ESPtext.RenderDistance ="Maximum Render Distance: ";

		ESPtext.BoxType_Normal ="Normal";
		ESPtext.BoxType_Edge ="Dynamic";
		ESPtext.BoxType_Corner ="Corner";
		ESPtext.LinePos_1 ="Top";
		ESPtext.LinePos_2 ="Center";
		ESPtext.LinePos_3 ="Bottom";

		// Aimbot
		AimbotText.Enable ="Enable Aimbot";
		AimbotText.FeatureName =" Aimbot";
		AimbotText.HotKeyList ="Hotkey   ";
		AimbotText.Toggle ="Toggle Mode";
		AimbotText.DrawFov ="Draw Fov";
		AimbotText.VisCheck ="Visible Only";
		AimbotText.JumpCheck ="On Ground Only";
		AimbotText.FovSlider ="FOV: ";
		AimbotText.FovMinSlider ="MinFOV: ";
		AimbotText.SmoothSlider ="Smooth: ";
		AimbotText.BoneList ="Hitbox";
		AimbotText.SprayBoneList ="Spray";
		AimbotText.Tip ="Aimbot will not work while the menu is opened";
		AimbotText.ScopeOnly ="Scope Only ";
		AimbotText.AimLock ="Aim Lock";
		AimbotText.AutoShot ="Auto Shot";
		AimbotText.BulletSlider ="Start Bullet: ";
		AimbotText.IgnoreFlash ="Ignore Flash ";
		AimbotText.Ragebot ="Ragebot";

		// RCS
		RCStext.Toggle ="Recoil Control";
		RCStext.Yaw ="Yaw: ";
		RCStext.Pitch ="Pitch: ";

		// Radar
		RadarText.Toggle ="Show Radar";
		RadarText.FeatureName =" Radar";
		RadarText.StyleList ="Style";
		RadarText.CustomCheck ="Custom";
		RadarText.CrossLine ="Cross Line";
		RadarText.SizeSlider ="Point Size:";
		RadarText.ProportionSlider ="Proportion:";
		RadarText.RangeSlider ="Range:";
		RadarText.AlphaSlider ="Window Background Alpha:";

		// Triggerbot
		TriggerText.Enable ="Enable Triggerbot";
		TriggerText.FeatureName =" Triggerbot";
		TriggerText.HotKeyList ="Hotkey   ";
		TriggerText.Toggle ="Always Active";
		TriggerText.ScopeOnly ="Scope Only"; 
		TriggerText.IgnoreFlash ="Ignore Flash";
		TriggerText.DelaySlider ="Shot Delay:";
		TriggerText.FakeShotSlider ="Shot Duration:";

		// Crosshairs
		CrosshairsText.Toggle ="Show Crosshairs";
		CrosshairsText.FeatureName =" Crosshairs";
		CrosshairsText.PresetList ="Presets";
		CrosshairsText.ColorEditor ="Crosshairs Color";
		CrosshairsText.Dot ="Center Dot";
		CrosshairsText.DotSizeSlider ="Dot Size:";
		CrosshairsText.Outline ="Outline";
		CrosshairsText.Crossline ="Crossline";
		CrosshairsText.hLengthSlider ="Horizontal Length:";
		CrosshairsText.vLengthSilder ="Vertical Length:";
		CrosshairsText.GapSlider ="Gap:";
		CrosshairsText.ThicknessSlider ="Thickness:";
		CrosshairsText.tStyle ="T Style";
		CrosshairsText.Circle ="Circle";
		CrosshairsText.RadiusSlider ="Circle Radius:";
		CrosshairsText.TargetCheck ="Targeting Crosshairs";
		CrosshairsText.TeamCheck ="TeamCheck";

		// Misc 
		MiscText.FeatureName =" Misc";
		MiscText.ThemeList ="Skin       ";
		MiscText.StyleList ="Style";
		MiscText.HeadshotLine ="Headshot Line";
		MiscText.SpecCheck ="Cheat in Spec";
		MiscText.NoFlash ="No Flash";
		MiscText.FastStop ="Fast Stop";
		MiscText.HitSound ="Hit Sound ";
		MiscText.bmbTimer ="Bomb Timer";
		MiscText.SpecList ="Spec List";
		MiscText.Bhop ="Bhop";
		MiscText.Watermark ="Watermark";
		MiscText.CheatList ="Cheat List";
		MiscText.TeamCheck ="Team Check";
		MiscText.AntiRecord ="Anti Record";
		MiscText.MoneyService ="Money Services";
		MiscText.ShowCashSpent ="Show Cash Spent";
		MiscText.EnemySensor ="Glow";
		MiscText.RadarHack ="Radar Hack";
		MiscText.FastStop ="Fast Stop";
		MiscText.VisCheckDisable ="Visible Check DISABLED";
		MiscText.NoSmoke ="No Smoke";
		MiscText.SmokeColor ="Smoke Color";
		MiscText.fovchanger ="Fov Changer: ";
		MiscText.ForceScope ="Force Scope";
		MiscText.FlashImmunity ="Flash Immunity: ";
		MiscText.NightMode ="Night Mode";
		MiscText.Alpha ="Alpha: ";
		MiscText.JumpThrow ="Jump Throw";

		MiscText.FakeDuck ="Fake Duck";

		MiscText.LanguageList ="Language";

		// Config Menu
		ConfigText.FeatureName ="Config Loader";
		ConfigText.MyConfigs ="Config List";
		ConfigText.Load ="Load Selected";
		ConfigText.Save ="Save Selected";
		ConfigText.Delete ="Delete Selected";
		ConfigText.Reset ="Reset Config";
		ConfigText.Create ="Create";
		ConfigText.OpenFolder ="Open Folder";
		ConfigText.SeparateLine ="Create Config";
		ConfigText.AuthorName ="Author Name";
		ConfigText.ConfigName ="Config Name";

		ConfigText.SafeMode ="Safe Mode";
		ConfigText.fpsCap ="Frame Limit: ";
		ConfigText.SafeModeHoveredTip ="Disable all unsafe functions that modify game's memory";

		// Readme Menu
		ReadMeText.FeatureName =" README";
		ReadMeText.LastUpdate ="Last update: ";
		ReadMeText.SourceButton ="Source Code";
		ReadMeText.DiscordButton ="Join Discord";
		ReadMeText.OffsetsTitle ="Offsets:";
		return;
	}


}
