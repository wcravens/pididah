tinker: tinker.ino.elf

tinker.ino.elf: tinker.ino
	arduino-cli compile -vb esp32:esp32:adafruit_feather_esp32s3_tft --output-dir . --dump-profile tinker.ino

upload: tinker.ino.elf 
	arduino-cli upload -vb esp32:esp32:adafruit_feather_esp32s3_tft -p /dev/cu.usbmodem101 --input-dir "."

clean:
	-rm \
tinker.ino.bin \
tinker.ino.bootloader.bin \
tinker.ino.elf \
tinker.ino.map \
tinker.ino.partitions.bin \
debug.cfg \
debug_custom.json \
esp32s3.svd
