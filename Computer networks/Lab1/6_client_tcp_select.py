import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.connect(('192.168.1.8', 7777))
message = "Hey there!e"
server.send(message.encode())
print (server.recv(1024).decode())
server.close()