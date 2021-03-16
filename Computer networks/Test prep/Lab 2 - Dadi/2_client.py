import socket

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("localhost",7777))
path = "/media/sf_Computer_Networks/hello_2.txt"
s.send(path.encode())
#print (s.recvfrom(100)[0].decode())
res = s.recv(100).decode()
print (res)
if res != -1:
    fileContent = res.split()
    print(fileContent)
    path += "-copy"
    print(path)
    f = open(path, "w")
    for i in range (1, len(fileContent)):
        f.write(fileContent[i])
        f.write(" ")
    f.close()

s.close()
