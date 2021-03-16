import socket, sys, time, random, datetime, string
from threading import Thread

group_port = int(sys.argv[1])
leader = int(sys.argv[2])
random.seed()

def processQuestions(cs, q):
    string = cs.recv(100).decode()
    if(string != ""):
        print ("\nProcessing new question:")
        
        print(string)
        s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        s.connect(("127.0.0.1",5555))
        s.send(string.encode())

        serverUDP = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # udp

        serverUDP.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        serverUDP.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

        serverUDP.settimeout(0.2) # so the socket does not block when trying to recieve data
        serverUDP.settimeout(0.2)
        answer = "Question: " + string + "\nAnswer: " + s.recv(500).decode() + "\n"
        serverUDP.sendto(answer.encode(), ("<broadcast>", group_port))


        s.close()

    cs.close()

def recieveQuestions():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind(("0.0.0.0", group_port))
    s.listen(5)
    i=0
    while (1==1):
        i=i+1
        cs,addr=s.accept()
        t=Thread(target=processQuestions,args=(cs,i, ))

        t.start()
    s.close()

def broadcastLeader():
    

    recieveQuestionsThread = Thread(target=recieveQuestions,args=())
    recieveQuestionsThread.start()
    
    serverUDP = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # udp

    serverUDP.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    serverUDP.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

    serverUDP.settimeout(0.2) # so the socket does not block when trying to recieve data
    message = b'leader'

    while True:
        serverUDP.sendto(message, ("<broadcast>", group_port))
        #print('Message sent!')
        time.sleep(3)

def questions():
    while(True):
        s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        s.connect(("127.0.0.1", group_port))
        time.sleep(3)
        number = random.random()
        if number > 0.5:
            question = ''.join(random.choice(string.ascii_letters) for i in range(random.randrange(1, 50, 1)))
            print(question)
            s.send(question.encode())
        s.close()

def regularStudent():
    questionThread=Thread(target=questions,args=())
    questionThread.start()
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # udp

    client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    client.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

    client.bind(("", group_port))

    while True:
        data, addr = client.recvfrom(1024)
        print("recieved message: %s" % data.decode())




if (leader):
    #leaderThread=Thread(target=broadcastLeader,args=())
    #leaderThread.start()
    broadcastLeader()
else:
    for i in range(0, 5):
        studentThread=Thread(target=regularStudent,args=())
        studentThread.start()
    #regularStudent()
    
