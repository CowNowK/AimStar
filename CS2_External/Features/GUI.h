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
#include "..\Resources\Images.h"

ID3D11ShaderResourceView* AS_Logo = NULL;
ID3D11ShaderResourceView* MenuButton1 = NULL;
ID3D11ShaderResourceView* MenuButton2 = NULL;
ID3D11ShaderResourceView* MenuButton3 = NULL;
ID3D11ShaderResourceView* MenuButton4 = NULL;
int LogoW = 0;
int LogoH = 0;
int buttonW = 0;
int buttonH = 0;

namespace GUI
{
	void LoadImages()
	{
		Gui.LoadTextureFromMemory(Images::AS_Logo, sizeof Images::AS_Logo, &AS_Logo, &LogoW, &LogoH);
		Gui.LoadTextureFromMemory(Images::VisualButton, sizeof Images::VisualButton, &MenuButton1, &buttonW, &buttonH);
		Gui.LoadTextureFromMemory(Images::AimbotButton, sizeof Images::AimbotButton, &MenuButton2, &buttonW, &buttonH);
		Gui.LoadTextureFromMemory(Images::MiscButton, sizeof Images::MiscButton, &MenuButton3, &buttonW, &buttonH);
		Gui.LoadTextureFromMemory(Images::ConfigButton, sizeof Images::ConfigButton, &MenuButton4, &buttonW, &buttonH);
	}

