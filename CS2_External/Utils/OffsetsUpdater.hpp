#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "curl/curl.h"
#include "json/json.hpp"
#include <ostream>

namespace Updater
{
    inline void OffsetsParser(std::map<std::string, int>& map, const std::string& dataPath, const std::string& moduleName) {
        std::ifstream file(dataPath);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << dataPath << std::endl;
            return;
        }

        try {
            nlohmann::json json;
            file >> json;
            for (auto& element : json[moduleName].items()) {
                map[element.key()] = element.value();
            }
        }
        catch (const nlohmann::json::parse_error& e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        file.close();
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