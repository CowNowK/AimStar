#pragma once

#include "..\Utils\yaml-cpp\yaml.h"
#include <string>

namespace MyConfigSaver {
    extern void SaveConfig(const std::string& filename, const std::string& author = "");
    extern void LoadConfig(const std::string& filename);
}