	// Components Settings
	// ########################################
	void AlignRight(float ContentWidth)
	{
		float ColumnContentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x;
		float checkboxPosX = ImGui::GetColumnOffset() + ColumnContentWidth - ContentWidth;
		ImGui::SetCursorPosX(checkboxPosX);
	}
	void PutSwitch(const char* string, float CursorX, float ContentWidth, bool* v, bool ColorEditor = false, const char* lable = NULL, float col[4] = NULL)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		ImGui::SameLine();
		if (ColorEditor) {
			AlignRight(ContentWidth + ImGui::GetFrameHeight() + 8);
			ImGui::ColorEdit4(lable, col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
			ImGui::SameLine();
		}
		else {
			AlignRight(ContentWidth);
		}
		
		Gui.SwitchButton(string, v);
		ImGui::PopID();
	}
	void PutSliderFloat(const char* string, float CursorX, float* v, const void* p_min, const void* p_max, const char* format)
	{
		// if there is no fucking ID, all the sliders would be fucking forced to sync when you click on one of them ;3
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		float SliderWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX;
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		ImGui::SameLine();
		ImGui::TextDisabled(format, *v);
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::SetNextItemWidth(SliderWidth);
		Gui.SliderScalarEx2("", ImGuiDataType_Float, v, p_min, p_max, "", ImGuiSliderFlags_None);
		ImGui::PopID();
	}
	void PutSliderInt(const char* string, float CursorX, int* v, const void* p_min, const void* p_max, const char* format)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		float SliderWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - CursorX;
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		ImGui::SameLine();
		ImGui::TextDisabled(format, *v);
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::SetNextItemWidth(SliderWidth);
		Gui.SliderScalarEx2("", ImGuiDataType_Float, v, p_min, p_max, "", ImGuiSliderFlags_None);
		ImGui::PopID();
	}
	// ########################################

	void NewGui()
	{
		LoadImages();

		char TempText[256];
		ImGuiWindowFlags Flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
		ImGui::SetNextWindowPos({ (ImGui::GetIO().DisplaySize.x - 851.0f) / 2.0f, (ImGui::GetIO().DisplaySize.y - 514.0f) / 2.0f }, ImGuiCond_Once);
		ImGui::SetNextWindowSize({ 851,514 });
		ImGui::Begin("AimStar Test", nullptr, Flags);
		{
			ImGui::SetCursorPos(MenuConfig::WCS.LogoPos);
			ImGui::Image((void*)AS_Logo, ImVec2(LogoW, LogoH));

			ImGui::SetCursorPos(MenuConfig::WCS.Button1Pos);
			ImGui::Image((void*)MenuButton1, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 0;
			}
			ImGui::SetCursorPos(MenuConfig::WCS.Button2Pos);
			ImGui::Image((void*)MenuButton2, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 1;
			}
			ImGui::SetCursorPos(MenuConfig::WCS.Button3Pos);
			ImGui::Image((void*)MenuButton3, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 2;
			}
			ImGui::SetCursorPos(MenuConfig::WCS.Button4Pos);
			ImGui::Image((void*)MenuButton4, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 3;
			}

			ImGui::SetCursorPos(MenuConfig::WCS.ChildPos);
			
			ImGui::BeginChild("Page", MenuConfig::WCS.ChildSize);
			{
				if (MenuConfig::WCS.MenuPage == 0)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText("ESP");
					float MinRounding = 0.f, MaxRouding = 15.f;
					PutSwitch("Box", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowBoxESP, true, "###BoxCol", reinterpret_cast<float*>(&ESPConfig::BoxColor));
					PutSliderFloat("Box Rounding:", 10.f, &ESPConfig::BoxRounding, &MinRounding, &MaxRouding, "%1.f");
					PutSwitch("Filled Box", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::FilledBox, true, "###HeadBoxCol", reinterpret_cast<float*>(&ESPConfig::FilledColor));
					PutSwitch("Head Box", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowHeadBox, true, "###HeadBoxCol", reinterpret_cast<float*>(&ESPConfig::HeadBoxColor));
					PutSwitch("Skeleton", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowBoneESP, true, "###BoneCol", reinterpret_cast<float*>(&ESPConfig::BoneColor));
					PutSwitch("Snap Line", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::ShowLineToEnemy, true, "###LineCol", reinterpret_cast<float*>(&MenuConfig::LineToEnemyColor));
					PutSwitch("Eye Ray", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowEyeRay, true, "###LineCol", reinterpret_cast<float*>(&ESPConfig::EyeRayColor));
					PutSwitch("Health", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowHealthBar);
					PutSwitch("Weapon", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowWeaponESP);
					PutSwitch("Distance", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowDistance);
					PutSwitch("Player Name", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowPlayerName);
					
					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText("Radar");
					float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
					float ProportionMin = 500.f, ProportionMax = 3300.f;
					float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
					float AlphaMin = 0.f, AlphaMax = 1.f;
					PutSwitch("Show Radar", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Radar.ShowRadar);
					if (MenuConfig::Radar.ShowRadar)
					{
						PutSwitch("Custom", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Radar.customRadar);
						if (MenuConfig::Radar.customRadar)
						{
							PutSliderFloat("Point Size:", 5.f, &MenuConfig::Radar.RadarPointSizeProportion, &RadarPointSizeProportionMin, &RadarPointSizeProportionMax, "%1.f");
							PutSliderFloat("Proportion:", 5.f, &MenuConfig::Radar.Proportion, &ProportionMin, &ProportionMax, "%1.f");
							PutSliderFloat("Radar Range:", 5.f, &MenuConfig::Radar.RadarRange, &RadarRangeMin, &RadarRangeMax, "%1.f");
							PutSliderFloat("Window Alpha:", 5.f, &MenuConfig::Radar.RadarBgAlpha, &AlphaMin, &AlphaMax, "%1.f");
						}
					}
					
					ImGui::NewLine();
					ImGui::SeparatorText("Crosshairs");
					float DotMin = 1.f, DotMax = 50.f;
					int LengthMin = 1, LengthMax = 100;
					int GapMin = 1, GapMax = 50;
					int ThickMin = 1, ThickMax = 20;
					float CircleRmin = 1.f, CircleRmax = 50.f;
					PutSwitch("Show Crosshais", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.ShowCrossHair, true, "###CrosshairsCol", reinterpret_cast<float*>(&MenuConfig::Crosshairs.CrossHairColor));
					if (MenuConfig::Crosshairs.ShowCrossHair)
					{
						PutSwitch("Center Dot", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.drawDot);
						if (MenuConfig::Crosshairs.drawDot)
							PutSliderFloat("Dot Size:", 5.f, &MenuConfig::Crosshairs.DotSize, &DotMin, &DotMax, "%1.f px");
						PutSwitch("Outline", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.drawOutLine);
						PutSwitch("Cross line", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.drawCrossline);
						if (MenuConfig::Crosshairs.drawCrossline)
						{
							PutSliderInt("Horizontal Length:", 5.f, &MenuConfig::Crosshairs.HorizontalLength, &LengthMin, &LengthMax, "%d px");
							PutSliderInt("Vertical Length:", 5.f, &MenuConfig::Crosshairs.VerticalLength, &LengthMin, &LengthMax, "%d px");
							PutSliderInt("Gap:", 5.f, &MenuConfig::Crosshairs.Gap, &GapMin, &GapMax, "%d px");
							PutSliderInt("Thickness:", 5.f, &MenuConfig::Crosshairs.Thickness, &ThickMin, &ThickMax, "%d px");
						}
						PutSwitch("T Style", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.tStyle);
						PutSwitch("Circle", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.drawCircle);
						if (MenuConfig::Crosshairs.drawCircle)
							PutSliderFloat("Circle Radius:", 5.f, &MenuConfig::Crosshairs.CircleRadius, &CircleRmin, &CircleRmax, "%.f px");
						PutSwitch("Targeting Crosshairs", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.showTargeting, true, "###CircleCol", reinterpret_cast<float*>(&MenuConfig::Crosshairs.TargetedColor));
						PutSwitch("Team Check", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Crosshairs.TeamCheck);
					}
					
					ImGui::Columns(1);
				}
				
				if (MenuConfig::WCS.MenuPage == 1)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText("Aimbot");
					float FovMin = 0.f, FovMax = 25.f;
					float SmoothMin = 0.f, SmoothMax = 5.f;
					PutSwitch("Aimbot", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::AimBot);
					if (MenuConfig::AimBot)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled("Hotkey   ");
						ImGui::SameLine();
						if (ImGui::Combo("###AimKey", &MenuConfig::AimBotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
						{
							AimControl::SetHotKey(MenuConfig::AimBotHotKey);
						}
						PutSwitch("Toggle Mode", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::AimToggleMode);
						PutSwitch("Draw FOV", 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::DrawFov, true, "###FOVcol", reinterpret_cast<float*>(&MenuConfig::FovCircleColor));
						PutSwitch("Visible Only", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::VisibleCheck);
						PutSliderFloat("FOV:", 10.f, &AimControl::AimFov, &FovMin, &FovMax, "%1.f");
						PutSliderFloat("Smooth:", 10.f, &AimControl::Smooth, &SmoothMin, &SmoothMax, "%1.f");
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled("Bone       ");
						ImGui::SameLine();
						if (ImGui::Combo("###AimPos", &MenuConfig::AimPosition, "Head\0Neck\0Chest\0Penis\0"))
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
					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText("RCS");
					PutSwitch("Enable RCS", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::RCS);

					ImGui::Columns(1);
				}

				if (MenuConfig::WCS.MenuPage == 2)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText("Misc");

					PutSwitch("Headshot Line", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::ShowHeadShootLine);
					PutSwitch("Cheat in Spec", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Misc.WorkInSpec);
					PutSwitch("No Flash", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Misc.NoFlash);
					PutSwitch("Hit Sound", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Misc.HitSound);
					PutSwitch("Bomb Timer", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Misc.bmbTimer, true, "###bmbTimerCol", reinterpret_cast<float*>(&MenuConfig::Misc.BombTimerCol));
					PutSwitch("Bunny Hop", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Misc.BunnyHop);
					PutSwitch("Watermark", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Misc.WaterMark);
					PutSwitch("Cheat list", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::Misc.CheatList);
					PutSwitch("Team Check", 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TeamCheck);

					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText("Menu Settings");
					PutSwitch("Anti Record", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::BypassOBS);
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					ImGui::TextDisabled("Style");
					ImGui::SameLine();
					ImGui::Combo("", &MenuConfig::WindowStyle, "Osiris\0AimStar\0");
					

					ImGui::Columns(1);
				}

				if (MenuConfig::WCS.MenuPage == 3)
				{
					ImGui::Columns(2, nullptr, false);
					ConfigMenu::RenderCFGmenu();

					ImGui::Columns(1);
				}

			} ImGui::EndChild();
		} ImGui::End();
	}

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
				Gui.MyCheckBox(Lang::Global.SwitchButton, &MenuConfig::Glow);
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
				if (ImGui::Combo(Lang::MiscText.ThemeList, &MenuConfig::MenuStyle, "AimStar\0Enemy\0Hacker\0Red\0Modern Dark\0Deep Dark\0Round Gray\0"))
					StyleChanger::UpdateSkin(MenuConfig::MenuStyle);
				if (ImGui::Combo(Lang::MiscText.StyleList, &MenuConfig::WindowStyle, "Osiris\0AimStar\0"))
					if (MenuConfig::WindowStyle)
						StyleChanger::UpdateSkin(0);

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
				ImGui::TextColored(ImColor(0, 200, 255, 255), "2023-12-9");
				sprintf_s(TempText, "%s%s", ICON_FA_COPY, Lang::ReadMeText.SourceButton);
				Gui.OpenWebpageButton(TempText, "https://github.com/CowNowK/AimStar");
				ImGui::SameLine();
				sprintf_s(TempText, "%s%s", ICON_FA_COMMENT_DOTS, Lang::ReadMeText.DiscordButton);
				Gui.OpenWebpageButton(TempText, "https://discord.com/invite/VgRrxwesPz");
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
}