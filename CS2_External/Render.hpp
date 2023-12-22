#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <chrono>
#include <map>
#include <Windows.h>
#include "Entity.h"
#include "Utils/Format.h"
#include "OS-ImGui/imgui/imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "OS-ImGui/imgui/imgui_internal.h"
#include "TriggerBot.h"

namespace Render
{

	void DrawHeadCircle(const CEntity& Entity, ImColor Color)
	{
		if (!ESPConfig::ShowHeadBox)
			return;

		Vec2 CenterPos;
		Vec3 Temp;
		BoneJointPos Head = Entity.GetBone().BonePosList[BONEINDEX::head];
		BoneJointPos Neck = Entity.GetBone().BonePosList[BONEINDEX::neck_0];

		CenterPos = Head.ScreenPos;
		float Radius = abs(Head.ScreenPos.y - Neck.ScreenPos.y) + 2;

		switch (ESPConfig::HeadBoxStyle)
		{
		case 1:
			Gui.CircleFilled(CenterPos, Radius + 1, Color & IM_COL32_A_MASK);
			Gui.CircleFilled(CenterPos, Radius, Color);
			break;
		default:
			Gui.Circle(CenterPos, Radius, Color, 1.2);
		}
		
	}

	void DrawDistance(const CEntity& LocalEntity, CEntity& Entity, ImVec4 Rect)
	{
		if (!ESPConfig::ShowDistance)
			return;

		int distance = static_cast<int>(Entity.Pawn.Pos.DistanceTo(LocalEntity.Pawn.Pos) / 100);
		std::string dis_str = Format("%im", distance);
		Gui.StrokeText(dis_str, { Rect.x + Rect.z + 4, Rect.y }, ImColor(255, 204, 0, 255), 14, false);
	}

	void DrawFovCircle(const CEntity& LocalEntity)
	{
		if (!ESPConfig::DrawFov)
			return;

		Vec2 CenterPoint = Gui.Window.Size / 2;
		float Radius = tan(AimControl::AimFov / 180.f * M_PI / 2.f) / tan(LocalEntity.Pawn.Fov / 180.f * M_PI / 2.f) * Gui.Window.Size.x;
		Gui.Circle(CenterPoint, Radius, MenuConfig::FovCircleColor, 1);
	}

