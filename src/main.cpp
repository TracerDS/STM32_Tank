#include <main.hpp>
#include <ethernet.hpp>
#include <usart.hpp>
#include <usb_otg.hpp>
#include <gpio.hpp>
#include <sysclock.hpp>
#include <hal.hpp>
#include <lcd.hpp>

using namespace STM32;

int main() {
    // Reset of all peripherals, Initializes the Flash interface and the Systick.
    HAL::Init();
    
    // Configure the system clock
    SysClock::Init();

    // Initialize all configured peripherals
    GPIO::Init();
    Ethernet::Init();
    USART::Init();
    USB_OTG::Init();
    LCD::Init();

    LCD::Clear();
    LCD::Print("Abc");

    while (true) {
        HAL::TogglePin(Pins::LD1_Pin);
        HAL::Delay(500);
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler()
{
    // User can add his own implementation to report the HAL error return state
    __disable_irq();
    while (true)
    {
    }
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(std::uint8_t* file, uint32_t line)
{
  // User can add his own implementation to report the file name and line number,
  // ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line)
}
#endif
