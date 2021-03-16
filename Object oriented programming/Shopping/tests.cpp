#include "tests.h"
#include <assert.h>

void Tests::TestDelete()
{
	Service<People> serv;
	
	People veggie1("jefe", "jehfe", 0);
	serv.ServiceAdd(veggie1);
	vector<People> vect = serv.GetElements();
	assert(vect.size() == 4);
	serv.ServiceDelete(veggie1);
	vect = serv.GetElements();
	assert(vect.size() == 3);
}

void TestAll()
{
	Tests test;
	test.TestDelete();
}