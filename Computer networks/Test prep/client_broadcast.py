import socket

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # udp

client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
client.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

client.bind(("", 7777))

while True:
    data, addr = client.recvfrom(1024)
    print("recieved message: %s" % data)
