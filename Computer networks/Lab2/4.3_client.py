import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("127.0.0.1", 7777))
print(s.recvfrom(10)[0].decode())
s.close()