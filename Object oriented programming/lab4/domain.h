#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

typedef struct {
	int profileIdNumber, yearsOfRecordedService;
	char* placeOfBirth;
	char *psychologicalProfile;

}Profile;

Profile* CreateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);

void ConvertProfileToString(Profile* profil, char* finalString);

Profile* Copy(Profile* profil);

void DestroyProfile(Profile* profil);
