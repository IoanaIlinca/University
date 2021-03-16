import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("127.0.0.1", 7777))
name = input("Eneter your name: ")
s.send(name.encode())
print(s.recvfrom(10)[0].decode())
s.close()