import socket, sys, queue, select

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setblocking(0)
server.bind(('192.168.1.8', 7777)) # 192.168.1.4 server on VM, 192.168.1.8 server on windows
server.listen(5)

inputs = [server]
outputs = []
exceptions = []
messages = {}

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
            s.send(next_message)

    for s in exceptional:
        inputs.remove(s)
        if s in outputs:
            outputs.remove(s)
        s.close()
        del messages[s]