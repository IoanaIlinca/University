#include "ShortTest.h"
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <assert.h>
#include <vector>
#include<iostream>

void testAll() {
	MultiMap m;
	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);

	assert(m.size() == 6);


	assert(m.remove(5, 600) == false);
	assert(m.remove(1, 500) == true);

	assert(m.size() == 5);


    vector<TValue> v;
	v=m.search(6);
	assert(v.size()==0);

	v=m.search(1);
	assert(v.size()==1);

	assert(m.isEmpty() == false);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		TElem e = im.getCurrent();
		//cout << e.first << ' ' << e.second << ' ';
		im.next();
	}
	//cout << '\n';
	assert(im.valid() == false);
	try {
        im.remove();
        assert(false);
	}
	catch (exception ex) {
        assert(true);
    }
	im.first();
	assert(im.valid() == true);
    TElem firstPair = im.remove();
    assert(firstPair.first == 1 && firstPair.second == 100);
    assert(im.getCurrent().first == 2 && im.getCurrent().second == 200);
    im.first();
    while (im.valid()) {
		TElem e = im.getCurrent();
		//cout << e.first << ' ' << e.second << ' ';
		im.next();
	}
}
