#pragma once
#include "..\MenuConfig.hpp"
#include "..\Entity.h"
#include <vector>
#include <string>
#include <iostream>

namespace SpecList
{
    float spectatorOffsetY = 0;
    bool isSpectating(const uint32_t m_hPawn)
    {
        uintptr_t pCSPlayerPawn, m_pObserverServices, m_hObserverTarget;
        ProcessMgr.ReadMemory<uintptr_t>(gGame.GetEntityListEntry() + 120 * (m_hPawn & 0x1FF), pCSPlayerPawn);
        ProcessMgr.ReadMemory<uintptr_t>(pCSPlayerPawn + 0x10C0, m_pObserverServices);
        ProcessMgr.ReadMemory<uintptr_t>(m_pObserverServices + 0x44, m_hObserverTarget);
        if (!m_hObserverTarget == 0) {
            std::cout << m_hObserverTarget << std::endl;
            return true;
        }

        return false;
    }

    void SpectatorWindowList(const std::vector<std::string>& spectators)
    {
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;

        if (ImGui::Begin("Spectators", NULL, flags))
        {

            float lineSpacing = -15.0f;


            for (const auto& spectator : spectators)
            {
                ImGui::TextColored(ImColor(0, 255, 0, 255), spectator.c_str());
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() + lineSpacing);
            }


            ImGui::End();
        }
    }

    void GetSpectatorList(CEntity& Entity, CEntity& LocalEntity, DWORD64 EntityAddress)
    {
        if (!MiscCFG::SpecList)
            return;

        std::vector<std::string> spectators;
        
        int spectatorCount = 0;
        uint32_t m_hPawn;
        uintptr_t pCSPlayerPawn;
        uintptr_t m_pObserverServices;
        
        ProcessMgr.ReadMemory<uint32_t>(Entity.Controller.Address + 0x5DC, m_hPawn);
        ProcessMgr.ReadMemory<uintptr_t>(gGame.GetEntityListEntry() + 120 * (m_hPawn & 0x1FF), pCSPlayerPawn);
        ProcessMgr.ReadMemory<uintptr_t>(pCSPlayerPawn + 0x10C0, m_pObserverServices);

        if (m_pObserverServices)
        {
            uint32_t m_hObserverTarget;
            uintptr_t list_entry;
            uintptr_t pController;
            ProcessMgr.ReadMemory<uint32_t>(m_pObserverServices + 0x44, m_hObserverTarget);
            ProcessMgr.ReadMemory<uintptr_t>(EntityAddress + 0x8 * ((m_hObserverTarget & 0x7FFF) >> 9) + 0x10, list_entry);
            ProcessMgr.ReadMemory<uintptr_t>(gGame.GetEntityListEntry() + 120 * (m_hObserverTarget & 0x1FF), pController);

            if (pController == LocalEntity.Pawn.Address)
            {
                spectators.push_back(Entity.Controller.PlayerName);
            }
            spectatorCount = 0;
        }
    }
}