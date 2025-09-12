#pragma once

#include "esp_err.h"
#include "esp_log.h"

class RgbLed {
private:
    PwmLed* red;
    PwmLed* green;
    PwmLed* blue;

public:
    enum class Color {
        OFF,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        CYAN,
        MAGENTA,
        WHITE
    };

    RgbLed(PwmLed* red, PwmLed* green, PwmLed* blue)
        : red(red), green(green), blue(blue) {
        setColor(Color::OFF); // start uit
    }

    void test() {
        red->setDuty(100);
        green->setDuty(6);
        blue->setDuty(0);
    }

    // Nieuwe functie: standaardkleuren instellen
    void setColor(Color color) {
        switch (color) {
            case Color::OFF:     setRgb(0,   0,   0);   break;
            case Color::RED:     setRgb(100, 0,   0);   break;
            case Color::GREEN:   setRgb(0,   100, 0);   break;
            case Color::BLUE:    setRgb(0,   0,   100); break;
            case Color::YELLOW:  setRgb(100, 6, 0);   break;
            case Color::CYAN:    setRgb(0,   100, 100); break;
            case Color::MAGENTA: setRgb(100, 0,   100); break;
            case Color::WHITE:   setRgb(100, 100, 100); break;
        }
    }

    // Extra: directe PWM waardes zetten
    void setRgb(uint8_t r, uint8_t g, uint8_t b) {
        red->setDuty(r);
        green->setDuty(g);
        blue->setDuty(b);
    }
};
