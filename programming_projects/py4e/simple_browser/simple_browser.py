import socket
from time import time
import re


start_time = time()
my_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
my_sock.connect(('data.pr4e.org', 80))
command = "GET http://data.pr4e.org/words.txt HTTP/1.0\r\n\r\n"
my_sock.send(command.encode())


received_data = ""
while True:
  data = my_sock.recv(512)
  if len(data) < 1:
    break
  received_data += data.decode()

raw_string = r'\n\n'
my_obj = re.search(raw_string, received_data)
print(my_obj)
print_data = received_data[my_obj.end():]
print(print_data)
print("\n[{}]".format(time()-start_time))