	void DrawCrossHair(ImDrawList* drawList, const ImVec2& pos, ImU32 color) noexcept
	{
		int BorderWidth = 2;
		int DotSize = 1;
		int gap = MenuConfig::Crosshairs.Gap / 2;

		int outlineGap = gap - 1;
		float Thickness = MenuConfig::Crosshairs.Thickness;

		ImVec2 offset1{ MenuConfig::Crosshairs.DotSize,MenuConfig::Crosshairs.DotSize };
		ImVec2 offset2{ MenuConfig::Crosshairs.DotSize + 1,MenuConfig::Crosshairs.DotSize + 1 };

		/*
		===== Outline =====
		*/
		if (MenuConfig::Crosshairs.drawOutLine)
		{
			//dot
			if (MenuConfig::Crosshairs.drawDot)
				drawList->AddRectFilled(ImVec2(pos.x - offset1.x, pos.y - offset1.y), ImVec2(pos.x + offset2.x, pos.y + offset2.y), color & IM_COL32_A_MASK);

			if (MenuConfig::Crosshairs.drawCrossline)
			{
				//left
				drawList->AddRectFilled(ImVec2(pos.x - (outlineGap + BorderWidth + MenuConfig::Crosshairs.HorizontalLength), pos.y - Thickness), ImVec2(pos.x - outlineGap, pos.y + 1 + Thickness), color & IM_COL32_A_MASK);
				//right
				drawList->AddRectFilled(ImVec2(pos.x + (outlineGap + DotSize), pos.y - Thickness), ImVec2(pos.x + (outlineGap + DotSize + BorderWidth + MenuConfig::Crosshairs.HorizontalLength), pos.y + 1 + Thickness), color & IM_COL32_A_MASK);
				//top
				if (!MenuConfig::Crosshairs.tStyle)
					drawList->AddRectFilled(ImVec2(pos.x - Thickness, pos.y - (outlineGap + BorderWidth + MenuConfig::Crosshairs.VerticalLength)), ImVec2(pos.x + 1 + Thickness, pos.y - outlineGap), color & IM_COL32_A_MASK);
				//bottom
				drawList->AddRectFilled(ImVec2(pos.x - Thickness, pos.y + outlineGap + DotSize), ImVec2(pos.x + 1 + Thickness, pos.y + (outlineGap + DotSize + BorderWidth + MenuConfig::Crosshairs.VerticalLength)), color & IM_COL32_A_MASK);
			}
						
			//circle
			if (MenuConfig::Crosshairs.drawCircle)
				drawList->AddCircle(ImVec2(pos.x, pos.y), MenuConfig::Crosshairs.CircleRadius, color & IM_COL32_A_MASK, 0, 3.0f);
		}

		/*
		===== Crosshair =====
		*/
		// dot
		if (MenuConfig::Crosshairs.drawDot)
			drawList->AddRectFilled(ImVec2(pos.x - offset1.x + DotSize, pos.y - offset1.y + DotSize), ImVec2(pos.x + offset1.x, pos.y + offset1.y), color);

		if (MenuConfig::Crosshairs.drawCrossline)
		{
			// left
			drawList->AddRectFilled(ImVec2(pos.x - (gap + MenuConfig::Crosshairs.HorizontalLength), pos.y - Thickness + 1), ImVec2(pos.x - gap, pos.y + Thickness), color);
			// right
			drawList->AddRectFilled(ImVec2(pos.x + gap + DotSize, pos.y - Thickness + 1), ImVec2(pos.x + (gap + DotSize + MenuConfig::Crosshairs.HorizontalLength), pos.y + Thickness), color);
			// top
			if (!MenuConfig::Crosshairs.tStyle)
				drawList->AddRectFilled(ImVec2(pos.x - Thickness + 1, pos.y - (gap + MenuConfig::Crosshairs.VerticalLength)), ImVec2(pos.x + Thickness, pos.y - gap), color);
			// bottom
			drawList->AddRectFilled(ImVec2(pos.x - Thickness + 1, pos.y + gap + DotSize), ImVec2(pos.x + Thickness, pos.y + (gap + DotSize + MenuConfig::Crosshairs.VerticalLength)), color);
		}
		
		// circle
		if (MenuConfig::Crosshairs.drawCircle)
			drawList->AddCircle(ImVec2(pos.x, pos.y), MenuConfig::Crosshairs.CircleRadius, color, 0, 1.0f);
	}

	void DrawCrossHair2D()
	{
		Vec2 SightPos = Gui.Window.Size / 2;
		Gui.Line({ SightPos.x - MenuConfig::Crosshairs.CrossHairSize,SightPos.y }, { SightPos.x + MenuConfig::Crosshairs.CrossHairSize,SightPos.y }, MenuConfig::Crosshairs.CrossHairColor, 1);
		Gui.Line({ SightPos.x,SightPos.y - MenuConfig::Crosshairs.CrossHairSize }, { SightPos.x ,SightPos.y + MenuConfig::Crosshairs.CrossHairSize }, MenuConfig::Crosshairs.CrossHairColor, 1);
	}

	void LineToEnemy(ImVec4 Rect, ImColor Color, float Thickness)
	{
		if (!MenuConfig::ShowLineToEnemy)
			return;

		switch (MenuConfig::LinePos)
		{
		case 0:
			Gui.Line({ Rect.x + Rect.z / 2,Rect.y }, { Gui.Window.Size.x / 2,0 }, Color, Thickness);
			break;
		case 1:
			Gui.Line({ Rect.x + Rect.z / 2,Rect.y }, { Gui.Window.Size.x / 2, Gui.Window.Size.y/2 }, Color, Thickness);
			break;
		case 2:
			Gui.Line({ Rect.x + Rect.z / 2,Rect.y }, { Gui.Window.Size.x / 2, Gui.Window.Size.y }, Color, Thickness);
			break;
		default:
			break;
		}
		
	}

	void DrawFov(const CEntity& LocalEntity, float Size, ImColor Color, float Thickness)
	{
		if (!MenuConfig::ShowFovLine)
			return;

		float Length;
		float radian;
		Vec2 LineEndPoint[2];
		Vec2 Pos = Gui.Window.Size / 2;

		radian = (LocalEntity.Pawn.Fov / 2) * M_PI / 180;

		LineEndPoint[0].y = Pos.y - Size;
		LineEndPoint[1].y = LineEndPoint[0].y;

		Length = Size * tan(radian);

		LineEndPoint[0].x = Pos.x - Length;
		LineEndPoint[1].x = Pos.x + Length;

		Gui.Line(Pos, LineEndPoint[0], Color, 1.5);
		Gui.Line(Pos, LineEndPoint[1], Color, 1.5);
	}

