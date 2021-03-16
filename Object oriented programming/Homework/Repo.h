#pragma once
#include "domain.h"
#include <vector>
#include <memory>
#include <stack>
using namespace std;

class Repo
{
protected:
	vector<shared_ptr<Client>> Clients;
	vector<Dwelling> Dwellings;

public:

	/*  Adds a piece in the array of pieces */
	void Add(shared_ptr<Client> newClient);
	void Add(Dwelling newDwelling);

	vector<shared_ptr<Client>> GetClients();
	vector<Dwelling> GetDwellings();


	/* Overwrites the << operator */
	//friend ostream& operator<<(ostream& output, const Repo& rep);
	
};
