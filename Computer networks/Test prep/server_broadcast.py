import socket
import time

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # udp

server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

server.settimeout(0.2) # so the socket does not block when trying to recieve data
message = b'your message is very important to us'

while True:
    server.sendto(message, ("<broadcast>", 7777))
    print('Message sent!')
    time.sleep(1)

    