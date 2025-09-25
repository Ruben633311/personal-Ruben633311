#include "Ili9341Display.hpp"
#include "esp_log.h"
#include <esp_random.h> // for esp_random()
#include <vector>

static const char* TAG = "MAIN";

extern "C" void app_main(void)
{
    Ili9341Display display(13, 14, 15, 2, -1, 27); // MOSI, SCLK, CS, DC, RST, BCKL (BL on GPIO 27, BL for CYD3.2 on GPIO 21)
    ESP_LOGI(TAG, "Init display");
    display.init();
    display.backlightOn(); // make sure the backlight is on
    // ESP_LOGI(TAG, "Starting diagnostics");
    // display.diagnostics(); // This works since in only uses the fillscreen method
    // display.diagnostics_drawables(); // Implement (all) primitives before you can call this method

    // Only the drawPixel method is implemented. 
    // This is a heavy task and you should do nothing like this in your main loop. Better to create a task.
    // This is for a demo only:
    display.fillScreen(display.rbg565(0, 0, 0)); // clear the screen

    uint8_t r = 0xFF;
    // maakt een plus
    // display.drawLine(150, 20, 150, 200, r);
    // display.drawLine(50, 100, 300, 100, r);

    // maak een rectangle
    // display.drawRectangle(150, 100, 150, 100, r);

    // maak een vierkant
    // display.drawSquare(100, 100, 100, 100, r);

    // maak een cirkel
    display.drawCircle(200, 130, 50, r);

    while (true){
        // Loop over all pixels
        for (int y = 0; y < Ili9341Display::HEIGHT; ++y) {
            for (int x = 0; x < Ili9341Display::WIDTH; ++x) {
                vTaskDelay(pdMS_TO_TICKS(10));
            }
        }

        // Small pause to prevent watchdog trigger
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
