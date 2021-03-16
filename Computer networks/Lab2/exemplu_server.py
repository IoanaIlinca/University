import time
import socket
from threading import Thread
def f(cs, i):
    print ("Procesez client"+str(i))
    b=cs.recv(10)
    time.sleep(10)
    cs.send(str(i).encode())
    cs.close()

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("0.0.0.0", 7777))
s.listen(5)
i = 0
while (True):
    i = i + 1
    cs,addr = s.accept()
    t = Thread(target = f, args = (cs, i, ))
    t.start()