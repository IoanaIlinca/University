import select, socket, sys, queue

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.setblocking(0)
s.bind(("0.0.0.0",5555))
s.listen(5)

i = [s]
o = []

while i:
    r, w, e = select.select(i, o, [])
    print ("Select")
    print (r)
    for ss in r:
        if ss == s:
            cs, addr = s.accept()
            print (addr)
            i.append(cs) # pun cs in lista de socketuri
            print (i)
        else:
            print (ss.recv(20))

    for ss in e:
        ss.close()
        i.remove(ss)