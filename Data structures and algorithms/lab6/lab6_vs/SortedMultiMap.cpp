#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <queue>
#include <exception>
//using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
	relation = r;
	siz = 0;
	capacity = 10;
    firstEmpty = 0;
    numberOfKeys = 0;
	array = new BSTNode[capacity];
	for (int i = 0; i < capacity; i++)
    {
        array[i].key = NULL_TKEY;
        array[i].capacityNode = 0;
        array[i].sizeNode = 0;
        if (i < capacity - 1)
            array[i].left = i + 1;
        else
            array[i].left = -1;
        array[i].right = -1;
        array[i].values = nullptr;
    }
	root = -1;
}

// BC = Theta(1), WC = Theta(capacity), Overall = O(capacity)
void SortedMultiMap::add(TKey c, TValue v) {

    if (root == -1)
    {
        int lastEmpty = firstEmpty;
        firstEmpty = array[firstEmpty].left;
        array[lastEmpty].key = c;
        array[lastEmpty].values = new TValue[1];
        array[lastEmpty].values[0] = v;
        array[lastEmpty].capacityNode = 1;
        array[lastEmpty].sizeNode = 1;
        array[lastEmpty].left = -1;
        array[lastEmpty].right = -1;
        root = lastEmpty;
        numberOfKeys++;
        siz++;
        return;
    }
    if (numberOfKeys >= capacity)
    {
        capacity = (capacity + 1)* 2 + 1;
        BSTNode* newNodes = new BSTNode[capacity];
        for(int i = 0; i < numberOfKeys; i++)
        {
            newNodes[i] = array[i];
        }
        

        for(int i = numberOfKeys; i < capacity; ++i)
        {
            newNodes[i].key = NULL_TKEY;
            newNodes[i].capacityNode = 0;
            newNodes[i].sizeNode = 0;
            if(i < capacity - 1)
                newNodes[i].left = i + 1;
            else
                newNodes[i].left = -1;
            newNodes[i].right = -1;
            newNodes[i].values = nullptr;
        }
        //if (firstEmpty == -1)
        firstEmpty = numberOfKeys;

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
                array[current].values[array[current].sizeNode] = v;
                array[current].sizeNode++;
                
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
               
                if(array[current].sizeNode + 1 >= array[current].capacityNode)
                {
                    array[current].capacityNode = (array[current].capacityNode +1 )* 2 + 1;
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
                array[current].values[array[current].sizeNode] = v;
                array[current].sizeNode++;
                
                siz++;
                return;
            }
    }
    int lastEmpty = firstEmpty;
    //cout << firstEmpty << ' ';
    firstEmpty = array[firstEmpty].left;
    array[lastEmpty].key = c;
    array[lastEmpty].values = new TValue[1];
    array[lastEmpty].values[0] = v;
    array[lastEmpty].capacityNode = 1;
    array[lastEmpty].sizeNode = 1;
    array[lastEmpty].left = -1;
    array[lastEmpty].right = -1;
    if(relation(array[parent].key, c) == true)
        array[parent].right = lastEmpty;
    else
        array[parent].left = lastEmpty;
    numberOfKeys++;
    siz++;

}

// BC = Theta(1), WC = Theta(numberOfKeys), Overall = O(numberOfKeys)
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

