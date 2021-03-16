#include "domain.h"



string Person::GetName()
{
	return name;
}

string Person::GetFamily()
{
	return family;
}

list<string> Person::GetParts()
{
	return parts;
}

void Person::SetName(string n)
{
	this->name = n;
}

void Person::SetFamily(string f)
{
	this->family = f;
}

void Person::SetParts(list<string> p)
{
	this->parts = p;
}