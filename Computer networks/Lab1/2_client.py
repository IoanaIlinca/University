import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
string = "Ana are me re"
s.sendto(string.encode(), ('127.0.0.1', 5555))
print (s.recvfrom(51))