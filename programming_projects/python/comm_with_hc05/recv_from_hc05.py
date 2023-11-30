import serial

hc05 = serial.Serial("com8", 9600);

while True:
  recv_msg = hc05.readline();
  print("HC05 SAYS:", recv_msg.decode());