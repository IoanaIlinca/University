import time
import socket
from threading import Thread

def function(cs, addr):
    clientName = cs.recv(10)
    time.sleep(3)
    print (clientName.decode())
    print (addr[1])
    port = addr[1]
    sum = 0
    while (port):
        sum += port%10
        port //= 10
    cs.send(str(sum).encode())
    cs.close()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("0.0.0.0", 7777))
s.listen(5)
print (s.getsockname()[1])

while (True):
    cs,addr = s.accept()
    t = Thread(target = function, args = (cs, addr))
    t.start()

