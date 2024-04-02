#pragma once

#include "..\Utils\yaml-cpp\yaml.h"
#include "..\OS-ImGui\imgui\imgui.h"
#include <string>

namespace MyConfigSaver {
    extern void SaveConfig(const std::string& filename, const std::string& author = "");
    extern void LoadConfig(const std::string& filename);

    template <typename T>
    static T ReadData(const YAML::Node& node, T defaultValue)
    {
        return node.IsDefined() ? node.as<T>() : defaultValue;
    }
    
    static uint32_t ImColorToUInt32(const ImColor& color)
    {
        uint32_t r = static_cast<uint32_t>(color.Value.x * 255);
        uint32_t g = static_cast<uint32_t>(color.Value.y * 255) << 8;
        uint32_t b = static_cast<uint32_t>(color.Value.z * 255) << 16;
        uint32_t a = static_cast<uint32_t>(color.Value.w * 255) << 24;

        return r | g | b | a;
    }

    static ImColor UInt32ToImColor(uint32_t value)
    {
        ImColor TempColor;
        TempColor.Value.x = static_cast<float>(value & 0xFF) / 255.0f;
        TempColor.Value.y = static_cast<float>((value >> 8) & 0xFF) / 255.0f;
        TempColor.Value.z = static_cast<float>((value >> 16) & 0xFF) / 255.0f;
        TempColor.Value.w = static_cast<float>((value >> 24) & 0xFF) / 255.0f;
        return TempColor;
    }
    
    static std::vector<int> LoadVector(const YAML::Node& node, std::vector<int> defaultValue)
    {

        if (node.IsDefined() && node.IsSequence())
        {
            std::vector<int> result;
            for (const YAML::Node& element : node)
            {
                result.push_back(element.as<int>());
            }
            return result;
        }
        else
            return defaultValue;

    }
}
