#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#   include <stm32f4xx_hal.h>

#ifdef __cplusplus
}
#endif

void Error_Handler();

namespace Pins {
    // User Pins
    
    constexpr auto PA6_Pin = GPIO_PIN_6;
    constexpr auto PB4_Pin = GPIO_PIN_4;
    constexpr auto PB5_Pin = GPIO_PIN_5;
    constexpr auto PB6_Pin = GPIO_PIN_6;
    constexpr auto PD3_Pin = GPIO_PIN_3;
    constexpr auto PE9_Pin = GPIO_PIN_9;
    constexpr auto PE11_Pin = GPIO_PIN_11;
    constexpr auto PE13_Pin = GPIO_PIN_13;
    constexpr auto PF14_Pin = GPIO_PIN_14;
    constexpr auto PF15_Pin = GPIO_PIN_15;
    
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

    constexpr auto USER_Btn_Pin = GPIO_PIN_13;
    constexpr auto LD1_Pin = GPIO_PIN_0;
    constexpr auto LD2_Pin = GPIO_PIN_7;
    constexpr auto LD3_Pin = GPIO_PIN_14;

    inline auto USER_Btn_GPIO_Port = GPIOC;
    inline auto LD1_GPIO_Port = GPIOB;
    inline auto LD2_GPIO_Port = GPIOB;
    inline auto LD3_GPIO_Port = GPIOB;

    // USB Pins

    constexpr auto USB_PowerSwitchOn_Pin = GPIO_PIN_6;
    constexpr auto USB_OverCurrent_Pin = GPIO_PIN_7;
    constexpr auto USB_SOF_Pin = GPIO_PIN_8;
    constexpr auto USB_VBUS_Pin = GPIO_PIN_9;
    constexpr auto USB_ID_Pin = GPIO_PIN_10;
    constexpr auto USB_DM_Pin = GPIO_PIN_11;
    constexpr auto USB_DP_Pin = GPIO_PIN_12;

    inline auto USB_PowerSwitchOn_GPIO_Port = GPIOG;
    inline auto USB_OverCurrent_GPIO_Port = GPIOG;
    inline auto USB_SOF_GPIO_Port = GPIOA;
    inline auto USB_VBUS_GPIO_Port = GPIOA;
    inline auto USB_ID_GPIO_Port = GPIOA;
    inline auto USB_DM_GPIO_Port = GPIOA;
    inline auto USB_DP_GPIO_Port = GPIOA;

    // System Pins

    constexpr auto RMII_MDC_Pin = GPIO_PIN_1;
    constexpr auto RMII_REF_CLK_Pin = GPIO_PIN_1;
    constexpr auto RMII_MDIO_Pin = GPIO_PIN_2;
    constexpr auto RMII_CRS_DV_Pin = GPIO_PIN_7;
    constexpr auto RMII_TX_EN_Pin = GPIO_PIN_11;
    constexpr auto RMII_RXD0_Pin = GPIO_PIN_4;
    constexpr auto RMII_RXD1_Pin = GPIO_PIN_5;
    constexpr auto RMII_TXD0_Pin = GPIO_PIN_13;
    constexpr auto RMII_TXD1_Pin = GPIO_PIN_13;
    constexpr auto MCO_Pin = GPIO_PIN_0;
    constexpr auto STLK_RX_Pin = GPIO_PIN_8;
    constexpr auto STLK_TX_Pin = GPIO_PIN_9;
    constexpr auto TMS_Pin = GPIO_PIN_13;
    constexpr auto TCK_Pin = GPIO_PIN_14;

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