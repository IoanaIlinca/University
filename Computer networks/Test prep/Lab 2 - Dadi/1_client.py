import socket
import sys

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1",7777)) 
s.send(str(sys.argv).encode())
'''
for i in range(1, len(sys.argv)):
    s.send(sys.argv[i].encode())
    print ('&')
print('I am here!')
s.send(b"")
print('Hereeee')
'''
#print (s.recvfrom(100)[0].decode())
#s.close()

res = s.recv(1000).decode()
print(res)
print (s.recv(10).decode())
#print ("Exit code: " + rc)
s.close()
