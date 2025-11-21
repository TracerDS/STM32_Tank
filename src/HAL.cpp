#include <HAL.hpp>

constexpr GPIO_TypeDef* PinToGPIO(std::uint16_t pin) noexcept {
    switch (pin) {
        case LD1_Pin:
            return LD1_GPIO_Port;
        case LD2_Pin:
            return LD2_GPIO_Port;
        case LD3_Pin:
            return LD3_GPIO_Port;
        case USER_Btn_Pin:
            return USER_Btn_GPIO_Port;
        default:
            return nullptr;
    }
}
constexpr bool IsUserBtnPin(std::uint16_t pin) noexcept {
    return pin == USER_Btn_Pin;
}

void HAL::TogglePin(std::uint16_t pin) noexcept {
    GPIO_TypeDef* port = PinToGPIO(pin);
    if (!port || IsUserBtnPin(pin))
        return;

    HAL_GPIO_TogglePin(port, pin);
}

void HAL::TogglePins(std::initializer_list<std::uint16_t> pins) noexcept {
    for (const auto& pin : pins) {
        TogglePin(pin);
    }
}

void HAL::WritePin(std::uint16_t pin, bool state) noexcept {
    GPIO_TypeDef* port = PinToGPIO(pin);
    if (!port || IsUserBtnPin(pin))
        return;

    HAL_GPIO_WritePin(
        port,
        pin,
        state ? GPIO_PinState::GPIO_PIN_SET : GPIO_PinState::GPIO_PIN_RESET
    );
}

void HAL::WritePins(std::initializer_list<std::uint16_t> pins, bool state) noexcept {
    for (const auto& pin : pins) {
        WritePin(pin, state);
    }
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