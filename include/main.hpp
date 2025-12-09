#pragma once

#include <cstdint>

extern "C" {
#   include <stm32f4xx_hal.h>
}

void Error_Handler();

namespace Pins {
    namespace Options {
        // PIN Layout
        // EXTRA DATA         | HARDWARE BITS 
        // 00000000 00000000 | XXXXXXXX XXXXXXXX
        // -------------------------------------
        // PIN[16:19] = Port ID 0x1=A, 0xB=K, 0xF=Invalid

        constexpr std::uint32_t PortA = 1 << 16;
        constexpr std::uint32_t PortB = 2 << 16;
        constexpr std::uint32_t PortC = 3 << 16;
        constexpr std::uint32_t PortD = 4 << 16;
        constexpr std::uint32_t PortE = 5 << 16;
        constexpr std::uint32_t PortF = 6 << 16;
        constexpr std::uint32_t PortG = 7 << 16;
        constexpr std::uint32_t PortH = 8 << 16;
        constexpr std::uint32_t PortI = 9 << 16;
        constexpr std::uint32_t PortJ = 10 << 16;
        constexpr std::uint32_t PortK = 11 << 16;

        constexpr GPIO_TypeDef* PinToGPIO(
            std::uint32_t pin
        ) noexcept {
            switch (pin >> 16) {
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
                default:
                    return nullptr;
            }
        }
    }

    // User Pins
    constexpr std::uint32_t PA0_Pin = GPIO_PIN_0 | Options::PortA;
    constexpr std::uint32_t PA1_Pin = GPIO_PIN_1 | Options::PortA;
    constexpr std::uint32_t PA2_Pin = GPIO_PIN_2 | Options::PortA;
    constexpr std::uint32_t PA3_Pin = GPIO_PIN_3 | Options::PortA;
    constexpr std::uint32_t PA4_Pin = GPIO_PIN_4 | Options::PortA;
    constexpr std::uint32_t PA5_Pin = GPIO_PIN_5 | Options::PortA;
    constexpr std::uint32_t PA6_Pin = GPIO_PIN_6 | Options::PortA;
    constexpr std::uint32_t PA7_Pin = GPIO_PIN_7 | Options::PortA;
    constexpr std::uint32_t PA8_Pin = GPIO_PIN_8 | Options::PortA;
    constexpr std::uint32_t PA9_Pin = GPIO_PIN_9 | Options::PortA;
    constexpr std::uint32_t PA10_Pin = GPIO_PIN_10 | Options::PortA;
    constexpr std::uint32_t PA11_Pin = GPIO_PIN_11 | Options::PortA;
    constexpr std::uint32_t PA12_Pin = GPIO_PIN_12 | Options::PortA;
    constexpr std::uint32_t PA13_Pin = GPIO_PIN_13 | Options::PortA;
    constexpr std::uint32_t PA14_Pin = GPIO_PIN_14 | Options::PortA;
    constexpr std::uint32_t PA15_Pin = GPIO_PIN_15 | Options::PortA;

    constexpr std::uint32_t PB0_Pin = GPIO_PIN_0 | Options::PortB;
    constexpr std::uint32_t PB1_Pin = GPIO_PIN_1 | Options::PortB;
    constexpr std::uint32_t PB2_Pin = GPIO_PIN_2 | Options::PortB;
    constexpr std::uint32_t PB3_Pin = GPIO_PIN_3 | Options::PortB;
    constexpr std::uint32_t PB4_Pin = GPIO_PIN_4 | Options::PortB;
    constexpr std::uint32_t PB5_Pin = GPIO_PIN_5 | Options::PortB;
    constexpr std::uint32_t PB6_Pin = GPIO_PIN_6 | Options::PortB;
    constexpr std::uint32_t PB7_Pin = GPIO_PIN_7 | Options::PortB;
    constexpr std::uint32_t PB8_Pin = GPIO_PIN_8 | Options::PortB;
    constexpr std::uint32_t PB9_Pin = GPIO_PIN_9 | Options::PortB;
    constexpr std::uint32_t PB10_Pin = GPIO_PIN_10 | Options::PortB;
    constexpr std::uint32_t PB11_Pin = GPIO_PIN_11 | Options::PortB;
    constexpr std::uint32_t PB12_Pin = GPIO_PIN_12 | Options::PortB;
    constexpr std::uint32_t PB13_Pin = GPIO_PIN_13 | Options::PortB;
    constexpr std::uint32_t PB14_Pin = GPIO_PIN_14 | Options::PortB;
    constexpr std::uint32_t PB15_Pin = GPIO_PIN_15 | Options::PortB;

