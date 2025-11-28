#include <main.hpp>

void HAL_MspInit() {
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();

    // System interrupt init
}