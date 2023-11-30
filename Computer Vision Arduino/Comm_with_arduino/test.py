import serial

my_serial = serial.Serial("com4", 9600)
while True:
  my_input = input("Please input something: ").strip()
  print("Sending {}...".format(my_input))
  my_serial.write(my_input.encode('utf-8'))
  print("Message sent successfully")
  print(my_serial.readline().decode('utf-8'))