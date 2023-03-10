#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#define GPIO_LEFT_PADDLE  45
#define GPIO_RIGHT_PADDLE 38
#define GPIO_INPUT_PIN_SEL ( ( 1ULL<<GPIO_LEFT_PADDLE ) | ( 1ULL<<GPIO_RIGHT_PADDLE ) );

static QueueHandle_t gpio_evt_queue = NULL;
static TaskHandle_t  gpio_task_handle; 

static void gpio_isr_handler( void* arg ) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    uint32_t gpioPin = (uint32_t) arg;
    xTaskNotifyFromISR( gpio_task_handle, gpioPin, eSetValueWithOverwrite, &xHigherPriorityTaskWoken );
    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

static void gpio_task_handler(void* pvParameters) {
    BaseType_t xEvent;
    uint32_t ulNotifiedValue;
    uint32_t lastLeftTick;
    uint32_t lastRightTick;
    for(;;) {
      xEvent = xTaskNotifyWait( 0x00, ULONG_MAX, &ulNotifiedValue, portMAX_DELAY );
      if( xEvent == pdPASS ) {
        TickType_t now = xTaskGetTickCount();
        uint32_t pinNum = ulNotifiedValue;
        uint32_t pinState = gpio_get_level( pinNum );
        printf( "Tick: %ld, GPIO Pin: %ld, State: %ld. \n", now, pinNum, pinState );
      }
    }
}

void configure_input_gpio() {
  gpio_config_t io_conf = {};
  io_conf.intr_type     = GPIO_INTR_ANYEDGE;
  io_conf.mode          = GPIO_MODE_INPUT;
  io_conf.pull_up_en    = GPIO_PULLUP_DISABLE;
  io_conf.pull_down_en  = GPIO_PULLDOWN_DISABLE;
  io_conf.pin_bit_mask  = GPIO_INPUT_PIN_SEL; 
  gpio_config( &io_conf );
}

void configure_event_management() {
  gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
  xTaskCreate( gpio_task_handler, "gpio_task_example", 2048, NULL, 10, &gpio_task_handle );
  gpio_install_isr_service( ESP_INTR_FLAG_EDGE );
  gpio_isr_handler_add( GPIO_RIGHT_PADDLE,  gpio_isr_handler, (void*) GPIO_RIGHT_PADDLE );
  gpio_isr_handler_add( GPIO_LEFT_PADDLE,   gpio_isr_handler, (void*) GPIO_LEFT_PADDLE  );
}

void app_main( void ) {
  configure_input_gpio();
  configure_event_management();
}