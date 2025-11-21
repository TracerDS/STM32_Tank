#include <HAL.hpp>

void HAL::TogglePin(std::uint16_t pin) noexcept {
    GPIO_TypeDef* port = nullptr;
    switch (pin) {
        case LD1_Pin:
            port = LD1_GPIO_Port;
            break;
        case LD2_Pin:
            port = LD2_GPIO_Port;
            break;
        case LD3_Pin:
            port = LD3_GPIO_Port;
            break;
        default:
            return;
    }
    HAL_GPIO_TogglePin(port, pin);
}