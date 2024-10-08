#pragma once
#include "OS-ImGui/OS-ImGui.h"

// 游戏视图类
class CView
{
public:
    float Matrix[4][4]{};

    bool WorldToScreen(const Vec3& Pos, Vec2& ToPos)
    {
        float SightX = Gui.Window.Size.x * .5f;
        float SightY = Gui.Window.Size.y * .5f;

        // 预计算矩阵乘法
        float m30 = Matrix[3][0], m31 = Matrix[3][1], m32 = Matrix[3][2], m33 = Matrix[3][3];
        float m00 = Matrix[0][0], m01 = Matrix[0][1], m02 = Matrix[0][2], m03 = Matrix[0][3];
        float m10 = Matrix[1][0], m11 = Matrix[1][1], m12 = Matrix[1][2], m13 = Matrix[1][3];

        float View = m30 * Pos.x + m31 * Pos.y + m32 * Pos.z + m33;

        if (View <= 0.01f)
            return false;

        float invView = 1.0f / View;
        ToPos.x = SightX + (m00 * Pos.x + m01 * Pos.y + m02 * Pos.z + m03) * invView * SightX;
        ToPos.y = SightY - (m10 * Pos.x + m11 * Pos.y + m12 * Pos.z + m13) * invView * SightY;

        return true;
    }


	Vec2 GetScreenCenterVec2()
	{
		Vec2 Pos = Gui.Window.Size * .5f;
		return Pos;
	}
};
