import socket, sys, queue, select

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setblocking(0)
server.bind(('192.168.1.8', 7777)) # 192.168.1.4 server on VM, 192.168.1.8 on windows
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
            string = next_message.decode()
            character = string[len(string) - 1]

            final = []
            occurence = string.find(character, 0, len(string) - 1)
            while (occurence != -1):
                final.append(occurence)
                occurence = string.find(character, occurence + 1, len(string) - 1)
            
            #final.pop()
            s.send(str(final).encode())

    for s in exceptional:
        inputs.remove(s)
        if s in outputs:
            outputs.remove(s)
        s.close()
        del messages[s]