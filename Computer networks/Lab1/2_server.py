import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("0.0.0.0", 5555))
buff,addr=s.recvfrom(51)
string = str(buff)
count = 0
for char in string:
    if char == ' ':
        count += 1

s.sendto(str(count).encode(), addr)