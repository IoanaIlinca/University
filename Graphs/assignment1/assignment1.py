import copy
import time
import random
import sys
import threading
from collections import defaultdict
start_time = time.time()

#sys.setrecursionlimit(150000)

#threading.stack_size(2**27)
#threading.Thread(target=run).start()

class Graph(object):
    def __init__(self):
        '''
            Constructor
            # all nodes are integers
            Input:
            graphOut - dictionary - keys are nodes, each element is a list of destinations
            graphIn  - dictionary - keys are nodes, each element is a list of sources
            costs - dictionary - keys - tuples (source, destionation) of nodes, element - the cost (integer)
        '''
        self.__graphOut = defaultdict(list)
        self.__graphIn = defaultdict(list)
        self.__costs = defaultdict(list)

    def checkIsNode(self, node):
        """
            Checks if a node is in the graph or not
            Input: node - integer
            Output: True if it in the graph False otherwise
        """
        if node in self.__graphOut:
            return True
        return False

    def parseOutBoundNodes(self, node):
        lis = []
        for y in self.__graphOut[node]:
            lis.append(y)
        return lis

    def parseInBoundNodes(self, node):
        lis = []
        for y in self.__graphIn[node]:
            lis.append(y)
        return lis

    def getNumberOfNodes(self):
        '''
            Returns the number of nodes
            Input: none
            Output: integer
        '''
        return len(self.__graphOut)

    def getNumberOfEdges(self):
        '''
            Returns the number of edges
            Input: none
            Output: integer
        '''
        return len(self.__costs)

    def parseNodes(self):
        '''
            Returns a list of all nodes in the graph
            Input: none
            Output: a list of nodes
        '''
        listOfnodes = []
        for key in self.__graphOut:
            print(key)
            listOfnodes.append(int(key))
        return listOfnodes
    
    def getInDegreeOfNode(self, node):
        '''
            Returns the number of edges that have the given node as destination or False if it is not in the graph
            Input: node - integer
            Output: positive integer or False
        '''
        if self.checkIsNode(node) == False:
            return False
        
        return len(self.__graphIn[node])

    def parseOutBoundEdges(self, node):
        '''
            Parses the outbound edges of a given node
            Input: node - integer
            Output: list of tuples of integer (source, destionation, cost)
        '''
        copy = []
        for neighbour in self.__graphOut[node]:
            copy.append((node, neighbour, self.__costs[(node, neighbour)]))
        return copy

    def getOutDegreeOfNode(self, node):
        '''
        returns the number of edges that have the given node as source or False if it is not in the graph
        input: node
        output: positive integer or False
        '''
        if self.checkIsNode(node) == False:
            return False
        return len(self.__graphOut[node])

    def parseInBoundEdges(self, node):
        '''
            Parses the inbound edges of a given node
            Input: node - integer
            Output: list of tuples of integer (source, destionation, cost)
        '''
        copy = []
        for source in self.__graphIn[node]:
            copy.append((source, node, self.__costs[(source, node)]))
        return copy

    def addNode(self, node):
        '''
            Adds an isolated node to the graph if t is not already in the graphs
            Input: node - integer
        '''
        if self.checkIsNode(node) == False:
            self.__graphIn[node] = []
            self.__graphOut[node] = []

    def removeNode(self, node):
        '''
        removes a node and all associated edges if it is in the graph
        input : node
        output:none
        '''
        if self.checkIsNode(node) == False:
            print("Invalid node")
        else:
            for key in self.__graphOut:
                if int(key) == node:
                    continue
                if node in self.__graphOut[key]:
                    del self.__costs[(key, node)]
                    self.__graphOut[key].remove(node)

            for key in self.__graphIn:
                if int(key) == node:
                    continue
                if node in self.__graphIn[key]:
                    del self.__costs[(node, key)]
                    self.__graphIn[key].remove(node)

            
            del self.__graphIn[node]
            del self.__graphOut[node]
            


    def checkIsEdge(self, source, destination):
        '''
        checks if an edge given by its source and destination is in the graph
        input: source, destination
        output: True or False
        '''
        if source == destination:
            return False
        if self.checkIsNode(source) == False or self.checkIsNode(destination) == False:
            return False
        if destination in self.__graphOut[source]:
            return True
        return False 

    def addEdge(self, source, destination, cost):
        '''
        adds a certain edge given by its source and destination and sets its cost if it is not laready in the graph 
        input: source, destination, cost
        output: None
        '''
        if self.checkIsEdge(source, destination) == False and source != destination:
            self.__graphOut[source].append(destination)
            self.__graphIn[destination].append(source)
            self.__costs[(source, destination)] = cost
    
    def removeEdge(self, source, destination):
        '''
        removes a certain edge given by its source and destination if it is in the graph 
        input: source, destination
        output: None
        '''
        if self.checkIsEdge(source, destination) == False:
            print("No such edge")
        else:
            del self.__costs[(source, destination)]
            self.__graphOut[source].remove(destination)
            self.__graphIn[destination].remove(source)

    def getEdgeCost(self, source, destination):
        '''
            returns the cost attached to a certain edge
            input: source, destination (integers)
            output: cost (integer)
        '''
        if self.checkIsEdge(source, destination) == False:
            return -1
        return self.__costs[(source, destination)]

    def modifyEdge(self, source, destination, newCost):
        '''
        modifies a certain edge given by its source and destination with then new cost if it exists
        input: source, destination, new cost
        output: none
        '''
        if self.checkIsEdge(source, destination) == True:
            self.__costs[(source, destination)] = newCost

    def copyGraph(self):
        '''
        creates a static copy of he graph
        input: none
        output: graph
        '''
        """
        newGraph = Graph()
        newGraph.__graphIn = copy.deepcopy(self.__graphIn)
        newGraph.__graphOut = copy.deepcopy(self.__graphOut)
        newGraph.__ = copy.deepcopy(self.__costs)
        """
        return copy.deepcopy(self)

    def readFromFile(self, fileName):
        '''
        reads a graph from a file
        input: the name of a file formatted as follows:
        first line numberOfnodes numberOfEdges
        next numberOfEdges-th lines triplets <node1 node2 cost>

        '''
        with open(fileName,"r") as f:
            firstLine = f.readline()
            data = firstLine.split()
            n = int(data[0])
            m = int(data[1])
            for i in range(0, n):
                #print(i)
                self.addNode(int(i))

            for i in range(0, m):
                line = f.readline()
                line = line.split()
                self.addEdge(int(line[0]), int(line[1]), int(line[2]))

    def writeToFile(self, fileName):
        '''
        reads a graph from a file
        input: the name of a file formatted as follows:
        first line numberOfnodes numberOfEdges
        next numberOfEdges-th lines triplets <node1 node2 cost>

        '''
        with open(fileName,"w") as f:
            f.write(str(self.getNumberOfNodes()) + ' ' + str(self.getNumberOfEdges()) + '\n\n')
            f.write(str(self))



    def __str__(self):
        string = ""
        for key in self.__costs:
            string += "Source: "
            string += str(key[0])
            string += " destination: "
            string += str(key[1])
            string += " cost: "
            string += str(self.__costs[key])
            string += '\n'
        
        return string

    def BFS(self, s, end): 
  
        # Mark all the vertices as not visited 
        visited = [False] * (len(self.__graphIn) + 1) 
        #print(visited)
        # Create a queue for BFS 
        queue = [] 
        fathers = {}
        for node in self.__graphIn:
            fathers[node] = -1
  
        # Mark the source node as  
        # visited and enqueue it 
        queue.append(s) 
        visited[s] = True
        fathers[s] = -1

        while queue: 
  
            # Dequeue a vertex from  
            # queue and print it 
            s = queue.pop(0) 
            #print (s, end = " ") 
  
            # Get all adjacent vertices of the 
            # dequeued vertex s. If a adjacent 
            # has not been visited, then mark it 
            # visited and enqueue it 
            for i in self.__graphOut[s]:
                if visited[i] == False: 
                    fathers[i] = s
                    queue.append(i) 
                    visited[i] = True
        
        node = end
        if(fathers[end] == -1):
            print("The node could not be reached")
            return
        string = ""
        cnt = -1
        while node != -1:
            cnt += 1
            string = str(node) + " " + string
            node = fathers[node]

        print(cnt)
        print(string)

    

    def DFSUtil(self, s, visited, dict):
        stack = []
        stack.append(s)  
  
        while (len(stack)):  
            # Pop a vertex from stack and print it  
            s = stack[-1]  
            stack.pop() 
  
            # Stack may contain same vertex twice. So  
            # we need to print the popped item only  
            # if it is not visited.  
            if (not visited[s]):  
                #print(s,end=' ') 
                visited[s] = True 
  
            # Get all adjacent vertices of the popped vertex s  
            # If a adjacent has not been visited, then push it  
            # to the stack.  
            for node in dict[s]:  
                if (not visited[node]):  
                    stack.append(node)   

        '''
        # Mark the current node as visited and print it 
        visited[v]= True
        #Recur for all the vertices adjacent to this vertex 
        for i in dict[v]: 
            if visited[i] == False: 
                self.DFSUtil(i, visited, dict) 
        '''
  
  
    def fillOrder(self, v, visited, stack, dict): 
        '''
        stack = []
        stack.append(s)  
  
        while (len(stack)):  
            # Pop a vertex from stack and print it  
            s = stack[-1]  
            stack.pop() 
  
            # Stack may contain same vertex twice. So  
            # we need to print the popped item only  
            # if it is not visited.  
            if (not visited[s]):  
                #print(s,end=' ') 
                visited[s] = True 

            
            # Get all adjacent vertices of the popped vertex s  
            # If a adjacent has not been visited, then push it  
            # to the stack.  
            for node in dict[s]:  
                if (not visited[node]):  
                    stack.append(node) 
            mainStack.append(s)
                    
            

        '''
        # Mark the current node as visited  
        visited[v]= True
        #Recur for all the vertices adjacent to this vertex 
        for i in dict[v]: 
            if visited[i]==False: 
                self.fillOrder(i, visited, stack, dict) 
        
        stack.append(v)
      
  
   
   
    # The main function that finds and prints all strongly 
    # connected components 
    def printSCCs(self): 
        cnt = 0
        stack = [] 

        visited =[False]*(len(self.__graphIn))

        for i in range(len(self.__graphIn)): 
            if visited[i]==False: 
                self.fillOrder(i, visited, stack, self.__graphOut) 
  
        
        visited =[False]*(len(self.__graphIn)) 
  
        while stack: 
            i = stack.pop() 
            if visited[i]==False: 
                cnt += 1
                self.DFSUtil(i, visited, self.__graphIn) 
                
        
        print(cnt)


