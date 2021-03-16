#include "service.h"


void InitializeService()
{
	InitializeRepo();
}

AllProfiles ServiceGetAll()
{
	return RepoGetAll();
}

int ServiceAddProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	if (CheckExisting(profileIdNumber))
		return 0;
	Profile newProfile = CreateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService);
	RepoAddProfile(newProfile);
	return 1;

}

int ServiceUpdateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	if (!CheckExisting(profileIdNumber))
	{
		return 0;
	}
	Profile newProfile = CreateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService);
	RepoUpdateProfile(newProfile);
	return 1;
}

int ServiceDeleteProfile(int profileIdNumber)
{
	if (!CheckExisting(profileIdNumber))
		return 0;
	RepoDeleteProfile(profileIdNumber);
	return 1;
}

void ServiceSortProfiles(AllProfiles* newList)
{
	int iterator = 0;
	for (iterator = 0; iterator < newList -> numberOfProfiles - 1; iterator++)
	{
		int secondIterator = iterator + 1;
		for (secondIterator = iterator + 1; secondIterator < newList->numberOfProfiles; secondIterator++)
		{
			char aux1[21], aux2[21];
			strcpy(aux1, newList->listOfProfiles[iterator].placeOfBirth);
			strcpy(aux2, newList->listOfProfiles[secondIterator].placeOfBirth);
			if (strcmp(_strlwr(aux1), _strlwr(aux2)) > 0)
			{
				Profile auxiliaryProfile;
				auxiliaryProfile = newList->listOfProfiles[iterator];
				newList->listOfProfiles[iterator] = newList->listOfProfiles[secondIterator];
				newList->listOfProfiles[secondIterator] = auxiliaryProfile;
			}
		}
			
	}
}