    constexpr std::uint32_t PC0_Pin = GPIO_PIN_0 | Options::PortC;
    constexpr std::uint32_t PC1_Pin = GPIO_PIN_1 | Options::PortC;
    constexpr std::uint32_t PC2_Pin = GPIO_PIN_2 | Options::PortC;
    constexpr std::uint32_t PC3_Pin = GPIO_PIN_3 | Options::PortC;
    constexpr std::uint32_t PC4_Pin = GPIO_PIN_4 | Options::PortC;
    constexpr std::uint32_t PC5_Pin = GPIO_PIN_5 | Options::PortC;
    constexpr std::uint32_t PC6_Pin = GPIO_PIN_6 | Options::PortC;
    constexpr std::uint32_t PC7_Pin = GPIO_PIN_7 | Options::PortC;
    constexpr std::uint32_t PC8_Pin = GPIO_PIN_8 | Options::PortC;
    constexpr std::uint32_t PC9_Pin = GPIO_PIN_9 | Options::PortC;
    constexpr std::uint32_t PC10_Pin = GPIO_PIN_10 | Options::PortC;
    constexpr std::uint32_t PC11_Pin = GPIO_PIN_11 | Options::PortC;
    constexpr std::uint32_t PC12_Pin = GPIO_PIN_12 | Options::PortC;
    constexpr std::uint32_t PC13_Pin = GPIO_PIN_13 | Options::PortC;
    constexpr std::uint32_t PC14_Pin = GPIO_PIN_14 | Options::PortC;
    constexpr std::uint32_t PC15_Pin = GPIO_PIN_15 | Options::PortC;

    constexpr std::uint32_t PD0_Pin = GPIO_PIN_0 | Options::PortD;
    constexpr std::uint32_t PD1_Pin = GPIO_PIN_1 | Options::PortD;
    constexpr std::uint32_t PD2_Pin = GPIO_PIN_2 | Options::PortD;
    constexpr std::uint32_t PD3_Pin = GPIO_PIN_3 | Options::PortD;
    constexpr std::uint32_t PD4_Pin = GPIO_PIN_4 | Options::PortD;
    constexpr std::uint32_t PD5_Pin = GPIO_PIN_5 | Options::PortD;
    constexpr std::uint32_t PD6_Pin = GPIO_PIN_6 | Options::PortD;
    constexpr std::uint32_t PD7_Pin = GPIO_PIN_7 | Options::PortD;
    constexpr std::uint32_t PD8_Pin = GPIO_PIN_8 | Options::PortD;
    constexpr std::uint32_t PD9_Pin = GPIO_PIN_9 | Options::PortD;
    constexpr std::uint32_t PD10_Pin = GPIO_PIN_10 | Options::PortD;
    constexpr std::uint32_t PD11_Pin = GPIO_PIN_11 | Options::PortD;
    constexpr std::uint32_t PD12_Pin = GPIO_PIN_12 | Options::PortD;
    constexpr std::uint32_t PD13_Pin = GPIO_PIN_13 | Options::PortD;
    constexpr std::uint32_t PD14_Pin = GPIO_PIN_14 | Options::PortD;
    constexpr std::uint32_t PD15_Pin = GPIO_PIN_15 | Options::PortD;

    constexpr std::uint32_t PE0_Pin = GPIO_PIN_0 | Options::PortE;
    constexpr std::uint32_t PE1_Pin = GPIO_PIN_1 | Options::PortE;
    constexpr std::uint32_t PE2_Pin = GPIO_PIN_2 | Options::PortE;
    constexpr std::uint32_t PE3_Pin = GPIO_PIN_3 | Options::PortE;
    constexpr std::uint32_t PE4_Pin = GPIO_PIN_4 | Options::PortE;
    constexpr std::uint32_t PE5_Pin = GPIO_PIN_5 | Options::PortE;
    constexpr std::uint32_t PE6_Pin = GPIO_PIN_6 | Options::PortE;
    constexpr std::uint32_t PE7_Pin = GPIO_PIN_7 | Options::PortE;
    constexpr std::uint32_t PE8_Pin = GPIO_PIN_8 | Options::PortE;
    constexpr std::uint32_t PE9_Pin = GPIO_PIN_9 | Options::PortE;
    constexpr std::uint32_t PE10_Pin = GPIO_PIN_10 | Options::PortE;
    constexpr std::uint32_t PE11_Pin = GPIO_PIN_11 | Options::PortE;
    constexpr std::uint32_t PE12_Pin = GPIO_PIN_12 | Options::PortE;
    constexpr std::uint32_t PE13_Pin = GPIO_PIN_13 | Options::PortE;
    constexpr std::uint32_t PE14_Pin = GPIO_PIN_14 | Options::PortE;
    constexpr std::uint32_t PE15_Pin = GPIO_PIN_15 | Options::PortE;

