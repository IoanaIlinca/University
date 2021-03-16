#include <assert.h>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
    assert(smm.getKeyRange() == -1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    //cout << smm.getKeyRange() << '\n';
    assert(smm.getKeyRange() == 0);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());

    vector<TValue> v= smm.search(1);
    //cout << v.size() << '\n';
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();

    while (it.valid()){
    	TElem e = it.getCurrent();
    	//cout << e.first << ' ' << e.second << '\n';
    	it.next();
    }
    //cout << "ok\n";*/
    smm.add(3, 3);
    //cout << smm.getKeyRange() << '\n';
    assert(smm.getKeyRange() == 2);
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(3, 3) == true);
    //cout << "1, 3\n";
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());
    // 
}