def InitializeGraph(graph, numberOfNodes, numberOfEdges):
    if (numberOfEdges > ((numberOfNodes - 1) * numberOfNodes)):
        numberOfEdges = (numberOfNodes - 1) * numberOfNodes
        print("Maximum number of edges exceeded, the number of edges has been changed to: " + str(numberOfEdges))
        
    edges = []
    for i in range(1, numberOfNodes + 1):
        graph.addNode(i)
        for j in range(1, numberOfNodes + 1):
            if (i != j):
                edges.append((i, j))
            
    for i in range(0, numberOfEdges):         
        added = False
        while (added == False):
            edge = edges[random.randint(0, len(edges) - 1)]
            graph.addEdge(edge[0], edge[1], random.randint(1, 100))
            added = graph.checkIsEdge(edge[0], edge[1])
            edges.remove(edge)
            

def tests(): 
    
    g = Graph()
    # Test add 
    assert( g.checkIsNode(1) == False)
    g.addNode(1)
    assert(g.getNumberOfNodes() == 1)
    assert(g.checkIsNode(1) == True)

    

    # Test delete 
    g.removeNode(1)
    assert(g.checkIsNode(1) == False)
    assert(g.checkIsNode(3) == False)
    g.removeNode(3)
    assert(g.checkIsNode(3) == False)

    # Test add edge 
    assert(g.checkIsEdge(1, 2) == False)
    g.addNode(1)
    assert(g.checkIsEdge(1, 2) == False)
    g.addNode(2)
    assert(g.checkIsEdge(1, 2) == False)
    assert(g.getNumberOfEdges() == 0)
    g.addEdge(1, 2, 16)
    assert(g.getNumberOfEdges() == 1)
    assert(g.checkIsEdge(1, 2) == True)
    g.addEdge(2, 1, 18)
    assert(g.getNumberOfEdges() == 2)
    g.removeNode(1)

    g.addNode(1)
    g.addEdge(1, 2, 16)

    # Test modify edge 
    assert(g.getEdgeCost(1, 2) == 16)
    g.modifyEdge(1, 2, 10)
    assert(g.getEdgeCost(1, 2) == 10)
    assert(g.getEdgeCost(1, 3) == -1)

    # Test remove edge 
    g.removeEdge(1, 2)
    assert(g.checkIsEdge(1, 2) == False)
    assert(g.checkIsEdge(1, 3) == False)
    g.removeEdge(1, 3)
    assert(g.checkIsEdge(1, 3) == False)

   
    #Test copy graph
    g.addEdge(1, 2, 16)
    g2 = Graph()
    g2 = g.copyGraph()
    g2.modifyEdge(1, 2, 18)
    assert(g.getEdgeCost(1, 2) == 16)
    assert(g2.getEdgeCost(1, 2) == 18)
    g2 = g2.copyGraph()
    assert(g2.getEdgeCost(1, 2) == 18)
    g2 = g.copyGraph()
    assert(g.getEdgeCost(1, 2) == 16)
    assert(g2.getEdgeCost(1, 2) == 16)
    
    #Test parse nodes
    lis = g.parseNodes()
    assert(len(lis) == g.getNumberOfNodes())

    # Test in degree of node 
    assert(g.getInDegreeOfNode(1) == 0)
    assert(g.getInDegreeOfNode(2) == 1)
    assert(g.getInDegreeOfNode(3) == False)

    # Test out degree of node 
    assert(g.getOutDegreeOfNode(1) == 1)
    assert(g.getOutDegreeOfNode(2) == 0)
    assert(g.getOutDegreeOfNode(3) == False)

    # Test outbound edges
    g.addNode(3)
    g.addNode(4)
    g.addEdge(1, 3, 14)
    g.addEdge(1, 4, 15)
    edges = g.parseOutBoundEdges(1)
    assert(len(edges) == 3)

    # Test inbound edges
    g.addEdge(3, 2, 14)
    g.addEdge(4, 2, 15)
    edges = g.parseInBoundEdges(2)
    assert(len(edges) == 3)

    # Test constructor random graph 
    gr = Graph()
    InitializeGraph(gr, 12, 10)
    assert(gr.getNumberOfNodes() == 12)
    assert(gr.getNumberOfEdges() == 10)
    
    g4 = Graph()
    InitializeGraph (g4, 5, 60)
    assert(g4.getNumberOfNodes() == 5)    
    assert(g4.getNumberOfEdges() == 20)

    g5 = Graph()
    g5.readFromFile("E:/Faculta/sem 2/grafuri/assignment1/in.txt")
    g5.writeToFile("E:/Faculta/sem 2/grafuri/assignment1/out.txt")

    g6 = Graph()
    g6.addNode(0)
    g6.addNode(1)
    g6.addNode(2)
    g6.addNode(3)
    g6.addNode(4)
    g6.addEdge(0, 1, 0) 
    g6.addEdge(0, 2, 0) 
    g6.addEdge(1, 2, 0) 
    g6.addEdge(2, 0, 0) 
    g6.addEdge(2, 3, 0) 
    g6.addEdge(3, 3, 0)
    g6.addEdge(1, 4, 0)
    g6.BFS(2, 4)


