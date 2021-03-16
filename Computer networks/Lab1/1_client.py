import socket
s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
array = [2, 3, 6]
array_length = 3
s.sendto(str(array_length).encode(), ('127.0.0.1', 5555))
for number in array:
    s.sendto(str(number).encode(), ('127.0.0.1', 5555))
print (s.recvfrom(10))
