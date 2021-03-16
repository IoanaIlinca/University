#include "domain.h"
#include <iostream>
using namespace std;



double Client::TotalIncome()
{
	return salary;
}

ostream& Client::Display(ostream& fout)
{
	fout << name << ' ' << salary << ' ';
	return fout;
}


bool WealthyClient::isInterested(Dwelling d)
{
	if ((d.LargeBankRate() <= (salary + moneyFromInvestments)) && d.GetIsProfitable())
		return true;
	return false;
}

ostream& WealthyClient::Display(ostream& fout)
{
	fout << name << ' ' << salary << ' ' << moneyFromInvestments <<  ' ';
	return fout;
}

bool NormalClient::isInterested(Dwelling d)
{
	if (d.NormalBankRate() <= this->salary)
		return true;
	return false;
}

Dwelling::Dwelling(string type, double price, bool isProfitable)
{
	this->type = type;
	this->price = price;
	this->isProfitable = isProfitable;
}
/*
bool Dwelling::GetIsProfitable()
{
	return isProfitable;
}
*/
string Dwelling::GetType()
{
	return type;
}

double Dwelling::NormalBankRate()
{
	return price/1000;
}

double Dwelling::LargeBankRate()
{
	return price/100;
}

ostream& Dwelling::Display(ostream& fout)
{
	fout << type << ' ' << price << ' ';
	if (isProfitable == true)
		fout << "true" << '\n';
	else 
		fout << "false" << '\n';
	return fout;
}

NormalClient::NormalClient(string name, double salary)
{
	this->name = name;
	this->salary = salary;
}

WealthyClient::WealthyClient(string name, double salary, double investments)
{
	this->name = name;
	this->salary = salary;
	this->moneyFromInvestments = investments;
}

double WealthyClient::TotalIncome()
{
	return (salary + moneyFromInvestments);
}
