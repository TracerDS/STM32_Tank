#pragma once

#include <initializer_list>
#include <main.hpp>

#include <cstdint>

class HAL {
public:
    static void TogglePin(std::uint16_t pin) noexcept;
    static void TogglePins(std::initializer_list<std::uint16_t> pins) noexcept;

    static void WritePin(std::uint16_t pin, bool state) noexcept;
    static void WritePins(std::initializer_list<std::uint16_t> pins, bool state) noexcept;
    
    static bool ReadPin(std::uint16_t pin) noexcept;

    static std::uint32_t GetTick() noexcept;
};