#pragma once
#include <iostream>
#include <string>
using namespace std;

class Dwelling {
private:
	string type;
	double price;
	bool isProfitable;

public:
	Dwelling(string type, double price, bool isProfitable);
	bool GetIsProfitable();

	string GetType();
	double NormalBankRate();
	double LargeBankRate();
	ostream& Display(ostream& fout);
};


class Client {
protected:
	string name;
	double salary;

public:
	Client() {}
	

	virtual ~Client() {}

	string GetName();

	virtual double TotalIncome();

	string ToString();
	


	virtual bool isInterested(Dwelling d) {  return false; }

	virtual ostream& Display(ostream& fout);
};

class NormalClient: virtual public Client{
public:
	NormalClient(string name, double salary);

	bool isInterested(Dwelling d);

	//ostream& Display(ostream& fout);
};

class WealthyClient: public Client {
private:
	double moneyFromInvestments;

public:
	WealthyClient(string name, double slary, double investments);

	double TotalIncome();

	bool isInterested(Dwelling d);

	
	ostream& Display(ostream& fout);

};
