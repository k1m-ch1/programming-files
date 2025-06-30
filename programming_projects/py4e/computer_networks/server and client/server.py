import socket

ADDRESS = socket.gethostname()
PORT = 5050

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((ADDRESS, PORT))

server.listen(5)

while True:
  client_obj, client_addr = server.accept()
  client_says = client_obj.recv(512)
  print("Client says: \n {}".format(client_says))
  print("From address: {}".format(client_addr))