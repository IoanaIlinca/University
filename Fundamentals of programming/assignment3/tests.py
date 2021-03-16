from service import *
from model import *


def test_set_innit_ap(lis):
    #tests the set innit app function
    #input: lis - list, usually empty
    #output: -
    set_innit_ap(lis)
    assert(get_expense(lis, 12, "gas") == 0)
    assert(get_expense(lis, 15, "water") == 0)
    assert(get_expense(lis, 22, "heating") == 0)
    replace_expense(lis, 12, "gas", 200)
    assert(get_expense(lis, 12, "gas") == 200)

def test_set_innit_values(lis):
    #tests the set innit app function
    #input: lis - list
    #output: -
    set_innit_values(lis)
    assert(get_expense(lis, 12, "gas") == 200)
    assert(get_expense(lis, 15, "water") == 100)
    assert(get_expense(lis, 47, "electricity") == 750)


def run_all_tests():
    #tests functions
    test_list = []
    test_set_innit_ap(test_list)
    test_set_innit_values(test_list)
