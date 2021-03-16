import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", 5555))
buff,addr=sock.recvfrom(51)
string = str(buff)
newString = ""
for char in string:
    newString = char + newString

sock.sendto(newString.encode(), addr)