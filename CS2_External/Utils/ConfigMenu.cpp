#include "ConfigMenu.hpp"
#include "../MenuConfig.hpp"
#include "ConfigSaver.hpp"
#include "../TriggerBot.h"
#include "../AimBot.hpp"
#include <filesystem>
#include <string>
#include "../Font/IconsFontAwesome5.h"
#include "../Resources/Language.h"

namespace ConfigMenu {
	
	void RenderCFGmenu()
	{
		static char configNameBuffer[128] = "NewConfig";
		static int selectedConfig = -1;

		const std::string configDir = MenuConfig::path;
		static std::vector<std::string> configFiles;
		std::vector<const char*> configFilesCStr;

		configFiles.clear();
		for (const auto& entry : std::filesystem::directory_iterator(configDir))
		{
			if (entry.is_regular_file() && entry.path().extension() == ".config")
			{
				configFiles.push_back(entry.path().filename().string());
			}
		}
		for (const auto& file : configFiles)
		{
			configFilesCStr.push_back(file.c_str());
		}

		float CursorX = 10.f;
		float CurrentCursorX = ImGui::GetCursorPosX();
		float ComponentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX * 2;

		ImGui::SetCursorPos(ImVec2(15.f, 24.f));
		ImGui::SeparatorText("Config");

		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled("Config Files");
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::SetNextItemWidth(ComponentWidth);
		ImGui::ListBox("##ConfigFiles", &selectedConfig, configFilesCStr.data(), configFilesCStr.size());
	}

	void RenderConfigMenu(const char *Tab) {
		// Config		
		if (ImGui::BeginTabItem(Tab))
		{
			ImGui::Columns(2, nullptr, false);
			ImGui::SetColumnOffset(1, 170.0f);

			ImGui::PushItemWidth(160.0f);

			static char configNameBuffer[128] = "NewConfig";

			static int selectedConfig = -1;

			const std::string configDir = MenuConfig::path;
			static std::vector<std::string> configFiles;
			std::vector<const char*> configFilesCStr;

			configFiles.clear();
			for (const auto& entry : std::filesystem::directory_iterator(configDir))
			{
				if (entry.is_regular_file() && entry.path().extension() == ".config")
				{
					configFiles.push_back(entry.path().filename().string());
				}
			}

			// 将vector转到const char*数组
			for (const auto& file : configFiles)
			{
				configFilesCStr.push_back(file.c_str());
			}

			// 创建列表框并载入配置文件数组
			ImGui::ListBox("##ConfigFiles", &selectedConfig, configFilesCStr.data(), configFilesCStr.size());

			ImGui::NextColumn();
			ImGui::PushItemWidth(100.0f);

			if (ImGui::Button("Load Selected", { 100.0f, 25.0f }) && selectedConfig >= 0 && selectedConfig < configFiles.size())
			{
				std::string selectedConfigFile = configFiles[selectedConfig];
				MyConfigSaver::LoadConfig(selectedConfigFile);
				// Because the style is switched when Combo is activated, the style should be manually updated here
				// Render::UpdateStyle(MenuConfig::MenuStyle);
				// Umm...Some problem occured
			}

			if (ImGui::Button("Save Selected", { 100.0f, 25.0f }) && selectedConfig >= 0 && selectedConfig < configFiles.size())
			{
				std::string selectedConfigFile = configFiles[selectedConfig];
				MyConfigSaver::SaveConfig(selectedConfigFile);
			}

			if (ImGui::Button("Delete Selected", { 100.0f, 25.0f }) && selectedConfig >= 0 && selectedConfig < configFiles.size())
				ImGui::OpenPopup("##reallyDelete");

			if (ImGui::BeginPopup("##reallyDelete"))
			{
				ImGui::TextUnformatted("Are you sure?");
				if (ImGui::Button("No", { 45.0f, 0.0f }))
					ImGui::CloseCurrentPopup();
				ImGui::SameLine();
				if (ImGui::Button("Yes", { 45.0f, 0.0f }))
				{
					// Delete
					std::string selectedConfigFile = configFiles[selectedConfig];
					std::string fullPath = configDir + "\\" + selectedConfigFile;
					if (std::remove(fullPath.c_str()) == 0)
					{
						configFiles.erase(configFiles.begin() + selectedConfig);
						selectedConfig = -1;
					}
					else
					{
					}
					ImGui::CloseCurrentPopup();
				}
			ImGui::EndPopup();
			}

			if (ImGui::Button("Reset Config", { 100.0f, 25.0f }))
				ImGui::OpenPopup("##reallyReset");
			if (ImGui::BeginPopup("##reallyReset"))
			{
				ImGui::TextUnformatted("Are you sure?");
				if (ImGui::Button("No", { 45.0f, 0.0f }))
					ImGui::CloseCurrentPopup();
				ImGui::SameLine();
				if (ImGui::Button("Yes", { 45.0f, 0.0f }))
				{
					ConfigMenu::ResetToDefault();
					ImGui::CloseCurrentPopup();
				}	
				ImGui::EndPopup();
			}
			ImGui::Columns(1);

			ImGui::SeparatorText("Save Config");
			ImGui::InputText(" ", configNameBuffer, sizeof(configNameBuffer));
			ImGui::SameLine();
			if (ImGui::Button("Create Config", { 100.0f, 25.0f }))
			{
				std::string configFileName = std::string(configNameBuffer) + ".config";
				MyConfigSaver::SaveConfig(configFileName);
			}
			ImGui::SameLine();

			if (ImGui::Button("Open Folder", { 100.0f, 25.0f }))
			{
				Gui.OpenWebpage(configDir.c_str());
			}

			ImGui::EndTabItem();
		}
	}

