/**************************************************************************
  This is a library for several Adafruit displays based on ST77* drivers.

  Works with the Adafruit ESP32-S2 TFT Feather
    ----> http://www.adafruit.com/products/5300

  Check out the links above for our tutorials and wiring diagrams.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 **************************************************************************/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

// Use dedicated hardware SPI pins
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


void initialize_tft() {
  // turn on backlite
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);

  // turn on the TFT / I2C power supply
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);

  // initialize TFT
  tft.init(135, 240);  // Init ST7789 240x135
  tft.setRotation(3);  // Top left corner of the TFT
  tft.setCursor(0, 0);
  tft.setTextWrap(true);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.fillScreen(ST77XX_BLACK);
  delay(10);
}
void setup(void) {
  Serial.begin(115200);
  initialize_tft();
  Serial.println(F("Welcome to PiDiDah!") );
  tft.println( F("Welcome to PiDiDah!") );
}

#define HEART_BEAT_IN_MILLIS 1000
uint64_t last_heart_beat_time = 0;

void print_heartbeat( char* txt, uint64_t time ) {
  Serial.println( txt + time );
  tft.println( txt + time );
}

void loop() {
  while( !Serial ) ;
  uint64_t now = millis();
  if( (now - HEART_BEAT_IN_MILLIS ) > last_heart_beat_time ) {
    last_heart_beat_time = now;
    Serial.println( "Heartbeat:" );
    Serial.println( last_heart_beat_time, DEC );
  }
}