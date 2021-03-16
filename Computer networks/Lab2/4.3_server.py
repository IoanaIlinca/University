import time
import socket
from threading import Thread

def function(cs, IP):
    sum = 0
    for character in IP:
        if character == '.':
            continue
        sum += int(character)
    
    
    cs.send(str(sum).encode())
    cs.close()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("0.0.0.0", 7777))
s.listen(5)

while (True):
    cs,addr=s.accept()
    t = Thread(target=function, args=(cs, addr[0], ))
    t.start()
