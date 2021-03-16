import time
import socket
from threading import Thread


def f(cs,i):
    print ("Procesez client"+str(i))
    path = cs.recv(100).decode()
    print(path)
    try:
        f = open(path)
        content = f.read()
        final = str(len(content)) + "\n" + content
        cs.send(final.encode())
        f.close()

    except:
        # file does not exist
        res = "-1"
        cs.send(res.encode())
    
    cs.close()


s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("localhost",7777))
s.listen(5)
i=0
while (1==1):
    i=i+1
    cs,addr=s.accept()
    t=Thread(target=f,args=(cs,i,))
    t.start()
