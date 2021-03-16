#include <iostream>
#include <fstream>
#include <map>
#include <tuple>
#include <list>
#include <vector>
#include <assert.h>
#include <time.h>
#include <cstdlib>
using namespace std;

ifstream fin("graph1k.txt");
ofstream fout("grapthOut.out");


class Graph{
//public:
private:
    /*
        all nodes are integers
        graphOut - dictionary - keys are nodes, each element is a list of destinations
        graphIn - dictionary - keys are nodes, each element is a list of sources
        costs - dictionary - keys - tuples(source, destionation) of nodes, element - the cost(integer)
    */
    map <int, list<int>> graphIn;
    map <int, list<int>> graphOut;
    map <tuple <int, int>, int> costs;
public:
    /*Constructor*/
    Graph()
    {

    }

    /*Constructor with parameters - generates a random graph */
    Graph(int numberOfNodes, int numberOfEdges)
    {
        if (numberOfEdges > ((numberOfNodes - 1) * numberOfNodes))
        {
            numberOfEdges = (numberOfNodes - 1) * numberOfNodes;
            cout << "Maximum number of edges exceeded, the number of edges has been changed to: " << numberOfEdges;
        }
        
        vector<tuple<int, int>> edges;
        for (int i = 0; i < numberOfNodes; i++)
        {
            addNode(i);
            for (int j = 0; j < numberOfNodes; j++)
                if (i != j)
                    edges.push_back(make_tuple(i, j));
        }
            

        unsigned long j1;
        srand((unsigned)time(NULL));
        for (int i = 1; i <= numberOfEdges; i++)
        {
            
            bool added = false;
            while (!added)
            {
                int position = rand() % edges.size();
                int source = get<0>(edges[position]);
                int destination = get<1>(edges[position]);
                edges.erase(edges.begin() + position);
                int cost = (rand() % 100 + 1);
                addEdge(source, destination, cost);
                added = checkIsEdge(source, destination);
            }
            
        }
            

    }

    Graph(const Graph& g)
    {
        this->costs = g.costs;
        this->graphIn = g.graphIn;
        this->graphOut = g.graphOut;
    }

    
    /* Checks if a node is in the graph or not
       Returns true if it in the graph false otherwise
     */
    bool checkIsNode(int node)
    {
        if (graphOut.find(node) != graphOut.end())
            return true;
        return false;
    }
        
    /*
        Returns a list of all the outbound nodes of a given node (copy - default in c++)
    */
    
    list<int> parseOutBoundNodes(int node)
    {
        return this->graphOut[node];
    }
       
    /*
        Returns a list of all the inbound nodes of a given node (copy - default in c++)
    */

    list<int> parseInBoundNodes(int node)
    {
        return this->graphIn[node];
    }
    
    /*Returns the number of nodes*/
    int getNumberOfNodes()
    {
        return graphIn.size();
    }
    
    /* Returns a list of all nodes in the graph */

    list<int> parseNodes()
    {
        list<int> listOfNodes;
        for (map <int, list<int>>::const_iterator it = graphIn.begin(); it != graphIn.end(); it++)
        {
            listOfNodes.push_back(it->first);
        }
            
        return listOfNodes;
    }
    
    /*Returns the number of edges that have the given node as destination or -1 if it is not in the graph*/
    int getInDegreeOfNode(int node)
    {
        if (checkIsNode(node) == false)
            return -1;

        return graphIn[node].size();
    }

    
    /* Returns a list of all the outbound edges of a given node */
    list<tuple<int, int, int>> parseOutBoundEdges(int node)
    {
        list<tuple <int, int, int>> OutBoundEdges;
        for (list<int>::const_iterator it = graphOut[node].begin(); it != graphOut[node].end(); ++it)
            OutBoundEdges.push_back(make_tuple(node, *it, costs[make_tuple(node, *it)]));
        return OutBoundEdges;
    }

     

    /*Returns the number of edges that have the given node as source or -1 if it is not in the graph*/
    int getOutDegreeOfNode(int node)
    {
        if (checkIsNode(node) == false)
            return -1;

        return graphOut[node].size();
    }

