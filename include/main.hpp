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
    }

    // User Pins

    constexpr std::uint32_t PA6_Pin  = GPIO_PIN_6  | Options::PortA;
    constexpr std::uint32_t PB4_Pin  = GPIO_PIN_4  | Options::PortB;
    constexpr std::uint32_t PB5_Pin  = GPIO_PIN_5  | Options::PortB;
    constexpr std::uint32_t PB6_Pin  = GPIO_PIN_6  | Options::PortB;
    constexpr std::uint32_t PD3_Pin  = GPIO_PIN_3  | Options::PortD;
    constexpr std::uint32_t PE9_Pin  = GPIO_PIN_9  | Options::PortE;
    constexpr std::uint32_t PE11_Pin = GPIO_PIN_11 | Options::PortE;
    constexpr std::uint32_t PE13_Pin = GPIO_PIN_13 | Options::PortE;
    constexpr std::uint32_t PF14_Pin = GPIO_PIN_14 | Options::PortF;
    constexpr std::uint32_t PF15_Pin = GPIO_PIN_15 | Options::PortF;
    
    inline auto PA6_GPIO_Port = GPIOA;
    inline auto PB4_GPIO_Port = GPIOB;
    inline auto PB5_GPIO_Port = GPIOB;
    inline auto PB6_GPIO_Port = GPIOB;
    inline auto PD3_GPIO_Port = GPIOD;
    inline auto PE9_GPIO_Port = GPIOE;
    inline auto PE11_GPIO_Port = GPIOE;
    inline auto PE13_GPIO_Port = GPIOE;
    inline auto PF14_GPIO_Port = GPIOF;
    inline auto PF15_GPIO_Port = GPIOF;
    
    // Default Pins

    constexpr auto USER_Btn_Pin = GPIO_PIN_13 | Options::PortC;
    constexpr auto LD1_Pin = GPIO_PIN_0 | Options::PortB;
    constexpr auto LD2_Pin = GPIO_PIN_7 | Options::PortB;
    constexpr auto LD3_Pin = GPIO_PIN_14 | Options::PortB;

    inline auto USER_Btn_GPIO_Port = GPIOC;
    inline auto LD1_GPIO_Port = GPIOB;
    inline auto LD2_GPIO_Port = GPIOB;
    inline auto LD3_GPIO_Port = GPIOB;

    // USB Pins

    constexpr auto USB_PowerSwitchOn_Pin = GPIO_PIN_6 | Options::PortG;
    constexpr auto USB_OverCurrent_Pin = GPIO_PIN_7 | Options::PortG;
    constexpr auto USB_SOF_Pin = GPIO_PIN_8 | Options::PortA;
    constexpr auto USB_VBUS_Pin = GPIO_PIN_9 | Options::PortA;
    constexpr auto USB_ID_Pin = GPIO_PIN_10 | Options::PortA;
    constexpr auto USB_DM_Pin = GPIO_PIN_11 | Options::PortA;
    constexpr auto USB_DP_Pin = GPIO_PIN_12 | Options::PortA;

    inline auto USB_PowerSwitchOn_GPIO_Port = GPIOG;
    inline auto USB_OverCurrent_GPIO_Port = GPIOG;
    inline auto USB_SOF_GPIO_Port = GPIOA;
    inline auto USB_VBUS_GPIO_Port = GPIOA;
    inline auto USB_ID_GPIO_Port = GPIOA;
    inline auto USB_DM_GPIO_Port = GPIOA;
    inline auto USB_DP_GPIO_Port = GPIOA;

    // System Pins

    constexpr auto RMII_MDC_Pin = GPIO_PIN_1 | Options::PortC;
    constexpr auto RMII_REF_CLK_Pin = GPIO_PIN_1 | Options::PortA;
    constexpr auto RMII_MDIO_Pin = GPIO_PIN_2 | Options::PortA;
    constexpr auto RMII_CRS_DV_Pin = GPIO_PIN_7 | Options::PortA;
    constexpr auto RMII_TX_EN_Pin = GPIO_PIN_11 | Options::PortG;
    constexpr auto RMII_RXD0_Pin = GPIO_PIN_4 | Options::PortC;
    constexpr auto RMII_RXD1_Pin = GPIO_PIN_5 | Options::PortC;
    constexpr auto RMII_TXD0_Pin = GPIO_PIN_13 | Options::PortG;
    constexpr auto RMII_TXD1_Pin = GPIO_PIN_13 | Options::PortB;
    constexpr auto MCO_Pin = GPIO_PIN_0 | Options::PortH;
    constexpr auto STLK_RX_Pin = GPIO_PIN_8 | Options::PortD;
    constexpr auto STLK_TX_Pin = GPIO_PIN_9 | Options::PortD;
    constexpr auto TMS_Pin = GPIO_PIN_13 | Options::PortA;
    constexpr auto TCK_Pin = GPIO_PIN_14 | Options::PortA;

    inline auto RMII_MDC_GPIO_Port = GPIOC;
    inline auto RMII_REF_CLK_GPIO_Port = GPIOA;
    inline auto RMII_MDIO_GPIO_Port = GPIOA;
    inline auto RMII_CRS_DV_GPIO_Port = GPIOA;
    inline auto RMII_TX_EN_GPIO_Port = GPIOG;
    inline auto RMII_RXD0_GPIO_Port = GPIOC;
    inline auto RMII_RXD1_GPIO_Port = GPIOC;
    inline auto RMII_TXD0_GPIO_Port = GPIOG;
    inline auto RMII_TXD1_GPIO_Port = GPIOB;
    inline auto MCO_GPIO_Port = GPIOH;
    inline auto STLK_RX_GPIO_Port = GPIOD;
    inline auto STLK_TX_GPIO_Port = GPIOD;
    inline auto TMS_GPIO_Port = GPIOA;
    inline auto TCK_GPIO_Port = GPIOA;
}