#pragma once
#define _USE_MATH_DEFINES
#define MAXV 10000e9
#include <math.h>
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
    inline bool Rage = false;

    extern unsigned int HotKey;
    extern int AimBullet;
    extern bool ScopeOnly;
    extern bool AutoShot;
    extern bool AimLock;
    extern float AimFov;
    extern float AimFovMin;
    extern float Smooth;
    extern std::vector<int> HotKeyList;

    extern void SetHotKey(int Index);

    extern void switchToggle();

    inline void Ragebot(const CEntity& Local, Vec3 LocalPos, std::vector<Vec3>& AimPosList)
    {
        if (!Local.Pawn.ShotsFired && !AimLock) {
            return;
        }

        if (AimControl::ScopeOnly)
        {
            bool isScoped;
            ProcessMgr.ReadMemory<bool>(Local.Pawn.Address + Offset::C_CSPlayerPawn.m_bIsScoped, isScoped);
            if (!isScoped) {
                return;
            }
        }

        int ListSize = AimPosList.size();
        
        float Yaw, Pitch;
        float Distance, Norm, BestNorm = MAXV;

        for (int i = 0; i < ListSize; i++)
        {
            Vec3 OppPos;

            OppPos = AimPosList[i] - LocalPos;

            Distance = sqrt(pow(OppPos.x, 2) + pow(OppPos.y, 2));

            Yaw = atan2f(OppPos.y, OppPos.x) * 57.295779513 - Local.Pawn.ViewAngle.y;
            Pitch = -atan(OppPos.z / Distance) * 57.295779513 - Local.Pawn.ViewAngle.x;
            Norm = sqrt(pow(Yaw, 2) + pow(Pitch, 2));

            if (Norm < BestNorm)
                BestNorm = Norm;
        }

        if (Norm > AimFov)
            return;

        Yaw += Local.Pawn.ViewAngle.y;
        Pitch += Local.Pawn.ViewAngle.x;

        // Recoil control
        if (Local.Pawn.ShotsFired)
        {
            Vec2 PunchAngle;
            if (Local.Pawn.AimPunchCache.Count <= 0 && Local.Pawn.AimPunchCache.Count > 0xFFFF)
                return;
            if (!ProcessMgr.ReadMemory<Vec2>(Local.Pawn.AimPunchCache.Data + (Local.Pawn.AimPunchCache.Count - 1) * sizeof(Vec3), PunchAngle))
                return;

            Yaw = Yaw - PunchAngle.y * 2.f;
            Pitch = Pitch - PunchAngle.x * 2.f;
        }

        gGame.SetViewAngle(Yaw, Pitch);
    }
}