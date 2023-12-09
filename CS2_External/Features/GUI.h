#pragma once
#include "..\MenuConfig.hpp"
#include "..\Render.hpp"
#include "..\AimBot.hpp"
#include "..\Radar\Radar.h"
#include "..\TriggerBot.h"
#include "..\Utils\ConfigMenu.hpp"
#include "..\Utils\ConfigSaver.hpp"

#include "StyleChanger.h"
#include "..\Resources\Language.h"

namespace GUI
{
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
				Gui.MyCheckBox(Lang::Global.SwitchButton, &ESPConfig::ESPenbled);
				ImGui::Checkbox(Lang::ESPtext.Box, &ESPConfig::ShowBoxESP);
				ImGui::SameLine();
				ImGui::ColorEdit4("##BoxColor", reinterpret_cast<float*>(&ESPConfig::BoxColor), ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
				ImGui::Combo("##BoxStyle", &MenuConfig::BoxType, "Normal\0Edge\0Corner\0Corner Edge\0");
				if (ESPConfig::ShowBoxESP)
					ImGui::SliderFloat(Lang::ESPtext.BoxRounding, &ESPConfig::BoxRounding, 0.0f, 15.0f, "%.1f", ImGuiSliderFlags_NoInput);

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

				ImGui::Checkbox(Lang::ESPtext.Weapon, &ESPConfig::ShowWeaponESP);
				ImGui::Checkbox(Lang::ESPtext.Distance, &ESPConfig::ShowDistance);
				ImGui::Checkbox(Lang::ESPtext.PlayerName, &ESPConfig::ShowPlayerName);

				ImGui::Checkbox(Lang::ESPtext.SnapLine, &MenuConfig::ShowLineToEnemy);
				ImGui::SameLine();
				ImGui::ColorEdit4("##LineToEnemyColor", reinterpret_cast<float*>(&MenuConfig::LineToEnemyColor), ImGuiColorEditFlags_NoInputs);
				ImGui::SameLine();
				ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
				ImGui::Combo(Lang::ESPtext.LinePosList, &MenuConfig::LinePos, "Top\0Center\0Bottom\0");
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
				Gui.MyCheckBox(Lang::Global.SwitchButton, &MenuConfig::Misc.Glow);
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

				Gui.MyCheckBox(Lang::Global.SwitchButton, &MenuConfig::Radar.ShowRadar);
				ImGui::SetNextItemWidth(MenuConfig::ComboWidth + 20);
				ImGui::Combo(Lang::RadarText.StyleList, &MenuConfig::Radar.RadarType, "Circle\0Arrow\0Circle & Arrow\0");
				ImGui::Checkbox(Lang::RadarText.CustomCheck, &MenuConfig::Radar.customRadar);

				if (MenuConfig::Radar.customRadar)
				{
					ImGui::NewLine();
					ImGui::Checkbox(Lang::RadarText.CrossLine, &MenuConfig::Radar.ShowRadarCrossLine);
					ImGui::SameLine();
					ImGui::ColorEdit4("##CrossLineColor", reinterpret_cast<float*>(&MenuConfig::Radar.RadarCrossLineColor), ImGuiColorEditFlags_NoInputs);
					float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
					float ProportionMin = 500.f, ProportionMax = 3300.f;
					float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
					ImGui::SliderFloat(Lang::RadarText.SizeSlider, &MenuConfig::Radar.RadarPointSizeProportion, RadarPointSizeProportionMin, RadarPointSizeProportionMax, "%.1f");
					ImGui::SliderFloat(Lang::RadarText.ProportionSlider, &MenuConfig::Radar.Proportion, ProportionMin, ProportionMax, "%.1f");
					ImGui::SliderFloat(Lang::RadarText.RangeSlider, &MenuConfig::Radar.RadarRange, RadarRangeMin, RadarRangeMax, "%.1f");
					ImGui::SliderFloat(Lang::RadarText.AlphaSlider, &MenuConfig::Radar.RadarBgAlpha, 0.0f, 1.0f, "%.2f");
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

				Gui.MyCheckBox(Lang::Global.SwitchButton, &MenuConfig::Crosshairs.ShowCrossHair);

				ImGui::SetNextItemWidth(MenuConfig::ComboWidth + 50);
				if (ImGui::Combo(Lang::CrosshairsText.PresetList, &MenuConfig::Crosshairs.crosshairPreset, "Custom\0Dot\0Circle Dot 1\0Circle Dot 2\0Crosshair Small\0Crosshair Medium\0Crosshair Dot\0Square\0"))
					Render::UpdateCrosshairPreset(MenuConfig::Crosshairs.crosshairPreset);

				ImGui::Text(Lang::CrosshairsText.ColorEditor);
				ImGui::SameLine();
				ImGui::ColorEdit4("##CrossHairColor", reinterpret_cast<float*>(&MenuConfig::Crosshairs.CrossHairColor), ImGuiColorEditFlags_NoInputs);

				ImGui::Checkbox(Lang::CrosshairsText.Dot, &MenuConfig::Crosshairs.drawDot);
				if (MenuConfig::Crosshairs.drawDot)
				{
					ImGui::SliderFloat(Lang::CrosshairsText.DotSizeSlider, &MenuConfig::Crosshairs.DotSize, 1.f, 50.f, "%.f");
				}

				ImGui::Checkbox(Lang::CrosshairsText.Outline, &MenuConfig::Crosshairs.drawOutLine);
				ImGui::Checkbox(Lang::CrosshairsText.Crossline, &MenuConfig::Crosshairs.drawCrossline);
				if (MenuConfig::Crosshairs.drawCrossline)
				{
					ImGui::SliderInt(Lang::CrosshairsText.hLengthSlider, &MenuConfig::Crosshairs.HorizontalLength, 1, 100, "%d", ImGuiSliderFlags_NoInput);
					ImGui::SliderInt(Lang::CrosshairsText.vLengthSilder, &MenuConfig::Crosshairs.VerticalLength, 1, 100, "%d", ImGuiSliderFlags_NoInput);
					ImGui::SliderInt(Lang::CrosshairsText.GapSlider, &MenuConfig::Crosshairs.Gap, 1, 50, "%d", ImGuiSliderFlags_NoInput);
					//				ImGui::Checkbox("Dynamic Gap", &MenuConfig::Crosshairs.DynamicGap);
					ImGui::SliderInt(Lang::CrosshairsText.ThicknessSlider, &MenuConfig::Crosshairs.Thickness, 1, 20, "%d", ImGuiSliderFlags_NoInput);
					ImGui::Checkbox(Lang::CrosshairsText.tStyle, &MenuConfig::Crosshairs.tStyle);
				}

				ImGui::Separator();
				ImGui::Checkbox(Lang::CrosshairsText.Circle, &MenuConfig::Crosshairs.drawCircle);
				if (MenuConfig::Crosshairs.drawCircle)
					ImGui::SliderFloat(Lang::CrosshairsText.RadiusSlider, &MenuConfig::Crosshairs.CircleRadius, 0.0f, 50.0f, "%.1f", ImGuiSliderFlags_NoInput);

				ImGui::Separator();
				ImGui::Checkbox(Lang::CrosshairsText.TargetCheck, &MenuConfig::Crosshairs.showTargeting);
				ImGui::SameLine();
				ImGui::ColorEdit4("##CrosshairColor", reinterpret_cast<float*>(&MenuConfig::Crosshairs.TargetedColor), ImGuiColorEditFlags_NoInputs);
				ImGui::Checkbox(Lang::CrosshairsText.TeamCheck, &MenuConfig::Crosshairs.TeamCheck);

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
					"English\0Danish\0German\0Polish\0Portuguese\0Russian\0Simplified Chinese\0Slovak\0French\0Turkish\0Hungarian\0")) // Korean\0
					Lang::ChangeLang(MenuConfig::Language);
				if (ImGui::Combo(Lang::MiscText.ThemeList, &MenuConfig::MenuStyle, "Default\0Hacker\0Red\0Modern Dark\0Deep Dark\0Round Gray\0"))
					StyleChanger::UpdateSkin(MenuConfig::MenuStyle);
				// ImGui::Combo(Lang::MiscText.StyleList, &MenuConfig::WindowStyle, "Window\0");

