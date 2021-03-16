def function(n):
    """
        The function determines if a number is prime or 
        Input: a number n (integer)
        Output: True if the number is prime and false otherwise
    """
    d = 2
    while (d < n - 1) and n % d > 0:
        d += 1
    return d >= n - 1


def test_function_prime():
    assert function(13) == True, "The number is prime, but the function thinks it isn't"

def test_function_not_prime():
    assert function(4) == False, "The number is not prime, but the function thinks it is"

test_function_prime()
test_function_not_prime()