    /* Returns a list of all the inbound edges of a given node */
    list<tuple<int, int, int>> parseInBoundEdges(int node)
    {
        list<tuple <int, int, int>> InBoundEdges;
        for (list<int>::const_iterator it = graphIn[node].begin(); it != graphIn[node].end(); ++it)
            InBoundEdges.push_back(make_tuple(*it, node, costs[make_tuple(*it, node)]));
        return InBoundEdges;
    }


    /*
       Adds an isolated node to the graph if t is not already in the graphs
       Input: node - integer
    */
    void addNode(int node)
    {
        if (checkIsNode(node) == false)
        {
            this->graphIn[node];
            this->graphOut[node];
        }
            
    }
        
    /*
        Removes a node and all associated edges if it is in the graph
        input : node
    */  
    void removeNode(int node)
    {
        if (this->checkIsNode(node) == false)
            return;
        else
        {
            for (auto element : this->graphIn[node])
            {
                this->graphOut[element].remove(node);
                this->costs.erase(make_tuple(element, node));
            }
            for (auto element : this->graphOut[node])
            {
                this->graphIn[element].remove(node);
                this->costs.erase(make_tuple(node, element));
            }
            this->graphIn.erase(node);
            this->graphOut.erase(node);
            
        }
    }



    /*
        checks if an edge given by its source and destination is in the graph
        input: source, destination
        output: true if it is or false otherwise
    */
    bool checkIsEdge(int source, int destination)
    {
        if (source == destination)
            return false;
        if (checkIsNode(source) == false || checkIsNode(destination) == false)
            return false;
        if (costs.find(make_tuple(source, destination)) != costs.end())
            return true;
        return false;
    }

    /* Returns the number of edges */
    int getNumberOfEdges()
    {
        return this->costs.size();
    }
        
    /*
        adds a certain edge given by its source and destination and sets its cost if it is not laready in the graph
        input: source, destination, cost
    */
    void addEdge(int source, int destination, int cost)
    {
        if (checkIsEdge(source, destination) == false && source != destination && checkIsNode(source) && checkIsNode(destination))
        {
            graphOut[source].push_back(destination);
            graphIn[destination].push_back(source);
            costs[make_tuple(source, destination)] = cost;
        }
            
    }
        

    /*
        removes a certain edge given by its source and destination if it is in the graph
        input: source, destination
    */

    void removeEdge(int source, int destination)
    {
        if (checkIsEdge(source, destination) == false)
            return;
        else
        {
            costs.erase(make_tuple(source, destination));
            graphOut[source].remove(destination);
            graphIn[destination].remove(source);
        }
        
    }

    /* Retuns the cost attached to a given edge, given its source and destination, or -1 if the edge does not exist */
    int getEdgeCost(int source, int destination)
    {
        if (checkIsEdge(source, destination))
            return costs[make_tuple(source, destination)];
        else return -1;
    }
        
    /* Modifies a certain edge given by its source and destination with then new cost if the edge exists */
    void modifyEdge(int source, int destination, int newCost)
    {
        if (checkIsEdge(source, destination) == true)
        {
            costs[(make_tuple(source, destination))] = newCost;
        }
    }
    
    /*Overdefines the = operator, provides a copy */
    Graph& operator=(const Graph& g)
    {
        if (this == &g)
            return *this;

        this->costs = g.costs;
        this->graphIn = g.graphIn;
        this->graphOut = g.graphOut;
        return *this;
    }

    /*
        reads a graph from a file
        file formatted as follows:
        first line numberOfnodes numberOfEdges
        next numberOfEdges-th lines triplets <node1 node2 cost>
    */

    void readFromFile()
    {
        int numberOfNodes, numberOfEdges;
        fin >> numberOfNodes >> numberOfEdges;
        for (int i = 0; i < numberOfNodes; i++)
        {
            addNode(i);
        }

        for (int i = 1; i <= numberOfEdges; i++)
        {
            int source, destination, cost;
            fin >> source >> destination >> cost;
            //cout << i << ' ';
            addEdge(source, destination, cost);
            //if (checkIsEdge(source, destination) == false)
                //cout << i << ' ' << source << ' ' << destination << ' ' << checkIsEdge(source, destination) << '\n';
        }
    }

