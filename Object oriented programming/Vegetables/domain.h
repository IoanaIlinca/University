#pragma once
#include <string>
#include <list>
using namespace std;

class Vegetable {
private:
	string name, family;
	list<string> parts;

public:
	Vegetable(string f, string n, list<string> p) : name{ n }, family{ f }, parts{ p } {}

	string GetName();

	string GetFamily();

	list<string> GetParts();

	void SetName(string n);

	void SetFamily(string f);

	void SetParts(list<string> p);
};