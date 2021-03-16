#pragma once
#include "repo.h"

struct Service {
	Repo repo;
	Repo* repository = &repo;
};

int AddElement(Service* serv, int profileIdNumber, int yearsOfRecordedService, char* placeOfBirth, char* psychologicalProfile)
{
	return AddProfile(&serv->repo, profileIdNumber, yearsOfRecordedService, placeOfBirth, psychologicalProfile);
}

int DeleteElement(Service* serv, int profileIdNumber)
{
	return DeleteProfile(serv->repository, profileIdNumber);
}

void ListElements(Service service)
{
	TurnIntoString(service.repo);
}
