#pragma once
//DO NOT INCLUDE SMMITERATOR
#include <iostream>
//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TKEY -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);

class BSTNode {
public:
    TKey key;
    TValue* values;
    int sizeNode, capacityNode;
    int left;
    int right;
    BSTNode& operator= (const BSTNode& node)
	{
		if (this == &node)
			return *this;

		this->key = node.key;
        TValue* newValues = new TValue[node.capacityNode];
        //cout << "\ncapacityNode: " << node.capacityNode << '\n';
        //cout << node.sizeNode << ' ' << node.capacityNode << '\n';
        for(int i = 0; i < node.sizeNode; i++)
            {
                //cout << '&' << i << ' ';
                
                newValues[i] = node.values[i];
            }
        for(int i = node.sizeNode; i < node.capacityNode; i++)
            {
                    newValues[i] = NULL_TVALUE;
            }
       


        //delete[] this->values;
        //cout << "I got here\n";

        this->values = newValues;

		this->capacityNode = node.capacityNode;
		this->left = node.left;
		this->right = node.right;
		this->sizeNode = node.sizeNode;
		return *this;
	}
	~BSTNode()
	{
        delete[] this->values;
	}
};

class SortedMultiMap {
	friend class SMMIterator;
    private:
		BSTNode* array;
		int root;
		Relation relation;
		int siz, capacity;
        int firstEmpty;
        int numberOfKeys;

    public:

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    std::vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)
    SMMIterator iterator() const;

    //returns the difference between the maximum and the minimum key (assume integer keys)
    //if the MultiMap is empty the range is -1
    int getKeyRange() const;

    // destructor
    ~SortedMultiMap();
};
