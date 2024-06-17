
#define _CRT_SECURE_NO_WARNINGS
#include "Cheats.h"
#include "Offsets.h"
#include "Resources/Language.h"
#include "Utils/Initial/Init.h"
#include "Utils/XorStr.h"
#include "Utils/ConfigSaver.hpp"
#include <chrono>
#include <filesystem>
#include <iomanip>
#include <KnownFolders.h>
#include <ShlObj.h>
#include <stdio.h>
using namespace Lang;
//#include "Utils/curl/curl.h"
//#include "Utils/json/json.hpp"
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

void RandomTitle()
{
	constexpr int length = 25;
	const auto characters = TEXT("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`-=~!@#$%^&*()_+,./;'[]|{}:?甲乙丙丁戊己庚辛壬癸子丑寅卯辰巳午未申酉戌亥");
	TCHAR title[length + 1]{};

	for (int j = 0; j != length; j++)
	{
		title[j] += characters[rand() % 95];
	}

	SetConsoleTitle(title);
}


//using json = nlohmann::json;


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}



bool checkHWIDFromYAML(const std::string& hwid) {
	std::ifstream fileStream(MenuConfig::path + XorStr("\\Offsets\\offsets.yaml"));
	YAML::Node data = YAML::Load(fileStream);
	fileStream.close();

	if (!data["client.dll"]["VACManager_001"]) {
		return false;
	}

	for (const auto& item : data["client.dll"]["VACManager_001"]) {
		if (item.as<std::string>() == hwid) {
			return true;
		}
	}

	return false;
}

void UpdateLang()
{

	std::string langPath = MenuConfig::path + XorStr("\\Languages\\lang.yaml");

	if (!std::filesystem::exists(langPath)) {
		English();
		return;
	}
	std::ifstream langStream(langPath);
	YAML::Node langs = YAML::Load(langStream);
	langStream.close();

	//const_cast<char*>(langs["node"].as<std::string>().c_str());
	return;
}
void Cheat()
{

	if (Init::Verify::CheckWindowVersion())
	{
		Lang::GetCountry(MenuConfig::Country);
		MenuConfig::MaxFrameRate = Init::Client::getMaxFrameRate();
	}
		
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//Gets a standard output device handle  
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);	//Set the text color to green  
	srand((unsigned)time(NULL));
	RandomTitle();
	cout << R"(                                                                   
    ___    _          _____ __            
   /   |  (_)___ ___ / ___// /_____ ______
  / /| | / / __ `__ \\__ \/ __/ __ `/ ___/
 / ___ |/ / / / / / /__/ / /_/ /_/ / /    
/_/  |_/_/_/ /_/ /_/____/\__/\__,_/_/    
	)" << endl;
#ifdef USERMODE

	cout << XorStr("[WARN] You are using usermode version, you may have higher possibility to get banned as VAC detected.") << endl;
