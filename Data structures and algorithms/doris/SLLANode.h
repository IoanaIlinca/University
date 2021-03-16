#pragma once

typedef int TElem;

class SLLANode
{
	public:
		TElem element;
		int next;
	public:
		SLLANode(TElem element = 0, int next = -1);
		TElem getElement() const;
		void setElement(TElem newElement);
		int getNext() const;
		void setNext(int newNext);

};