	void HeadShootLine(const CEntity& LocalEntity, ImColor Color)
	{
		if (!MenuConfig::ShowHeadShootLine)
			return;

		Vec2 Pos;
		Pos.x = Gui.Window.Size.x / 2;
		Pos.y = Gui.Window.Size.y / 2.0f - Gui.Window.Size.y / (2.0f * std::sin(LocalEntity.Pawn.Fov * M_PI / 180.0f) / std::sin(90.0f * M_PI / 180.0f)) * std::sin(LocalEntity.Pawn.ViewAngle.x * M_PI / 180.0f) / std::sin(90.0f * M_PI / 180.0f);

		// left
		Gui.RectangleFilled(Vec2{ Pos.x - 21, Pos.y - 1 }, Vec2{ 17, 3}, Color & IM_COL32_A_MASK);
		Gui.RectangleFilled(Vec2{ Pos.x - 20, Pos.y }, Vec2{ 17, 3 }, Color);

		// right
		Gui.RectangleFilled(Vec2{ Pos.x + 5, Pos.y - 1 }, Vec2{ 17, 3 }, Color & IM_COL32_A_MASK);
		Gui.RectangleFilled(Vec2{ Pos.x + 6, Pos.y }, Vec2{ 17, 3 }, Color);
	}

	// �������
	ImVec4 Get2DBox(const CEntity& Entity)
	{
		BoneJointPos Head = Entity.GetBone().BonePosList[BONEINDEX::head];

		Vec2 Size, Pos;
		Size.y = (Entity.Pawn.ScreenPos.y - Head.ScreenPos.y) * 1.09;
		Size.x = Size.y * 0.6;

		Pos = ImVec2(Entity.Pawn.ScreenPos.x - Size.x / 2, Head.ScreenPos.y- Size.y*0.08);

		return ImVec4{ Pos.x,Pos.y,Size.x,Size.y };
	}

	// ��������
	void DrawBone(const CEntity& Entity, ImColor Color, float Thickness)
	{
		if (!ESPConfig::ShowBoneESP)
			return;

		BoneJointPos Previous, Current;
		for (auto i : BoneJointList::List)
		{
			Previous.Pos = Vec3(0, 0, 0);
			for (auto Index : i)
			{
				Current = Entity.GetBone().BonePosList[Index];
				if (Previous.Pos == Vec3(0, 0, 0))
				{
					Previous = Current;
					//pGame->View->Gui->Text(Current.Name.c_str(), Current.ScreenPos, ImColor(255, 255, 0, 255));
					continue;
				}
				if (Previous.IsVisible && Current.IsVisible)
				{
					Gui.Line(Previous.ScreenPos, Current.ScreenPos, Color, Thickness);
					//pGame->View->Gui->Text(Current.Name.c_str(), Current.ScreenPos, ImColor(255, 255, 0, 255));
				}
				Previous = Current;
			}
		}
	}

	// �������
	void ShowLosLine(const CEntity& Entity, const float Length, ImColor Color, float Thickness)
	{
		if (!ESPConfig::ShowEyeRay)
			return;

		Vec2 StartPoint, EndPoint;
		Vec3 Temp;
		BoneJointPos Head = Entity.GetBone().BonePosList[BONEINDEX::head];

		StartPoint = Head.ScreenPos;

		float LineLength = cos(Entity.Pawn.ViewAngle.x * M_PI / 180) * Length;

		Temp.x = Head.Pos.x + cos(Entity.Pawn.ViewAngle.y * M_PI / 180) * LineLength;
		Temp.y = Head.Pos.y + sin(Entity.Pawn.ViewAngle.y * M_PI / 180) * LineLength;
		Temp.z = Head.Pos.z - sin(Entity.Pawn.ViewAngle.x * M_PI / 180) * Length;

		if (!gGame.View.WorldToScreen(Temp, EndPoint))
			return;

		Gui.Line(StartPoint, EndPoint, Color, Thickness);
	}

