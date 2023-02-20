GPIOInterrupt.ino.elf: GPIOInterrupt.ino
	arduino-cli compile -vb esp32:esp32:adafruit_feather_esp32s3_tft --output-dir . GPIOInterrupt.ino

upload: GPIOInterrupt.ino.elf 
	arduino-cli upload -vb esp32:esp32:adafruit_feather_esp32s3_tft -p /dev/cu.usbmodem2101 -l serial --input-dir "."

clean:
	-rm \
GPIOInterrupt.ino.bin \
GPIOInterrupt.ino.bootloader.bin \
GPIOInterrupt.ino.elf \
GPIOInterrupt.ino.map \
GPIOInterrupt.ino.partitions.bin \
debug.cfg \
debug_custom.json \
esp32s3.svd
