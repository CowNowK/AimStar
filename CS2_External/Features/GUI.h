#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#include <functional>

#include "..\MenuConfig.hpp"
#include "..\Render.hpp"
#include "..\Features\Aimbot\Legitbot.hpp"
#include "..\Features\Aimbot\SilentAim.hpp"
#include "..\Radar\Radar.h"
#include "..\TriggerBot.h"
#include "..\Utils\ConfigMenu.hpp"
#include "..\Utils\ConfigSaver.hpp"

#include "StyleChanger.h"
#include "..\Resources\Language.h"
#include "..\Resources\Images.h"

ID3D11ShaderResourceView* AS_Logo = NULL;
ID3D11ShaderResourceView* NL_Logo = NULL;
ID3D11ShaderResourceView* AW_Logo = NULL;
ID3D11ShaderResourceView* MenuButton1 = NULL;
ID3D11ShaderResourceView* MenuButton2 = NULL;
ID3D11ShaderResourceView* MenuButton3 = NULL;
ID3D11ShaderResourceView* MenuButton4 = NULL;
ID3D11ShaderResourceView* HitboxImage = NULL;
ID3D11ShaderResourceView* AvatarImage = NULL;

int LogoW = 0, LogoH = 0;
int LogoW2 = 0, LogoH2 = 0;
int LogoW3 = 0, LogoH3 = 0;
int buttonW = 0;
int buttonH = 0;
int hitboxW = 0, hitboxH = 0;
int avatarW = 0, avatarH = 0;
// checkbox for hitbox
bool checkbox1 = true;
bool checkbox2 = false;
bool checkbox3 = false;
bool checkbox4 = false;
bool checkbox5 = false;

namespace GUI
{
	void LoadDefaultConfig()
	{
		if (!MenuConfig::defaultConfig)
			return;

		MyConfigSaver::LoadConfig(XorStr("default.yml"));
		std::cout << XorStr("[Info] Default configuration loaded!") << std::endl;

		MenuConfig::defaultConfig = false;
	}