	//ţţ����
	void ShowPenis(const CEntity& Entity, const float Length, ImColor Color, float Thickness)
	{
		if (!ESPConfig::ShowPenis)
			return;

		Vec2 StartPoint, EndPoint;
		Vec3 Temp;
		BoneJointPos Dick = Entity.GetBone().BonePosList[BONEINDEX::pelvis];

		StartPoint = Dick.ScreenPos;

		float LineLength = cos(Entity.Pawn.ViewAngle.x * M_PI / 180) * Length;

		Temp.x = Dick.Pos.x + cos(Entity.Pawn.ViewAngle.y * M_PI / 180) * LineLength;
		Temp.y = Dick.Pos.y + sin(Entity.Pawn.ViewAngle.y * M_PI / 180) * LineLength;
		Temp.z = Dick.Pos.z - sin(Entity.Pawn.ViewAngle.x * M_PI / 180) * Length;

		if (!gGame.View.WorldToScreen(Temp, EndPoint))
			return;

		Gui.Line(StartPoint, EndPoint, Color, Thickness);
	}

	// 2D���������
	ImVec4 Get2DBoneRect(const CEntity& Entity)
	{
		Vec2 Min, Max, Size;
		Min = Max = Entity.GetBone().BonePosList[0].ScreenPos;

		for (auto &BoneJoint : Entity.GetBone().BonePosList)
		{
			if (!BoneJoint.IsVisible)
				continue;
			Min.x = min(BoneJoint.ScreenPos.x, Min.x);
			Min.y = min(BoneJoint.ScreenPos.y, Min.y);
			Max.x = max(BoneJoint.ScreenPos.x, Max.x);
			Max.y = max(BoneJoint.ScreenPos.y, Max.y);
		}
		Size.x = Max.x - Min.x;
		Size.y = Max.y - Min.y;

		return ImVec4(Min.x, Min.y, Size.x, Size.y);
	}

	class HealthBar
	{
	private:
		using TimePoint_ = std::chrono::steady_clock::time_point;
	private:
		// ��ʾ����Ѫ��ʱ��(ms)
		const int ShowBackUpHealthDuration = 500;
		// ���Ѫ��
		float MaxHealth = 0.f;
		// ��ǰѪ��
		float CurrentHealth = 0.f;
		// �������Ѫ����С
		float LastestBackupHealth = 0.f;
		// Ѫ������
		ImVec2 RectPos{};
		// Ѫ����С
		ImVec2 RectSize{};
		// ������ʾ����Ѫ��
		bool InShowBackupHealth = false;
		// ��ʾ����Ѫ����ʼʱ���
		TimePoint_ BackupHealthTimePoint{};
	public:
		HealthBar() {}
		// ����
		void DrawHealthBar_Horizontal(float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size);
		// ����
		void DrawHealthBar_Vertical(float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size);
	private:
		// ��ɫ����
		ImColor Mix(ImColor Col_1, ImColor Col_2, float t);
		// ��һ�׶�Ѫ����ɫ 0.5-1
		ImColor FirstStageColor = ImColor(96, 246, 113, 220);
		// �ڶ��׶�Ѫ����ɫ 0.5-0.2
		ImColor SecondStageColor = ImColor(247, 214, 103, 220);
		// �����׶�Ѫ����ɫ 0.2-0.0
		ImColor ThirdStageColor = ImColor(255, 95, 95, 220);
		// ����Ѫ����ɫ
		ImColor BackupHealthColor = ImColor(255, 255, 255, 220);
		// �߿���ɫ
		ImColor FrameColor = ImColor(45, 45, 45, 220);
		// ������ɫ
		ImColor BackGroundColor = ImColor(90, 90, 90, 220);
	};