    constexpr std::uint32_t PF0_Pin = GPIO_PIN_0 | Options::PortF;
    constexpr std::uint32_t PF1_Pin = GPIO_PIN_1 | Options::PortF;
    constexpr std::uint32_t PF2_Pin = GPIO_PIN_2 | Options::PortF;
    constexpr std::uint32_t PF3_Pin = GPIO_PIN_3 | Options::PortF;
    constexpr std::uint32_t PF4_Pin = GPIO_PIN_4 | Options::PortF;
    constexpr std::uint32_t PF5_Pin = GPIO_PIN_5 | Options::PortF;
    constexpr std::uint32_t PF6_Pin = GPIO_PIN_6 | Options::PortF;
    constexpr std::uint32_t PF7_Pin = GPIO_PIN_7 | Options::PortF;
    constexpr std::uint32_t PF8_Pin = GPIO_PIN_8 | Options::PortF;
    constexpr std::uint32_t PF9_Pin = GPIO_PIN_9 | Options::PortF;
    constexpr std::uint32_t PF10_Pin = GPIO_PIN_10 | Options::PortF;
    constexpr std::uint32_t PF11_Pin = GPIO_PIN_11 | Options::PortF;
    constexpr std::uint32_t PF12_Pin = GPIO_PIN_12 | Options::PortF;
    constexpr std::uint32_t PF13_Pin = GPIO_PIN_13 | Options::PortF;
    constexpr std::uint32_t PF14_Pin = GPIO_PIN_14 | Options::PortF;
    constexpr std::uint32_t PF15_Pin = GPIO_PIN_15 | Options::PortF;

    constexpr std::uint32_t PG0_Pin = GPIO_PIN_0 | Options::PortG;
    constexpr std::uint32_t PG1_Pin = GPIO_PIN_1 | Options::PortG;
    constexpr std::uint32_t PG2_Pin = GPIO_PIN_2 | Options::PortG;
    constexpr std::uint32_t PG3_Pin = GPIO_PIN_3 | Options::PortG;
    constexpr std::uint32_t PG4_Pin = GPIO_PIN_4 | Options::PortG;
    constexpr std::uint32_t PG5_Pin = GPIO_PIN_5 | Options::PortG;
    constexpr std::uint32_t PG6_Pin = GPIO_PIN_6 | Options::PortG;
    constexpr std::uint32_t PG7_Pin = GPIO_PIN_7 | Options::PortG;
    constexpr std::uint32_t PG8_Pin = GPIO_PIN_8 | Options::PortG;
    constexpr std::uint32_t PG9_Pin = GPIO_PIN_9 | Options::PortG;
    constexpr std::uint32_t PG10_Pin = GPIO_PIN_10 | Options::PortG;
    constexpr std::uint32_t PG11_Pin = GPIO_PIN_11 | Options::PortG;
    constexpr std::uint32_t PG12_Pin = GPIO_PIN_12 | Options::PortG;
    constexpr std::uint32_t PG13_Pin = GPIO_PIN_13 | Options::PortG;
    constexpr std::uint32_t PG14_Pin = GPIO_PIN_14 | Options::PortG;
    constexpr std::uint32_t PG15_Pin = GPIO_PIN_15 | Options::PortG;

    constexpr std::uint32_t PH0_Pin = GPIO_PIN_0 | Options::PortH;
    constexpr std::uint32_t PH1_Pin = GPIO_PIN_1 | Options::PortH;
    constexpr std::uint32_t PH2_Pin = GPIO_PIN_2 | Options::PortH;
    constexpr std::uint32_t PH3_Pin = GPIO_PIN_3 | Options::PortH;
    constexpr std::uint32_t PH4_Pin = GPIO_PIN_4 | Options::PortH;
    constexpr std::uint32_t PH5_Pin = GPIO_PIN_5 | Options::PortH;
    constexpr std::uint32_t PH6_Pin = GPIO_PIN_6 | Options::PortH;
    constexpr std::uint32_t PH7_Pin = GPIO_PIN_7 | Options::PortH;
    constexpr std::uint32_t PH8_Pin = GPIO_PIN_8 | Options::PortH;
    constexpr std::uint32_t PH9_Pin = GPIO_PIN_9 | Options::PortH;
    constexpr std::uint32_t PH10_Pin = GPIO_PIN_10 | Options::PortH;
    constexpr std::uint32_t PH11_Pin = GPIO_PIN_11 | Options::PortH;
    constexpr std::uint32_t PH12_Pin = GPIO_PIN_12 | Options::PortH;
    constexpr std::uint32_t PH13_Pin = GPIO_PIN_13 | Options::PortH;
    constexpr std::uint32_t PH14_Pin = GPIO_PIN_14 | Options::PortH;
    constexpr std::uint32_t PH15_Pin = GPIO_PIN_15 | Options::PortH;

