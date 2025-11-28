#include <usart.hpp>
#include <main.hpp>

UART_HandleTypeDef huart3;

/**
 * @brief USART3 GPIO Configuration
 * PD8     ------> USART3_TX
 * PD9     ------> USART3_RX
*/

void MX_USART3_UART_Init() {
    huart3.Instance = USART3;
    huart3.Init.BaudRate = 115200;
    huart3.Init.WordLength = UART_WORDLENGTH_8B;
    huart3.Init.StopBits = UART_STOPBITS_1;
    huart3.Init.Parity = UART_PARITY_NONE;
    huart3.Init.Mode = UART_MODE_TX_RX;
    huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart3.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart3) != HAL_OK) {
        Error_Handler();
    }
}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{
    if (uartHandle->Instance != USART3)
        return;
    
    // USART3 clock enable
    __HAL_RCC_USART3_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    
    GPIO_InitTypeDef GPIO_InitStruct{};    
    GPIO_InitStruct.Pin = Pins::STLK_RX_Pin | Pins::STLK_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle) {
    if (uartHandle->Instance != USART3)
        return;

    // Peripheral clock disable
    __HAL_RCC_USART3_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOD, Pins::STLK_RX_Pin | Pins::STLK_TX_Pin);
}