#pragma once

#include <cstdint>
#include <initializer_list>

namespace STM32 {
    class HAL {
    public:
        using GPIOPin = std::uint32_t;
        
        static void Init() noexcept;

        static void TogglePin(GPIOPin pin) noexcept;
        static void TogglePins(std::initializer_list<GPIOPin> pins) noexcept;

        static void WritePin(GPIOPin pin, bool value) noexcept;
        static void WritePins(
            std::initializer_list<GPIOPin> pins,
            bool value
        ) noexcept;

        static bool ReadPin(GPIOPin pin) noexcept;

        static std::uint32_t GetTick() noexcept;
        static void Delay(std::uint32_t ms) noexcept;
    };
}