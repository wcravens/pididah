TftTinker: build/TftTinker.ino.elf

build/TftTinker.ino.elf: TftTinker.ino
	arduino-cli compile -vb esp32:esp32:adafruit_feather_esp32s3_tft --output-dir build --dump-profile TftTinker.ino

upload: build/TftTinker.ino.elf
	esptool.py --chip esp32s3 --port "/dev/cu.usbmodem14501" --baud 921600  --before default_reset --after hard_reset write_flash  -z --flash_mode dio --flash_freq 80m --flash_size 4MB 0x0 "build/TftTinker.ino.bootloader.bin" 0x8000 "build/TftTinker.ino.partitions.bin" 0xe000 "/Users/wcravens/Library/Arduino15/packages/esp32/hardware/esp32/2.0.6/tools/partitions/boot_app0.bin" 0x10000 "build/TftTinker.ino.bin" 0x2d0000 "/Users/wcravens/Library/Arduino15/packages/esp32/hardware/esp32/2.0.6/variants/adafruit_feather_esp32s3_tft/tinyuf2.bin"

clean:
	-@rm build/* 2> /dev/null || true
	-@echo "Clean."
