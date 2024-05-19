#pragma once
#include <iostream>
#include <map>
#include <string>
#include "curl/curl.h"
#include "json/json.hpp"
#include <ostream>

namespace Updater
{
    static size_t WriteCallback(void* Contents, size_t Size, size_t nmemb, std::string* s) {
        size_t newLength = Size * nmemb;
        try {
            s->append((char*)Contents, newLength);
        }
        catch (std::bad_alloc& e) {
            // Used to handle out of memory errors
            return 0;
        }
        return newLength;
    }

    inline void OffsetsParser(std::map<std::string, int>& map, const std::string& url, const std::string& moduleName) {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }
            else {
                // Uses json.h to parse json data
                auto json = nlohmann::json::parse(readBuffer);
                for (auto& element : json[moduleName].items()) {
                    map[element.key()] = element.value();
                }
            }
        }
    }

    inline int GetOffset(const std::map<std::string, int>& Offsets, const std::string& Name) {
        auto it = Offsets.find(Name);
        if (it != Offsets.end()) {
            return it->second;
        }
        else {
            std::cerr << "Offset [" << Name << "] not found." << std::endl;
            return -1;
        }
    }
}