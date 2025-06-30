import socket

ADDRESS = socket.gethostbyname(socket.gethostname())
PORT = 5050

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((ADDRESS, PORT))

client.send("Hello, world".encode())

print("Server responded with {}".format(client.recv(512).decode()))