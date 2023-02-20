**Starting and Stopping pigpiod**

   systemctl status pigpiod
   systemctl enable|disable pigpiod
   systemctl start|stop
Run `./gpiozero_tinker.py` for a test of reading the paddles.

**gpiozero**

`gpiozero` uses `Rpi.Gpio` by default. It was giving me some random responses.  In particlar it
was frequently failing to recognise `when_released`. Switching to `pigpio` with
`gpiozero.pins.pigpio` and `PiGPIOFactory` did the trick.

**[Inter-process communication in Linux: Using pipes and message
queues](https://opensource.com/article/19/4/interprocess-communication-linux-channels)**

**[TLDP Interprocess Communication Mechanisms](https://tldp.org/LDP/tlk/ipc/ipc.html)**

**[Arduino Language Refrence](https://www.arduino.cc/reference/en/)**

**[Espressif Arduino esp32 package file](https://raw.githubusercontent.com/espressif/arduino-esp32/master/package/package_esp32_index.template.json)

**Install esp32 core for Arduino environment**
```
   vi ~/Library/Arduino15/arduino-cli.yaml
   #   <   additional_urls: []
   #   ---
   #   >   additional_urls:
   #   >     - https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
   arduinio-cli core update-index
   arduinio-cli core install esp32:esp32
```

       