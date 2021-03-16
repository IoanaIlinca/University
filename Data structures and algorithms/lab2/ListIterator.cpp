#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>
//#include <stdexcept>

using namespace std;


/// Complexity - bc, wc, overall: theta(1)
ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	currentElement = list.head;
}

/// Complexity - bc, wc, overall: theta(1)
void ListIterator::first(){
	currentElement = list.head;
}

/// Complexity - bc, wc, overall: theta(1)
void ListIterator::next(){
    exception e;
	if (currentElement == nullptr)
        throw e;

    currentElement = currentElement -> next;
}

/// Complexity - bc, wc, overall: theta(1)
bool ListIterator::valid() const{
	if (currentElement == nullptr)
        return false;
    return true;
}

/// Complexity - bc, wc, overall: theta(1)
TComp ListIterator::getCurrent() const{
    exception e;
    if (currentElement == nullptr)
        throw e;

    return currentElement -> info;
}

/// Complexity - bc - theta(1) (k is 1, the iterator is on the first position,
                                /// it needs to get to that position
                                /// wc - theta(n) - last element, overall: O(n)
void ListIterator::jumpBackward(int k) {
    exception ex;
    if (currentElement == nullptr || k <= 0)
        throw ex;

    int index = 0, cnt = 0;
    Node *lastElement = currentElement;
    Node *searchedElement = nullptr;
    currentElement = list.head;

    while (currentElement -> info != lastElement -> info)
        {
            currentElement = currentElement -> next;
            index++;
            if (index == k)
                searchedElement = list.head;
            if (index >= k + 1)
                searchedElement = searchedElement -> next;
        }
    if (index < k)
        currentElement = nullptr;
    else
        currentElement = searchedElement;
}

