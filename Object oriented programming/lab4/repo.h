#pragma once
#include "domain.h"
#include "array.h"
#include "command.h"
#include <stdlib.h>

DynamicArray* myList;
DynamicArray* undoArrayOfArrays;
DynamicArray* redoArrayOfArrays;
DynamicArray* undoCommands;
DynamicArray* redoCommands;

void InitializeRepo();

int CheckExisting(DynamicArray* List, int profileIdNumber);

int ReturnIndex(DynamicArray* List, int profileIdNumber);

void RepoAddProfile(Profile* profil);

void RepoUpdateProfile(Profile* updatedProfile);

int RepoDeleteProfile(int profileIdNumber);

DynamicArray* RepoGetAll();
