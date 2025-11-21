#pragma once

#include "main.hpp"
#include "stm32f429xx.h"
#include <cstdint>
class HAL {
public:
    static void TogglePin(std::uint16_t pin) noexcept;
};