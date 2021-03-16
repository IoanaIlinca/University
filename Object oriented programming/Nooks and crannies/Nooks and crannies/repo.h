#pragma once
#include "domain.h"

struct Repo {
	Profile listOfProfiles[100];
	int numberOfProfiles = 0;
};

int FindProfile(Repo* repository, int currentId)
{
	for (int iterator = 1; iterator <= repository->numberOfProfiles; iterator++)
	{
		if (GetProfileIdNumber(repository->listOfProfiles[iterator]) == currentId)
		{
			return iterator;
		}
			
	}
	return -1;
}

int AddProfile(Repo* repository, int profileIdNumber, int yearsOfRecordedService, char placeOfBirth[], char psychologicalProfile[])
{
	Profile profile;
	Profile* newProfile = &(profile);
	SetProfileIdNumber(newProfile, profileIdNumber);
	SetYearsOfRecordedService(newProfile, yearsOfRecordedService);
	SetPlaceOfBirth (newProfile, placeOfBirth);
	SetPsychologicalProfile (newProfile, psychologicalProfile);
	if (FindProfile(repository, profileIdNumber) == -1)
	{
		repository -> listOfProfiles[++(repository -> numberOfProfiles)] = profile;
		return 1;
	}
	else
		return 0;
}

int DeleteProfile(Repo* repository, int currentId)
{
	int index = FindProfile(repository, currentId);
	if (index == -1)
		return 0;
	else
	{
		for (int iterator = index; iterator < (repository -> numberOfProfiles); iterator++)
			repository -> listOfProfiles[iterator] = repository -> listOfProfiles[iterator + 1];
		(repository -> numberOfProfiles)--;
		return 1;
	}

}

void TurnIntoString(Repo repo)
{
	char printable[5001];
	int len = 0;
	for (int iterator = 1; iterator <= repo.numberOfProfiles; iterator++)
	{
		/*
		strcpy(printable + len, ConvertToString(&(repo.listOfProfiles[iterator])));
		len += sizeof(ConvertToString(&(repo.listOfProfiles[iterator])));
		printable[++len] = '\n';
		*/
		ConvertToString(&(repo.listOfProfiles[iterator]));
	}
}