    constexpr std::uint32_t PJ0_Pin = GPIO_PIN_0 | Options::PortJ;
    constexpr std::uint32_t PJ1_Pin = GPIO_PIN_1 | Options::PortJ;
    constexpr std::uint32_t PJ2_Pin = GPIO_PIN_2 | Options::PortJ;
    constexpr std::uint32_t PJ3_Pin = GPIO_PIN_3 | Options::PortJ;
    constexpr std::uint32_t PJ4_Pin = GPIO_PIN_4 | Options::PortJ;
    constexpr std::uint32_t PJ5_Pin = GPIO_PIN_5 | Options::PortJ;
    constexpr std::uint32_t PJ6_Pin = GPIO_PIN_6 | Options::PortJ;
    constexpr std::uint32_t PJ7_Pin = GPIO_PIN_7 | Options::PortJ;
    constexpr std::uint32_t PJ8_Pin = GPIO_PIN_8 | Options::PortJ;
    constexpr std::uint32_t PJ9_Pin = GPIO_PIN_9 | Options::PortJ;
    constexpr std::uint32_t PJ10_Pin = GPIO_PIN_10 | Options::PortJ;
    constexpr std::uint32_t PJ11_Pin = GPIO_PIN_11 | Options::PortJ;
    constexpr std::uint32_t PJ12_Pin = GPIO_PIN_12 | Options::PortJ;
    constexpr std::uint32_t PJ13_Pin = GPIO_PIN_13 | Options::PortJ;
    constexpr std::uint32_t PJ14_Pin = GPIO_PIN_14 | Options::PortJ;
    constexpr std::uint32_t PJ15_Pin = GPIO_PIN_15 | Options::PortJ;

    constexpr std::uint32_t PK0_Pin = GPIO_PIN_0 | Options::PortK;
    constexpr std::uint32_t PK1_Pin = GPIO_PIN_1 | Options::PortK;
    constexpr std::uint32_t PK2_Pin = GPIO_PIN_2 | Options::PortK;
    constexpr std::uint32_t PK3_Pin = GPIO_PIN_3 | Options::PortK;
    constexpr std::uint32_t PK4_Pin = GPIO_PIN_4 | Options::PortK;
    constexpr std::uint32_t PK5_Pin = GPIO_PIN_5 | Options::PortK;
    constexpr std::uint32_t PK6_Pin = GPIO_PIN_6 | Options::PortK;
    constexpr std::uint32_t PK7_Pin = GPIO_PIN_7 | Options::PortK;
    constexpr std::uint32_t PK8_Pin = GPIO_PIN_8 | Options::PortK;
    constexpr std::uint32_t PK9_Pin = GPIO_PIN_9 | Options::PortK;
    constexpr std::uint32_t PK10_Pin = GPIO_PIN_10 | Options::PortK;
    constexpr std::uint32_t PK11_Pin = GPIO_PIN_11 | Options::PortK;
    constexpr std::uint32_t PK12_Pin = GPIO_PIN_12 | Options::PortK;
    constexpr std::uint32_t PK13_Pin = GPIO_PIN_13 | Options::PortK;
    constexpr std::uint32_t PK14_Pin = GPIO_PIN_14 | Options::PortK;
    constexpr std::uint32_t PK15_Pin = GPIO_PIN_15 | Options::PortK;
    
    inline auto PA0_GPIO_Port = Options::PinToGPIO(PA0_Pin);
    inline auto PA1_GPIO_Port = Options::PinToGPIO(PA1_Pin);
    inline auto PA2_GPIO_Port = Options::PinToGPIO(PA2_Pin);
    inline auto PA3_GPIO_Port = Options::PinToGPIO(PA3_Pin);
    inline auto PA4_GPIO_Port = Options::PinToGPIO(PA4_Pin);
    inline auto PA5_GPIO_Port = Options::PinToGPIO(PA5_Pin);
    inline auto PA6_GPIO_Port = Options::PinToGPIO(PA6_Pin);
    inline auto PA7_GPIO_Port = Options::PinToGPIO(PA7_Pin);
    inline auto PA8_GPIO_Port = Options::PinToGPIO(PA8_Pin);
    inline auto PA9_GPIO_Port = Options::PinToGPIO(PA9_Pin);
    inline auto PA10_GPIO_Port = Options::PinToGPIO(PA10_Pin);
    inline auto PA11_GPIO_Port = Options::PinToGPIO(PA11_Pin);
    inline auto PA12_GPIO_Port = Options::PinToGPIO(PA12_Pin);
    inline auto PA13_GPIO_Port = Options::PinToGPIO(PA13_Pin);
    inline auto PA14_GPIO_Port = Options::PinToGPIO(PA14_Pin);
    inline auto PA15_GPIO_Port = Options::PinToGPIO(PA15_Pin);

