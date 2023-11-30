import serial
import time
hc05 = serial.Serial('com8', 9600)

while True:
  hc05.write(b'1')
  print("Sent a one: turned on led")
  time.sleep(2)
  hc05.write(b'0')
  print("Sent a 0: turned off led")
  time.sleep(2)
