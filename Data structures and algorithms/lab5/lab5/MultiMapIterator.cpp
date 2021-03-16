#include "MultiMapIterator.h"
#include "MultiMap.h"

/// BC = Theta(1), WC = Theta(m), AC = O(m) - m -capacity
MultiMapIterator::MultiMapIterator(MultiMap& c): col(c) {
	if (col.numberOfElements > 0)
    {
        current = 0;
        while (col.multiMap[current].first == NULL_TKEY&& current < col.m)
            current++;
        return;
    }
    current = -1;
}

/// BC = WC = AC = Theta(1)
TElem MultiMapIterator::getCurrent() const{
    if (!valid())
    {
        exception ex;
        throw ex;
    }
    if (valid())
        return col.multiMap[current];
	return NULL_TELEM;
}

/// BC = WC = AC = Theta(1)
bool MultiMapIterator::valid() const {
	if (current >= 0 && current < col.m)
        return true;
	return false;
}

/// BC = Theta(1), WC = Theta(m), AC = O(m) - m -capacity
void MultiMapIterator::next() {
    if (!valid())
    {
        exception ex;
        throw ex;
    }
    if (col.numberOfElements == 0)
    {
        current = -1;
        return;
    }
	if(valid() && col.numberOfElements != 0)
    {
        current++;
        while (col.multiMap[current].first == NULL_TKEY && current < col.m)
            current++;
    }
}

/// BC = Theta(1), WC = Theta(m), AC = O(m) - m -capacity
void MultiMapIterator::first() {
	current = 0;
    while (col.multiMap[current].first == NULL_TKEY && current < col.m)
        current++;
}

/// BC = WC = AC = Theta(1)
TElem MultiMapIterator::remove() {
    exception ex;
    if (!valid())
    {
        throw ex;
    }
    TElem returnValue = col.multiMap[current];
    col.multiMap[current].first = NULL_TKEY;
    next();

    return returnValue;
}

