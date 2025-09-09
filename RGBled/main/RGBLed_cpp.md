#include "RGBLed.hpp"

void RgbLed::configureGpio(gpio_num_t pin) {

	gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << pin); ;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
}

void RgbLed::setRgb(bool red, bool green, bool blue) {
    gpio_set_level(red_pin,   !red);
    gpio_set_level(green_pin, !green);
    gpio_set_level(blue_pin,  !blue);
}