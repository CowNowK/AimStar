#include "Glow.h"
#include <thread>

void Glow::Run(const CEntity& aLocalPlayer)
{
	float on = 86400.f;
	float off = 0.f;
	if (!MiscCFG::EnemySensor)
	{
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::Entity.EnemySensor, off);
	}
	else {
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::Entity.EnemySensor, on);
	}
	
}