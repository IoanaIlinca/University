import time
import socket
from threading import Thread

def function(cs, port):
    number = int(cs.recv(10).decode())
    time.sleep(3)
    stringNumber = ""
    if (number == 0):
        stringNumber = "zero"
    i = 0
    if(number < 10 or ((number //10) % 10 != 1)):
        if (number == 1):
            stringNumber = "unu"
        if (number == 2):
            stringNumber = "doi"
        if (number == 3):
            stringNumber = "trei"
        if (number == 4):
            stringNumber = "patru"
        if (number == 5):
            stringNumber = "cinci"

    cs.send(str(sum).encode())
    cs.close()
    

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("0.0.0.0", 7777))
s.listen(5)

while (True):
    cs,addr = s.accept()
    t = Thread(target = function, args = (cs, int(s.getsockname()[1]), ))
    t.start()