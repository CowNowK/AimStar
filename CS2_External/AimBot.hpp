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
    inline int AimBullet = 1;
    inline bool ScopeOnly = false;
    inline bool AutoShot = false;
    inline bool AimLock = false;
    inline bool IgnoreFlash = false;
    inline float AimFov = 5;
    inline float AimFovMin = .5f;
    inline float Smooth = 2.0f;
    inline std::vector<int> HotKeyList{ VK_LMENU, VK_LBUTTON, VK_RBUTTON, VK_XBUTTON1, VK_XBUTTON2, VK_CAPITAL, VK_LSHIFT, VK_LCONTROL };

    inline bool HasTarget = false;

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

        //int isFired;
        //ProcessMgr.ReadMemory(Local.Pawn.Address + Offset::Pawn.iShotsFired, isFired);
        //if (!isFired && !AimLock)
        if (Local.Pawn.ShotsFired <= AimBullet && !AimLock) {
            HasTarget = false;
            return;
        }
            

        if (AimControl::ScopeOnly)
        {
            bool isScoped;
            ProcessMgr.ReadMemory<bool>(Local.Pawn.Address + Offset::Pawn.isScoped, isScoped);
            if (!isScoped) {
                HasTarget = false;
                return;
            }
        }

        if (!IgnoreFlash && Local.Pawn.FlashDuration > 0.f)
            return;

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
            float rad = Angles.x * RCS::RCSScale.x / 360.f * M_PI;
            float si = sinf(rad);
            float co = cosf(rad);

            float z = OppPos.z * co + Distance * si;
            float d = (Distance * co - OppPos.z * si) / Distance;

            rad = -Angles.y * RCS::RCSScale.y / 360.f * M_PI;
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

        if (Norm < AimFov && Norm > AimFovMin)
        {
            HasTarget = true;
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
        else
            HasTarget = false;
    }

    inline void ragebot(const CEntity& Local, Vec3 LocalPos, Vec3 AimPos)
    {
        float Yaw, Pitch;
        float Distance, Norm;
        Vec3 OppPos;

        OppPos = AimPos - LocalPos;

        Distance = sqrt(pow(OppPos.x, 2) + pow(OppPos.y, 2));

        Yaw = atan2f(OppPos.y, OppPos.x) * 57.295779513 - Local.Pawn.ViewAngle.y;
        Pitch = -atan(OppPos.z / Distance) * 57.295779513 - Local.Pawn.ViewAngle.x;
        Norm = sqrt(pow(Yaw, 2) + pow(Pitch, 2));
        if (Norm > AimFov)
            return;

        Yaw += Local.Pawn.ViewAngle.y;
        Pitch += Local.Pawn.ViewAngle.x;

        // Recoil control
        if (Local.Pawn.ShotsFired > AimBullet)
        {
            Vec2 PunchAngle;
            if (Local.Pawn.AimPunchCache.Count <= 0 && Local.Pawn.AimPunchCache.Count > 0xFFFF)
                return;
            if (!ProcessMgr.ReadMemory<Vec2>(Local.Pawn.AimPunchCache.Data + (Local.Pawn.AimPunchCache.Count - 1) * sizeof(Vec3), PunchAngle))
                return;

            Yaw = Yaw - PunchAngle.y * RCS::RCSScale.x;
            Pitch = Pitch - PunchAngle.x * RCS::RCSScale.y;
        }

        gGame.SetViewAngle(Yaw, Pitch);
    }
}