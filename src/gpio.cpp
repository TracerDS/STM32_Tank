#include <gpio.hpp>
#include <main.hpp>

void MX_GPIO_Init() {
    GPIO_InitTypeDef GPIO_InitStruct{};

    // GPIO Ports Clock Enable
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();

    HAL_GPIO_WritePin(Pins::PA6_GPIO_Port, Pins::PA6_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(
        GPIOB,
        Pins::LD1_Pin | Pins::LD3_Pin | Pins::PB4_Pin | Pins::PB5_Pin | Pins::PB6_Pin | Pins::LD2_Pin,
        GPIO_PIN_RESET
    );
    HAL_GPIO_WritePin(GPIOF, Pins::PF14_Pin | Pins::PF15_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOE, Pins::PE9_Pin | Pins::PE11_Pin | Pins::PE13_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Pins::USB_PowerSwitchOn_GPIO_Port, Pins::USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Pins::PD3_GPIO_Port, Pins::PD3_Pin, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin = Pins::USER_Btn_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(Pins::USER_Btn_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::PA6_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(Pins::PA6_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::LD1_Pin | Pins::LD3_Pin | Pins::PB4_Pin
        | Pins::PB5_Pin | Pins::PB6_Pin | Pins::LD2_Pin;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::PF14_Pin | Pins::PF15_Pin;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::PE9_Pin | Pins::PE11_Pin | Pins::PE13_Pin;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::PD3_Pin;
    HAL_GPIO_Init(Pins::PD3_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::USB_PowerSwitchOn_Pin;
    HAL_GPIO_Init(Pins::USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::USB_OverCurrent_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(Pins::USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);
}