				ImGui::Checkbox(Lang::MiscText.HeadshotLine, &MenuConfig::ShowHeadShootLine);
				ImGui::SameLine();
				ImGui::ColorEdit4("##HeadShootLineColor", reinterpret_cast<float*>(&MenuConfig::HeadShootLineColor), ImGuiColorEditFlags_NoInputs);
				ImGui::Checkbox(Lang::MiscText.SpecCheck, &MenuConfig::Misc.WorkInSpec);
				ImGui::Checkbox(Lang::MiscText.NoFlash, &MenuConfig::Misc.NoFlash);
				ImGui::Checkbox(Lang::MiscText.HitSound, &MenuConfig::Misc.HitSound);
				ImGui::Checkbox(Lang::MiscText.bmbTimer, &MenuConfig::Misc.bmbTimer);
				ImGui::SameLine();
				ImGui::ColorEdit4("##BombTimerCol", reinterpret_cast<float*>(&MenuConfig::Misc.BombTimerCol), ImGuiColorEditFlags_NoInputs);
				ImGui::Checkbox(Lang::MiscText.SpecList, &MenuConfig::Misc.SpecList);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
				{
					ImGui::SetTooltip("Broken");
				}
//				ImGui::Checkbox("Invincible", &MenuConfig::infinity);

				ImGui::NextColumn();
				ImGui::Checkbox(Lang::MiscText.Bhop, &MenuConfig::Misc.BunnyHop);
				if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
				{
					ImGui::SetTooltip("Bhop is currently unavailable as Valve fixes a bug that force jump");
				}
				ImGui::Checkbox(Lang::MiscText.Watermark, &MenuConfig::Misc.WaterMark);
				ImGui::Checkbox(Lang::MiscText.CheatList, &MenuConfig::Misc.CheatList);
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
				/*
				if (ImGui::IsItemHovered())
				{
					ImGui::SetTooltip("About.");
				}*/

