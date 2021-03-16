import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", 5555))
buff,addr=sock.recvfrom(101)
number = int(buff.decode())
lis = []
print(number)
for i in range(1, number + 1):
    print(i)
    if number % i == 0:
        lis.append(i)

sock.sendto(str(lis).encode(), addr)