#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
	vector<T> vect;
	int maxCapacity;
public:
	Stack(int cap) : maxCapacity{ cap } {}
	int getMaxCapacity()
	{
		return maxCapacity;
	}
	Stack<T> operator+(T elem)
	{
		Stack<T> st(this->getMaxCapacity());
		st = *this;
		exception ex("Stack is full!");
		if (st.vect.size() == st.maxCapacity)
			throw ex;
		st.vect.push_back(elem);
		return st;
	}
	T pop()
	{
		T elem = vect[vect.size() - 1];
		vect.pop_back();
		return elem;
	}
	Stack<T> operator=(const Stack<T>& st)
	{
		//if (*this == st)
			//return *this;
		this->maxCapacity = st.maxCapacity;
		while (!vect.empty())
			vect.pop_back();
		for (auto elem : st.vect)
		{
			this->vect.push_back(elem);
		}
		return *this;
	}
};


int main()
{
	Stack<string> s{ 2 };
	assert(s.getMaxCapacity() == 2);
	try {
		s = s + "examination";
		s = s + "oop";
		s = s + "test";
	}
	catch (std::exception& e) {
		assert(strcmp(e.what(), "Stack is full!") == 0);
	}
	
	assert(s.pop() == "oop");
	assert(s.pop() == "examination");
	return 0;
}