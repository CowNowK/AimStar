#define _CRT_SECURE_NO_WARNINGS
#include "Cheats.h"
#include "Offsets.h"
#include "Resources/Language.h"
#include "Utils/Initial/Init.h"
#include "Utils/ConfigSaver.hpp"
#include <chrono>
#include <filesystem>
#include <iomanip>
#include <KnownFolders.h>
#include <ShlObj.h>
#include <stdio.h>

using namespace std;
/*
Contributors:
	Shinyaluvs,
	Nx0Ri,
	ByteCorum,
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

namespace fs = filesystem;
bool otp = false;
string fileName;

void Exit()
{
	system("pause");
	exit(0);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

void rndmTitle()
{
	constexpr int length = 25;
	const auto characters = TEXT("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	TCHAR title[length + 1]{};

	for (int j = 0; j != length; j++)
	{
		title[j] += characters[rand() % 62];
	}

	SetConsoleTitle(title);
}

void Cheat()
{
	MenuConfig::HWID = Init::Client::GenerateHWID();
	if (Init::Verify::CheckWindowVersion())
	{
		Lang::GetCountry(MenuConfig::Country);
		MenuConfig::MaxFrameRate = Init::Client::getMaxFrameRate();
	}
		
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//Gets a standard output device handle  
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);	//Set the text color to green  
	rndmTitle();
	cout << R"(                                                                   
    ___    _          _____ __            
   /   |  (_)___ ___ / ___// /_____ ______
  / /| | / / __ `__ \\__ \/ __/ __ `/ ___/
 / ___ |/ / / / / / /__/ / /_/ /_/ / /    
/_/  |_/_/_/ /_/ /_/____/\__/\__,_/_/    
	)" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	auto ProcessStatus = ProcessMgr.Attach("cs2.exe");

	char documentsPath[MAX_PATH];
	if (SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
		cerr << "[Info] Error: Failed to get the Documents folder path." << endl;
		Exit();
	}
	MenuConfig::path = documentsPath;
	MenuConfig::path += "\\AimStar";

	switch (ProcessStatus) {
	case 1:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Please launch the game first!" << endl;
		Exit();
	case 2:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to hook process, please run the cheat as Administrator (Right click AimStar > Run as Adminstrator)." << endl;
		Exit();
	case 3:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to get module address." << endl;
		Exit();
	default:
		break;
	}

	if (!Offset::UpdateOffsets())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to update offsets." << endl;
		Exit();
	}

	if (!gGame.InitAddress())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR] Failed to call InitAddress()." << endl;
		Exit();
	}

	cout << "[Game] Process ID: " << ProcessMgr.ProcessID << endl;
	cout << "[Game] Client Address: " << gGame.GetClientDLLAddress() << endl;

	if (fs::exists(MenuConfig::path))
	{
		cout << "[Info] Config folder connected: " << MenuConfig::path << endl;
	}
	else
	{
		if (fs::create_directory(MenuConfig::path))
		{
			cout << "[Info] Config folder created: " << MenuConfig::path << endl;
		}
		else
		{
			cerr << "[Info] Error: Failed to create the config directory." << endl;
			Exit();
		}
	}

	ifstream defaultConfig(MenuConfig::path + "\\default.yml");
	if (defaultConfig.is_open())
	{
		MenuConfig::defaultConfig = true;
		defaultConfig.close();		
	}

	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "Cheat running successfully!" << endl;
	cout << "Press [INS] to show or hide Menu." << endl;
	cout << "Have fun..." << endl << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "=======[ Offset List ]=======" << endl;
	cout << setw(23) << left << "EntityList:" << setiosflags(ios::uppercase) << hex << Offset::EntityList << endl;
	cout << setw(23) << left << "Matrix:" << setiosflags(ios::uppercase) << hex << Offset::Matrix << endl;
	cout << setw(23) << left << "LocalPlayerController:" << setiosflags(ios::uppercase) << hex << Offset::LocalPlayerController << endl;
	cout << setw(23) << left << "ViewAngles:" << setiosflags(ios::uppercase) << hex << Offset::ViewAngle << endl;
	cout << setw(23) << left << "LocalPlayerPawn:" << setiosflags(ios::uppercase) << hex << Offset::LocalPlayerPawn << endl;
	cout << setw(23) << left << "PlantedC4:" << setiosflags(ios::uppercase) << hex << Offset::PlantedC4 << endl;
	cout << setw(23) << left << "ForceJump:" << setiosflags(ios::uppercase) << hex << Offset::ForceJump << endl;
	cout << setw(23) << left << "Sensitivity:" << setiosflags(ios::uppercase) << hex << Offset::Sensitivity << endl;
	// cout << setw(23) << left << "ForceCrouch:" << setiosflags(ios::uppercase) << hex << Offset::ForceCrouch << endl;
	// cout << setw(23) << left << "ForceForward:" << setiosflags(ios::uppercase) << hex << Offset::ForceForward << endl;
	// cout << setw(23) << left << "ForceLeft:" << setiosflags(ios::uppercase) << hex << Offset::ForceLeft << endl;
	// cout << setw(23) << left << "ForceRight:" << setiosflags(ios::uppercase) << hex << Offset::ForceRight << endl;
	// cout << setw(23) << left << "TestPointer:" << setiosflags(ios::uppercase) << hex << Offset::Pointer << endl;
	cout << endl;
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
			cout << e.what() << endl;
		}
	}
}

int main(void)
{

	const char* tempPath = std::getenv("TMP");
	if (tempPath != nullptr)
	{
		fileName = std::string(tempPath) + "\\Aimstar";
		otp = Init::Verify::isVerified(fileName);
	}

	if (otp)
	{
		Cheat();
		return 0;
	}
	else
	{
		// OTP Window
		WNDCLASS wc = { 0 };
		const wchar_t CLASS_NAME[] = L"OTPInputClass";

		wc.lpfnWndProc = WndProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);

		HWND hwnd = CreateWindowEx(
			0, CLASS_NAME, L"Verify", WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
			NULL, NULL, GetModuleHandle(NULL), NULL
		);

		if (hwnd == NULL) {
			return 0;
		}

		ShowWindow(hwnd, SW_SHOW);

		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	//bool showed = false;
	if (!otp /*&& !showed*/)
	{
		cout << "Please enter your OTP code! Get the OTP code from: https://aimstar.tkm.icu" << endl;
		//showed = true;
	}
	static int RetTimes = 0;

	switch (message) {
        case WM_CREATE:
	{
		CreateWindowW(L"STATIC", L"Please enter your OTP code:",
			WS_VISIBLE | WS_CHILD | SS_CENTER,
			50, 20, 300, 20, hwnd, NULL, NULL, NULL);
		CreateWindowW(L"EDIT", L"",
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			100, 50, 200, 20, hwnd, (HMENU)2, NULL, NULL);
		CreateWindowW(L"BUTTON", L"Verify",
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			215, 90, 70, 30, hwnd, (HMENU)1, NULL, NULL);
		CreateWindowW(L"BUTTON", L"Get OTP",
			WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			115, 90, 70, 30, hwnd, (HMENU)3, NULL, NULL);
		break;
	}
	case WM_COMMAND:
	{
		if (LOWORD(wParam) == 1) {
			wchar_t buffer[10];
			GetWindowTextW(GetDlgItem(hwnd, 2), buffer, 10);
			wstring ws(buffer);
			string input(ws.begin(), ws.end());
			string time, code;
			Init::Verify::CodeGenerate(time, code);

			if (input != code) {
				RetTimes++;
				if (RetTimes < 3) {
					MessageBox(hwnd, L"OTP code error!!", L"Error", MB_OK | MB_ICONERROR);
				}
				else {
					MessageBox(hwnd, L"Exceeded maximum attempts.", L"Error", MB_OK | MB_ICONERROR);
					DestroyWindow(hwnd);
					Init::Client::QuitGame();
					Exit();
				}
			}
			else {
				otp = true;
				std::ofstream outfile(fileName);
				outfile.close();
				ShowWindow(hwnd, SW_HIDE);
				system("cls");
				Cheat();
			}
		}
		if (LOWORD(wParam) == 3)
		{
			ShellExecuteA(NULL, "open", "https://aimstar.tkm.icu", NULL, NULL, SW_SHOWNORMAL);
			// ShellExecute(NULL, TEXT("open"), TEXT("https://aimstar.tkm.icu"), NULL, NULL, SW_SHOWNORMAL);
		}
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
