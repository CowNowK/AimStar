#pragma once
#include "Game.h"
#include "Bone.h"

namespace MenuConfig
{
	inline std::string path = "";
	inline std::string SoundPath = "";
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

	inline bool ShowRadar = false;
	inline float RadarRange = 150;
	inline float RadarPointSizeProportion = 1.f;
	inline bool ShowRadarCrossLine = false;
	inline ImColor RadarCrossLineColor = ImColor(220, 220, 220, 255);
	// 0: circle 1: arrow 2: circle with arrow
	inline int RadarType = 2;
	inline float Proportion = 3300.f;
	inline bool customRadar = false;
	inline float RadarBgAlpha = 0.1f;

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

	inline bool BypassOBS = false;

	inline bool BunnyHop = false;
	inline bool WorkInSpec = true;
	inline bool NoFlash = false;
	inline bool WaterMark = false;
	inline bool CheatList = false;
	inline bool HitSound = false;
	inline bool SkinChanger = false;
	inline bool Glow = false;
	inline bool bmbTimer = false;
	inline bool infinity = false;
	inline bool SpecList = false;
	inline ImColor BombTimerCol = ImColor(255, 120, 0, 255);
	inline ImColor GlowColor = ImColor(255, 0, 0, 100);

}

namespace CrosshairConfig
{
	inline float CrossHairSize = 75;

	inline bool ShowCrossHair = false;
	inline bool drawDot = true;
	inline bool drawCrossline = true;
	inline bool tStyle = false;
	inline bool drawCircle = false;
	inline bool drawOutLine = true;
	inline bool showTargeting = false;
	inline bool DynamicGap = false;
	inline bool TeamCheck = true;

	inline int crosshairPreset = 0;
	inline int Gap = 8;
	inline int HorizontalLength = 6;
	inline int VerticalLength = 6;
	inline int Thickness = 1.0f;
	inline float DotSize = 1.0f;
	inline float CircleRadius = 3.f;

	inline bool isAim = false;
	inline bool isJump = false;
	
	inline ImColor CrossHairColor = ImColor(0, 255, 0, 255);
	inline ImColor TargetedColor = ImColor(255, 0, 0, 255);
}

namespace ESPConfig
{
	inline bool ESPenbled = false;
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
	inline ImColor FilledColor = ImColor(255, 255, 255, 255);
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