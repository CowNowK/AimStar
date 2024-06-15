#pragma once
#include <array>
#include <sstream>
#include <string>

#pragma pack(push, 1)
struct Color4r {

    std::array<float, 4> color{ 1.0f, 1.0f, 1.0f, 1.0f };
    float rainbowSpeed = 0.6f;
    bool rainbow = false;

    template <typename Configurator>
    void configure(Configurator& configurator)
    {
        configurator("Color", color)
            .def({ 1.0f, 1.0f, 1.0f, 1.0f })
            .loadString([this](std::string str) {
            if (str.length() == 7 && str[0] == '#') {
                const auto color_ = std::strtol(str.c_str() + 1, nullptr, 16);
                color[0] = ((color_ >> 16) & 0xFF) / 255.0f;
                color[1] = ((color_ >> 8) & 0xFF) / 255.0f;
                color[2] = (color_ & 0xFF) / 255.0f;
            }
                })
            .save([this]() {
                    std::ostringstream s;
                    s << '#' << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(color[0] * 255) << std::setw(2) << static_cast<int>(color[1] * 255) << std::setw(2) << static_cast<int>(color[2] * 255);
                    return s.str();
                });

                configurator("Alpha", color[3]).def(1.0f);
                configurator("Rainbow Speed", rainbowSpeed).def(0.6f);
                configurator("Rainbow", rainbow).def(false);
    }
};

struct Color3r {
    std::array<float, 3> color{ 1.0f, 1.0f, 1.0f };
    float rainbowSpeed = 0.6f;
    bool rainbow = false;
};