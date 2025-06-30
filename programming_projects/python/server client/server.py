import socket

HOST = socket.gethostname()
PORT = 5050

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

print(f"binding to {HOST} at port {PORT}")
server.bind((HOST, PORT))

server.listen(5)
while True:
  obj, address = server.accept()
  sent_data = obj.recv(1024).decode('utf-8')
  print("Sent data is", sent_data)
  obj.close()