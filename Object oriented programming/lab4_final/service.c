#include "service.h"


void InitializeService()
{
	InitializeRepo();
}

DynamicArray* ServiceGetAll()
{
	return RepoGetAll();
}

int ServiceAddProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	if (CheckExisting(profileIdNumber))
		return 0;
	Profile* newProfile = CreateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService);
	RepoAddProfile(newProfile);
	return 1;

}

int ServiceUpdateProfile(int profileIdNumber, char* placeOfBirth, char* psychologicalProfile, int yearsOfRecordedService)
{
	if (!CheckExisting(profileIdNumber))
	{
		return 0;
	}
	Profile* newProfile = CreateProfile(profileIdNumber, placeOfBirth, psychologicalProfile, yearsOfRecordedService);
	RepoUpdateProfile(newProfile);
	return 1;
}

int ServiceDeleteProfile(int profileIdNumber)
{
	if (!CheckExisting(profileIdNumber))
		return 0;
	if (RepoDeleteProfile(profileIdNumber) != -1)
		return 1;
	return 0;
}

void ServiceSortProfiles(DynamicArray* newList)
{
	int iterator = 0;
	for (iterator = 0; iterator < (newList -> length - 1); iterator++)
	{
		int secondIterator = iterator + 1;
		for (secondIterator = iterator + 1; secondIterator < (newList->length); secondIterator++)
		{
			Profile* p = getElementAtPosition(newList, iterator);
			Profile* p2 = getElementAtPosition(newList, secondIterator);
			if (strcmp(p -> placeOfBirth, p2 -> placeOfBirth) > 0)
			{
				Profile* auxiliaryProfile;
				auxiliaryProfile = p;
				substitute(newList, iterator, p2);
				substitute(newList, secondIterator, auxiliaryProfile);
			}
		}

	}
}
