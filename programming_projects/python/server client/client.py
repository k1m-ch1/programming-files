import socket

PORT = 5050
ADDRESS = socket.gethostname()

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((ADDRESS, PORT))

client.send("Hello! from client".encode('utf-8'))

client.close()