def set_innit_ap(ap):
    #initializes the appartment list with 100 apartments with 0 expenses
    #each element is a dictionary
    #input: ap - list
    for i in range(0, 101):
        ap.append({
            "water": 0,
            "heating": 0,
            "gas": 0,
            "electricity": 0,
            "others": 0,
            "total": 0})

def set_innit_values(ap):
    #initializes some apartment values
    #each element is a dictionary
    #input: ap - list
    replace_expense(ap, 12, "gas", 200)
    replace_expense(ap, 15, "water", 100)
    replace_expense(ap, 20, "gas", 250)
    replace_expense(ap, 22, "heating", 70)
    replace_expense(ap, 47, "electricity", 750)
    replace_expense(ap, 12, "others", 30)
    replace_expense(ap, 55, "water", 20)
    replace_expense(ap, 63, "gas", 80)

def get_number(ap, number):
	#function that gets the apartment with the number number
	#input: ap - list, number - integer
	#output:  aprtment number number - dictionary
	return ap[int(number)]

def get_expense(ap, number, category):
        #function that gets the expense from a certain category
        #input: ap - list, number - integer, category - string
        #output: the exemnses in one category - integer
	return ap[int(number)][category]

def add_expense(ap, number, typ, amount):
        #adds to a certain expense category the set amount
        #input: ap - list, number - integer, typ - string, amount - integer
        #output: - 
        ap[int(number)][typ] = ap[int(number)][typ] + int(amount)
        ap[int(number)]["total"] = ap[int(number)]["total"] + int(amount)

def remove_expenses(ap, number):

        #sets all expenses to 0
        #input: ap - list, number - integer
        #output: -
        ap[int(number)]["water"] = 0
        ap[int(number)]["heating"] = 0
        ap[int(number)]["electricity"] = 0
        ap[int(number)]["gas"] = 0
        ap[int(number)]["others"] = 0
        ap[int(number)]["total"] = 0

def replace_expense(ap, number, typ, amount):
        #sets a certain expense category to the set amount
        #input: ap - list, number - integer, typ - string, amount - integer
        #output: -

        ap[int(number)]["total"] = ap[int(number)]["total"] - ap[int(number)][typ]
        ap[int(number)][typ] = int(amount)
        ap[int(number)]["total"] = ap[int(number)]["total"] + ap[int(number)][typ]
        






"""class apartment:

    __number = 0
    __amount = 0
    __category = ""

    def create_apartment(self,number, amount, category):
	#function that creates an apartment based on its hid, name and value
	#input: number, amount - integer, category - string
	#output: ap - an apartment having the number number, the amount amount in the specified category
        self.__number = number
        self.__amount = amount
        self.__category = category
        print(self.__number)
        return self"""
