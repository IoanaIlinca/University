#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
	numberOfElements = 0;
	m = 4;
	multiMap = new TElem[m];
	for (int i = 0; i < m; i++)
        multiMap[i] = NULL_TELEM;
}


void MultiMap::add(TKey c, TValue v) {
    numberOfElements++;
    if (numberOfElements == m)
        Rehash();
    int permutation = 0;

    TKey ogKey = c;
    if (c < 0)
        c *= -1;
    int position = HashFunction(c, permutation);
    while(multiMap[position] != NULL_TELEM)
    {
        permutation++;
        position = HashFunction(c, permutation);
    }
    multiMap[position] = make_pair(ogKey, v);
    //cout << multiMap[position].first << ' ' << multiMap[position].second << '\n';
}


bool MultiMap::remove(TKey c, TValue v) {
    if (numberOfElements == 0)
        return false;
    int position = 0;
    TKey ogKey = c;
    if (c < 0)
        c *= -1;
    bool found = false;
    for (int permutation = 0; permutation < m; ++permutation)
    {
        position = HashFunction(c, permutation);
        if (multiMap[position].first == ogKey && multiMap[position].second == v)
        {
            found = true;
            break;
        }

    }
    if (!found)
        return false;
    multiMap[position] = NULL_TELEM;
    numberOfElements--;
	return  true;
}


vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> v;
	int permutation = 0;
	TKey copyKey = c;
    if (copyKey < 0)
        copyKey *= -1;
    
	int position = HashFunction(copyKey, 0);
	for (permutation = 0; permutation < m; permutation++)
    {
        position = HashFunction(copyKey, permutation);
        //cout << position << ' ';
        if(multiMap[position].first == c)
            v.push_back(multiMap[position].second);

    }
	return v;
}


int MultiMap::size() const {
	return numberOfElements;
}


bool MultiMap::isEmpty() const {
	return (numberOfElements == 0);
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
    delete[] multiMap;
}

int MultiMap::HashFunction(TKey key, int permutation) const
{
    return (((int)(key % m + permutation / 2.0 + (permutation * permutation) / 2.0)) % m);
}


void MultiMap::Rehash()
{
    m *= 2;
    TElem* newMultiMap = new TElem[m];
	for (int i = 0; i < m; i++) {
		newMultiMap[i]=NULL_TELEM;
	}

	for (int i = 0; i < m / 2; i++)
    {
        TKey c = multiMap[i].first;
        TValue v = multiMap[i].second;
        int permutation = 0;
        TKey ogKey = c;
        if (c < 0)
            c *= -1;
        int position = HashFunction(c, permutation);
        while(newMultiMap[position] != NULL_TELEM)
        {
            permutation++;
            position = HashFunction(c, permutation);
        }
        newMultiMap[position] = make_pair(ogKey, v);

	}
	delete[] multiMap;
	multiMap = newMultiMap;
}