	void HealthBar::DrawHealthBar_Horizontal(float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size)
	{
		auto InRange = [&](float value, float min, float max) -> bool
		{
			return value > min && value <= max;
		};

		ImDrawList* DrawList = ImGui::GetBackgroundDrawList();

		this->MaxHealth = MaxHealth;
		this->CurrentHealth = CurrentHealth;
		this->RectPos = Pos;
		this->RectSize = Size;

		// ռ��
		float Proportion = CurrentHealth / MaxHealth;
		// Ѫ��������
		float Width = RectSize.x * Proportion;
		// Ѫ������ɫ
		ImColor Color;

		// ����
		DrawList->AddRectFilled(RectPos,
			{ RectPos.x + RectSize.x,RectPos.y + RectSize.y },
			BackGroundColor, 5, 15);

		// ��ɫ�л�
		float Color_Lerp_t = pow(Proportion, 2.5);
		if (InRange(Proportion, 0.5, 1))
			Color = Mix(FirstStageColor, SecondStageColor, Color_Lerp_t * 3 - 1);
		else
			Color = Mix(SecondStageColor, ThirdStageColor, Color_Lerp_t * 4);

		// �����������Ѫ��
		if (LastestBackupHealth == 0
			|| LastestBackupHealth < CurrentHealth)
			LastestBackupHealth = CurrentHealth;

		if (LastestBackupHealth != CurrentHealth)
		{
			if (!InShowBackupHealth)
			{
				BackupHealthTimePoint = std::chrono::steady_clock::now();
				InShowBackupHealth = true;
			}

			std::chrono::steady_clock::time_point CurrentTime = std::chrono::steady_clock::now();
			if (CurrentTime - BackupHealthTimePoint > std::chrono::milliseconds(ShowBackUpHealthDuration))
			{
				// ��ʱ��ֹͣ��ʾ����Ѫ�������Ҹ����������Ѫ��
				LastestBackupHealth = CurrentHealth;
				InShowBackupHealth = false;
			}

			if (InShowBackupHealth)
			{
				// ����Ѫ�����ƿ���
				float BackupHealthWidth = LastestBackupHealth / MaxHealth * RectSize.x;
				// ����Ѫ��alpha����
				float BackupHealthColorAlpha = 1 - 0.95 * (std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - BackupHealthTimePoint).count() / (float)ShowBackUpHealthDuration);
				ImColor BackupHealthColorTemp = BackupHealthColor;
				BackupHealthColorTemp.Value.w = BackupHealthColorAlpha;
				// ����Ѫ�����Ȼ���
				float BackupHealthWidth_Lerp = 1 * (std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - BackupHealthTimePoint).count() / (float)ShowBackUpHealthDuration);
				BackupHealthWidth_Lerp *= (BackupHealthWidth - Width);
				BackupHealthWidth -= BackupHealthWidth_Lerp;
				// ����Ѫ��
				DrawList->AddRectFilled(RectPos,
					{ RectPos.x + BackupHealthWidth,RectPos.y + RectSize.y },
					BackupHealthColorTemp, 5);
			}
		}

		// Ѫ��
		DrawList->AddRectFilled(RectPos,
			{ RectPos.x + Width,RectPos.y + RectSize.y },
			Color, 5);

		// �߿�
		DrawList->AddRect(RectPos,
			{ RectPos.x + RectSize.x,RectPos.y + RectSize.y },
			FrameColor, 5, 15, 1);
	}

	void HealthBar::DrawHealthBar_Vertical(float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size)
	{
		auto InRange = [&](float value, float min, float max) -> bool
		{
			return value > min && value <= max;
		};

		ImDrawList* DrawList = ImGui::GetBackgroundDrawList();

		this->MaxHealth = MaxHealth;
		this->CurrentHealth = CurrentHealth;
		this->RectPos = Pos;
		this->RectSize = Size;

		// ռ��
		float Proportion = CurrentHealth / MaxHealth;
		// Ѫ�����߶�
		float Height = RectSize.y * Proportion;
		// Ѫ������ɫ
		ImColor Color;

		// ����
		DrawList->AddRectFilled(RectPos,
			{ RectPos.x + RectSize.x,RectPos.y + RectSize.y },
			BackGroundColor, 5, 15);

		// ��ɫ�л�
		float Color_Lerp_t = pow(Proportion, 2.5);
		if (InRange(Proportion, 0.5, 1))
			Color = Mix(FirstStageColor, SecondStageColor, Color_Lerp_t * 3 - 1);
		else
			Color = Mix(SecondStageColor, ThirdStageColor, Color_Lerp_t * 4);

		// �����������Ѫ��
		if (LastestBackupHealth == 0
			|| LastestBackupHealth < CurrentHealth)
			LastestBackupHealth = CurrentHealth;

		if (LastestBackupHealth != CurrentHealth)
		{
			if (!InShowBackupHealth)
			{
				BackupHealthTimePoint = std::chrono::steady_clock::now();
				InShowBackupHealth = true;
			}

			std::chrono::steady_clock::time_point CurrentTime = std::chrono::steady_clock::now();
			if (CurrentTime - BackupHealthTimePoint > std::chrono::milliseconds(ShowBackUpHealthDuration))
			{
				// ��ʱ��ֹͣ��ʾ����Ѫ�������Ҹ����������Ѫ��
				LastestBackupHealth = CurrentHealth;
				InShowBackupHealth = false;
			}

			if (InShowBackupHealth)
			{
				// ����Ѫ�����Ƹ߶�
				float BackupHealthHeight = LastestBackupHealth / MaxHealth * RectSize.y;
				// ����Ѫ��alpha����
				float BackupHealthColorAlpha = 1 - 0.95 * (std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - BackupHealthTimePoint).count() / (float)ShowBackUpHealthDuration);
				ImColor BackupHealthColorTemp = BackupHealthColor;
				BackupHealthColorTemp.Value.w = BackupHealthColorAlpha;
				// ����Ѫ���߶Ȼ���
				float BackupHealthHeight_Lerp = 1 * (std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - BackupHealthTimePoint).count() / (float)ShowBackUpHealthDuration);
				BackupHealthHeight_Lerp *= (BackupHealthHeight - Height);
				BackupHealthHeight -= BackupHealthHeight_Lerp;
				// ����Ѫ��
				DrawList->AddRectFilled({ RectPos.x,RectPos.y + RectSize.y - BackupHealthHeight },
					{ RectPos.x + RectSize.x,RectPos.y + RectSize.y },
					BackupHealthColorTemp, 5);
			}
		}

		// Ѫ��
		DrawList->AddRectFilled({ RectPos.x,RectPos.y + RectSize.y - Height },
			{ RectPos.x + RectSize.x,RectPos.y + RectSize.y },
			Color, 5);

		// �߿�
		DrawList->AddRect(RectPos,
			{ RectPos.x + RectSize.x,RectPos.y + RectSize.y },
			FrameColor, 5, 15, 1);
	}

	ImColor HealthBar::Mix(ImColor Col_1, ImColor Col_2, float t)
	{
		ImColor Col;
		Col.Value.x = t * Col_1.Value.x + (1 - t) * Col_2.Value.x;
		Col.Value.y = t * Col_1.Value.y + (1 - t) * Col_2.Value.y;
		Col.Value.z = t * Col_1.Value.z + (1 - t) * Col_2.Value.z;
		Col.Value.w = Col_1.Value.w;
		return Col;
	}

	// Sign�����κ����͵��˱�ʶ��Ĭ�Ͽɴ����˵�ַ
	void DrawHealthBar(DWORD Sign, float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size, bool Horizontal)
	{
		static std::map<DWORD, HealthBar> HealthBarMap;
		if (!HealthBarMap.count(Sign))
		{
			HealthBarMap.insert({ Sign,HealthBar() });
		}
		if (HealthBarMap.count(Sign))
		{
			if (Horizontal)
				HealthBarMap[Sign].DrawHealthBar_Horizontal(MaxHealth, CurrentHealth, Pos, Size);
			else
				HealthBarMap[Sign].DrawHealthBar_Vertical(MaxHealth, CurrentHealth, Pos, Size);
		}
	}

	// Update crosshair preset
	void UpdateCrosshairPreset(int style)
	{
		switch (style) {
		case 1:
			MenuConfig::Crosshairs.drawDot = true;
			MenuConfig::Crosshairs.DotSize = 2;
			MenuConfig::Crosshairs.drawOutLine = true;
			MenuConfig::Crosshairs.drawCrossline = false;
			MenuConfig::Crosshairs.drawCircle = false;
			MenuConfig::TargetingCrosshairs = true;
			break;
		case 2:
			MenuConfig::Crosshairs.drawDot = true;
			MenuConfig::Crosshairs.DotSize = 2;
			MenuConfig::Crosshairs.drawOutLine = true;
			MenuConfig::Crosshairs.drawCrossline = false;
			MenuConfig::Crosshairs.drawCircle = true;
			MenuConfig::Crosshairs.CircleRadius = 10.f;
			MenuConfig::TargetingCrosshairs = true;
			break;
		case 3:
			MenuConfig::Crosshairs.drawDot = true;
			MenuConfig::Crosshairs.DotSize = 1;
			MenuConfig::Crosshairs.drawOutLine = true;
			MenuConfig::Crosshairs.drawCrossline = true;
			MenuConfig::Crosshairs.HorizontalLength = 5;
			MenuConfig::Crosshairs.VerticalLength = 5;
			MenuConfig::Crosshairs.Gap = 18;
			MenuConfig::Crosshairs.tStyle = false;
			MenuConfig::Crosshairs.drawCircle = true;
			MenuConfig::Crosshairs.CircleRadius = 10.f;
			MenuConfig::TargetingCrosshairs = true;
			MenuConfig::Crosshairs.Thickness = 1;
			break;
		case 4:
			MenuConfig::Crosshairs.drawDot = true;
			MenuConfig::Crosshairs.DotSize = 1;
			MenuConfig::Crosshairs.drawOutLine = true;
			MenuConfig::Crosshairs.drawCrossline = true;
			MenuConfig::Crosshairs.HorizontalLength = 5;
			MenuConfig::Crosshairs.VerticalLength = 5;
			MenuConfig::Crosshairs.Gap = 1;
			MenuConfig::Crosshairs.tStyle = false;
			MenuConfig::Crosshairs.drawCircle = false;
			MenuConfig::TargetingCrosshairs = true;
			MenuConfig::Crosshairs.Thickness = 1;
			break;
		case 5:
			MenuConfig::Crosshairs.drawDot = false;
			MenuConfig::Crosshairs.drawOutLine = true;
			MenuConfig::Crosshairs.drawCrossline = true;
			MenuConfig::Crosshairs.HorizontalLength = 7;
			MenuConfig::Crosshairs.VerticalLength = 7;
			MenuConfig::Crosshairs.Gap = 10;
			MenuConfig::Crosshairs.tStyle = false;
			MenuConfig::Crosshairs.drawCircle = false;
			MenuConfig::TargetingCrosshairs = true;
			MenuConfig::Crosshairs.Thickness = 1;
			break;
		case 6:
			MenuConfig::Crosshairs.drawDot = true;
			MenuConfig::Crosshairs.DotSize = 2;
			MenuConfig::Crosshairs.drawOutLine = true;
			MenuConfig::Crosshairs.drawCrossline = true;
			MenuConfig::Crosshairs.HorizontalLength = 8;
			MenuConfig::Crosshairs.VerticalLength = 8;
			MenuConfig::Crosshairs.Gap = 20;
			MenuConfig::Crosshairs.tStyle = false;
			MenuConfig::Crosshairs.drawCircle = false;
			MenuConfig::TargetingCrosshairs = true;
			MenuConfig::Crosshairs.Thickness = 1;
			break;
		case 7:
			MenuConfig::Crosshairs.drawDot = false;
			MenuConfig::Crosshairs.drawOutLine = true;
			MenuConfig::Crosshairs.drawCrossline = true;
			MenuConfig::Crosshairs.HorizontalLength = 4;
			MenuConfig::Crosshairs.VerticalLength = 4;
			MenuConfig::Crosshairs.Gap = 13;
			MenuConfig::Crosshairs.Thickness = 10;
			MenuConfig::Crosshairs.tStyle = false;
			MenuConfig::Crosshairs.drawCircle = false;
			MenuConfig::TargetingCrosshairs = true;
		default:
			break;
		}
	}

	// Get the center pos of screen
	ImVec2 GetScreenCenterImVec2()
	{
		int W = GetSystemMetrics(SM_CXSCREEN);
		int H = GetSystemMetrics(SM_CYSCREEN);

		float CenterX = static_cast<float>(W) / 2;
		float CenterY = static_cast<float>(H) / 2;

		return ImVec2(CenterX, CenterY);
	}

	// Convert RGBA to ImVec4
	// Why not use "ImColor()"? Because I forgot about this.
	ImVec4 rgba2ImVec(int r, int g, int b, int a)
	{
		ImVec4 color;
		color.x = static_cast<float>(r) / 255.0f;
		color.y = static_cast<float>(g) / 255.0f;
		color.z = static_cast<float>(b) / 255.0f;
		color.w = static_cast<float>(a) / 255.0f;

		return color;
	}
}