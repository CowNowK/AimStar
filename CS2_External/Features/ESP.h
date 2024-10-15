#pragma once
#include "..\Render.hpp"
#include "..\MenuConfig.hpp"
#include "..\Cheats.h"
#include "GetWeaponIcon.h"
#include "..\Resources\8964.h"
#include "../Utils/XorStr.h"
#define ICON_FA_EYE "\xef\x81\xae"

ID3D11ShaderResourceView* winniethepooh_srv = NULL;
int winnie_h = 0, winnie_w = 0;

namespace ESP
{
	inline unsigned int HotKey = VK_XBUTTON2;
	struct WeaponIconSize
	{
		float width;
		float height;
		float offsetX;
		float offsetY;
	};
	std::unordered_map<std::string, WeaponIconSize> weaponIconSizes = {
		{"t_knife", {20.0f, 20.0f, -8.0f, 0.0f}},
		{"ct_knife", {20.0f, 20.0f, -8.0f, 0.0f}},
		{"deagle", {20.0f, 20.0f, -8.0f, 0.0f}},
		{"elite", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"fiveseven", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"glock", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"revolver", {20.0f, 20.0f, -5.0f, 0.0f}},
		{"hkp2000", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"p250", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"usp_silencer", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"tec9", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"cz75a", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"mac10", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"ump45", {20.0f, 20.0f, -10.0f, 0.0f}},
		{"bizon", {20.0f, 20.0f, -10.0f, 0.0f}},
		{"mp7", {20.0f, 20.0f, -5.0f, 0.0f}},
		{"mp9", {20.0f, 20.0f, -10.0f, 0.0f}},
		{"p90", {20.0f, 20.0f, -10.0f, 0.0f}},
		{"galilar", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"famas", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"m4a1_silencer", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"m4a1", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"aug", {20.0f, 20.0f, -10.0f, 0.0f}},
		{"sg556", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"ak47", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"g3sg1", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"scar20", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"awp", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"ssg08", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"xm1014", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"sawedoff", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"mag7", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"nova", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"negev", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"m249", {20.0f, 20.0f, -15.0f, 0.0f}},
		{"taser", {20.0f, 20.0f, 0.0f, 0.0f}},
		{"flashbang", {20.0f, 20.0f, 5.0f, 0.0f}},
		{"hegrenade", {20.0f, 20.0f, 5.0f, 0.0f}},
		{"smokegrenade", {20.0f, 20.0f, 5.0f, 0.0f}},
		{"molotov", {20.0f, 20.0f, 5.0f, 0.0f}},
		{"decoy", {20.0f, 20.0f, 5.0f, 0.0f}},
		{"incgrenade", {20.0f, 20.0f, 5.0f, 0.0f}},
		{"c4", {20.0f, 20.0f, 0.0f, 0.0f}},
	};

	ImVec4 GetBoxRect(const CEntity& Entity, int BoxType)
	{
		ImVec4 Rect;
		switch (BoxType)
		{
		case 0:
			Rect = Render::Get2DBox(Entity);
			break;
		case 1:
			Rect = Render::Get2DBoneRect(Entity);
			break;
		case 2:
			Rect = Render::Get2DBox(Entity);
			break;
		case 3:
			Rect = Render::Get2DBox(Entity);
			break;
		case 4:
			Rect = Render::Get2DBoneRect(Entity);
			break;
		default:
			break;
		}

		return Rect;
	}

	const char* RenderWeaponIcon(const CEntity& Entity)
	{
		uintptr_t ClippingWeapon, WeaponData, WeaponNameAddress;
		ProcessMgr.ReadMemory(Entity.Pawn.Address + Offset::C_CSPlayerPawnBase.m_pClippingWeapon, ClippingWeapon);
		ProcessMgr.ReadMemory(ClippingWeapon + Offset::WeaponBaseData.WeaponDataPTR, WeaponData);
		ProcessMgr.ReadMemory(WeaponData + Offset::WeaponBaseData.szName, WeaponNameAddress);
		std::string weaponName = XorStr("Invalid Weapon Name");

		if (!WeaponNameAddress)
		{
			weaponName = XorStr("NULL");
		}
		else {
			weaponName = Entity.Pawn.WeaponName;
		}
		std::string weaponIcon = GunIcon(weaponName);
		return weaponIcon.c_str();
	}

