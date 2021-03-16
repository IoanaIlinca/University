#include "SMMIterator.h"
#include "SortedMultiMap.h"
//#include <iostream>
using namespace std;

// BC = Theta(1), WC = Theta(numberOfKeys), Overall = O(numberOfKeys)
SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	current = map.root;
    value = 0;
    if (map.root == -1)
        return;
	while(map.array[current].left != -1)
        current = map.array[current].left;
    
}

// BC = Theta(1), WC = Theta(numberOfKeys), Overall = O(numberOfKeys)
void SMMIterator::first(){
	current = map.root;
    if (map.root == -1)
        return;
	while(map.array[current].left != -1)
        current = map.array[current].left;
    value = 0;
}

// BC = Theta(1), WC = Theta(numberOfKeys), Overall = O(numberOfKeys)
void SMMIterator::next(){
	exception ex;
    if(!valid())
    {
        throw ex;
    }
    
    int node = map.root;
    int parent = -1;
    while (node != -1)
    {
        if (map.relation(map.array[current].key, map.array[node].key) == false)
            if (map.array[current].key != map.array[node].key)
            {
                node = map.array[node].right;
            }
            else
            {
                if (value < (map.array[current].sizeNode - 1))
                {
                    value++;
                    return;
                }
                if (parent == -1)
                {
                    parent = map.array[current].right;
                    if (parent == -1)
                    {
                        current = parent;
                        value = 0;
                        return;
                    }
                    while (map.array[parent].left != -1)
                    {
                        parent = map.array[parent].left;
                    }
                    current = parent;
                    value = 0;
                    return;
                }
                if (map.array[current].right != -1)
                {
                    parent = map.array[current].right;
                    while (map.array[parent].left != -1)
                    {
                        parent = map.array[parent].left;
                    }
                    current = parent;
                    value = 0;
                    return;
                }
                current = parent;
                value = 0;
                return;
            }
        else
            if (map.array[current].key != map.array[node].key)
            {
                parent = node;
                node = map.array[node].left;
            }
            else
            {
                if (value < (map.array[current].sizeNode - 1))
                {
                    value++;
                    return;
                }
                if (parent == -1)
                {
                    parent = map.array[current].right;
                    if (parent == -1)
                    {
                        current = parent;
                        value = 0;
                        return;
                    }
                    while (map.array[parent].left != -1)
                    {
                        parent = map.array[parent].left;
                    }
                    current = parent;
                    value = 0;
                    return;
                }
                if (map.array[current].right != -1)
                {
                    parent = map.array[current].right;
                    while (map.array[parent].left != -1)
                    {
                        parent = map.array[parent].left;
                    }
                    current = parent;
                    value = 0;
                    return;
                }
                current = parent;
                value = 0;
                return;
            }
    }
    current = parent;
    value = 0;
}

// BC = Theta(1), WC = Theta(1), AC = Theta(1)
bool SMMIterator::valid() const{
	if(current >= 0 && current < map.capacity && value >= 0 && value < map.array[current].sizeNode)
        return true;
    //cout << "Current: " << current << ' ' << "value: " << value << '\n';
	return false;
}

// BC = Theta(1), WC = Theta(1), AC = Theta(1)
TElem SMMIterator::getCurrent() const{
    exception ex;
    ////cout << "this exception\n";
    if(!valid())
    {
        throw ex;
    }
    TElem elem;
    elem.first = map.array[current].key;
    elem.second = map.array[current].values[value];
	return elem;
}


