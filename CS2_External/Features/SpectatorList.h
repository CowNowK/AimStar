#pragma once
#include "..\MenuConfig.hpp"
#include "..\Entity.h"
#include <vector>
#include <string>
#include <iostream>

namespace SpecList
{
    float spectatorOffsetY = 0;
    bool isSpectating(uintptr_t localPlayer, uintptr_t entityList, uintptr_t playerPawn, uintptr_t playerController)
    {
        uintptr_t m_pObserverServices = 0;
        uint32_t m_hObserverTarget = 0;
        uintptr_t targetController = 0;
        char buffer[128] = { 0 };
        char const* playerName = { 0 };
        std::string name;

        if (!ProcessMgr.ReadMemory<uintptr_t>(playerPawn + Offset::PlayerController.m_pObserverServices, m_pObserverServices))
            return false;
        if (!ProcessMgr.ReadMemory<uint32_t>(m_pObserverServices + Offset::PlayerController.m_hObserverTarget, m_hObserverTarget)) // uint32_t
            return false;
        if (!ProcessMgr.ReadMemory<uintptr_t>((entityList + 0x8 * ((m_hObserverTarget & 0x7FFF) >> 9) + 16), targetController))
            return false;
        if (!ProcessMgr.ReadMemory<uintptr_t>(targetController + 120 * (m_hObserverTarget & 0x1FF), targetController))
            return false;
        if (targetController != localPlayer)
            return false;

        ProcessMgr.ReadMemory<std::string>(playerController + Offset::Entity.iszPlayerName, name);
        playerName = name.c_str();

        std::cout << playerName << std::endl;

        return true;
    }

    void SpecWindowList(std::vector<std::string> SpectatorList)
    {
        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoCollapse;
        if (!MenuConfig::ShowMenu)
            ImGui::SetNextWindowBgAlpha(0.3f);
        ImGui::SetNextWindowSize(ImVec2(200, 0));
        ImGui::Begin("Spectator List", nullptr, windowFlags);

        for (const auto& spectator : SpectatorList)
        {
            ImGui::Text(spectator.c_str());
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
        SpecWindowList(spectators);
    }
}