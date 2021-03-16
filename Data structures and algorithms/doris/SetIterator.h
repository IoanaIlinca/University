#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);

	//TODO - Representation
	int currentNode;

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