// BC = Theta(1), WC = Theta(numberOfKeys), Overall = O(numberOfKeys)
bool SortedMultiMap::remove(TKey c, TValue v) {
    if (siz == 0)
        return false;
    bool found = false;
    int current = root;
    int parent = -1;
    while (current != -1)
    {
        if (relation(array[current].key, c) == true)
            if (array[current].key != c)
            {
                parent = current;
                current = array[current].right;
            }
            else
            {
                if (array[current].sizeNode > 1)
                {
                    for (int i = 0; i < array[current].sizeNode; ++i)
                    {
                        if (array[current].values[i] == v)
                            found = true;
                        if (!found)
                            array[current].values[i] = array[current].values[i];
                        else
                            array[current].values[i] = array[current].values[i + 1];
                    }
                    if (found == true)
                    {
                        array[current].sizeNode--;
                        siz--;
                        return found;
                    }

                    return found;
                }
                else
                    break;
            }
        else
            if (array[current].key != c)
            {
                parent = current;
                current = array[current].left;
            }
            else
            {
                if (array[current].sizeNode > 1)
                {
                    for (int i = 0; i < array[current].sizeNode; ++i)
                    {
                        if (array[current].values[i] == v)
                            found = true;
                        if (!found)
                            array[current].values[i] = array[current].values[i];
                        else
                            array[current].values[i] = array[current].values[i + 1];
                    }
                    if (found == true)
                    {
                        array[current].sizeNode--;
                        siz--;
                        return found;
                    }

                    return found;
                }
                else
                    break;
            }
    }
    
    if (current == -1)
        return false;
    //cout << array[current].values[0] << ' ' << array[current].values[1] << "\n";
    if (array[current].values[0] != v)
        return false;
    //cout << "I am here\n";
    found = true;

    if (parent == -1) // remove root
    {
        if (array[current].left == -1 && array[current].right == -1) // no descendants, only the root
        {
            array[current].left = firstEmpty;
            firstEmpty = root;
            root = -1;
            array[current].capacityNode = 0;
            array[current].key = NULL_TKEY;
            array[current].right = -1;
            array[current].sizeNode = 0;
            array[current].values = nullptr;
            siz--;
            numberOfKeys--;
            return found;
            
        }
        else
        {
            if (array[current].left == -1) // one descendant
            {
                root = array[current].right;
                array[current].left = firstEmpty;
                firstEmpty = current;
                array[current].capacityNode = 0;
                array[current].key = NULL_TKEY;
                array[current].right = -1;
                array[current].sizeNode = 0;
                array[current].values = nullptr;
                siz--;
                numberOfKeys--;
                return found;
            }
            else
            {
                if (array[current].right == -1)
                {
                    root = array[current].left;
                    array[current].left = firstEmpty;
                    firstEmpty = current;
                    array[current].capacityNode = 0;
                    array[current].key = NULL_TKEY;
                    array[current].right = -1;
                    array[current].sizeNode = 0;
                    array[current].values = nullptr;
                    siz--;
                    numberOfKeys--;
                    return found;
                }
                else // two descendants, minimum of the right subtree
                {
                    int minimumOfRightsubtree = array[current].right;
                    while (array[minimumOfRightsubtree].left != -1)
                    {
                        minimumOfRightsubtree = array[minimumOfRightsubtree].left;
                    }
                    array[current] = array[minimumOfRightsubtree];
                    array[minimumOfRightsubtree].left = firstEmpty;
                    firstEmpty = minimumOfRightsubtree;
                    array[minimumOfRightsubtree].capacityNode = 0;
                    array[minimumOfRightsubtree].key = NULL_TKEY;
                    array[minimumOfRightsubtree].right = -1;
                    array[minimumOfRightsubtree].sizeNode = 0;
                    array[minimumOfRightsubtree].values = nullptr;
                    siz--;
                    numberOfKeys--;
                    return found;
                }
            }
        }
       
    }
    if (array[current].left == -1 && array[current].right == -1) // no descendants
    {
        if (array[parent].right == current)
            array[parent].right = -1;
        else
            array[parent].left = -1;
        array[current].left = firstEmpty;
        firstEmpty = current;
        array[current].capacityNode = 0;
        array[current].key = NULL_TKEY;
        array[current].right = -1;
        array[current].sizeNode = 0;
        array[current].values = nullptr;
        siz--;
        numberOfKeys--;
        return found;
    }
    else
    {
        if (array[current].left == -1)
        {
            if (array[parent].right == current)
                array[parent].right = array[current].right;
            else
                array[parent].left = array[current].right;
            array[current].left = firstEmpty;
            firstEmpty = current;
            array[current].capacityNode = 0;
            array[current].key = NULL_TKEY;
            array[current].right = -1;
            array[current].sizeNode = 0;
            array[current].values = nullptr;
            siz--;
            numberOfKeys--;
            return found;
        }
        else
        {
            if (array[current].right == -1)
            {
                if (array[parent].right == current)
                    array[parent].right = array[current].left;
                else
                    array[parent].left = array[current].left;
                array[current].left = firstEmpty;
                firstEmpty = current;
                array[current].capacityNode = 0;
                array[current].key = NULL_TKEY;
                array[current].right = -1;
                array[current].sizeNode = 0;
                array[current].values = nullptr;
                siz--;
                numberOfKeys--;
                return found;
            }
            else // two descendants, minimum of the right subtree
            {
                int minimumOfRightsubtree = array[current].right;
                while (array[minimumOfRightsubtree].left != -1)
                {
                    minimumOfRightsubtree = array[minimumOfRightsubtree].left;
                }
                array[current] = array[minimumOfRightsubtree];
                array[minimumOfRightsubtree].left = firstEmpty;
                firstEmpty = minimumOfRightsubtree;
                array[minimumOfRightsubtree].capacityNode = 0;
                array[minimumOfRightsubtree].key = NULL_TKEY;
                array[minimumOfRightsubtree].right = -1;
                array[minimumOfRightsubtree].sizeNode = 0;
                array[minimumOfRightsubtree].values = nullptr;
                siz--;
                numberOfKeys--;
                return found;
            }
        }
    }
    siz--;
    numberOfKeys--;
    return found;
}

// BC = Theta(1), WC = Theta(1), Overall = Theta(1)
int SortedMultiMap::size() const {
	return siz;
}

// BC = Theta(1), WC = Theta(1), Overall = Theta(1)
bool SortedMultiMap::isEmpty() const {
	if (siz == 0)
        return true;
	return false;
}

// BC = Theta(1), WC = Theta(1), AC = Theta(1)
SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}
/*
// BC = Theta(numberOfKeys), WC = Theta(numberOfKeys), AC = Theta(numberOfKeys)
int SortedMultiMap::getKeyRange() const
{
    if (siz == 0)
        return -1;
    int current = root;
    int parent = root;
    queue<int> positions;
    positions.push(root);

    int min = 0x3f3f3f3f, max = -0x3f3f3f3f;
    while (!positions.empty())
    {
        current = positions.front();
        positions.pop();
        if (array[current].left != -1)
            positions.push(array[current].left);
        if (array[current].right != -1)
            positions.push(array[current].right);
        if (array[current].key < min)
            min = array[current].key;
        if (array[current].key > max)
            max = array[current].key;
    }
    return abs(max - min);
}
*/

// BC = Theta(1), WC = Theta(numberOfKeys), Overall = O(numberOfKeys)
int SortedMultiMap::getKeyRange() const
{
    if (siz == 0)
        return -1;
    int current = root;
    //int parent = root;


    int min = array[root].key, max = array[root].key;
    while (array[current].left != -1)
    {
        
        current = array[current].left;
    }
    min = array[current].key;
    current = root;
    while (array[current].right != -1)
    {
       
        current = array[current].right;
    }
    max = array[current].key;
    return max - min;
}

// BC = Theta(1), WC = Theta(1), Overall = Theta(1)
SortedMultiMap::~SortedMultiMap() {
    delete[] array;
}
