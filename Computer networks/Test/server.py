import socket, sys, queue, select

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setblocking(0)
server.bind(('192.168.1.8', 7000)) # 192.168.1.4 server on VM, 192.168.1.8 server on windows
server.listen(5)

inputs = [server]
outputs = []
exceptions = []
messages = {}
connected_clients = []

while(inputs):
    readable, writable, exceptional = select.select(inputs, outputs, exceptions)

    for s in readable:
       
        if s is server:
            connection, client_address = s.accept()
            connection.setblocking(0)
            inputs.append(connection)
            ip, port = s.getsockname()
            connected_clients.append((ip, port))
            print(connected_clients)
            
            messages[connection] = queue.Queue()
        else:
            data = ""
            try:
                data = s.recv(1024).decode()
            except:
                ip, port = s.getsockname()
        
                connected_clients.remove((ip, port))
                print(connected_clients)
                readable.remove(s)
                if s in outputs:
                    outputs.remove(s)
            
                s.close()
                #del messages[s]
                #for conn in readable:
                    
                    #if (not conn._closed):
                        #conn.send(str(connected_clients).encode())
            if data != "":
                messages[s].put(data)
                if s not in outputs:
                    outputs.append(s)
            
            else:
                if s in outputs:
                    outputs.remove(s)
                inputs.remove(s)
                s.close()
                del messages[s]
            
        #s.send(str(connected_clients).encode())
        '''
        try:
            s.send(str(connected_clients).encode())
        except socket.error:
            ip, port = s.getsockname()
            #connected_clients.append((port, ip))
            connected_clients.remove((ip, port))
        '''

    for s in writable:
        try:
            next_message = messages[s].get_nowait()
        except queue.Empty:
            outputs.remove(s)
        else:
           if (next_message.decode() == "QUIT"):
               for c in inputs:
                   ip, port = s.getsockname()
                   message = "Client " + str(ip) + " has disconnected"
                   c.send(message.encode())
           

    for s in exceptional:
        inputs.remove(s)
        if s in outputs:
            outputs.remove(s)
       
        s.close()
        del messages[s]