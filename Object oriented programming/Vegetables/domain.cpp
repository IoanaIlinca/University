#include "domain.h"



string Vegetable::GetName()
{
	return name;
}

string Vegetable::GetFamily()
{
	return family;
}

list<string> Vegetable::GetParts()
{
	return parts;
}

void Vegetable::SetName(string n)
{
	this->name = n;
}

void Vegetable::SetFamily(string f)
{
	this->family = f;
}

void Vegetable::SetParts(list<string> p)
{
	this->parts = p;
}