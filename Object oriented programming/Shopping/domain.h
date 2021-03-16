#pragma once
#include <string>
#include <list>
using namespace std;

class People {
private:
	string name, family;
	list<string> traits;

public:
	People(string f, string n, list<string> t) : name{ n }, family{ f }, traits{ t } {}

	string GetName();

	string GetFamily();

	list<string> GetTraits();
	/*	void SetName(string n);

	void SetFamily(string f);

	void SetQuantity(int q);

	friend bool operator== (const People& v1, const People& v2)
	{
		return (v2.family == v1.family) && (v2.name == v1.name) && (v2.quantity == v1.quantity);
	}*/

};