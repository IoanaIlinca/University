import copy


class Graph(object):
    def __init__(self, graphIn = {}, graphOut = {}, costs = {}):
        '''
            Constructor
            # all nodes are integers
            Input:
            graphOut - dictionary - keys are nodes, each element is a list of destinations
            graphIn  - dictionary - keys are nodes, each element is a list of sources
            costs - dictionary - keys - tuples (source, destionation) of nodes, element - the cost (integer)
        '''
        self.__graphOut = graphOut  
        self.__graphIn = graphIn
        self.__costs = costs

    def checkIsNode(self, node):
        """
            Checks if a node is in the graph or not
            Input: node - integer
            Output: True if it in the graph false otherwise
        """
        if node in self.__graphOut:
            return True
        return False

    def getNumberOfNodes(self):
        '''
            Returns the number of nodes
            Input: none
            Output: integer
        '''
        return len(self.__graphOut)

    def parseNodes(self):
        '''
            Returns a list of all nodes in the graph
            Input: none
            Output: a list of nodes
        '''
        listOfnodes = []
        for key in self.__graphOut:
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
        
        return len(self.__graphIn)

    def parseOutBoundEdges(self, node):
        '''
            Parses the outbound edges of a given node
            Input: node - integer
            Output: list of tuples of integer (source, destionation, cost)
        '''
        copy = []
        for neighbour in self.__graphOut[node]:
            copy.append(node, neighbour, self.__costs[(node, neighbour)])
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
            copy.append(source, node, self.__costs[(source, node)])
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
        output: true or false
        '''
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
        if self.checkIsEdge(source, destination) == False:
            self.__graphOut[source].append(destination)
            self.__graphOut[destination].append(source)
            self.__costs[(source, destination)] = cost
    
    def removeEdge(self, source, destination):
        '''
        renmoves a certain edge given by its source and destination if it is in the graph 
        input: source, destination
        output: None
        '''
        if self.checkIsEdge(source, destination) == False:
            print("No such edge")
        else:
            del self.__costs[(source, destination)]
            self.__graphOut[source].remove(destination)
            self.__graphOut[destination].remove(source)

    """
    def searchEdge(self, source, destination):
        '''
        searches if a certain edge given by its source and destination is in the graph 
        input: source, destination
        output: True or False
        '''
        if destination in self._succesors[source]:
            return True
        return False
    """

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
        copyGraphIn = copy.deepcopy(self.__graphIn)
        copyGraphOut = copy.deepcopy(self.__graphOut)
        copyCosts = copy.deepcopy(self.__costs)
        return Graph(copyGraphIn, copyGraphOut, copyCosts)

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
            for i in range(n):
                self.__graphIn[i] = []
                self.__graphOut[i] = []

            lines = f.readlines()
            for line in lines:
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

'''
graph = Graph()
print(graph.checkIsNode(1)) 
graph.addNode(1)
print(graph.checkIsNode(1))   
graph.addNode(2)
graph.addNode(3)
graph.addEdge(1, 2, -3)
graph.addEdge(1, 3, -5)
graph.addEdge(2, 3, -1)
print(graph)

graph2 = graph.copyGraph()
graph2.removeEdge(1, 3)
'''
graph2 = Graph()
graph2.readFromFile("graph1k.txt")
graph2.writeToFile("out.txt")

#print(graph2._edges)
#print(graph2._succesors)
#print(graph2._predecessors)

