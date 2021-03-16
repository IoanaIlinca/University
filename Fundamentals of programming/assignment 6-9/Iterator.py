class Iterator:
    def __init__(self, initialList):
        self.__data = initialList
        self.__index = -1

    def __iter__(self):
        #iterates the class
        return iter(self.__data)

    def __next__(self):
        #gets the next item
        if self.__index > len(self.__data) - 1:
            raise StopIteration
        else:
            self.__index += 1
        return self.__data[self.__index]

    def __len__(self):
        # returns the length
        return len(self.__data)

    def __setitem__(self, index, val):
        # setter for an item
        self.__data[index] = val

    def __getitem__(self, index):
        # getter for an item
        return self.__data[index]

    def append(self, var):
        # adds an item to the list
        self.__data.append(var)

    def __delitem__(self, index):
        # delets an item
        del self.__data[index]

    def remove(self, index):
        # delets an item
        del self.__data[index]

    def pop(self, key):
        # pops the last item
        self.__data.pop(key - 1)

    def clear(self):
        # clears the list
        self.__data.clear()

    def getData(self):
        # returns the list
        return self.__data

    def gnomeSort(self, givenData, comparisonFunction):
        # the comparion function returns true if a >= b
        index = 0
        while index < len(givenData):
            if index == 0 or comparisonFunction(givenData[index], givenData[index - 1]) == True:
                index += 1
            else:
                auxilliaryVariable = givenData[index]
                givenData[index] = givenData[index - 1]
                givenData[index - 1] = auxilliaryVariable
                index -= 1
        return givenData


    def filter(self, givenData, filterCriteria):
        # filters the data with a given criteria
        temporaryData = []
        for object in givenData:
            if filterCriteria(object) == True:
                temporaryData.append(object)
        return temporaryData