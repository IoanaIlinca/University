#include <assert.h>
#include <iostream>

#include "SortedIteratedList.h"
#include "ListIterator.h"

#include <exception>
using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedIteratedList list = SortedIteratedList(relation1);
	assert(list.size() == 0);
	assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator it = list.search(1);
    assert(it.valid());
    assert(it.getCurrent() == 1);
    it.next();
    assert(!it.valid());
    it.first();
    assert(it.valid());
    ListIterator itFirst = list.first();
    assert(itFirst.valid());
    assert(itFirst.getCurrent() == 1);
    assert(list.remove(it) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());

    /// Test extra functionality
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    ListIterator iter = list.search(6);
    iter.jumpBackward(3);
    assert(iter.getCurrent() == 3);
    ListIterator iter2 = list.search(6);
    iter2.jumpBackward(4);
    assert(iter2.getCurrent() == 2);
    ListIterator iter3 = list.search(6);
    iter3.jumpBackward(10);
    assert(iter3.valid() == false);
}

