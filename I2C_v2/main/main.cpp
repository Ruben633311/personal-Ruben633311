#include "I2CManager.hpp"
#include <stdint.h>

static const char* TAG = "MAIN";

extern "C" void app_main() {
    I2CManager i2c;
    if (i2c.init() != ESP_OK) {
        ESP_LOGI(TAG, "Failed to initialize I2C");
        return;
    }

    uint8_t data = 0;

    while (true) {

        esp_err_t result = i2c.readRegisterpcf(&data);

        if (result == ESP_OK) {
            ESP_LOGI(TAG, "Raw PCF value: 0x%02X", data);

            for (int pin = 0; pin < 5; pin++) {
                bool state = (data >> pin) & 0x01;   // bit uitlezen
                ESP_LOGI(TAG, "Pin P%d = %s", pin, state ? "HIGH" : "LOW");
            }
        } else {
            ESP_LOGE(TAG, "I2C read error: %d", result);
        }

        vTaskDelay(pdMS_TO_TICKS(500));  // 5x per seconde
    }
}
