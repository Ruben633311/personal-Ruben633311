#pragma once
#include <crt_CleanRTOS.h>
#include "Button.h"
#include "PwmLed.hpp"

namespace crt
{

	class TrafficLight : public Task{
		enum class State {GreenLed, OrangeLed, RedLed, OrangeBlink, RedBlink};

		static constexpr const char *TAG = "TrafficLight";
		
		private:
			PwmLed greenLed;
    		PwmLed redLed; 
            const uint8_t PIN_RLED;
            const uint8_t PIN_GLED;
			State state = State::GreenLed;
			crt::Button *btnKlik1;
			crt::Button *btnKlik2;
			int blinks = 0;

		public:

			TrafficLight (const char *taskName, unsigned int taskPriority, unsigned int taskCoreNumber, const uint8_t pinRled, uint8_t pinGled, crt::Button *btn1,
           		crt::Button *btn2)
				: Task(taskName, taskPriority, 3000, taskCoreNumber), greenLed(static_cast<gpio_num_t>(pinGled), LEDC_CHANNEL_0, LEDC_TIMER_0),
				redLed(static_cast<gpio_num_t>(pinRled), LEDC_CHANNEL_1, LEDC_TIMER_0), PIN_RLED(pinRled), PIN_GLED(pinGled), btnKlik1(btn1), btnKlik2(btn2)
				
				{

				ESP_LOGI(TAG, "start task");
				start();
			}

		private:
			void main()
			{
				state = State::GreenLed;

				while (true)
				{
					switch(state){
						case State::GreenLed:{
                            ESP_LOGI(TAG, "Green led on");
							greenLed.setDuty(10); 
							redLed.setDuty(0); 
							vTaskDelay(100);
							if (btnKlik1->isPressed()) {
								ESP_LOGI(TAG, "button pressed Orange led on");
								state = State::OrangeLed;
							}
							break;
							}

						case State::OrangeLed:{
							greenLed.setDuty(6); 
							redLed.setDuty(100);
							vTaskDelay(400);
							greenLed.setDuty(0);
							ESP_LOGI(TAG, "Red led on");
							state = State::RedLed;
							break;
							}

                        case State::RedLed:{
							// redLed.setDuty(100);
							vTaskDelay(100);
							if (btnKlik2->isPressed()) {
								ESP_LOGI(TAG, "button pressed Orange and Red blinks on");
								state = State::OrangeBlink;
							}
							break;
							}

                        case State::OrangeBlink:{
							// gpio_set_level((gpio_num_t)PIN_GLED, 0);
							greenLed.setDuty(6); 
							ESP_LOGI(TAG, "orange blink on");
							state = State::RedBlink;
							blinks++;
							vTaskDelay(50);
							}
							break;

                        case State::RedBlink:{
							greenLed.setDuty(0); 
							redLed.setDuty(100);
							// gpio_set_level((gpio_num_t)PIN_GLED, 1);
							ESP_LOGI(TAG, "red blink on");
							state = State::OrangeBlink;
							if (blinks >= 5) {
								state = State::GreenLed;
								blinks = 0;
							}
							vTaskDelay(50);
							}
							break;
						}
				}
				vTaskDelay(200);
		}
	}; 
}; // end namespace CleanRTOS