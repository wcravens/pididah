gpiointerrupt: gpiointerrupt-upload

GPIOInterrupt/GPIOInterrupt.ino.elf: GPIOInterrupt/GPIOInterrupt.ino
	arduino-cli compile -vb esp32:esp32:adafruit_feather_esp32s3_tft --output-dir GPIOInterrupt GPIOInterrupt

gpiointerrupt-upload: GPIOInterrupt/GPIOInterrupt.ino.elf 
	arduino-cli upload -vb esp32:esp32:adafruit_feather_esp32s3_tft -p /dev/cu.usbmodem14501 GPIOInterrupt

clean:
	rm \
GPIOInterrupt/GPIOInterrupt.ino.bin \
GPIOInterrupt/GPIOInterrupt.ino.bootloader.bin \
GPIOInterrupt/GPIOInterrupt.ino.elf \
GPIOInterrupt/GPIOInterrupt.ino.map \
GPIOInterrupt/GPIOInterrupt.ino.partitions.bin \
GPIOInterrupt/GPIOInterupt.ino.bin \
GPIOInterrupt/GPIOInterupt.ino.bootloader.bin \
GPIOInterrupt/GPIOInterupt.ino.elf \
GPIOInterrupt/GPIOInterupt.ino.map \
GPIOInterrupt/GPIOInterupt.ino.partitions.bin \
GPIOInterrupt/debug.cfg \
GPIOInterrupt/debug_custom.json \
GPIOInterrupt/esp32s3.svd
