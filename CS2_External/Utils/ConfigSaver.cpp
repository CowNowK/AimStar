#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ConfigSaver.hpp"
#include "../MenuConfig.hpp" // Include your global settings header
#include "../TriggerBot.h"
#include "../AimBot.hpp"
#include "../Features/RCS.h"

namespace MyConfigSaver {

    // Function to save the configuration to a file
    void SaveConfig(const std::string& filename) {
        std::ofstream configFile(MenuConfig::path + '\\' + filename);
        if (!configFile.is_open()) {
            std::cerr << "[Info] Error: Could not open the configuration file." << std::endl;
            return;
        }

        // Example: Save global settings to the file
        configFile << "FilledBox " << ESPConfig::FilledBox << std::endl;
        configFile << "BoxFilledColor2 " << ESPConfig::FilledColor2.Value.x << " " << ESPConfig::FilledColor2.Value.y << " " << ESPConfig::FilledColor2.Value.z << " " << ESPConfig::FilledColor2.Value.w << std::endl;
        configFile << "BoxFilledColor " << ESPConfig::FilledColor.Value.x << " " << ESPConfig::FilledColor.Value.y << " " << ESPConfig::FilledColor.Value.z << " " << ESPConfig::FilledColor.Value.w << std::endl;
        configFile << "MultiColor " << ESPConfig::MultiColor << std::endl;
        configFile << "BoxFilledVisColor " << ESPConfig::BoxFilledVisColor.Value.x << " " << ESPConfig::BoxFilledVisColor.Value.y << " " << ESPConfig::BoxFilledVisColor.Value.z << " " << ESPConfig::BoxFilledVisColor.Value.w << std::endl;
        configFile << "BoxFilledVisCheck " << ESPConfig::FilledVisBox << std::endl;
        configFile << "SpecList " << MenuConfig::SpecList << std::endl;
        configFile << "BombTimerCol " << MenuConfig::BombTimerCol.Value.x << " " << MenuConfig::BombTimerCol.Value.y << " " << MenuConfig::BombTimerCol.Value.z << " " << MenuConfig::BombTimerCol.Value.w << std::endl;
        configFile << "bmbTimer " << MenuConfig::bmbTimer << std::endl;
        configFile << "ESPVisCol " << ESPConfig::VisibleColor.Value.x << " " << ESPConfig::VisibleColor.Value.y << " " << ESPConfig::VisibleColor.Value.z << " " << ESPConfig::VisibleColor.Value.w << std::endl;;
        configFile << "ESPVisCheck " << ESPConfig::VisibleCheck << std::endl;
        configFile << "GlowColor " << MenuConfig::GlowColor.Value.x << " " << MenuConfig::GlowColor.Value.y << " " << MenuConfig::GlowColor.Value.z << " " << MenuConfig::GlowColor.Value.w << std::endl;
        configFile << "Glow " << MenuConfig::Glow << std::endl;
        configFile << "AirJump " << MenuConfig::AirJump << std::endl;
        configFile << "MenuStyle " << MenuConfig::MenuStyle << std::endl;
        configFile << "WindowStyle " << MenuConfig::WindowStyle << std::endl;
        configFile << "BoxAlpha " << ESPConfig::BoxAlpha << std::endl;
        configFile << "EspPreview " << ESPConfig::ShowPreview << std::endl;
        configFile << "ShowHeadBox " << ESPConfig::ShowHeadBox << std::endl;
        configFile << "HeadBoxStyle " << ESPConfig::HeadBoxStyle << std::endl;
        configFile << "HeadboxColor " << ESPConfig::HeadBoxColor << std::endl;
        configFile << "ShowDistance " << ESPConfig::ShowDistance << std::endl;
        configFile << "ShowBoneESP " << ESPConfig::ShowBoneESP << std::endl;
        configFile << "TriggerDelay " << TriggerBot::TriggerDelay << std::endl;
        configFile << "FakeShot " << TriggerBot::FakeShotDelay << std::endl;
        configFile << "ShowBoxESP " << ESPConfig::ShowBoxESP << std::endl;
        configFile << "BoxRounding " << ESPConfig::BoxRounding << std::endl;
        configFile << "TriggerHotKey " << MenuConfig::TriggerHotKey << std::endl;
        configFile << "RCSBullet " << RCS::RCSBullet << std::endl;
        configFile << "ShowHealthBar " << ESPConfig::ShowHealthBar << std::endl;
        configFile << "AimFov " << AimControl::AimFov << std::endl;
        configFile << "FovLineSize " << MenuConfig::FovLineSize << std::endl;
        configFile << "AimBotHotKey " << MenuConfig::AimBotHotKey << std::endl;
        configFile << "ShowLineToEnemy " << MenuConfig::ShowLineToEnemy << std::endl;
        configFile << "RCSScale.x " << AimControl::RCSScale.x << std::endl;
        configFile << "RCSScale.y " << AimControl::RCSScale.y << std::endl;
        configFile << "ShowWeaponESP " << ESPConfig::ShowWeaponESP << std::endl;
        configFile << "Smooth " << AimControl::Smooth << std::endl;
        configFile << "ShowFovLine " << MenuConfig::ShowFovLine << std::endl;
        configFile << "ShowEyeRay " << ESPConfig::ShowEyeRay << std::endl;
        configFile << "ShowPlayerName " << ESPConfig::ShowPlayerName << std::endl;
        configFile << "AimBot " << MenuConfig::AimBot << std::endl;
        configFile << "AimAlways " << MenuConfig::AimAlways << std::endl;
        configFile << "AimToggle " << MenuConfig::AimToggleMode << std::endl;
        configFile << "AimPosition " << MenuConfig::AimPosition << std::endl;
        configFile << "AimPositionIndex " << MenuConfig::AimPositionIndex << std::endl;
        configFile << "HealthBarType " << MenuConfig::HealthBarType << std::endl;
        configFile << "BoneColor " << ESPConfig::BoneColor.Value.x << " " << ESPConfig::BoneColor.Value.y << " " << ESPConfig::BoneColor.Value.z << " " << ESPConfig::BoneColor.Value.w << std::endl;
        configFile << "FovLineColor " << MenuConfig::FovLineColor.Value.x << " " << MenuConfig::FovLineColor.Value.y << " " << MenuConfig::FovLineColor.Value.z << " " << MenuConfig::FovLineColor.Value.w << std::endl;
        configFile << "LineToEnemyColor " << MenuConfig::LineToEnemyColor.Value.x << " " << MenuConfig::LineToEnemyColor.Value.y << " " << MenuConfig::LineToEnemyColor.Value.z << " " << MenuConfig::LineToEnemyColor.Value.w << std::endl;
        configFile << "BoxColor " << ESPConfig::BoxColor.Value.x << " " << ESPConfig::BoxColor.Value.y << " " << ESPConfig::BoxColor.Value.z << " " << ESPConfig::BoxColor.Value.w << std::endl;
        configFile << "EyeRayColor " << ESPConfig::EyeRayColor.Value.x << " " << ESPConfig::EyeRayColor.Value.y << " " << ESPConfig::EyeRayColor.Value.z << " " << ESPConfig::EyeRayColor.Value.w << std::endl;
        configFile << "RadarCrossLineColor " << MenuConfig::RadarCrossLineColor.Value.x << " " << MenuConfig::RadarCrossLineColor.Value.y << " " << MenuConfig::RadarCrossLineColor.Value.z << " " << MenuConfig::RadarCrossLineColor.Value.w << std::endl;
        configFile << "HeadShootLineColor " << MenuConfig::HeadShootLineColor.Value.x << " " << MenuConfig::HeadShootLineColor.Value.y << " " << MenuConfig::HeadShootLineColor.Value.z << " " << MenuConfig::HeadShootLineColor.Value.w << std::endl;
        configFile << "ShowMenu " << MenuConfig::ShowMenu << std::endl;
        configFile << "ShowRadar " << MenuConfig::ShowRadar << std::endl;
        configFile << "RadarRange " << MenuConfig::RadarRange << std::endl;
        configFile << "RadarPointSizeProportion " << MenuConfig::RadarPointSizeProportion << std::endl;
        configFile << "RadarBgAlpha " << MenuConfig::RadarBgAlpha << std::endl;
        configFile << "ShowCrossLine " << MenuConfig::ShowRadarCrossLine << std::endl;
        configFile << "RadarType " << MenuConfig::RadarType << std::endl;
        configFile << "Proportion " << MenuConfig::Proportion << std::endl;
        configFile << "BoxType " << MenuConfig::BoxType << std::endl;
        configFile << "TriggerBot " << MenuConfig::TriggerBot << std::endl;
        configFile << "TriggerAlways " << MenuConfig::TriggerAlways << std::endl;
        configFile << "TeamCheck " << MenuConfig::TeamCheck << std::endl;
        configFile << "BypassOBS " << MenuConfig::BypassOBS << std::endl;
        configFile << "VisibleCheck " << MenuConfig::VisibleCheck << std::endl;
        configFile << "ShowHeadShootLine " << MenuConfig::ShowHeadShootLine << std::endl;
        configFile << "ShowCrossHair " << CrosshairConfig::ShowCrossHair << std::endl;
        configFile << "CrossHairColor " << CrosshairConfig::CrossHairColor.Value.x << " " << CrosshairConfig::CrossHairColor.Value.y << " " << CrosshairConfig::CrossHairColor.Value.z << " " << CrosshairConfig::CrossHairColor.Value.w << std::endl;
        configFile << "CrossHairSize " << CrosshairConfig::CrossHairSize << std::endl;
        configFile << "drawDot " << CrosshairConfig::drawDot << std::endl;
        configFile << "tStyle " << CrosshairConfig::tStyle << std::endl;
        configFile << "HorizontalLength " << CrosshairConfig::HorizontalLength << std::endl;
        configFile << "VerticalLength " << CrosshairConfig::VerticalLength << std::endl;
        configFile << "drawOutLine " << CrosshairConfig::drawOutLine << std::endl;
        configFile << "drawCrossline " << CrosshairConfig::drawCrossline << std::endl;
        configFile << "drawCircle " << CrosshairConfig::drawCircle << std::endl;
        configFile << "showTargeting " << CrosshairConfig::showTargeting << std::endl;
        configFile << "CircleRadius " << CrosshairConfig::CircleRadius << std::endl;
        configFile << "TargetedColor " << CrosshairConfig::TargetedColor.Value.x << " " << CrosshairConfig::TargetedColor.Value.y << " " << CrosshairConfig::TargetedColor.Value.z << " " << CrosshairConfig::TargetedColor.Value.w << std::endl;
        configFile << "Gap " << CrosshairConfig::Gap << std::endl;
        configFile << "DynamicGap " << CrosshairConfig::DynamicGap << std::endl;
        configFile << "DotSize " << CrosshairConfig::DotSize << std::endl;
        configFile << "CrosshairsThickness " << CrosshairConfig::Thickness << std::endl;
        configFile << "CrosshairsTeamCheck " << CrosshairConfig::TeamCheck << std::endl;

        configFile << "BunnyHop " << MenuConfig::BunnyHop << std::endl;
        configFile << "WorkInSpec " << MenuConfig::WorkInSpec << std::endl;
        configFile << "NoFlash" << MenuConfig::NoFlash << std::endl;
        configFile << "WaterMark " << MenuConfig::WaterMark << std::endl;
        configFile << "CheatList " << MenuConfig::CheatList << std::endl;
        configFile << "HitSound " << MenuConfig::HitSound << std::endl;

        configFile << "ESPenabled " << ESPConfig::ESPenbled << std::endl;
        configFile << "DrawFov " << ESPConfig::DrawFov << std::endl;
        configFile << "FovColor " << MenuConfig::FovCircleColor.Value.x << " " << MenuConfig::FovCircleColor.Value.y << " " << MenuConfig::FovCircleColor.Value.z << " " << MenuConfig::FovCircleColor.Value.w << std::endl;
        configFile << "ShowPenis " << ESPConfig::ShowPenis << std::endl;
        configFile << "PenisColor " << ESPConfig::PenisColor.Value.x << " " << ESPConfig::PenisColor.Value.y << " " << ESPConfig::PenisColor.Value.z << " " << ESPConfig::PenisColor.Value.w << std::endl;
        configFile << "PenisSize " << ESPConfig::PenisSize << std::endl;
        configFile << "PenisLength " << ESPConfig::PenisLength << std::endl;
        configFile << "SnaplinePos " << MenuConfig::LinePos << std::endl;
        configFile << "CustomRadar " << MenuConfig::customRadar << std::endl;
        configFile << "MenuStyle " << MenuConfig::MenuStyle << std::endl;


        configFile.close();
        std::cout << "[Info] Configuration saved to " << MenuConfig::path + '\\' + filename << std::endl;
    }

