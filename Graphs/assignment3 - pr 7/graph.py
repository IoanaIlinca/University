import copy
import time
import random

from collections import defaultdict


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
        self.__floydWarshall = defaultdict(list)
        self.__floydWarshallPrevious = defaultdict(list)
        self.__bonus1 = defaultdict(list)
        self.__doneFW = False

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
        self.__graphOut = defaultdict(list)
        self.__graphIn = defaultdict(list)
        self.__costs = defaultdict(list)
        self.__floydWarshall = defaultdict(list)
        self.__doneFW = False
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

    def getPathFloydWarshall(self, start, finish):
        string = ""
        string = str(finish) + string
        prev = self.__floydWarshallPrevious[start][finish]
        while prev != start:
            string = str(prev) + ' ' + string
            prev = self.__floydWarshallPrevious[start][prev]

        string = '\n' + str(start) + ' ' + string
        return string

    def getFloydWarshall(self, start, finish):
        print(start, finish)
        if self.__floydWarshall[start][finish] != 0x3f3f3f3f:
            return (str(self.__floydWarshall[start][finish]) + self.getPathFloydWarshall(start, finish))
        return "There is no path between those nodes"

    def bonus1(self, start, finish):
        return self.__bonus1[start][finish]

    


    def doneFloydWarshall(self):
        return self.__doneFW

    def FloydWarshall(self):
        for key in self.__graphIn:
            self.__floydWarshall[key] = [0x3f3f3f3f] * (len(self.__graphIn) + 1)
            self.__floydWarshallPrevious[key] = [-1] * (len(self.__graphIn) + 1)
            self.__bonus1[key] = [0] * (len(self.__graphIn))
            self.__floydWarshall[key][key] = 0

        
        for edge in self.__costs:
            self.__floydWarshall[edge[0]][edge[1]] = self.__costs[edge]
            self.__floydWarshallPrevious[edge[0]][edge[1]] = int(edge[0])
            self.__bonus1[edge[0]][edge[1]] = 1
        '''
        for i in self.__floydWarshall:
                for j in self.__floydWarshall:
                    print(self.__floydWarshall[i][j], end=" ")
                print ()

        for i in self.__floydWarshall:
                for j in self.__floydWarshall:
                    print(self.__floydWarshallPrevious[i][j], end=" ")
                print ()
        for i in self.__floydWarshall:
                for j in self.__floydWarshall:
                    print(self.__bonus1[i][j], end=" ")
                print ()
        print()
        '''
        for k in self.__graphIn:
            '''
            for i in self.__floydWarshall:
                for j in self.__floydWarshall:
                    print(self.__floydWarshall[i][j], end=" ")
                print ()

            for i in self.__floydWarshall:
                for j in self.__floydWarshall:
                    print(self.__floydWarshallPrevious[i][j], end=" ")
                print ()
            
            for i in self.__floydWarshall:
                for j in self.__floydWarshall:
                    print(self.__bonus1[i][j], end=" ")
                print ()
            print()
            '''
            for i in self.__graphIn:
                for j in self.__graphIn:
                    if self.__floydWarshall[i][j] == self.__floydWarshall[i][k] + self.__floydWarshall[k][j] and k != i and k != j and i != j:
                        self.__bonus1[i][j] += self.__bonus1[i][k] * self.__bonus1[k][j]
                        #print(i, k, j)
                    if self.__floydWarshall[i][j] > self.__floydWarshall[i][k] + self.__floydWarshall[k][j] and i != j:
                         self.__floydWarshallPrevious[i][j] = self.__floydWarshallPrevious[k][j]
                         self.__bonus1[i][j] = self.__bonus1[i][k] * self.__bonus1[k][j]
                    self.__floydWarshall[i][j] = min(self.__floydWarshall[i][j], self.__floydWarshall[i][k]+ self.__floydWarshall[k][j])

        
        self.__doneFW = True
        



            

