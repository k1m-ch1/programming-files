import serial
import time
import math

my_string,val = ",100,100,100,100,100,", 0
my_serial = serial.Serial('COM4', 9600, timeout=1)
for i in range(math.floor(256/10)):
  my_serial.write(f",{val},{val},{val},{val},{val},".strip().encode('utf-8'))
  print("sent!")
  val+= 10