import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
number = 15
s.sendto(str(number).encode(), ('127.0.0.1', 5555))
print (s.recvfrom(101))