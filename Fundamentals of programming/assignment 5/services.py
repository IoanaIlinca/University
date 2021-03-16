import copy
from expenses import *

class services:
    __lis = []
    __stack = []

    def __init__(self):
        self.__lis = []
        self.__stack = []

    def getList(self):
        return self.__lis

    def getStack(self):
        return self.__stack

    def modifyList(self, li):
        self.__lis = copy.deepcopy(li)

    def addTolist(self, day, amount, typ):
        self.__lis.append(expense(day, amount, typ))
        

    def addToStack(self):
        self.__stack.append(copy.deepcopy(self.__lis))
        
    def addExpense(self, day, amount, typ):
        NewExpense = expense(day, amount, typ)
        self.__list.append(NewExpense)
        return NewExpense