	inline void InitHitboxList()
	{
		if (MenuConfig::HitboxUpdated)
			return;

		auto HitboxList = AimControl::HitboxList;

		auto it = std::find(HitboxList.begin(), HitboxList.end(), BONEINDEX::head);
		if (it != HitboxList.end())
			checkbox1 = true;

		it = std::find(HitboxList.begin(), HitboxList.end(), BONEINDEX::neck_0);
		if (it != HitboxList.end())
			checkbox2 = true;

		it = std::find(HitboxList.begin(), HitboxList.end(), BONEINDEX::spine_1);
		if (it != HitboxList.end())
			checkbox3 = true;

		it = std::find(HitboxList.begin(), HitboxList.end(), BONEINDEX::spine_2);
		if (it != HitboxList.end())
			checkbox4 = true;

		it = std::find(HitboxList.begin(), HitboxList.end(), BONEINDEX::pelvis);
		if (it != HitboxList.end())
			checkbox5 = true;

		MenuConfig::HitboxUpdated = true;
	}
	void addHitbox(int BoneIndex)
	{
		AimControl::HitboxList.push_back(BoneIndex);
	}
	void removeHitbox(int BoneIndex)
	{
		for (auto it = AimControl::HitboxList.begin(); it != AimControl::HitboxList.end(); ++it) {
			if (*it == BoneIndex) {
				AimControl::HitboxList.erase(it);
				break;
			}
		}
	}
	void CheckHitbox()
	{
		bool exist = false;
		for (int value : AimControl::HitboxList) {
			if (value == MenuConfig::SparyPositionIndex) {
				exist = true;
				break;
			}
		}
		if (!exist) {
			AimControl::HitboxList.push_back(MenuConfig::SparyPositionIndex);

		}
	}
	char* wstringToChar(const std::wstring& wstr) {
		int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
		char* buffer = new char[len];
		WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, buffer, len, NULL, NULL);
		return buffer;
	}//ONETIME USING..
	void LoadImages()
	{
		if (AS_Logo == NULL)
		{
			// Updater::CheckForUpdates();
			Gui.LoadTextureFromMemory(Images::AS_Logo, sizeof Images::AS_Logo, &AS_Logo, &LogoW, &LogoH);
			Gui.LoadTextureFromMemory(Images::NL_Logo, sizeof Images::NL_Logo, &NL_Logo, &LogoW2, &LogoH2);
			Gui.LoadTextureFromMemory(Images::AW_Logo, sizeof Images::AW_Logo, &AW_Logo, &LogoW3, &LogoH3);
			Gui.LoadTextureFromMemory(Images::VisualButton, sizeof Images::VisualButton, &MenuButton1, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::AimbotButton, sizeof Images::AimbotButton, &MenuButton2, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::MiscButton, sizeof Images::MiscButton, &MenuButton3, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::ConfigButton, sizeof Images::ConfigButton, &MenuButton4, &buttonW, &buttonH);
			Gui.LoadTextureFromMemory(Images::ZekamashiImg, sizeof Images::ZekamashiImg, &HitboxImage, &hitboxW, &hitboxH);
			StyleChanger::UpdateSkin(MenuConfig::Theme);
		}
		if (AvatarImage == NULL)
			Gui.LoadTextureFromFile(wstringToChar(MenuConfig::AvatarPath), &AvatarImage, &avatarW, &avatarH);
	}

	// Components Settings
	// ########################################
	void AlignRight(float ContentWidth)
	{
		float ColumnContentWidth = ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x;
		float checkboxPosX = ImGui::GetColumnOffset() + ColumnContentWidth - ContentWidth;
		ImGui::SetCursorPosX(checkboxPosX);
	}
	bool SettingButton(const char* label, float CursorX)
	{
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX + ImGui::CalcTextSize(label).x);
		ImGui::SameLine();
		return ImGui::Button(ICON_FA_SUN);
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
	// return true when extended button clicked
	bool SwitchExtendedButton(const char* string, float CursorX, float ContentWidth, bool* v, const char* ButtonText, const char* Tip = NULL)
	{
		ImGui::PushID(string);
		float CurrentCursorX = ImGui::GetCursorPosX();
		ImGui::SetCursorPosX(CurrentCursorX + CursorX);
		ImGui::TextDisabled(string);
		if (Tip && ImGui::IsItemHovered())
			ImGui::SetTooltip(Tip);
		ImGui::SameLine();
		ImVec2 TempCursorPos = ImGui::GetCursorPos();
		AlignRight(ContentWidth);
		Gui.SwitchButton(string, v);
		ImGui::PopID();

		ImGui::SetCursorPos(TempCursorPos);
		return ImGui::Button(ButtonText);
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
	void CircleImage(ImTextureID user_texture_id, float diameter, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), const ImVec4& tint_col = ImVec4(1, 1, 1, 1))
	{
		ImVec2 p_min = ImGui::GetCursorScreenPos();
		ImVec2 p_max = ImVec2(p_min.x + diameter, p_min.y + diameter);
		ImGui::GetWindowDrawList()->AddImageRounded(user_texture_id, p_min, p_max, uv0, uv1, ImGui::GetColorU32(tint_col), diameter * 0.5f);
		ImGui::Dummy(ImVec2(diameter, diameter));
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
			ImageID = (void*)AW_Logo;
			LogoSize = ImVec2(LogoW3, LogoH3);
			LogoPos = MenuConfig::WCS.Logo3Pos;
			MenuConfig::ButtonBorderColor = MenuConfig::WCS.BorderColor_Red;
			break;
		case 3:
			ImageID = (void*)AS_Logo;
			LogoSize = ImVec2(LogoW, LogoH);
			LogoPos = MenuConfig::WCS.LogoPos;
			MenuConfig::ButtonBorderColor = MenuConfig::WCS.BorderColor_Light;
			break;
		case 4:
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
		ImGui::Begin(XorStr("AimStar"), nullptr, Flags);
		{
			ImGui::SetCursorPos(LogoPos);
			ImGui::Image(ImageID, LogoSize);
			ImGui::SetCursorPos(ImVec2(20,5));
			ImGui::TextColored(ImColor(255, 255, 255, 45), MenuConfig::HWID.substr(MenuConfig::HWID.length() - 16).c_str());

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

			ImColor BgCol = ImGui::GetStyleColorVec4(ImGuiCol_ChildBg);
			ImColor Alpha = ImColor(0, 0, 0, 0);
			ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 15,440));
			ImGui::BeginChild("User", { 150,60 });

			// Rounding avatar
			ImVec2 tempPos1, tempPos2, wdPos;
			ImGui::SetCursorPos({ ImGui::GetCursorPosX() + 5,ImGui::GetCursorPosY() + 10});
			tempPos1 = ImGui::GetCursorPos();
			ImDrawList* DrawList = ImGui::GetForegroundDrawList();
			CircleImage((void*)AvatarImage, 40);
			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 15 + 48);
			ImGui::SameLine();
			ImGui::Text(XorStr("User:\n%s"), getenv("USERNAME")); //If u want current player name -> MenuConfig::UserName (2 lazy to adapt non-ascii)
			ImGui::EndChild();

			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 15);
			ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 15, 85));
#ifdef USERMODE

			ImGui::Text(XorStr("Ring3-%s"), __DATE__);
#else
			ImGui::Text(XorStr("Kernel-%s"), __DATE__);
