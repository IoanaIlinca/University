#include "Sale.h"

void Sale::add(SaleItem s)
{
	sales.push_back(s);
}

vector<SaleItem> Sale::GetItems()
{
	return sales;
}
