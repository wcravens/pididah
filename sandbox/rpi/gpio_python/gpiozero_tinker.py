#!/usr/bin/env python

from gpiozero import Device, Button
from signal import pause
from gpiozero.pins.pigpio import PiGPIOFactory 
import time

RIGHT_PADDLE_PIN = 5  
LEFT_PADDLE_PIN  = 4

Device.pin_factory = PiGPIOFactory()
right_paddle = Button( RIGHT_PADDLE_PIN, bounce_time=0.001 )
left_paddle  = Button( LEFT_PADDLE_PIN , bounce_time=0.001 )


obj = time.gmtime(0)
epoch = time.asctime(obj)
print( "The Epoch is : ", epoch)

counter = 0
time_closed = 0
time_open = 0

def right_paddle_closed():
  global counter, time_closed
  counter += 1
  time_closed = time.time()
  print( "Right Paddle Closed\n", counter )

def right_paddle_open():
  global counter, time_closed
  print( "Right Paddle Open\n" , time.time() - time_closed, counter) 
  time_closed = 0
  
def left_paddle_closed():
  global counter, time_closed
  counter += 1
  time_closed = time.time() 
  print( "Left Paddle Closed\n" , counter )
  
def left_paddle_open():
  global counter, time_closed
  print( "Left Paddle Open\n" , time.time() - time_closed, counter )
  time_closed = 0

right_paddle.when_pressed = right_paddle_closed
right_paddle.when_released = right_paddle_open
left_paddle.when_pressed = left_paddle_closed
left_paddle.when_released = left_paddle_open

pause()