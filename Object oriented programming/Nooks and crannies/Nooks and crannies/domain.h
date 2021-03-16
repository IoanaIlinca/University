#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

struct Profile {
	int profileIdNumber = 0, yearsOfRecordedService = 0;
	char placeOfBirth[21], psychologicalProfile[21];
	
};

int GetProfileIdNumber(Profile currentProfile)
{
	return currentProfile.profileIdNumber;
}

int GetYearsOdRecordedService(Profile currentProfile)
{
	return currentProfile.yearsOfRecordedService;
}

char* GetPlaceOfBirth(Profile currentProfile)
{
	return currentProfile.placeOfBirth;
}

char* GetPsychologicalProfile(Profile currentProfile)
{
	return currentProfile.psychologicalProfile;
}

void SetProfileIdNumber(Profile* currentProfile, int profileIdNumber)
{
	currentProfile -> profileIdNumber = profileIdNumber;
}

void SetYearsOfRecordedService(Profile* currentProfile, int newYearsOfRecordedService)
{
	currentProfile -> yearsOfRecordedService = newYearsOfRecordedService;
}

void SetPlaceOfBirth(Profile* currentProfile, char newPlaceOfBirth[])
{
	strcpy_s(currentProfile -> placeOfBirth, newPlaceOfBirth);
}

void SetPsychologicalProfile(Profile* currentProfile, char newPsychologicalProfile[])
{
	strcpy_s(currentProfile -> psychologicalProfile, newPsychologicalProfile);
}

void ConvertToString(Profile* currentProfile)
{
	/*
	*/
	char printable[101];
	int id = currentProfile->profileIdNumber, years = currentProfile->yearsOfRecordedService;
	int len = 0;
	if (id == 0)
		printable[len++] = '0';
	else
		while (id != 0)
		{
			char digit = (id % 10) + '0';
			printable[len++] = digit;
			id /= 10;
		}
	printable[len++] = ' ';
	if (years == 0)
		printable[len++] = '0';
	else
		while (years != 0)
		{
			char digit = (years % 10) + '0';
			printable[len++] = digit;
			years /= 10;
		}
	printable[len++] = ' ';
	for (int iterator = 0; iterator < sizeof(currentProfile->placeOfBirth); iterator++) /* se poate sa copieze si \0*/
	{
		printable[len++] = currentProfile->placeOfBirth[iterator];
	}
	printable[len++] = ' ';
	for (int iterator = 0; iterator < sizeof(currentProfile->psychologicalProfile); iterator++)
	{
		printable[len++] = currentProfile->psychologicalProfile[iterator];
	}
	printable[len++] = '\0';

	printf("%s\n", printable);
	
}


