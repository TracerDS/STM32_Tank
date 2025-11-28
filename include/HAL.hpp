#pragma once

#include <cstdint>

namespace HAL {
    class HAL {
    public:
        static void TogglePin(std::uint16_t pin) noexcept;

        static void WritePin(std::uint16_t pin, bool value) noexcept;
        static bool ReadPin(std::uint16_t pin) noexcept;

        static std::uint32_t GetTick() noexcept;
        static void Delay(std::uint32_t ms) noexcept;
    };
}