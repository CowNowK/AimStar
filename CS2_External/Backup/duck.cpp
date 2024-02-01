enum class Flags
{
	NONE,
	IN_AIR = 1 << 0,
	IN_CROUCH = 1 << 1
};

inline bool CrouchCheck(const CEntity& Local)
{
	const bool hasFlagDucking = Local.Pawn.HasFlag(PlayerPawn::Flags::IN_CROUCH);
	return hasFlagDucking;
}

void FastCrouch(const CEntity& Local) noexcept
{
	int ForceCrouch;
	DWORD64 MovementServices;
	bool ctrlPressed = GetAsyncKeyState(VK_LCONTROL);
	bool isCrouched = CrouchCheck(Local);

	ProcessMgr.ReadMemory(Local.Pawn.Address + Offset::Pawn.MovementServices, MovementServices);
	gGame.GetForceCrouch(ForceCrouch);
	// std::cout << ForceCrouch << std::endl;

	float a = 1.f;
	std::cout << a << std::endl;
	if (!ctrlPressed && isCrouched)
	{
		gGame.SetForceCrouch(256);
	}
	else if (ctrlPressed && !isCrouched)
	{
		ProcessMgr.WriteMemory(MovementServices + 0x224, a);
		gGame.SetForceCrouch(65537);
	}
	else if (!ctrlPressed && ForceCrouch == 65537)
	{
		gGame.SetForceCrouch(256);
	}
}