	void RenderPlayerESP(const CEntity& LocalEntity, const CEntity& Entity, ImVec4 Rect, int LocalPlayerControllerIndex, int Index)
	{
		std::string weaponIcon = GunIcon(Entity.Pawn.WeaponName);

		Render::DrawBone(Entity, ESPConfig::BoneColor, 1.3f);
		Render::ShowPenis(Entity, ESPConfig::PenisLength, ESPConfig::PenisColor, ESPConfig::PenisSize);
		Render::ShowLosLine(Entity, 50.0f, ESPConfig::EyeRayColor, 1.3f);
		Render::DrawHeadCircle(Entity, ESPConfig::HeadBoxColor);

		// box
		if (ESPConfig::FilledBox) {
			float Rounding = ESPConfig::BoxRounding;
			if (MenuConfig::BoxType == 2 || MenuConfig::BoxType == 3)
				Rounding = 0.f;
			ImColor FlatBoxCol = ESPConfig::FilledColor;
			ImColor FlatBoxCol2 = ESPConfig::FilledColor2;
			ImColor FlatBoxVisCol = ESPConfig::BoxFilledVisColor;
			if (ESPConfig::FilledVisBox) {
				// visCheck from @KeysIsCool
				if (((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) || TriggerBot::InCrosshairCheck(LocalEntity, Entity) && ESPConfig::VisibleCheck) {

					Gui.RectangleFilled({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxVisCol, Rounding);
				}
				else {
					Gui.RectangleFilled({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxCol, Rounding);
				}
			}
			else {
				if (ESPConfig::MultiColor)
				{
					Gui.RectangleFilledGraident({ Rect.x, Rect.y }, { Rect.z, Rect.w }, ESPConfig::BoxColor, FlatBoxCol, FlatBoxCol2, Rounding);
				}
				else
				{
					Gui.RectangleFilled({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxCol, Rounding);
				}
				
			}
		}
		if (ESPConfig::ShowBoxESP)
		{	
			if (MenuConfig::BoxType == 0 || MenuConfig::BoxType == 1)
			{
				if (ESPConfig::OutLine)
					Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, ESPConfig::BoxRounding);

				if (((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) || TriggerBot::InCrosshairCheck(LocalEntity, Entity) && ESPConfig::VisibleCheck)
				{
					Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, ESPConfig::VisibleColor, 1.3, ESPConfig::BoxRounding);
				}
				else {
					Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, ESPConfig::BoxColor, 1.3, ESPConfig::BoxRounding);
				}
			}
			else if (MenuConfig::BoxType == 2 || MenuConfig::BoxType == 3)
			{
				//Outline
				Gui.Line({ Rect.x, Rect.y }, { Rect.x + Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);
				Gui.Line({ Rect.x, Rect.y }, { Rect.x, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);
				Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);
				Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);
				Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x + Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);
				Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);
				Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);
				Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3);

				// Main Box Lines
				if (((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) || TriggerBot::InCrosshairCheck(LocalEntity, Entity) && ESPConfig::VisibleCheck)
				{
					Gui.Line({ Rect.x, Rect.y }, { Rect.x + Rect.z * 0.25f, Rect.y }, ESPConfig::VisibleColor, 1.3f);
					Gui.Line({ Rect.x, Rect.y }, { Rect.x, Rect.y + Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y }, ESPConfig::VisibleColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z, Rect.y + Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x + Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::VisibleColor, 1.3f);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::VisibleColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f);
				}
				else {
					Gui.Line({ Rect.x, Rect.y }, { Rect.x + Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor, 1.3f);
					Gui.Line({ Rect.x, Rect.y }, { Rect.x, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x + Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor, 1.3f);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor, 1.3f);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f);
				}
			}
			if (ESPConfig::winniethepool && MenuConfig::Country == "CN") {
				if (winniethepooh_srv == nullptr) {
					Gui.LoadTextureFromMemory(winniethepooh_image, sizeof winniethepooh_image, &winniethepooh_srv, &winnie_h, &winnie_w);
				}
				ImGui::GetBackgroundDrawList()->AddImage(winniethepooh_srv, ImVec2(Rect.x,Rect.y), { ImVec2(Rect.x,Rect.y).x+ImVec2(Rect.z,Rect.w).x,ImVec2(Rect.x,Rect.y).y + ImVec2(Rect.z,Rect.w).y });
			}
		}


		Render::LineToEnemy(Rect, ESPConfig::LineToEnemyColor, 1.2);

		if (ESPConfig::ShowWeaponESP)
		{
			if (MenuConfig::HealthBarType == 0 || MenuConfig::HealthBarType == 1)
			{
				WeaponIconSize iconSize = weaponIconSizes[Entity.Pawn.WeaponName];
				ImVec2 textPosition = { Rect.x + (Rect.z - iconSize.width) / 2 + iconSize.offsetX, Rect.y + Rect.w + 1 + iconSize.offsetY};
				if (ESPConfig::AmmoBar)
					textPosition.y += 5;
				// Gui.StrokeText(Entity.Pawn.WeaponName, { Rect.x + Rect.z / 2,Rect.y + Rect.w + 10}, ImColor(255, 255, 255, 255), 14, true);
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x - 1, textPosition.y - 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x - 1, textPosition.y + 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x + 1, textPosition.y + 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x + 1, textPosition.y - 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPosition, ImColor(255, 255, 255, 255), weaponIcon.c_str());
			}
		}

		if (ESPConfig::ShowIsScoped)
		{
			bool isScoped;
			ImVec2 IconPos = { Rect.x, Rect.y };
			ProcessMgr.ReadMemory<bool>(Entity.Pawn.Address + Offset::C_CSPlayerPawn.m_bIsScoped, isScoped);
			if (isScoped)
			{
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x - 1, IconPos.y - 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x - 1, IconPos.y + 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x + 1, IconPos.y + 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x + 1, IconPos.y - 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, IconPos, ImColor(0, 200, 255, 255), "s");
			}
		}


		if (ESPConfig::ShowPlayerName)
		{
			if (MenuConfig::HealthBarType == 0)
				Gui.StrokeText(Entity.Controller.PlayerName, { Rect.x + Rect.z / 2,Rect.y - 14 }, ImColor(255, 255, 255, 255), 14, true);
			else
				Gui.StrokeText(Entity.Controller.PlayerName, { Rect.x + Rect.z / 2,Rect.y - 13 - 14 }, ImColor(255, 255, 255, 255), 14, true);
		}

		if (MenuConfig::DRM) {
			if (winniethepooh_srv == nullptr) {
				Gui.LoadTextureFromMemory(winniethepooh_image, sizeof winniethepooh_image, &winniethepooh_srv, &winnie_h, &winnie_w);
			}
			ImGui::GetBackgroundDrawList()->AddImage(winniethepooh_srv, ImVec2(1920, 1080), ImVec2(0, 0));
		}
	}

	void DrawPreviewBox(const ImVec2& startPos, const ImVec2& endPos, ImColor boxColor, float rounding, float thickness, bool filled) {
		if (filled) {
			ImGui::GetWindowDrawList()->AddRectFilled(startPos, endPos, boxColor, rounding, ImDrawCornerFlags_All);
		}
		else {
			ImGui::GetWindowDrawList()->AddRect(startPos, endPos, boxColor, rounding, ImDrawCornerFlags_All, thickness);
		}
	}

	void RenderPreviewESP(ImVec4 Rect)
	{

		ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);
		std::string weaponIcon = GunIcon("ak47");

		// box
		if (ESPConfig::FilledBox) {
			float Rounding = ESPConfig::BoxRounding;
			if (MenuConfig::BoxType == 2 || MenuConfig::BoxType == 3)
				Rounding = 0.f;
			ImColor FlatBoxCol = ESPConfig::FilledColor;
			ImColor FlatBoxCol2 = ESPConfig::FilledColor2;
			ImColor FlatBoxVisCol = ESPConfig::BoxFilledVisColor;
			if (ESPConfig::FilledVisBox) {
				Gui.RectangleFilled({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxCol, Rounding , true);
			}
			else {
				if (ESPConfig::MultiColor)
				{
					Gui.RectangleFilledGraident({ Rect.x, Rect.y }, { Rect.z, Rect.w }, ESPConfig::BoxColor, FlatBoxCol, FlatBoxCol2, Rounding, true);
				}
				else
				{
					Gui.RectangleFilled({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxCol, Rounding, true);
				}
			}
		}
		if (ESPConfig::ShowBoxESP)
		{
			if (MenuConfig::BoxType == 0 || MenuConfig::BoxType == 1)
			{
				if (ESPConfig::OutLine)
					Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, ESPConfig::BoxRounding, true);

				if (ESPConfig::VisibleCheck)
				{
					Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, ESPConfig::VisibleColor, 1.3, ESPConfig::BoxRounding, true);
				}
				else {
					Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, ESPConfig::BoxColor, 1.3, ESPConfig::BoxRounding, true);
				}
			}
			else if (MenuConfig::BoxType == 2 || MenuConfig::BoxType == 3)
			{
				//Outline
				Gui.Line({ Rect.x, Rect.y }, { Rect.x + Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);
				Gui.Line({ Rect.x, Rect.y }, { Rect.x, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);
				Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);
				Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);
				Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x + Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);
				Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);
				Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);
				Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, true);

				// Main Box Lines
				if (ESPConfig::VisibleCheck)
				{
					Gui.Line({ Rect.x, Rect.y }, { Rect.x + Rect.z * 0.25f, Rect.y }, ESPConfig::VisibleColor, 1.3f, true);
					Gui.Line({ Rect.x, Rect.y }, { Rect.x, Rect.y + Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y }, ESPConfig::VisibleColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z, Rect.y + Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f, true);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x + Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::VisibleColor, 1.3f, true);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::VisibleColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::VisibleColor, 1.3f, true);
				}
				else {
					Gui.Line({ Rect.x, Rect.y }, { Rect.x + Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor, 1.3f, true);
					Gui.Line({ Rect.x, Rect.y }, { Rect.x, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y }, ESPConfig::BoxColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y }, { Rect.x + Rect.z, Rect.y + Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f, true);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x + Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor, 1.3f, true);
					Gui.Line({ Rect.x, Rect.y + Rect.w }, { Rect.x, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z - Rect.z * 0.25f, Rect.y + Rect.w }, ESPConfig::BoxColor, 1.3f, true);
					Gui.Line({ Rect.x + Rect.z, Rect.y + Rect.w }, { Rect.x + Rect.z, Rect.y + Rect.w - Rect.w * 0.25f }, ESPConfig::BoxColor, 1.3f, true);
				}
			}
		}


		Render::LineToEnemy(Rect, ESPConfig::LineToEnemyColor, 1.2 , true);

		if (ESPConfig::ShowWeaponESP)
		{
			if (MenuConfig::HealthBarType == 0 || MenuConfig::HealthBarType == 1)
			{
				WeaponIconSize iconSize = weaponIconSizes["ak47"];
				ImVec2 textPosition = { Rect.x + (Rect.z - iconSize.width) / 2 + iconSize.offsetX, Rect.y + Rect.w + 1 + iconSize.offsetY };
				if (ESPConfig::AmmoBar)
					textPosition.y += 5;
				// Gui.StrokeText(Entity.Pawn.WeaponName, { Rect.x + Rect.z / 2,Rect.y + Rect.w + 10}, ImColor(255, 255, 255, 255), 14, true);
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x - 1, textPosition.y - 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x - 1, textPosition.y + 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x + 1, textPosition.y + 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x + 1, textPosition.y - 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPosition, ImColor(255, 255, 255, 255), weaponIcon.c_str());
			}
		}

		if (ESPConfig::ShowIsScoped)
		{
			bool isScoped = true;
			ImVec2 IconPos = { Rect.x, Rect.y };
			if (isScoped)
			{
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x - 1, IconPos.y - 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x - 1, IconPos.y + 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x + 1, IconPos.y + 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, ImVec2{ IconPos.x + 1, IconPos.y - 1 }, ImColor(0, 0, 0, 255), "s");
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 13.0f, IconPos, ImColor(0, 200, 255, 255), "s");
			}
		}


		if (ESPConfig::ShowPlayerName)
		{
			char Name[64] = "Not ";
			strcat(Name, MenuConfig::UserName.c_str());
			if (MenuConfig::HealthBarType == 0)
				Gui.StrokeText(Name, { Rect.x + Rect.z / 2,Rect.y - 14 }, ImColor(255, 255, 255, 255), 14, true, true);
			else
				Gui.StrokeText(Name, { Rect.x + Rect.z / 2,Rect.y - 13 - 14 }, ImColor(255, 255, 255, 255), 14, true, true);
		}

		if (ESPConfig::ShowDistance) {
			int distance = 1337;
			std::string dis_str = Format("%im", distance);
			Gui.StrokeText(dis_str, { Rect.x + Rect.z + 4, Rect.y }, ImColor(255, 204, 0, 255), 14, false);
		}

		// Draw HealthBar
		if (ESPConfig::ShowHealthBar)
		{
			const int HealthFactor = std::ceil(100 * (sin(ImGui::GetTime()) + 1.0f) / 2.0f);
			ImVec2 HealthBarPos = { Rect.x - 6.f,Rect.y };
			ImVec2 HealthBarSize = { 4 ,Rect.w };
			Render::DrawHealthBar(0, 100, HealthFactor, HealthBarPos, HealthBarSize);
		}

		// Draw Ammo
		// When player is using knife or nade, Ammo = -1.
		if (ESPConfig::AmmoBar)
		{
			const int AmmoFactor = std::ceil(30 * (sin(ImGui::GetTime()) + 1.0f) / 2.0f);
			ImVec2 AmmoBarPos = { Rect.x, Rect.y + Rect.w + 2 };
			ImVec2 AmmoBarSize = { Rect.z,4 };
			if (AmmoFactor > 0)
				Render::DrawAmmoBar(0, 30, AmmoFactor, AmmoBarPos, AmmoBarSize);
		}

		// Draw Armor
		// It is meaningless to render a empty bar
		if (ESPConfig::ArmorBar)
		{
			const int ArmorFactor = std::ceil(100 * (sin(ImGui::GetTime()) + 1.0f) / 2.0f);
			const bool HasHelmet = ArmorFactor > 50;
			ImVec2 ArmorBarPos;
			ArmorBarPos = { Rect.x + Rect.z + 2.f,Rect.y };
			ImVec2 ArmorBarSize = { 4.f,Rect.w };
			if (ArmorFactor > 0)
				Render::DrawArmorBar(0, 100, ArmorFactor, HasHelmet, ArmorBarPos, ArmorBarSize);
		}
		ImGui::PopFont();
	}

}
