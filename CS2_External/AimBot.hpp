#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Game.h"
#include "Entity.h"
#include "MenuConfig.hpp"
#include <iostream>
#include "View.hpp"
#include "Features/RCS.h"

extern "C" {
#include "Features\Mouse.h"
#include "Entity.h"
}


namespace AimControl
{
    inline int HotKey = VK_LMENU;
    inline bool ScopeOnly = false;
    inline bool AutoShot = false;
    inline bool AimLock = false;
    inline float AimFov = 5;
    inline float Smooth = 2.0f;
    inline Vec2 RCSScale = { 1.f,1.f };
    inline std::vector<int> HotKeyList{ VK_LMENU, VK_LBUTTON, VK_RBUTTON, VK_XBUTTON1, VK_XBUTTON2, VK_CAPITAL, VK_LSHIFT, VK_LCONTROL };

    inline void SetHotKey(int Index)
    {
        HotKey = HotKeyList.at(Index);
    }

    inline void switchToggle()
    {
        MenuConfig::AimAlways = !MenuConfig::AimAlways;
    }

    inline void AimBot(const CEntity& Local, Vec3 LocalPos, Vec3 AimPos)
    {
        if (MenuConfig::ShowMenu)
            return;

        int isFired;
        ProcessMgr.ReadMemory(Local.Pawn.Address + Offset::Pawn.iShotsFired, isFired);
        if (!isFired && !AimLock)
            return;

        if (AimControl::ScopeOnly)
        {
            bool isScoped;
            ProcessMgr.ReadMemory<bool>(Local.Pawn.Address + Offset::Pawn.isScoped, isScoped);
            if (!isScoped)
                return;
        }

        float Yaw, Pitch;
        float Distance, Norm, Length;
        Vec3 OppPos;
        Vec2 Angles{ 0,0 };
        int ScreenCenterX = Gui.Window.Size.x / 2;
        int ScreenCenterY = Gui.Window.Size.y / 2;
        float TargetX = 0.f;
        float TargetY = 0.f;

        OppPos = AimPos - LocalPos;

        Distance = sqrt(pow(OppPos.x, 2) + pow(OppPos.y, 2));

        Length = sqrt(Distance * Distance + OppPos.z * OppPos.z);
        // RCS by @Tairitsu
        if (MenuConfig::RCS)
        {
            RCS::UpdateAngles(Local, Angles);
            float rad = Angles.x * RCSScale.x / 180.f * M_PI;
            float si = sinf(rad);
            float co = cosf(rad);

            float z = OppPos.z * co + Distance * si;
            float d = (Distance * co - OppPos.z * si) / Distance;

            rad = -Angles.y * RCSScale.y / 180.f * M_PI;
            si = sinf(rad);
            co = cosf(rad);

            float x = (OppPos.x * co - OppPos.y * si) * d;
            float y = (OppPos.x * si + OppPos.y * co) * d;

            OppPos = Vec3{ x, y, z };

            AimPos = LocalPos + OppPos;
        }

        Yaw = atan2f(OppPos.y, OppPos.x) * 57.295779513 - Local.Pawn.ViewAngle.y;
        Pitch = -atan(OppPos.z / Distance) * 57.295779513 - Local.Pawn.ViewAngle.x;
        Norm = sqrt(pow(Yaw, 2) + pow(Pitch, 2));

        Vec2 ScreenPos;
        gGame.View.WorldToScreen(Vec3(AimPos), ScreenPos);

        if (Norm < AimFov)
        {
            // Shake Fixed by @Sweely
            if (ScreenPos.x != ScreenCenterX)
            {
                TargetX = (ScreenPos.x > ScreenCenterX) ? -(ScreenCenterX - ScreenPos.x) : ScreenPos.x - ScreenCenterX;
                TargetX /= Smooth != 0.0f ? Smooth : 1.5f;
                TargetX = (TargetX + ScreenCenterX > ScreenCenterX * 2 || TargetX + ScreenCenterX < 0) ? 0 : TargetX;
            }

            if (ScreenPos.y != 0)
            {
                if (ScreenPos.y != ScreenCenterY)
                {
                    TargetY = (ScreenPos.y > ScreenCenterY) ? -(ScreenCenterY - ScreenPos.y) : ScreenPos.y - ScreenCenterY;
                    TargetY /= Smooth != 0.0f ? Smooth : 1.5f;
                    TargetY = (TargetY + ScreenCenterY > ScreenCenterY * 2 || TargetY + ScreenCenterY < 0) ? 0 : TargetY;
                }
            }

            if (!Smooth)
            {
                mouse_event(MOUSEEVENTF_MOVE, (DWORD)(TargetX), (DWORD)(TargetY), NULL, NULL);
                if (AutoShot)
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
                return;
            }

            // Dynamic AimSmooth based on distance
            float DistanceRatio = Norm / AimFov; // Calculate the distance ratio
            float SpeedFactor = 1.0f + (1.0f - DistanceRatio); // Determine the speed factor based on the distance ratio
            TargetX /= (Smooth * SpeedFactor);
            TargetY /= (Smooth * SpeedFactor);
            // by Skarbor
            
            if (ScreenPos.x != ScreenCenterX)
            {
                TargetX = (ScreenPos.x > ScreenCenterX) ? -(ScreenCenterX - ScreenPos.x) : ScreenPos.x - ScreenCenterX;
                TargetX /= Smooth != 0.0f ? Smooth : 1.5f;
                TargetX = (TargetX + ScreenCenterX > ScreenCenterX * 2 || TargetX + ScreenCenterX < 0) ? 0 : TargetX;
            }

            if (ScreenPos.y != 0)
            {
                if (ScreenPos.y != ScreenCenterY)
                {
                    TargetY = (ScreenPos.y > ScreenCenterY) ? -(ScreenCenterY - ScreenPos.y) : ScreenPos.y - ScreenCenterY;
                    TargetY /= Smooth != 0.0f ? Smooth : 1.5f;
                    TargetY = (TargetY + ScreenCenterY > ScreenCenterY * 2 || TargetY + ScreenCenterY < 0) ? 0 : TargetY;
                }
            }
            mouse_event(MOUSEEVENTF_MOVE, TargetX, TargetY, NULL, NULL);
            if (AutoShot)
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }
        }
    }
}