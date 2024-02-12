#include "Offsets.h"
#include "Cheats.h"
#include "Resources/Language.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <filesystem>
#include <cstdlib>
#include <KnownFolders.h>
#include <ShlObj.h>
#include <string>
#include <chrono>

using namespace std;
/*
Contributors:
	Shinyaluvs,
	Nx0Ri,
	Skarbor,
	PedroGoncalves,
	KeysIsCool,
	Kenny,
	Cr1ppl3,
	Tairitsu,
	sh1pi,
	toepas,
	djsacred,
	tokinaa,
	faster_bbc,
	vsantos1,
	5mmod,
	gScream,
	Hazetick,
	styx,
	user1232,
	TaKaStuKi.sen
*/

namespace fs = std::filesystem;
//otp code verify by @_ukia_
void CodeGenerate(string &time, string &code) {
  auto now = chrono::system_clock::now();
  auto now_utc = chrono::system_clock::to_time_t(now);
  struct tm tm_utc;
  gmtime_s(&tm_utc, &now_utc);
  int year = tm_utc.tm_year + 1900;
  int month = tm_utc.tm_mon + 1;
  int day = tm_utc.tm_mday;
  int hour = tm_utc.tm_hour;
  int minute = tm_utc.tm_min;
  int sum = year + month + day + hour + minute;
  int otp = sum ^ 3351 % 10000;
  time = to_string(year) + "-" + to_string(month) + "-" + to_string(day) + "-" + to_string(hour) + "-" + to_string(minute);
  code = to_string(otp);
}

int main()
{
	Lang::GetCountry(MenuConfig::Country);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//Gets a standard output device handle  
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);	//Set the text color to green  
	std::cout << R"(                                                                   
    ___    _          _____ __            
   /   |  (_)___ ___ / ___// /_____ ______
  / /| | / / __ `__ \\__ \/ __/ __ `/ ___/
 / ___ |/ / / / / / /__/ / /_/ /_/ / /    
/_/  |_/_/_/ /_/ /_/____/\__/\__,_/_/    
	)" << std::endl; 
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");

	string time, code;
	int RetTimes;
	//cout << "local utc = " << time << endl;
	cout << "!!If you paid money for this software, you may have been scammed!!" << endl;
	cout << "Please visit https://aimstar.tkm.icu/ to get the otp code" << endl;
	RETRY:
	cout << "Plz enter your otp code: " << endl;
	string input;
	cin >> input;
	CodeGenerate(time, code);
	if (input != code) {
		cout << "otp code error!!" << endl;
		if (RetTimes < 3){
			RetTimes++;
			goto RETRY;
		}
		else
		goto END;
	} 

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
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Please launch the game first!" << std::endl;
		goto END;
	case 2: 
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to hook process, please run the cheat as Administrator (Right click AimStar > Run as Adminstrator)." << std::endl; 
		goto END; 
	case 3:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to get module address." << std::endl; 
		goto END; 
	default: 
		break;
	}

	if (!Offset::UpdateOffsets())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to update offsets." << std::endl;
		goto END;
	}

	if (!gGame.InitAddress())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "[ERROR] Failed to call InitAddress()."<< std::endl;
		goto END;
	}

	std::cout << "[Game] Process ID: " << ProcessMgr.ProcessID << std::endl;
	std::cout << "[Game] Client Address: " << gGame.GetClientDLLAddress() << std::endl;

	if (fs::exists(MenuConfig::path))
	{
		std::cout << "[Info] Config folder connected: " << MenuConfig::path << std::endl;
	}
	else
	{
		if (fs::create_directory(MenuConfig::path))
		{
			std::cout << "[Info] Config folder created: " << MenuConfig::path << std::endl;
		}
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
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	std::cout << "Cheat running successfully!" << std::endl;
	std::cout << "Press [INS] to show or hide Menu." << std::endl;
	std::cout << "Have fun..." << std::endl << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "=======[ Offset List ]=======" << std::endl;
	std::cout << std::setw(23) << std::left << "EntityList:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::EntityList << std::endl;
	std::cout << std::setw(23) << std::left << "Matrix:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::Matrix << std::endl;
	std::cout << std::setw(23) << std::left << "LocalPlayerController:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerController << std::endl;
	std::cout << std::setw(23) << std::left << "ViewAngles:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ViewAngle << std::endl;
	std::cout << std::setw(23) << std::left << "LocalPlayerPawn:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::LocalPlayerPawn << std::endl;
	std::cout << std::setw(23) << std::left << "PlantedC4:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::PlantedC4 << std::endl;
	std::cout << std::setw(23) << std::left << "ForceJump:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceJump << std::endl;
	// std::cout << std::setw(23) << std::left << "ForceCrouch:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceCrouch << std::endl;
	// std::cout << std::setw(23) << std::left << "ForceForward:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceForward << std::endl;
	// std::cout << std::setw(23) << std::left << "ForceLeft:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceLeft << std::endl;
	// std::cout << std::setw(23) << std::left << "ForceRight:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::ForceRight << std::endl;
	// std::cout << std::setw(23) << std::left << "TestPointer:" << std::setiosflags(std::ios::uppercase) << std::hex << Offset::Pointer << std::endl;
	std::cout << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

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
