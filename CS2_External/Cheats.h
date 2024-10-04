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
	float m_realtime; //0x0000
	int32_t m_framecount; //0x0004
	float m_fratmetime; //0x0008
	float m_abs_frametime; //0x000C
	int32_t m_maxclients; //0x0010
	char pad_0014[28]; //0x0014
	float m_frametime2; //0x0030
	float m_curtime; //0x0034
	float m_curtime2; //0x0038
	char pad_003C[20]; //0x003C
	int32_t m_tickcount; //0x0050
	char pad_0054[292]; //0x0054
	uint64_t m_current_map; //0x0178
	uint64_t m_current_mapname; //0x0180
};

struct {
	ImFont* normal15px = nullptr;
} fonts;