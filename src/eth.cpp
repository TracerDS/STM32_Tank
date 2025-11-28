#include <eth.hpp>
#include <cstring>

ETH_DMADescTypeDef  DMARxDscrTab[ETH_RX_DESC_CNT]; /* Ethernet Rx DMA Descriptors */
ETH_DMADescTypeDef  DMATxDscrTab[ETH_TX_DESC_CNT]; /* Ethernet Tx DMA Descriptors */

ETH_TxPacketConfig TxConfig{};
ETH_HandleTypeDef heth;

/**
 * @brief ETH GPIO Configuration
 * 
 * PC1   ------> ETH_MDC
 * PA1   ------> ETH_REF_CLK
 * PA2   ------> ETH_MDIO
 * PA7   ------> ETH_CRS_DV
 * PC4   ------> ETH_RXD0
 * PC5   ------> ETH_RXD1
 * PB13  ------> ETH_TXD1
 * PG11  ------> ETH_TX_EN
 * PG13  ------> ETH_TXD0
*/

void MX_ETH_Init() {
    static uint8_t MACAddr[6];

    heth.Instance = ETH;
    MACAddr[0] = 0x00;
    MACAddr[1] = 0x80;
    MACAddr[2] = 0xE1;
    MACAddr[3] = 0x00;
    MACAddr[4] = 0x00;
    MACAddr[5] = 0x00;
    heth.Init.MACAddr = &MACAddr[0];
    heth.Init.MediaInterface = HAL_ETH_RMII_MODE;
    heth.Init.TxDesc = DMATxDscrTab;
    heth.Init.RxDesc = DMARxDscrTab;
    heth.Init.RxBuffLen = 1524;

    if (HAL_ETH_Init(&heth) != HAL_OK) {
        Error_Handler();
    }

    TxConfig.Attributes = ETH_TX_PACKETS_FEATURES_CSUM | ETH_TX_PACKETS_FEATURES_CRCPAD;
    TxConfig.ChecksumCtrl = ETH_CHECKSUM_IPHDR_PAYLOAD_INSERT_PHDR_CALC;
    TxConfig.CRCPadCtrl = ETH_CRC_PAD_INSERT;
}

void HAL_ETH_MspInit(ETH_HandleTypeDef* ethHandle) {
    if (ethHandle->Instance != ETH)
        return;
    
    // ETH clock enable
    __HAL_RCC_ETH_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct{};
    GPIO_InitStruct.Pin = Pins::RMII_MDC_Pin | Pins::RMII_RXD0_Pin | Pins::RMII_RXD1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::RMII_REF_CLK_Pin | Pins::RMII_MDIO_Pin | Pins::RMII_CRS_DV_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::RMII_TXD1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(Pins::RMII_TXD1_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::RMII_TX_EN_Pin | Pins::RMII_TXD0_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
}

void HAL_ETH_MspDeInit(ETH_HandleTypeDef* ethHandle) {
    if (ethHandle->Instance != ETH)
        return;

    // Peripheral clock disable
    __HAL_RCC_ETH_CLK_DISABLE();

    HAL_GPIO_DeInit(GPIOC, Pins::RMII_MDC_Pin | Pins::RMII_RXD0_Pin | Pins::RMII_RXD1_Pin);
    HAL_GPIO_DeInit(GPIOA, Pins::RMII_REF_CLK_Pin | Pins::RMII_MDIO_Pin | Pins::RMII_CRS_DV_Pin);
    HAL_GPIO_DeInit(Pins::RMII_TXD1_GPIO_Port, Pins::RMII_TXD1_Pin);
    HAL_GPIO_DeInit(GPIOG, Pins::RMII_TX_EN_Pin | Pins::RMII_TXD0_Pin);
}