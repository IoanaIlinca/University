
#include "PriorityQueue.h"
#include <exception>
using namespace std;

/// BC = WC = overall = theta(1)
PriorityQueue::PriorityQueue(Relation r) {
	elements = nullptr;
	capacity = 0;
	head = -1;
	tail = -1;
	firstEmpty = 0;
	//for (int i = firstEmpty; i < capacity; i++)
        //(elements + i)->next = i + 1;
	siz = 0;
	rel = r;
}

/// BC = theta(1) - empty list or first position, WC = theta(newCapacity) - when resizing is needed, Overall = O(capacity)
void PriorityQueue::push(TElem e, TPriority p) {
    if ((siz + 1) >= capacity)
    {
        capacity = 2 * (siz + 1);
        DLLANode *newElements;
        newElements = new DLLANode[capacity];
        for (int i = 0; i < siz; i++)
            *(newElements + i) = *(elements + i);
        for (int i = siz; i < capacity; i++)
            (newElements + i) -> info = NULL_TELEM; /// unoccupied elements will be set to this value
        for (int i = siz; i < capacity; i++)
        {
            //cout << i << ' ';
            (newElements + i)->next = i + 1;
        }
        //cout << '\n';
        (newElements + capacity - 1)->next = -1;
        firstEmpty = siz;

        delete[] elements;
        elements = newElements;
    }
    DLLANode newNode;
	if (siz == 0)
    {
        Element newInfo;
        newInfo.first = e;
        newInfo.second = p;
        newNode.info = newInfo;
        newNode.next = -1;
        newNode.prev = -1;
        *(elements + siz) = newNode;
        head = 0;
        tail = 0;
        firstEmpty = (elements + firstEmpty)->next;

        //(elements + 1)->next = 2;
        //cout << p << ' ' << newNode.prev << ' ' << newNode.next << '\n';
    }
    else
    {
        int nextFirstEmpty = (elements + firstEmpty)->next;
        //(elements + firstEmpty)->next = siz + 1;
        //DLLANode newNode;
        Element newInfo;
        newInfo.first = e;
        newInfo.second = p;
        newNode.info = newInfo;
        bool added = false;
        int index = head;
        DLLANode *currentNode;
        while (index != -1)
        {
            //cout << index << '\n';
            currentNode = (elements + index);
            //if (p == -8)
                //cout << index << ' ';
            if (rel(p, currentNode -> info.second) == true) /// it means that the new node needs to be added before the current node
            {
                added = true;


                if (currentNode -> prev != -1) /// it means we don't add to the first position
                {

                    DLLANode *previousNode = (elements + currentNode -> prev);

                        //cout << "###" <<  previousNode ->info.first << ' ' << previousNode -> prev << ' ' << previousNode -> next << ' ';
                        //cout << "###" << firstEmpty << ' ';
                    //if (p == -9)
                        //cout << "###" << previousNode -> next << ' ';

                    newNode.prev = currentNode -> prev;
                    newNode.next = previousNode -> next;
                    previousNode -> next = firstEmpty;
                    currentNode -> prev = firstEmpty;
                    *(elements + firstEmpty) = newNode; /// actually adding the nodes
                    //if (p == -9)
                        //cout << p << ' ' << newNode.prev << ' ' << newNode.next << '\n';
                }
                else /// adding to the first position
                {
                    newNode.prev = currentNode -> prev; /// which will be -1
                    newNode.next = index; /// the index of the current node, the node after it
                    currentNode -> prev = firstEmpty; /// the index on which the new node will be added
                    head = firstEmpty; /// changing the tail
                    *(elements + firstEmpty) = newNode; /// actually adding the nodes
                    //cout << "***" << p << ' ' << newNode.prev << ' ' << newNode.next << '\n';
                    //cout << p << ' ' << (elements + firstEmpty) -> prev  << ' ' << (elements + firstEmpty) -> next << '\n';
                }



                break;
            }
            index = currentNode -> next;
            //cout << "***" << newInfo.second << "***\n";
        }
        //cout << "Added: " << added << ' ';
        /// the element needs to be added at the end, after the current node
        if (rel(p, (elements + tail) -> info.second) == false)
        {
            //cout << "***";
            //cout << tail << '\n';
            currentNode = (elements + tail);
            currentNode -> next = firstEmpty;
            //cout << currentNode -> next;
            newNode.prev = tail;
            newNode.next = -1;
            tail = firstEmpty;
            //cout << tail << '\n';
            *(elements + firstEmpty) = newNode;
            //cout << p << ' ' << newNode.prev << ' ' << newNode.next << '\n';
            //cout << p << ' ' << (elements + firstEmpty) -> prev  << ' ' << (elements + firstEmpty) -> next << '\n';
        }
        firstEmpty = nextFirstEmpty;
    }
	siz++;


    //cout << p << ' ' << newNode.prev << ' ' << newNode.next << '\n';
}

//throws exception if the queue is empty
/// BC = WC = AC = theta(1)
Element PriorityQueue::top() const {
    exception ex;
	if (siz == 0)
        throw ex;


	return (elements + head) -> info;
}

/// AC = BC = WC = theta(1)
Element PriorityQueue::pop() {
    exception ex;
	if (siz == 0)
        throw ex;

    int newFirstEmpty = head;
    Element result = (elements + head) -> info;
    DLLANode *oldNode = (elements + head);
	DLLANode *newHead = (elements + ((elements + head) -> next));
	newHead -> prev = -1;
	head = (elements + head) -> next;

	oldNode -> info = NULL_TELEM;
	siz--;
	(elements + newFirstEmpty)->next = firstEmpty;
	firstEmpty = newFirstEmpty;

	return result;
}

/// AC = BC = WC = theta(1)
bool PriorityQueue::isEmpty() const {
	if (siz == 0)
        return true;
	return false;
}

/// AC = BC = WC = theta(n/2)
TElem PriorityQueue::getMiddle() const {
    exception ex;
	if (siz == 0)
        throw ex;

    DLLANode *currentNode = (elements + head);
    //cout << currentNode->info.first<< ' ';
    for (int i = 1; i <= (siz / 2); i++)
    {
        currentNode = (elements + (currentNode->next));
        //cout << currentNode->info.first << ' ';
    }
        

    return currentNode->info.first;
}

/// AC = BC = WC = theta(1)
PriorityQueue::~PriorityQueue() {
	//delete[] elements;
    //for (int i = 0; i < capacity; i++)
        //cout << (elements + i)->info.first << ' ';
};

/// AC = BC = WC = theta(n)
ostream& operator<<(ostream& os, const PriorityQueue& q)
{
    cout << "--------------------\n";
    int index = q.head;
    cout << q.head << ' ' << q.tail << '\n';
    for (index = 0; index < q.capacity; index++)
    {
        os << index << ' ' << (q.elements + index) -> info.second << " previous: " << (q.elements + index) -> prev << " next: " << (q.elements + index) -> next << '\n';
        //index = (q.elements + index) -> next;
    }
    cout << "--------------------\n";
    return os;
}

