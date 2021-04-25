#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

#include "poll_button.h"

#define BLINK_GPIO CONFIG_BLINK_GPIO
#define BUTTON_GPIO GPIO_NUM_23

static const char *TAG = "BLINK";

void setup_poll_button()
{
    //esp_log_level_set("BLINK", ESP_LOG_ERROR);
    esp_log_level_set("BLINK", ESP_LOG_INFO);

    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_pulldown_en(BUTTON_GPIO);
}

void loop_poll_button()
{
    switch (gpio_get_level(BUTTON_GPIO))
    {
    case 0:
        // button is not pressed
        ESP_LOGI(TAG, "Turning off the LED");
        gpio_set_level(BLINK_GPIO, 0);
        break;
    case 1:
        // button is pressed
        ESP_LOGI(TAG, "Turning on the LED");
        gpio_set_level(BLINK_GPIO, 1);
        break;
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
}
