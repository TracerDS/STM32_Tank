#include <hal.hpp>
#include <main.hpp>

#include <stm32f4xx_hal.h>

namespace STM32 {
    GPIO_TypeDef* PinToGPIO(HAL::GPIOPin pin) noexcept {
        std::uint32_t portCode = (pin >> 16) & 0x0F;

        switch (portCode) {
            case 1: return GPIOA;
            case 2: return GPIOB;
            case 3: return GPIOC;
            case 4: return GPIOD;
            case 5: return GPIOE;
            case 6: return GPIOF;
            case 7: return GPIOG;
            case 8: return GPIOH;
            case 9: return GPIOI;
            case 10: return GPIOJ;
            case 11: return GPIOK;
            default: return nullptr;
        }
    }

    void HAL::Init() noexcept {
        HAL_Init();
    }
    
    void HAL::TogglePin(GPIOPin pin) noexcept {
        GPIO_TypeDef* port = PinToGPIO(pin);
        if (!port)
            return;

        HAL_GPIO_TogglePin(port, pin);
    }

    void HAL::TogglePins(std::initializer_list<GPIOPin> pins) noexcept {
        for (const auto& pin : pins) {
            TogglePin(pin);
        }
    }

    void HAL::WritePin(GPIOPin pin, bool state) noexcept {
        GPIO_TypeDef* port = PinToGPIO(pin);
        if (!port)
            return;

        HAL_GPIO_WritePin(
            port,
            static_cast<std::uint16_t>(pin & 0xFFFF),
            state ? GPIO_PinState::GPIO_PIN_SET : GPIO_PinState::GPIO_PIN_RESET
        );
    }
    
    void HAL::WritePins(
        std::initializer_list<GPIOPin> pins,
        bool value
    ) noexcept {
        for (const auto& pin : pins) {
            WritePin(pin, value);
        }
    }

    bool HAL::ReadPin(GPIOPin pin) noexcept {
        GPIO_TypeDef* port = PinToGPIO(pin);
        if (!port)
            return false;

        return HAL_GPIO_ReadPin(port, pin) == GPIO_PinState::GPIO_PIN_SET;
    }

    std::uint32_t HAL::GetTick() noexcept {
        return HAL_GetTick();
    }

    void HAL::Delay(std::uint32_t ms) noexcept {
        HAL_Delay(ms);
    }
}