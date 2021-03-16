import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.connect(('192.168.1.8', 7777)) # 192.168.1.4 server on VM, 192.168.1.8 server on windows

server.send(b'Hey there!')
print (server.recv(1024).decode())
server.close()