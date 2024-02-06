#pragma once
#include "..\MenuConfig.hpp"
#include "..\Render.hpp"
#include "..\AimBot.hpp"
#include "..\Radar\Radar.h"
#include "..\TriggerBot.h"
#include "..\Utils\ConfigMenu.hpp"
#include "..\Utils\ConfigSaver.hpp"
#include "..\Utils\Updater.h"

#include "StyleChanger.h"
#include "..\Resources\Language.h"
#include "..\Resources\Images.h"

ID3D11ShaderResourceView* AS_Logo = NULL;
ID3D11ShaderResourceView* NL_Logo = NULL;
ID3D11ShaderResourceView* MenuButton1 = NULL;
ID3D11ShaderResourceView* MenuButton2 = NULL;
ID3D11ShaderResourceView* MenuButton3 = NULL;
ID3D11ShaderResourceView* MenuButton4 = NULL;
int LogoW = 0, LogoH = 0;
int LogoW2 = 0, LogoH2 = 0;
int buttonW = 0;
int buttonH = 0;

namespace GUI
{
	void LoadImages()
	{
		if (AS_Logo == NULL)
		{
			// Updater::CheckForUpdates();
			Gui.LoadTextureFromMemory(Images::AS_Logo, sizeof Images::AS_Logo, &AS_Logo, &LogoW, &LogoH);
			Gui.LoadTextureFromMemory(Images::NL_Logo, sizeof Images::NL_Logo, &NL_Logo, &LogoW2, &LogoH2);
			Gui.LoadTextureFromMemory(Images::VisualButton, sizeof Images::VisualButton, &MenuButton1, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::AimbotButton, sizeof Images::AimbotButton, &MenuButton2, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::MiscButton, sizeof Images::MiscButton, &MenuButton3, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::ConfigButton, sizeof Images::ConfigButton, &MenuButton4, &buttonW, &buttonH);
		}
	}

