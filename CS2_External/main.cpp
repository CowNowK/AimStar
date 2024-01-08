#include "Offsets.h"
#include "Cheats.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <filesystem>
#include <cstdlib>
#include <KnownFolders.h>
#include <ShlObj.h>

namespace fs = std::filesystem;

int main()
{

	std::printf(
	"AimStar External for CS2\n"
	"Author: CowNow\n"
	"Source Code: https://github.com/CowNowK/AimStar\n"
	"\n"
	"- Press [INS] to show or hide Menu.\n"
	"\n"
	"#Disclamers:\n"
	"- Use at your own risk\n"
	"- It is highly not recommended to use AimStar on your main account"
	"\n"
	"#Contributors: \n"
	"Shinyaluvs, Nx0Ri, Skarbor, PedroGoncalves, KeysIsCool, Kenny, Cr1ppl3, Tairitsu, sh1pi, toepas, djsacred, tokinaa, faster_bbc, vsantos1, 5mmod, gScream, Hazetick, styx, user1232, TaKaStuKi.sen\n"
	"\n"
	);

	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");

	char documentsPath[MAX_PATH];
	if (SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
		std::cerr << "[Info] Error: Failed to get the Documents folder path." << std::endl;
		goto END;
	}
	MenuConfig::path = documentsPath;
	MenuConfig::path += "\\AimStar";
	MenuConfig::SoundPath = MenuConfig::path + "\\Sounds";

	switch (ProcessStatus) {
	case 1:
		std::cout << "[ERROR] Please launch the game first!" << std::endl;
		goto END;
	case 2: 
		std::cout << "[ERROR] Failed to hook process, please run the cheat as Administrator (Right click AimStar > Run as Adminstrator)." << std::endl; 
		goto END; 
	case 3:
		std::cout << "[ERROR] Failed to get module address." << std::endl; 
		goto END; 
	default: 
		break;
	}

	if (!Offset::UpdateOffsets())
	{
		std::cout << "[ERROR] Failed to update offsets." << std::endl;
		goto END;
	}

	if (!gGame.InitAddress())
	{
		std::cout << "[ERROR] Failed to call InitAddress()."<< std::endl;
		goto END;
	}
	std::cout << "[Game] Process ID: " << ProcessMgr.ProcessID << std::endl;
	std::cout << "[Game] Client Address: " << gGame.GetClientDLLAddress() << std::endl;

	/*
	std::cout << "Offset:" << std::endl;
	std::cout << "--EntityList:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::EntityList << std::endl;
	std::cout << "--Matrix:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::Matrix << std::endl;
	std::cout << "--LocalPlayerController:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerController << std::endl;
	std::cout << "--ViewAngles:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ViewAngle << std::endl;
	std::cout << "--LocalPlayerPawn:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerPawn << std::endl;
	*/

	if (fs::exists(MenuConfig::path))
		std::cout << "[Info] Config folder connected: " << MenuConfig::path << std::endl;
	else
	{
		if (fs::create_directory(MenuConfig::path))
			std::cout << "[Info] Config folder created: " << MenuConfig::path << std::endl;
		else
		{
			std::cerr << "[Info] Error: Failed to create the config directory." << std::endl;
			goto END;
		}
	}

	if (fs::exists(MenuConfig::SoundPath))
		std::cout << "[Info] Hitsound folder connected: " << MenuConfig::SoundPath << std::endl;
	else
	{
		if (fs::create_directory(MenuConfig::SoundPath))
			std::cout << "[Info] Hitsound folder created: " << MenuConfig::SoundPath << std::endl;
		else
		{
			std::cerr << "[Info] Error: Failed to create the file directory." << std::endl;
			goto END;
		}
	}

	std::cout << std::endl;
	std::cout << "Cheat running successfully!" << std::endl;
	std::cout << "Have fun..." << std::endl;

	try
	{
		Gui.AttachAnotherWindow("Counter-Strike 2", "SDL_app", Cheats::Run);
	}
	catch (OSImGui::OSException& e)
	{
		try
		{
			// Perfect World version
			Gui.AttachAnotherWindow("反恐精英：全球攻势", "SDL_app", Cheats::Run);
		}
		catch (OSImGui::OSException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

END:
	std::cout << std::endl;
	system("pause");
	return 0;
}