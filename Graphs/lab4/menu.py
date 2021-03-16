from graph import Graph
import random



def InitializeGraph(graph, numberOfNodes, numberOfEdges):
    if (numberOfEdges > ((numberOfNodes - 1) * numberOfNodes)):
        numberOfEdges = (numberOfNodes - 1) * numberOfNodes
        print("Maximum number of edges exceeded, the number of edges has been changed to: " + str(numberOfEdges))
        
    edges = []
    for i in range(numberOfNodes):
        graph.addNode(i)
        for j in range(numberOfNodes):
            if (i != j):
                edges.append((i, j))
            
    for i in range(0, numberOfEdges):         
        added = False
        while (added == False):
            edge = edges[random.randint(0, len(edges) - 1)]
            graph.addEdge(edge[0], edge[1], random.randint(1, 100))
            added = graph.checkIsEdge(edge[0], edge[1])
            edges.remove(edge)

def menu():
    g = Graph()
    print("You can do the following: print, createRandomGraph, addEdge, addNode, checkIsEdge, checkIsNode, getEdgeCost, getInDegreeOfNode, getOutDegreeOfNode, getNumberOfEdges, getNumberOfNodes, modifyEdge, readFromFile, removeEdge, removeNode, writeToFile, ShortestPath, StronglyConnectedComponents, Floyd-Warshall, bonus1, Kruskal, exit\n")
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
            string = ""
            string = input("Enter file name: ")
            g.readFromFile(string)
        
        if (command == "writeToFile"):
        
            ok = True
            g.writeToFile("out.txt")
        
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

        if (command == "Floyd-Warshall"):
            ok = True
            source = int(input("Source: "))
            destination = int(input("Destination: "))
            #print(g.doneFloydWarshall())
            #if g.doneFloydWarshall() == False:
            g.FloydWarshall()
            #print(g.doneFloydWarshall())
            #print("Finished")
            print(g.getFloydWarshall(source, destination))

        if (command == "Kruskal"):
            ok = True
            g.KruskalMST()
            
        if (command == "bonus1"):
            ok = True
            source = int(input("Source: "))
            destination = int(input("Destination: "))
            #print(g.doneFloydWarshall())
            #if g.doneFloydWarshall() == False:
            g.FloydWarshall()
            #print(g.doneFloydWarshall())
            #print("Finished")
            print(g.getFloydWarshall(source, destination))
            print(g.bonus1(source, destination))
        
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