	// Components Settings
	// ########################################
	void AlignRight(float ContentWidth)
	{
		float ColumnContentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x;
		float checkboxPosX = ImGui::GetColumnOffset() + ColumnContentWidth - ContentWidth;
		ImGui::SetCursorPosX(checkboxPosX);
	}
	void PutSwitch(const char* string, float CursorX, float ContentWidth, bool* v, bool ColorEditor = false, const char* lable = NULL, float col[4] = NULL, const char* Tip = NULL)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		if (Tip && ImGui::IsItemHovered())
			ImGui::SetTooltip(Tip);
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
	void PutColorEditor(const char* text, const char* lable, float CursorX, float ContentWidth, float col[4], const char* Tip = NULL)
	{
		ImGui::PushID(text);
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(text);
		if (Tip && ImGui::IsItemHovered())
			ImGui::SetTooltip(Tip);
		ImGui::SameLine();
		AlignRight(ContentWidth + ImGui::GetFrameHeight() + 8);
		ImGui::ColorEdit4(lable, col, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_AlphaPreview);
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
		ImTextureID ImageID;
		ImVec2 LogoSize, LogoPos;
		switch (MenuConfig::Theme)
		{
		case 0:
			ImageID = (void*)AS_Logo;
			LogoSize = ImVec2(LogoW, LogoH);
			LogoPos = MenuConfig::WCS.LogoPos;
			MenuConfig::ButtonBorderColor = MenuConfig::WCS.BorderColor_Yellow;
			break;
		case 1:
			ImageID = (void*)NL_Logo;
			LogoSize = ImVec2(LogoW2, LogoH2);
			LogoPos = MenuConfig::WCS.Logo2Pos;
			MenuConfig::ButtonBorderColor = MenuConfig::WCS.BorderColor_Purple;
			break;
		case 2:
			ImageID = (void*)AS_Logo;
			LogoSize = ImVec2(LogoW, LogoH);
			LogoPos = MenuConfig::WCS.LogoPos;
			MenuConfig::ButtonBorderColor = MenuConfig::ButtonBorderColor;
			break;
		default:
			ImageID = (void*)AS_Logo;
			LogoSize = ImVec2(LogoW, LogoH);
			LogoPos = MenuConfig::WCS.LogoPos;
			MenuConfig::ButtonBorderColor = MenuConfig::WCS.BorderColor_Yellow;
			break;
		}
		ImColor BorderColor = MenuConfig::ButtonBorderColor;

		char TempText[256];
		ImGuiWindowFlags Flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
		ImGui::SetNextWindowPos({ (ImGui::GetIO().DisplaySize.x - 851.0f) / 2.0f, (ImGui::GetIO().DisplaySize.y - 514.0f) / 2.0f }, ImGuiCond_Once);
		ImGui::SetNextWindowSize({ 851,514 });
		ImGui::Begin("AimStar", nullptr, Flags);
		{
			ImGui::SetCursorPos(LogoPos);
			ImGui::Image(ImageID, LogoSize);

			ImGui::SetCursorPos(MenuConfig::WCS.Button1Pos);
			ImGui::Image((void*)MenuButton1, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 0;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(MenuConfig::WCS.Button1Pos.x + ImGui::GetWindowPos().x, MenuConfig::WCS.Button1Pos.y + ImGui::GetWindowPos().y), 
				ImVec2(MenuConfig::WCS.Button1Pos.x + buttonW + ImGui::GetWindowPos().x, MenuConfig::WCS.Button1Pos.y + buttonH + ImGui::GetWindowPos().y), 
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);
			
			ImGui::SetCursorPos(MenuConfig::WCS.Button2Pos);
			ImGui::Image((void*)MenuButton2, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 1;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(MenuConfig::WCS.Button2Pos.x + ImGui::GetWindowPos().x, MenuConfig::WCS.Button2Pos.y + ImGui::GetWindowPos().y),
				ImVec2(MenuConfig::WCS.Button2Pos.x + buttonW + ImGui::GetWindowPos().x, MenuConfig::WCS.Button2Pos.y + buttonH + ImGui::GetWindowPos().y),
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

			ImGui::SetCursorPos(MenuConfig::WCS.Button3Pos);
			ImGui::Image((void*)MenuButton3, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 2;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(MenuConfig::WCS.Button3Pos.x + ImGui::GetWindowPos().x, MenuConfig::WCS.Button3Pos.y + ImGui::GetWindowPos().y),
				ImVec2(MenuConfig::WCS.Button3Pos.x + buttonW + ImGui::GetWindowPos().x, MenuConfig::WCS.Button3Pos.y + buttonH + ImGui::GetWindowPos().y),
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

			ImGui::SetCursorPos(MenuConfig::WCS.Button4Pos);
			ImGui::Image((void*)MenuButton4, ImVec2(buttonW, buttonH));
			if (ImGui::IsItemClicked()) {
				MenuConfig::WCS.MenuPage = 3;
			}
			ImGui::GetWindowDrawList()->AddRect(
				ImVec2(MenuConfig::WCS.Button4Pos.x + ImGui::GetWindowPos().x, MenuConfig::WCS.Button4Pos.y + ImGui::GetWindowPos().y),
				ImVec2(MenuConfig::WCS.Button4Pos.x + buttonW + ImGui::GetWindowPos().x, MenuConfig::WCS.Button4Pos.y + buttonH + ImGui::GetWindowPos().y),
				BorderColor, 9.f, ImDrawFlags_RoundCornersAll, 2.f);

			ImGui::SetCursorPos(MenuConfig::WCS.ChildPos);
			
			ImGui::BeginChild("Page", MenuConfig::WCS.ChildSize);
			{
				if (MenuConfig::WCS.MenuPage == 0)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(ICON_FA_EYE" ESP");
					float MinRounding = 0.f, MaxRouding = 5.f;
					int MinCombo = 0, MaxCombo = 2;
					PutSwitch(Lang::ESPtext.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ESPenabled);
					if (ESPConfig::ESPenabled)
					{
						const char* BoxTypes[] = { Lang::ESPtext.BoxType_Normal, Lang::ESPtext.BoxType_Edge, Lang::ESPtext.BoxType_Corner };
						const char* LinePos[] = { Lang::ESPtext.LinePos_1, Lang::ESPtext.LinePos_2, Lang::ESPtext.LinePos_3 };
						PutSwitch(Lang::ESPtext.Box, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowBoxESP, true, "###BoxCol", reinterpret_cast<float*>(&ESPConfig::BoxColor));
						if (ESPConfig::ShowBoxESP)
						{
							PutSwitch(Lang::ESPtext.Outline, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::OutLine);
							PutSliderInt(Lang::ESPtext.BoxType, 10.f, &MenuConfig::BoxType, &MinCombo, &MaxCombo, BoxTypes[MenuConfig::BoxType]);
							PutSliderFloat(Lang::ESPtext.BoxRounding, 10.f, &ESPConfig::BoxRounding, &MinRounding, &MaxRouding, "%.1f");
						}
						PutSwitch(Lang::ESPtext.FilledBox, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::FilledBox, true, "###FilledBoxCol", reinterpret_cast<float*>(&ESPConfig::FilledColor));
						if (ESPConfig::FilledBox)
							PutSwitch(Lang::ESPtext.MultiColor, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::MultiColor, true, "###MultiCol", reinterpret_cast<float*>(&ESPConfig::FilledColor2));
						PutSwitch(Lang::ESPtext.HeadBox, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowHeadBox, true, "###HeadBoxCol", reinterpret_cast<float*>(&ESPConfig::HeadBoxColor));
						PutSwitch(Lang::ESPtext.Skeleton, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowBoneESP, true, "###BoneCol", reinterpret_cast<float*>(&ESPConfig::BoneColor));
						PutSwitch(Lang::ESPtext.SnapLine, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowLineToEnemy, true, "###LineCol", reinterpret_cast<float*>(&ESPConfig::LineToEnemyColor));
						if (ESPConfig::ShowLineToEnemy)
							PutSliderInt(Lang::ESPtext.LinePosList, 10.f, &ESPConfig::LinePos, &MinCombo, &MaxCombo, LinePos[ESPConfig::LinePos]);
						PutSwitch(Lang::ESPtext.EyeRay, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowEyeRay, true, "###LineCol", reinterpret_cast<float*>(&ESPConfig::EyeRayColor));
						PutSwitch(Lang::ESPtext.HealthBar, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowHealthBar);
						PutSwitch(Lang::ESPtext.HealthNum, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowHealthNum);
						PutSwitch(Lang::ESPtext.Weapon, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowWeaponESP);
						PutSwitch(Lang::ESPtext.Ammo, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::AmmoBar);
						PutSwitch(Lang::ESPtext.Distance, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowDistance);
						PutSwitch(Lang::ESPtext.PlayerName, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowPlayerName);
						PutSwitch(Lang::ESPtext.ScopedESP, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowIsScoped);
						PutSwitch(Lang::ESPtext.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::VisibleCheck, true, "###VisibleCol", reinterpret_cast<float*>(&ESPConfig::VisibleColor));
					}
					
					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(ICON_FA_GRIN_ALT " ESP Preview");
					// ESP::RenderPreview({ ImGui::GetColumnWidth(), ImGui::GetCursorPosY() }, { ImGui::GetCursorPosX() - ImGui::GetColumnWidth() * 0.65f, ImGui::GetCursorPosY() - ImGui::GetFrameHeight() });
					ESP::RenderPreview({ ImGui::GetColumnWidth(), ImGui::GetCursorPosY() });
					// :P
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					ImGui::NewLine();
					//

					ImGui::SeparatorText(ICON_FA_COMPASS" External Radar");
					float RadarPointSizeProportionMin = 0.8f, RadarPointSizeProportionMax = 2.f;
					float ProportionMin = 500.f, ProportionMax = 3300.f;
					float RadarRangeMin = 100.f, RadarRangeMax = 300.f;
					float AlphaMin = 0.f, AlphaMax = 1.f;
					PutSwitch(Lang::RadarText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &RadarCFG::ShowRadar);
					if (RadarCFG::ShowRadar)
					{
						PutSwitch(Lang::RadarText.CustomCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &RadarCFG::customRadar);
						if (RadarCFG::customRadar)
						{
							PutSliderFloat(Lang::RadarText.SizeSlider, 5.f, &RadarCFG::RadarPointSizeProportion, &RadarPointSizeProportionMin, &RadarPointSizeProportionMax, "%1.f");
							PutSliderFloat(Lang::RadarText.ProportionSlider, 5.f, &RadarCFG::Proportion, &ProportionMin, &ProportionMax, "%.1f");
							PutSliderFloat(Lang::RadarText.RangeSlider, 5.f, &RadarCFG::RadarRange, &RadarRangeMin, &RadarRangeMax, "%.1f");
							PutSliderFloat(Lang::RadarText.AlphaSlider, 5.f, &RadarCFG::RadarBgAlpha, &AlphaMin, &AlphaMax, "%.1f");
						}
					}
					
					ImGui::NewLine();
					ImGui::SeparatorText(ICON_FA_DOT_CIRCLE" Crosshairs");
					float DotMin = 1.f, DotMax = 50.f;
					int LengthMin = 1, LengthMax = 100;
					int GapMin = 1, GapMax = 50;
					int ThickMin = 1, ThickMax = 20;
					float CircleRmin = 1.f, CircleRmax = 50.f;
					PutSwitch(Lang::CrosshairsText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::ShowCrossHair, true, "###CrosshairsCol", reinterpret_cast<float*>(&CrosshairsCFG::CrossHairColor));
					if (CrosshairsCFG::ShowCrossHair)
					{
						PutSwitch(Lang::CrosshairsText.Dot, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::drawDot);
						if (CrosshairsCFG::drawDot)
							PutSliderFloat(Lang::CrosshairsText.DotSizeSlider, 5.f, &CrosshairsCFG::DotSize, &DotMin, &DotMax, "%.f px");
						PutSwitch(Lang::CrosshairsText.Outline, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::drawOutLine);
						PutSwitch(Lang::CrosshairsText.Crossline, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::drawCrossline);
						if (CrosshairsCFG::drawCrossline)
						{
							PutSliderInt(Lang::CrosshairsText.hLengthSlider, 5.f, &CrosshairsCFG::HorizontalLength, &LengthMin, &LengthMax, "%d px");
							PutSliderInt(Lang::CrosshairsText.vLengthSilder, 5.f, &CrosshairsCFG::VerticalLength, &LengthMin, &LengthMax, "%d px");
							PutSliderInt(Lang::CrosshairsText.GapSlider, 5.f, &CrosshairsCFG::Gap, &GapMin, &GapMax, "%d px");
							PutSliderInt(Lang::CrosshairsText.ThicknessSlider, 5.f, &CrosshairsCFG::Thickness, &ThickMin, &ThickMax, "%d px");
						}
						PutSwitch(Lang::CrosshairsText.tStyle, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::tStyle);
						PutSwitch(Lang::CrosshairsText.Circle, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::drawCircle);
						if (CrosshairsCFG::drawCircle)
							PutSliderFloat(Lang::CrosshairsText.RadiusSlider, 5.f, &CrosshairsCFG::CircleRadius, &CircleRmin, &CircleRmax, "%.f px");
						PutSwitch(Lang::CrosshairsText.TargetCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TargetingCrosshairs, true, "###CircleCol", reinterpret_cast<float*>(&CrosshairsCFG::TargetedColor));
						PutSwitch(Lang::CrosshairsText.TeamCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::TeamCheck);
					}
					
					ImGui::Columns(1);
				}
				
				if (MenuConfig::WCS.MenuPage == 1)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(ICON_FA_USER" Aimbot");
					float FovMin = 0.f, FovMax = 25.f;
					float SmoothMin = 0.f, SmoothMax = 5.f;
					PutSwitch(Lang::AimbotText.Enable, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::AimBot);
					if (MenuConfig::AimBot)
					{
						if (!MenuConfig::AimAlways)
						{
							ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
							ImGui::TextDisabled(Lang::AimbotText.HotKeyList);
							ImGui::SameLine();
							if (ImGui::Combo("###AimKey", &MenuConfig::AimBotHotKey, "LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
							{
								AimControl::SetHotKey(MenuConfig::AimBotHotKey);
							}
							PutSwitch(Lang::AimbotText.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::AimToggleMode);
						}
						PutSwitch(Lang::AimbotText.AimLock, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::AimAlways);
						PutSwitch(Lang::AimbotText.DrawFov, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::DrawFov, true, "###FOVcol", reinterpret_cast<float*>(&MenuConfig::FovCircleColor));
						PutSwitch(Lang::AimbotText.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::VisibleCheck);
						PutSwitch(Lang::AimbotText.ScopeOnly, 10.f, ImGui::GetFrameHeight() * 1.7, &AimControl::ScopeOnly);
						PutSliderFloat(Lang::AimbotText.FovSlider, 10.f, &AimControl::AimFov, &FovMin, &FovMax, "%.1f");
						PutSliderFloat(Lang::AimbotText.SmoothSlider, 10.f, &AimControl::Smooth, &SmoothMin, &SmoothMax, "%.1f");
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled(Lang::AimbotText.BoneList);
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
					ImGui::SeparatorText(ICON_FA_ARROW_ALT_CIRCLE_DOWN " RCS");
					PutSwitch("Enable RCS", 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::RCS);

					ImGui::NewLine();
					ImGui::SeparatorText(ICON_FA_HAND_POINTER" Triggerbot");
					int DelayMin = 10, DelayMax = 1000;
					int DurationMin = 0, DurationMax = 1000;
					PutSwitch(Lang::TriggerText.Enable, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TriggerBot);
					if (MenuConfig::TriggerBot)
					{
						if (!MenuConfig::TriggerAlways)
						{
							ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
							ImGui::TextDisabled(Lang::TriggerText.HotKeyList);
							ImGui::SameLine();
							if (ImGui::Combo("###TriggerbotKey", &MenuConfig::TriggerHotKey, "LALT\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0"))
							{
								TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
							}
						}
						PutSwitch(Lang::TriggerText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TriggerAlways);
						PutSliderInt(Lang::TriggerText.DelaySlider, 5.f, &TriggerBot::TriggerDelay, &DelayMin, &DelayMax, "%d ms");
						PutSliderInt(Lang::TriggerText.FakeShotSlider, 5.f, &TriggerBot::FakeShotDelay, &DurationMin, &DurationMax, "%d ms");
					}

					ImGui::Columns(1);
				}

				if (MenuConfig::WCS.MenuPage == 2)
				{
					int FovMin = 60, FovMax = 140;
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(ICON_FA_SUN" Misc");

					PutSwitch(Lang::MiscText.HeadshotLine, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::ShowHeadShootLine);
					PutSwitch(Lang::MiscText.SpecCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::WorkInSpec);
					PutSliderInt(Lang::MiscText.fovchanger, 10.f, &MiscCFG::Fov , &FovMin, &FovMax, "%d");
					PutSwitch(Lang::MiscText.NoFlash, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::NoFlash);
					PutSwitch(Lang::MiscText.FastStop, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::FastStop);
					PutSwitch(Lang::MiscText.NoSmoke, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::NoSmoke);
					PutSwitch(Lang::MiscText.SmokeColor, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::SmokeColored, true, "###SmokeColor", reinterpret_cast<float*>(&MiscCFG::SmokeColor));
					PutSwitch(Lang::MiscText.HitSound, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::HitSound);
					PutSwitch(Lang::MiscText.bmbTimer, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::bmbTimer, true, "###bmbTimerCol", reinterpret_cast<float*>(&MiscCFG::BombTimerCol));
					PutSwitch(Lang::MiscText.Bhop, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::BunnyHop);
					// PutSwitch(Lang::MiscText.SpecList, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::SpecList);
					PutSwitch(Lang::MiscText.RadarHack, 10.f, ImGui::GetFrameHeight() * 1.7f, &MiscCFG::RadarHack);
					if (MiscCFG::RadarHack)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextColored(ImColor(255, 50, 0, 255), Lang::MiscText.VisCheckDisable);
					}
					PutSwitch(Lang::MiscText.MoneyService, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::MoneyService);
					if (MiscCFG::MoneyService)
						PutSwitch(Lang::MiscText.ShowCashSpent, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::ShowCashSpent);
					PutSwitch(Lang::MiscText.EnemySensor, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::EnemySensor);
					PutSwitch(Lang::MiscText.Watermark, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::WaterMark);
					PutSwitch(Lang::MiscText.CheatList, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::CheatList);
					PutSwitch(Lang::MiscText.TeamCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TeamCheck);

					ImGui::NewLine();
					ImGui::SeparatorText(ICON_FA_FUTBOL" Fun");
					PutSwitch(Lang::MiscText.FakeDuck, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::Jitter);
					if (MiscCFG::Jitter)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextColored(ImColor(255, 50, 0, 255), "This might cause BAN");
					}

					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(ICON_FA_HEART" Menu Settings");
					PutSwitch(Lang::MiscText.AntiRecord, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::BypassOBS);
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					ImGui::TextDisabled(Lang::MiscText.LanguageList);
					ImGui::SameLine();
					if (ImGui::Combo("###Language", &MenuConfig::Language,
						"English\0Danish\0German\0Polish\0Portuguese\0Russian\0Simplified Chinese\0Slovak\0French\0Turkish\0Hungarian\0Dutch\0Cezch\0Spanish\0Romanian\0"))
						Lang::ChangeLang(MenuConfig::Language);
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					ImGui::TextDisabled(Lang::MiscText.ThemeList);
					ImGui::SameLine();
					if (ImGui::Combo("###Theme", &MenuConfig::Theme, "AimStar\0NeverLose\0Custom\0"))
						StyleChanger::UpdateSkin(MenuConfig::Theme);
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
						// ########################################
						ImGui::SeparatorText("Theme Color Settings");
						PutColorEditor("Button Border", "###ThemeCol1", 5.f, 0.f, reinterpret_cast<float*>(&MenuConfig::ButtonBorderColor));
						PutColorEditor("Border", "###ThemeCol2", 5.f, 0.f, reinterpret_cast<float*>(&borderColor));
						PutColorEditor("Button", "###ThemeCol3", 5.f, 0.f, reinterpret_cast<float*>(&ButtonColor));
						PutColorEditor("Button Hovered", "###ThemeCol4", 5.f, 0.f, reinterpret_cast<float*>(&ButtonHovered));
						PutColorEditor("Button Active", "###ThemeCol5", 5.f, 0.f, reinterpret_cast<float*>(&ButtonActive));
						PutColorEditor("Child Window Bg", "###ThemeCol6", 5.f, 0.f, reinterpret_cast<float*>(&childBgColor));
						PutColorEditor("Frame Bg", "###ThemeCol7", 5.f, 0.f, reinterpret_cast<float*>(&FrameBgColor));
						PutColorEditor("Frame Bg Hovered", "###ThemeCol8", 5.f, 0.f, reinterpret_cast<float*>(&FrameHovered));
						PutColorEditor("Frame Bg Active", "###ThemeCol9", 5.f, 0.f, reinterpret_cast<float*>(&FrameActive));
						PutColorEditor("Header", "###ThemeCol10", 5.f, 0.f, reinterpret_cast<float*>(&Header));
						PutColorEditor("Header Active", "###ThemeCol11", 5.f, 0.f, reinterpret_cast<float*>(&HeaderActive));
						PutColorEditor("Header Hovered", "###ThemeCol12", 5.f, 0.f, reinterpret_cast<float*>(&HeaderHovered));
						PutColorEditor("Scrollbar Bg", "###ThemeCol13", 5.f, 0.f, reinterpret_cast<float*>(&ScrollBg));
						PutColorEditor("Window Bg", "###ThemeCol14", 5.f, 0.f, reinterpret_cast<float*>(&windowBgColor));

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
					}

					ImGui::NewLine();
					PutSwitch(Lang::ReadMeText.DiscordButton, 5.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::mother);
					PutSwitch(Lang::ReadMeText.SourceButton, 5.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::fucker);

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
}