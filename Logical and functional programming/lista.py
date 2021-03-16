

class Nod:
    def __init__(self, e):
        self.e = e
        self.urm = None
    
class Lista:
    def __init__(self):
        self.prim = None
        

'''
test equality
'''
def testEquality(list1, list2):
    if list1.prim == None and list2.prim == None:
        return True
    if list1.prim == None or list2.prim == None:
        return False
    if list1.prim.e != list2.prim.e:
        return False
    return testEquality(list1.prim.urm, list2.prim.urm)
    #return True

'''
crearea unei liste din valori citite pana la 0
'''
def creareLista():
    lista = Lista()
    lista.prim = creareLista_rec()
    return lista

def creareLista_rec():
    x = int(input("x="))
    if x == 0:
        return None
    else:
        nod = Nod(x)
        nod.urm = creareLista_rec()
        return nod
    
'''
tiparirea elementelor unei liste
'''
def tipar(lista):
    tipar_rec(lista.prim)
    
def tipar_rec(nod):
    if nod != None:
        print (nod.e)
        tipar_rec(nod.urm)


        

'''
program pentru test
'''
        
def main():
    list = creareLista()
    tipar(list)
    list2 = creareLista()
    tipar(list2)
    print(testEquality(list, list2))
    
main() 
    
    
    
    
    