    inline auto PB0_GPIO_Port = Options::PinToGPIO(PB0_Pin);
    inline auto PB1_GPIO_Port = Options::PinToGPIO(PB1_Pin);
    inline auto PB2_GPIO_Port = Options::PinToGPIO(PB2_Pin);
    inline auto PB3_GPIO_Port = Options::PinToGPIO(PB3_Pin);
    inline auto PB4_GPIO_Port = Options::PinToGPIO(PB4_Pin);
    inline auto PB5_GPIO_Port = Options::PinToGPIO(PB5_Pin);
    inline auto PB6_GPIO_Port = Options::PinToGPIO(PB6_Pin);
    inline auto PB7_GPIO_Port = Options::PinToGPIO(PB7_Pin);
    inline auto PB8_GPIO_Port = Options::PinToGPIO(PB8_Pin);
    inline auto PB9_GPIO_Port = Options::PinToGPIO(PB9_Pin);
    inline auto PB10_GPIO_Port = Options::PinToGPIO(PB10_Pin);
    inline auto PB11_GPIO_Port = Options::PinToGPIO(PB11_Pin);
    inline auto PB12_GPIO_Port = Options::PinToGPIO(PB12_Pin);
    inline auto PB13_GPIO_Port = Options::PinToGPIO(PB13_Pin);
    inline auto PB14_GPIO_Port = Options::PinToGPIO(PB14_Pin);
    inline auto PB15_GPIO_Port = Options::PinToGPIO(PB15_Pin);

    inline auto PC0_GPIO_Port = Options::PinToGPIO(PC0_Pin);
    inline auto PC1_GPIO_Port = Options::PinToGPIO(PC1_Pin);
    inline auto PC2_GPIO_Port = Options::PinToGPIO(PC2_Pin);
    inline auto PC3_GPIO_Port = Options::PinToGPIO(PC3_Pin);
    inline auto PC4_GPIO_Port = Options::PinToGPIO(PC4_Pin);
    inline auto PC5_GPIO_Port = Options::PinToGPIO(PC5_Pin);
    inline auto PC6_GPIO_Port = Options::PinToGPIO(PC6_Pin);
    inline auto PC7_GPIO_Port = Options::PinToGPIO(PC7_Pin);
    inline auto PC8_GPIO_Port = Options::PinToGPIO(PC8_Pin);
    inline auto PC9_GPIO_Port = Options::PinToGPIO(PC9_Pin);
    inline auto PC10_GPIO_Port = Options::PinToGPIO(PC10_Pin);
    inline auto PC11_GPIO_Port = Options::PinToGPIO(PC11_Pin);
    inline auto PC12_GPIO_Port = Options::PinToGPIO(PC12_Pin);
    inline auto PC13_GPIO_Port = Options::PinToGPIO(PC13_Pin);
    inline auto PC14_GPIO_Port = Options::PinToGPIO(PC14_Pin);
    inline auto PC15_GPIO_Port = Options::PinToGPIO(PC15_Pin);

    inline auto PD0_GPIO_Port = Options::PinToGPIO(PD0_Pin);
    inline auto PD1_GPIO_Port = Options::PinToGPIO(PD1_Pin);
    inline auto PD2_GPIO_Port = Options::PinToGPIO(PD2_Pin);
    inline auto PD3_GPIO_Port = Options::PinToGPIO(PD3_Pin);
    inline auto PD4_GPIO_Port = Options::PinToGPIO(PD4_Pin);
    inline auto PD5_GPIO_Port = Options::PinToGPIO(PD5_Pin);
    inline auto PD6_GPIO_Port = Options::PinToGPIO(PD6_Pin);
    inline auto PD7_GPIO_Port = Options::PinToGPIO(PD7_Pin);
    inline auto PD8_GPIO_Port = Options::PinToGPIO(PD8_Pin);
    inline auto PD9_GPIO_Port = Options::PinToGPIO(PD9_Pin);
    inline auto PD10_GPIO_Port = Options::PinToGPIO(PD10_Pin);
    inline auto PD11_GPIO_Port = Options::PinToGPIO(PD11_Pin);
    inline auto PD12_GPIO_Port = Options::PinToGPIO(PD12_Pin);
    inline auto PD13_GPIO_Port = Options::PinToGPIO(PD13_Pin);
    inline auto PD14_GPIO_Port = Options::PinToGPIO(PD14_Pin);
    inline auto PD15_GPIO_Port = Options::PinToGPIO(PD15_Pin);