    // Function to load the configuration from a file
    void LoadConfig(const std::string& filename) {
        std::ifstream configFile(MenuConfig::path + '\\' + filename);
        if (!configFile.is_open()) {
            std::cerr << "[Info] Error: Could not open the configuration file." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(configFile, line)) {
            std::istringstream iss(line);
            std::string key;
            if (iss >> key) {
                if (key == "ShowBoneESP") iss >> ESPConfig::ShowBoneESP;
                else if (key == "FilledBox") iss >> ESPConfig::FilledBox;
                else if (key == "MultiColor") iss >> ESPConfig::MultiColor;
                else if (key == "BoxFilledColor") iss >> ESPConfig::FilledColor.Value.x >> ESPConfig::FilledColor.Value.y >> ESPConfig::FilledColor.Value.z >> ESPConfig::FilledColor.Value.w;
                else if (key == "BoxFilledColor2") iss >> ESPConfig::FilledColor2.Value.x >> ESPConfig::FilledColor2.Value.y >> ESPConfig::FilledColor2.Value.z >> ESPConfig::FilledColor2.Value.w;
                else if (key == "BoxFilledVisColor") iss >> ESPConfig::BoxFilledVisColor.Value.x >> ESPConfig::BoxFilledVisColor.Value.y >> ESPConfig::BoxFilledVisColor.Value.z >> ESPConfig::BoxFilledVisColor.Value.w;
                else if (key == "BoxFilledVisCheck") iss >> ESPConfig::FilledVisBox;
                else if (key == "SpecList") iss >> MenuConfig::SpecList;
                else if (key == "BombTimerCol") iss >> MenuConfig::BombTimerCol.Value.x >> MenuConfig::BombTimerCol.Value.y >> MenuConfig::BombTimerCol.Value.z >> MenuConfig::BombTimerCol.Value.w;
                else if (key == "bmbTimer") iss >> MenuConfig::bmbTimer;
                else if (key == "ESPVisCol") iss >> ESPConfig::VisibleColor.Value.x >> ESPConfig::VisibleColor.Value.y >> ESPConfig::VisibleColor.Value.z >> ESPConfig::VisibleColor.Value.w;
                else if (key == "ESPVisCheck") iss >> ESPConfig::VisibleCheck;
                else if (key == "GlowColor") iss >> MenuConfig::GlowColor.Value.x >> MenuConfig::GlowColor.Value.y >> MenuConfig::GlowColor.Value.z >> MenuConfig::GlowColor.Value.w;
                else if (key == "Glow") iss >> MenuConfig::Glow;
                else if (key == "AirJump") iss >> MenuConfig::AirJump;
                else if (key == "MenuStyle") iss >> MenuConfig::MenuStyle;
                else if (key == "WindowStyle") iss >> MenuConfig::WindowStyle;
                else if (key == "BoxAlpha") iss >> ESPConfig::BoxAlpha;
                else if (key == "EspPreview") iss >> ESPConfig::ShowPreview;
                else if (key == "ShowHeadBox") iss >> ESPConfig::ShowHeadBox;
                else if (key == "HeadBoxStyle") iss >> ESPConfig::HeadBoxStyle;
                else if (key == "HeadboxColor") iss >> ESPConfig::HeadBoxColor.Value.x >> ESPConfig::HeadBoxColor.Value.y >> ESPConfig::HeadBoxColor.Value.z >> ESPConfig::HeadBoxColor.Value.w;
                else if (key == "ShowDistance") iss >> ESPConfig::ShowDistance;
                else if (key == "TriggerDelay") iss >> TriggerBot::TriggerDelay;
                else if (key == "FakeShot") iss >> TriggerBot::FakeShotDelay;
                else if (key == "ShowBoxESP") iss >> ESPConfig::ShowBoxESP;
                else if (key == "BoxRounding") iss >> ESPConfig::BoxRounding;
                else if (key == "TriggerHotKey") { iss >> MenuConfig::TriggerHotKey; TriggerBot::SetHotKey(MenuConfig::TriggerHotKey); }
                else if (key == "RCSBullet") iss >> RCS::RCSBullet;
                else if (key == "ShowHealthBar") iss >> ESPConfig::ShowHealthBar;
                else if (key == "AimFov") iss >> AimControl::AimFov;
                else if (key == "FovLineSize") iss >> MenuConfig::FovLineSize;
                else if (key == "AimBotHotKey") { iss >> MenuConfig::AimBotHotKey; AimControl::SetHotKey(MenuConfig::AimBotHotKey); }
                else if (key == "ShowLineToEnemy") iss >> MenuConfig::ShowLineToEnemy;
                else if (key == "RCSScale.x") iss >> AimControl::RCSScale.x;
                else if (key == "RCSScale.y") iss >> AimControl::RCSScale.y;
                else if (key == "ShowWeaponESP") iss >> ESPConfig::ShowWeaponESP;
                else if (key == "Smooth") iss >> AimControl::Smooth;
                else if (key == "ShowFovLine") iss >> MenuConfig::ShowFovLine;
                else if (key == "ShowEyeRay") iss >> ESPConfig::ShowEyeRay;
                else if (key == "ShowPlayerName") iss >> ESPConfig::ShowPlayerName;
                else if (key == "AimBot") iss >> MenuConfig::AimBot;
                else if (key == "AimAlways") iss >> MenuConfig::AimAlways;
                else if (key == "AimToggle") iss >> MenuConfig::AimToggleMode;
                else if (key == "AimPosition") iss >> MenuConfig::AimPosition;
                else if (key == "AimPositionIndex") iss >> MenuConfig::AimPositionIndex;
                else if (key == "HealthBarType") iss >> MenuConfig::HealthBarType;
                else if (key == "BoneColor") iss >> ESPConfig::BoneColor.Value.x >> ESPConfig::BoneColor.Value.y >> ESPConfig::BoneColor.Value.z >> ESPConfig::BoneColor.Value.w;
                else if (key == "FovLineColor") iss >> MenuConfig::FovLineColor.Value.x >> MenuConfig::FovLineColor.Value.y >> MenuConfig::FovLineColor.Value.z >> MenuConfig::FovLineColor.Value.w;
                else if (key == "LineToEnemyColor") iss >> MenuConfig::LineToEnemyColor.Value.x >> MenuConfig::LineToEnemyColor.Value.y >> MenuConfig::LineToEnemyColor.Value.z >> MenuConfig::LineToEnemyColor.Value.w;
                else if (key == "BoxColor") iss >> ESPConfig::BoxColor.Value.x >> ESPConfig::BoxColor.Value.y >> ESPConfig::BoxColor.Value.z >> ESPConfig::BoxColor.Value.w;
                else if (key == "EyeRayColor") iss >> ESPConfig::EyeRayColor.Value.x >> ESPConfig::EyeRayColor.Value.y >> ESPConfig::EyeRayColor.Value.z >> ESPConfig::EyeRayColor.Value.w;
                else if (key == "CrossLineColor") iss >> MenuConfig::RadarCrossLineColor.Value.x >> MenuConfig::RadarCrossLineColor.Value.y >> MenuConfig::RadarCrossLineColor.Value.z >> MenuConfig::RadarCrossLineColor.Value.w;
                else if (key == "HeadShootLineColor") iss >> MenuConfig::HeadShootLineColor.Value.x >> MenuConfig::HeadShootLineColor.Value.y >> MenuConfig::HeadShootLineColor.Value.z >> MenuConfig::HeadShootLineColor.Value.w;
                else if (key == "ShowMenu") iss >> MenuConfig::ShowMenu;
                else if (key == "ShowRadar") iss >> MenuConfig::ShowRadar;
                else if (key == "RadarRange") iss >> MenuConfig::RadarRange;
                else if (key == "RadarPointSizeProportion") iss >> MenuConfig::RadarPointSizeProportion;
                else if (key == "RadarBgAlpha") iss >> MenuConfig::RadarBgAlpha;
                else if (key == "ShowCrossLine") iss >> MenuConfig::ShowRadarCrossLine;
                else if (key == "RadarType") iss >> MenuConfig::RadarType;
                else if (key == "Proportion") iss >> MenuConfig::Proportion;
                else if (key == "BoxType") iss >> MenuConfig::BoxType;
                else if (key == "TriggerBot") iss >> MenuConfig::TriggerBot;
                else if (key == "TriggerAlways") iss >> MenuConfig::TriggerAlways;
                else if (key == "TeamCheck") iss >> MenuConfig::TeamCheck;
                else if (key == "BypassOBS") iss >> MenuConfig::BypassOBS;
                else if (key == "VisibleCheck") iss >> MenuConfig::VisibleCheck;
                else if (key == "ShowHeadShootLine") iss >> MenuConfig::ShowHeadShootLine;
                else if (key == "ShowCrossHair") iss >> CrosshairConfig::ShowCrossHair;
                else if (key == "CrossHairColor") iss >> CrosshairConfig::CrossHairColor.Value.x >> CrosshairConfig::CrossHairColor.Value.y >> CrosshairConfig::CrossHairColor.Value.z >> CrosshairConfig::CrossHairColor.Value.w;
                else if (key == "CrossHairSize") iss >> CrosshairConfig::CrossHairSize;
                else if (key == "drawDot") iss >> CrosshairConfig::drawDot;
                else if (key == "tStyle") iss >> CrosshairConfig::tStyle;
                else if (key == "HorizontalLength") iss >> CrosshairConfig::HorizontalLength;
                else if (key == "VerticalLength") iss >> CrosshairConfig::VerticalLength;
                else if (key == "drawOutLine") iss >> CrosshairConfig::drawOutLine;
                else if (key == "Gap") iss >> CrosshairConfig::Gap;
                else if (key == "drawCrossline") iss >> CrosshairConfig::drawCrossline;
                else if (key == "drawCircle") iss >> CrosshairConfig::drawCircle;
                else if (key == "showTargeting") iss >> CrosshairConfig::showTargeting;
                else if (key == "CircleRadius") iss >> CrosshairConfig::CircleRadius;
                else if (key == "TargetedColor") iss >> CrosshairConfig::TargetedColor.Value.x >> CrosshairConfig::TargetedColor.Value.y >> CrosshairConfig::TargetedColor.Value.z >> CrosshairConfig::TargetedColor.Value.w;
                else if (key == "DynamicGap") iss >> CrosshairConfig::DynamicGap;
                else if (key == "DotSize") iss >> CrosshairConfig::DotSize;
                else if (key == "CrosshairsThickness") iss >> CrosshairConfig::Thickness;
                else if (key == "CrosshairsTeamCheck") iss >> CrosshairConfig::TeamCheck;

                else if (key == "BunnyHop") iss >> MenuConfig::BunnyHop;
                else if (key == "WorkInSpec") iss >> MenuConfig::WorkInSpec;
                else if (key == "NoFlash") iss >> MenuConfig::NoFlash;
                else if (key == "WaterMark") iss >> MenuConfig::WaterMark;
                else if (key == "CheatList") iss >> MenuConfig::CheatList;
                else if (key == "HitSound") iss >> MenuConfig::HitSound;

                else if (key == "ESPenabled") iss >> ESPConfig::ESPenbled;
                else if (key == "DrawFov") iss >> ESPConfig::DrawFov;
                else if (key == "FovColor") iss >> MenuConfig::FovCircleColor.Value.x >> MenuConfig::FovCircleColor.Value.y >> MenuConfig::FovCircleColor.Value.z >> MenuConfig::FovCircleColor.Value.w;
                else if (key == "ShowPenis") iss >> ESPConfig::ShowPenis;
                else if (key == "PenisColor") iss >> ESPConfig::PenisColor.Value.x >> ESPConfig::PenisColor.Value.y >> ESPConfig::PenisColor.Value.z >> ESPConfig::PenisColor.Value.w;
                else if (key == "PenisSize") iss >> ESPConfig::PenisSize;
                else if (key == "PenisLength") iss >> ESPConfig::PenisLength;
                else if (key == "SnaplinePos") iss >> MenuConfig::LinePos;
                else if (key == "CustomRadar") iss >> MenuConfig::customRadar;
                else if (key == "MenuStyle") iss >> MenuConfig::MenuStyle;

            }
        }

        configFile.close();
        std::cout << "[Info] Configuration loaded from " << MenuConfig::path + '\\' + filename << std::endl;
    }
} // namespace ConfigSaver
