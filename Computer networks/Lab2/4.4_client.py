import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("127.0.0.1", 7777))
s.send(str(123).encode())
print(s.recvfrom(100)[0].decode())
s.close()