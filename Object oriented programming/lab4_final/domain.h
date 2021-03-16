#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

typedef struct {
	int profileIdNumber, yearsOfRecordedService;
	char placeOfBirth[21], psychologicalProfile[21];

}Profile;

Profile* CreateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);

void ConvertProfileToString(Profile* profil, char* finalString);

void DestroyProfile(Profile* profil);
