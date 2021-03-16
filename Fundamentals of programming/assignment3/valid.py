from model import *

def verify_number(x):
    if int(x) <= 100 and int(x) >= 1:
        return True
    else:
        return False

def verify_type(x):
    if x in ["water", "heating", "electricity", "gas", "others"]:
        return True

    return False

