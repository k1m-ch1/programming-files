import time
import serial

my_serial = serial.Serial('com4', 9600)

while True:
  my_serial.write(b'0')
  time.sleep(1)
  my_serial.write(b'1')
  time.sleep(1)