#pragma once
#include "Repo.h"

class Service {
private:
	Repo repository;

public:

	void Add(string name, double salary);
	void Add(string name, double salary, double investments);
	void AddDwelling(string type, double price, bool isProfitable);

	vector<shared_ptr<Client>> GetClients();
	vector<Dwelling> GetDwellings();
	vector<Dwelling> GetDwellings(string type);
};
