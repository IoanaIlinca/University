from Iterator import Iterator
import pickle
class RepoError(Exception):
    pass

class Repo(object):
    def __init__(self, initialList):
        # constructor, initialList - list
        self._list = Iterator(initialList)

    @property
    def list(self):
        # returns the list
        return self._list.getData()
    
    def add_element(self, element):
        # adds an element to the list
        if element in self._list.getData():
            raise RepoError("id already exists!\n")
        self._list.getData().append(element)

    def get_all(self):
        # gets all the elements from the list
        elementList = []
        elementList[:] = self._list.getData()
        return elementList

    def remove_element(self, key):
        # removes an element with the id key - integer from the list
        if key not in self._list.getData():
            raise RepoError("id does not exist\n")
        i = 0
        while i<(len(self._list.getData())):
            if self._list.getData()[i] == key:
                del self._list.getData()[i]
                i -= 1
            i += 1

    def search(self, key):
        # searches for an element by its key - integer
        if key not in self._list.getData():
            raise RepoError("id does not exist\n")
        for currentElement in self._list.getData():
            if currentElement == key:
                return currentElement

    def all_to_str(self):
        # converts the list to a string
        finalString = ""
        for element in self._list.getData():
            finalString += str(element)+"\n"
        return finalString

class fileRepo(Repo):
    
    
    def __init__(self,filename,read_object,write_object):
        self.__filename = filename
        self.__read_object = read_object
        self.__write_object = write_object
        Repo.__init__(self, [])
        
    def __read_all_from_file(self):
        self._list = []
        with open(self.__filename,"r") as readFile:
            lines = readFile.readlines()
            for line in lines:
                line = line.strip()
                if line != "":
                    obj = self.__read_object(line)
                    self._list.append(obj)

    def __write_all_to_file(self):
        with open(self.__filename,"w") as writeFile:
            writeFile.seek(0)
            for obj in self._list:
                line = self.__write_object(obj)
                writeFile.write(line+"\n")
            writeFile.truncate()

    @property
    def list(self):
        # returns the list
        self.__read_all_from_file()
        self.__write_all_to_file()
        return self._list
        
    
    def add_element(self, element):
        # adds an element to the list
        self.__read_all_from_file()
        if element in self._list:
            raise RepoError("id already exists!\n")
        self._list.append(element)
        self.__write_all_to_file()

    def get_all(self):
        # gets all the elements from the list
        self.__read_all_from_file()
        elementList = []
        elementList[:] = self._list
        return elementList

    def remove_element(self, key):
        # removes an element with the id key - integer from the list
        self.__read_all_from_file()
        if key not in self._list:
            raise RepoError("id does not exist\n")
        i = 0
        while i<(len(self._list)):
            if self._list[i] == key:
                del self._list[i]
                i -= 1
            i += 1
        
        self.__write_all_to_file()


    def search(self, key):
        # searches for an element by its key - integer
        self.__read_all_from_file()
        if key not in self._list:
            raise RepoError("id does not exist\n")
        for currentElement in self._list:
            if currentElement == key:
                return currentElement

    def all_to_str(self):
        # converts the list to a string
        self.__read_all_from_file()
        finalString = ""
        for element in self._list:
            finalString += str(element)+"\n"
        return finalString


class pickleRepo(Repo):
    
    
    def __init__(self, filename):                  #,read_object,write_object):
        self.__filename = filename
        #self.__read_object = read_object
        #self.__write_object = write_object
        Repo.__init__(self, [])
        
    def __read_all_from_file(self):
        self._list = []
        with open(self.__filename, "rb") as readFile:
            try:
                self._list = pickle.load(readFile)
            except EOFError:
                pass

    def __write_all_to_file(self):
        with open(self.__filename,"wb") as writeFile:
            writeFile.seek(0)
            pickle.dump(self._list, writeFile)

    @property
    def list(self):
        # returns the list
        self.__read_all_from_file()
        self.__write_all_to_file()
        return self._list
        
    
    def add_element(self, element):
        # adds an element to the list
        self.__read_all_from_file()
        if element in self._list:
            raise RepoError("id already exists!\n")
        self._list.append(element)
        self.__write_all_to_file()

    def get_all(self):
        # gets all the elements from the list
        self.__read_all_from_file()
        elementList = []
        elementList[:] = self._list
        return elementList

    def remove_element(self, key):
        # removes an element with the id key - integer from the list
        self.__read_all_from_file()
        if key not in self._list:
            raise RepoError("id does not exist\n")
        i = 0
        while i<(len(self._list)):
            if self._list[i] == key:
                del self._list[i]
                i -= 1
            i += 1
        
        self.__write_all_to_file()


    def search(self, key):
        # searches for an element by its key - integer
        self.__read_all_from_file()
        if key not in self._list:
            raise RepoError("id does not exist\n")
        for currentElement in self._list:
            if currentElement == key:
                return currentElement

    def all_to_str(self):
        # converts the list to a string
        self.__read_all_from_file()
        finalString = ""
        for element in self._list:
            finalString += str(element)+"\n"
        return finalString
