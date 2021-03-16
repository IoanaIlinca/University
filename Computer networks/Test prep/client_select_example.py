import socket
import sys

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",5555))
s.send(b"Salut")
#print (s.recv(100))
#print (s.recv(100))
s.close()
