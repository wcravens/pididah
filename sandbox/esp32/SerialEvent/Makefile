SerialEvent: SerialEvent.ino.elf

SerialEvent.ino.elf: SerialEvent.ino
	arduino-cli compile -vb esp32:esp32:adafruit_feather_esp32s3_tft --output-dir build --dump-profile SerialEvent.ino

upload: SerialEvent.ino.elf 
	arduino-cli upload -vb esp32:esp32:adafruit_feather_esp32s3_tft -p /dev/cu.usbmodem14501 --input-dir "build"

clean:
	-@rm build/* 2> /dev/null || true
	-@echo "Clean."
