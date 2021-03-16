#include "SetIterator.h"
#include "Set.h"
#include <stdexcept>

/// best case - teta(1), worst case - O(set.length), overall - O(set.length)
SetIterator::SetIterator(const Set& m) : set(m)
{
    for (int i = 0; i < set.length; i++)
    {
        if(set.sir[i] == true)
        {
            current = i;
            break;
        }
    }
}

/// best case - teta(1), worst case - O(set.length), overall - O(set.length)
void SetIterator::first() {
	for (int i = 0; i < set.length; i++)
    {
        if(set.sir[i] == true)
        {
            current = i;
            break;
        }
    }
}

/// best case - teta(1), worst case - O(set.length), overall - O(set.length)
void SetIterator::last() {
	for (int i = set.length - 1; i >= 0; i--)
    {
        if(set.sir[i] == true)
        {
            current = i;
            break;
        }
    }
}

/// best case - teta(1), worst case - O(set.length), overall - O(set.length)
void SetIterator::next() {
    if (current < 0 || current >= set.length)
        throw std::invalid_argument( "Already reached the last element" );
	for (int iter = current + 1; iter < set.length; iter++)
        if (set.sir[iter] == true)
        {
            current = iter;
            return;
        }
    current = set.length;
}

/// best case - teta(1), worst case - teta(1), overall - teta(1))
TElem SetIterator::getCurrent()
{
    if (valid() == false)
        throw "Invalid iterator!";

    return current + set.leftValue;
}

/// best case - teta(1), worst case - teta(1), overall - teta(1)
bool SetIterator::valid() const {
    if (set.numberOfElems == 0)
        return false;
    return (current >= 0 && current < set.length);
}

/// best case - teta(1),  worst case - teta(set.length), overall - O(set.length)
void SetIterator::previous() {
    if (current < 0 || current > set.length)
        throw std::invalid_argument( "Already reached the first element" );
	for (int iter = current - 1; iter >= 0; iter--)
        if (set.sir[iter] == true)
        {
            current = iter;
            return;
        }
    current = -1;
}



