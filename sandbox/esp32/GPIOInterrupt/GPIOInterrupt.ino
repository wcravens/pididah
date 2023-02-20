#include <chrono>
#include <Arduino.h>

#define DEBOUNCE_MILLISECONDS 100

unsigned long debounce_counter = 0;

struct Button {
    const uint8_t PIN;
    uint32_t numberKeyPresses;
    bool pressed;
    unsigned long millis_since_last_interrupt;
};

Button button1 = {11, 0, false};
Button button2 = {5, 0, false};

/*
void ARDUINO_ISR_ATTR isr(void* arg) {
    Button* s = static_cast<Button*>(arg);
    if( millis() - s->millis_since_last_interrrupt < DEBOUNCE_MILLISECONDS ) return; 
    s->numberKeyPresses += 1;
    s->millis_since_last_interrrupt = millis();
    s->pressed = true;
}
*/

void ARDUINO_ISR_ATTR button_1_isr() {
    if( millis() - debounce_counter < DEBOUNCE_MILLISECONDS ) return; 
    button1.numberKeyPresses += 1;
    debounce_counter = millis();
    button1.pressed = true;
}
void ARDUINO_ISR_ATTR button_2_isr() {
    if( millis() - debounce_counter < DEBOUNCE_MILLISECONDS ) return; 
    button2.numberKeyPresses += 1;
    debounce_counter = millis();
    button2.pressed = true;
}


void setup() {
    auto start = std::chrono::steady_clock::now();
    Serial.begin(115200);

    pinMode(button1.PIN, INPUT_PULLUP);
    attachInterrupt( digitalPinToInterrupt( button1.PIN ), button_1_isr, FALLING );

    pinMode(button2.PIN, INPUT_PULLUP);
    attachInterrupt( digitalPinToInterrupt( button2.PIN ), button_2_isr, FALLING );
}

void loop() {
    if (button1.pressed) {
        Serial.printf("Button 1 has been pressed %u times\n", button1.numberKeyPresses);
        Serial.println( button1.millis_since_last_interrupt );
        button1.pressed = false;
    }
    if (button2.pressed) {
        Serial.printf("Button 2 has been pressed %u times\n", button2.numberKeyPresses);
        Serial.println( button2.millis_since_last_interrupt );
        button2.pressed = false;
    }
    /*
    static uint32_t lastMillis = 0;
    if (millis() - lastMillis > 10000) {
      lastMillis = millis();
      detachInterrupt(digitalPinToInterrupt( button1.PIN ) );
      Serial.println( "Detached button1.PIN\n");
    }
    */
}

