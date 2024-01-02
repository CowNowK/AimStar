#pragma once

#include <random>
#include <type_traits>

template <typename T>
inline T RandomPara(T min, T max) {

    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_integral<T>::value) {
        // T is int
        std::uniform_int_distribution<T> distribution(min, max);
        return distribution(gen);
    }
    else if constexpr (std::is_floating_point<T>::value) {
        // T is float
        std::uniform_real_distribution<T> distribution(min, max);
        return distribution(gen);
    }
    else {
        // T isn't int or float
        static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type.");
    }
}