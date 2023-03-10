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

static void gpio_isr_handler( void* arg ) {
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}

static void gpio_task_example(void* arg) {
    uint32_t io_num;
    for(;;) {
        if( xQueueReceive( gpio_evt_queue, &io_num, portMAX_DELAY ) ) {
            printf( "GPIO[%"PRIu32"] intr, val: %d\n", io_num, gpio_get_level( io_num ) );
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
  xTaskCreate( gpio_task_example, "gpio_task_example", 2048, NULL, 10, NULL );
  gpio_install_isr_service( ESP_INTR_FLAG_EDGE );
  gpio_isr_handler_add( GPIO_RIGHT_PADDLE,  gpio_isr_handler, (void*) GPIO_RIGHT_PADDLE );
  gpio_isr_handler_add( GPIO_LEFT_PADDLE,   gpio_isr_handler, (void*) GPIO_LEFT_PADDLE  );
}



void app_main( void ) {
  configure_input_gpio();
  configure_event_management();
}