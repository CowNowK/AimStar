#pragma once
#define _USE_MATH_DEFINES
#define MAXV 10000e9
#include <math.h>
#include <thread>
#include <chrono>
#include "..\..\Game.h"
#include "..\..\Entity.h"
#include "..\..\MenuConfig.hpp"
#include <iostream>
#include "..\..\View.hpp"
#include "..\..\Features/RCS.h"

extern "C" {
#include "..\..\Features\Mouse.h"
#include "..\..\Entity.h"
}


namespace AimControl
{
    extern bool Rage;

    inline int HotKey = VK_LMENU;
    inline int AimBullet = 1;
    inline bool ScopeOnly = false;
    inline bool AutoShot = false;
    inline bool AimLock = false;
    inline bool IgnoreFlash = false;
    inline float AimFov = 5;
    inline float AimFovMin = 0.f;
    inline float Smooth = 2.0f;
    inline std::vector<int> HitboxList{ BONEINDEX::head };
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

    inline void AimBot(const CEntity& Local, Vec3 LocalPos, std::vector<Vec3>& AimPosList)
    {
        if (MenuConfig::ShowMenu)
            return;

        //int isFired;
        //ProcessMgr.ReadMemory(Local.Pawn.Address + Offset::Pawn.iShotsFired, isFired);
        //if (!isFired && !AimLock)
        if (Local.Pawn.ShotsFired <= AimBullet - 1 && !AimLock && AimBullet != 0)
        {
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

        if (MenuConfig::Ban) {//Bye and get vac ban
            MenuConfig::SafeMode = false;
            gGame.SetViewAngle(rand() % 180, rand() % 89);
            gGame.SetForceJump(65537);
            gGame.SetForceCrouch(65537);
            gGame.SetForceMove(0,255);

            return;
        }
        int ListSize = AimPosList.size();
        float BestNorm = MAXV;

        float Yaw, Pitch;
        float Distance, Norm, Length;
        Vec2 Angles{ 0,0 };
        int ScreenCenterX = Gui.Window.Size.x / 2;
        int ScreenCenterY = Gui.Window.Size.y / 2;
        float TargetX = 0.f;
        float TargetY = 0.f;

        Vec2 ScreenPos;

        for (int i = 0; i < ListSize; i++)
        {
            Vec3 OppPos;

            OppPos = AimPosList[i] - LocalPos;

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

                AimPosList[i] = LocalPos + OppPos;
            }

            Yaw = atan2f(OppPos.y, OppPos.x) * 57.295779513 - Local.Pawn.ViewAngle.y;
            Pitch = -atan(OppPos.z / Distance) * 57.295779513 - Local.Pawn.ViewAngle.x;
            Norm = sqrt(pow(Yaw, 2) + pow(Pitch, 2));

            if (Norm < BestNorm)
                BestNorm = Norm;

            gGame.View.WorldToScreen(Vec3(AimPosList[i]), ScreenPos);
        }

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

            int AimInterval = round(1000.0 / MenuConfig::MaxFrameRate);
            std::this_thread::sleep_for(std::chrono::milliseconds(AimInterval));
        }
        else
            HasTarget = false;
    }
}