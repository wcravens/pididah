TftTinker: build/TftTinker.ino.elf

build/TftTinker.ino.elf: TftTinker.ino
	arduino-cli compile -vb esp32:esp32:adafruit_feather_esp32s3_tft --output-dir build --dump-profile TftTinker.ino

upload: build/TftTinker.ino.elf
	arduino-cli upload -vb esp32:esp32:adafruit_feather_esp32s3_tft --input-dir build -p /dev/cu.usbmodem14501 TftTinker.ino

clean:
	-@rm build/* 2> /dev/null || true
	-@echo "Clean."