    inline auto PE0_GPIO_Port = Options::PinToGPIO(PE0_Pin);
    inline auto PE1_GPIO_Port = Options::PinToGPIO(PE1_Pin);
    inline auto PE2_GPIO_Port = Options::PinToGPIO(PE2_Pin);
    inline auto PE3_GPIO_Port = Options::PinToGPIO(PE3_Pin);
    inline auto PE4_GPIO_Port = Options::PinToGPIO(PE4_Pin);
    inline auto PE5_GPIO_Port = Options::PinToGPIO(PE5_Pin);
    inline auto PE6_GPIO_Port = Options::PinToGPIO(PE6_Pin);
    inline auto PE7_GPIO_Port = Options::PinToGPIO(PE7_Pin);
    inline auto PE8_GPIO_Port = Options::PinToGPIO(PE8_Pin);
    inline auto PE9_GPIO_Port = Options::PinToGPIO(PE9_Pin);
    inline auto PE10_GPIO_Port = Options::PinToGPIO(PE10_Pin);
    inline auto PE11_GPIO_Port = Options::PinToGPIO(PE11_Pin);
    inline auto PE12_GPIO_Port = Options::PinToGPIO(PE12_Pin);
    inline auto PE13_GPIO_Port = Options::PinToGPIO(PE13_Pin);
    inline auto PE14_GPIO_Port = Options::PinToGPIO(PE14_Pin);
    inline auto PE15_GPIO_Port = Options::PinToGPIO(PE15_Pin);

    inline auto PF0_GPIO_Port = Options::PinToGPIO(PF0_Pin);
    inline auto PF1_GPIO_Port = Options::PinToGPIO(PF1_Pin);
    inline auto PF2_GPIO_Port = Options::PinToGPIO(PF2_Pin);
    inline auto PF3_GPIO_Port = Options::PinToGPIO(PF3_Pin);
    inline auto PF4_GPIO_Port = Options::PinToGPIO(PF4_Pin);
    inline auto PF5_GPIO_Port = Options::PinToGPIO(PF5_Pin);
    inline auto PF6_GPIO_Port = Options::PinToGPIO(PF6_Pin);
    inline auto PF7_GPIO_Port = Options::PinToGPIO(PF7_Pin);
    inline auto PF8_GPIO_Port = Options::PinToGPIO(PF8_Pin);
    inline auto PF9_GPIO_Port = Options::PinToGPIO(PF9_Pin);
    inline auto PF10_GPIO_Port = Options::PinToGPIO(PF10_Pin);
    inline auto PF11_GPIO_Port = Options::PinToGPIO(PF11_Pin);
    inline auto PF12_GPIO_Port = Options::PinToGPIO(PF12_Pin);
    inline auto PF13_GPIO_Port = Options::PinToGPIO(PF13_Pin);
    inline auto PF14_GPIO_Port = Options::PinToGPIO(PF14_Pin);
    inline auto PF15_GPIO_Port = Options::PinToGPIO(PF15_Pin);

    inline auto PG0_GPIO_Port = Options::PinToGPIO(PG0_Pin);
    inline auto PG1_GPIO_Port = Options::PinToGPIO(PG1_Pin);
    inline auto PG2_GPIO_Port = Options::PinToGPIO(PG2_Pin);
    inline auto PG3_GPIO_Port = Options::PinToGPIO(PG3_Pin);
    inline auto PG4_GPIO_Port = Options::PinToGPIO(PG4_Pin);
    inline auto PG5_GPIO_Port = Options::PinToGPIO(PG5_Pin);
    inline auto PG6_GPIO_Port = Options::PinToGPIO(PG6_Pin);
    inline auto PG7_GPIO_Port = Options::PinToGPIO(PG7_Pin);
    inline auto PG8_GPIO_Port = Options::PinToGPIO(PG8_Pin);
    inline auto PG9_GPIO_Port = Options::PinToGPIO(PG9_Pin);
    inline auto PG10_GPIO_Port = Options::PinToGPIO(PG10_Pin);
    inline auto PG11_GPIO_Port = Options::PinToGPIO(PG11_Pin);
    inline auto PG12_GPIO_Port = Options::PinToGPIO(PG12_Pin);
    inline auto PG13_GPIO_Port = Options::PinToGPIO(PG13_Pin);
    inline auto PG14_GPIO_Port = Options::PinToGPIO(PG14_Pin);
    inline auto PG15_GPIO_Port = Options::PinToGPIO(PG15_Pin);

