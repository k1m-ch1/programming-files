import socket

ADDRESS = " "
PORT = 6969

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((ADDRESS, PORT))
print("Connected successfully!")


to_send = input("input to send to server: ")
client.sendall(to_send.encode())

client.close()