#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
using namespace std;

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	current = map.root;
	while(map.array[current].left != -1)
        current = map.array[current].left;
}

void SMMIterator::first(){
	current = map.root;
	while(map.array[current].left != -1)
        current = map.array[current].left;
}

void SMMIterator::next(){
	exception ex;
    if(!valid())
    {
        throw ex;
    }

}

bool SMMIterator::valid() const{
	if(current >= 0 && current < map.siz)
        return true;
	return false;
}

TElem SMMIterator::getCurrent() const{
    exception ex;
    if(!valid())
    {
        throw ex;
    }
    TElem elem;
    elem.first = map.array[current].key;
    elem.second = map.array[current].values;
	return elem;
}


