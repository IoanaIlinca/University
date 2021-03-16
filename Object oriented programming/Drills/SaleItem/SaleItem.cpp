#include "SaleItem.h"

SaleItem::SaleItem(int code, double price)
{
	this->code = code;
	this->price = price;
}

int SaleItem::GetCode()
{
	return code;
}

double SaleItem::GetPrice()
{
	return price;
}
