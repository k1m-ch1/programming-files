import socket

# ADDRESS = "10.67.251.110"
PORT = 12121

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(('localhost', PORT))

print("Server listening on {} on port {}".format('localhost', PORT))
server.listen(5)

while True: 
  conn, addr = server.accept()
  print("Connected to device at addr {}".format(addr))
  recieved_message = conn.recv(1024).decode()
  print("Client says: {}".format(recieved_message))
  conn.close()