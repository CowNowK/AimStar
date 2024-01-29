#pragma once
#include "curl/curl.h"
#include "../MenuConfig.hpp"

namespace Updater
{
    inline size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t totalSize = size * nmemb;
        output->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }

    inline std::string GetLatestVersionFromGitHub() {
        CURL* curl;
        CURLcode res;

        std::string readBuffer;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if (curl) {
            std::string apiUrl = "https://api.github.com/repos/CowNowK/AimStar/releases/latest";
            curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            
            /*
            if (res != CURLE_OK) {
                std::cerr << "Failed to perform HTTP request: " << curl_easy_strerror(res) << std::endl;
            }
            */

            curl_easy_cleanup(curl);
        }

        size_t startPos = readBuffer.find("\"tag_name\":") + 13;
        if (startPos == std::string::npos) {
            // std::cerr << "Failed to find \"tag_name\" in the JSON response." << std::endl;
            return "";
        }

        size_t endPos = readBuffer.find("\"", startPos);
        if (endPos == std::string::npos) {
            // std::cerr << "Failed to find closing double quote in the JSON response." << std::endl;
            return "";
        }

        std::string latestVersion = readBuffer.substr(startPos, endPos - startPos);

        return latestVersion;
    }

    inline void CheckForUpdates() {
        std::string LatestVersion = GetLatestVersionFromGitHub();

        if (LatestVersion == "")
        {
            std::cout << "[Info] Failed to check update." << std::endl;
            return;
        }

        if (LatestVersion != MenuConfig::LocalVersion) {
            std::cout << "A new update is available: " << LatestVersion << std::endl;
        }
        else {
            std::cout << "You are using the latest version." << std::endl;
        }
    }
}