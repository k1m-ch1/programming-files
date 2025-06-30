import socket

ADDRESS = socket.gethostbyname(socket.gethostname())
PORT = 5050
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((ADDRESS, PORT))

print("Listening on {}".format(PORT))
server.listen(5)

while True:
  obj, address_client = server.accept()
  received_data = obj.recv(512).decode()
  print("Client says: {}".format(received_data))
  obj.send("Ok, I got the message".encode())
  obj.close()