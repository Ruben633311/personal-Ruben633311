#pragma once
#include <crt_CleanRTOS.h>
#include "TrafficLight.hpp"

// by Bart Bozon, 2025

namespace crt
{
	class ButtonTask : public Task{
		
		private:
			uint8_t pinButton;
			int timeBetweenReads;
			TrafficLight& trafficLight;
			
		public:
			ButtonTask(const char *taskName, unsigned int taskPriority, unsigned int taskCoreNumber, const uint8_t pinButton, int timeBetweenReads, TrafficLight& trafficlight)
			: Task(taskName, taskPriority, 3000, taskCoreNumber), pinButton(pinButton), timeBetweenReads(timeBetweenReads), trafficLight(trafficlight)
			{
				esp_rom_gpio_pad_select_gpio(pinButton);
				gpio_reset_pin((gpio_num_t)pinButton);
				gpio_set_direction((gpio_num_t)pinButton, GPIO_MODE_INPUT);
				ESP_LOGI(taskName, "start task");
				start();
			}

			// bool isPressed()
			// {
			// 	bool buttonRead = gpio_get_level((gpio_num_t)pinButton);
			// 	bool bPressed = (buttonRead == true);
			// 	return bPressed;
			// }

		private:
			int buttonlevel = 0;

			void main()
			{

				// main function
				while (true)
				{
					int level = gpio_get_level((gpio_num_t)pinButton);
					
					if (level == 0 && buttonlevel == 1)
					{
						if(pinButton == 0){
							trafficLight.knopIngedruktA();
						}
						if(pinButton == 22){
							trafficLight.knopIngedruktB();
						}
					}
					buttonlevel = level;
					vTaskDelay(pdMS_TO_TICKS(timeBetweenReads));
				}
			}; 
	};
}