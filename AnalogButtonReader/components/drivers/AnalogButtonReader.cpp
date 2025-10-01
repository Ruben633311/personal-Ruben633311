/*! \brief ADC reading analog buttons implementation
 *
 *  Make an analog reading from an analog keypad with 5 buttons
 *  ToDo: some keypresses seem to be missed no raw value is registered. Faster polling?
 */
#include "AnalogButtonReader.hpp"

static const char* TAG = "AnalogButtonReader";

/**
* @brief   maakt een ButtonThreshold struct aan met members voor een button threshold vector.
* @param   min  een minimale ruwe waarde waarboven een state actief gaat zijn
* @param   max  een maximale ruwe waarde waaronder een state actief gaat zijn
* @param   button  een Button enum class die meerder richtingen erin heeft zitten
*/
struct ButtonThreshold {
    int min;
    int max;
    Button button;
};

/**
* @brief   maakt een vector van button_thresholds, hierin staat wanneer welke state geactiveerd moet zijn.
*/
static const std::vector<ButtonThreshold> button_thresholds = {
    {200, 300, Button::UP},
    {550, 610, Button::DOWN},
    {900, 1000, Button::RIGHT},
    {0, 0, Button::LEFT},
    {1400, 1500, Button::FIRE},
};

/**
* @brief   Initialiseerd de AnalogButtonReader class door de channel, pin, interval, mee te geven in de constructor 
en task handle, running en button callback ook in de initialisatielijst te zetten
* de width van het kanaal wordt bepaald met adc1_config_width en wordt een breedte van 2 tot de macht 11 ingevuld.
* het kanaal zelf wordt geconfigureerd met adc1_config_channel_atten en wordt het kanaal nummer gegeven en het spanningsbereik dat de ADC op die pin aankan.
*/
AnalogButtonReader::AnalogButtonReader(adc1_channel_t channel, gpio_num_t pin, uint32_t interval_ms)
    : adc_channel_(channel), gpio_pin_(pin), interval_ms_(interval_ms),
      task_handle_(nullptr), running_(false), button_callback_(nullptr) {

    adc1_config_width(ADC_WIDTH_BIT_11);
    adc1_config_channel_atten(adc_channel_, ADC_ATTEN_DB_12);
}

AnalogButtonReader::~AnalogButtonReader() {
    stop();
}

void AnalogButtonReader::start() {
    if (!running_) {
        running_ = true;
        xTaskCreatePinnedToCore(taskWrapper, "AnalogButtonTask", 4096, this, 5, &task_handle_, 1);
    }
}

void AnalogButtonReader::stop() {
    if (running_) {
        running_ = false;
        if (task_handle_) {
            vTaskDelete(task_handle_);
            task_handle_ = nullptr;
        }
    }
}

void AnalogButtonReader::setCallback(std::function<void(Button)> callback) {
    button_callback_ = callback;
}

void AnalogButtonReader::taskWrapper(void* pvParameters) {
    AnalogButtonReader* reader = static_cast<AnalogButtonReader*>(pvParameters);
    reader->run();
}

/**
* @brief   hier wordt de run functie gedfinieerd. De button wordt automatisch op NONE gezet. De ruwe adc waarde en de knop worden gelezen.
als een andere knop is ingedrukt dan wordt een bericht in de cmd gestuurd en er zit een delay zodat tussendoor andere dingen gedaan kunnen worden.
* @param   lastButton  een object van de Button enum class en deze veranderd van waardes, hierop werkt de state machine.
*/
void AnalogButtonReader::run() {
    Button lastButton = Button::NONE;

    while (running_) {
        int raw = adc1_get_raw(adc_channel_);
        Button currentButton = detectButton(raw);
        if (currentButton != lastButton) {
            ESP_LOGI(TAG, "Button Changed: %d (ADC Raw: %d)", static_cast<int>(currentButton), raw);
            lastButton = currentButton;
            if (button_callback_) {
                button_callback_(currentButton);
            }
        }

        vTaskDelay(pdMS_TO_TICKS(interval_ms_));
    }
}

/**
* @brief   hier wordt de detectButton functie gedefinieerd. De code checkt de thresholds en als de waarde er tussen valt wordt het geretourneerd. 
Ander wordt de Button op NONE gezet en wordt dit geretourneerd.
* @param   threshold  is een ButtonThreshold datatype en deze bevat waardes waar de ruwe data tussen moet vallen voordat de state veranderd wordt.
* @param   raw_adc  De gemeten ADC-waarde.
* @return  De gedetecteerde knop of Button::NONE als geen match gevonden is.
*/
Button AnalogButtonReader::detectButton(int raw_adc) {
    for (const ButtonThreshold& threshold : button_thresholds) {
    if (raw_adc >= threshold.min && raw_adc <= threshold.max) {
        return threshold.button;
        }
    }
    return Button::NONE;
}