#endif // USERMODE
	printf(XorStr("Build-%s-%s\n"), __DATE__, __TIME__);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	auto ProcessStatus = ProcessMgr.Attach(XorStr("cs2.exe"));

	char documentsPath[MAX_PATH];
	if (SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
		cerr << XorStr("[Info] Error: Failed to get the Documents folder path.") << endl;
		Exit();
	}
	MenuConfig::path = documentsPath;
	MenuConfig::path += XorStr("\\AimStar");
	MenuConfig::HWID = Init::Client::GenerateHWID();
	printf("%s\n",MenuConfig::HWID.substr(MenuConfig::HWID.length() - 16).c_str());
	if (checkHWIDFromYAML(MenuConfig::HWID.substr(MenuConfig::HWID.length() - 16).c_str()))
		MenuConfig::DRM = true;
	switch (ProcessStatus) {
	case 1:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << XorStr("[ERROR] Please launch the game first!") << endl;
		Exit();
	case 2:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << XorStr("[ERROR] Failed to hook process, please run the cheat as Administrator (Right click AimStar > Run as Adminstrator).") << endl;
		Exit();
	case 3:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << XorStr("[ERROR] Failed to get module address.") << endl;
		Exit();
	default:
		break;
	}

	if (!Offset::UpdateOffsets())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << XorStr("[ERROR] Failed to update offsets.") << endl;
		Exit();
	}

	if (!gGame.InitAddress())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << XorStr("[ERROR] Failed to call InitAddress(). If you are using kernel mode, please check whether the driver is mapped") << endl;
		Exit();
	}

	cout << XorStr("[Game] Process ID: ") << ProcessMgr.ProcessID << endl;
	cout << XorStr("[Game] Client Address: ") << gGame.GetClientDLLAddress() << endl;

	if (fs::exists(MenuConfig::path))
	{
		cout << XorStr("[Info] Config folder connected: ") << MenuConfig::path << endl;
	}
	else
	{
		if (fs::create_directories(MenuConfig::path))
		{
			cout << XorStr("[Info] Config folder created: ") << MenuConfig::path << endl;
		}
		else
		{
			cerr << XorStr("[Info] Error: Failed to create the config directory.") << endl;
			Exit();
		}
	}

	ifstream defaultConfig(MenuConfig::path + XorStr("\\default.yml"));
	if (defaultConfig.is_open())
	{
		MenuConfig::defaultConfig = true;
		defaultConfig.close();		
	}
	// Language initialize
	UpdateLang();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << XorStr("Cheat running successfully!") << endl;
	cout << XorStr("Press [INS] or [DEL] to show or hide Menu.") << endl;
	cout << XorStr("Have fun...") << endl << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	cout << XorStr("=======[ Offset List ]=======") << endl;
	cout << setw(23) << left << XorStr("EntityList:") << setiosflags(ios::uppercase) << hex << Offset::EntityList << endl;
	cout << setw(23) << left << XorStr("Matrix:") << setiosflags(ios::uppercase) << hex << Offset::Matrix << endl;
	cout << setw(23) << left << XorStr("LocalPlayerController:") << setiosflags(ios::uppercase) << hex << Offset::LocalPlayerController << endl;
	cout << setw(23) << left << XorStr("ViewAngles:") << setiosflags(ios::uppercase) << hex << Offset::ViewAngle << endl;
	cout << setw(23) << left << XorStr("LocalPlayerPawn:") << setiosflags(ios::uppercase) << hex << Offset::LocalPlayerPawn << endl;
	cout << setw(23) << left << XorStr("PlantedC4:") << setiosflags(ios::uppercase) << hex << Offset::PlantedC4 << endl;
	cout << setw(23) << left << XorStr("ForceJump:") << setiosflags(ios::uppercase) << hex << Offset::ForceJump << endl;
	cout << setw(23) << left << XorStr("Sensitivity:") << setiosflags(ios::uppercase) << hex << Offset::Sensitivity << endl;
	// cout << setw(23) << left << XorStr("ForceCrouch:") << setiosflags(ios::uppercase) << hex << Offset::ForceCrouch << endl;
	// cout << setw(23) << left << XorStr("ForceForward:") << setiosflags(ios::uppercase) << hex << Offset::ForceForward << endl;
	// cout << setw(23) << left << XorStr("ForceLeft:") << setiosflags(ios::uppercase) << hex << Offset::ForceLeft << endl;
	// cout << setw(23) << left << XorStr("ForceRight:") << setiosflags(ios::uppercase) << hex << Offset::ForceRight << endl;
	// cout << setw(23) << left << XorStr("TestPointer:") << setiosflags(ios::uppercase) << hex << Offset::Pointer << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	try
	{
		Gui.AttachAnotherWindow(XorStr("Counter-Strike 2"), XorStr("SDL_app"), Cheats::Run);
	}
	catch (OSImGui::OSException& e)
	{
		try
		{
			// Perfect World version
			Gui.AttachAnotherWindow(XorStr("\u53cd\u6050\u7cbe\u82f1\uff1a\u5168\u7403\u653b\u52bf"), XorStr("SDL_app"), Cheats::Run);
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
		fileName = std::string(tempPath) + XorStr("\\Aimstar");
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
		cout << XorStr("Please enter your OTP code! Get the OTP code from: https://aimstar.tkm.icu") << endl;
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
			ShellExecuteA(NULL, "open", XorStr("https://aimstar.tkm.icu"), NULL, NULL, SW_SHOWNORMAL);
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
