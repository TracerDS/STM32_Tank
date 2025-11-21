#include "stm32f4xx_hal.h"
#include <main.hpp>
#include <initDriver.hpp>
#include <HAL.hpp>

#include <cstdio>
#include <cstdint>
#include <functional>
#include <list>
#include <thread>

std::list<std::function<void()>> taskQueue;

int main()
{
    // Reset of all peripherals, Initializes the Flash interface and the Systick.
    HAL_Init();

    // Configure the system clock
    SystemClock_Config();

    // Initialize all configured peripherals
    MX_GPIO_Init();
    MX_ETH_Init();
    MX_USART3_UART_Init();
    MX_USB_OTG_FS_PCD_Init();

    HAL::WritePins({LD1_Pin, LD2_Pin, LD3_Pin}, true);

    static bool initialized = false;

    auto it = taskQueue.emplace(taskQueue.end());
    *it = [it](){
        if (!HAL::ReadPin(USER_Btn_Pin)) {
            return;
        }
        if (initialized)
            return;
        initialized = true;

        HAL::TogglePins({LD1_Pin, LD2_Pin, LD3_Pin});

        taskQueue.erase(it);
    };

    uint32_t timeBetweenBlinks = 500;
    uint32_t current = HAL::GetTick();

    enum class Mode {
        LED1 = 0,
        LED2 = 1,
        LED3 = 2,
    } mode = Mode::LED1;

    const auto ModeToPin = [](Mode m) {
        switch (m) {
            default:
            case Mode::LED1: return LD1_Pin;
            case Mode::LED2: return LD2_Pin;
            case Mode::LED3: return LD3_Pin;
        }
    };

    bool pressed = false;

    while (true)
    {
        for (const auto& task : taskQueue) {
            task();
        }
        if (!initialized)
            continue;

        if (HAL::ReadPin(USER_Btn_Pin) && !pressed) {
            pressed = true;
        } else {
            pressed = false;
        }

        if (HAL::GetTick() - current >= timeBetweenBlinks) {
            if (mode == Mode::LED1) {
                HAL::WritePins({LD2_Pin, LD3_Pin}, false);
            } else if (mode == Mode::LED2) {
                HAL::WritePins({LD1_Pin, LD3_Pin}, false);
            } else if (mode == Mode::LED3) {
                HAL::WritePins({LD1_Pin, LD2_Pin}, false);
            }
            HAL::TogglePin(ModeToPin(mode));
            current = HAL::GetTick();
        }

        if (pressed) {
            mode = static_cast<Mode>((static_cast<int>(mode) + 1) % 3);
        }
    }
}