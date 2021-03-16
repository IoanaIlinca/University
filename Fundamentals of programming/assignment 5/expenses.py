class expense:
    __day = 0
    __amount = 0
    __typ = "" # private - convention
    
    def __init__(self, day, amount, typ):
        #class constructor
        #input: day, amount - integers, typ - string
        self.__day = day
        self.__amount = amount
        self.__typ = typ

    def getDay(self):
        #returns the value of the day - integer
        return self.__day

    def getAmount(self):
        #returns the value of the amount - integer
        return self.__amount

    def getType(self):
        #returns the type - string
        return self.__typ
    
    def setDay(self, day):
        #input: day - integer
        #sets the value of __day of the variable to day
        self.__day = day

    def setAmount(self, amount):
        #input: amount - integer
        #sets the value of __amount of the variable to amount
        self.__day = day

    def setType(self, typ):
        #input: typ - string
        #sets the value of __typ of the variable to typ
        self.__day = day


    

    
    
