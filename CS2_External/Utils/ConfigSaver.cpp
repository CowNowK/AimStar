#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ConfigSaver.hpp"
#include "../Features/StyleChanger.h"
#include "../Resources/Language.h"
#include "../MenuConfig.hpp"
#include "../TriggerBot.h"
#include "../Features/Aimbot/Legitbot.hpp"

namespace MyConfigSaver {

    void SaveConfig(const std::string& filename, const std::string& author) {
        std::ofstream configFile(MenuConfig::path + '\\' + filename);
        if (!configFile.is_open()) {
            std::cerr << "[Info] Error: Could not open the configuration file." << std::endl;
            return;
        }

        YAML::Emitter emitter;

        emitter << YAML::Comment("AimStar Config File\nVersion: 4.7\nAuthor: " + author);
        emitter << YAML::BeginMap;

        emitter << YAML::Key << "ESP";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << ESPConfig::ESPenabled;
        emitter << YAML::Key << "BoneESP" << YAML::Value << ESPConfig::ShowBoneESP;
        emitter << YAML::Key << "BoxESP" << YAML::Value << ESPConfig::ShowBoxESP;
        emitter << YAML::Key << "BoxType" << YAML::Value << MenuConfig::BoxType;
        emitter << YAML::Key << "SnapLine" << YAML::Value << ESPConfig::ShowLineToEnemy;
        emitter << YAML::Key << "LinePos" << YAML::Value << ESPConfig::LinePos;
        emitter << YAML::Key << "HealthBar" << YAML::Value << ESPConfig::ShowHealthBar;
        emitter << YAML::Key << "AmmoBar" << YAML::Value << ESPConfig::AmmoBar;
        emitter << YAML::Key << "WeaponESP" << YAML::Value << ESPConfig::ShowWeaponESP;
        emitter << YAML::Key << "EyeRay" << YAML::Value << ESPConfig::ShowEyeRay;
        emitter << YAML::Key << "PlayerName" << YAML::Value << ESPConfig::ShowPlayerName;
        emitter << YAML::Key << "DistanceESP" << YAML::Value << ESPConfig::ShowDistance;
        emitter << YAML::Key << "HealthNum" << YAML::Value << ESPConfig::ShowHealthNum;
        emitter << YAML::Key << "HeadBox" << YAML::Value << ESPConfig::ShowHeadBox;
        emitter << YAML::Key << "Preview" << YAML::Value << ESPConfig::ShowPreview;
        emitter << YAML::Key << "VisCheck" << YAML::Value << ESPConfig::VisibleCheck;
        emitter << YAML::Key << "FilledBox" << YAML::Value << ESPConfig::FilledBox;
        emitter << YAML::Key << "FilledVisBox" << YAML::Value << ESPConfig::FilledVisBox;
        emitter << YAML::Key << "MultiColor" << YAML::Value << ESPConfig::MultiColor;
        emitter << YAML::Key << "OutLine" << YAML::Value << ESPConfig::OutLine;
        emitter << YAML::Key << "HeadBoxStyle" << YAML::Value << ESPConfig::HeadBoxStyle;
        emitter << YAML::Key << "BoxRounding" << YAML::Value << ESPConfig::BoxRounding;
        emitter << YAML::Key << "ShowScoped" << YAML::Value << ESPConfig::ShowIsScoped;
        emitter << YAML::Key << "ArmorBar" << YAML::Value << ESPConfig::ArmorBar;
        emitter << YAML::Key << "ArmorNum" << YAML::Value << ESPConfig::ShowArmorNum;
        emitter << YAML::Key << "MaxRenderDistance" << YAML::Value << ESPConfig::RenderDistance;
        emitter << YAML::Key << "BoneColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::BoneColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::BoneColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::BoneColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::BoneColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "BoxColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::BoxColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::BoxColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::BoxColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::BoxColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "SnapLineColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::LineToEnemyColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::LineToEnemyColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::LineToEnemyColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::LineToEnemyColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "EyeRayColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::EyeRayColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::EyeRayColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::EyeRayColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::EyeRayColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "HeadBoxColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::HeadBoxColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::HeadBoxColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::HeadBoxColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::HeadBoxColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "VisibleColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::VisibleColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::VisibleColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::VisibleColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::VisibleColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FilledColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::FilledColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::FilledColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::FilledColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::FilledColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FilledColor2";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::FilledColor2.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::FilledColor2.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::FilledColor2.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::FilledColor2.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FilledVisColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::BoxFilledVisColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::BoxFilledVisColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::BoxFilledVisColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::BoxFilledVisColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "PenisColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << ESPConfig::PenisColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << ESPConfig::PenisColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << ESPConfig::PenisColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << ESPConfig::PenisColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "PenisESP" << YAML::Value << ESPConfig::ShowPenis;
        emitter << YAML::Key << "PenisLength" << YAML::Value << ESPConfig::PenisLength;
        emitter << YAML::Key << "PenisSize" << YAML::Value << ESPConfig::PenisSize;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Crosshairs";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << CrosshairsCFG::ShowCrossHair;
        emitter << YAML::Key << "Size" << YAML::Value << CrosshairsCFG::CrossHairSize;
        emitter << YAML::Key << "Dot" << YAML::Value << CrosshairsCFG::drawDot;
        emitter << YAML::Key << "Crossline" << YAML::Value << CrosshairsCFG::drawCrossline;
        emitter << YAML::Key << "tStyle" << YAML::Value << CrosshairsCFG::tStyle;
        emitter << YAML::Key << "Circle" << YAML::Value << CrosshairsCFG::drawCircle;
        emitter << YAML::Key << "Outline" << YAML::Value << CrosshairsCFG::drawOutLine;
        emitter << YAML::Key << "DynamicGap" << YAML::Value << CrosshairsCFG::DynamicGap;
        emitter << YAML::Key << "TeamCheck" << YAML::Value << CrosshairsCFG::TeamCheck;
        emitter << YAML::Key << "Preset" << YAML::Value << CrosshairsCFG::crosshairPreset;
        emitter << YAML::Key << "Gap" << YAML::Value << CrosshairsCFG::Gap;
        emitter << YAML::Key << "H_Length" << YAML::Value << CrosshairsCFG::HorizontalLength;
        emitter << YAML::Key << "V_Length" << YAML::Value << CrosshairsCFG::VerticalLength;
        emitter << YAML::Key << "Thickness" << YAML::Value << CrosshairsCFG::Thickness;
        emitter << YAML::Key << "DotSize" << YAML::Value << CrosshairsCFG::DotSize;
        emitter << YAML::Key << "CircleRadius" << YAML::Value << CrosshairsCFG::CircleRadius;
        emitter << YAML::Key << "TargetCheck" << YAML::Value << MenuConfig::TargetingCrosshairs;
        emitter << YAML::Key << "CrosshairsColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << CrosshairsCFG::CrossHairColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << CrosshairsCFG::CrossHairColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << CrosshairsCFG::CrossHairColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << CrosshairsCFG::CrossHairColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "TargetedColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << CrosshairsCFG::TargetedColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << CrosshairsCFG::TargetedColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << CrosshairsCFG::TargetedColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << CrosshairsCFG::TargetedColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Radar";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << RadarCFG::ShowRadar;
        emitter << YAML::Key << "Type" << YAML::Value << RadarCFG::RadarType;
        emitter << YAML::Key << "Range" << YAML::Value << RadarCFG::RadarRange;
        emitter << YAML::Key << "Proportion" << YAML::Value << RadarCFG::Proportion;
        emitter << YAML::Key << "PointProportion" << YAML::Value << RadarCFG::RadarPointSizeProportion;
        emitter << YAML::Key << "Alpha" << YAML::Value << RadarCFG::RadarBgAlpha;
        emitter << YAML::Key << "Custom" << YAML::Value << RadarCFG::customRadar;
        emitter << YAML::Key << "Crossline" << YAML::Value << RadarCFG::ShowRadarCrossLine;
        emitter << YAML::Key << "CrosslineColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << RadarCFG::RadarCrossLineColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << RadarCFG::RadarCrossLineColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << RadarCFG::RadarCrossLineColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << RadarCFG::RadarCrossLineColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Misc";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Bhop" << YAML::Value << MiscCFG::BunnyHop;
        emitter << YAML::Key << "HeadShootLine" << YAML::Value << MenuConfig::ShowHeadShootLine;
        emitter << YAML::Key << "HeadShootLineColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << MenuConfig::HeadShootLineColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << MenuConfig::HeadShootLineColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << MenuConfig::HeadShootLineColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << MenuConfig::HeadShootLineColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "WorkInSpec" << YAML::Value << MiscCFG::WorkInSpec;
        emitter << YAML::Key << "Fov" << YAML::Value << MiscCFG::Fov;
        emitter << YAML::Key << "FlashImmunity" << YAML::Value << MiscCFG::FlashImmunity;
        emitter << YAML::Key << "CheatList" << YAML::Value << MiscCFG::CheatList;
        emitter << YAML::Key << "Watermark" << YAML::Value << MiscCFG::WaterMark;
        emitter << YAML::Key << "HitMarker" << YAML::Value << MiscCFG::HitMarker;
        emitter << YAML::Key << "HitSounds" << YAML::Value << MiscCFG::HitSound;
        emitter << YAML::Key << "BombTimer" << YAML::Value << MiscCFG::bmbTimer;
        emitter << YAML::Key << "TimerColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << MiscCFG::BombTimerCol.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << MiscCFG::BombTimerCol.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << MiscCFG::BombTimerCol.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << MiscCFG::BombTimerCol.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "FastStop" << YAML::Value << MiscCFG::FastStop;
        emitter << YAML::Key << "SpecList" << YAML::Value << MiscCFG::SpecList;
        emitter << YAML::Key << "Glow" << YAML::Value << MiscCFG::EnemySensor;
        emitter << YAML::Key << "GlowColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << MiscCFG::GlowColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << MiscCFG::GlowColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << MiscCFG::GlowColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << MiscCFG::GlowColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "RainbowedGlow" << YAML::Value << MiscCFG::GlowRainbow;
        emitter << YAML::Key << "RadarHack" << YAML::Value << MiscCFG::RadarHack;
        emitter << YAML::Key << "MoneyService";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << MiscCFG::MoneyService;
        emitter << YAML::Key << "ShowCashSpent" << YAML::Value << MiscCFG::ShowCashSpent;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "NoSmoke" << YAML::Value << MiscCFG::NoSmoke;
        emitter << YAML::Key << "NightMode" << YAML::Value << MiscCFG::NightMode;
        emitter << YAML::Key << "NightModeAlpha" << YAML::Value << MiscCFG::NightModeAlpha;
        emitter << YAML::Key << "JumpThrow" << YAML::Value << MiscCFG::jumpthrow;
        emitter << YAML::Key << "TeamCheck" << YAML::Value << MenuConfig::TeamCheck;
        emitter << YAML::Key << "AntiRecord" << YAML::Value << MenuConfig::BypassOBS;
        emitter << YAML::Key << "Jitter" << YAML::Value << MiscCFG::Jitter;
        emitter << YAML::Key << "SmokeColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << MiscCFG::SmokeColored;
        emitter << YAML::Key << "r" << YAML::Value << MiscCFG::SmokeColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << MiscCFG::SmokeColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << MiscCFG::SmokeColor.Value.z;
        emitter << YAML::EndMap;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Aimbot";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << MenuConfig::AimBot;
        emitter << YAML::Key << "Ragebot" << YAML::Value << AimControl::Rage;
        emitter << YAML::Key << "AimLock" << YAML::Value << AimControl::AimLock;
        emitter << YAML::Key << "ToggleMode" << YAML::Value << MenuConfig::AimToggleMode;
        emitter << YAML::Key << "Hotkey" << YAML::Value << MenuConfig::AimBotHotKey; 
        emitter << YAML::Key << "AimBullet" << YAML::Value << AimControl::AimBullet;
        emitter << YAML::Key << "Fov" << YAML::Value << AimControl::AimFov;
        emitter << YAML::Key << "FovMin" << YAML::Value << AimControl::AimFovMin;
        emitter << YAML::Key << "FovCircle" << YAML::Value << ESPConfig::DrawFov;
        emitter << YAML::Key << "CircleColor";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "r" << YAML::Value << MenuConfig::FovCircleColor.Value.x;
        emitter << YAML::Key << "g" << YAML::Value << MenuConfig::FovCircleColor.Value.y;
        emitter << YAML::Key << "b" << YAML::Value << MenuConfig::FovCircleColor.Value.z;
        emitter << YAML::Key << "a" << YAML::Value << MenuConfig::FovCircleColor.Value.w;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "Smooth" << YAML::Value << AimControl::Smooth;
        emitter << YAML::Key << "Hitboxes" << YAML::Value << AimControl::HitboxList;
        emitter << YAML::Key << "SprayHitbox" << YAML::Value << MenuConfig::SparyPosition;
        emitter << YAML::Key << "VisibleCheck" << YAML::Value << MenuConfig::VisibleCheck;
        emitter << YAML::Key << "IgnoreFlash" << YAML::Value << AimControl::IgnoreFlash;
        emitter << YAML::Key << "ScopeOnly" << YAML::Value << AimControl::ScopeOnly;
        emitter << YAML::Key << "AutoShot" << YAML::Value << AimControl::AutoShot;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Recoil Control System";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << MenuConfig::RCS;
        emitter << YAML::Key << "Yaw" << YAML::Value << RCS::RCSScale.x;
        emitter << YAML::Key << "Pitch" << YAML::Value << RCS::RCSScale.y;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Triggerbot";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << MenuConfig::TriggerBot;
        emitter << YAML::Key << "Hotkey" << YAML::Value << MenuConfig::TriggerHotKey;
        emitter << YAML::Key << "Delay" << YAML::Value << TriggerBot::TriggerDelay;
        emitter << YAML::Key << "FakeShot" << YAML::Value << TriggerBot::ShotDuration;
        emitter << YAML::Key << "ScopeOnly" << YAML::Value << TriggerBot::ScopeOnly;
        emitter << YAML::Key << "IgnoreFlash" << YAML::Value << TriggerBot::IgnoreFlash;
        emitter << YAML::Key << "AutoMode" << YAML::Value << MenuConfig::TriggerAlways;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Menu";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "RenderFrameLimit" << YAML::Value << MenuConfig::MaxRenderFPS;
        emitter << YAML::Key << "Theme" << YAML::Value << MenuConfig::Theme;
        emitter << YAML::EndMap;

        // Custom Theme Saver
        if (MenuConfig::Theme == 2)
        {
            ImColor windowBgColor = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);
            ImColor borderColor = ImGui::GetStyleColorVec4(ImGuiCol_Border);
            ImColor childBgColor = ImGui::GetStyleColorVec4(ImGuiCol_ChildBg);
            ImColor ButtonColor = ImGui::GetStyleColorVec4(ImGuiCol_Button);
            ImColor ButtonHovered = ImGui::GetStyleColorVec4(ImGuiCol_ButtonHovered);
            ImColor ButtonActive = ImGui::GetStyleColorVec4(ImGuiCol_ButtonActive);
            ImColor FrameBgColor = ImGui::GetStyleColorVec4(ImGuiCol_FrameBg);
            ImColor FrameHovered = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgHovered);
            ImColor FrameActive = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgActive);
            ImColor Header = ImGui::GetStyleColorVec4(ImGuiCol_Header);
            ImColor HeaderActive = ImGui::GetStyleColorVec4(ImGuiCol_HeaderActive);
            ImColor HeaderHovered = ImGui::GetStyleColorVec4(ImGuiCol_HeaderHovered);
            ImColor ScrollBg = ImGui::GetStyleColorVec4(ImGuiCol_ScrollbarBg);

            ImColor FeatureName = ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled);
            ImColor Text = ImGui::GetStyleColorVec4(ImGuiCol_Text);
            ImColor Separator = ImGui::GetStyleColorVec4(ImGuiCol_Separator);

            emitter << YAML::Key << "Custom Theme";
            emitter << YAML::Value;
            emitter << YAML::BeginMap;
            emitter << YAML::Key << "Button Border" << YAML::Value << ImColorToUInt32(MenuConfig::ButtonBorderColor);
            emitter << YAML::Key << "Feature Name" << YAML::Value << ImColorToUInt32(FeatureName);
            emitter << YAML::Key << "Text" << YAML::Value << ImColorToUInt32(Text);
            emitter << YAML::Key << "Border" << YAML::Value << ImColorToUInt32(borderColor);
            emitter << YAML::Key << "Button" << YAML::Value << ImColorToUInt32(ButtonColor);
            emitter << YAML::Key << "Button Hovered" << YAML::Value << ImColorToUInt32(ButtonHovered);
            emitter << YAML::Key << "Button Active" << YAML::Value << ImColorToUInt32(ButtonActive);
            emitter << YAML::Key << "Child Window Bg" << YAML::Value << ImColorToUInt32(childBgColor);
            emitter << YAML::Key << "Frame Bg" << YAML::Value << ImColorToUInt32(FrameBgColor);
            emitter << YAML::Key << "Frame Bg Hovered" << YAML::Value << ImColorToUInt32(FrameHovered);
            emitter << YAML::Key << "Frame Bg Active" << YAML::Value << ImColorToUInt32(FrameActive);
            emitter << YAML::Key << "Header" << YAML::Value << ImColorToUInt32(Header);
            emitter << YAML::Key << "Header Hovered" << YAML::Value << ImColorToUInt32(HeaderHovered);
            emitter << YAML::Key << "Header Active" << YAML::Value << ImColorToUInt32(HeaderActive);
            emitter << YAML::Key << "Scrollbar Bg" << YAML::Value << ImColorToUInt32(ScrollBg);
            emitter << YAML::Key << "Separator" << YAML::Value << ImColorToUInt32(Separator);
            emitter << YAML::Key << "Window Bg" << YAML::Value << ImColorToUInt32(windowBgColor);
            emitter << YAML::EndMap;
        }

        emitter << YAML::EndMap;

        configFile << emitter.c_str();
        configFile.close();
        std::cout << "[Info] Configuration saved to " << MenuConfig::path + '\\' + filename << std::endl;
    }

    // Function to load the configuration from a file
    void LoadConfig(const std::string& filename) {
        YAML::Node config = YAML::LoadFile(MenuConfig::path + '\\' + filename);
        if (config["ESP"]) {
            // If you want to make the new version compatible with the old configuration, you can use "<Config>.IsDefine() ? <Config>.as() : <Default Value>"
            ESPConfig::ESPenabled = ReadData(config["ESP"]["Enable"], false);
            ESPConfig::ShowBoneESP = ReadData(config["ESP"]["BoneESP"], false);
            ESPConfig::ShowBoxESP = ReadData(config["ESP"]["BoxESP"], false);
            MenuConfig::BoxType = ReadData(config["ESP"]["BoxType"], 0);
            ESPConfig::ShowLineToEnemy = ReadData(config["ESP"]["SnapLine"], false);
            ESPConfig::LinePos = ReadData(config["ESP"]["LinePos"], 0);
            ESPConfig::ShowHealthBar = ReadData(config["ESP"]["HealthBar"], false);
            ESPConfig::AmmoBar = ReadData(config["ESP"]["AmmoBar"], false);
            ESPConfig::ShowScoping = ReadData(config["ESP"]["Scoping"], false);
            ESPConfig::ShowWeaponESP = ReadData(config["ESP"]["WeaponESP"], false);
            ESPConfig::ShowEyeRay = ReadData(config["ESP"]["EyeRay"], false);
            ESPConfig::ShowPlayerName = ReadData(config["ESP"]["PlayerName"], false);
            ESPConfig::ShowDistance = ReadData(config["ESP"]["DistanceESP"], false);
            ESPConfig::ShowHealthNum = ReadData(config["ESP"]["HealthNum"], false);
            ESPConfig::ShowHeadBox = ReadData(config["ESP"]["HeadBox"], false);
            ESPConfig::ShowPreview = ReadData(config["ESP"]["Preview"], false);
            ESPConfig::VisibleCheck = ReadData(config["ESP"]["VisCheck"], false);
            ESPConfig::FilledBox = ReadData(config["ESP"]["FilledBox"], false);
            ESPConfig::FilledVisBox = ReadData(config["ESP"]["FilledVisBox"], false);
            ESPConfig::MultiColor = ReadData(config["ESP"]["MultiColor"], false);
            ESPConfig::OutLine = ReadData(config["ESP"]["OutLine"], false);
            ESPConfig::BoxRounding = ReadData(config["ESP"]["BoxRounding"], 0.f);
            ESPConfig::ShowIsScoped = ReadData(config["ESP"]["ShowScoped"], false);
            ESPConfig::ArmorBar = ReadData(config["ESP"]["ArmorBar"], false);
            ESPConfig::ShowArmorNum = ReadData(config["ESP"]["ArmorNum"], false);
            ESPConfig::RenderDistance = ReadData(config["ESP"]["MaxRenderDistance"], 80);
            ESPConfig::BoneColor.Value.x = ReadData(config["ESP"]["BoneColor"]["r"], 0.f);
            ESPConfig::BoneColor.Value.y = ReadData(config["ESP"]["BoneColor"]["g"], 0.f);
            ESPConfig::BoneColor.Value.z = ReadData(config["ESP"]["BoneColor"]["b"], 0.f);
            ESPConfig::BoneColor.Value.w = ReadData(config["ESP"]["BoneColor"]["a"], 0.f);
            ESPConfig::BoxColor.Value.x = ReadData(config["ESP"]["BoxColor"]["r"], 0.f);
            ESPConfig::BoxColor.Value.y = ReadData(config["ESP"]["BoxColor"]["g"], 0.f);
            ESPConfig::BoxColor.Value.z = ReadData(config["ESP"]["BoxColor"]["b"], 0.f);
            ESPConfig::BoxColor.Value.w = ReadData(config["ESP"]["BoxColor"]["a"], 0.f);
            ESPConfig::LineToEnemyColor.Value.x = ReadData(config["ESP"]["SnapLineColor"]["r"], 0.f);
            ESPConfig::LineToEnemyColor.Value.y = ReadData(config["ESP"]["SnapLineColor"]["g"], 0.f);
            ESPConfig::LineToEnemyColor.Value.z = ReadData(config["ESP"]["SnapLineColor"]["b"], 0.f);
            ESPConfig::LineToEnemyColor.Value.w = ReadData(config["ESP"]["SnapLineColor"]["a"], 0.f);
            ESPConfig::HeadBoxColor.Value.x = ReadData(config["ESP"]["HeadBoxColor"]["r"], 0.f);
            ESPConfig::HeadBoxColor.Value.y = ReadData(config["ESP"]["HeadBoxColor"]["g"], 0.f);
            ESPConfig::HeadBoxColor.Value.z = ReadData(config["ESP"]["HeadBoxColor"]["b"], 0.f);
            ESPConfig::HeadBoxColor.Value.w = ReadData(config["ESP"]["HeadBoxColor"]["a"], 0.f);
            ESPConfig::VisibleColor.Value.x = ReadData(config["ESP"]["VisibleColor"]["r"], 0.f);
            ESPConfig::VisibleColor.Value.y = ReadData(config["ESP"]["VisibleColor"]["g"], 0.f);
            ESPConfig::VisibleColor.Value.z = ReadData(config["ESP"]["VisibleColor"]["b"], 0.f);
            ESPConfig::VisibleColor.Value.w = ReadData(config["ESP"]["VisibleColor"]["a"], 0.f);
            ESPConfig::FilledColor.Value.x = ReadData(config["ESP"]["FilledColor"]["r"], 0.f);
            ESPConfig::FilledColor.Value.y = ReadData(config["ESP"]["FilledColor"]["g"], 0.f);
            ESPConfig::FilledColor.Value.z = ReadData(config["ESP"]["FilledColor"]["b"], 0.f);
            ESPConfig::FilledColor.Value.w = ReadData(config["ESP"]["FilledColor"]["a"], 0.f);
            ESPConfig::FilledColor2.Value.x = ReadData(config["ESP"]["FilledColor2"]["r"], 0.f);
            ESPConfig::FilledColor2.Value.y = ReadData(config["ESP"]["FilledColor2"]["g"], 0.f);
            ESPConfig::FilledColor2.Value.z = ReadData(config["ESP"]["FilledColor2"]["b"], 0.f);
            ESPConfig::FilledColor2.Value.w = ReadData(config["ESP"]["FilledColor2"]["a"], 0.f);
            ESPConfig::BoxFilledVisColor.Value.x = ReadData(config["ESP"]["FilledVisColor"]["r"], 0.f);
            ESPConfig::BoxFilledVisColor.Value.y = ReadData(config["ESP"]["FilledVisColor"]["g"], 0.f);
            ESPConfig::BoxFilledVisColor.Value.z = ReadData(config["ESP"]["FilledVisColor"]["b"], 0.f);
            ESPConfig::BoxFilledVisColor.Value.w = ReadData(config["ESP"]["FilledVisColor"]["a"], 0.f);
            ESPConfig::EyeRayColor.Value.x = ReadData(config["ESP"]["EyeRayColor"]["r"], 0.f);
            ESPConfig::EyeRayColor.Value.y = ReadData(config["ESP"]["EyeRayColor"]["g"], 0.f);
            ESPConfig::EyeRayColor.Value.z = ReadData(config["ESP"]["EyeRayColor"]["b"], 0.f);

        }
        if (config["Crosshairs"]) {
            CrosshairsCFG::ShowCrossHair = ReadData(config["Crosshairs"]["Enable"], false);
            CrosshairsCFG::CrossHairSize = ReadData(config["Crosshairs"]["Size"], 0.f);
            CrosshairsCFG::drawDot = ReadData(config["Crosshairs"]["Dot"], false);
            CrosshairsCFG::drawCrossline = ReadData(config["Crosshairs"]["Crossline"], false);
            CrosshairsCFG::tStyle = ReadData(config["Crosshairs"]["tStyle"], false);
            CrosshairsCFG::drawCircle = ReadData(config["Crosshairs"]["Circle"], false);
            CrosshairsCFG::drawOutLine = ReadData(config["Crosshairs"]["Outline"], false);
            CrosshairsCFG::DynamicGap = ReadData(config["Crosshairs"]["DynamicGap"], false);
            CrosshairsCFG::TeamCheck = ReadData(config["Crosshairs"]["TeamCheck"], false);
            CrosshairsCFG::crosshairPreset = ReadData(config["Crosshairs"]["Preset"], 0);
            CrosshairsCFG::Gap = ReadData(config["Crosshairs"]["Gap"], 0);
            CrosshairsCFG::HorizontalLength = ReadData(config["Crosshairs"]["H_Length"], 0);
            CrosshairsCFG::VerticalLength = ReadData(config["Crosshairs"]["V_Length"], 0);
            CrosshairsCFG::Thickness = ReadData(config["Crosshairs"]["Thickness"], 0);
            CrosshairsCFG::DotSize = ReadData(config["Crosshairs"]["DotSize"], 0.f);
            CrosshairsCFG::CircleRadius = ReadData(config["Crosshairs"]["CircleRadius"], 0.f);
            MenuConfig::TargetingCrosshairs = ReadData(config["Crosshairs"]["TargetCheck"], false);
            CrosshairsCFG::CrossHairColor.Value.x = ReadData(config["Crosshairs"]["CrosshairsColor"]["r"], 0.f);
            CrosshairsCFG::CrossHairColor.Value.y = ReadData(config["Crosshairs"]["CrosshairsColor"]["g"], 0.f);
            CrosshairsCFG::CrossHairColor.Value.z = ReadData(config["Crosshairs"]["CrosshairsColor"]["b"], 0.f);
            CrosshairsCFG::CrossHairColor.Value.w = ReadData(config["Crosshairs"]["CrosshairsColor"]["a"], 0.f);
            CrosshairsCFG::TargetedColor.Value.x = ReadData(config["Crosshairs"]["TargetedColor"]["r"], 0.f);
            CrosshairsCFG::TargetedColor.Value.y = ReadData(config["Crosshairs"]["TargetedColor"]["g"], 0.f);
            CrosshairsCFG::TargetedColor.Value.z = ReadData(config["Crosshairs"]["TargetedColor"]["b"], 0.f);
            CrosshairsCFG::TargetedColor.Value.w = ReadData(config["Crosshairs"]["TargetedColor"]["a"], 0.f);

        }
        if (config["Radar"])
        {
            RadarCFG::ShowRadar = ReadData(config["Radar"]["Enable"], false);
            RadarCFG::RadarType = ReadData(config["Radar"]["Type"], 2);
            RadarCFG::RadarRange = ReadData(config["Radar"]["Range"], 150.f);
            RadarCFG::Proportion = ReadData(config["Radar"]["Proportion"], 3300.f);
            RadarCFG::RadarPointSizeProportion = ReadData(config["Radar"]["PointProportion"], 1.f);
            RadarCFG::RadarBgAlpha = ReadData(config["Radar"]["Alpha"], 0.1f);
            RadarCFG::customRadar = ReadData(config["Radar"]["Custom"], false);
            RadarCFG::ShowRadarCrossLine = ReadData(config["Radar"]["Crossline"], false);
            RadarCFG::RadarCrossLineColor.Value.x = ReadData(config["Radar"]["CrosslineColor"]["r"], 0.f);
            RadarCFG::RadarCrossLineColor.Value.y = ReadData(config["Radar"]["CrosslineColor"]["g"], 0.f);
            RadarCFG::RadarCrossLineColor.Value.z = ReadData(config["Radar"]["CrosslineColor"]["b"], 0.f);
            RadarCFG::RadarCrossLineColor.Value.w = ReadData(config["Radar"]["CrosslineColor"]["a"], 0.f);

        }
        if (config["Misc"])
        {
            MiscCFG::BunnyHop = ReadData(config["Misc"]["Bhop"], false);
            MenuConfig::ShowHeadShootLine = ReadData(config["Misc"]["HeadShootLine"], false);
            MenuConfig::HeadShootLineColor.Value.x = ReadData(config["Misc"]["HeadShootLineColor"]["r"], 0.f);
            MenuConfig::HeadShootLineColor.Value.y = ReadData(config["Misc"]["HeadShootLineColor"]["g"], 0.f);
            MenuConfig::HeadShootLineColor.Value.z = ReadData(config["Misc"]["HeadShootLineColor"]["b"], 0.f);
            MenuConfig::HeadShootLineColor.Value.w = ReadData(config["Misc"]["HeadShootLineColor"]["a"], 0.f);
            MiscCFG::WorkInSpec = ReadData(config["Misc"]["WorkInSpec"], false);
            MiscCFG::FovHacker = ReadData(config["Misc"]["Fov"], 90);
            MiscCFG::FlashImmunity = ReadData(config["Misc"]["FlashImmunity"], 0.f);
            MiscCFG::CheatList = ReadData(config["Misc"]["CheatList"], false);
            MiscCFG::WaterMark = ReadData(config["Misc"]["Watermark"], false);
            MiscCFG::HitMarker = ReadData(config["Misc"]["HitMarker"], false);
            MiscCFG::HitSound = ReadData(config["Misc"]["HitSounds"], 0);
            MiscCFG::bmbTimer = ReadData(config["Misc"]["BombTimer"], false);
            MiscCFG::BombTimerCol.Value.x = ReadData(config["Misc"]["TimerColor"]["r"], 0.f);
            MiscCFG::BombTimerCol.Value.y = ReadData(config["Misc"]["TimerColor"]["g"], 0.f);
            MiscCFG::BombTimerCol.Value.z = ReadData(config["Misc"]["TimerColor"]["b"], 0.f);
            MiscCFG::BombTimerCol.Value.w = ReadData(config["Misc"]["TimerColor"]["a"], 0.f);
            MiscCFG::FastStop = ReadData(config["Misc"]["FastStop"], false);
            MiscCFG::SpecList = ReadData(config["Misc"]["SpecList"], false);
            MiscCFG::EnemySensor = ReadData(config["Misc"]["Glow"], false);
            MiscCFG::GlowColor.Value.x = ReadData(config["Misc"]["GlowColor"]["r"], 0.f);
            MiscCFG::GlowColor.Value.y = ReadData(config["Misc"]["GlowColor"]["g"], 0.f);
            MiscCFG::GlowColor.Value.z = ReadData(config["Misc"]["GlowColor"]["b"], 0.f);
            MiscCFG::GlowColor.Value.w = ReadData(config["Misc"]["GlowColor"]["a"], 0.f);
            MiscCFG::GlowRainbow = ReadData(config["Misc"]["RainbowedGlow"], false);
            MiscCFG::RadarHack = ReadData(config["Misc"]["RadarHack"], false);
            MiscCFG::MoneyService = ReadData(config["Misc"]["MoneyService"]["Enable"], false);
            MiscCFG::ShowCashSpent = ReadData(config["Misc"]["MoneyService"]["ShowCashSpent"], false);
            MiscCFG::NoSmoke = ReadData(config["Misc"]["NoSmoke"], false);
            MiscCFG::NightMode = ReadData(config["Misc"]["NightMode"], false);
            MiscCFG::NightModeAlpha = ReadData(config["Misc"]["NightModeAlpha"], 0);
            MiscCFG::jumpthrow = ReadData(config["Misc"]["JumpThrow"], false);
            MenuConfig::TeamCheck = ReadData(config["Misc"]["TeamCheck"], true);
            MenuConfig::BypassOBS = ReadData(config["Misc"]["AntiRecord"], false);
            MiscCFG::Jitter = ReadData(config["Misc"]["Jitter"], false);
            MiscCFG::SmokeColored = ReadData(config["Misc"]["SmokeColor"]["Enable"], false);
            MiscCFG::SmokeColor.Value.x = ReadData(config["Misc"]["SmokeColor"]["r"], 255.f);
            MiscCFG::SmokeColor.Value.y = ReadData(config["Misc"]["SmokeColor"]["g"], 0.f);
            MiscCFG::SmokeColor.Value.z = ReadData(config["Misc"]["SmokeColor"]["b"], 0.f);
        }
        if (config["Aimbot"])
        {
            MenuConfig::AimBot = ReadData(config["Aimbot"]["Enable"], false);
            AimControl::Rage = ReadData(config["Aimbot"]["Ragebot"], false);
            AimControl::AimLock = ReadData(config["Aimbot"]["AimLock"], false);
            MenuConfig::AimToggleMode = ReadData(config["Aimbot"]["ToggleMode"], false);
            MenuConfig::AimBotHotKey = ReadData(config["Aimbot"]["Hotkey"], 0);
            AimControl::AimBullet = ReadData(config["Aimbot"]["AimBullet"], 0);
            AimControl::AimFov = ReadData(config["Aimbot"]["Fov"], 5.f);
            AimControl::AimFovMin = ReadData(config["Aimbot"]["FovMin"], .5f);
            ESPConfig::DrawFov = ReadData(config["Aimbot"]["FovCircle"], false);
            MenuConfig::FovCircleColor.Value.x = ReadData(config["Aimbot"]["CircleColor"]["r"], 0.f);
            MenuConfig::FovCircleColor.Value.y = ReadData(config["Aimbot"]["CircleColor"]["g"], 0.f);
            MenuConfig::FovCircleColor.Value.z = ReadData(config["Aimbot"]["CircleColor"]["b"], 0.f);
            MenuConfig::FovCircleColor.Value.w = ReadData(config["Aimbot"]["CircleColor"]["a"], 0.f);
            AimControl::Smooth = ReadData(config["Aimbot"]["Smooth"], 2.f);
            AimControl::HitboxList = LoadVector(config["Aimbot"]["Hitboxes"], { BONEINDEX::head });
            MenuConfig::SparyPosition = ReadData(config["Aimbot"]["SprayHitbox"], 0);
            MenuConfig::VisibleCheck = ReadData(config["Aimbot"]["VisibleCheck"], true);
            AimControl::IgnoreFlash = ReadData(config["Aimbot"]["IgnoreFlash"], false);
            AimControl::ScopeOnly = ReadData(config["Aimbot"]["ScopeOnly"], false);
            AimControl::AutoShot = ReadData(config["Aimbot"]["AutoShot"], false);
        }
        if (config["Recoil Control System"])
        {
            MenuConfig::RCS = ReadData(config["Recoil Control System"]["Enable"], false);
            RCS::RCSScale.x = ReadData(config["Recoil Control System"]["Yaw"], 1.f);
            RCS::RCSScale.y = ReadData(config["Recoil Control System"]["Pitch"], 1.f);
        }
        if (config["Triggerbot"])
        {
            MenuConfig::TriggerBot = ReadData(config["Triggerbot"]["Enable"], false);
            MenuConfig::TriggerHotKey = ReadData(config["Triggerbot"]["Hotkey"], 0);
            TriggerBot::TriggerDelay = ReadData(config["Triggerbot"]["Delay"], 20);
            TriggerBot::ShotDuration = ReadData(config["Triggerbot"]["FakeShot"], 200);
            TriggerBot::ScopeOnly = ReadData(config["Triggerbot"]["ScopeOnly"], false);
            TriggerBot::IgnoreFlash = ReadData(config["Triggerbot"]["IgnoreFlash"], false);
            MenuConfig::TriggerAlways = ReadData(config["Triggerbot"]["AutoMode"], false);
        }
        if (config["Menu"])
        {
            MenuConfig::MaxRenderFPS = ReadData(config["Menu"]["RenderFrameLimit"], MenuConfig::MaxFrameRate);
            MenuConfig::Theme = ReadData(config["Menu"]["Theme"], 0);
        }

        if (MenuConfig::Theme == 4)
        {
            // Custom Theme Loader
            if (config["Custom Theme"])
            {
                ImColor windowBgColor = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);
                ImColor borderColor = ImGui::GetStyleColorVec4(ImGuiCol_Border);
                ImColor childBgColor = ImGui::GetStyleColorVec4(ImGuiCol_ChildBg);
                ImColor ButtonColor = ImGui::GetStyleColorVec4(ImGuiCol_Button);
                ImColor ButtonHovered = ImGui::GetStyleColorVec4(ImGuiCol_ButtonHovered);
                ImColor ButtonActive = ImGui::GetStyleColorVec4(ImGuiCol_ButtonActive);
                ImColor FrameBgColor = ImGui::GetStyleColorVec4(ImGuiCol_FrameBg);
                ImColor FrameHovered = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgHovered);
                ImColor FrameActive = ImGui::GetStyleColorVec4(ImGuiCol_FrameBgActive);
                ImColor Header = ImGui::GetStyleColorVec4(ImGuiCol_Header);
                ImColor HeaderActive = ImGui::GetStyleColorVec4(ImGuiCol_HeaderActive);
                ImColor HeaderHovered = ImGui::GetStyleColorVec4(ImGuiCol_HeaderHovered);
                ImColor ScrollBg = ImGui::GetStyleColorVec4(ImGuiCol_ScrollbarBg);

                ImColor FeatureName = ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled);
                ImColor Text = ImGui::GetStyleColorVec4(ImGuiCol_Text);
                ImColor Separator = ImGui::GetStyleColorVec4(ImGuiCol_Separator);

                MenuConfig::ButtonBorderColor = UInt32ToImColor(config["Custom Theme"]["Button Border"].as<uint32_t>());
                FeatureName = UInt32ToImColor(config["Custom Theme"]["Feature Name"].as<uint32_t>());
                Text = UInt32ToImColor(config["Custom Theme"]["Text"].as<uint32_t>());
                Separator = UInt32ToImColor(config["Custom Theme"]["Separator"].as<uint32_t>());
                windowBgColor = UInt32ToImColor(config["Custom Theme"]["Window Bg"].as<uint32_t>());
                borderColor = UInt32ToImColor(config["Custom Theme"]["Border"].as<uint32_t>());
                childBgColor = UInt32ToImColor(config["Custom Theme"]["Child Window Bg"].as<uint32_t>());
                ButtonColor = UInt32ToImColor(config["Custom Theme"]["Button"].as<uint32_t>());
                ButtonHovered = UInt32ToImColor(config["Custom Theme"]["Button Hovered"].as<uint32_t>());
                ButtonActive = UInt32ToImColor(config["Custom Theme"]["Button Active"].as<uint32_t>());
                FrameBgColor = UInt32ToImColor(config["Custom Theme"]["Frame Bg"].as<uint32_t>());
                FrameHovered = UInt32ToImColor(config["Custom Theme"]["Frame Bg Hovered"].as<uint32_t>());
                FrameActive = UInt32ToImColor(config["Custom Theme"]["Frame Bg Active"].as<uint32_t>());
                Header = UInt32ToImColor(config["Custom Theme"]["Header"].as<uint32_t>());
                HeaderActive = UInt32ToImColor(config["Custom Theme"]["Header Active"].as<uint32_t>());
                HeaderHovered = UInt32ToImColor(config["Custom Theme"]["Header Hovered"].as<uint32_t>());
                ScrollBg = UInt32ToImColor(config["Custom Theme"]["Scrollbar Bg"].as<uint32_t>());

                // Update Color
                ImGui::GetStyle().Colors[ImGuiCol_Border] = borderColor;
                ImGui::GetStyle().Colors[ImGuiCol_Button] = ButtonColor;
                ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ButtonActive;
                ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = ButtonHovered;
                ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = FrameBgColor;
                ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = FrameHovered;
                ImGui::GetStyle().Colors[ImGuiCol_FrameBgActive] = FrameActive;
                ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = windowBgColor;
                ImGui::GetStyle().Colors[ImGuiCol_ChildBg] = childBgColor;
                ImGui::GetStyle().Colors[ImGuiCol_Header] = Header;
                ImGui::GetStyle().Colors[ImGuiCol_HeaderActive] = HeaderActive;
                ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered] = HeaderHovered;
                ImGui::GetStyle().Colors[ImGuiCol_ScrollbarBg] = ScrollBg;

                ImGui::GetStyle().Colors[ImGuiCol_TextDisabled] = FeatureName;
                ImGui::GetStyle().Colors[ImGuiCol_Text] = Text;
                ImGui::GetStyle().Colors[ImGuiCol_Separator] = Separator;
            }
        }
        else {
            StyleChanger::UpdateSkin(MenuConfig::Theme);
        }

        AimControl::SetHotKey(MenuConfig::AimBotHotKey);
        TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
        MenuConfig::HitboxUpdated = false;

        std::cout << "[Info] Configuration loaded from " << MenuConfig::path + '\\' + filename << std::endl;
    }
} // namespace ConfigSaver
