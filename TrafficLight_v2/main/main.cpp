// Important: Update the CMakeLists file in the same folder as this main.cpp file
// (the folder "main", that is) to make sure that every dependency can be built.
#include "ButtonTask.h"

const uint8_t PIN_BTN =  0; // ESP32: BOOT Button
const uint8_t PIN_BTN22 =  22; // ESP32: Bult-in LED
const uint8_t PIN_RLED =  4; // ESP32: Bult-in LED
const uint8_t PIN_GLED =  17; // ESP32: Bult-in LED

extern "C"
{
	void app_main();
}

void app_main(void)
{
	int timeBetweenReads = 50;

	crt::TrafficLight trafficlight("task", 5, 1, PIN_RLED, PIN_GLED);
	crt::ButtonTask buttonA("ButtonTask", 2 /*priority*/, 0 /*RUNNING_CORE*/, PIN_BTN, timeBetweenReads, trafficlight);
	crt::ButtonTask buttonB("ButtonTask", 2 /*priority*/, 0 /*RUNNING_CORE*/, PIN_BTN22, timeBetweenReads, trafficlight);


	while(true){
		// do nothing while the task is running
		vTaskDelay(100);
	}
}
