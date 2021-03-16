#include "SetIterator.h"
#include "Set.h"
#include<exception>
using namespace std;


SetIterator::SetIterator(const Set& m) : set(m)
{
	first();
}


void SetIterator::first() {

	if (set.arraySize > 0)
	{
		currentNode = set.head;
	}
	else
	{
		currentNode = -1;
	}
}


void SetIterator::next() {
    exception ex;
	if (!valid())
	{
		throw ex;
	}
	currentNode = set.elems[currentNode].getNext();
}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	exception ex;
	if (!valid())
	{
		throw ex;
	}
	return set.elems[currentNode].getElement();
}

bool SetIterator::valid() const {
	//TODO - Implementation
	return currentNode != -1;
}



