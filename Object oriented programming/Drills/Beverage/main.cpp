#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Beverage {
private:
	string description;
public:
	Beverage() {}
	Beverage(string d) : description{ d } {}
	/*string GetDescription()
	{
		return description;
	}*/
	virtual double price() = 0;
	void print()
	{
		cout << description << ' ';
	}
	~Beverage() {}
};

class Coffee : public Beverage
{
public:
	Coffee() : Beverage("Coffee") {}
	double price() { return 2.5; }

};

class Tea : public Beverage
{
public:
	Tea() : Beverage("Tea") {}
	double price() { return 1.5; }
};

class BeverageWithMilk : public Beverage
{
private:
	int milk;
	shared_ptr<Beverage> beverage;
public:
	BeverageWithMilk(shared_ptr<Beverage> bev, int m) : beverage{ bev }, milk{ m }/*, Beverage(bev->GetDescription())*/ {}
	double price() {
		return beverage->price() + milk * 0.5;
	}
	void print()
	{
		beverage->print();
		cout << milk << ' ';
	}
};

class BeverageMachine {
public:
	BeverageMachine() {}
	void prepare(string BeverageType, int milkCount)
	{
		if (BeverageType == "Coffee")
		{
			Coffee cup;
			shared_ptr<Coffee> ptrCup = make_shared<Coffee>(cup);
			BeverageWithMilk bev(ptrCup, milkCount);
			bev.print();
			cout << bev.price() << '\n';
		}
		else
		{
			Tea cup;
			shared_ptr<Tea> ptrCup = make_shared<Tea>(cup);
			BeverageWithMilk bev(ptrCup, milkCount);
			bev.print();
			cout << bev.price() << '\n';
		}
	}
};

int main()
{
	BeverageMachine machine;
	machine.prepare("Tea", 0);
	machine.prepare("Coffee", 1);
	machine.prepare("Coffee", 2);
	return 0;
}