				// Since it's already the MIT license, there's no need to do that.
				// ImGui::TextColored(ImColor(255, 0, 0, 255), "Reselling prohibited");

				ImGui::TextColored(ImColor(0, 200, 255, 255), Lang::ReadMeText.LastUpdate);
				ImGui::SameLine();
				ImGui::TextColored(ImColor(0, 200, 255, 255), "2023-11-19");
				sprintf_s(TempText, "%s%s", ICON_FA_COPY, Lang::ReadMeText.SourceButton);
				Gui.OpenWebpageButton(TempText, "https://github.com/CowNowK/AimStar");
				ImGui::SameLine();
				sprintf_s(TempText, "%s%s", ICON_FA_COMMENT_DOTS, Lang::ReadMeText.DiscordButton);
				Gui.OpenWebpageButton(TempText, "https://discord.gg/rsqmbc7Tz3");
				ImGui::NewLine();

				ImGui::Text(Lang::ReadMeText.OffsetsTitle);
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

				ImGui::EndTabItem();
			}

		}ImGui::End();
	}
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
				ImGui::Checkbox("Enabled", &MenuConfig::ShowRadar);
				ImGui::SetNextItemWidth(MenuConfig::ComboWidth + 20);
				ImGui::Combo("Style", &MenuConfig::RadarType, "Circle\0Arrow\0Circle & Arrow\0");
				ImGui::Checkbox("Custom", &MenuConfig::customRadar);

				if (MenuConfig::customRadar)
				{
					ImGui::NewLine();
					ImGui::Checkbox("Cross Line", &MenuConfig::ShowRadarCrossLine);
					float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
					float ProportionMin = 500.f, ProportionMax = 3300.f;
					float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
					ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
					ImGui::SliderFloat("PointSize", &MenuConfig::RadarPointSizeProportion, RadarPointSizeProportionMin, RadarPointSizeProportionMax, "%.1f", ImGuiColorEditFlags_NoInputs);
					ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
					ImGui::SliderFloat("Proportion", &MenuConfig::Proportion, ProportionMin, ProportionMax, "%.1f", ImGuiColorEditFlags_NoInputs);
					ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
					ImGui::SliderFloat("Range", &MenuConfig::RadarRange, RadarRangeMin, RadarRangeMax, "%.1f", ImGuiColorEditFlags_NoInputs);
					ImGui::SetNextItemWidth(MenuConfig::SliderWidth);
					ImGui::SliderFloat("Backgroud Alpha", &MenuConfig::RadarBgAlpha, 0.0f, 1.0f, "%.2f", ImGuiColorEditFlags_NoInputs);
				}
			}

			if (ImGui::CollapsingHeader("Glow"))
			{
				Gui.MyCheckBox("Enabled", &MenuConfig::Glow);
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
			ImGui::Checkbox("Cheat In Spec", &MenuConfig::WorkInSpec);
			ImGui::Checkbox("No Flash", &MenuConfig::NoFlash);
			ImGui::Checkbox("Watermark", &MenuConfig::WaterMark);
			ImGui::Checkbox("Cheat List", &MenuConfig::CheatList);
			ImGui::Checkbox("HitSound", &MenuConfig::HitSound);
			ImGui::Checkbox("Bunny Hop", &MenuConfig::BunnyHop);
			ImGui::Checkbox("Bomb Timer", &MenuConfig::bmbTimer);
			ImGui::SameLine();
			ImGui::ColorEdit4("##BombTimerCol", reinterpret_cast<float*>(&MenuConfig::BombTimerCol), ImGuiColorEditFlags_NoInputs);
			ImGui::Checkbox("Spectator List", &MenuConfig::SpecList);
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
				ImGui::ColorEdit4("Cross Line", reinterpret_cast<float*>(&MenuConfig::RadarCrossLineColor), ImGuiColorEditFlags_NoInputs);
				ImGui::SeparatorText("Crosshairs");
				ImGui::ColorEdit4("Untarget", reinterpret_cast<float*>(&CrosshairConfig::CrossHairColor), ImGuiColorEditFlags_NoInputs);
				ImGui::ColorEdit4("Targeting", reinterpret_cast<float*>(&CrosshairConfig::TargetedColor), ImGuiColorEditFlags_NoInputs);
				ImGui::SeparatorText("Window Style");
				ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
				if (ImGui::Combo("Theme", &MenuConfig::MenuStyle, "Default\0Hacker\0Red\0Modern Dark\0Deep Dark\0Round Gray\0Square Dark\0"))
					StyleChanger::UpdateSkin(MenuConfig::MenuStyle);
				ImGui::SetNextItemWidth(MenuConfig::ComboWidth);
				ImGui::Combo("Style", &MenuConfig::WindowStyle, "Window\0Collapse\0");
				ImGui::EndTabItem();
			} 
//			ConfigMenu::RenderConfigMenu();

		} ImGui::End();
	}
}