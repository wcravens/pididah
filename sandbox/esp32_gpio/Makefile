gpiointerrupt: gpiointerupt-upload

GPIOInterupt/GPIOInterupt.ino.elf: GPIOInterupt/GPIOInterupt.ino
	arduino-cli compile -vb esp32:esp32:adafruit_feather_esp32s3_tft --output-dir GPIOInterupt GPIOInterupt

gpiointerupt-upload: GPIOInterupt/GPIOInterupt.ino.elf 
	arduino-cli upload -vb esp32:esp32:adafruit_feather_esp32s3_tft -p /dev/cu.usbmodem14501 GPIOInterupt

