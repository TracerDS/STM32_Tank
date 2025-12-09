#include <hal.hpp>
#include <gpio.hpp>
#include <main.hpp>

#include <initializer_list>
#include <array>
#include <utility>

namespace STM32 {
    void InitializePin(
        std::uint32_t pin,
        unsigned long mode = GPIO_MODE_OUTPUT_PP,
        unsigned int pull = GPIO_NOPULL,
        unsigned int speed = GPIO_SPEED_FREQ_LOW
    ) noexcept {
        GPIO_InitTypeDef GPIO_InitStruct{};
        GPIO_InitStruct.Pin = pin & 0xFFFF;
        GPIO_InitStruct.Mode = mode;
        GPIO_InitStruct.Pull = pull;
        GPIO_InitStruct.Speed = speed;

        HAL_GPIO_Init(
            Pins::Options::PinToGPIO(pin),
            &GPIO_InitStruct
        );
    }
    void InitializePins(
        std::initializer_list<std::uint32_t> pins,
        unsigned long mode = GPIO_MODE_OUTPUT_PP,
        unsigned int pull = GPIO_NOPULL,
        unsigned int speed = GPIO_SPEED_FREQ_LOW
    ) noexcept {
        for (const auto& pin : pins) {
            InitializePin(pin, mode, pull, speed);
        }
    }

    void GPIO::Init() {
        // GPIO Ports Clock Enable
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOD_CLK_ENABLE();
        __HAL_RCC_GPIOE_CLK_ENABLE();
        __HAL_RCC_GPIOF_CLK_ENABLE();
        __HAL_RCC_GPIOG_CLK_ENABLE();
        __HAL_RCC_GPIOH_CLK_ENABLE();
        __HAL_RCC_GPIOI_CLK_ENABLE();
        __HAL_RCC_GPIOJ_CLK_ENABLE();
        __HAL_RCC_GPIOK_CLK_ENABLE();

        constexpr std::array<
            std::pair<std::uint32_t, unsigned long>,
            18
        > EnabledPins = {{
            { Pins::PA6_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PB0_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PB4_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PB5_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PB6_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PB7_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PB14_Pin, GPIO_MODE_OUTPUT_PP },
            { Pins::PC0_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PD3_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PE9_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PE11_Pin, GPIO_MODE_OUTPUT_PP },
            { Pins::PE13_Pin, GPIO_MODE_OUTPUT_PP },
            { Pins::PF12_Pin, GPIO_MODE_OUTPUT_PP },
            { Pins::PF13_Pin, GPIO_MODE_OUTPUT_PP },
            { Pins::PF14_Pin, GPIO_MODE_OUTPUT_PP },
            { Pins::PF15_Pin, GPIO_MODE_OUTPUT_PP },
            { Pins::PG6_Pin,  GPIO_MODE_OUTPUT_PP },
            { Pins::PG14_Pin,  GPIO_MODE_OUTPUT_PP },
        }};

        for (const auto& [pin, mode] : EnabledPins) {
            InitializePin(pin, mode);
        }

        InitializePin(Pins::USER_Btn_Pin, GPIO_MODE_IT_RISING);
        InitializePin(Pins::USB_OverCurrent_Pin, GPIO_MODE_INPUT);
    }
}