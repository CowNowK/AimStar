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
        configFile << "SpecList " << MenuConfig::Misc.SpecList << std::endl;
        configFile << "BombTimerCol " << MenuConfig::Misc.BombTimerCol.Value.x << " " << MenuConfig::Misc.BombTimerCol.Value.y << " " << MenuConfig::Misc.BombTimerCol.Value.z << " " << MenuConfig::Misc.BombTimerCol.Value.w << std::endl;
        configFile << "bmbTimer " << MenuConfig::Misc.bmbTimer << std::endl;
        configFile << "ESPVisCol " << ESPConfig::VisibleColor.Value.x << " " << ESPConfig::VisibleColor.Value.y << " " << ESPConfig::VisibleColor.Value.z << " " << ESPConfig::VisibleColor.Value.w << std::endl;;
        configFile << "ESPVisCheck " << ESPConfig::VisibleCheck << std::endl;
        configFile << "GlowColor " << MenuConfig::Misc.GlowColor.Value.x << " " << MenuConfig::Misc.GlowColor.Value.y << " " << MenuConfig::Misc.GlowColor.Value.z << " " << MenuConfig::Misc.GlowColor.Value.w << std::endl;
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
        configFile << "RadarCrossLineColor " << MenuConfig::Radar.RadarCrossLineColor.Value.x << " " << MenuConfig::Radar.RadarCrossLineColor.Value.y << " " << MenuConfig::Radar.RadarCrossLineColor.Value.z << " " << MenuConfig::Radar.RadarCrossLineColor.Value.w << std::endl;
        configFile << "HeadShootLineColor " << MenuConfig::HeadShootLineColor.Value.x << " " << MenuConfig::HeadShootLineColor.Value.y << " " << MenuConfig::HeadShootLineColor.Value.z << " " << MenuConfig::HeadShootLineColor.Value.w << std::endl;
        configFile << "ShowMenu " << MenuConfig::ShowMenu << std::endl;
        configFile << "ShowRadar " << MenuConfig::Radar.ShowRadar << std::endl;
        configFile << "RadarRange " << MenuConfig::Radar.RadarRange << std::endl;
        configFile << "RadarPointSizeProportion " << MenuConfig::Radar.RadarPointSizeProportion << std::endl;
        configFile << "RadarBgAlpha " << MenuConfig::Radar.RadarBgAlpha << std::endl;
        configFile << "ShowCrossLine " << MenuConfig::Radar.ShowRadarCrossLine << std::endl;
        configFile << "RadarType " << MenuConfig::Radar.RadarType << std::endl;
        configFile << "Proportion " << MenuConfig::Radar.Proportion << std::endl;
        configFile << "BoxType " << MenuConfig::BoxType << std::endl;
        configFile << "TriggerBot " << MenuConfig::TriggerBot << std::endl;
        configFile << "TriggerAlways " << MenuConfig::TriggerAlways << std::endl;
        configFile << "TeamCheck " << MenuConfig::TeamCheck << std::endl;
        configFile << "BypassOBS " << MenuConfig::BypassOBS << std::endl;
        configFile << "VisibleCheck " << MenuConfig::VisibleCheck << std::endl;
        configFile << "ShowHeadShootLine " << MenuConfig::ShowHeadShootLine << std::endl;
        configFile << "ShowCrossHair " << MenuConfig::Crosshairs.ShowCrossHair << std::endl;
        configFile << "CrossHairColor " << MenuConfig::Crosshairs.CrossHairColor.Value.x << " " << MenuConfig::Crosshairs.CrossHairColor.Value.y << " " << MenuConfig::Crosshairs.CrossHairColor.Value.z << " " << MenuConfig::Crosshairs.CrossHairColor.Value.w << std::endl;
        configFile << "CrossHairSize " << MenuConfig::Crosshairs.CrossHairSize << std::endl;
        configFile << "drawDot " << MenuConfig::Crosshairs.drawDot << std::endl;
        configFile << "tStyle " << MenuConfig::Crosshairs.tStyle << std::endl;
        configFile << "HorizontalLength " << MenuConfig::Crosshairs.HorizontalLength << std::endl;
        configFile << "VerticalLength " << MenuConfig::Crosshairs.VerticalLength << std::endl;
        configFile << "drawOutLine " << MenuConfig::Crosshairs.drawOutLine << std::endl;
        configFile << "drawCrossline " << MenuConfig::Crosshairs.drawCrossline << std::endl;
        configFile << "drawCircle " << MenuConfig::Crosshairs.drawCircle << std::endl;
        configFile << "showTargeting " << MenuConfig::Crosshairs.showTargeting << std::endl;
        configFile << "CircleRadius " << MenuConfig::Crosshairs.CircleRadius << std::endl;
        configFile << "TargetedColor " << MenuConfig::Crosshairs.TargetedColor.Value.x << " " << MenuConfig::Crosshairs.TargetedColor.Value.y << " " << MenuConfig::Crosshairs.TargetedColor.Value.z << " " << MenuConfig::Crosshairs.TargetedColor.Value.w << std::endl;
        configFile << "Gap " << MenuConfig::Crosshairs.Gap << std::endl;
        configFile << "DynamicGap " << MenuConfig::Crosshairs.DynamicGap << std::endl;
        configFile << "DotSize " << MenuConfig::Crosshairs.DotSize << std::endl;
        configFile << "CrosshairsThickness " << MenuConfig::Crosshairs.Thickness << std::endl;
        configFile << "CrosshairsTeamCheck " << MenuConfig::Crosshairs.TeamCheck << std::endl;

        configFile << "BunnyHop " << MenuConfig::Misc.BunnyHop << std::endl;
        configFile << "WorkInSpec " << MenuConfig::Misc.WorkInSpec << std::endl;
        configFile << "NoFlash" << MenuConfig::Misc.NoFlash << std::endl;
        configFile << "WaterMark " << MenuConfig::Misc.WaterMark << std::endl;
        configFile << "CheatList " << MenuConfig::Misc.CheatList << std::endl;
        configFile << "HitSound " << MenuConfig::Misc.HitSound << std::endl;

        configFile << "ESPenabled " << ESPConfig::ESPenbled << std::endl;
        configFile << "DrawFov " << ESPConfig::DrawFov << std::endl;
        configFile << "FovColor " << MenuConfig::FovCircleColor.Value.x << " " << MenuConfig::FovCircleColor.Value.y << " " << MenuConfig::FovCircleColor.Value.z << " " << MenuConfig::FovCircleColor.Value.w << std::endl;
        configFile << "ShowPenis " << ESPConfig::ShowPenis << std::endl;
        configFile << "PenisColor " << ESPConfig::PenisColor.Value.x << " " << ESPConfig::PenisColor.Value.y << " " << ESPConfig::PenisColor.Value.z << " " << ESPConfig::PenisColor.Value.w << std::endl;
        configFile << "PenisSize " << ESPConfig::PenisSize << std::endl;
        configFile << "PenisLength " << ESPConfig::PenisLength << std::endl;
        configFile << "SnaplinePos " << MenuConfig::LinePos << std::endl;
        configFile << "CustomRadar " << MenuConfig::Radar.customRadar << std::endl;
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
                else if (key == "SpecList") iss >> MenuConfig::Misc.SpecList;
                else if (key == "BombTimerCol") iss >> MenuConfig::Misc.BombTimerCol.Value.x >> MenuConfig::Misc.BombTimerCol.Value.y >> MenuConfig::Misc.BombTimerCol.Value.z >> MenuConfig::Misc.BombTimerCol.Value.w;
                else if (key == "bmbTimer") iss >> MenuConfig::Misc.bmbTimer;
                else if (key == "ESPVisCol") iss >> ESPConfig::VisibleColor.Value.x >> ESPConfig::VisibleColor.Value.y >> ESPConfig::VisibleColor.Value.z >> ESPConfig::VisibleColor.Value.w;
                else if (key == "ESPVisCheck") iss >> ESPConfig::VisibleCheck;
                else if (key == "GlowColor") iss >> MenuConfig::Misc.GlowColor.Value.x >> MenuConfig::Misc.GlowColor.Value.y >> MenuConfig::Misc.GlowColor.Value.z >> MenuConfig::Misc.GlowColor.Value.w;
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
                else if (key == "CrossLineColor") iss >> MenuConfig::Radar.RadarCrossLineColor.Value.x >> MenuConfig::Radar.RadarCrossLineColor.Value.y >> MenuConfig::Radar.RadarCrossLineColor.Value.z >> MenuConfig::Radar.RadarCrossLineColor.Value.w;
                else if (key == "HeadShootLineColor") iss >> MenuConfig::HeadShootLineColor.Value.x >> MenuConfig::HeadShootLineColor.Value.y >> MenuConfig::HeadShootLineColor.Value.z >> MenuConfig::HeadShootLineColor.Value.w;
                else if (key == "ShowMenu") iss >> MenuConfig::ShowMenu;
                else if (key == "ShowRadar") iss >> MenuConfig::Radar.ShowRadar;
                else if (key == "RadarRange") iss >> MenuConfig::Radar.RadarRange;
                else if (key == "RadarPointSizeProportion") iss >> MenuConfig::Radar.RadarPointSizeProportion;
                else if (key == "RadarBgAlpha") iss >> MenuConfig::Radar.RadarBgAlpha;
                else if (key == "ShowCrossLine") iss >> MenuConfig::Radar.ShowRadarCrossLine;
                else if (key == "RadarType") iss >> MenuConfig::Radar.RadarType;
                else if (key == "Proportion") iss >> MenuConfig::Radar.Proportion;
                else if (key == "BoxType") iss >> MenuConfig::BoxType;
                else if (key == "TriggerBot") iss >> MenuConfig::TriggerBot;
                else if (key == "TriggerAlways") iss >> MenuConfig::TriggerAlways;
                else if (key == "TeamCheck") iss >> MenuConfig::TeamCheck;
                else if (key == "BypassOBS") iss >> MenuConfig::BypassOBS;
                else if (key == "VisibleCheck") iss >> MenuConfig::VisibleCheck;
                else if (key == "ShowHeadShootLine") iss >> MenuConfig::ShowHeadShootLine;
                else if (key == "ShowCrossHair") iss >> MenuConfig::Crosshairs.ShowCrossHair;
                else if (key == "CrossHairColor") iss >> MenuConfig::Crosshairs.CrossHairColor.Value.x >> MenuConfig::Crosshairs.CrossHairColor.Value.y >> MenuConfig::Crosshairs.CrossHairColor.Value.z >> MenuConfig::Crosshairs.CrossHairColor.Value.w;
                else if (key == "CrossHairSize") iss >> MenuConfig::Crosshairs.CrossHairSize;
                else if (key == "drawDot") iss >> MenuConfig::Crosshairs.drawDot;
                else if (key == "tStyle") iss >> MenuConfig::Crosshairs.tStyle;
                else if (key == "HorizontalLength") iss >> MenuConfig::Crosshairs.HorizontalLength;
                else if (key == "VerticalLength") iss >> MenuConfig::Crosshairs.VerticalLength;
                else if (key == "drawOutLine") iss >> MenuConfig::Crosshairs.drawOutLine;
                else if (key == "Gap") iss >> MenuConfig::Crosshairs.Gap;
                else if (key == "drawCrossline") iss >> MenuConfig::Crosshairs.drawCrossline;
                else if (key == "drawCircle") iss >> MenuConfig::Crosshairs.drawCircle;
                else if (key == "showTargeting") iss >> MenuConfig::Crosshairs.showTargeting;
                else if (key == "CircleRadius") iss >> MenuConfig::Crosshairs.CircleRadius;
                else if (key == "TargetedColor") iss >> MenuConfig::Crosshairs.TargetedColor.Value.x >> MenuConfig::Crosshairs.TargetedColor.Value.y >> MenuConfig::Crosshairs.TargetedColor.Value.z >> MenuConfig::Crosshairs.TargetedColor.Value.w;
                else if (key == "DynamicGap") iss >> MenuConfig::Crosshairs.DynamicGap;
                else if (key == "DotSize") iss >> MenuConfig::Crosshairs.DotSize;
                else if (key == "CrosshairsThickness") iss >> MenuConfig::Crosshairs.Thickness;
                else if (key == "CrosshairsTeamCheck") iss >> MenuConfig::Crosshairs.TeamCheck;

                else if (key == "BunnyHop") iss >> MenuConfig::Misc.BunnyHop;
                else if (key == "WorkInSpec") iss >> MenuConfig::Misc.WorkInSpec;
                else if (key == "NoFlash") iss >> MenuConfig::Misc.NoFlash;
                else if (key == "WaterMark") iss >> MenuConfig::Misc.WaterMark;
                else if (key == "CheatList") iss >> MenuConfig::Misc.CheatList;
                else if (key == "HitSound") iss >> MenuConfig::Misc.HitSound;

                else if (key == "ESPenabled") iss >> ESPConfig::ESPenbled;
                else if (key == "DrawFov") iss >> ESPConfig::DrawFov;
                else if (key == "FovColor") iss >> MenuConfig::FovCircleColor.Value.x >> MenuConfig::FovCircleColor.Value.y >> MenuConfig::FovCircleColor.Value.z >> MenuConfig::FovCircleColor.Value.w;
                else if (key == "ShowPenis") iss >> ESPConfig::ShowPenis;
                else if (key == "PenisColor") iss >> ESPConfig::PenisColor.Value.x >> ESPConfig::PenisColor.Value.y >> ESPConfig::PenisColor.Value.z >> ESPConfig::PenisColor.Value.w;
                else if (key == "PenisSize") iss >> ESPConfig::PenisSize;
                else if (key == "PenisLength") iss >> ESPConfig::PenisLength;
                else if (key == "SnaplinePos") iss >> MenuConfig::LinePos;
                else if (key == "CustomRadar") iss >> MenuConfig::Radar.customRadar;
                else if (key == "MenuStyle") iss >> MenuConfig::MenuStyle;

            }
        }

        configFile.close();
        std::cout << "[Info] Configuration loaded from " << MenuConfig::path + '\\' + filename << std::endl;
    }
} // namespace ConfigSaver
