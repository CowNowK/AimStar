#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ConfigSaver.hpp"
#include "../Features/StyleChanger.h"
#include "../Resources/Language.h"
#include "../MenuConfig.hpp"
#include "../TriggerBot.h"
#include "../AimBot.hpp"

namespace MyConfigSaver {

    void SaveConfig(const std::string& filename, const std::string& author) {
        std::ofstream configFile(MenuConfig::path + '\\' + filename);
        if (!configFile.is_open()) {
            std::cerr << "[Info] Error: Could not open the configuration file." << std::endl;
            return;
        }

        YAML::Emitter emitter;

        emitter << YAML::Comment("AimStar Config File\nVersion: 3.8\nAuthor: " + author);
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
        emitter << YAML::Key << "NoFlash" << YAML::Value << MiscCFG::NoFlash;
        emitter << YAML::Key << "Watermark" << YAML::Value << MiscCFG::WaterMark;
        emitter << YAML::Key << "CheatList" << YAML::Value << MiscCFG::CheatList;
        emitter << YAML::Key << "HitSound" << YAML::Value << MiscCFG::HitSound;
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
        emitter << YAML::Key << "SpecList" << YAML::Value << MiscCFG::BunnyHop;
        emitter << YAML::Key << "Glow" << YAML::Value << MiscCFG::EnemySensor;
        emitter << YAML::Key << "RadarHack" << YAML::Value << MiscCFG::RadarHack;
        emitter << YAML::Key << "MoneyService";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << MiscCFG::MoneyService;
        emitter << YAML::Key << "ShowCashSpent" << YAML::Value << MiscCFG::ShowCashSpent;
        emitter << YAML::EndMap;
        emitter << YAML::Key << "NoSmoke" << YAML::Value << MiscCFG::NoSmoke;
        emitter << YAML::Key << "TeamCheck" << YAML::Value << MenuConfig::TeamCheck;
        emitter << YAML::Key << "AntiRecord" << YAML::Value << MenuConfig::BypassOBS;
        emitter << YAML::Key << "Jitter" << YAML::Value << MiscCFG::Jitter;
        emitter << YAML::Key << "SmokeColor" << YAML::Value << MiscCFG::SmokeColored;
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
        emitter << YAML::Key << "AutoLock" << YAML::Value << MenuConfig::AimAlways;
        emitter << YAML::Key << "ToggleMode" << YAML::Value << MenuConfig::AimToggleMode;
        emitter << YAML::Key << "Hotkey" << YAML::Value << MenuConfig::AimBotHotKey;
        emitter << YAML::Key << "Fov" << YAML::Value << AimControl::AimFov;
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
        emitter << YAML::Key << "AimPos" << YAML::Value << MenuConfig::AimPosition;
        emitter << YAML::Key << "VisibleCheck" << YAML::Value << MenuConfig::VisibleCheck;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Triggerbot";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Enable" << YAML::Value << MenuConfig::TriggerBot;
        emitter << YAML::Key << "Hotkey" << YAML::Value << MenuConfig::TriggerHotKey;
        emitter << YAML::Key << "Delay" << YAML::Value << TriggerBot::TriggerDelay;
        emitter << YAML::Key << "FakeShot" << YAML::Value << TriggerBot::FakeShotDelay;
        emitter << YAML::Key << "AutoMode" << YAML::Value << MenuConfig::TriggerAlways;
        emitter << YAML::EndMap;

        emitter << YAML::Key << "Menu";
        emitter << YAML::Value;
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "Theme" << YAML::Value << MenuConfig::Theme;
        emitter << YAML::Key << "Language" << YAML::Value << MenuConfig::Language;
        emitter << YAML::EndMap;

        emitter << YAML::EndMap;

        configFile << emitter.c_str();
        configFile.close();
        std::cout << "[Info] Configuration saved to " << MenuConfig::path + '\\' + filename << std::endl;
    }

