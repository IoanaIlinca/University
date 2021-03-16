import socket, sys, queue, select, random, string

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setblocking(0)
server.bind(("127.0.0.1",5555)) # 192.168.1.4 server on VM, 192.168.1.8 on windows
server.listen(5)

inputs = [server]
outputs = []
exceptions = []
messages = {}
random.seed()

while(inputs):
    readable, writable, exceptional = select.select(inputs, outputs, exceptions)

    for s in readable:
        if s is server:
            connection, client_address = s.accept()
            connection.setblocking(0)
            inputs.append(connection)
            messages[connection] = queue.Queue()
        else:
            data = s.recv(1024)
            if data:
                messages[s].put(data)
                if s not in outputs:
                    outputs.append(s)
            
            else:
                if s in outputs:
                    outputs.remove(s)
                inputs.remove(s)
                s.close()
                del messages[s]

    for s in writable:
        try:
            next_message = messages[s].get_nowait()
        except queue.Empty:
            outputs.remove(s)
        else:
            answer = ''.join(random.choice(string.ascii_letters) for i in range(random.randrange(1, 50, 1)))
            array = []
            for i in range(random.randrange(1, 50, 1)):
                array.append(int(random.randrange(1, 150, 1)))
            answer += " " + str(array)
            print(answer)
            s.send(answer.encode())
            
            

    for s in exceptional:
        inputs.remove(s)
        if s in outputs:
            outputs.remove(s)
        s.close()
        del messages[s]