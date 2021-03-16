#pragma once
#include <assert.h>
#include "ui.h"

void testAdd()
{
	Repo repo;
	Repo* repository = &(repo);
	assert(FindProfile(repository, 12) == -1);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	AddProfile(repository, 12, 2, placeOfBirth, psychologicalProfile);
	assert(FindProfile(repository, 12) != -1);
}

void testDelete()
{
	Repo repo;
	Repo* repository = &(repo);
	assert(FindProfile(repository, 12) == -1);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	AddProfile(repository, 12, 2, placeOfBirth, psychologicalProfile);
	DeleteProfile(repository, 12);
	assert(FindProfile(repository, 12) == -1);
}

void testAll()
{
	testAdd();
	testDelete();
}
