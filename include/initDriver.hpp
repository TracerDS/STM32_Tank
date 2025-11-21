#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void SystemClock_Config();
void MX_ETH_Init();
void MX_USART3_UART_Init();
void MX_USB_OTG_FS_PCD_Init();
void MX_GPIO_Init();

#ifdef __cplusplus
}
#endif