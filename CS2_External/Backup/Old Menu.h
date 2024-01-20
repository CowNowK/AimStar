void RenderMenu()
{
	char TempText[256];
	ImGui::Begin("AimStar", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);
	{
		ImGui::BeginTabBar("AimStar", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_NoTooltip);

		// esp menu
		sprintf_s(TempText, "%s%s", ICON_FA_EYE, Lang::ESPtext.FeatureName);
		if (ImGui::BeginTabItem(TempText))
		{
			Gui.MyCheckBox(Lang::Global.SwitchButton, &ESPConfig::ESPenabled);
			ImGui::Checkbox(Lang::ESPtext.Box, &ESPConfig::ShowBoxESP);
			ImGui::SameLine();
			ImGui::ColorEdit4("##BoxColor", reinterpret_cast<float*>(&ESPConfig::BoxColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("##BoxStyle", &MenuConfig::BoxType, "Normal\0Edge\0Corner\0Corner Edge\0");
			if (ESPConfig::ShowBoxESP)
				ImGui::SliderFloat(Lang::ESPtext.BoxRounding, &ESPConfig::BoxRounding, 0.0f, 5.0f, "%.1f", ImGuiSliderFlags_NoInput);

			ImGui::Checkbox(Lang::ESPtext.FilledBox, &ESPConfig::FilledBox);
			ImGui::SameLine();
			if (ImGui::Button("..."))
				ImGui::OpenPopup("##FilledboxSettings");
			if (ImGui::BeginPopup("##FilledboxSettings")) {
				ImGui::TextUnformatted(Lang::Global.FeatureSettings);
				ImGui::ColorEdit4("Default Color", reinterpret_cast<float*>(&ESPConfig::FilledColor), ImGuiColorEditFlags_NoInputs);
				ImGui::SliderFloat(Lang::ESPtext.FilledAlpha, &ESPConfig::BoxAlpha, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_NoInput);
				ImGui::Checkbox(Lang::ESPtext.VisCheck, &ESPConfig::FilledVisBox);
				ImGui::SameLine();
				ImGui::ColorEdit4("##FilledBoxVisColor", reinterpret_cast<float*>(&ESPConfig::BoxFilledVisColor), ImGuiColorEditFlags_NoInputs);
				ImGui::Checkbox(Lang::ESPtext.MultiColor, &ESPConfig::MultiColor);
				ImGui::SameLine();
				ImGui::ColorEdit4("##Color2", reinterpret_cast<float*>(&ESPConfig::FilledColor2), ImGuiColorEditFlags_NoInputs);
				if (ESPConfig::MultiColor && ESPConfig::BoxRounding > 0.f)
				{
					ImGui::TextColored(ImColor(255, 59, 59, 255), Lang::ESPtext.MultiColTip);
				}
				ImGui::EndPopup();
			}

			ImGui::Checkbox(Lang::ESPtext.Skeleton, &ESPConfig::ShowBoneESP);
			ImGui::SameLine();
			ImGui::ColorEdit4("##BoneColor", reinterpret_cast<float*>(&ESPConfig::BoneColor), ImGuiColorEditFlags_NoInputs);

			ImGui::Checkbox(Lang::ESPtext.HeadBox, &ESPConfig::ShowHeadBox);
			ImGui::SameLine();
			ImGui::ColorEdit4("##HeadBoxColor", reinterpret_cast<float*>(&ESPConfig::HeadBoxColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("##HeadBoxStyle", &ESPConfig::HeadBoxStyle, "Normal\0Flat\0");

			ImGui::Checkbox(Lang::ESPtext.EyeRay, &ESPConfig::ShowEyeRay);
			ImGui::SameLine();
			ImGui::ColorEdit4("##EyeRay", reinterpret_cast<float*>(&ESPConfig::EyeRayColor), ImGuiColorEditFlags_NoInputs);

			ImGui::Checkbox(Lang::ESPtext.HealthBar, &ESPConfig::ShowHealthBar);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("##BarStyle", &MenuConfig::HealthBarType, "Vertical\0Top\0");
			ImGui::Checkbox("Ammo", &ESPConfig::AmmoBar);

			ImGui::Checkbox(Lang::ESPtext.Weapon, &ESPConfig::ShowWeaponESP);
			ImGui::Checkbox(Lang::ESPtext.Distance, &ESPConfig::ShowDistance);
			ImGui::Checkbox(Lang::ESPtext.PlayerName, &ESPConfig::ShowPlayerName);

			ImGui::Checkbox(Lang::ESPtext.SnapLine, &ESPConfig::ShowLineToEnemy);
			ImGui::SameLine();
			ImGui::ColorEdit4("##LineToEnemyColor", reinterpret_cast<float*>(&ESPConfig::LineToEnemyColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo(Lang::ESPtext.LinePosList, &ESPConfig::LinePos, "Top\0Center\0Bottom\0");
			ImGui::Checkbox(Lang::ESPtext.VisCheck, &ESPConfig::VisibleCheck);
			ImGui::SameLine();
			ImGui::ColorEdit4("##EspVisCol", reinterpret_cast<float*>(&ESPConfig::VisibleColor), ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox(Lang::ESPtext.Preview, &ESPConfig::ShowPreview);

			//			ImGui::NextColumn();
			ImGui::NewLine();
			if (ImGui::CollapsingHeader(Lang::ESPtext.CollapseHead))
			{
				ImGui::Checkbox(Lang::ESPtext.Penis, &ESPConfig::ShowPenis);
				ImGui::SameLine();
				ImGui::ColorEdit4("##PenisColor", reinterpret_cast<float*>(&ESPConfig::PenisColor), ImGuiColorEditFlags_NoInputs);
				ImGui::SliderFloat(Lang::ESPtext.PenisLength, &ESPConfig::PenisLength, 1.0f, 50.0f, "%.1f");
				ImGui::SliderFloat(Lang::ESPtext.PenisSize, &ESPConfig::PenisSize, 1.3f, 5.0f, "%.3f");
			}

			//			ImGui::Columns(1);
			ImGui::EndTabItem();
		}

		// aimbot menu
		sprintf_s(TempText, "%s%s", ICON_FA_USER, Lang::AimbotText.FeatureName);
		if (ImGui::BeginTabItem(TempText))
		{

			Gui.MyCheckBox(Lang::Global.SwitchButton, &MenuConfig::AimBot);

			ImGui::SetNextItemWidth(75.f);
			if (ImGui::Combo(Lang::AimbotText.HotKeyList, &MenuConfig::AimBotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL"))
			{
				AimControl::SetHotKey(MenuConfig::AimBotHotKey);
			}
			ImGui::SameLine();
			ImGui::Checkbox(Lang::AimbotText.Toggle, &MenuConfig::AimToggleMode);

			ImGui::Checkbox(Lang::AimbotText.DrawFov, &ESPConfig::DrawFov);
			ImGui::SameLine();
			ImGui::ColorEdit4("##FovCircleColor", reinterpret_cast<float*>(&MenuConfig::FovCircleColor), ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox(Lang::AimbotText.VisCheck, &MenuConfig::VisibleCheck);
			ImGui::Checkbox(Lang::AimbotText.JumpCheck, &MenuConfig::AirJump);

			ImGui::SliderFloat(Lang::AimbotText.FovSlider, &AimControl::AimFov, 0.0f, 25.0f, "%.1f", ImGuiSliderFlags_Logarithmic | ImGuiColorEditFlags_NoInputs);
			ImGui::SliderFloat(Lang::AimbotText.SmoothSlider, &AimControl::Smooth, 0.0f, 5.0f, "%.1f", ImGuiColorEditFlags_NoInputs);
			if (ImGui::Combo(Lang::AimbotText.BoneList, &MenuConfig::AimPosition, "Head\0Neck\0Chest\0Penis"))
			{
				switch (MenuConfig::AimPosition)
				{
				case 0:
					MenuConfig::AimPositionIndex = BONEINDEX::head;
					break;
				case 1:
					MenuConfig::AimPositionIndex = BONEINDEX::neck_0;
					break;
				case 2:
					MenuConfig::AimPositionIndex = BONEINDEX::spine_1;
					break;
				case 3:
					MenuConfig::AimPositionIndex = BONEINDEX::pelvis;
					break;
				default:
					break;
				}
			}
			ImGui::TextColored(ImColor(101, 255, 0, 255), Lang::AimbotText.Tip);
			ImGui::Checkbox("Recoil Control", &MenuConfig::RCS);
			/*
			ImGui::NewLine();
			ImGui::SeparatorText("Recoil Control System");
			Gui.MyCheckBox("Enabled", &MenuConfig::RCS);
			ImGui::SliderInt("Start Bullet", &RCS::RCSBullet, 1, 6, "%d");
			ImGui::SliderFloat("Yaw", &AimControl::RCSScale.x, 0.f, 2.f, "%.1f");
			ImGui::SliderFloat("Pitch", &AimControl::RCSScale.y, 0.f, 2.f, "%.1f");*/

			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem(Lang::GlowText.FeatureName))
		{
			Gui.MyCheckBox(Lang::Global.SwitchButton, &MiscCFG::EnemySensor);
			ImGui::EndTabItem();
		}
		// Radar menu
		sprintf_s(TempText, "%s%s", ICON_FA_COMPASS, Lang::RadarText.FeatureName);
		if (ImGui::BeginTabItem(TempText))
		{
			/*
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip("External rendering radar hack.");
			}*/

			Gui.MyCheckBox(Lang::Global.SwitchButton, &RadarCFG::ShowRadar);
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth + 20);
			ImGui::Combo(Lang::RadarText.StyleList, &RadarCFG::RadarType, "Circle\0Arrow\0Circle & Arrow\0");
			ImGui::Checkbox(Lang::RadarText.CustomCheck, &RadarCFG::customRadar);

			if (RadarCFG::customRadar)
			{
				ImGui::NewLine();
				ImGui::Checkbox(Lang::RadarText.CrossLine, &RadarCFG::ShowRadarCrossLine);
				ImGui::SameLine();
				ImGui::ColorEdit4("##CrossLineColor", reinterpret_cast<float*>(&RadarCFG::RadarCrossLineColor), ImGuiColorEditFlags_NoInputs);
				float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
				float ProportionMin = 500.f, ProportionMax = 3300.f;
				float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
				ImGui::SliderFloat(Lang::RadarText.SizeSlider, &RadarCFG::RadarPointSizeProportion, RadarPointSizeProportionMin, RadarPointSizeProportionMax, "%.1f");
				ImGui::SliderFloat(Lang::RadarText.ProportionSlider, &RadarCFG::Proportion, ProportionMin, ProportionMax, "%.1f");
				ImGui::SliderFloat(Lang::RadarText.RangeSlider, &RadarCFG::RadarRange, RadarRangeMin, RadarRangeMax, "%.1f");
				ImGui::SliderFloat(Lang::RadarText.AlphaSlider, &RadarCFG::RadarBgAlpha, 0.0f, 1.0f, "%.2f");
			}
			ImGui::EndTabItem();
		}

		// TriggerBot
		sprintf_s(TempText, "%s%s", ICON_FA_HAND_POINTER, Lang::TriggerText.FeatureName);
		if (ImGui::BeginTabItem(TempText))
		{
			/*
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip("Automatically fires a weapon as soon as an enemy comes into the crosshair.");
			}*/

			Gui.MyCheckBox(Lang::Global.SwitchButton, &MenuConfig::TriggerBot);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);

			if (ImGui::Combo(Lang::TriggerText.HotKeyList, &MenuConfig::TriggerHotKey, "LALT\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL"))
			{
				TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
			}

			ImGui::Checkbox(Lang::TriggerText.Toggle, &MenuConfig::TriggerAlways);
			DWORD TriggerDelayMin = 10, TriggerDelayMax = 1000;
			ImGui::SliderInt(Lang::TriggerText.DelaySlider, &TriggerBot::TriggerDelay, TriggerDelayMin, TriggerDelayMax, "%d ms", ImGuiSliderFlags_None);
			ImGui::SliderInt(Lang::TriggerText.FakeShotSlider, &TriggerBot::FakeShotDelay, 0, 1000, "%d ms", ImGuiSliderFlags_None);

			ImGui::EndTabItem();
		}

		//Crosshair
		sprintf_s(TempText, "%s%s", ICON_FA_DOT_CIRCLE, Lang::CrosshairsText.FeatureName);
		if (ImGui::BeginTabItem(TempText))
		{
			/*
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip("Highly customizable external crosshair.");
			}*/

			Gui.MyCheckBox(Lang::Global.SwitchButton, &CrosshairsCFG::ShowCrossHair);

			ImGui::SetNextItemWidth(MenuConfig::ComboWidth + 50);
			if (ImGui::Combo(Lang::CrosshairsText.PresetList, &CrosshairsCFG::crosshairPreset, "Custom\0Dot\0Circle Dot 1\0Circle Dot 2\0Crosshair Small\0Crosshair Medium\0Crosshair Dot\0Square\0"))
				Render::UpdateCrosshairPreset(CrosshairsCFG::crosshairPreset);

			ImGui::Text(Lang::CrosshairsText.ColorEditor);
			ImGui::SameLine();
			ImGui::ColorEdit4("##CrossHairColor", reinterpret_cast<float*>(&CrosshairsCFG::CrossHairColor), ImGuiColorEditFlags_NoInputs);

			ImGui::Checkbox(Lang::CrosshairsText.Dot, &CrosshairsCFG::drawDot);
			if (CrosshairsCFG::drawDot)
			{
				ImGui::SliderFloat(Lang::CrosshairsText.DotSizeSlider, &CrosshairsCFG::DotSize, 1.f, 50.f, "%.f");
			}

			ImGui::Checkbox(Lang::CrosshairsText.Outline, &CrosshairsCFG::drawOutLine);
			ImGui::Checkbox(Lang::CrosshairsText.Crossline, &CrosshairsCFG::drawCrossline);
			if (CrosshairsCFG::drawCrossline)
			{
				ImGui::SliderInt(Lang::CrosshairsText.hLengthSlider, &CrosshairsCFG::HorizontalLength, 1, 100, "%d", ImGuiSliderFlags_NoInput);
				ImGui::SliderInt(Lang::CrosshairsText.vLengthSilder, &CrosshairsCFG::VerticalLength, 1, 100, "%d", ImGuiSliderFlags_NoInput);
				ImGui::SliderInt(Lang::CrosshairsText.GapSlider, &CrosshairsCFG::Gap, 1, 50, "%d", ImGuiSliderFlags_NoInput);
				//				ImGui::Checkbox("Dynamic Gap", &CrosshairsCFG::DynamicGap);
				ImGui::SliderInt(Lang::CrosshairsText.ThicknessSlider, &CrosshairsCFG::Thickness, 1, 20, "%d", ImGuiSliderFlags_NoInput);
				ImGui::Checkbox(Lang::CrosshairsText.tStyle, &CrosshairsCFG::tStyle);
			}

			ImGui::Separator();
			ImGui::Checkbox(Lang::CrosshairsText.Circle, &CrosshairsCFG::drawCircle);
			if (CrosshairsCFG::drawCircle)
				ImGui::SliderFloat(Lang::CrosshairsText.RadiusSlider, &CrosshairsCFG::CircleRadius, 0.0f, 50.0f, "%.1f", ImGuiSliderFlags_NoInput);

			ImGui::Separator();
			ImGui::Checkbox(Lang::CrosshairsText.TargetCheck, &MenuConfig::TargetingCrosshairs);
			ImGui::SameLine();
			ImGui::ColorEdit4("##CrosshairColor", reinterpret_cast<float*>(&CrosshairsCFG::TargetedColor), ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox(Lang::CrosshairsText.TeamCheck, &CrosshairsCFG::TeamCheck);

			ImGui::EndTabItem();
		}

		// Misc
		sprintf_s(TempText, "%s%s", ICON_FA_SUN, Lang::MiscText.FeatureName);
		if (ImGui::BeginTabItem(TempText))
		{
			/*
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip("Other features.");
			}*/

			ImGui::Columns(2, nullptr, false);
			ImGui::SetColumnOffset(1, 250.0f);

			if (ImGui::Combo(Lang::MiscText.LanguageList, &MenuConfig::Language,
				"English\0Danish\0German\0Polish\0Portuguese\0Russian\0Simplified Chinese\0Slovak\0French\0Turkish\0Hungarian\0Dutch\0")) // Korean\0
				Lang::ChangeLang(MenuConfig::Language);
			if (ImGui::Combo(Lang::MiscText.ThemeList, &MenuConfig::MenuStyle, "AimStar\0Enemy\0Hacker\0Red\0Modern Dark\0Deep Dark\0Round Gray\0Square Dark\0Egirl\0Trans\0"))
				StyleChanger::UpdateSkin(MenuConfig::MenuStyle);
			if (ImGui::Combo(Lang::MiscText.StyleList, &MenuConfig::WindowStyle, "Osiris\0AimStar\0"))
				if (MenuConfig::WindowStyle)
					StyleChanger::UpdateSkin(0);

			ImGui::Checkbox(Lang::MiscText.HeadshotLine, &MenuConfig::ShowHeadShootLine);
			ImGui::SameLine();
			ImGui::ColorEdit4("##HeadShootLineColor", reinterpret_cast<float*>(&MenuConfig::HeadShootLineColor), ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox(Lang::MiscText.SpecCheck, &MiscCFG::WorkInSpec);
			ImGui::Checkbox(Lang::MiscText.NoFlash, &MiscCFG::NoFlash);
			ImGui::Checkbox(Lang::MiscText.FastStop, &MiscCFG::FastStop);
			ImGui::Checkbox(Lang::MiscText.HitSound, &MiscCFG::HitSound);
			ImGui::Checkbox(Lang::MiscText.bmbTimer, &MiscCFG::bmbTimer);
			ImGui::SameLine();
			ImGui::ColorEdit4("##BombTimerCol", reinterpret_cast<float*>(&MiscCFG::BombTimerCol), ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox("Radar Hack", &MiscCFG::RadarHack);
			ImGui::Checkbox(Lang::MiscText.SpecList, &MiscCFG::SpecList);
			if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
			{
				ImGui::SetTooltip("Broken");
			}
			//				ImGui::Checkbox("Invincible", &MenuConfig::infinity);

			ImGui::NextColumn();
			ImGui::SliderFloat("FOV", &MiscCFG::Fov, -5.f, 0.f, "%.1f");
			ImGui::Checkbox(Lang::MiscText.Bhop, &MiscCFG::BunnyHop);
			ImGui::Checkbox(Lang::MiscText.Watermark, &MiscCFG::WaterMark);
			ImGui::Checkbox(Lang::MiscText.CheatList, &MiscCFG::CheatList);
			ImGui::Checkbox(Lang::MiscText.TeamCheck, &MenuConfig::TeamCheck);
			ImGui::Checkbox(Lang::MiscText.AntiRecord, &MenuConfig::BypassOBS);

			ImGui::Columns(1);
			ImGui::EndTabItem();
		}

		// Config
		sprintf_s(TempText, "%s%s", ICON_FA_FOLDER_OPEN, Lang::ConfigText.FeatureName);
		ConfigMenu::RenderConfigMenu(TempText);

		// About
		sprintf_s(TempText, "%s%s", ICON_FA_FILE_CODE, Lang::ReadMeText.FeatureName);
		if (ImGui::BeginTabItem(TempText))
		{
			ImGui::TextColored(ImColor(0, 200, 255, 255), Lang::ReadMeText.LastUpdate);
			ImGui::SameLine();
			ImGui::TextColored(ImColor(0, 200, 255, 255), "2024-01-17");
			sprintf_s(TempText, "%s%s", ICON_FA_COPY, Lang::ReadMeText.SourceButton);
			Gui.OpenWebpageButton(TempText, "https://github.com/CowNowK/AimStar");
			ImGui::SameLine();
			sprintf_s(TempText, "%s%s", ICON_FA_COMMENT_DOTS, Lang::ReadMeText.DiscordButton);
			Gui.OpenWebpageButton(TempText, "https://discord.com/invite/VgRrxwesPz");
			ImGui::NewLine();

			ImGui::SeparatorText(Lang::ReadMeText.OffsetsTitle);
			ImGui::Text("EntityList:");
			ImGui::SameLine();
			ImGui::Text(std::to_string(Offset::EntityList).c_str());
			ImGui::Text("Matrix:");
			ImGui::SameLine();
			ImGui::Text(std::to_string(Offset::Matrix).c_str());
			ImGui::Text("LocalPlayerController:");
			ImGui::SameLine();
			ImGui::Text(std::to_string(Offset::LocalPlayerController).c_str());
			ImGui::Text("ViewAngle:");
			ImGui::SameLine();
			ImGui::Text(std::to_string(Offset::ViewAngle).c_str());
			ImGui::Text("LocalPlayerPawn:");
			ImGui::SameLine();
			ImGui::Text(std::to_string(Offset::LocalPlayerPawn).c_str());
			ImGui::Text("PlantedC4:");
			ImGui::SameLine();
			ImGui::Text(std::to_string(Offset::PlantedC4).c_str());
			ImGui::Text("ForceJump:");
			ImGui::SameLine();
			ImGui::Text(std::to_string(Offset::ForceJump).c_str());

			ImGui::EndTabItem();
		}

	}ImGui::End();
}

void RenderConfigMenu(const char* Tab) {
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
			if (entry.is_regular_file() && entry.path().extension() == ".yml")
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
			std::string configFileName = std::string(configNameBuffer) + ".yml";
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