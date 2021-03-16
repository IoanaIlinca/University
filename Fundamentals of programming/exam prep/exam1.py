"""
 Compute the sum of even elements in the given list
 input:
 l - the list of numbers
 output:
 The sum of the even elements in the list

 Raises TypeError if parameter l is not a Python list
 Raises ValueError if the list does not contain even numbers
"""

def function(l):
    if type(l) is not list:
        raise TypeError("This is not a list")


    l2 = []
    s = 0

    for i in l:
        if i % 2 == 0:
            l2.append(i)
            s += i

    if len(l2) == 0:
        raise ValueError("There are no even numbers")
    else:
        return s

l = [1, 3, 2, 4, 6]
print(function(l))