    /* Writes graph to file */
    void writeToFile()
    {
        fout << *(this);
    }
    

    /* Defines the << operator */
    friend ostream& operator<<(ostream& os, const Graph& g)
    {
        for (map<tuple <int, int>, int>::const_iterator it = g.costs.begin(); it != g.costs.end(); ++it)
        {
            os << "Source: " << get<0>(it->first) << " destination: " << get<1>(it->first) << " cost: " << it->second << "\n";
        }
        return os;
    }
        
};

void Tests()
{
    Graph g;
    /* Test add */
    assert(g.checkIsNode(1) == false);
    g.addNode(1);
    assert(g.getNumberOfNodes() == 1);
    assert(g.checkIsNode(1) == true);

    /* Test delete */
    g.removeNode(1);
    assert(g.checkIsNode(1) == false);
    assert(g.checkIsNode(3) == false);
    g.removeNode(3);
    assert(g.checkIsNode(3) == false);

    /* Test add edge */
    assert(g.checkIsEdge(1, 2) == false);
    g.addNode(1);
    assert(g.checkIsEdge(1, 2) == false);
    g.addNode(2);
    assert(g.checkIsEdge(1, 2) == false);
    assert(g.getNumberOfEdges() == 0);
    g.addEdge(1, 2, 16);
    assert(g.getNumberOfEdges() == 1);
    assert(g.checkIsEdge(1, 2) == true);
    g.addEdge(2, 1, 18);
    assert(g.getNumberOfEdges() == 2);
    g.removeNode(1);

    g.addNode(1);
    g.addEdge(1, 2, 16);
    
    /* Test modify edge */
    assert(g.getEdgeCost(1, 2) == 16);
    g.modifyEdge(1, 2, 10);
    assert(g.getEdgeCost(1, 2) == 10);
    assert(g.getEdgeCost(1, 3) == -1);

    /* Test remove edge */
    g.removeEdge(1, 2);
    assert(g.checkIsEdge(1, 2) == false);
    assert(g.checkIsEdge(1, 3) == false);
    g.removeEdge(1, 3);
    assert(g.checkIsEdge(1, 3) == false);

    /*Test = operator and copy constructor*/
    g.addEdge(1, 2, 16);
    Graph g2 = g;
    g2.modifyEdge(1, 2, 18);
    assert(g.getEdgeCost(1, 2) == 16);
    assert(g2.getEdgeCost(1, 2) == 18);
    g2 = g2;
    assert(g2.getEdgeCost(1, 2) == 18);
    g2 = g;
    assert(g.getEdgeCost(1, 2) == 16);
    assert(g2.getEdgeCost(1, 2) == 16);

    /*Test parse nodes*/
    list<int> lis;
    lis = g.parseNodes();
    assert(lis.size() == g.getNumberOfNodes());

    /* Test in degree of node */
    assert(g.getInDegreeOfNode(1) == 0);
    assert(g.getInDegreeOfNode(2) == 1);
    assert(g.getInDegreeOfNode(3) == -1);

    /* Test out degree of node */
    assert(g.getOutDegreeOfNode(1) == 1);
    assert(g.getOutDegreeOfNode(2) == 0);
    assert(g.getOutDegreeOfNode(3) == -1);

    /* Test outbound edges*/
    list<tuple<int, int, int>> edges;
    g.addNode(3);
    g.addNode(4);
    g.addEdge(1, 3, 14);
    g.addEdge(1, 4, 15);
    edges = g.parseOutBoundEdges(1);
    assert(edges.size() == 3);

    /* Test inbound edges*/
    g.addEdge(3, 2, 14);
    g.addEdge(4, 2, 15);
    edges = g.parseInBoundEdges(2);
    assert(edges.size() == 3);

    /* Test constructor random graph */
    Graph g3(12, 10);
    assert(g3.getNumberOfNodes() == 12);
    assert(g3.getNumberOfEdges() == 10);

    Graph g4(5, 60);
    assert(g4.getNumberOfNodes() == 5);
    assert(g4.getNumberOfEdges() == 20);
}

