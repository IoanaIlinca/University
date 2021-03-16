#pragma once
#include <memory>
#include "Sale.h"

class Discount
{

public:
	virtual double calc(Sale s) = 0;
	~Discount() {}
};

class ItemDiscount : public Discount
{
private:
	int code, percentage;
public:
	ItemDiscount(int c, int p) : code{ c }, percentage{ p } {}
	double calc(Sale s);
	int GetCode();

};

class SumDiscount : public Discount
{
private:
	vector<shared_ptr<Discount>> discounts;
public:
	void add(shared_ptr<Discount> d);
	double calc(Sale s);
};