    inline auto PH0_GPIO_Port = Options::PinToGPIO(PH0_Pin);
    inline auto PH1_GPIO_Port = Options::PinToGPIO(PH1_Pin);
    inline auto PH2_GPIO_Port = Options::PinToGPIO(PH2_Pin);
    inline auto PH3_GPIO_Port = Options::PinToGPIO(PH3_Pin);
    inline auto PH4_GPIO_Port = Options::PinToGPIO(PH4_Pin);
    inline auto PH5_GPIO_Port = Options::PinToGPIO(PH5_Pin);
    inline auto PH6_GPIO_Port = Options::PinToGPIO(PH6_Pin);
    inline auto PH7_GPIO_Port = Options::PinToGPIO(PH7_Pin);
    inline auto PH8_GPIO_Port = Options::PinToGPIO(PH8_Pin);
    inline auto PH9_GPIO_Port = Options::PinToGPIO(PH9_Pin);
    inline auto PH10_GPIO_Port = Options::PinToGPIO(PH10_Pin);
    inline auto PH11_GPIO_Port = Options::PinToGPIO(PH11_Pin);
    inline auto PH12_GPIO_Port = Options::PinToGPIO(PH12_Pin);
    inline auto PH13_GPIO_Port = Options::PinToGPIO(PH13_Pin);
    inline auto PH14_GPIO_Port = Options::PinToGPIO(PH14_Pin);
    inline auto PH15_GPIO_Port = Options::PinToGPIO(PH15_Pin);

    inline auto PJ0_GPIO_Port = Options::PinToGPIO(PJ0_Pin);
    inline auto PJ1_GPIO_Port = Options::PinToGPIO(PJ1_Pin);
    inline auto PJ2_GPIO_Port = Options::PinToGPIO(PJ2_Pin);
    inline auto PJ3_GPIO_Port = Options::PinToGPIO(PJ3_Pin);
    inline auto PJ4_GPIO_Port = Options::PinToGPIO(PJ4_Pin);
    inline auto PJ5_GPIO_Port = Options::PinToGPIO(PJ5_Pin);
    inline auto PJ6_GPIO_Port = Options::PinToGPIO(PJ6_Pin);
    inline auto PJ7_GPIO_Port = Options::PinToGPIO(PJ7_Pin);
    inline auto PJ8_GPIO_Port = Options::PinToGPIO(PJ8_Pin);
    inline auto PJ9_GPIO_Port = Options::PinToGPIO(PJ9_Pin);
    inline auto PJ10_GPIO_Port = Options::PinToGPIO(PJ10_Pin);
    inline auto PJ11_GPIO_Port = Options::PinToGPIO(PJ11_Pin);
    inline auto PJ12_GPIO_Port = Options::PinToGPIO(PJ12_Pin);
    inline auto PJ13_GPIO_Port = Options::PinToGPIO(PJ13_Pin);
    inline auto PJ14_GPIO_Port = Options::PinToGPIO(PJ14_Pin);
    inline auto PJ15_GPIO_Port = Options::PinToGPIO(PJ15_Pin);

    inline auto PK0_GPIO_Port = Options::PinToGPIO(PK0_Pin);
    inline auto PK1_GPIO_Port = Options::PinToGPIO(PK1_Pin);
    inline auto PK2_GPIO_Port = Options::PinToGPIO(PK2_Pin);
    inline auto PK3_GPIO_Port = Options::PinToGPIO(PK3_Pin);
    inline auto PK4_GPIO_Port = Options::PinToGPIO(PK4_Pin);
    inline auto PK5_GPIO_Port = Options::PinToGPIO(PK5_Pin);
    inline auto PK6_GPIO_Port = Options::PinToGPIO(PK6_Pin);
    inline auto PK7_GPIO_Port = Options::PinToGPIO(PK7_Pin);
    inline auto PK8_GPIO_Port = Options::PinToGPIO(PK8_Pin);
    inline auto PK9_GPIO_Port = Options::PinToGPIO(PK9_Pin);
    inline auto PK10_GPIO_Port = Options::PinToGPIO(PK10_Pin);
    inline auto PK11_GPIO_Port = Options::PinToGPIO(PK11_Pin);
    inline auto PK12_GPIO_Port = Options::PinToGPIO(PK12_Pin);
    inline auto PK13_GPIO_Port = Options::PinToGPIO(PK13_Pin);
    inline auto PK14_GPIO_Port = Options::PinToGPIO(PK14_Pin);
    inline auto PK15_GPIO_Port = Options::PinToGPIO(PK15_Pin);
    
