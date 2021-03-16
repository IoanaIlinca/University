#pragma once
#include "domain.h"
#include <stdlib.h>

typedef struct {
	Profile listOfProfiles[100];
	int numberOfProfiles;
} AllProfiles;

AllProfiles myList;

void InitializeRepo();

int CheckExisting(int profileIdNumber);

void RepoAddProfile(Profile newProfile);

void RepoUpdateProfile(Profile updatedProfile);

void RepoDeleteProfile(int profileIdNumber);

AllProfiles RepoGetAll();
