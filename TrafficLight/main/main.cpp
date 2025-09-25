// Important: Update the CMakeLists file in the same folder as this main.cpp file
// (the folder "main", that is) to make sure that every dependency can be built.

#include "TrafficLight.h"

const uint8_t PIN_BTN =  0; // ESP32: BOOT Button
const uint8_t PIN_BTN22 =  22; // ESP32: Bult-in LED
const uint8_t PIN_RLED =  4; // ESP32: Bult-in LED
const uint8_t PIN_GLED =  17; // ESP32: Bult-in LED

extern "C"

void app_main(void)
{
	crt::Button btnInput1("InputButton1", PIN_BTN, false);  
	crt::Button btnInput2("InputButton2", PIN_BTN22, false); 
	crt::TrafficLight trafficLight("TrafficLightTask", 2, 0, PIN_RLED, PIN_GLED, &btnInput1, &btnInput2);
	while(true){
		vTaskDelay(100);
	}
}