#endif // USERMODE
			
			ImGui::SetCursorPos(MenuConfig::WCS.ChildPos);
			
			ImGui::BeginChild(XorStr("Page"), MenuConfig::WCS.ChildSize);
			{
				if (MenuConfig::WCS.MenuPage == 0)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(XorStr(ICON_FA_EYE" ESP"));
					float MinRounding = 0.f, MaxRouding = 5.f;
					int MinCombo = 0, MaxCombo = 2;
					int MinDis = 0, MaxDis = 128;
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
						PutSwitch(Lang::ESPtext.Penis, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowPenis, true, "###PenisCol", reinterpret_cast<float*>(&ESPConfig::PenisColor));
						PutSwitch(Lang::ESPtext.SnapLine, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowLineToEnemy, true, "###LineCol", reinterpret_cast<float*>(&ESPConfig::LineToEnemyColor));
						if (ESPConfig::ShowLineToEnemy)
							PutSliderInt(Lang::ESPtext.LinePosList, 10.f, &ESPConfig::LinePos, &MinCombo, &MaxCombo, LinePos[ESPConfig::LinePos]);
						PutSwitch(Lang::ESPtext.EyeRay, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowEyeRay, true, "###LineCol", reinterpret_cast<float*>(&ESPConfig::EyeRayColor));
						PutSwitch(Lang::ESPtext.HealthBar, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowHealthBar);
						if (ESPConfig::ShowHealthBar)
							PutSwitch(Lang::ESPtext.HealthNum, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowHealthNum);
						PutSwitch(Lang::ESPtext.ShowArmorBar, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ArmorBar);
						if (ESPConfig::ArmorBar)
							PutSwitch(Lang::ESPtext.ArmorNum, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowArmorNum);
						PutSwitch(Lang::ESPtext.Weapon, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowWeaponESP);
						PutSwitch(Lang::ESPtext.Ammo, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::AmmoBar);
						PutSwitch(Lang::ESPtext.Distance, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowDistance);
						PutSwitch(Lang::ESPtext.PlayerName, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowPlayerName);
						PutSwitch(Lang::ESPtext.ScopedESP, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::ShowIsScoped);
						PutSwitch(Lang::ESPtext.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::VisibleCheck, true, "###VisibleCol", reinterpret_cast<float*>(&ESPConfig::VisibleColor));
						PutSliderInt(Lang::ESPtext.RenderDistance, 10.f, &ESPConfig::RenderDistance, &MinDis, &MaxDis, "%dm");

					
					}
					
					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(XorStr(ICON_FA_GRIN_ALT " ESP Preview"));
					// ESP::RenderPreview({ ImGui::GetColumnWidth(), ImGui::GetCursorPosY() }, { ImGui::GetCursorPosX() - ImGui::GetColumnWidth() * 0.65f, ImGui::GetCursorPosY() - ImGui::GetFrameHeight() });
					ESP::RenderPreview({ ImGui::GetColumnWidth(), ImGui::GetCursorPosY() });
					ImGui::Dummy({ 0.f, ImGui::GetFrameHeight() * 9 });

					ImGui::SeparatorText(XorStr(ICON_FA_LIGHTBULB" Glow"));
					float SpeedMin = 1.f, SpeedMax = 20.f;
					PutSwitch(Lang::MiscText.EnemySensor, 5.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::EnemySensor, true, "###GlowCol", reinterpret_cast<float*>(&MiscCFG::GlowColor));
					PutSwitch(XorStr("Rainbow"), 5.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::GlowRainbow);
					if (MiscCFG::GlowRainbow)
						PutSliderFloat(XorStr("Rainbow Speed: "), 5.f, &MiscCFG::Rainbow_Speed, &SpeedMin, &SpeedMax, "%.1f");

					ImGui::SeparatorText(XorStr(ICON_FA_COMPASS" External Radar"));
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
							PutSwitch(Lang::RadarText.CrossLine, 5.f, ImGui::GetFrameHeight() * 1.7, &RadarCFG::ShowRadarCrossLine);
							PutSliderFloat(Lang::RadarText.SizeSlider, 5.f, &RadarCFG::RadarPointSizeProportion, &RadarPointSizeProportionMin, &RadarPointSizeProportionMax, "%1.f");
							PutSliderFloat(Lang::RadarText.ProportionSlider, 5.f, &RadarCFG::Proportion, &ProportionMin, &ProportionMax, "%.1f");
							PutSliderFloat(Lang::RadarText.RangeSlider, 5.f, &RadarCFG::RadarRange, &RadarRangeMin, &RadarRangeMax, "%.1f");
							PutSliderFloat(Lang::RadarText.AlphaSlider, 5.f, &RadarCFG::RadarBgAlpha, &AlphaMin, &AlphaMax, "%.1f");
						}
					}
					
					ImGui::NewLine();
					ImGui::SeparatorText(XorStr(ICON_FA_DOT_CIRCLE" Crosshairs"));
					float DotMin = 1.f, DotMax = 50.f;
					int LengthMin = 1, LengthMax = 100;
					int GapMin = 1, GapMax = 50;
					int ThickMin = 1, ThickMax = 20;
					float CircleRmin = 1.f, CircleRmax = 50.f;
					PutSwitch(Lang::CrosshairsText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::ShowCrossHair, true, XorStr("###CrosshairsCol"), reinterpret_cast<float*>(&CrosshairsCFG::CrossHairColor));
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
						PutSwitch(Lang::CrosshairsText.TargetCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TargetingCrosshairs, true, XorStr("###CircleCol"), reinterpret_cast<float*>(&CrosshairsCFG::TargetedColor));
						//PutSwitch(Lang::CrosshairsText.TeamCheck, 5.f, ImGui::GetFrameHeight() * 1.7, &CrosshairsCFG::TeamCheck);
					}
					
					ImGui::Columns(1);
				}
				
				if (MenuConfig::WCS.MenuPage == 1)
				{
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(XorStr(ICON_FA_USER" Aimbot"));

					float FovMin = 0.f, FovMax = 25.f, MinFovMax = 1.f;
					int BulletMin = 0, BulletMax = 5;
					float SmoothMin = 0.4f, SmoothMax = 5.f;
					PutSwitch(Lang::AimbotText.Enable, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::AimBot);
					if (MenuConfig::AimBot)
					{
						// PutSwitch("Silent Aim", 10.f, ImGui::GetFrameHeight() * 1.7, &AimControl::silent);
						PutSwitch(Lang::AimbotText.Ragebot, 10.f, ImGui::GetFrameHeight() * 1.7, &AimControl::Rage);

						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled(Lang::AimbotText.HotKeyList);
						ImGui::SameLine();
						if (ImGui::Combo(XorStr("###AimKey"), &MenuConfig::AimBotHotKey, XorStr("LALT\0LBUTTON\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0")))
						{
							AimControl::SetHotKey(MenuConfig::AimBotHotKey);
						}
						if (!AimControl::Rage)
							PutSliderInt(Lang::AimbotText.BulletSlider, 10.f, &AimControl::AimBullet, &BulletMin, &BulletMax, "%d");
						PutSwitch(Lang::AimbotText.Toggle, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::AimToggleMode);
						PutSwitch(Lang::AimbotText.AimLock, 10.f, ImGui::GetFrameHeight() * 1.7, &AimControl::AimLock);
						PutSwitch(Lang::AimbotText.DrawFov, 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::DrawFov, true, XorStr("###FOVcol"), reinterpret_cast<float*>(&MenuConfig::FovCircleColor));
						PutSwitch(Lang::AimbotText.VisCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::VisibleCheck);
						if (!MenuConfig::VisibleCheck && !AimControl::Rage)
							PutSwitch(Lang::AimbotText.IgnoreFlash, 10.f, ImGui::GetFrameHeight() * 1.7, &AimControl::IgnoreFlash);
						PutSwitch(Lang::AimbotText.ScopeOnly, 10.f, ImGui::GetFrameHeight() * 1.7, &AimControl::ScopeOnly);
						PutSwitch(Lang::AimbotText.AutoShot, 10.f, ImGui::GetFrameHeight() * 1.7, &AimControl::AutoShot);
						PutSliderFloat(Lang::AimbotText.FovSlider, 10.f, &AimControl::AimFov, &AimControl::AimFovMin, &FovMax, "%.1f");
						if (!AimControl::Rage)
						{
							PutSliderFloat(Lang::AimbotText.FovMinSlider, 10.f, &AimControl::AimFovMin, &FovMin, &MinFovMax, "%.2f");
							PutSliderFloat(Lang::AimbotText.SmoothSlider, 10.f, &AimControl::Smooth, &SmoothMin, &SmoothMax, "%.1f");
						}
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextDisabled(Lang::AimbotText.BoneList);
						/*
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
						*/
						ImVec2 StartPos = ImGui::GetCursorScreenPos();
						ImGui::Image((void*)HitboxImage, ImVec2(hitboxW, hitboxH));
						ImGui::GetWindowDrawList()->AddLine(ImVec2(StartPos.x + 130, StartPos.y + 74), ImVec2(StartPos.x + 205, StartPos.y + 74), ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)), 1.8f); // Head
						ImGui::SetCursorScreenPos(ImVec2(StartPos.x + 203, StartPos.y + 63)); 
						if (ImGui::Checkbox(XorStr("###Head"), &checkbox1))
						{
							if (checkbox1) {
								addHitbox(BONEINDEX::head);
							}
							else {
								removeHitbox(BONEINDEX::head);
							}
						}
						ImGui::GetWindowDrawList()->AddLine(ImVec2(StartPos.x + 129, StartPos.y + 103), ImVec2(StartPos.x + 59, StartPos.y + 103), ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)), 1.8f); // Neck
						ImGui::SetCursorScreenPos(ImVec2(StartPos.x + 39, StartPos.y + 92));
						if (ImGui::Checkbox(XorStr("###Neck"), &checkbox2))
						{
							if (checkbox2) {
								addHitbox(BONEINDEX::neck_0);
							}
							else {
								removeHitbox(BONEINDEX::neck_0);
							}
						}
						ImGui::GetWindowDrawList()->AddLine(ImVec2(StartPos.x + 120, StartPos.y + 141), ImVec2(StartPos.x + 195, StartPos.y + 141), ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)), 1.8f); // Chest
						ImGui::SetCursorScreenPos(ImVec2(StartPos.x + 193, StartPos.y + 130));
						if (ImGui::Checkbox(XorStr("###Chest"), &checkbox3))
						{
							if (checkbox3) {
								addHitbox(BONEINDEX::spine_1);
							}
							else {
								removeHitbox(BONEINDEX::spine_1);
							}
						}
						ImGui::GetWindowDrawList()->AddLine(ImVec2(StartPos.x + 119, StartPos.y + 167), ImVec2(StartPos.x + 44, StartPos.y + 167), ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)), 1.8f); // Penis
						ImGui::SetCursorScreenPos(ImVec2(StartPos.x + 24, StartPos.y + 156));
						if (ImGui::Checkbox(XorStr("###Stomache"), &checkbox4))
						{
							if (checkbox4) {
								addHitbox(BONEINDEX::spine_2);
							}
							else {
								removeHitbox(BONEINDEX::spine_2);
							}
						}
						ImGui::GetWindowDrawList()->AddLine(ImVec2(StartPos.x + 119, StartPos.y + 200), ImVec2(StartPos.x + 195, StartPos.y + 200), ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)), 1.8f); // Penis
						ImGui::SetCursorScreenPos(ImVec2(StartPos.x + 193, StartPos.y + 189));
						if (ImGui::Checkbox(XorStr("###Penis"), &checkbox5))
						{
							if (checkbox5) {
								addHitbox(BONEINDEX::pelvis);
							}
							else {
								removeHitbox(BONEINDEX::pelvis);
							}
						}
						ImGui::SetCursorScreenPos(ImVec2(StartPos.x, StartPos.y + hitboxH));
						ImGui::TextDisabled(Lang::AimbotText.SprayBoneList);
						ImGui::SameLine();
						if (ImGui::Combo(XorStr("###SparyPos"), &MenuConfig::SparyPosition, XorStr("Nearest\0Head\0Neck\0Chest\0Penis\0")))
						{
							switch (MenuConfig::SparyPosition)
							{
							case 0:
								MenuConfig::SparyPositionIndex = 0xff;
								break;
							case 1:
								MenuConfig::SparyPositionIndex = BONEINDEX::head;
								checkbox1 = true;
								break;
							case 2:
								MenuConfig::SparyPositionIndex = BONEINDEX::neck_0;
								checkbox2 = true;
								break;
							case 3:
								MenuConfig::SparyPositionIndex = BONEINDEX::spine_1;
								checkbox3 = true;
								break;
							case 4:
								MenuConfig::SparyPositionIndex = BONEINDEX::pelvis;
								checkbox5 = true;
								break;
							default:
								break;
							}
							CheckHitbox();
						}
					}
					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(XorStr(ICON_FA_ARROW_ALT_CIRCLE_DOWN " RCS"));
					float recoilMin = 0.f, recoilMax = 2.f;
					PutSwitch(Lang::RCStext.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::RCS);
					if (MenuConfig::RCS) {
						PutSliderFloat(Lang::RCStext.Yaw, 5.f, &RCS::RCSScale.x, &recoilMin, &recoilMax, "%.2f");
						PutSliderFloat(Lang::RCStext.Pitch, 5.f, &RCS::RCSScale.y, &recoilMin, &recoilMax, "%.2f");
						float scalex = (2.22 - RCS::RCSScale.x) *.5f;
						float scaley = (2.12 - RCS::RCSScale.y) *.5f;//Simulate reasonable error values
						ImVec2 BulletPos = ImGui::GetCursorScreenPos();

						// Example Preview
						ImVec2 BulletPos0, BulletPos1, BulletPos2, BulletPos3, BulletPos4, BulletPos5, BulletPos6, BulletPos7, BulletPos8, BulletPos9, BulletPos10, BulletPos11, BulletPos12, BulletPos13, BulletPos14, BulletPos15;
						BulletPos.y += 123 * scaley;
						BulletPos0.x = BulletPos.x + 125; BulletPos0.y = BulletPos.y + 5;
						BulletPos1.x = BulletPos0.x - 3 * scalex; BulletPos1.y = BulletPos0.y - 5 * scaley;
						BulletPos2.x = BulletPos1.x + 2 * scalex; BulletPos2.y = BulletPos1.y - 10 * scaley;
						BulletPos3.x = BulletPos2.x + 4 * scalex; BulletPos3.y = BulletPos2.y - 11 * scaley;
						BulletPos4.x = BulletPos3.x - 3 * scalex; BulletPos4.y = BulletPos3.y - 31 * scaley;
						BulletPos5.x = BulletPos4.x - 1 * scalex; BulletPos5.y = BulletPos4.y - 20 * scaley;
						BulletPos6.x = BulletPos5.x - 2 * scalex; BulletPos6.y = BulletPos5.y - 17 * scaley;
						BulletPos7.x = BulletPos6.x - 15 * scalex; BulletPos7.y = BulletPos6.y - 9 * scaley;
						BulletPos8.x = BulletPos7.x + 7 * scalex; BulletPos8.y = BulletPos7.y - 8 * scaley;
						BulletPos9.x = BulletPos8.x + 33 * scalex; BulletPos9.y = BulletPos8.y + 2 * scaley;
						BulletPos10.x = BulletPos9.x + 1 * scalex; BulletPos10.y = BulletPos9.y - 16 * scaley;
						BulletPos11.x = BulletPos10.x - 9 * scalex; BulletPos11.y = BulletPos10.y + 20 * scaley;
						BulletPos12.x = BulletPos11.x - 3 * scalex; BulletPos12.y = BulletPos11.y - 9 * scaley;
						BulletPos13.x = BulletPos12.x + 15 * scalex; BulletPos13.y = BulletPos12.y - 5 * scaley;
						BulletPos14.x = BulletPos13.x + 10 * scalex; BulletPos14.y = BulletPos13.y - 4 * scaley;
						
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos0, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos1, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos2, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos3, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos4, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos5, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos6, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos7, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos8, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos9, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos10, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos11, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos12, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos13, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));
						ImGui::GetWindowDrawList()->AddCircleFilled(BulletPos14, 4.f, ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)));

						ImGui::SetCursorScreenPos(ImVec2(BulletPos.x, BulletPos.y + 10));
					}

					ImGui::NewLine();
					ImGui::SeparatorText(XorStr(ICON_FA_HAND_POINTER" Triggerbot"));
					int DelayMin = 0, DelayMax = 300;
					int DurationMin = 0, DurationMax = 1000;
					PutSwitch(Lang::TriggerText.Enable, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TriggerBot);
					if (MenuConfig::TriggerBot)
					{
						if (!MenuConfig::TriggerAlways)
						{
							ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
							ImGui::TextDisabled(Lang::TriggerText.HotKeyList);
							ImGui::SameLine();
							if (ImGui::Combo(XorStr("###TriggerbotKey"), &MenuConfig::TriggerHotKey, XorStr("LALT\0RBUTTON\0XBUTTON1\0XBUTTON2\0CAPITAL\0SHIFT\0CONTROL\0")))
							{
								TriggerBot::SetHotKey(MenuConfig::TriggerHotKey);
							}
						}
						PutSwitch(Lang::TriggerText.Toggle, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TriggerAlways);
						PutSwitch(Lang::TriggerText.ScopeOnly, 5.f, ImGui::GetFrameHeight() * 1.7, &TriggerBot::ScopeOnly);
						PutSwitch(Lang::TriggerText.IgnoreFlash, 10.f, ImGui::GetFrameHeight() * 1.7, &TriggerBot::IgnoreFlash);
						PutSliderInt(Lang::TriggerText.DelaySlider, 1.f, &TriggerBot::TriggerDelay, &DelayMin, &DelayMax, "%d ms");
						PutSliderInt(Lang::TriggerText.FakeShotSlider, 5.f, &TriggerBot::ShotDuration, &DurationMin, &DurationMax, "%d ms");
					}

					ImGui::Columns(1);
				}

				if (MenuConfig::WCS.MenuPage == 2)
				{
					int FovMin = 60, FovMax = 140;
					int NightMin = 0, NightMax = 150;
					float FlashMin = 0.f, FlashMax = 255.f;
					ImGui::Columns(2, nullptr, false);
					ImGui::SetCursorPos(ImVec2(15.f, 24.f));
					ImGui::SeparatorText(XorStr(ICON_FA_SUN" Misc"));

					if (SwitchExtendedButton(Lang::MiscText.NightMode, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::NightMode, "..."))
						ImGui::OpenPopup(XorStr("##NightModeSettings"));
					ImGui::SetNextWindowSize(ImVec2(ImGui::GetColumnWidth(), 0));
					if (ImGui::BeginPopup(XorStr("##NightModeSettings"))) {
						PutSliderInt(Lang::MiscText.Alpha, 10.f, &MiscCFG::NightModeAlpha, &NightMin, &NightMax, "%d");
						ImGui::EndPopup();
					}
					PutSliderInt(Lang::MiscText.fovchanger, 10.f, &MiscCFG::Fov, &FovMin, &FovMax, "%d");
					PutSliderFloat(Lang::MiscText.FlashImmunity, 10.f, &MiscCFG::FlashImmunity, &FlashMin, &FlashMax, "%.f");
					PutSwitch(Lang::MiscText.Bhop, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::BunnyHop);
					PutSwitch(Lang::MiscText.bmbTimer, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::bmbTimer, true, XorStr("###bmbTimerCol"), reinterpret_cast<float*>(&MiscCFG::BombTimerCol));
					PutSwitch(Lang::MiscText.CheatList, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::CheatList);
					PutSwitch(Lang::MiscText.FastStop, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::FastStop);
					PutSwitch(Lang::MiscText.ForceScope, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::ForceScope);
					PutSwitch(Lang::MiscText.HeadshotLine, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::ShowHeadShootLine, true, "###HSCol", reinterpret_cast<float*>(&MenuConfig::HeadShootLineColor));
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
					ImGui::TextDisabled(Lang::MiscText.HitSound);
					ImGui::SameLine();
					ImGui::SetNextItemWidth(165.f);
					ImGui::Combo(XorStr("###HitSounds"), &MiscCFG::HitSound, XorStr("None\0Neverlose\0Skeet\0Fuck\0Senpai\0"));
					PutSwitch(XorStr("Hit Marker"), 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::HitMarker);
					// SwitchExtendedButton("Hit Marker", 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::HitMarker, "...");
					PutSwitch(Lang::MiscText.JumpThrow, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::jumpthrow);
					PutSwitch(Lang::MiscText.MoneyService, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::MoneyService);
					if (MiscCFG::MoneyService)
						PutSwitch(Lang::MiscText.ShowCashSpent, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::ShowCashSpent);
					PutSwitch(Lang::MiscText.SpecCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::WorkInSpec);
					// PutSwitch(Lang::MiscText.SpecList, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::SpecList);
					PutSwitch(Lang::MiscText.TeamCheck, 10.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::TeamCheck);
					PutSwitch(Lang::MiscText.Watermark, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::WaterMark);

					ImGui::NewLine();
					ImGui::SeparatorText(XorStr(ICON_FA_FUTBOL" Fun"));
					PutSwitch(Lang::MiscText.FakeDuck, 10.f, ImGui::GetFrameHeight() * 1.7, &MiscCFG::Jitter);
					if (MiscCFG::Jitter)
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10.f);
						ImGui::TextColored(ImColor(255, 50, 0, 255), XorStr("This might cause BAN"));
					}
					if (MenuConfig::Country == XorStr("CN") && MenuConfig::Language == 6)
					{
						PutSwitch(XorStr("Winnie"), 10.f, ImGui::GetFrameHeight() * 1.7, &ESPConfig::winniethepool);
					}


					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(XorStr(ICON_FA_HEART" Menu Settings"));
					PutSwitch(Lang::MiscText.AntiRecord, 5.f, ImGui::GetFrameHeight() * 1.7, &MenuConfig::BypassOBS);
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					ImGui::TextDisabled(Lang::MiscText.ThemeList);
					ImGui::SameLine();
					if (ImGui::Combo(XorStr("###Theme"), &MenuConfig::Theme, XorStr("AimStar\0NeverLose\0AIMWARE\0Lumine\0Fatality\0Custom\0")))
						StyleChanger::UpdateSkin(MenuConfig::Theme);
					if (MenuConfig::Theme == 5)
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
						// ########################################
						ImGui::SeparatorText(XorStr("Theme Color Settings"));
						PutColorEditor(XorStr("Button Border"), XorStr("###ThemeCol1"), 5.f, 0.f, reinterpret_cast<float*>(&MenuConfig::ButtonBorderColor));
						PutColorEditor(XorStr("FeatureName"), XorStr("###ThemeCol16"), 5.f, 0.f, reinterpret_cast<float*>(&FeatureName));
						PutColorEditor(XorStr("Text"), XorStr("###ThemeCol17"), 5.f, 0.f, reinterpret_cast<float*>(&Text));

						PutColorEditor(XorStr("Border"), XorStr("###ThemeCol2"), 5.f, 0.f, reinterpret_cast<float*>(&borderColor));
						PutColorEditor(XorStr("Button"), XorStr("###ThemeCol3"), 5.f, 0.f, reinterpret_cast<float*>(&ButtonColor));
						PutColorEditor(XorStr("Button Hovered"), XorStr("###ThemeCol4"), 5.f, 0.f, reinterpret_cast<float*>(&ButtonHovered));
						PutColorEditor(XorStr("Button Active"), XorStr("###ThemeCol5"), 5.f, 0.f, reinterpret_cast<float*>(&ButtonActive));
						PutColorEditor(XorStr("Child Window Bg"), XorStr("###ThemeCol6"), 5.f, 0.f, reinterpret_cast<float*>(&childBgColor));
						PutColorEditor(XorStr("Frame Bg"), XorStr("###ThemeCol7"), 5.f, 0.f, reinterpret_cast<float*>(&FrameBgColor));
						PutColorEditor(XorStr("Frame Bg Hovered"), XorStr("###ThemeCol8"), 5.f, 0.f, reinterpret_cast<float*>(&FrameHovered));
						PutColorEditor(XorStr("Frame Bg Active"), XorStr("###ThemeCol9"), 5.f, 0.f, reinterpret_cast<float*>(&FrameActive));
						PutColorEditor(XorStr("Header"), XorStr("###ThemeCol10"), 5.f, 0.f, reinterpret_cast<float*>(&Header));
						PutColorEditor(XorStr("Header Active"), XorStr("###ThemeCol11"), 5.f, 0.f, reinterpret_cast<float*>(&HeaderActive));
						PutColorEditor(XorStr("Header Hovered"), XorStr("###ThemeCol12"), 5.f, 0.f, reinterpret_cast<float*>(&HeaderHovered));
						PutColorEditor(XorStr("Scrollbar Bg"), XorStr("###ThemeCol13"), 5.f, 0.f, reinterpret_cast<float*>(&ScrollBg));
						PutColorEditor(XorStr("Separator"), XorStr("###ThemeCol14"), 5.f, 0.f, reinterpret_cast<float*>(&Separator));
						PutColorEditor(XorStr("Window Bg"), XorStr("###ThemeCol15"), 5.f, 0.f, reinterpret_cast<float*>(&windowBgColor));

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

					ImGui::NewLine();
					
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					if (ImGui::Button(XorStr(ICON_FA_COPY " Source Code"), { ImGui::GetColumnWidth() - 20.f, 25.f }))
						Gui.OpenWebpage(XorStr("https://github.com/CowNowB/Aimstar"));
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					if (ImGui::Button(XorStr(ICON_FA_COMMENT_DOTS " Join Discord"), { ImGui::GetColumnWidth() - 20.f, 25.f }))
						Gui.OpenWebpage(XorStr("https://discord.com/invite/VgRrxwesPz"));

					if (MenuConfig::Country == XorStr("CN"))
					{
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
						if (ImGui::Button(XorStr(ICON_FA_COMMENT_DOTS " QQ Group"), { ImGui::GetColumnWidth() - 20.f, 25.f }))
							Gui.OpenWebpage(XorStr("https://qm.qq.com/cgi-bin/qm/qr?k=1I-2ldOcQkFYCAk_4ayY2GhIPXUYePUa&jump_from=webapi&authKey=Ff3VOoKW8u61rE4WqF3U46e0mQco8M6TeWp7gKDyo9dB/KZfU75xPifeo4d8Ke4H"));
					}

					ImGui::NewLine();
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 5.f);
					if (ImGui::Button(XorStr("Update Offsets"), { 125.f, 25.f }))
					{
						Gui.OpenWebpage(XorStr("https://aimstar.tkm.icu/updater"));

					
						ImGui::OpenPopup(XorStr("How to update:"));
					}
					ImGui::SameLine();
					if (ImGui::Button(XorStr("Safe Exit"), { 125.f, 25.f }))
						Init::Client::Exit();

					if (ImGui::BeginPopupModal(XorStr("How to update:"), NULL, ImGuiWindowFlags_AlwaysAutoResize))
					{
						ImGui::Text("1. Click 'fetch Offsets' to fetch game offsets.");
						ImGui::Text("2. Click 'Download YAML' to download the yaml file.");
						ImGui::Text("3. Put the yaml file in 'Documents\\AimStar\\Offsets\\' folder.");
						ImGui::Text("4. Restart the cheat.");
						if (ImGui::Button(XorStr("OK")))
							ImGui::CloseCurrentPopup();
					}


					ImGui::Columns(1);
				}

				if (MenuConfig::WCS.MenuPage == 3)
				{
					ImGui::Columns(2, nullptr, false);
					ConfigMenu::RenderCFGmenu();

					int FPS = 1200;
					ImGui::NextColumn();
					ImGui::SetCursorPosY(24.f);
					ImGui::SeparatorText(XorStr("Cheat Settings"));
					PutSliderInt(Lang::ConfigText.fpsCap, 5.f, &MenuConfig::MaxRenderFPS, &MenuConfig::MaxFrameRate, &FPS, "%d");

					ImGui::Columns(1);
				}
			} ImGui::EndChild();
		} ImGui::End();

		LoadDefaultConfig();
	}
}
