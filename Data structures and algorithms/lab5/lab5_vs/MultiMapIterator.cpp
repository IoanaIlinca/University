#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	if (col.numberOfElements > 0)
    {
        current = 0;
        while (col.multiMap[current] == NULL_TELEM && current < col.m)
            current++;
        return;
    }
    current = -1;
}

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

bool MultiMapIterator::valid() const {
	if (current >= 0 && current < col.m)
        return true;
	return false;
}

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
        while (col.multiMap[current] == NULL_TELEM && current < col.m)
            current++;
    }
}

void MultiMapIterator::first() {
	current = 0;
    while (col.multiMap[current] == NULL_TELEM && current < col.m)
        current++;
}