    // Default Pins

    constexpr auto USER_Btn_Pin = PC13_Pin;
    constexpr auto LD1_Pin = PB0_Pin;
    constexpr auto LD2_Pin = PB7_Pin;
    constexpr auto LD3_Pin = PB14_Pin;

    inline auto USER_Btn_GPIO_Port = Options::PinToGPIO(USER_Btn_Pin);
    inline auto LD1_GPIO_Port = Options::PinToGPIO(LD1_Pin);
    inline auto LD2_GPIO_Port = Options::PinToGPIO(LD2_Pin);
    inline auto LD3_GPIO_Port = Options::PinToGPIO(LD3_Pin);

    // USB Pins

    constexpr auto USB_PowerSwitchOn_Pin = PG6_Pin;
    constexpr auto USB_OverCurrent_Pin = PG7_Pin;
    constexpr auto USB_SOF_Pin = PA8_Pin;
    constexpr auto USB_VBUS_Pin = PA9_Pin;
    constexpr auto USB_ID_Pin = PA10_Pin;
    constexpr auto USB_DM_Pin = PA11_Pin;
    constexpr auto USB_DP_Pin = PA12_Pin;

    inline auto USB_PowerSwitchOn_GPIO_Port = Options::PinToGPIO(USB_PowerSwitchOn_Pin);
    inline auto USB_OverCurrent_GPIO_Port = Options::PinToGPIO(USB_OverCurrent_Pin);
    inline auto USB_SOF_GPIO_Port = Options::PinToGPIO(USB_SOF_Pin);
    inline auto USB_VBUS_GPIO_Port = Options::PinToGPIO(USB_VBUS_Pin);
    inline auto USB_ID_GPIO_Port = Options::PinToGPIO(USB_ID_Pin);
    inline auto USB_DM_GPIO_Port = Options::PinToGPIO(USB_DM_Pin);
    inline auto USB_DP_GPIO_Port = Options::PinToGPIO(USB_DP_Pin);

    // System Pins

    constexpr auto RMII_MDC_Pin = PC1_Pin;
    constexpr auto RMII_REF_CLK_Pin = PA1_Pin;
    constexpr auto RMII_MDIO_Pin = PA2_Pin;
    constexpr auto RMII_CRS_DV_Pin = PA7_Pin;
    constexpr auto RMII_TX_EN_Pin = PG11_Pin;
    constexpr auto RMII_RXD0_Pin = PC4_Pin;
    constexpr auto RMII_RXD1_Pin = PC5_Pin;
    constexpr auto RMII_TXD0_Pin = PG13_Pin;
    constexpr auto RMII_TXD1_Pin = PB13_Pin;
    constexpr auto MCO_Pin = PH0_Pin;
    constexpr auto STLK_RX_Pin = PD8_Pin;
    constexpr auto STLK_TX_Pin = PD9_Pin;
    constexpr auto TMS_Pin = PA13_Pin;
    constexpr auto TCK_Pin = PA14_Pin;

    inline auto RMII_MDC_GPIO_Port = Options::PinToGPIO(PC1_Pin);
    inline auto RMII_REF_CLK_GPIO_Port = Options::PinToGPIO(PA1_Pin);
    inline auto RMII_MDIO_GPIO_Port = Options::PinToGPIO(PA2_Pin);
    inline auto RMII_CRS_DV_GPIO_Port = Options::PinToGPIO(PA7_Pin);
    inline auto RMII_TX_EN_GPIO_Port = Options::PinToGPIO(PG11_Pin);
    inline auto RMII_RXD0_GPIO_Port = Options::PinToGPIO(PC4_Pin);
    inline auto RMII_RXD1_GPIO_Port = Options::PinToGPIO(PC5_Pin);
    inline auto RMII_TXD0_GPIO_Port = Options::PinToGPIO(PG13_Pin);
    inline auto RMII_TXD1_GPIO_Port = Options::PinToGPIO(PB13_Pin);
    inline auto MCO_GPIO_Port = Options::PinToGPIO(PH0_Pin);
    inline auto STLK_RX_GPIO_Port = Options::PinToGPIO(PD8_Pin);
    inline auto STLK_TX_GPIO_Port = Options::PinToGPIO(PD9_Pin);
    inline auto TMS_GPIO_Port = Options::PinToGPIO(PA13_Pin);
    inline auto TCK_GPIO_Port = Options::PinToGPIO(PA14_Pin);
}