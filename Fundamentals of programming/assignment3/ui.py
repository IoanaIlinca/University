from service import *
from model import *
from valid import *
import copy

def ui_read_apartment():
    x = int(input("insert apartment number: "))
    while True:
        if verify_number(x):
            return x
        else:
            x = int(input("Wrong input! Insert apartment number: "))
            
def ui_read_type():
    typ = input("insert type: ")
    while True:
        if (verify_type(typ)):
            return typ
        else:
            typ = input("insert correct type: ")

def ui_add(inp, ui, ap, stack):
    li = copy.deepcopy(ap)
    stack.append(li)
    if ui == True:
        number = ui_read_apartment()
        typ = ui_read_type()
        amount = int(input("insert amount: "))
    else:
        number = inp[1]
        typ = inp[2]
        amount = inp[3]
        
    srv_add_expense(ap, number, typ, amount)

def ui_print(inp, ui, ap, stack):
    for i in range(1, len(ap)):
        if(get_expense(ap, i, "total") != 0):
            print(i)
            print(get_number(ap, i))
            print("\n")

def ui_print_apartment(inp, ui, ap, stack):
    if ui == True:
        x = ui_read_apartment()
    else:
        x = inp[1]

    print(x)
    var = get_number(ap, x)
    print(var)
    print("\n")

def ui_remove(inp, ui, ap, stack):
    li = copy.deepcopy(ap)
    stack.append(li)
    if ui == True:
        number = ui_read_apartment()
    else:
        number = int(inp[1])
    remove_expenses(ap, number)
    

def ui_remove_range(inp, ui, ap, stack):
    li = copy.deepcopy(ap)
    stack.append(li)
    if ui == True:
        number1 = ui_read_apartment()
        number2 = ui_read_apartment()
    else:
        number1 = int(inp[1])
        number2 = int(inp[3])
    
    for i in range(number1 + 1, number2):
        remove_expenses(ap, i)
    

def ui_remove_type(inp, ui, ap, stack):
    li = copy.deepcopy(ap)
    stack.append(li)
    if ui == True:
        typ = ui_read_type()
    else:
        typ = inp[1]
    
    for i in range (1, 101):
        replace_expense(ap, i, typ, 0)

def ui_replace(inp, ui, ap, stack):
    li = copy.deepcopy(ap)
    stack.append(li)
    if ui == True:
        number = ui_read_apartment()
        typ = input("insert type: ")
        amount = input("insert amount: ")
    else:
        number = inp[1]
        typ = inp[2]
        amount = inp[4]
    replace_expense(ap, number, typ, amount)

def ui_print_amount(inp, ui, ap, stack):
    if ui == True:
        op = input("insert operand: ")
        x = input("insert amount: ")
    else:
        op = inp[1]
        x = inp[2]
    while True:
        if op == "<":
            for i in range(1, 101):
                if(get_expense(ap, i, "total") < int(x)):
                    print(i)
                    print('\n')
            break
        elif op == ">":
                for i in range(1, 101):
                    if(get_expense(ap, i, "total") > int(x)):
                        print(i)
                        print('\n')
                break
        elif op == "=":
                for i in range(1, 101):
                    if(get_expense(ap, i, "total") == int(x)):
                        print(i)
                        print('\n')
                break
        else:
            print("invalid operand!\n")
            op = input("insert operand: ")

def ui_sum(inp, ui, ap, stack):
    if ui == True:
        typ = input("Insert type: ")
    else:
        typ = inp[1]
    s = 0
    while True:
        if typ in ['water', 'gas', 'electricity', 'heating' , 'others']:
            for i in range(1, 101):
                s = s + get_expense(ap, i, typ)
            break
        else:
            typ = input("Invalid type! Insert type: ")

    print(s)

def ui_max(inp, ui, ap, stack):
    if ui == True:
        no = input("Insert apartment number: ")
    else:
        no = inp[1]
    for typ in ['water', 'gas', 'electricity', 'heating', 'others']:
        if get_expense(ap, no, typ) != 0:
            print("Apartment " + str(no) + " has the highest expense for " + typ + " equal to " + str(get_expense(ap, no, typ)) + "\n")

    print("Apartment " + str(no) + " has no other expenses")


def ui_sort_apartment(inp, ui, ap, stack):
    index = [[0, 0]]
    for i in range(1, 101):
        index.append([i, get_expense(ap, i, "total")])

    for i in range(1, 101):
        for j in range(i + 1, 101):
            if index[i][1] > index[j][1]:
                aux = index[i][0] 
                index[i][0] = index[j][0]
                index[j][0] = aux
                aux = index[i][1]
                index[i][1] = index[j][1]
                index[j][1] = aux
                
    for i in range(1, 101):
        if index[i][1] != 0:
            print(str(index[i][0]) + ' ' + str(index[i][1]))

