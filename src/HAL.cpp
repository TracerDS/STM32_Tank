#include <hal.hpp>
#include <main.hpp>

#include <stm32f4xx_hal.h>

#include <map>

namespace HAL {
    GPIO_TypeDef* PinToGPIO(std::uint16_t pin) noexcept {
        static const std::map<std::uint16_t, GPIO_TypeDef*> pinToGPIOMap = {
            { Pins::PA6_Pin, Pins::PA6_GPIO_Port },
            { Pins::PB4_Pin, Pins::PB4_GPIO_Port },
            { Pins::PB5_Pin, Pins::PB5_GPIO_Port },
            { Pins::PB6_Pin, Pins::PB6_GPIO_Port },
            { Pins::PD3_Pin, Pins::PD3_GPIO_Port },
            { Pins::PE9_Pin, Pins::PE9_GPIO_Port },
            { Pins::PE11_Pin, Pins::PE11_GPIO_Port },
            { Pins::PE13_Pin, Pins::PE13_GPIO_Port },
            { Pins::PF14_Pin, Pins::PF14_GPIO_Port },
            { Pins::PF15_Pin, Pins::PF15_GPIO_Port },
            { Pins::USER_Btn_Pin, Pins::USER_Btn_GPIO_Port },
            { Pins::LD1_Pin, Pins::LD1_GPIO_Port },
            { Pins::LD2_Pin, Pins::LD2_GPIO_Port },
            { Pins::LD3_Pin, Pins::LD3_GPIO_Port },
            { Pins::USB_PowerSwitchOn_Pin, Pins::USB_PowerSwitchOn_GPIO_Port },
            { Pins::USB_OverCurrent_Pin, Pins::USB_OverCurrent_GPIO_Port },
            { Pins::USB_SOF_Pin, Pins::USB_SOF_GPIO_Port },
            { Pins::USB_VBUS_Pin, Pins::USB_VBUS_GPIO_Port },
            { Pins::USB_ID_Pin, Pins::USB_ID_GPIO_Port },
            { Pins::USB_DM_Pin, Pins::USB_DM_GPIO_Port },
            { Pins::USB_DP_Pin, Pins::USB_DP_GPIO_Port },
            { Pins::RMII_MDC_Pin, Pins::RMII_MDC_GPIO_Port },
            { Pins::RMII_REF_CLK_Pin, Pins::RMII_REF_CLK_GPIO_Port },
            { Pins::RMII_MDIO_Pin, Pins::RMII_MDIO_GPIO_Port },
            { Pins::RMII_CRS_DV_Pin, Pins::RMII_CRS_DV_GPIO_Port },
            { Pins::RMII_TX_EN_Pin, Pins::RMII_TX_EN_GPIO_Port },
            { Pins::RMII_RXD0_Pin, Pins::RMII_RXD0_GPIO_Port },
            { Pins::RMII_RXD1_Pin, Pins::RMII_RXD1_GPIO_Port },
            { Pins::RMII_TXD0_Pin, Pins::RMII_TXD0_GPIO_Port },
            { Pins::RMII_TXD1_Pin, Pins::RMII_TXD1_GPIO_Port },
            { Pins::MCO_Pin, Pins::MCO_GPIO_Port },
            { Pins::STLK_RX_Pin, Pins::STLK_RX_GPIO_Port },
            { Pins::STLK_TX_Pin, Pins::STLK_TX_GPIO_Port },
            { Pins::TMS_Pin, Pins::TMS_GPIO_Port },
            { Pins::TCK_Pin, Pins::TCK_GPIO_Port },
        };
        if (pinToGPIOMap.find(pin) != pinToGPIOMap.end()) {
            return pinToGPIOMap.at(pin);
        }
        return nullptr;
    }
    
    void HAL::TogglePin(std::uint16_t pin) noexcept {
        GPIO_TypeDef* port = PinToGPIO(pin);
        if (!port)
            return;

        HAL_GPIO_TogglePin(port, pin);
    }

    void HAL::WritePin(std::uint16_t pin, bool state) noexcept {
        GPIO_TypeDef* port = PinToGPIO(pin);
        if (!port)
            return;

        HAL_GPIO_WritePin(
            port,
            pin,
            state ? GPIO_PinState::GPIO_PIN_SET : GPIO_PinState::GPIO_PIN_RESET
        );
    }

    bool HAL::ReadPin(std::uint16_t pin) noexcept {
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