void RenderGUI()
{
	// ESP
	ImGui::SetNextWindowSize({ 320,0 });
	ImGui::Begin(ICON_FA_EYE " Visual", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	{
		if (ImGui::CollapsingHeader("ESP"))
		{
			ImGui::Checkbox("Enabled", &ESPConfig::ESPenbled);
			ImGui::Checkbox("Box", &ESPConfig::ShowBoxESP);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("##BoxStyle", &MenuConfig::BoxType, "Normal\0Edge\0Corner\0Corner Edge\0");
			ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
			if (ESPConfig::ShowBoxESP)
				ImGui::SliderFloat("Box Rounding", &ESPConfig::BoxRounding, 0.0f, 15.0f, "%.1f", ImGuiSliderFlags_NoInput);

			ImGui::Checkbox("Filled Box", &ESPConfig::FilledBox);
			if (ImGui::IsItemClicked(1))
			{
				ImGui::OpenPopup("##Filledboxvis");
			}
			if (ImGui::BeginPopup("##Filledboxvis")) {
				ImGui::TextUnformatted("Settings");
				ImGui::Checkbox("Visible Check", &ESPConfig::FilledVisBox);
				ImGui::SameLine();
				ImGui::ColorEdit4("##FilledBoxVisColor", reinterpret_cast<float*>(&ESPConfig::BoxFilledVisColor), ImGuiColorEditFlags_NoInputs);
				ImGui::EndPopup();
			}

			if (ESPConfig::FilledBox)
			{
				ImGui::SliderFloat("Filled Box Alpha", &ESPConfig::BoxAlpha, 0.0f, 1.0f, "%.2f", ImGuiSliderFlags_NoInput);
			}

			ImGui::Checkbox("Skeleton", &ESPConfig::ShowBoneESP);
			ImGui::Checkbox("Head Box", &ESPConfig::ShowHeadBox);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("##HeadBoxStyle", &ESPConfig::HeadBoxStyle, "Normal\0Flat");

			ImGui::Checkbox("EyeRay", &ESPConfig::ShowEyeRay);

			ImGui::Checkbox("HealthBar", &ESPConfig::ShowHealthBar);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("##BarStyle", &MenuConfig::HealthBarType, "Vertical\0Top\0Bottom\0");

			ImGui::Checkbox("Weapon", &ESPConfig::ShowWeaponESP);
			ImGui::Checkbox("Distance", &ESPConfig::ShowDistance);
			ImGui::Checkbox("Name", &ESPConfig::ShowPlayerName);

			ImGui::Checkbox("SnapLine", &MenuConfig::ShowLineToEnemy);
			ImGui::SameLine();
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("Line Pos", &MenuConfig::LinePos, "Top\0Center\0Bottom");

			ImGui::SeparatorText("Sexy ESP");
			ImGui::Checkbox("Penis", &ESPConfig::ShowPenis);
			ImGui::SameLine();
			ImGui::ColorEdit4("##PenisColor", reinterpret_cast<float*>(&ESPConfig::PenisColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SliderFloat("Length", &ESPConfig::PenisLength, 1.0f, 50.0f, "%.1f");
			ImGui::SliderFloat("Size", &ESPConfig::PenisSize, 1.3f, 5.0f, "%.3f");
		}
		if (ImGui::CollapsingHeader("Radar"))
		{
			ImGui::Checkbox("Enabled", &MenuConfig::Radar.ShowRadar);
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth + 20);
			ImGui::Combo("Style", &MenuConfig::Radar.RadarType, "Circle\0Arrow\0Circle & Arrow\0");
			ImGui::Checkbox("Custom", &MenuConfig::Radar.customRadar);

			if (MenuConfig::Radar.customRadar)
			{
				ImGui::NewLine();
				ImGui::Checkbox("Cross Line", &MenuConfig::Radar.ShowRadarCrossLine);
				float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
				float ProportionMin = 500.f, ProportionMax = 3300.f;
				float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderFloat("PointSize", &MenuConfig::Radar.RadarPointSizeProportion, RadarPointSizeProportionMin, RadarPointSizeProportionMax, "%.1f", ImGuiColorEditFlags_NoInputs);
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderFloat("Proportion", &MenuConfig::Radar.Proportion, ProportionMin, ProportionMax, "%.1f", ImGuiColorEditFlags_NoInputs);
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderFloat("Range", &MenuConfig::Radar.RadarRange, RadarRangeMin, RadarRangeMax, "%.1f", ImGuiColorEditFlags_NoInputs);
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderFloat("Backgroud Alpha", &MenuConfig::Radar.RadarBgAlpha, 0.0f, 1.0f, "%.2f", ImGuiColorEditFlags_NoInputs);
			}
		}

		if (ImGui::CollapsingHeader("Glow"))
		{
			Gui.MyCheckBox("Enabled", &MenuConfig::Misc.Glow);
		}
		if (ImGui::CollapsingHeader("Crosshairs"))
		{
			ImGui::Checkbox("Enabled", &CrosshairConfig::ShowCrossHair);

			ImGui::SetNextItemWidth(MenuConfig::ComboWidth + 50);
			if (ImGui::Combo("Presets", &CrosshairConfig::crosshairPreset, "Custom\0Dot\0Circle Dot 1\0Circle Dot 2\0Crosshair Small\0Crosshair Medium\0Crosshair Dot\0Square\0"))
				Render::UpdateCrosshairPreset(CrosshairConfig::crosshairPreset);

			ImGui::Checkbox("Center Dot", &CrosshairConfig::drawDot);
			if (CrosshairConfig::drawDot)
			{
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderFloat("Dot Size", &CrosshairConfig::DotSize, 1.f, 50.f, "%.f", ImGuiColorEditFlags_NoInputs);
			}

			ImGui::Checkbox("Outline", &CrosshairConfig::drawOutLine);
			ImGui::Checkbox("Crossline", &CrosshairConfig::drawCrossline);
			if (CrosshairConfig::drawCrossline)
			{
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderInt("Horizontal Length", &CrosshairConfig::HorizontalLength, 1, 100, "%d", ImGuiColorEditFlags_NoInputs);
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderInt("Vertical Length", &CrosshairConfig::VerticalLength, 1, 100, "%d", ImGuiColorEditFlags_NoInputs);
				ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
				ImGui::SliderInt("Gap", &CrosshairConfig::Gap, 1, 50, "%d", ImGuiColorEditFlags_NoInputs);
				//				ImGui::Checkbox("Dynamic Gap", &CrosshairConfig::DynamicGap);
				ImGui::SliderInt("Thickness", &CrosshairConfig::Thickness, 1, 20, "%d", ImGuiSliderFlags_NoInput);
				ImGui::Checkbox("T Style", &CrosshairConfig::tStyle);
			}

			ImGui::Separator();
			ImGui::Checkbox("Circle", &CrosshairConfig::drawCircle);
			ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
			if (CrosshairConfig::drawCircle)
				ImGui::SliderFloat("Circle Radius", &CrosshairConfig::CircleRadius, 0.0f, 50.0f, "%.1f", ImGuiColorEditFlags_NoInputs);

			ImGui::Separator();
			ImGui::Checkbox("Target Crosshair", &CrosshairConfig::showTargeting);
			ImGui::Checkbox("TeamCheck", &CrosshairConfig::TeamCheck);
		}
	} ImGui::End();

	ImGui::SetNextWindowSize({ 320,0 });
	ImGui::Begin(ICON_FA_USER " Player", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	{
		if (ImGui::CollapsingHeader("Aimbot"))
		{
			ImGui::Checkbox("Enabled", &MenuConfig::AimBot);

			ImGui::SetNextItemWidth(75.f);
			if (ImGui::Combo("Key", &MenuConfig::AimBotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL"))
			{
				AimControl::SetHotKey(MenuConfig::AimBotHotKey);
			}
			ImGui::SameLine();
			ImGui::Checkbox("Toggle Mode", &MenuConfig::AimToggleMode);

			ImGui::Checkbox("Draw Fov", &ESPConfig::DrawFov);
			ImGui::Checkbox("Visible Only", &MenuConfig::VisibleCheck);
			ImGui::Checkbox("On Ground Only", &MenuConfig::AirJump);

			float FovMin = 0.1f, FovMax = 89.f;
			float SmoothMin = 0.1f, SmoothMax = 1.f;
			ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
			ImGui::SliderFloat("Fov", &AimControl::AimFov, 0.0f, 25.0f, "%.1f", ImGuiSliderFlags_Logarithmic | ImGuiColorEditFlags_NoInputs);
			ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
			ImGui::SliderFloat("Smooth", &AimControl::Smooth, 1.0f, 5.0f, "%.1f", ImGuiColorEditFlags_NoInputs);
			if (ImGui::Combo("Bone", &MenuConfig::AimPosition, "Head\0Neck\0Chest\0Penis"))
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
		}
		if (ImGui::CollapsingHeader("TriggerBot"))
		{
			ImGui::Checkbox("Enabled", &MenuConfig::TriggerBot);
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);

			if (ImGui::Combo("Togglekey", &MenuConfig::TriggerHotKey, "LALT\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL"))
			{
				TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
			}

			ImGui::Checkbox("Always Activate", &MenuConfig::TriggerAlways);
			DWORD TriggerDelayMin = 10, TriggerDelayMax = 1000;
			ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
			ImGui::SliderInt("Delay", &TriggerBot::TriggerDelay, TriggerDelayMin, TriggerDelayMax, "%d ms", ImGuiSliderFlags_None | ImGuiColorEditFlags_NoInputs);
			ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
			ImGui::SliderInt("Fake Shot", &TriggerBot::FakeShotDelay, 0, 1000, "%d ms", ImGuiSliderFlags_None | ImGuiColorEditFlags_NoInputs);
		}

	} ImGui::End();

	// Misc
	ImGui::SetNextWindowSize({ 320,0 });
	ImGui::Begin(ICON_FA_SUN " Misc", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	{
		ImGui::Checkbox("Headshot Line", &MenuConfig::ShowHeadShootLine);
		ImGui::SameLine();
		ImGui::ColorEdit4("##HeadShootLineColor", reinterpret_cast<float*>(&MenuConfig::HeadShootLineColor), ImGuiColorEditFlags_NoInputs);
		ImGui::Checkbox("Cheat In Spec", &MenuConfig::Misc.WorkInSpec);
		ImGui::Checkbox("No Flash", &MenuConfig::Misc.NoFlash);
		ImGui::Checkbox("Watermark", &MenuConfig::Misc.WaterMark);
		ImGui::Checkbox("Cheat List", &MenuConfig::Misc.CheatList);
		ImGui::Checkbox("HitSound", &MenuConfig::Misc.HitSound);
		ImGui::Checkbox("Bunny Hop", &MenuConfig::Misc.BunnyHop);
		ImGui::Checkbox("Bomb Timer", &MenuConfig::Misc.bmbTimer);
		ImGui::SameLine();
		ImGui::ColorEdit4("##BombTimerCol", reinterpret_cast<float*>(&MenuConfig::Misc.BombTimerCol), ImGuiColorEditFlags_NoInputs);
		ImGui::Checkbox("Spectator List", &MenuConfig::Misc.SpecList);
		ImGui::Checkbox("Team Check", &MenuConfig::TeamCheck);
		ImGui::Checkbox("Bypass OBS", &MenuConfig::BypassOBS);

		ImGui::SeparatorText("Support");
		ImGui::Text(ICON_FA_COPY);
		ImGui::SameLine();
		Gui.OpenWebpageButton("Source Code", "https://github.com/CowNowK/AimStarCS2");
		ImGui::Text(ICON_FA_COMMENT_DOTS);
		ImGui::SameLine();
		Gui.OpenWebpageButton("Join Discord", "https://discord.gg/MzbmSRaU3p");
	} ImGui::End();

	// Color Settings
	ImGui::SetNextWindowSize({ 320,0 });
	ImGui::Begin(ICON_FA_EDIT " Config", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	{
		ImGui::BeginTabBar("ConfigBar", ImGuiTabBarFlags_NoTooltip);
		if (ImGui::BeginTabItem(ICON_FA_EDIT " Colors"))
		{
			ImGui::SeparatorText("ESP");
			ImGui::ColorEdit4("Box", reinterpret_cast<float*>(&ESPConfig::BoxColor), ImGuiColorEditFlags_NoInputs);
			ImGui::ColorEdit4("Bone", reinterpret_cast<float*>(&ESPConfig::BoneColor), ImGuiColorEditFlags_NoInputs);
			ImGui::ColorEdit4("Head Box", reinterpret_cast<float*>(&ESPConfig::HeadBoxColor), ImGuiColorEditFlags_NoInputs);
			ImGui::ColorEdit4("Snap Line", reinterpret_cast<float*>(&MenuConfig::LineToEnemyColor), ImGuiColorEditFlags_NoInputs);
			ImGui::ColorEdit4("Eye Ray", reinterpret_cast<float*>(&ESPConfig::EyeRayColor), ImGuiColorEditFlags_NoInputs);
			ImGui::ColorEdit4("Filled Box", reinterpret_cast<float*>(&ESPConfig::FilledColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SeparatorText("Aimbot");
			ImGui::ColorEdit4("Fov Circle", reinterpret_cast<float*>(&MenuConfig::FovCircleColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SeparatorText("Radar");
			ImGui::ColorEdit4("Cross Line", reinterpret_cast<float*>(&MenuConfig::Radar.RadarCrossLineColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SeparatorText("Crosshairs");
			ImGui::ColorEdit4("Untarget", reinterpret_cast<float*>(&CrosshairConfig::CrossHairColor), ImGuiColorEditFlags_NoInputs);
			ImGui::ColorEdit4("Targeting", reinterpret_cast<float*>(&CrosshairConfig::TargetedColor), ImGuiColorEditFlags_NoInputs);
			ImGui::SeparatorText("Window Style");
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			if (ImGui::Combo("Theme", &MenuConfig::MenuStyle, "Default\0Hacker\0Red\0Modern Dark\0Deep Dark\0"))
				StyleChanger::UpdateSkin(MenuConfig::MenuStyle);
			ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
			ImGui::Combo("Style", &MenuConfig::WindowStyle, "Window\0Collapse\0");
			ImGui::EndTabItem();
		}
		//			ConfigMenu::RenderConfigMenu();

	} ImGui::End();
}