def ui_sort_type(inp, ui, ap, stack):
    lis = []
    water = 0
    gas = 0
    electricity = 0
    heating = 0
    others = 0
    for i in range(1, 101):
        water = water + get_expense(ap, i, "water")
        gas = gas + get_expense(ap, i, "gas")
        electricity = electricity + get_expense(ap, i, "electricity")
        heating = heating + get_expense(ap, i, "heating")
        others = others + get_expense(ap, i, "others")

    lis.append(["water", water])
    lis.append(["gas", gas])
    lis.append(["electricity", electricity])
    lis.append(["heating", heating])
    lis.append(["others", others])

    for i in range(0, 5):
        for j in range(i + 1, 5):
            if lis[i][1] > lis[j][1]:
                aux = lis[i][0] 
                lis[i][0] = lis[j][0]
                lis[j][0] = aux
                aux = lis[i][1]
                lis[i][1] = lis[j][1]
                lis[j][1] = aux

    print(lis)

def ui_filter_type(inp, ui, ap, stack):
    li = copy.deepcopy(ap)
    stack.append(li)
    if ui == True:
        typ = input("Introoduce type: ")
    else:
        typ = inp[1]
    while True:
        if typ in ['water', 'gas', 'electricity', 'heating' , 'others']:
            for i in range(1, 101):
                aux  = get_expense(ap, i, typ)
                remove_expenses(ap, i)
                add_expense(ap, i, typ, aux)
            break
        else:
            typ = input("Invalid type! Insert type: ")
    
    
def ui_filter_value(inp, ui, ap, stack):
    li = copy.deepcopy(ap)
    stack.append(li)
    if ui == True:
        amount = int(input("Enter amount: "))
    else:
        amount = int(inp[1])
    for i in range(1, 101):
        for typ in ['water', 'gas', 'electricity', 'heating' , 'others']:
            aux = get_expense(ap, i, typ)
            if aux > amount:
                replace_expense(ap, i, typ, 0)

def ui_undo(inp, ui, ap, stack):
    if len(stack) > 0:
        for i in range(1, 101):
            for typ in ['water', 'gas', 'electricity', 'heating' , 'others']:
                replace_expense(ap, i, typ, stack[len(stack) - 1][i][typ])

        stack.pop()
    else:
        print("No more actions to undo!")
                

def select_ui():
    s = input("Type \'command\' to use commands and \'menu\' to use a menu\n")

    while True:
        if s == "command":
            return False
        elif s == "menu":
            return True
        else:
            s = input("Invalid input! Type \'command\' to use commands and \'menu\' to use a menu\n")

def ui_command():
    Input = input("Introduce a command ")
    return Input.split(' ')




def run():
    ap = []
    commands = {
    "add": ui_add,
    "remove": ui_remove,
    "remove_range": ui_remove_range,
    "remove_type": ui_remove_type,
    "replace": ui_replace,
    "list": ui_print,
    "list_apartment": ui_print_apartment,
    "list_amount": ui_print_amount,
    "sum": ui_sum,
    "max": ui_max,
    "sort_apartment": ui_sort_apartment,
    "sort_type": ui_sort_type,
    "filter_type": ui_filter_type,
    "filter_value": ui_filter_value,
    "undo": ui_undo
    }

    set_innit_ap(ap)
    set_innit_values(ap)
    stack = []
    ui = select_ui()
    if ui == True:
        while True:
            cmd = input(">>>")
            if cmd == "exit":
                exit()

            if cmd in commands:
                try:
                    commands[cmd](cmd, ui, ap, stack)
                except Exception as ex:
                    print(str(ex))
            else:
                print("invalid command!\n")
    else:
        while True:
            cmd = ui_command()
            if cmd[0] == "exit":
                exit()
            if cmd[0] in ["add", "sum", "max", "undo", "replace"]:
                try:
                    commands[cmd[0]](cmd, ui, ap, stack)
                except Exception as ex:
                    print(str(ex))

            if cmd[0] == 'remove':
                if len(cmd) == 2:
                    if cmd[1] in ['water', 'gas', 'electricity', 'heating' , 'others']:
                        commands["remove_type"](cmd, ui, ap, stack)
                    else:
                        try:
                            cmd[1] == int(cmd[1])
                            commands["remove"](cmd, ui, ap, stack)
                        except Exception as ex:
                            print(str(ex))
                elif len(cmd) == 4:
                    commands["remove_range"](cmd, ui, ap, stack)
                else:
                    print("invalid command!\n")

            if cmd[0] == 'list':
                if len(cmd) == 1:
                    commands["list"](cmd, ui, ap, stack)
                elif len(cmd) == 2:
                    commands["list_apartment"](cmd, ui, ap, stack)
                else:
                    commands["list_amount"](cmd, ui, ap, stack)

            if cmd[0] == 'sort':
                if len(cmd) != 2:
                    print("invalid command!\n")
                elif cmd[1] == "apartment":
                    commands["sort_apartment"](cmd, ui, ap, stack)
                elif cmd[1] == "type":
                    commands["sort_type"](cmd, ui, ap, stack)
                else:
                    print("invalid command!\n")

            if cmd[0] == 'filter':
                if len(cmd) != 2:
                    print("invalid command!\n")
                elif cmd[1] in ['water', 'gas', 'electricity', 'heating' , 'others']:
                    commands["filter_type"](cmd, ui, ap, stack)
                else:
                    try:
                        cmd[1] == int(cmd[1])
                        commands["filter_value"](cmd, ui, ap, stack)
                    except Exception as ex:
                        print(str(ex))

        


run()
