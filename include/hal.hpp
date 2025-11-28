#pragma once

#include <cstdint>
#include <initializer_list>

namespace HAL {
    class HAL {
    public:
        static void Init() noexcept;

        static void TogglePin(std::uint16_t pin) noexcept;
        static void TogglePins(std::initializer_list<std::uint16_t> pins) noexcept;

        static void WritePin(std::uint16_t pin, bool value) noexcept;
        static void WritePins(
            std::initializer_list<std::uint16_t> pins,
            bool value
        ) noexcept;

        static bool ReadPin(std::uint16_t pin) noexcept;

        static std::uint32_t GetTick() noexcept;
        static void Delay(std::uint32_t ms) noexcept;
    };
}