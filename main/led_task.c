#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

#include "led_task.h"

#define BLINK_GPIO CONFIG_BLINK_GPIO
#define BLINK_ON_LENGTH_MS CONFIG_BLINK_ON_LENGTH_MS
#define BLINK_OFF_LENGTH_MS CONFIG_BLINK_OFF_LENGTH_MS

static const char *TAG = "BLINK";

static void led_task(void *_)
{
    esp_log_level_set("BLINK", ESP_LOG_INFO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while (1)
    {
        ESP_LOGI(TAG, "Turning on the LED");
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(BLINK_ON_LENGTH_MS / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "Turning off the LED");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(BLINK_OFF_LENGTH_MS / portTICK_PERIOD_MS);
    }
}

void setup_led_task()
{
    xTaskCreate(led_task, "LED-task", 2048, NULL, 1, NULL);
}

void loop_led_task()
{
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
