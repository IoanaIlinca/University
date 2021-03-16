#include <iostream>
#include "Sale.h"
#include "Discount.h"
using namespace std;

int main()
{
	SaleItem s1(1, 22.99);
	SaleItem s2(2, 12.99);
	SaleItem s3(3, 14.99);
	Sale sale;
	sale.add(s1);
	sale.add(s2);
	sale.add(s3);
	ItemDiscount i1(1, 10);
	ItemDiscount i2(2, 15);
	SumDiscount sum;
	shared_ptr<ItemDiscount> ptrI1 = make_shared<ItemDiscount>(i1);
	shared_ptr<ItemDiscount> ptrI2 = make_shared<ItemDiscount>(i2);
	sum.add(ptrI1);
	sum.add(ptrI2);
	cout << sum.calc(sale);
	return 0;
}