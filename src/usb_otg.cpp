#include <usb_otg.hpp>

PCD_HandleTypeDef hpcd_USB_OTG_FS;

/**
 * @brief USB_OTG_FS GPIO Configuration
 * 
 * PA8   ------> USB_OTG_FS_SOF
 * PA9   ------> USB_OTG_FS_VBUS
 * PA10  ------> USB_OTG_FS_ID
 * PA11  ------> USB_OTG_FS_DM
 * PA12  ------> USB_OTG_FS_DP
*/

void MX_USB_OTG_FS_PCD_Init() {
    hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
    hpcd_USB_OTG_FS.Init.dev_endpoints = 4;
    hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
    hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
    hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
    hpcd_USB_OTG_FS.Init.Sof_enable = ENABLE;
    hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
    hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
    hpcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;
    hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;

    if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK) {
        Error_Handler();
    }
}

void HAL_PCD_MspInit(PCD_HandleTypeDef* pcdHandle) {
    if (pcdHandle->Instance != USB_OTG_FS)
        return;

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct{};
    GPIO_InitStruct.Pin = Pins::USB_SOF_Pin | Pins::USB_ID_Pin
        | Pins::USB_DM_Pin | Pins::USB_DP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = Pins::USB_VBUS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(Pins::USB_VBUS_GPIO_Port, &GPIO_InitStruct);

    // USB_OTG_FS clock enable
    __HAL_RCC_USB_OTG_FS_CLK_ENABLE();
}

void HAL_PCD_MspDeInit(PCD_HandleTypeDef* pcdHandle) {
    if (pcdHandle->Instance != USB_OTG_FS)
        return;

    // Peripheral clock disable
    __HAL_RCC_USB_OTG_FS_CLK_DISABLE();

    HAL_GPIO_DeInit(
        GPIOA,
        Pins::USB_SOF_Pin | Pins::USB_VBUS_Pin | Pins::USB_ID_Pin |
            Pins::USB_DM_Pin | Pins::USB_DP_Pin
    );
}