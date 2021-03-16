import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("0.0.0.0", 5555))
buff,addr=s.recvfrom(10)
sum = 0
length = int(buff)
for i in range(length):
    buff,addr=s.recvfrom(10)
    number = int(buff)
    sum += number

s.sendto(str(sum).encode(), addr)