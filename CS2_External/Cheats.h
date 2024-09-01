#pragma once
#include "Game.h"
#include "Entity.h"
#include "Features\Aimbot\Legitbot.hpp"
#include "Features\Aimbot\Ragebot.hpp"
#include "Radar/Radar.h"
#include "TriggerBot.h"

#include "Features/Glow.h"
#include "Features/Misc.h"
#include "Features/HUD.h"

namespace Cheats
{
	void KeyCheckThread();

	void RenderCrossHair(ImDrawList* drawList) noexcept;

	void SignatureMutation() noexcept;

	void FastBypass() noexcept;

	bool AntiTKMAC(const INT64 hash) noexcept;

	void RadarSetting(Base_Radar& Radar);

	void Run();
}
class CGlobalVarsBase
{
public:
    float m_flRealTime;
    int m_iFrameCount;
    float m_flAbsoluteFrameTime;
    float m_flAbsoluteFrameStartTimeStdDev;
    int m_nMaxClients;
private:
    std::byte pad1[0x1C];
public:
    float m_flIntervalPerTick;
    float m_flCurrentTime;
    float m_flCurrentTime2;
private:
    std::byte pad2[0x14];
public:
    std::int32_t m_nTickCount;
    float m_flIntervalPerTick2;
private:
    std::byte pad3[0x158];
public:
    std::uint64_t m_uCurrentMap;
    std::uint64_t m_uCurrentMapName;
};
struct {
	ImFont* normal15px = nullptr;
} fonts;