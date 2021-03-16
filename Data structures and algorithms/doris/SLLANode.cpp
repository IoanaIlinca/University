#include "SLLANode.h"

TElem SLLANode::getElement() const {
	return element;
}

void SLLANode::setElement(TElem newElement)
{
	SLLANode::element = newElement;
}

int SLLANode::getNext() const {
	return next;
}

void SLLANode::setNext(int newNext)
{
	SLLANode::next = newNext;
}

SLLANode::SLLANode(TElem element, int next) :element(element), next(next) {}