import time
import socket
from threading import Thread

def function(cs, port):
    sum = int(cs.recv(10).decode())
    time.sleep(3)
    while (port):
        sum += port % 10
        port //= 10
    cs.send(str(sum).encode())
    cs.close()
    

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("0.0.0.0", 7777))
s.listen(5)

while (True):
    cs,addr = s.accept()
    t = Thread(target = function, args = (cs, int(s.getsockname()[1]), ))
    t.start()