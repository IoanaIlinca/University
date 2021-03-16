import time
import socket
import subprocess
from threading import Thread


def f(cs, i):
    print ("Procesez client "+str(i))
    command = []
    string = cs.recv(100).decode()
    print(string)
    splitted = string.split(", ")
    command = []
    for i in range(1, len(splitted)):
        command.append(splitted[i].strip('\'[]"'))
    print (command)
    '''
    while (string != ""):
        command.append(string)
        print("*")
        string = cs.recv(100).decode()
    print (command)
    '''
    #print (type(string))
    #string.pop(0)
    #print (string)
    #time.sleep(10)
    #output = subprocess.check_output(command)
    time.sleep(5)

    result = subprocess.run(command, stdout=subprocess.PIPE)
    output = result.stdout
    rc = result.returncode
    print(rc)

    #print(output.decode())
    #cs.send(output)
    

    cs.send(output)
    cs.send(str(rc).encode())
    cs.close()


s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("0.0.0.0",7777))
s.listen(5)
i=0
while (1==1):
    i=i+1
    cs,addr=s.accept()
    t=Thread(target=f,args=(cs,i,))
    t.start()
    #time.sleep(10)
