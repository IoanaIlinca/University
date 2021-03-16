#pragma once
#include "domain.h"
#include "array.h"
#include <stdlib.h>

DynamicArray* myList;
DynamicArray* undoArrayOfArrays;
DynamicArray* redoArrayOfArrays;

void InitializeRepo();

int CheckExisting(int profileIdNumber);

void RepoAddProfile(Profile* profil);

void RepoUpdateProfile(Profile* updatedProfile);

int RepoDeleteProfile(int profileIdNumber);

DynamicArray* RepoGetAll();
