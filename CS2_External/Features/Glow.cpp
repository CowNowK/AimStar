#include "Glow.h"
#include <thread>

// runs on gui loop writes with no safemode check or even a check to see if its enabled lmao and doesnt work
void Glow::Run(const CEntity& aLocalPlayer)
{
	return;
	/*
	float on = 86400.f;
	float off = 0.f;
	if (!MiscCFG::EnemySensor)
	{
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::Entity.EnemySensor, off);
	}
	else {
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::Entity.EnemySensor, on);
	}outdated*/

}