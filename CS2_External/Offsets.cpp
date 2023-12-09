#include "Offsets.h"

DWORD64 SearchOffsets(std::string Signature, DWORD64 ModuleAddress)
{
	std::vector<DWORD64> TempAddressList;
	DWORD64 Address = 0;
	DWORD Offsets = 0;

	TempAddressList = ProcessMgr.SearchMemory(Signature, ModuleAddress, ModuleAddress + 0x4000000);


	JZ(TempAddressList.size() <= 0);

	JZ(!ProcessMgr.ReadMemory<DWORD>(TempAddressList.at(0) + 3, Offsets))

	Address = TempAddressList.at(0) + Offsets + 7;
	return Address;
}

bool Offset::UpdateOffsets()
{
	DWORD64 ClientDLL = reinterpret_cast<DWORD64>(ProcessMgr.GetProcessModuleHandle("client.dll"));

	JZ(ClientDLL);

	DWORD64 ServerDLL = reinterpret_cast<DWORD64>(ProcessMgr.GetProcessModuleHandle("server.dll"));

	JZ(ServerDLL);

	DWORD64 TempAddress = 0;

	TempAddress = SearchOffsets(Offset::Signatures::EntityList, ClientDLL);
	JZ(TempAddress);

	Offset::EntityList = TempAddress - ClientDLL;

	TempAddress = SearchOffsets(Offset::Signatures::LocalPlayerController, ClientDLL);
	JZ(TempAddress);

	Offset::LocalPlayerController = TempAddress - ClientDLL;

	TempAddress = SearchOffsets(Offset::Signatures::ViewMatrix, ClientDLL);
	JZ(TempAddress);

	Offset::Matrix = TempAddress - ClientDLL;

	TempAddress = SearchOffsets(Offset::Signatures::GlobalVars, ClientDLL);
	JZ(TempAddress);


	Offset::GlobalVars = TempAddress - ClientDLL;

	TempAddress = SearchOffsets(Offset::Signatures::ViewAngles, ClientDLL);
	JZ(TempAddress);


	JZ(!ProcessMgr.ReadMemory(TempAddress, TempAddress));

	Offset::ViewAngle = TempAddress + 0x6140 - ClientDLL;

	TempAddress = SearchOffsets(Offset::Signatures::LocalPlayerPawn, ClientDLL);
	JZ(TempAddress);


	Offset::LocalPlayerPawn = TempAddress + 0x138 - ClientDLL;

	TempAddress = SearchOffsets(Offset::Signatures::ForceJump, ClientDLL);
	JZ(TempAddress);


	Offset::ForceJump = TempAddress + 0x30 - ClientDLL;

	TempAddress = SearchOffsets(Offset::Signatures::PlantedC4, ClientDLL);
	JZ(TempAddress);


	Offset::PlantedC4 = TempAddress - ClientDLL;
	return true;
}