#pragma once
#include "Game.h"
#include "Bone.h"

namespace MenuConfig
{
	inline std::string path = "";
	inline std::string SoundPath = "";

	struct {
		// 0: Visual 1: Aimbot 2: Misc 3: Config
		int MenuPage = 0;
		ImVec2 LogoPos		= ImVec2(30.f, 30.f);
		ImVec2 Button1Pos	= ImVec2(30.f, 142.f);
		ImVec2 Button2Pos	= ImVec2(30.f, 142.f + 90.f);
		ImVec2 Button3Pos	= ImVec2(30.f, 142.f + 180.f);
		ImVec2 Button4Pos	= ImVec2(30.f, 142.f + 270.f);
		ImVec2 ChildPos		= ImVec2(257.f, 20.f);
		ImVec2 ChildSize	= ImVec2(574.f, 474.f);
	} WCS;	// Window Component Settings
	
	struct {
		bool BunnyHop = false;
		bool WorkInSpec = true;
		bool NoFlash = false;
		bool WaterMark = false;
		bool CheatList = false;
		bool HitSound = false;
		bool SkinChanger = false;
		bool bmbTimer = false;
		bool SpecList = false;
		ImColor BombTimerCol = ImColor(255, 120, 0, 255);
		ImColor GlowColor = ImColor(255, 0, 0, 100);
	} Misc;

	struct {
		bool ShowRadar = false;
		float RadarRange = 150;
		float RadarPointSizeProportion = 1.f;
		bool ShowRadarCrossLine = false;
		ImColor RadarCrossLineColor = ImColor(220, 220, 220, 255);
		// 0: circle 1: arrow 2: circle with arrow
		int RadarType = 2;
		float Proportion = 3300.f;
		bool customRadar = false;
		float RadarBgAlpha = 0.1f;
	} Radar;

	struct {
		float CrossHairSize = 75;

		bool ShowCrossHair = false;
		bool drawDot = true;
		bool drawCrossline = true;
		bool tStyle = false;
		bool drawCircle = false;
		bool drawOutLine = true;
		bool showTargeting = false;
		bool DynamicGap = false;
		bool TeamCheck = true;

		int crosshairPreset = 0;
		int Gap = 8;
		int HorizontalLength = 6;
		int VerticalLength = 6;
		int Thickness = 1.0f;
		float DotSize = 1.0f;
		float CircleRadius = 3.f;

		bool isAim = false;
		bool isJump = false;

		ImColor CrossHairColor = ImColor(0, 255, 0, 255);
		ImColor TargetedColor = ImColor(255, 0, 0, 255);
	} Crosshairs;

	// 0: English 1: SimplifiedChinese
	inline int Language = 0;

	inline bool AirJump = false;
	inline float ComboWidth = 100.f;
	inline float SliderWidth = 150.f;
	inline int MenuStyle = 0;
	// 0: Window 1: Collapse
	inline int WindowStyle = 0;

	inline bool AimBot = false;
	inline bool AimAlways = false;
	inline bool AimToggleMode = false;
	inline int AimBotHotKey = 0;
	// 0: head 1: neck 3: spine
	inline int  AimPosition = 0;
	inline DWORD  AimPositionIndex = BONEINDEX::head;
	inline bool VisibleCheck = true;

	inline bool RCS = false;
	inline bool Bhop = false;

	// 0: normal 1: dynamic 2: Flat
	inline int BoxType = 0;
	// 0: Vertical 1: Horizontal
	inline int  HealthBarType = 0;
	// 0: Top 1: Center 2: Bottom
	inline int  LinePos = 0;

	inline ImColor FovCircleColor = ImColor(180, 255, 0, 255);

	inline bool ShowMenu = true;

	inline bool TriggerBot = false;
	inline bool TriggerAlways = false;
	inline int TriggerHotKey = 0;

	inline bool TeamCheck = true;

	inline bool ShowHeadShootLine = false;
	inline ImColor HeadShootLineColor = ImColor(255, 255, 255, 200);

	inline bool ShowFovLine = false;
	inline ImColor FovLineColor = ImColor(55, 55, 55, 220);
	inline float FovLineSize = 60.f;

	inline bool ShowLineToEnemy = false;
	inline ImColor LineToEnemyColor = ImColor(255, 255, 255, 220);

	inline bool Glow = false;

	inline bool BypassOBS = false;
}

namespace ESPConfig
{
	inline bool ESPenbled = true;
	inline bool ShowBoneESP = true;
	inline bool ShowBoxESP = true;
	inline bool ShowHealthBar = true;
	inline bool ShowWeaponESP = false;
	inline bool ShowEyeRay = false;
	inline bool ShowPlayerName = true;
	inline bool DrawFov = false;
	inline bool ShowDistance = false;
	inline bool ShowHeadBox = false;
	inline bool ShowPreview = true;
	inline bool VisibleCheck = false;
	inline bool FilledBox = false;
	inline bool FilledVisBox = false;
	inline bool MultiColor = false;
	// 0: normal 1: Flat
	inline int HeadBoxStyle = 0;
	inline float BoxRounding = 5.0f;
	inline float BoxAlpha = 0.35f;

	inline ImColor BoneColor = ImColor(0, 255, 255, 255);
	inline ImColor BoxColor = ImColor(255, 80, 0, 255);
	inline ImColor EyeRayColor = ImColor(255, 0, 0, 255);
	inline ImColor HeadBoxColor = ImColor(255, 255, 255, 255);
	inline ImColor VisibleColor = ImColor(255, 196, 0, 255);
	inline ImColor FilledColor = ImColor(255, 255, 255, 128);
	inline ImColor BoxFilledVisColor = ImColor(0, 0, 255, 255);
	inline ImColor FilledColor2 = ImColor(0, 255, 102, 255);

	// Penis Config
	inline bool ShowPenis = false;
	inline float PenisLength = 15.f;
	inline float PenisSize = 1.3f;
	inline ImColor PenisColor = ImColor(255, 0, 0, 200);
}

namespace DebuggerConfig
{
	inline bool Debug = false;
}