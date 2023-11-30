import serial

arduino = serial.Serial('com4', 9600)

while True:
  arduino_data = arduino.readline().decode('ascii').strip('\n')
  print(f"Arduino said: {arduino_data}")