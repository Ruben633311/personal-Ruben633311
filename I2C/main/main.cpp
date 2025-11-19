#include "I2CManager.hpp"
#include <stdint.h>

static const char* TAG = "MAIN";

extern "C" void app_main() {
    I2CManager i2c;
    if (i2c.init() != ESP_OK) {
        ESP_LOGI(TAG, "Failed to initialize I2C");
        return;
    }

    uint8_t address = 0x20; // A0=A1=A2=GND
    uint8_t data = 0x01;
    // uint8_t address2 = 0x20; // A0=A1=A2=GND
 

    while (true) {
        int result = i2c.readRegister(address, &data, 1);
        ESP_LOGI(TAG, "Wrote: 0x%02X", address);

        ESP_LOGI(TAG, "check if readRegister worked: result=%d",
        result);

        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}

// #include <Wire.h>

// byte i2c_rcv;               // data received from I2C bus
// unsigned long time_start;   // start time in mSec
// int stat_LED;               // status of LED: 1 = ON, 0 = OFF
// byte value_pot;             // potentiometer position

// void setup(){
// 	Wire.begin(0x08);           // join I2C bus as Slave with address 0x08
	
// 	// event handler initializations
// 	Wire.onReceive(dataRcv);    // register an event handler for received data
// 	Wire.onRequest(dataRqst);   // register an event handler for data requests
	
// 	// initialize global variables
// 	i2c_rcv = 255;
// 	time_start = millis();
// 	stat_LED = 0;
	
// 	pinMode(13, OUTPUT);        // set pin 13 mode to output
// }

// void loop(){

// 	value_pot = analogRead(A0); // read analog value at pin A0 (potentiometer voltage)
	
// 	// blink logic code
//         if((millis() - time_start) > (1000 * (float)(i2c_rcv/255))) {
// 		stat_LED = !stat_LED;
// 		time_start = millis();
// 	}
// 	digitalWrite(13, stat_LED);
// }

// //received data handler function
// void dataRcv(int numBytes){
// 	while(Wire.available()) {	// read all bytes received
// 		i2c_rcv = Wire.read();
// 	}
// }

// // requests data handler function
// void dataRqst(){
// 	Wire.write(value_pot); // send potentiometer position
// }