#pragma once
class SaleItem
{
private:
	int code;
	double price;

public:
	SaleItem(int code, double price);
	int GetCode();
	double GetPrice();
};