def menu():
    g = Graph()
    print("You can do the following: print, createRandomGraph, addEdge, addNode, checkIsEdge, checkIsNode, getEdgeCost, getInDegreeOfNode, getOutDegreeOfNode, getNumberOfEdges, getNumberOfNodes, modifyEdge, readFromFile, removeEdge, removeNode, writeToFile, ShortestPath, StronglyConnectedComponents, exit\n")
    print("\n")
    print("Enter command: ")
    command = input()
    while (True):
    
        ok = False
        if (command == "addEdge"):
        
            ok = True
            source = int(input("source: "))
            destination = int(input("destination: "))
            cost = int(input("cost: "))
            g.addEdge(source, destination, cost)
        
        if (command == "addNode"):
        
            ok = True
            node = int(input("node: "))
            g.addNode(node)
        
        if (command == "checkIsEdge"):
        
            ok = True
            source = int(input("source: "))
            destination = int(input("destination: "))
            if (g.checkIsEdge(source, destination)):
                print("True")
            else:
                print("False")
        
        if (command == "checkIsNode"):
        
            ok = True
            node = int(input("node: "))
            if (g.checkIsNode(node)):
                print("True")
            else:
                print("False")
        
        if (command == "getEdgeCost"):
        
            ok = True
            source = int(input("source: "))
            destination = int(input("destination: "))
            print(g.getEdgeCost(source, destination))
        
        if (command == "getInDegreeOfNode"):
        
            ok = True
            node = int(input("node: "))
            print(g.getInDegreeOfNode(node))
            print(g.parseInBoundEdges(node))

        if (command == "getOutDegreeOfNode"):

            ok = True
            node = int(input("node: "))
            print(g.getOutDegreeOfNode(node))
            print(g.parseOutBoundEdges(node))
        
        if (command == "getNumberOfEdges"):
        
            ok = True
            print(g.getNumberOfEdges())
        
        if (command == "getNumberOfNodes"):
        
            ok = True
            print(g.getNumberOfNodes())
        
        if (command == "modifyEdge"):
        
            ok = True
            source = int(input("source: "))
            destination = int(input("destination: "))
            newCost = int(input("new cost: "))
            g.modifyEdge(source, destination, newCost)
        
        if (command == "readFromFile"):
        
            ok = True
            g.readFromFile("E:/Faculta/sem 2/grafuri/assignment1/graph10k.txt")
        
        if (command == "writeToFile"):
        
            ok = True
            g.writeToFile("E:/Faculta/sem 2/grafuri/assignment1/out.txt")
        
        if (command == "removeEdge"):
        
            ok = True
            source = int(input("source: "))
            destination = int(input("destination: "))
            g.removeEdge(source, destination)
        
        if (command == "removeNode"):
        
            ok = True
            node = int(input("node: "))
            g.removeNode(node)
        
        if (command == "createRandomGraph"):
            ok = True
            n = int(input("number of nodes: "))
            m = int(input("number of edges: "))
            InitializeGraph(g, n, m)

        if (command == "ShortestPath"):
            ok = True
            source = int(input("Source: "))
            destination = int(input("Destination: "))
            g.BFS(source, destination)

        if (command == "StronglyConnectedComponents"):
            ok = True
            g.printSCCs()
        
        if (command == "print"):
            ok = True
            print(g)
        
        if (command == "exit"):
            return

        if (ok == False):
            print("Wrong command!")

        print("\n")
        print("Enter command: ")
        command = input()
    
  
sys.setrecursionlimit(150000)

threading.stack_size(2**27)
threading.Thread(target=menu).start()
#tests()
#menu()
