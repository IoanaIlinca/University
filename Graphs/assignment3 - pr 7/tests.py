from graph import Graph
from menu import InitializeGraph


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
    g6.addEdge(0, 1, 4) 
    g6.addEdge(0, 2, 20) 
    g6.addEdge(1, 2, 16) 
    g6.addEdge(2, 0, 15) 
    g6.addEdge(2, 3, 1) 
    g6.addEdge(3, 3, 3)
    g6.addEdge(1, 4, 22)
    g6.BFS(2, 4)

    g7 = Graph()
    g7.addNode(0)
    g7.addNode(1)
    g7.addNode(2)
    g7.addNode(3)
    g7.addNode(4)
    g7.addNode(5)
    g7.addEdge(0, 1, 3) 
    g7.addEdge(0, 2, 2) 
    g7.addEdge(1, 2, 1) 
    g7.addEdge(1, 4, 5) 
    g7.addEdge(2, 1, 4) 
    g7.addEdge(2, 3, 3) 
    g7.addEdge(3, 0, 5) 
    g7.addEdge(4, 2, 5) 
    g7.addEdge(4, 5, 2) 
    g7.addEdge(5, 2, 1) 
    g7.addEdge(5, 3, 4) 
    g7.addEdge(5, 4, 4) 
    g7.FloydWarshall()