    // Function to load the configuration from a file
    void LoadConfig(const std::string& filename) {
        YAML::Node config = YAML::LoadFile(MenuConfig::path + '\\' + filename);
        if (config["ESP"]) {
            // If you want to make the new version compatible with the old configuration, you can add IsDefine(), like line 284.
            ESPConfig::ESPenabled = config["ESP"]["Enable"].as<bool>();
            ESPConfig::ShowBoneESP = config["ESP"]["BoneESP"].as<bool>();
            ESPConfig::ShowBoxESP = config["ESP"]["BoxESP"].as<bool>();
            MenuConfig::BoxType = config["ESP"]["BoxType"].as<int>();
            ESPConfig::ShowLineToEnemy = config["ESP"]["SnapLine"].as<bool>();
            ESPConfig::LinePos = config["ESP"]["LinePos"].as<int>();
            ESPConfig::ShowHealthBar = config["ESP"]["HealthBar"].as<bool>();
            ESPConfig::AmmoBar = config["ESP"]["AmmoBar"].IsDefined() ? config["ESP"]["AmmoBar"].as<bool>() : false;
            ESPConfig::ShowWeaponESP = config["ESP"]["WeaponESP"].as<bool>();
            ESPConfig::ShowEyeRay = config["ESP"]["EyeRay"].as<bool>();
            ESPConfig::ShowPlayerName = config["ESP"]["PlayerName"].as<bool>();
            ESPConfig::ShowDistance = config["ESP"]["DistanceESP"].as<bool>();
            ESPConfig::ShowHealthNum = config["ESP"]["HealthNum"].as<bool>();
            ESPConfig::ShowHeadBox = config["ESP"]["HeadBox"].as<bool>();
            ESPConfig::ShowPreview = config["ESP"]["Preview"].as<bool>();
            ESPConfig::VisibleCheck = config["ESP"]["VisCheck"].as<bool>();
            ESPConfig::FilledBox = config["ESP"]["FilledBox"].as<bool>();
            ESPConfig::FilledVisBox = config["ESP"]["FilledVisBox"].as<bool>();
            ESPConfig::MultiColor = config["ESP"]["MultiColor"].as<bool>();
            ESPConfig::OutLine = config["ESP"]["OutLine"].as<bool>();
            ESPConfig::BoxRounding = config["ESP"]["BoxRounding"].as<float>();
            ESPConfig::BoneColor.Value.x = config["ESP"]["BoneColor"]["r"].as<float>();
            ESPConfig::BoneColor.Value.y = config["ESP"]["BoneColor"]["g"].as<float>();
            ESPConfig::BoneColor.Value.z = config["ESP"]["BoneColor"]["b"].as<float>();
            ESPConfig::BoneColor.Value.w = config["ESP"]["BoneColor"]["a"].as<float>();
            ESPConfig::BoxColor.Value.x = config["ESP"]["BoxColor"]["r"].as<float>();
            ESPConfig::BoxColor.Value.y = config["ESP"]["BoxColor"]["g"].as<float>();
            ESPConfig::BoxColor.Value.z = config["ESP"]["BoxColor"]["b"].as<float>();
            ESPConfig::BoxColor.Value.w = config["ESP"]["BoxColor"]["a"].as<float>();
            ESPConfig::LineToEnemyColor.Value.x = config["ESP"]["SnapLineColor"]["r"].as<float>();
            ESPConfig::LineToEnemyColor.Value.y = config["ESP"]["SnapLineColor"]["g"].as<float>();
            ESPConfig::LineToEnemyColor.Value.z = config["ESP"]["SnapLineColor"]["b"].as<float>();
            ESPConfig::LineToEnemyColor.Value.w = config["ESP"]["SnapLineColor"]["a"].as<float>();
            ESPConfig::HeadBoxColor.Value.x = config["ESP"]["HeadBoxColor"]["r"].as<float>();
            ESPConfig::HeadBoxColor.Value.y = config["ESP"]["HeadBoxColor"]["g"].as<float>();
            ESPConfig::HeadBoxColor.Value.z = config["ESP"]["HeadBoxColor"]["b"].as<float>();
            ESPConfig::HeadBoxColor.Value.w = config["ESP"]["HeadBoxColor"]["a"].as<float>();
            ESPConfig::EyeRayColor.Value.x = config["ESP"]["EyeRayColor"]["r"].as<float>();
            ESPConfig::EyeRayColor.Value.y = config["ESP"]["EyeRayColor"]["g"].as<float>();
            ESPConfig::EyeRayColor.Value.z = config["ESP"]["EyeRayColor"]["b"].as<float>();
            ESPConfig::EyeRayColor.Value.w = config["ESP"]["EyeRayColor"]["a"].as<float>();
            ESPConfig::VisibleColor.Value.x = config["ESP"]["VisibleColor"]["r"].as<float>();
            ESPConfig::VisibleColor.Value.y = config["ESP"]["VisibleColor"]["g"].as<float>();
            ESPConfig::VisibleColor.Value.z = config["ESP"]["VisibleColor"]["b"].as<float>();
            ESPConfig::VisibleColor.Value.w = config["ESP"]["VisibleColor"]["a"].as<float>();
            ESPConfig::FilledColor.Value.x = config["ESP"]["FilledColor"]["r"].as<float>();
            ESPConfig::FilledColor.Value.y = config["ESP"]["FilledColor"]["g"].as<float>();
            ESPConfig::FilledColor.Value.z = config["ESP"]["FilledColor"]["b"].as<float>();
            ESPConfig::FilledColor.Value.w = config["ESP"]["FilledColor"]["a"].as<float>();
            ESPConfig::FilledColor2.Value.x = config["ESP"]["FilledColor2"]["r"].as<float>();
            ESPConfig::FilledColor2.Value.y = config["ESP"]["FilledColor2"]["g"].as<float>();
            ESPConfig::FilledColor2.Value.z = config["ESP"]["FilledColor2"]["b"].as<float>();
            ESPConfig::FilledColor2.Value.w = config["ESP"]["FilledColor2"]["a"].as<float>();
            ESPConfig::BoxFilledVisColor.Value.x = config["ESP"]["FilledVisColor"]["r"].as<float>();
            ESPConfig::BoxFilledVisColor.Value.y = config["ESP"]["FilledVisColor"]["g"].as<float>();
            ESPConfig::BoxFilledVisColor.Value.z = config["ESP"]["FilledVisColor"]["b"].as<float>();
            ESPConfig::BoxFilledVisColor.Value.w = config["ESP"]["FilledVisColor"]["a"].as<float>();
            ESPConfig::PenisColor.Value.x = config["ESP"]["PenisColor"]["r"].as<float>();
            ESPConfig::PenisColor.Value.y = config["ESP"]["PenisColor"]["g"].as<float>();
            ESPConfig::PenisColor.Value.z = config["ESP"]["PenisColor"]["b"].as<float>();
            ESPConfig::PenisColor.Value.w = config["ESP"]["PenisColor"]["a"].as<float>();
            ESPConfig::ShowPenis = config["ESP"]["PenisESP"].as<bool>();
            ESPConfig::PenisLength = config["ESP"]["PenisLength"].as<float>();
            ESPConfig::PenisSize = config["ESP"]["PenisSize"].as<float>();
        }
        if (config["Crosshairs"]) {
            CrosshairsCFG::ShowCrossHair = config["Crosshairs"]["Enable"].as<bool>();
            CrosshairsCFG::CrossHairSize = config["Crosshairs"]["Size"].as<float>();
            CrosshairsCFG::drawDot = config["Crosshairs"]["Dot"].as<bool>();
            CrosshairsCFG::drawCrossline = config["Crosshairs"]["Crossline"].as<bool>();
            CrosshairsCFG::tStyle = config["Crosshairs"]["tStyle"].as<bool>();
            CrosshairsCFG::drawCircle = config["Crosshairs"]["Circle"].as<bool>();
            CrosshairsCFG::drawOutLine = config["Crosshairs"]["Outline"].as<bool>();
            CrosshairsCFG::DynamicGap = config["Crosshairs"]["DynamicGap"].as<bool>();
            CrosshairsCFG::TeamCheck = config["Crosshairs"]["TeamCheck"].as<bool>();
            CrosshairsCFG::crosshairPreset = config["Crosshairs"]["Preset"].as<int>();
            CrosshairsCFG::Gap = config["Crosshairs"]["Gap"].as<int>();
            CrosshairsCFG::HorizontalLength = config["Crosshairs"]["H_Length"].as<int>();
            CrosshairsCFG::VerticalLength = config["Crosshairs"]["V_Length"].as<int>();
            CrosshairsCFG::Thickness = config["Crosshairs"]["Thickness"].as<int>();
            CrosshairsCFG::DotSize = config["Crosshairs"]["DotSize"].as<float>();
            CrosshairsCFG::CircleRadius = config["Crosshairs"]["CircleRadius"].as<float>();
            CrosshairsCFG::CrossHairColor.Value.x = config["Crosshairs"]["CrosshairsColor"]["r"].as<float>();
            CrosshairsCFG::CrossHairColor.Value.y = config["Crosshairs"]["CrosshairsColor"]["g"].as<float>();
            CrosshairsCFG::CrossHairColor.Value.z = config["Crosshairs"]["CrosshairsColor"]["b"].as<float>();
            CrosshairsCFG::CrossHairColor.Value.w = config["Crosshairs"]["CrosshairsColor"]["a"].as<float>();
            CrosshairsCFG::TargetedColor.Value.x = config["Crosshairs"]["TargetedColor"]["r"].as<float>();
            CrosshairsCFG::TargetedColor.Value.y = config["Crosshairs"]["TargetedColor"]["g"].as<float>();
            CrosshairsCFG::TargetedColor.Value.z = config["Crosshairs"]["TargetedColor"]["b"].as<float>();
            CrosshairsCFG::TargetedColor.Value.w = config["Crosshairs"]["TargetedColor"]["a"].as<float>();
        }
        if (config["Radar"])
        {
            RadarCFG::ShowRadar = config["Radar"]["Enable"].as<bool>();
            RadarCFG::RadarType = config["Radar"]["Type"].as<int>();
            RadarCFG::RadarRange = config["Radar"]["Range"].as<float>();
            RadarCFG::Proportion = config["Radar"]["Proportion"].as<float>();
            RadarCFG::RadarPointSizeProportion = config["Radar"]["PointProportion"].as<float>();
            RadarCFG::RadarBgAlpha = config["Radar"]["Alpha"].as<float>();
            RadarCFG::customRadar = config["Radar"]["Custom"].as<bool>();
            RadarCFG::ShowRadarCrossLine = config["Radar"]["Crossline"].as<bool>();
            RadarCFG::RadarCrossLineColor.Value.x = config["Radar"]["CrosslineColor"]["r"].as<float>();
            RadarCFG::RadarCrossLineColor.Value.y = config["Radar"]["CrosslineColor"]["g"].as<float>();
            RadarCFG::RadarCrossLineColor.Value.z = config["Radar"]["CrosslineColor"]["b"].as<float>();
            RadarCFG::RadarCrossLineColor.Value.w = config["Radar"]["CrosslineColor"]["a"].as<float>();
        }
        if (config["Misc"])
        {
            MiscCFG::BunnyHop = config["Misc"]["Bhop"].as<bool>();
            MenuConfig::ShowHeadShootLine = config["Misc"]["HeadShootLine"].as<bool>();
            MenuConfig::HeadShootLineColor.Value.x = config["Misc"]["HeadShootLineColor"]["r"].as<float>();
            MenuConfig::HeadShootLineColor.Value.y = config["Misc"]["HeadShootLineColor"]["g"].as<float>();
            MenuConfig::HeadShootLineColor.Value.z = config["Misc"]["HeadShootLineColor"]["b"].as<float>();
            MenuConfig::HeadShootLineColor.Value.w = config["Misc"]["HeadShootLineColor"]["a"].as<float>();
            MiscCFG::WorkInSpec = config["Misc"]["WorkInSpec"].as<bool>();
            MiscCFG::Fov = config["Misc"]["Fov"].IsDefined() ? config["Misc"]["Fov"].as<bool>() : 0;
            MiscCFG::NoFlash = config["Misc"]["NoFlash"].as<bool>();
            MiscCFG::WaterMark = config["Misc"]["Watermark"].as<bool>();
            MiscCFG::CheatList = config["Misc"]["CheatList"].as<bool>();
            MiscCFG::HitSound = config["Misc"]["HitSound"].as<bool>();
            MiscCFG::bmbTimer = config["Misc"]["BombTimer"].as<bool>();
            MiscCFG::BombTimerCol.Value.x = config["Misc"]["TimerColor"]["r"].as<float>();
            MiscCFG::BombTimerCol.Value.y = config["Misc"]["TimerColor"]["g"].as<float>();
            MiscCFG::BombTimerCol.Value.z = config["Misc"]["TimerColor"]["b"].as<float>();
            MiscCFG::BombTimerCol.Value.w = config["Misc"]["TimerColor"]["a"].as<float>();
            MiscCFG::FastStop = config["Misc"]["FastStop"].as<bool>();
            MiscCFG::SpecList = config["Misc"]["SpecList"].as<bool>();
            MiscCFG::EnemySensor = config["Misc"]["Glow"].as<bool>();
            MiscCFG::RadarHack = config["Misc"]["RadarHack"].IsDefined() ? config["Misc"]["RadarHack"].as<bool>() : false;
            MiscCFG::MoneyService = config["Misc"]["MoneyService"]["Enable"].IsDefined() ? config["Misc"]["MoneyService"]["Enable"].as<bool>() : false;
            MiscCFG::ShowCashSpent = config["Misc"]["MoneyService"]["ShowCashSpent"].IsDefined() ? config["Misc"]["MoneyService"]["ShowCashSpent"].as<bool>() : false;
            MiscCFG::NoSmoke = config["Misc"]["NoSmoke"].IsDefined() ? config["Misc"]["NoSmoke"].as<bool>() : false;
            MenuConfig::TeamCheck = config["Misc"]["TeamCheck"].as<bool>();
            MenuConfig::BypassOBS = config["Misc"]["AntiRecord"].as<bool>();
            MiscCFG::Jitter = config["Misc"]["Jitter"].IsDefined() ? config["Misc"]["Jitter"].as<bool>() : false;
            MiscCFG::SmokeColored = config["Misc"]["SmokeColor"]["Enable"].IsDefined() ? config["Misc"]["SmokeColor"]["Enable"].as<bool>() : false;
            MiscCFG::SmokeColor.Value.x = config["Misc"]["SmokeColor"]["r"].IsDefined() ? config["Misc"]["SmokeColor"]["r"].as<float>() : 255.f;
            MiscCFG::SmokeColor.Value.y = config["Misc"]["SmokeColor"]["g"].IsDefined() ? config["Misc"]["SmokeColor"]["g"].as<float>() : 0.f;
            MiscCFG::SmokeColor.Value.z = config["Misc"]["SmokeColor"]["b"].IsDefined() ? config["Misc"]["SmokeColor"]["b"].as<float>() : 0.f;
        }
        if (config["Aimbot"])
        {
            MenuConfig::AimBot = config["Aimbot"]["Enable"].as<bool>();
            MenuConfig::AimAlways = config["Aimbot"]["AutoLock"].as<bool>();
            MenuConfig::AimToggleMode = config["Aimbot"]["ToggleMode"].as<bool>();
            MenuConfig::AimBotHotKey = config["Aimbot"]["Hotkey"].as<int>();
            AimControl::AimFov = config["Aimbot"]["Fov"].as<float>();
            ESPConfig::DrawFov = config["Aimbot"]["FovCircle"].as<bool>();
            MenuConfig::FovCircleColor.Value.x = config["Aimbot"]["CircleColor"]["r"].as<float>();
            MenuConfig::FovCircleColor.Value.y = config["Aimbot"]["CircleColor"]["g"].as<float>();
            MenuConfig::FovCircleColor.Value.z = config["Aimbot"]["CircleColor"]["b"].as<float>();
            MenuConfig::FovCircleColor.Value.w = config["Aimbot"]["CircleColor"]["a"].as<float>();
            AimControl::Smooth = config["Aimbot"]["Smooth"].as<float>();
            MenuConfig::AimPosition = config["Aimbot"]["AimPos"].as<int>();
            MenuConfig::VisibleCheck = config["Aimbot"]["VisibleCheck"].as<bool>();
        }
        if (config["Triggerbot"])
        {
            MenuConfig::TriggerBot = config["Triggerbot"]["Enable"].as<bool>();
            MenuConfig::TriggerHotKey = config["Triggerbot"]["Hotkey"].as<int>();
            TriggerBot::TriggerDelay = config["Triggerbot"]["Delay"].as<float>();
            TriggerBot::FakeShotDelay = config["Triggerbot"]["FakeShot"].as<float>();
            MenuConfig::TriggerAlways = config["Triggerbot"]["AutoMode"].as<bool>();
        }
        if (config["Menu"])
        {
            MenuConfig::Theme = config["Menu"]["Theme"].as<int>();
            MenuConfig::Language = config["Menu"]["Language"].IsDefined() ? config["Menu"]["Language"].as<int>() : 0;
        }

        AimControl::SetHotKey(MenuConfig::AimBotHotKey);
        StyleChanger::UpdateSkin(MenuConfig::Theme);
        Lang::ChangeLang(MenuConfig::Language);

        std::cout << "[Info] Configuration loaded from " << MenuConfig::path + '\\' + filename << std::endl;
    }
} // namespace ConfigSaver
