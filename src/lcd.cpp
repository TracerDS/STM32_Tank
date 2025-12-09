#include "hal.hpp"
#include <lcd.hpp>
#include <main.hpp>

namespace STM32 {
    namespace Commands {
        constexpr std::uint8_t ClearDisplay = 0x01;
        constexpr std::uint8_t ReturnHome = 0x02;
        constexpr std::uint8_t EntryModeSet = 0x04;
        constexpr std::uint8_t DisplayControl = 0x08;
        constexpr std::uint8_t FunctionSet = 0x20;
        constexpr std::uint8_t SetDDRAMAddr = 0x80;
    }

    constexpr auto RS_Pin = Pins::PA6_Pin;
    constexpr auto E_Pin = Pins::PB6_Pin;
    constexpr auto D0_Pin = Pins::PG14_Pin;
    constexpr auto D1_Pin = Pins::PF15_Pin;
    constexpr auto D2_Pin = Pins::PE13_Pin;
    constexpr auto D3_Pin = Pins::PF14_Pin;
    constexpr auto D4_Pin = Pins::PE11_Pin;
    constexpr auto D5_Pin = Pins::PE9_Pin;
    constexpr auto D6_Pin = Pins::PF13_Pin;
    constexpr auto D7_Pin = Pins::PF12_Pin;

    inline auto RS_GPIO_Port = Pins::Options::PinToGPIO(RS_Pin);
    inline auto E_GPIO_Port  = Pins::Options::PinToGPIO(E_Pin);
    inline auto D0_GPIO_Port = Pins::Options::PinToGPIO(D0_Pin);
    inline auto D1_GPIO_Port = Pins::Options::PinToGPIO(D1_Pin);
    inline auto D2_GPIO_Port = Pins::Options::PinToGPIO(D2_Pin);
    inline auto D3_GPIO_Port = Pins::Options::PinToGPIO(D3_Pin);
    inline auto D4_GPIO_Port = Pins::Options::PinToGPIO(D4_Pin);
    inline auto D5_GPIO_Port = Pins::Options::PinToGPIO(D5_Pin);
    inline auto D6_GPIO_Port = Pins::Options::PinToGPIO(D6_Pin);
    inline auto D7_GPIO_Port = Pins::Options::PinToGPIO(D7_Pin);

    void Pulse() noexcept {
        HAL::WritePin(E_Pin, true);
        HAL::Delay(1); // Enable pulse must be >450ns
        HAL::WritePin(E_Pin, false);
        HAL::Delay(1); // Enable pulse must be >450ns
    }

    void Send(std::uint8_t data) noexcept {
        HAL::WritePin(D0_Pin, (data >> 0) & 1);
        HAL::WritePin(D1_Pin, (data >> 1) & 1);
        HAL::WritePin(D2_Pin, (data >> 2) & 1);
        HAL::WritePin(D3_Pin, (data >> 3) & 1);
        HAL::WritePin(D4_Pin, (data >> 4) & 1);
        HAL::WritePin(D5_Pin, (data >> 5) & 1);
        HAL::WritePin(D6_Pin, (data >> 6) & 1);
        HAL::WritePin(D7_Pin, (data >> 7) & 1);
    }

    void LCD::Init() noexcept {
        // 0. Wait for LCD to stabilize
        //while(HAL::GetTick() < 50);
        HAL::Delay(50);

        // 1. Init
        HAL::WritePins({ RS_Pin, E_Pin }, false);

        // 2. Initialize 8bit mode
        LCD::SendCommand(0x38);
        HAL::Delay(5);
        LCD::SendCommand(0x38);
        HAL::Delay(1);
        LCD::SendCommand(0x38);
        HAL::Delay(1);

        // 3. Full Function Set command (8-bit, 2 lines, 5x8 font)
        LCD::SendCommand(0x38);
        HAL::Delay(1);

        // 4. Screen enabled, cursor disabled, blinking disabled
        LCD::SendCommand(0x0C);

        // 5. Clear screen
        LCD::Clear();

        // 6. Entry Mode Set (Increment, No Shift)
        LCD::SendCommand(0x06);
    }
    
    void LCD::Clear() noexcept {
        LCD::SendCommand(Commands::ClearDisplay);
        HAL::Delay(2); // Requires >1.52ms delay
    }

    void LCD::SetCursor(std::uint16_t x, std::uint16_t y) noexcept {
        std::uint8_t address;
        
        if (x == 0) {
            address = 0x00 + y;
        } else {
            address = 0x40 + y;
        }
        
        LCD::SendCommand(Commands::SetDDRAMAddr | address);
    }

    void LCD::Print(std::string_view str) noexcept {
        for (const auto& c : str) {
            LCD::SendData(static_cast<std::uint8_t>(c));
        }
    }

    void LCD::SendCommand(std::uint8_t cmd) noexcept {
        HAL::WritePin(RS_Pin, false);
        Send(cmd);
        Pulse();
    }

    void LCD::SendData(std::uint8_t data) noexcept {
        HAL::WritePin(RS_Pin, true);
        Send(data);
        Pulse();
    }
}