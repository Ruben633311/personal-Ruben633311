#include "RLed.hpp"

void RLed::configureGpio(gpio_num_t pin) {

	gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << pin);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
}

void RLed::redLedOn() {
    gpio_set_level(GPIO_NUM_4, 0);

}

void RLed::redLedOff() {
    gpio_set_level(GPIO_NUM_4, 1);

}