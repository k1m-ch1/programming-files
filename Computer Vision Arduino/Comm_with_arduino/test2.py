import serial
import time

my_serial= serial.Serial('com4', 9600, timeout=1)
time.sleep(3)
str_send = ""
for i in range(4, 256):
  for j in range (5):
    str_send = str_send + ',' + str(i-j)
  str_send = str_send + ','
  my_serial.write(str_send.strip().encode('utf-8'))
  time.sleep(0.1)
  str_send = ""
print("program ended")
