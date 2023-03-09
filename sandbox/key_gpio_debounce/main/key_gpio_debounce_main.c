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

struct gpioInteruptMessage {
  gpio_num_t gpio_num;
  int level;
};

int64_t now() {
    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    return (int64_t)tv_now.tv_sec * 1000000L + (int64_t)tv_now.tv_usec;
}

static QueueHandle_t gpio_evt_queue = NULL;
volatile TickType_t lastISR = 0;

static void IRAM_ATTR gpio_isr_handler( void* arg ) {
  struct gpioInteruptMessage state;
  state.gpio_num = (gpio_num_t) arg;
  state.level = gpio_get_level( state.gpio_num );
  xQueueSendFromISR( gpio_evt_queue, &state, NULL );
}

static void gpio_task_example( void* arg ) {
  struct gpioInteruptMessage state;
  for(;;) {
    if ( xQueueReceive( gpio_evt_queue, &state, portMAX_DELAY ) ) {
      TickType_t nowTick = xTaskGetTickCount();
      printf( "GPIO[%d] intr, val: %d,%lu\n", state.gpio_num, state.level, nowTick );
      if ( nowTick - lastISR > 10 ) {
        lastISR = nowTick;
      }
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

void setup_isr_queue(){
  gpio_evt_queue = xQueueCreate( 1, sizeof( struct gpioInteruptMessage ) );
  xTaskCreate( gpio_task_example, "gpio_task_example", 2048, NULL, 10, NULL );
  gpio_install_isr_service( ESP_INTR_FLAG_EDGE );
  gpio_isr_handler_add( GPIO_RIGHT_PADDLE, gpio_isr_handler, (void*) GPIO_RIGHT_PADDLE );
  gpio_isr_handler_add( GPIO_LEFT_PADDLE,  gpio_isr_handler, (void*) GPIO_LEFT_PADDLE  );
}

void app_main( void ) {
  configure_input_gpio();
  setup_isr_queue();
}