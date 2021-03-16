#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class ToDo {
private:
	vector<T> vect;
	int current = 0;
public:
	ToDo() { current = 0; }
	ToDo(int c) : current(c) {}
	void operator+=(T item)
	{
		this->vect.push_back(item);
	}
	ToDo<T> operator++()
	{
		current++;
		return ToDo<T>(current);
	}
	
	void reversePrint(ostream& out)
	{
		for (int i = vect.size() - 1; i >= 0; i--)
			out << vect[i] << '\n';
	}
	auto begin()
	{
		return vect.begin();
	}
	auto end()
	{
		return vect.end();
	}
	/*
	 current()
	{
		return &ToDo<T>(current);
	}*/
};

class Activity {
private:
	string description, time;
public:
	Activity(string d, string t) : description{d}, time{t} {}
	friend ostream& operator<<(ostream& out, const Activity& act)
	{
		out << "Activity " << act.description << " will take place at " << act.time << ".";
		return out;
	}
	bool operator!=(Activity item) const
	{
		return (this->description != item.description) && (this->time != item.time);
	}
};

int main()
{
	ToDo<Activity> todo{};
	Activity tiff{ "go to TIFF movie", "20:00" };
	todo += tiff;
	Activity project{ "present project assignment", "09.20" };
	todo += project;

	// iterates through the activities and prints them as follows:
	// Activity present project assignment will take place at 09.20.
	// Activity go to TIFF movie will take place at 20.00.
	for (auto a : todo)
		std::cout << a << '\n';

	// Prints the activities as follows:
	// Activity go to TIFF movie will take place at 20.00.
	// Activity present project assignment will take place at 09.20.
	todo.reversePrint(std::cout);
	return 0;
}