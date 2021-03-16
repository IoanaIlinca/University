import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", 5555))
buff,addr=sock.recvfrom(101)
newString = str(buff.decode())
print(newString)
buff,addr=sock.recvfrom(101)
newString += str(buff.decode())
print(newString)
newStringSorted = ''.join(sorted(newString))

sock.sendto(newStringSorted.encode(), addr)