**Starting and Stoping pigpiod**

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

**[TLDP hInterprocess Communication Mechanisms](https://tldp.org/LDP/tlk/ipc/ipc.html)**

**[Arduino Language Refrence](https://www.arduino.cc/reference/en/)**
