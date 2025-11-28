#pragma once

#include <cstdint>
#include <string_view>

namespace STM32 {
    class LCD {
    public:
        static void Init() noexcept;
        static void Clear() noexcept;
        static void SetCursor(std::uint16_t x, std::uint16_t y) noexcept;
        static void Print(std::string_view str) noexcept;

        static void SendCommand(std::uint8_t cmd) noexcept;
        static void SendData(std::uint8_t data) noexcept;
    };
}