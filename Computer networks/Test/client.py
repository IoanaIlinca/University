import socket, sys
from threading import Thread

socketUDP = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # udp

socketUDP.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
socketUDP.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

socketUDP.settimeout(0.2) # so the socket does not block when trying to recieve data
 

def serverConnection():
   
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    s.connect(("192.168.1.8", 7000))
    
    while (True):
        connection = s.recv(1024)
        if (connection):
            print (connection.decode())
        s.send(b'Hi!')
    s.close()


def inputFunction():
    message = ""
    

    while (message != "QUIT"):
    
        message = input("Enter your message here: ")
        if (message == "QUIT"):
            #s.send(message.encode())
            #print("Client %s has disconnected" % str(ip))
            exit(0)
        socketUDP.sendto(message.encode(), ('<broadcast>', 7777))
    #s.close()
    socketUDP.close()



#ip, port = s.getsockname()
#print("Client %s has connected" % str(ip))



clientUDP = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # udp

clientUDP.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
clientUDP.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

clientUDP.bind(("", 7777))

message = ""
connected_clients = [("192.168.1.8", 7000)]
t = Thread(target = serverConnection, args= ())
t.start()
inputThread = Thread(target=inputFunction, args = ())
inputThread.start()
while (True):
    
    data, addr = clientUDP.recvfrom(1024)
    print(data.decode())
    

clientUDP.close()
