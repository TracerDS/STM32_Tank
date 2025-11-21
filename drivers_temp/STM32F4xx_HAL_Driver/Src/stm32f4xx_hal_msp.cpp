#include "main.hpp"

/**
  * Initializes the Global MSP.
  */
void HAL_MspInit()
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
  * @brief ETH MSP Initialization
  * This function configures the hardware resources used in this example
  * @param heth: ETH handle pointer
  * @retval None
  */
void HAL_ETH_MspInit(ETH_HandleTypeDef* heth)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (heth->Instance != ETH)
        return;
    
    // Peripheral clock enable
    __HAL_RCC_ETH_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    // ETH GPIO Configuration
    // PC1   ------> ETH_MDC
    // PA1   ------> ETH_REF_CLK
    // PA2   ------> ETH_MDIO
    // PA7   ------> ETH_CRS_DV
    // PC4   ------> ETH_RXD0
    // PC5   ------> ETH_RXD1
    // PB13  ------> ETH_TXD1
    // PG11  ------> ETH_TX_EN
    // PG13  ------> ETH_TXD0
    
    GPIO_InitStruct.Pin = RMII_MDC_Pin|RMII_RXD0_Pin|RMII_RXD1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = RMII_REF_CLK_Pin|RMII_MDIO_Pin|RMII_CRS_DV_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = RMII_TXD1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(RMII_TXD1_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = RMII_TX_EN_Pin|RMII_TXD0_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
}

/**
  * @brief ETH MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param heth: ETH handle pointer
  * @retval None
  */
void HAL_ETH_MspDeInit(ETH_HandleTypeDef* heth)
{
    if (heth->Instance != ETH)
        return;

    // Peripheral clock disable
    __HAL_RCC_ETH_CLK_DISABLE();

    // ETH GPIO Configuration
    // PC1   ------> ETH_MDC
    // PA1   ------> ETH_REF_CLK
    // PA2   ------> ETH_MDIO
    // PA7   ------> ETH_CRS_DV
    // PC4   ------> ETH_RXD0
    // PC5   ------> ETH_RXD1
    // PB13  ------> ETH_TXD1
    // PG11  ------> ETH_TX_EN
    // PG13  ------> ETH_TXD0
    
    HAL_GPIO_DeInit(GPIOC, RMII_MDC_Pin|RMII_RXD0_Pin|RMII_RXD1_Pin);
    HAL_GPIO_DeInit(GPIOA, RMII_REF_CLK_Pin|RMII_MDIO_Pin|RMII_CRS_DV_Pin);
    HAL_GPIO_DeInit(RMII_TXD1_GPIO_Port, RMII_TXD1_Pin);
    HAL_GPIO_DeInit(GPIOG, RMII_TX_EN_Pin|RMII_TXD0_Pin);
}

/**
  * @brief UART MSP Initialization
  * This function configures the hardware resources used in this example
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (huart->Instance != USART3)
        return;

    // Peripheral clock enable
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    // USART3 GPIO Configuration
    // PD8  ------> USART3_TX
    // PD9  ------> USART3_RX
    
    GPIO_InitStruct.Pin = STLK_RX_Pin|STLK_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

/**
  * @brief UART MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
    if (huart->Instance != USART3)
        return;

    // Peripheral clock disable
    __HAL_RCC_USART3_CLK_DISABLE();

    // USART3 GPIO Configuration
    // PD8  ------> USART3_TX
    // PD9  ------> USART3_RX
    HAL_GPIO_DeInit(GPIOD, STLK_RX_Pin|STLK_TX_Pin);
}

/**
  * @brief PCD MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hpcd: PCD handle pointer
  * @retval None
  */
void HAL_PCD_MspInit(PCD_HandleTypeDef* hpcd)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (hpcd->Instance != USB_OTG_FS)
        return;

    __HAL_RCC_GPIOA_CLK_ENABLE();
    // USB_OTG_FS GPIO Configuration
    // PA8   ------> USB_OTG_FS_SOF
    // PA9   ------> USB_OTG_FS_VBUS
    // PA10  ------> USB_OTG_FS_ID
    // PA11  ------> USB_OTG_FS_DM
    // PA12  ------> USB_OTG_FS_DP
    
    GPIO_InitStruct.Pin = USB_SOF_Pin|USB_ID_Pin|USB_DM_Pin|USB_DP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = USB_VBUS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(USB_VBUS_GPIO_Port, &GPIO_InitStruct);

    // Peripheral clock enable
    __HAL_RCC_USB_OTG_FS_CLK_ENABLE();
}

/**
  * @brief PCD MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hpcd: PCD handle pointer
  * @retval None
  */
void HAL_PCD_MspDeInit(PCD_HandleTypeDef* hpcd)
{
    if (hpcd->Instance != USB_OTG_FS)
        return;
    // Peripheral clock disable
    __HAL_RCC_USB_OTG_FS_CLK_DISABLE();

    // USB_OTG_FS GPIO Configuration
    // PA8   ------> USB_OTG_FS_SOF
    // PA9   ------> USB_OTG_FS_VBUS
    // PA10  ------> USB_OTG_FS_ID
    // PA11  ------> USB_OTG_FS_DM
    // PA12  ------> USB_OTG_FS_DP
    
    HAL_GPIO_DeInit(GPIOA, USB_SOF_Pin|USB_VBUS_Pin|USB_ID_Pin|USB_DM_Pin|USB_DP_Pin);
}