#pragma once
#include <assert.h>
#include <stdlib.h>
#include "repo.h"

void testAdd()
{
    Repo repo;
	Repo* repository = &(repo);
	assert(FindProfile(*repository, 12) == -1);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	AddProfile(repository, 12, 2, placeOfBirth, psychologicalProfile);
	AddProfile(repository, 14, 1, placeOfBirth, psychologicalProfile);
	AddProfile(repository, 11, 6, placeOfBirth, psychologicalProfile);
	assert(FindProfile(*repository, 12) != -1);
}

void testDelete()
{
	Repo repo;
	Repo* repository = &(repo);
	assert(FindProfile(*repository, 12) == -1);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	AddProfile(repository, 12, 2, placeOfBirth, psychologicalProfile);
	AddProfile(repository, 14, 1, placeOfBirth, psychologicalProfile);
	AddProfile(repository, 11, 6, placeOfBirth, psychologicalProfile);
	DeleteProfile(repository, 12);
	/*char** matrix;
	matrix = (char**) calloc (3, sizeof(char));
	TurnIntoString(repository, matrix);*/
	assert(FindProfile(*repository, 12) == -1);
}

void testList()
{
    Repo repo;
	Repo* repository = &(repo);
	assert(FindProfile(*repository, 12) == -1);
	char placeOfBirth[] = "Bistrita";
	char psychologicalProfile[] = "normal";
	AddProfile(repository, 12, 2, placeOfBirth, psychologicalProfile);
	AddProfile(repository, 14, 1, placeOfBirth, psychologicalProfile);
	AddProfile(repository, 11, 6, placeOfBirth, psychologicalProfile);
	char** matrix;
	/*matrix = (char**) calloc (3, sizeof(char));
    TurnIntoString(repository, matrix);
    for (int it = 1; it <= repository -> numberOfProfiles; it++)
    {
         printf("%s", matrix[it]);
    }*/
}

void testAll()
{
	testAdd();
	testDelete();
	testList();
}
