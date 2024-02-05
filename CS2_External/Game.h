#pragma once
#include <optional>
#include "Utils/ProcessManager.hpp"
#include "Offsets.h"
#include "View.hpp"

class CGame
{
private:
	struct
	{
		DWORD64 ForceJump;
		DWORD64 ForceCrouch;
		DWORD64 ForceForward;
		DWORD64 ForceLeft;
		DWORD64 ForceRight;

		DWORD64 ServerDLL;
		DWORD64 ClientDLL;
		DWORD64 EntityList;
		DWORD64 Matrix;
		DWORD64 ViewAngle;
		DWORD64 EntityListEntry;
		DWORD64 LocalController;
		DWORD64 LocalPawn;
		DWORD64 ServerPawn;
		DWORD64 GlobalVars;
	}Address;

public:
	CView View;

public:	

	bool InitAddress();

	DWORD64 GetClientDLLAddress();
	DWORD64 GetServerDLLAddress();

	DWORD64 GetEntityListAddress();

	DWORD64 GetMatrixAddress();

	DWORD64 GetViewAngleAddress();

	DWORD64 GetEntityListEntry();

	DWORD64 GetLocalControllerAddress();

	DWORD64 GetLocalPawnAddress();

	DWORD64 GetServerPawnAddress();

	DWORD64 GetGlobalVarsAddress();

	bool UpdateEntityListEntry();

	bool SetViewAngle(float Yaw, float Pitch);

	bool SetForceJump(int Value);
	bool GetForceJump(int& Value);
	bool SetForceCrouch(int Value);
	bool GetForceCrouch(int& Value);
	bool SetForceMove(int MovingType, int Value);
	bool GetForceMove(int MovingType, int& Value);
};

inline CGame gGame;