void Menu()
{
    Graph g;
    string command;
    //g.addEdge();
    cout << "You can do the following: print, createRandomGraph, addEdge, addNode, checkIsEdge, checkIsNode, getEdgeCost, getInDegreeOfNode, getOutDegreeOfNode, getNumberOfEdges, getNumberOfNodes, modifyEdge, readFromFile, removeEdge, removeNode, writeToFile, exit\n";
    cout << "\n";
    cout << "Enter command: ";
    cin >> command;
    while (true)
    {
        bool ok = false;
        if (command == "addEdge")
        {
            ok = true;
            int source, destination, cost;
            cout << "source, destination, cost: ";
            cin >> source >> destination >> cost;
            g.addEdge(source, destination, cost);
        }
        if (command == "addNode")
        {
            ok = true;
            int node;
            cout << "node: ";
            cin >> node;
            g.addNode(node);
        }
        if (command == "checkIsEdge")
        {
            ok = true;
            int source, destination;
            cout << "source, destination: ";
            cin >> source >> destination;
            if (g.checkIsEdge(source, destination))
                cout << "True";
            else cout << "False";
        }
        if (command == "checkIsNode")
        {
            ok = true;
            int node;
            cout << "node: ";
            cin >> node;
            if (g.checkIsNode(node))
                cout << "True";
            else cout << "False";
        }
        if (command == "getEdgeCost")
        {
            ok = true;
            int source, destination;
            cout << "source, destination: ";
            cin >> source >> destination;
            cout << g.getEdgeCost(source, destination);
        }
        if (command == "getInDegreeOfNode")
        {
            ok = true;
            int node;
            cout << "node: ";
            cin >> node;
            cout << g.getInDegreeOfNode(node);
            cout << '\n';
            list<tuple<int, int, int>> edges;
            edges = g.parseInBoundEdges(node);
            for (list<tuple<int, int, int>>::const_iterator it = edges.begin(); it != edges.end(); it++)
                cout << "Source: " << get<0>(*it) << " destination: " << get<1>(*it) << " cost: " << get<2>(*it) << "\n";
        }
        if (command == "getOutDegreeOfNode")
        {
            ok = true;
            int node;
            cout << "node: ";
            cin >> node;
            cout << g.getOutDegreeOfNode(node);
            cout << '\n';
            list<tuple<int, int, int>> edges;
            edges = g.parseOutBoundEdges(node);
            for (list<tuple<int, int, int>>::const_iterator it = edges.begin(); it != edges.end(); it++)
                cout << "Source: " << get<0>(*it) << " destination: " << get<1>(*it) << " cost: " << get<2>(*it) << "\n";
        }
        if (command == "getNumberOfEdges")
        {
            ok = true;
            cout << g.getNumberOfEdges();
        }
        if (command == "getNumberOfNodes")
        {
            ok = true;
            cout << g.getNumberOfNodes();
        }
        if (command == "modifyEdge")
        {
            ok = true;
            int source, destination, newCost;
            cout << "source, destination, new cost: ";
            cin >> source >> destination >> newCost;
            g.modifyEdge(source, destination, newCost);
        }
        if (command == "readFromFile")
        {
            ok = true;
            g.readFromFile();
        }
        if (command == "writeToFile")
        {
            ok = true;
            g.writeToFile();
        }
        if (command == "removeEdge")
        {
            ok = true;
            int source, destination;
            cout << "source, destination: ";
            cin >> source >> destination;
            g.removeEdge(source, destination);
        }
        if (command == "removeNode")
        {
            ok = true;
            int node;
            cout << "node: ";
            cin >> node;
            g.removeNode(node);
        }
        if (command == "createRandomGraph")
        {
            ok = true;
            int n, m;
            cout << "number of nodes, number of edges: ";
            cin >> n >> m;
            Graph g2(n, m);
            g = g2;
        }
        
        if (command == "print")
        {
            ok = true;
            cout << g;
        }
            
        
        if (command == "exit")
            return;

        if (!ok)
            cout << "Wrong command!";
        cout << "\n";
        cout << "Enter command: ";
        cin >> command;
    }
        

  
}

int main()
{   
    //Tests();
    Menu();
    return 0;
}