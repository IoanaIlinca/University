#include "tests.h"

void Tests::TestGetSelected()
{
	Service<Person> serv;
	vector<Person> vect = serv.GetSelected("mm");
	assert(vect.size() == 2);
}

void TestAll()
{
	Tests test;
	test.TestGetSelected();
}
