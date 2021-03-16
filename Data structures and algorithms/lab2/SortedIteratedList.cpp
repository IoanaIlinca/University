#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

/// Copmlexity - bc, wc, overall: theta(1)
SortedIteratedList::SortedIteratedList(Relation r) {
	rel = r;
	head = nullptr;
	elements = 0;
}

/// Complexity - bc, wc, overall: theta(1)
int SortedIteratedList::size() const {

    return elements;
}

/// Complexity - bc, wc, overall: theta(1)
bool SortedIteratedList::isEmpty() const {
	if (head == nullptr)
        return true;
	return false;
}

/// Complexity - bc, wc, overall: theta(1)
ListIterator SortedIteratedList::first() const {
	ListIterator it(*this);
	it.first();
	return it;
}

/// Complexity - bc, wc, overall: theta(1)
TComp SortedIteratedList::getElement(ListIterator poz) const {
        exception e;
        if (!poz.valid())
            throw e;
        return poz.getCurrent();
}

/// Complexity - bc - theta(1), wc - theta(n), overall: O(n)
TComp SortedIteratedList::remove(ListIterator& poz) {
        exception e;
        if (!poz.valid())
            throw e;
        elements--;
        Node* toRemove = poz.currentElement;
        poz.next();
        TComp result = toRemove ->info;
        Node* currentNode = head;
        Node* previousNode = head;
        if (currentNode -> info == toRemove -> info)
        {
            head = currentNode -> next;
            delete[] currentNode;
            return result;
        }
        currentNode = currentNode -> next;
        while (currentNode != nullptr && (currentNode -> info != toRemove -> info))
        {
            currentNode = currentNode -> next;
            previousNode = previousNode -> next;
        }
        previousNode -> next = currentNode -> next;
        delete[] currentNode;
        return result;

}

/// Complexity - bc - theta(1), wc - theta(n), overall: O(n)
ListIterator SortedIteratedList::search(TComp e) const {
	ListIterator it(*this);
	while (it.valid() && it.getCurrent() != e)
    {
        it.next();
    }

	return it;
}

/// Complexity: bc - theta(1), wc - theta(n), overall: O(n)
void SortedIteratedList::add(TComp e) {
    elements++;
    Node *newNode = new Node;
    newNode -> info = e;
    newNode -> next = nullptr;
    if (head == nullptr)
        head = newNode;
    else
    {
        if (rel(e, head -> info) == true)
        {
            newNode -> next = head;
            head = newNode;
        }
        else
        {
            Node *currentNode;
            currentNode = head;
            while ((currentNode -> next != nullptr) && (rel(e, currentNode -> next -> info) == false))
                currentNode = currentNode -> next;

            newNode -> next = currentNode -> next;
            currentNode -> next = newNode;
        }

    }
}


/// Complexity - bc - theta(n), wc - theta(n), overall: theta(n)
SortedIteratedList::~SortedIteratedList() {
	Node* lastNode;
	lastNode = head;
	while (head != nullptr)
    {
        head = head -> next;
        delete[] lastNode;
        lastNode = head;

    }

}
