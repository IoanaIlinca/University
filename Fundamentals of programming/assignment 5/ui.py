import copy
from expenses import *
from services import *
from valid import *


class UI:
    __serv = services()
    
    def __init__(self):
        self.__serv = services()

    def set_initial_values(self):      
        self.__serv.addTolist(23, 200, "gas")
        self.__serv.addTolist(24, 30, "water")
        self.__serv.addTolist(2, 50, "gas")
        self.__serv.addTolist(3, 20, "electricity")
        self.__serv.addTolist(6, 22, "phone")
        self.__serv.addTolist(23, 50, "internet")
        self.__serv.addTolist(12, 40, "heating")
        self.__serv.addTolist(14, 40, "water")
        self.__serv.addTolist(30, 5, "gas")
        self.__serv.addTolist(20, 300, "phone")
        
        

    def print_expense(self):
        for i in self.__serv.getList():  
            print(i.getDay())
            print(i.getAmount())
            print(i.getType())
            print("\n")

    def add_expense(self):
        self.__serv.addToStack()
        day = input("Input day: ")
        if validateDay(day) == False:
            day = input("Wrong value! Input day: ")
        elif validateDay(day) != True:
            print(validateDay(day))
            day = input("Input day: ")

        amount = input("Input amount: ")

        if validateAmount(amount) == False:
            amount = input("Wrong value! Input amount: ")
        elif validateAmount(amount) != True:
            print(validateAmount(amount))
            amount = input("Input amount: ")

        typ = input("Input type: ")

        self.__serv.addTolist(day, amount, typ)

    def filter_expense(self):
        self.__serv.addToStack()
        value = int(input("Input value: "))
        li = []
        for i in range(0, len(self.__serv.getList())):
            if int(self.__serv.getList()[i].getAmount()) > value:
                li.append(self.__serv.getList()[i])

        self.__serv.modifyList(li)
                
     

    def undo(self):
        if (len(self.__serv.getStack()) > 0):
            self.__serv.modifyList(self.__serv.getStack().pop())

        
def run():
    lis = []
    stack = []
    serv = services()
    ui = UI()

    ui.set_initial_values()

    while True:
            cmd = input(">>>")
            if cmd == "exit":
                exit()

            if cmd == "show":
                ui.print_expense()
                
            elif cmd == "add":
                ui.add_expense()

            elif cmd == "filter":
                ui.filter_expense()

            elif cmd == "undo":
                ui.undo()
                
            else:
                print("invalid command!\n")



run()
    
