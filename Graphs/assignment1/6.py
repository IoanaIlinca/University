import random
import time
start_time = time.time()


class MatrGraph:
	"""A directed graph, represented by adjacency matrix.
	Vertices are numbers from 0 to n-1"""
	
	def __init__(self, n):
		"""Creates a graph with n vertices (numbered from 0 to n-1)
		and no edges"""
		self._matr = []
		for i in range(n):
			self._matr.append([])
			for j in range(n):
				self._matr[i].append(False)
				
	def parseX(self):
		"""Returns an iterable containing all the vertices"""
		nrOfVertices = len(self._matr)
		return range(nrOfVertices)
		
	def parseNout(self, x):
		"""Returns an iterable containing the outbound neighbours of x"""
		list =[]
		for i in range(len(self._matr[x])):
			if self._matr[x][i] :
				list.append(i)
		return list
		
	def parseNin(self,x):
		"""Returns an iterable containing the inbound neighbours of x"""
		list =[]
		for i in range(len(self._matr)):
			if self._matr[i][x] :
				list.append(i)
		return list
		
	def isEdge(self,x,y):
		"""Returns True if there is an edge from x to y, False otherwise"""
		return self._matr[x][y]
	
	def addEdge(self,x,y):
		"""Adds an edge from x to y.
		Precondition: there is no edge from x to y"""
		self._matr[x][y] = True
		
class DictGraph:
	"""A directed graph, represented as a map from each vertex to
	the set of outbound neighbours"""

	def __init__(self,n):
		"""Creates a graph with n vertices (numbered from 0 to n-1)
		and no edges"""
		self._dict={}
		for i in range(n):
			self._dict[i]=[]
			
	def parseX(self):
		"""Returns an iterable containing all the vertices"""
		return self._dict.keys()

	def parseNout(self,x):
		"""Returns an iterable containing the outbound neighbours of x"""
		return self._dict[x]

	def parseNin(self,x):
		"""Returns an iterable containing the inbound neighbours of x"""
		list=[]
		for i in self._dict.keys():
			if x in self._dict[i]:
				list.append(i)
		return list

	def isEdge(self,x,y):
		"""Returns True if there is an edge from x to y, False otherwise"""
		return y in self._dict[x]

	def addEdge(self,x,y):
		"""Adds an edge from x to y.
		Precondition: there is no edge from x to y"""
		self._dict[x].append(y)	
	
	
class DoubleDictGraph:
	"""A directed graph, represented as two maps,
	one from each vertex to the set of outbound neighbours,
	the other from each vertex to the set of inbound neighbours"""

	def __init__(self,n):
		"""Creates a graph with n vertices (numbered from 0 to n-1)
		and no edges"""
		self._dictOut={}
		self._dictIn = {}
		for i in range(n):
			self._dictOut[i]=[]
			self._dictIn[i] = []
			
	def parseX(self):
		"""Returns an iterable containing all the vertices"""
		return self._dictOut.keys()

	def parseNout(self,x):
		"""Returns an iterable containing the outbound neighbours of x"""
		return self._dictOut[x]

	def parseNin(self,x):
		"""Returns an iterable containing the inbound neighbours of x"""
		return self._dictIn[x]	

	def isEdge(self,x,y):
		"""Returns True if there is an edge from x to y, False otherwise"""
		return y in self._dictOut[x]

	def addEdge(self,x,y):
		"""Adds an edge from x to y.
		Precondition: there is no edge from x to y"""
		self._dictOut[x].append(y)
		self._dictIn[y].append(x)
	
def accessible(g, s):
	"""Returns the set of vertices of the graph g that are accessible
	from the vertex s"""
	acc = set()
	acc.add(s)
	list = [s]
	while len(list) > 0:
		x = list[0]
		list = list[1 : ]
		for y in g.parseNout(x):
			if y not in acc:
				acc.add(y)
				list.append(y)
	return acc
	
	


	

def initMyGraph(ctor):
	"""Constructs and returns a hard-coded sample graph.
	ctor must be a callable that gets the number of vertices and
	creates a graph with the given number of vertces and with no edges"""
	g = ctor(5)
	g.addEdge(0,1)
	g.addEdge(1,0)
	g.addEdge(1,1)
	g.addEdge(1,2)
	g.addEdge(4,0)
	g.addEdge(4,2)
	return g
	
def initRandomGraph(ctor,n,m):
	"""Constructs and returns a randomly generated graph
	with n vertices and m edges.
	ctor must be a callable that gets the number of vertices and
	creates a graph with the given number of vertces and with no edges"""
	g=ctor(n)
	addedEdges=0
	while addedEdges < m:
		x=random.randrange(0,n)
		y=random.randrange(0,n)
		if not g.isEdge(x,y):
			g.addEdge(x,y)
			addedEdges+=1
	return g
		
def run():
	g = initMyGraph(DoubleDictGraph)
	for x in g.parseX():
		print ("%s:" % x)
		for y in g.parseNin(x):
			print ("%s <- %s" % (x, y))
		
			
run()

#g = initRandomGraph(DoubleDictGraph, 1000, 10000)
#g = initRandomGraph(DoubleDictGraph, 10000, 100000)
g = initRandomGraph(DoubleDictGraph, 100000, 1000000)
g.parseNout(5)
print("Process finished --- %s seconds ---" % (time.time() - start_time))