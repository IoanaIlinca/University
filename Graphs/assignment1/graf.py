class Graf(object):
    def __init__(self, n):
        # creates a graph with n vertices
        self.__dict = {}
        for i in range(n):
            self.__dict[i] = []

    def add_edge(self, x, y):
        if self.is_edge(x, y) == False:
            self.__dict[x].append(y)

    def is_edge(self, x, y):
        return y in self.__dict[x]

    def is_vertex(self, x):
        return x in self.__dict.keys()

    def add_vertex(self, x):
        if not self.is_vertex(x):
            self.__dict[x] = []

    def remove_edge(self, x, y):
        self.__dict[x].remove(y)

    def remove_vertex(self, x):
        for lis in self.__dict:
            if x in lis:
                lis.remove(x)
        del self.__dict[x]