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

static TaskHandle_t  left_paddle_task_handle; 
static TaskHandle_t  right_paddle_task_handle; 

static void paddle_isr_handler( void* arg ) {
    TaskHandle_t task_handle = *(TaskHandle_t*) arg;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xTaskNotifyFromISR( task_handle, NULL, eNoAction, &xHigherPriorityTaskWoken );
    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

static void gpio_task_handler(void* pvParameters) {
    uint32_t pinNum = (uint32_t) pvParameters;
    uint32_t pinState = 0;
    uint32_t lastTick = 0;
    BaseType_t xEvent;

    for(;;) {
      xEvent = xTaskNotifyWait( 0x00, ULONG_MAX, NULL, portMAX_DELAY );
      if( xEvent == pdPASS ) {
        TickType_t now = xTaskGetTickCount();
        //if( now - lastTick > 5 ) {
          lastTick = now;
          uint32_t currentState = gpio_get_level( pinNum );
          if( currentState != pinState ) {
            pinState = currentState;
            printf( "Tick: %ld, GPIO Pin: %ld, State: %ld. \n", now, pinNum, pinState );
          }
        //}
      }
    }
}

void configure_input_gpio() {
  gpio_config_t io_conf = {};
  io_conf.intr_type     = GPIO_INTR_ANYEDGE;
  io_conf.mode          = GPIO_MODE_INPUT;
  io_conf.pull_up_en    = GPIO_PULLUP_ENABLE;
  io_conf.pull_down_en  = GPIO_PULLDOWN_DISABLE;
  io_conf.pin_bit_mask  = GPIO_INPUT_PIN_SEL; 
  gpio_config( &io_conf );
}

void configure_event_management() {
  gpio_install_isr_service( ESP_INTR_FLAG_EDGE );
  
  xTaskCreate( gpio_task_handler, "left_paddle_task_handler",  2048, (void*) GPIO_LEFT_PADDLE,  10,  &left_paddle_task_handle  );
  xTaskCreate( gpio_task_handler, "right_paddle_task_handler", 2048, (void*) GPIO_RIGHT_PADDLE, 10, &right_paddle_task_handle );

  gpio_isr_handler_add( GPIO_LEFT_PADDLE,   paddle_isr_handler, (void*) &left_paddle_task_handle  );
  gpio_isr_handler_add( GPIO_RIGHT_PADDLE,  paddle_isr_handler, (void*) &right_paddle_task_handle );
}

void app_main( void ) {
  configure_input_gpio();
  configure_event_management();
}