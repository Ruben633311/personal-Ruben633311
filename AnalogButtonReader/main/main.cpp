#include "AnalogButtonReader.hpp"

static const char* TAG = "MAIN";

extern "C" void app_main() {
/**
* @brief   maakt een buttons reader aan met channel 7, gpio pin 35 en een interval van 200ms. 
Ook wordt een callback geset op de reader en de cases gedefinieerd. Hierdoor word het indrukken van knoppen herkend en kunnen de cases verwisselen.
* @param   buttons  een AnalogButtonReader object buttons die op de knoppen leest.
* de while true loop met vTaskDelay zorgt ervoor dat het programma altijd gerunt wordt en dat tussendoor tijd aan andere taken wordt gegeven.
*/
    AnalogButtonReader buttons(ADC1_CHANNEL_7, GPIO_NUM_35, 200);

    buttons.setCallback([&](Button button){
        switch (button) {
        case Button::UP:    ESP_LOGI("MAIN", "UP pressed"); break;
        case Button::DOWN:  ESP_LOGI("MAIN", "DOWN pressed"); break;
        case Button::LEFT:  ESP_LOGI("MAIN", "LEFT pressed"); break;
        case Button::RIGHT: ESP_LOGI("MAIN", "RIGHT pressed"); break;
        case Button::FIRE:  ESP_LOGI("MAIN", "SELECT pressed"); break;
        default: break;
    }
    });
    buttons.start();

    // Keep running
    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}