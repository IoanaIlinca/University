from expenses import *
from services import *

def testInnit():
    NewExpense = expense(24, 200, "electricity")
    
    assert(NewExpense.getDay() == 24)
    assert(NewExpense.getAmount() == 200)
    assert(NewExpense.getType() == "electricity")


def runAllTests():
    testInnit()
    
