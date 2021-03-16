#pragma once
#include "SaleItem.h"
#include <vector>
using namespace std;

class Sale
{
private:
	vector<SaleItem> sales;
public:
	void add(SaleItem s);
	vector<SaleItem> GetItems();
	
};

