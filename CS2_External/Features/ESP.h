#pragma once
#include "..\Render.hpp"
#include "..\MenuConfig.hpp"
#include "..\Cheats.h"
#include "GetWeaponIcon.h"
#define ICON_FA_EYE "\xef\x81\xae"

namespace ESP
{
	struct WeaponIconSize
	{
		float width;
		float height;
		float offsetX;
		float offsetY;
	};
	std::unordered_map<std::string, WeaponIconSize> weaponIconSizes = {
		{"knife", {20.0f, 20.0f, -8.0f, 0.0f}},
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
		ProcessMgr.ReadMemory(Entity.Pawn.Address + Offset::Pawn.pClippingWeapon, ClippingWeapon);
		ProcessMgr.ReadMemory(ClippingWeapon + 0x360, WeaponData);
		ProcessMgr.ReadMemory(WeaponData + Offset::WeaponBaseData.m_szName, WeaponNameAddress);
		std::string weaponName = "Invalid Weapon Name";

		if (!WeaponNameAddress)
		{
			weaponName = "NULL";
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
				if ((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) ||
					(LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex))) {

					Gui.RectangleFilled({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxVisCol, Rounding);
				}
				else {
					Gui.RectangleFilled({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxCol, Rounding);
				}
			}
			else {
				if (ESPConfig::MultiColor)
				{
					Gui.RectangleFilledGraident({ Rect.x, Rect.y }, { Rect.z, Rect.w }, FlatBoxCol, FlatBoxCol2, Rounding);
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
				Gui.Rectangle({ Rect.x,Rect.y }, { Rect.z,Rect.w }, ESPConfig::BoxColor & IM_COL32_A_MASK, 3, ESPConfig::BoxRounding);
				if (((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) && ESPConfig::VisibleCheck)
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
				if (((Entity.Pawn.bSpottedByMask & (DWORD64(1) << LocalPlayerControllerIndex)) || (LocalEntity.Pawn.bSpottedByMask & (DWORD64(1) << Index))) && ESPConfig::VisibleCheck)
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
		}


		Render::LineToEnemy(Rect, MenuConfig::LineToEnemyColor, 1.2);

		if (ESPConfig::ShowWeaponESP)
		{
			if (MenuConfig::HealthBarType == 0 || MenuConfig::HealthBarType == 1)
			{
				WeaponIconSize iconSize = weaponIconSizes[Entity.Pawn.WeaponName];
				ImVec2 textPosition = { Rect.x + (Rect.z - iconSize.width) / 2 + iconSize.offsetX, Rect.y + Rect.w + 1 + iconSize.offsetY };

				//Gui.StrokeText(Entity.Pawn.WeaponName, { Rect.x + Rect.z / 2,Rect.y + Rect.w }, ImColor(255, 255, 255, 255), 14, true);
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x - 1, textPosition.y - 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x - 1, textPosition.y + 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x + 1, textPosition.y + 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, ImVec2{ textPosition.x + 1, textPosition.y - 1 }, ImColor(0, 0, 0, 255), weaponIcon.c_str());
				ImGui::GetBackgroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPosition, ImColor(255, 255, 255, 255), weaponIcon.c_str());
			}
		}
			


		if (ESPConfig::ShowPlayerName)
		{
			if (MenuConfig::HealthBarType == 0)
				Gui.StrokeText(Entity.Controller.PlayerName, { Rect.x + Rect.z / 2,Rect.y - 14 }, ImColor(255, 255, 255, 255), 14, true);
			else
				Gui.StrokeText(Entity.Controller.PlayerName, { Rect.x + Rect.z / 2,Rect.y - 13 - 14 }, ImColor(255, 255, 255, 255), 14, true);
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

	void RenderPreview(ImVec2 windowSize)
	{
		if (!ESPConfig::ShowPreview)
			return;

		ImVec2 rectSize(100, 150);
		ImVec2 rectPos((windowSize.x - rectSize.x) * 0.45f, (windowSize.y - rectSize.y) * 0.3f);
		ImVec2 centerPos = ImGui::GetCursorScreenPos();
		centerPos.x += rectPos.x;
		centerPos.y += rectPos.y * -1.20f;

		if (ESPConfig::ShowEyeRay) {
			ImU32 EyeC = ESPConfig::EyeRayColor;
			ImVec2 lineStart(centerPos.x + 44, centerPos.y + 15);
			ImVec2 lineEnd(centerPos.x - 10, centerPos.y + 20);
			ImGui::GetWindowDrawList()->AddLine(lineStart, lineEnd, EyeC, 2.0f);
		}
		if (ESPConfig::ShowBoneESP) {
			ImU32 boneColor = ESPConfig::BoneColor;
			ImVec2 SpineStart(centerPos.x + 50, centerPos.y + 25);
			ImVec2 SpineEnd(centerPos.x + 60, centerPos.y + 55);
			ImGui::GetWindowDrawList()->AddLine(SpineStart, SpineEnd, boneColor, 1.8f); // Neck to Spine
			ImVec2 PelvisStart(centerPos.x + 60, centerPos.y + 55);
			ImVec2 PelvisEnd(centerPos.x + 62, centerPos.y + 65);
			ImGui::GetWindowDrawList()->AddLine(PelvisStart, PelvisEnd, boneColor, 1.8f); // Spine to Pelvis
			ImVec2 UL_LegStart(centerPos.x + 62, centerPos.y + 65);
			ImVec2 UL_LegEnd(centerPos.x + 65, centerPos.y + 70);
			ImGui::GetWindowDrawList()->AddLine(UL_LegStart, UL_LegEnd, boneColor, 1.8f); // Left Leg_Up
			ImVec2 ML_LegStart(centerPos.x + 65, centerPos.y + 70);
			ImVec2 ML_LegEnd(centerPos.x + 60, centerPos.y + 100);
			ImGui::GetWindowDrawList()->AddLine(ML_LegStart, ML_LegEnd, boneColor, 1.8f); // Left Leg_Mid
			ImVec2 DL_LegStart(centerPos.x + 60, centerPos.y + 100);
			ImVec2 DL_LegEnd(centerPos.x + 68, centerPos.y + 145);
			ImGui::GetWindowDrawList()->AddLine(DL_LegStart, DL_LegEnd, boneColor, 1.8f); // Left Leg_Down
			ImVec2 UR_LegStart(centerPos.x + 62, centerPos.y + 65);
			ImVec2 UR_LegEnd(centerPos.x + 35, centerPos.y + 100);
			ImGui::GetWindowDrawList()->AddLine(UR_LegStart, UR_LegEnd, boneColor, 1.8f); // Right Leg_Up
			ImVec2 DR_LegStart(centerPos.x + 35, centerPos.y + 100);
			ImVec2 DR_LegEnd(centerPos.x + 47, centerPos.y + 130);
			ImGui::GetWindowDrawList()->AddLine(DR_LegStart, DR_LegEnd, boneColor, 1.8f); // Right Leg_Down
			ImVec2 L_ScapulaStart(centerPos.x + 50, centerPos.y + 25);
			ImVec2 L_ScapulaEnd(centerPos.x + 60, centerPos.y + 30);
			ImGui::GetWindowDrawList()->AddLine(L_ScapulaStart, L_ScapulaEnd, boneColor, 1.8f); // Left Scapula
			ImVec2 UL_ArmStart(centerPos.x + 60, centerPos.y + 30);
			ImVec2 UL_ArmEnd(centerPos.x + 45, centerPos.y + 55);
			ImGui::GetWindowDrawList()->AddLine(UL_ArmStart, UL_ArmEnd, boneColor, 1.8f); // Left Arm_Up
			ImVec2 DL_ArmStart(centerPos.x + 45, centerPos.y + 55);
			ImVec2 DL_ArmEnd(centerPos.x + 25, centerPos.y + 45);
			ImGui::GetWindowDrawList()->AddLine(DL_ArmStart, DL_ArmEnd, boneColor, 1.8f); // Left Arm_Down
			ImVec2 R_ScapulaStart(centerPos.x + 50, centerPos.y + 25);
			ImVec2 R_ScapulaEnd(centerPos.x + 40, centerPos.y + 30);
			ImGui::GetWindowDrawList()->AddLine(R_ScapulaStart, R_ScapulaEnd, boneColor, 1.8f); // Right Scapula
			ImVec2 UR_ArmStart(centerPos.x + 40, centerPos.y + 30);
			ImVec2 UR_ArmEnd(centerPos.x + 27, centerPos.y + 53);
			ImGui::GetWindowDrawList()->AddLine(UR_ArmStart, UR_ArmEnd, boneColor, 1.8f); // Right Arm_Up
			ImVec2 DR_ArmStart(centerPos.x + 27, centerPos.y + 53);
			ImVec2 DR_ArmEnd(centerPos.x + 20, centerPos.y + 45);
			ImGui::GetWindowDrawList()->AddLine(DR_ArmStart, DR_ArmEnd, boneColor, 1.8f); // Right Arm_Down
		}
		if (ESPConfig::ShowPenis)
		{
			ImU32 PenisCol = ESPConfig::PenisColor;
			ImVec2 BoneStart(centerPos.x + 62, centerPos.y + 65);
			ImVec2 BoneEnd(BoneStart.x - 30, BoneStart.y + 5);
			ImGui::GetWindowDrawList()->AddLine(BoneStart, BoneEnd, PenisCol, 2.0f);
		}
		if (ESPConfig::ShowHeadBox) {
			switch (ESPConfig::HeadBoxStyle)
			{
			case 0:
				ImGui::GetWindowDrawList()->AddCircle({ centerPos.x + 44, centerPos.y + 17 }, 12.0f, ESPConfig::HeadBoxColor, 0, 1.8f);
				break;
			case 1:
				ImGui::GetWindowDrawList()->AddCircleFilled({ centerPos.x + 44, centerPos.y + 17 }, 12.0f, ESPConfig::HeadBoxColor, 0);
			default:
				break;
			}

		}

		if (ESPConfig::FilledBox) {
			ImVec2 rectStartPos;
			ImVec2 rectEndPos;
			ImColor filledBoxColor = { ESPConfig::FilledColor.Value.x, ESPConfig::FilledColor.Value.y, ESPConfig::FilledColor.Value.z, ESPConfig::FilledColor.Value.w };
			ImColor filledBoxColor2 = { ESPConfig::FilledColor2.Value.x, ESPConfig::FilledColor2.Value.y, ESPConfig::FilledColor2.Value.z, ESPConfig::FilledColor2.Value.w };

			rectStartPos = centerPos;
			rectEndPos = { rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y };

			if (MenuConfig::BoxType == 0)
			{
				if (ESPConfig::MultiColor && ESPConfig::BoxRounding == 0)
				{
					ImGui::GetWindowDrawList()->AddRectFilledMultiColor(rectStartPos, rectEndPos, filledBoxColor, filledBoxColor, filledBoxColor2, filledBoxColor2);
				}
				else {
					ImGui::GetWindowDrawList()->AddRectFilled(rectStartPos, rectEndPos, filledBoxColor, ESPConfig::BoxRounding);
				}
			}
			else if (MenuConfig::BoxType == 1)
			{
				rectStartPos = { centerPos.x + 20, centerPos.y + 15 };
				rectEndPos = { rectStartPos.x + 50, rectStartPos.y + 132 };
				if (ESPConfig::MultiColor && ESPConfig::BoxRounding == 0)
				{
					ImGui::GetWindowDrawList()->AddRectFilledMultiColor(rectStartPos, rectEndPos, filledBoxColor, filledBoxColor, filledBoxColor2, filledBoxColor2);
				}
				else {
					ImGui::GetWindowDrawList()->AddRectFilled(rectStartPos, rectEndPos, filledBoxColor, ESPConfig::BoxRounding);
				}
			}
			else if (MenuConfig::BoxType == 2)
			{
				if (ESPConfig::MultiColor && ESPConfig::BoxRounding == 0)
				{
					ImGui::GetWindowDrawList()->AddRectFilledMultiColor(rectStartPos, rectEndPos, filledBoxColor, filledBoxColor, filledBoxColor2, filledBoxColor2);
				}
				else {
					ImGui::GetWindowDrawList()->AddRectFilled(rectStartPos, rectEndPos, filledBoxColor, 0);
				}
			}
		}

		if (ESPConfig::ShowBoxESP) {
			ImVec2 rectStartPos;
			ImVec2 rectEndPos;
			ImColor boxColor = ESPConfig::BoxColor;

			rectStartPos = centerPos;
			rectEndPos = { rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y };

			switch (MenuConfig::BoxType)
			{
			case 0:
				DrawPreviewBox(rectStartPos, rectEndPos, boxColor, ESPConfig::BoxRounding, 1.3f, false);
				break;
			case 1:
				//DrawPreviewBox(rectStartPos, rectEndPos, boxColor, ESPConfig::BoxRounding, 1.3f, false);
				rectStartPos = { centerPos.x + 20, centerPos.y + 15 };
				rectEndPos = { rectStartPos.x + 50, rectStartPos.y + 132 };
				DrawPreviewBox(rectStartPos, rectEndPos, boxColor, ESPConfig::BoxRounding, 1.0f, false);
				break;
			case 2:
				ImGui::GetWindowDrawList()->AddLine(rectStartPos, { rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine(rectStartPos, { rectStartPos.x, rectStartPos.y + rectSize.y * 0.25f }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y }, { rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y + rectSize.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y }, { rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.75f }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x, rectStartPos.y + rectSize.y }, { rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y + rectSize.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x, rectStartPos.y + rectSize.y }, { rectStartPos.x, rectStartPos.y + rectSize.y * 0.75f }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y }, { rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y }, { rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.25f }, boxColor, 1.3f);
				break;
			case 3:
				ImGui::GetWindowDrawList()->AddLine(rectStartPos, { rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine(rectStartPos, { rectStartPos.x, rectStartPos.y + rectSize.y * 0.25f }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y }, { rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y + rectSize.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y }, { rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.75f }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x, rectStartPos.y + rectSize.y }, { rectStartPos.x + rectSize.x * 0.25f, rectStartPos.y + rectSize.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x, rectStartPos.y + rectSize.y }, { rectStartPos.x, rectStartPos.y + rectSize.y * 0.75f }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y }, { rectStartPos.x + rectSize.x * 0.75f, rectStartPos.y }, boxColor, 1.3f);
				ImGui::GetWindowDrawList()->AddLine({ rectStartPos.x + rectSize.x, rectStartPos.y }, { rectStartPos.x + rectSize.x, rectStartPos.y + rectSize.y * 0.25f }, boxColor, 1.3f);
				break;
			}
		}
		if (ESPConfig::ShowHealthBar) {
			ImU32 greenColor = IM_COL32(0, 255, 0, 255);
			ImVec2 HBPos = centerPos;
			ImVec2 HBSize = rectSize;
			if (MenuConfig::BoxType == 1 || MenuConfig::BoxType == 3) {
				HBPos = { centerPos.x + 20, centerPos.y + 15 };
				HBSize = { rectSize.x - 2, rectSize.y - 18 };
			}
			if (MenuConfig::HealthBarType == 0) {
				ImVec2 HBS(HBPos.x - 6, HBPos.y);
				ImVec2 HBE(HBPos.x - 3, HBPos.y + HBSize.y);
				ImGui::GetWindowDrawList()->AddRectFilled(HBS, HBE, ImColor(96, 246, 113, 220), 30.f, ImDrawCornerFlags_All);
			}
			if (MenuConfig::HealthBarType == 1) {
				ImVec2 HBS(HBPos.x, HBPos.y - 6);
				ImVec2 HBE(HBPos.x + HBSize.x, HBPos.y - 3);
				ImGui::GetWindowDrawList()->AddRectFilled(HBS, HBE, ImColor(96, 246, 113, 220), 30.f, ImDrawCornerFlags_All);
			}
			if (MenuConfig::HealthBarType == 2) {
				ImVec2 HBS(HBPos.x, HBPos.y + HBSize.y + 6);
				ImVec2 HBE(HBPos.x + HBSize.x, HBPos.y + HBSize.y + 3);
				ImGui::GetWindowDrawList()->AddRectFilled(HBS, HBE, ImColor(96, 246, 113, 220), 30.f, ImDrawCornerFlags_All);
			}
		}
		if (MenuConfig::ShowLineToEnemy) {
			ImVec2 LineStart, LineEnd;
			LineStart = { centerPos.x + rectSize.x / 2 , centerPos.y };
			switch (MenuConfig::LinePos)
			{
			case 0:
				LineEnd = { LineStart.x, LineStart.y - 50 };
				break;
			case 1:
				LineEnd = { Gui.Window.Size.x, Gui.Window.Size.y };
				break;
			case 2:
				LineEnd = { LineStart.x, LineStart.y + 200 };
				break;
			}
			ImGui::GetWindowDrawList()->AddLine(LineStart, LineEnd, MenuConfig::LineToEnemyColor, 1.8f);
		}
		if (ESPConfig::ShowPlayerName) {
			if (MenuConfig::BoxType == 1 || MenuConfig::BoxType == 3) {
				centerPos.x -= 3;
				centerPos.y += 15;
			}
			if (MenuConfig::HealthBarType == 0 || MenuConfig::HealthBarType == 2) {
				ImVec2 textPos(centerPos.x + 30, centerPos.y - 18);
				ImGui::GetWindowDrawList()->AddText(textPos, IM_COL32(255, 255, 255, 255), "Player");
			}
			if (MenuConfig::HealthBarType == 1) {
				ImVec2 textPos(centerPos.x + 30, centerPos.y - 22);
				ImGui::GetWindowDrawList()->AddText(textPos, IM_COL32(255, 255, 255, 255), "Player");
			}
		}
		if (ESPConfig::ShowDistance) {
			ImVec2 textPos(centerPos.x + 105, centerPos.y);
			if (MenuConfig::BoxType == 1 || MenuConfig::BoxType == 3)
			{
				textPos = { textPos.x - 27, textPos.y };
			}
			ImGui::GetWindowDrawList()->AddText(textPos, IM_COL32(255, 204, 0, 255), "20m");
		}
		if (ESPConfig::ShowWeaponESP) {
			if (MenuConfig::BoxType == 1 || MenuConfig::BoxType == 3) {
				centerPos.x -= 3;
				centerPos.y -= 20;
			}
			if (MenuConfig::HealthBarType == 2) {
				ImVec2 textPos(centerPos.x + 27, centerPos.y + 155);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPos, IM_COL32(255, 255, 255, 255), "W");
			}
			if (MenuConfig::HealthBarType == 0 || MenuConfig::HealthBarType == 1) {
				ImVec2 textPos(centerPos.x + 27, centerPos.y + 150);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[1], 15.0f, textPos, IM_COL32(255, 255, 255, 255), "W");
			}
		}
	}
}