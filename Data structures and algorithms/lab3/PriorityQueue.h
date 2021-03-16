#pragma once
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool (*Relation)(TPriority p1, TPriority p2);
#define NULL_TELEM pair<TElem, TPriority> (-11111,-11111)

class DLLANode {
public:
    Element info;
    int next;
    int prev;

    DLLANode& operator= (const DLLANode& node)
	{
		if (this == &node)
			return *this;

		this->info = node.info; /// might need to do this manually
		this->prev = node.prev;
		this->next = node.next;
		return *this;
	}

	~DLLANode() {}
};

class PriorityQueue {
private:
	DLLANode *elements;
	int capacity; /// ?
	int head;
	int tail;
    int firstEmpty;
	int siz;
	Relation rel;

public:
	//implicit constructor
	PriorityQueue(Relation r);

	//pushes an element with priority to the queue
	void push(TElem e, TPriority p);

	//returns the element with the highest priority with respect to the order relation
	//throws exception if the queue is empty
	Element top()  const;

	//removes and returns the element with the highest priority
	//throws exception if the queue is empty
	Element pop();

	//checks if the queue is empty
	bool isEmpty() const;

	TElem getMiddle() const;


	//destructor
	~PriorityQueue();


	friend ostream& operator<<(ostream& os, const PriorityQueue& q);
    /*
	PriorityQueue& operator= (const PriorityQueue& q)
	{
		if (this == &)
			return *this;

		this->capacity = q.capacity;
		this->imageClarityLevel = piece.imageClarityLevel;
		this->measurement = piece.measurement;
		this->photograph = piece.photograph;
		this->quantity = piece.quantity;
		return *this;
	}*/

};
