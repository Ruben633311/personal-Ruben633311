/*! \brief A analog reader class for reading a keypad
 *
 *  Make an analog reading from the ESP32 ADC 
 *  The anaolog "input only" GPIO 35 is used as input to read the analog keypad.
 */

/**
* @file    AnalogButtonReader.hpp
* @brief   Class AnalogButtonReader wordt geinitialiseerd, functies en members gegeven.
* @details De class werkt met ADC1_CHANNEL_7 en met GPIO_NUM_35 van de cs-32.
* @author  Ruben Kroon
* @date    29-09-2025
*/

#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/adc.h"
#include <vector>
#include <functional>

enum class Button {
    NONE,
    UP,
    DOWN,
    RIGHT,
    LEFT,
    FIRE
};

/**
* @brief   maakt een reader aan die de knoppen leest
* @param   adc_channel_  het kanaal waaruit de adc waarde wordt gelezen.
* @param   gpio_pin_    de pin waaruit de data gelezen wordt.
* @param   interval_ms_   variabel voor de vTaskDelay.
* @param   task_handle_    nodig om de xTaskCreatePinnedToCore in te stellen.
* @param   running_    variabele die bijhoud of de class aan het runnen is.
*/
class AnalogButtonReader {
public:
    AnalogButtonReader(adc1_channel_t channel, gpio_num_t pin, uint32_t interval_ms);
    ~AnalogButtonReader();

    void start();
    void stop();

    void setCallback(std::function<void(Button)> callback);

private:
    adc1_channel_t adc_channel_;
    gpio_num_t gpio_pin_;
    uint32_t interval_ms_;
    TaskHandle_t task_handle_;
    bool running_;
    std::function<void(Button)> button_callback_;

    static void taskWrapper(void* pvParameters);
    void run();
    Button detectButton(int raw_adc);
};