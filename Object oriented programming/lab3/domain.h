#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

typedef struct {
	int profileIdNumber, yearsOfRecordedService;
	char placeOfBirth[21], psychologicalProfile[21];

}Profile;

Profile CreateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService);