	void ResetToDefault() {
		ESPConfig::FilledColor = ImColor(255, 255, 255, 255);
		ESPConfig::FilledColor2 = ImColor(255, 255, 255, 255);
		ESPConfig::MultiColor = false;
		ESPConfig::BoxFilledVisColor = ImColor(0, 0, 255, 255);
		ESPConfig::FilledVisBox = false;
		MenuConfig::Misc.SpecList = false;
		MenuConfig::Misc.BombTimerCol = ImColor(255, 120, 0, 255);
		MenuConfig::Misc.bmbTimer = false;
		ESPConfig::VisibleColor = ImColor(255, 196, 0, 255);
		ESPConfig::VisibleCheck = false;
		MenuConfig::Misc.GlowColor = ImColor(255, 0, 0, 100);;
		MenuConfig::Misc.Glow = false;
		MenuConfig::AirJump = false;
		MenuConfig::MenuStyle = 0;
		MenuConfig::WindowStyle = 0;
		ESPConfig::BoxAlpha = 0.0f;
		ESPConfig::ShowPreview = true;
		ESPConfig::ShowHeadBox = false;
		ESPConfig::HeadBoxStyle = 0;
		ESPConfig::HeadBoxColor = ImColor(255, 255, 255, 255);
		ESPConfig::ShowDistance = false;
		ESPConfig::ShowBoneESP = true;
		ESPConfig::ShowBoxESP = true;
		ESPConfig::ShowHealthBar = true;
		ESPConfig::ShowWeaponESP = false;
		ESPConfig::ShowEyeRay = false;
		ESPConfig::ShowPlayerName = true;
		ESPConfig::BoxRounding = 0.0f;
		MenuConfig::AimBot = false;
		MenuConfig::AimAlways = false;
		MenuConfig::AimToggleMode = false;
		MenuConfig::AimPosition = 0;
		MenuConfig::AimPositionIndex = BONEINDEX::head;
		MenuConfig::BoxType = 0;
		MenuConfig::HealthBarType = 0;
		ESPConfig::BoneColor = ImColor(0, 255, 255, 255);
		ESPConfig::BoxColor = ImColor(255, 80, 0, 255);
		ESPConfig::EyeRayColor = ImVec4(255, 0, 0, 255);
		MenuConfig::ShowMenu = true;
		MenuConfig::Radar.ShowRadar = false;
		MenuConfig::Radar.RadarRange = 150;
		MenuConfig::Radar.ShowRadarCrossLine = true;
		MenuConfig::Radar.RadarCrossLineColor = ImColor(220, 220, 220, 255);
		MenuConfig::Radar.RadarType = 2;
		MenuConfig::Radar.RadarPointSizeProportion = 1.f;
		MenuConfig::Radar.RadarBgAlpha = 0.1f;
		MenuConfig::Radar.Proportion = 3300;
		MenuConfig::TriggerBot = false;
		MenuConfig::TriggerAlways = false;
		MenuConfig::TeamCheck = true;
		MenuConfig::BypassOBS = false;
		MenuConfig::VisibleCheck = true;
		MenuConfig::ShowHeadShootLine = false;
		MenuConfig::HeadShootLineColor = ImColor(255, 255, 255, 200);
		MenuConfig::AimBotHotKey = 0;
		AimControl::SetHotKey(MenuConfig::AimBotHotKey);
		MenuConfig::ShowLineToEnemy = false;
		MenuConfig::FovLineSize = 60.0f;
		TriggerBot::TriggerDelay = 90;
		TriggerBot::FakeShotDelay = 500;
		RCS::RCSBullet = 1;
		MenuConfig::TriggerHotKey = 0;
		TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
		AimControl::RCSScale = ImVec2(1.2f, 1.4f);
		MenuConfig::FovLineColor = ImVec4(55, 55, 55, 220);
		MenuConfig::LineToEnemyColor = ImVec4(255, 255, 255, 220);
		MenuConfig::Crosshairs.ShowCrossHair = false;
		MenuConfig::Crosshairs.CrossHairColor = ImColor(0, 255, 0, 255);
		MenuConfig::Crosshairs.CrossHairSize = 75;
		MenuConfig::Crosshairs.drawDot = true;
		MenuConfig::Crosshairs.tStyle = false;
		MenuConfig::Crosshairs.HorizontalLength = 6;
		MenuConfig::Crosshairs.VerticalLength = 6;
		MenuConfig::Crosshairs.drawOutLine = true;
		MenuConfig::Crosshairs.Gap = 8;
		MenuConfig::Crosshairs.drawCrossline = true;
		MenuConfig::Crosshairs.drawCircle = false;
		MenuConfig::Crosshairs.showTargeting = false;
		MenuConfig::Crosshairs.TargetedColor = ImColor(255, 0, 0, 255);
		MenuConfig::Crosshairs.CircleRadius = 3.f;
		MenuConfig::Crosshairs.DynamicGap = false;
		MenuConfig::Crosshairs.DotSize = 1.0f;
		MenuConfig::Crosshairs.Thickness = 1;
		MenuConfig::Crosshairs.TeamCheck = true;
		MenuConfig::Misc.BunnyHop = false;
		MenuConfig::Misc.WorkInSpec = true;
		MenuConfig::Misc.NoFlash = false;
		MenuConfig::Misc.WaterMark = false;
		MenuConfig::Misc.CheatList = false;
		MenuConfig::Misc.HitSound = false;

		ESPConfig::ESPenbled = false;

		ESPConfig::ShowPenis = false;
		ESPConfig::PenisLength = 15.f;
		ESPConfig::PenisSize = 1.3f;
		ESPConfig::PenisColor = ImColor(255, 0, 0, 200);

		ESPConfig::DrawFov = false;
		MenuConfig::FovCircleColor = ImColor(255, 255, 255, 255);
	}
}
