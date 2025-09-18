#pragma once
#include <crt_CleanRTOS.h>
#include "Button.h"

// crt::KlikAanKlikUit
// by Hagen Patzke, 2025

namespace crt
{

// class PwmLed {
// public:
//     PwmLed(gpio_num_t pin, ledc_channel_t channel, ledc_timer_t timer)
//         : m_pin(pin), m_channel(channel), m_timer(timer), m_maxDuty(8191) {
//         init();
//     }

//     void setDuty(uint8_t percent) {
//         if (percent > 100) percent = 100;
//         uint32_t duty = ((100-percent) * m_maxDuty) / 100;
//         ledc_set_duty(LEDC_HIGH_SPEED_MODE, m_channel, duty);
//         ledc_update_duty(LEDC_HIGH_SPEED_MODE, m_channel);
//     }
// }

	class ButtonTask : public Task{
		enum class State {GreenLed, OrangeLed, RedLed, OrangeBlink, RedBlink};
		
		private:
            const uint8_t PIN_BTN;
            const uint8_t PIN_BTN22;
            const uint8_t PIN_RLED;
            const uint8_t PIN_GLED;
			State state = State::GreenLed;
			crt::Button *btnKlik;
			int blinks = 0;

		public:

			ButtonTask(const char *taskName, unsigned int taskPriority, unsigned int taskCoreNumber, uint8_t pinBtn, uint8_t pinBtn22, const uint8_t pinRled, uint8_t pinGled, crt::Button *btnKlik)
				: Task(taskName, taskPriority, 3000, taskCoreNumber), PIN_BTN(pinBtn), PIN_BTN22(pinBtn22), PIN_RLED(pinRled), PIN_GLED(pinGled), btnKlik(btnKlik)

			{
				// set up the LED pin
				esp_rom_gpio_pad_select_gpio(PIN_RLED);
				gpio_reset_pin((gpio_num_t)PIN_RLED);
				gpio_set_direction((gpio_num_t)PIN_RLED, GPIO_MODE_OUTPUT);
				gpio_set_level((gpio_num_t)PIN_RLED, 0);

                esp_rom_gpio_pad_select_gpio(PIN_GLED);
				gpio_reset_pin((gpio_num_t)PIN_GLED);
				gpio_set_direction((gpio_num_t)PIN_GLED, GPIO_MODE_OUTPUT);
				gpio_set_level((gpio_num_t)PIN_GLED, 0);
				// our constructor also starts our task
				ESP_LOGI("KlikAanKlikUit", "start task");
				start();
			}

		private:
			void main()
			{
				// Built-In Self Test: flash LED three times
				for (int i = 1; i < 10; i++)
				{
					vTaskDelay(100);
					gpio_set_level((gpio_num_t)PIN_RLED, (i & 1));
				}

				// main function
				while (true)
				{
					switch(state){
						case State::GreenLed:{
                            ESP_LOGI("KlikAanKlikUit", "Green led on");
							gpio_set_level((gpio_num_t)PIN_GLED, 0);
							if (btnKlik->isPressed()) {
								ESP_LOGI("KlikAanKlikUit", "button pressed Orange led on");
								state = State::OrangeLed;
							}
                            vTaskDelay(100);
							break;
							}

						case State::OrangeLed:{
                            gpio_set_level((gpio_num_t)PIN_RLED, 0);
							vTaskDelay(3000);
							ESP_LOGI("KlikAanKlikUit", "Red led on");
							state = State::RedLed;
							break;
							}

                            case State::RedLed:{
                            gpio_set_level((gpio_num_t)PIN_GLED, 1);
							if (btnKlik->isPressed()) {
								ESP_LOGI("KlikAanKlikUit", "button pressed Orange and Red blinks on");
								state = State::OrangeBlink;
							}
                            vTaskDelay(100);
							break;
							}

                            case State::OrangeBlink:{
							gpio_set_level((gpio_num_t)PIN_GLED, 0);
							ESP_LOGI("KlikAanKlikUit", "Red led on");
							state = State::RedBlink;
                            blinks++;
							vTaskDelay(500);
							}
							break;

                            case State::RedBlink:{
							gpio_set_level((gpio_num_t)PIN_GLED, 1);
							ESP_LOGI("KlikAanKlikUit", "button pressed blue led on");
							state = State::OrangeBlink;
							vTaskDelay(500);
							}
							break;
						}
				}
				vTaskDelay(200);
		}
	}; // end class KlikAanKlikUit
}; // end namespace CleanRTOS