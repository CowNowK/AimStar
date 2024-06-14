#include "Glow.h"
#include <thread>

void Glow::Run(const CEntity& Entity)
{
	int on = 1;
	int off = 0;
	DWORD color = 0x800000FF;
	if (!MiscCFG::EnemySensor)
	{
		ProcessMgr.WriteMemory(Entity.Pawn.Address + Offset::Entity.GlowFunction, off);
	}
	else {
		ProcessMgr.WriteMemory(Entity.Pawn.Address + Offset::Entity.GlowFunction, on);
		ProcessMgr.WriteMemory(Entity.Pawn.Address + Offset::Entity.GlowColorOverride, color);
	}
	return;
}
