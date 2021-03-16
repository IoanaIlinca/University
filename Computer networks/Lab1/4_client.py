import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
string1 = "Ioana"
string2 = "Maria"
string1Sorted = ''.join(sorted(string1))
string2Sorted = ''.join(sorted(string2))
s.sendto(string1Sorted.encode(), ('127.0.0.1', 5555))
s.sendto(string2Sorted.encode(), ('127.0.0.1', 5555))
print (s.recvfrom(101))