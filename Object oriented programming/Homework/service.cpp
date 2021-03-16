#include "service.h"
#include <memory>
#include <fstream>
using namespace std;



void Service::Add(string name, double salary)
{
	NormalClient client(name, salary);
	repository.Add(make_shared<NormalClient>(client));
}

void Service::Add(string name, double salary, double investments)
{
	WealthyClient client(name, salary, investments);
	repository.Add(make_shared<WealthyClient>(client));
}

void Service::AddDwelling(string type, double price, bool isProfitable)
{
	Dwelling dw(type, price, isProfitable);
	this->repository.Add(dw);
}

vector<shared_ptr<Client>> Service::GetClients()
{
	return repository.GetClients();
}

vector<Dwelling> Service::GetDwellings()
{
	return repository.GetDwellings();
}

vector<Dwelling> Service::GetDwellings(string type)
{
	vector<Dwelling> vect = repository.GetDwellings();
	vector<Dwelling> final;
	for (auto i : vect)
		if (i.GetType() == type)
			final.push_back(i);
	return final;
}
