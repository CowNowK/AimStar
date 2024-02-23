#include "TriggerBot.h"

DWORD uHandle = 0;
DWORD64 ListEntry = 0;
DWORD64 PawnAddress = 0;
CEntity Entity;
bool AllowShoot = false;

void TriggerBot::ReleaseMouseButton()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(FakeShotDelay));
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void TriggerBot::Run(const CEntity& LocalEntity)
{
	if (!ProcessMgr.ReadMemory<DWORD>(LocalEntity.Pawn.Address + Offset::Pawn.iIDEntIndex, uHandle))
		return;
	if (uHandle == -1)
		return;

	ListEntry = ProcessMgr.TraceAddress(gGame.GetEntityListAddress(), { 0x8 * (uHandle >> 9) + 0x10,0x0 });
	if (ListEntry == 0)
		return;

	if (!ProcessMgr.ReadMemory<DWORD64>(ListEntry + 0x78 * (uHandle & 0x1FF), PawnAddress))
		return;

	if (!Entity.UpdatePawn(PawnAddress))
		return;

	if (!IgnoreFlash && LocalEntity.Pawn.FlashDuration > 0.f)
		return;

	if (ScopeOnly)
	{
		bool isScoped;
		ProcessMgr.ReadMemory<bool>(LocalEntity.Pawn.Address + Offset::Pawn.isScoped, isScoped);
		if (!isScoped) {
			return;
		}
	}

	if (MenuConfig::TeamCheck)
		AllowShoot = LocalEntity.Pawn.TeamID != Entity.Pawn.TeamID && Entity.Pawn.Health > 0;
	else
		AllowShoot = Entity.Pawn.Health > 0;

	if (!AllowShoot)
		return;

	static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();
	auto CurTimePoint = std::chrono::steady_clock::now();
	if (CurTimePoint - LastTimePoint >= std::chrono::milliseconds(TriggerDelay))
	{
		const bool isAlreadyShooting = GetAsyncKeyState(VK_LBUTTON) < 0;
		if (!isAlreadyShooting)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			std::thread TriggerThread(ReleaseMouseButton);
			TriggerThread.detach();
		}
		LastTimePoint = CurTimePoint;
	}
}

void TriggerBot::TargetCheck(const CEntity& LocalEntity) noexcept
{
	if (!ProcessMgr.ReadMemory<DWORD>(LocalEntity.Pawn.Address + Offset::Pawn.iIDEntIndex, uHandle) || uHandle == -1)
	{
		CrosshairsCFG::isAim = false;
	}
	else
	{
		ListEntry = ProcessMgr.TraceAddress(gGame.GetEntityListAddress(), { 0x8 * (uHandle >> 9) + 0x10, 0x0 });
		if (ListEntry != 0)
		{
			if (ProcessMgr.ReadMemory<DWORD64>(ListEntry + 0x78 * (uHandle & 0x1FF), PawnAddress))
			{
				if (Entity.UpdatePawn(PawnAddress))
				{
					CrosshairsCFG::isAim = CrosshairsCFG::TeamCheck ? (LocalEntity.Pawn.TeamID != Entity.Pawn.TeamID) : true;
					return;
				}
			}
		}
		CrosshairsCFG::isAim = false;
	}
}