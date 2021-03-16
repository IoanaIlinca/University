#include "tests.h"

void testAdd()
{
	/* Tests the add functionality */
	DynamicArray* repo;
	repo = createDynamicArray(10, DestroyProfile);
	assert(CheckExisting(repo, 12) == 0);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	Profile* p = CreateProfile(12, placeOfBirth, psychologicalProfile, 2);
	add(repo, p);
	//add(repo, p);
	assert(CheckExisting(repo, 12) != 0);
	//free(placeOfBirth);
	//free(psychologicalProfile);
	destroy(repo);
}

void testDelete()
{
	/* Tests the delete functionality */
	DynamicArray* repo;
	repo = createDynamicArray(10, DestroyProfile);
	assert(CheckExisting(repo, 12) == 0);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	Profile* p = CreateProfile(12, placeOfBirth, psychologicalProfile, 2);
	add(repo, p);
	int index = ReturnIndex(repo, p->profileIdNumber);
	deleteElement(repo, index);
	//add(repo, p);
	assert(CheckExisting(repo, 12) == 0);
	destroy(repo);
}

void testUpdate()
{
	/* Teste the update functionality */
	DynamicArray* repo;
	repo = createDynamicArray(10, DestroyProfile);
	assert(CheckExisting(repo, 12) == 0);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	Profile* p = CreateProfile(12, placeOfBirth, psychologicalProfile, 2);
	Profile* p2 = CreateProfile(12, placeOfBirth, psychologicalProfile, 14);
	add(repo, p);
	int index = ReturnIndex(repo, p->profileIdNumber);
	substitute(repo, index, p2);
	index = ReturnIndex(repo, p2);
	//add(repo, p);
	p2 = getElementAtPosition(repo, index);
	assert(p2->yearsOfRecordedService == 14);
	destroy(repo);
}

void testAll()
{
	testAdd();
	//_CrtMemState s1;
	//_CrtMemCheckpoint(&s1);
	//_CrtMemDumpStatistics(&s1);
	testDelete();
	testUpdate();
}

