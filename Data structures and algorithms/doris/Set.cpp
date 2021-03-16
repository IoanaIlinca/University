#include "Set.h"
#include "SetITerator.h"

Set::Set()
{
	arraySize = 0;
	arrayCapacity = 100;
	elems = new SLLANode[100];
	for (int i = 0; i < 100; i++)
        (elems + i) -> element = NULL_TELEM;
	head = -1;
    firstEmpty = 0;
}


bool Set::add(TElem elem) {
    // if size + 1 >= capacity, resize
	int currentNode = head;

	if (search(elem) == true)
		return false;

	while (currentNode != -1 && elems[currentNode].getElement() != elem)
	{
		currentNode = elems[currentNode].getNext();
	}

	if (currentNode == -1)
	{
		++arraySize;
		if (head == -1)
		{
			int nextFreePos; //lems[firstEmpty].getNext();
			for (int i = 0; i < arrayCapacity; ++i)
                if ((elems + i)-> element = NULL_TELEM)
                {
                    nextFreePos = i;
                    break;
                }
			head = firstEmpty;
			elems[head].setElement(elem);
			elems[head].setNext(-1);
			firstEmpty = nextFreePos;
		}
		else
		{
			int nextFreePosition; //elems[firstEmpty].getNext();
			for (int i = 0; i < arrayCapacity; ++i)
                if ((elems + i)-> element = NULL_TELEM)
                {
                    nextFreePosition = i;
                    break;
                }
			elems[firstEmpty].setElement(elem);
			elems[firstEmpty].setNext(-1);
			firstEmpty = nextFreePosition;
		}
		return true;
	}
	return false;
}


bool Set::remove(TElem elem) {
	//TODO - Implementation
	if (search(elem) == false)
		return false;
	int currentNode = head;
	int currentNodePrev = -1;

	// if the searched element for remove is
	// on the head's position
	if (currentNode == elem)
	{
		int nextNode = elems[currentNode].getNext();
		(elems + head) -> element = NULL_TELEM;
		head = nextNode;
		arraySize--;
		return true;
	}
	// we use the currentNodePrev for
	// reconnecting nodes after removing one
	else
	{

		while (currentNode != -1 && elems[currentNode].getElement() != elem)
		{
			currentNodePrev = currentNode;
			currentNode = elems[currentNode].getNext();
		}
        (elems + currentNode) ->element = NULL_TELEM;
		elems[currentNodePrev].setNext(elems[currentNode].getNext());
		arraySize--;
		return true;
	}

	return false;
}

bool Set::search(TElem elem) const {
	//TODO - Implementation
	int currentNode = head;
	if (arraySize == 0)
		return false;
	while (currentNode != -1)
	{
		if (elems[currentNode].getElement() == elem)
		{
			return true;
		}
		currentNode = elems[currentNode].getNext();
	}
	return false;
}


int Set::size() const {
	//TODO - Implementation
	int theSize = 0;
	int currentNode = head;
	while (currentNode != -1)
	{
		theSize++;
		currentNode = elems[currentNode].getNext();
	}
	return theSize;
}


bool Set::isEmpty() const {
	//TODO - Implementation
	return arraySize == 0;
}


Set::~Set() {
	delete[]elems;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


