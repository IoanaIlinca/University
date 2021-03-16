#include <iostream>
#include <vector>
#include <memory>
using namespace std;

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

class Sale
{
private:
	vector<SaleItem> sales;
public:
	void add(SaleItem s);
	vector<SaleItem> GetItems();
	
};

void Sale::add(SaleItem s)
{
	sales.push_back(s);
}

vector<SaleItem> Sale::GetItems()
{
	return sales;
}


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


double ItemDiscount::calc(Sale s)
{
    for (auto item : s.GetItems())
    {
        if (item.GetCode() == code)
            return (item.GetPrice() * percentage) / 100.0;
    }
}

int ItemDiscount::GetCode()
{
    return code;
}

void SumDiscount::add(shared_ptr<Discount> d)
{
    discounts.push_back(d);
}

double SumDiscount::calc(Sale s)
{
    double sum = 0.0;
    for (auto disc : discounts)
    {
        double d = disc->calc(s);
        sum += d;

    }
    return sum;
}


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