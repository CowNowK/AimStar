#pragma once
#include <fstream>
#include <windows.h>
#include <shellapi.h>
#include <iostream>
#include <string>
#include <cstdlib>

namespace Init
{
    using namespace std;

	class Verify
	{
	public:
		// Check if the Windows version is higher than 7
		static bool CheckWindowVersion() {
            OSVERSIONINFOEX osvi;
            ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
            osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
            osvi.dwMajorVersion = 6;
            osvi.dwMinorVersion = 1;

            ULONGLONG conditionMask = VerSetConditionMask(0, VER_MAJORVERSION, VER_GREATER_EQUAL);
            conditionMask = VerSetConditionMask(conditionMask, VER_MINORVERSION, VER_GREATER_EQUAL);

            if (VerifyVersionInfo(&osvi, VER_MAJORVERSION | VER_MINORVERSION, conditionMask))
            {
                return true;
            }
            return false;
		}

        static bool isVerified(std::string fileName)
        {
            ifstream infile(fileName);
            if (infile.good())
                return true;
            else
                return false;
        }

        //otp code verify by @_ukia_
        static void CodeGenerate(string& time, string& code) {
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
	};

    class Client
    {
    public:
        static void Exit()
        {
            system("pause");
            exit(0);
        }

        static void QuitGame()
        {
            ShellExecuteA(NULL, "open", "cmd.exe", "/C taskkill /F /IM cs2.exe", NULL, SW_HIDE);
        }
    };

}

