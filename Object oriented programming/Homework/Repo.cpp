#include "Repo.h"

void Repo::Add(shared_ptr<Client> newCl)
{
	Clients.push_back(move(newCl));
}

void Repo::Add(Dwelling newDwelling)
{
	Dwellings.push_back(newDwelling);
}

vector<Dwelling> Repo::GetDwellings()
{
	return Dwellings;
}

vector<shared_ptr<Client>> Repo::GetClients()
{
	return Clients;
}
