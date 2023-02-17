Run `./gpiozero_tinker.py` for a test of reading the paddles.

**gpiozero**

`gpiozero` uses `Rpi.Gpio` by default. It was giving me some random responses.  In particlar it
was frequently failing to recognise `when_released`. Switching to `pigpio` with
`gpiozero.pins.pigpio` and `PiGPIOFactory` did the trick.
