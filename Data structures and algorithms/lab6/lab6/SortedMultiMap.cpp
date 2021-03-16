#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
//using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
	relation = r;
	siz = 0;
	capacity = 10;
	array = new BSTNode[capacity];
	for (int i = 0; i < capacity; i++)
    {
        array[i].key = NULL_TKEY;
        array[i].capacityNode = 0;
        array[i].sizeNode = 0;
        array[i].left = -1;
        array[i].right = -1;
        array[i].values = nullptr;
    }
	root = -1;
}

void SortedMultiMap::add(TKey c, TValue v) {

    if (root == -1)
    {
        array[0].key = c;
        array[0].values = new TValue[1];
        array[0].values[0] = v;
        array[0].capacityNode = 1;
        array[0].sizeNode = 1;
        array[0].left = -1;
        array[0].right = -1;
        root = 0;
        siz++;
        return;
    }
    if (siz + 1 >= capacity)
    {
        capacity = capacity * 2 + 1;
        BSTNode* newNodes = new BSTNode[capacity];
        for(int i = 0; i < siz; i++)
        {
            newNodes[i] = array[i];
        }

        for(int i = siz; i < capacity; ++i)
        {
            newNodes[i].key = NULL_TKEY;
            newNodes[i].capacityNode = 0;
            newNodes[i].sizeNode = 0;
            newNodes[i].left = -1;
            newNodes[i].right = -1;
            newNodes[i].values = nullptr;
        }

        delete[] array;

        array = newNodes;
    }

    int current = root;
    int parent = -1;
    //cout << root << ' ';
    while(current != -1)
    {
        //cout << array[current].left << ' ';
        if(relation(array[current].key, c) == true)
            if(array[current].key != c)
            {
                parent = current;
                current = array[current].right;
            }
            else
            {
                if(array[current].sizeNode + 1 > array[current].capacityNode)
                {
                    array[current].capacityNode = array[current].capacityNode * 2 + 1;
                    TValue* newValues = new TValue[array[current].capacityNode];
                    for(int i = 0; i < array[current].sizeNode; i++)
                    {
                        newValues[i] = array[current].values[i];
                    }
                    for(int i = array[current].sizeNode; i < array[current].capacityNode; i++)
                    {
                        newValues[i] = NULL_TVALUE;
                    }
                    delete[] array[current].values;
                    array[current].values = newValues;
                }
                array[current].sizeNode++;
                array[current].values[array[current].sizeNode] = v;
                siz++;
                return;
            }
        else
            if(array[current].key != c)
            {
                parent = current;
                current = array[current].left;
            }
            else
            {
                if(array[current].sizeNode + 1 > array[current].capacityNode)
                {
                    array[current].capacityNode = array[current].capacityNode * 2 + 1;
                    TValue* newValues = new TValue[array[current].capacityNode];
                    for(int i = 0; i < array[current].sizeNode; i++)
                    {
                        newValues[i] = array[current].values[i];
                    }
                    for(int i = array[current].sizeNode; i < array[current].capacityNode; i++)
                    {
                        newValues[i] = NULL_TVALUE;
                    }
                    delete[] array[current].values;
                    array[current].values = newValues;
                }
                array[current].sizeNode++;
                array[current].values[array[current].sizeNode] = v;
                siz++;
                return;
            }
    }
    array[siz].key = c;
    array[siz].values = new TValue[1];
    array[siz].values[0] = v;
    array[siz].capacityNode = 1;
    array[siz].sizeNode = 1;
    array[siz].left = -1;
    array[siz].right = -1;
    if(relation(array[parent].key, c) == true)
        array[parent].right = siz;
    else
        array[parent].left = siz;
    siz++;

}

std::vector<TValue> SortedMultiMap::search(TKey c) const {
    std::vector<TValue> result;
    int current = root;
    int parent = -1;
    while(current != -1)
    {
        if(relation(array[current].key, c) == true)
            if(array[current].key != c)
            {
                parent = current;
                current = array[current].right;
            }
            else
            {
                for(int i = 0; i < array[current].sizeNode; i++)
                    result.push_back(array[current].values[i]);
                return result;
            }
        else
            if(array[current].key != c)
            {
                parent = current;
                current = array[current].left;
            }
            else
            {
                for(int i = 0; i < array[current].sizeNode; i++)
                    result.push_back(array[current].values[i]);
                return result;
            }
    }
    return result;
}

bool SortedMultiMap::remove(TKey c, TValue v) {

}


int SortedMultiMap::size() const {
	return siz;
}

bool SortedMultiMap::isEmpty() const {
	if (siz == 0)
        return true;
	return false;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
    delete[] array;
}
