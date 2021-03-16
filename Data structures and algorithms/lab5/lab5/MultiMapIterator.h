#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	MultiMap& col;
	int current;

	MultiMapIterator(MultiMap& c);

public:
	TElem getCurrent()const;
	TElem remove();
	bool valid() const;
	void next();
	void first();
};

