#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <iphlpapi.h>
#include <sstream>
#include <iomanip>

#pragma comment(lib, "iphlpapi.lib")

namespace Init
{
    inline std::string MAC10() {
        IP_ADAPTER_INFO AdapterInfo[16];
        DWORD dwBufLen = sizeof(AdapterInfo);
        DWORD dwStatus = GetAdaptersInfo(AdapterInfo, &dwBufLen);

        if (dwStatus != ERROR_SUCCESS) {
            return "Error";
        }

        PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
        std::stringstream macAddress;

        do {
            macAddress << std::hex << std::uppercase
                << std::setw(2) << std::setfill('0') << static_cast<int>(pAdapterInfo->Address[0])
                << std::setw(2) << std::setfill('0') << static_cast<int>(pAdapterInfo->Address[1])
                << std::setw(2) << std::setfill('0') << static_cast<int>(pAdapterInfo->Address[2])
                << std::setw(2) << std::setfill('0') << static_cast<int>(pAdapterInfo->Address[3])
                << std::setw(2) << std::setfill('0') << static_cast<int>(pAdapterInfo->Address[4])
                << std::setw(2) << std::setfill('0') << static_cast<int>(pAdapterInfo->Address[5]);

            pAdapterInfo = pAdapterInfo->Next;
        } while (pAdapterInfo);

        return macAddress.str();
    }

    inline std::string HardDick() {
        DWORD serialNum;
        GetVolumeInformationA(
            "C:\\",
            NULL,
            0,
            &serialNum,
            NULL,
            NULL,
            NULL,
            0
        );

        std::stringstream ss;
        ss << serialNum;
        return ss.str();
    }
}