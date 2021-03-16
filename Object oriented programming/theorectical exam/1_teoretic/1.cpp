#include <iostream>

#include <string>

#include <vector>

#include <utility>

#include <assert.h>

using namespace std;



class Person {

private:

	string name;

	int age;

public:

	Person(string n, int a) : name{ n }, age{ a } {}

	friend ostream& operator<<(ostream& out, Person p)

	{

		out << p.name << " is " << p.age << " years old";

		return out;

	}

};



template <typename T1, typename T2>

class MultiDictionary {

private:

	vector<pair<T1, vector<T2>>> vect;

public:

	MultiDictionary<T1, T2>& add(T1 val1, T2 val2)

	{

		for (auto p : vect)

		{

			if (p.first == val1)

			{

				p.second.push_back(val2);

				return *this;

			}



		}

		vector<T2> secondElement;

		secondElement.push_back(val2);

		vect.push_back(make_pair(val1, secondElement));

		return *this;

	}

	void print(ostream& out)

	{

		for (auto p : vect)

		{

			out << p.first << ' ';

			for (auto elem : p.second)

				out << elem << ";";

			out << " ";

		}



		out << '\n';

	}



	void erase(T1 val1, T2 val2)

	{

		pair<T1, T2> valueToBeRemoved;

		vector<pair<T1, vector<T2>>> vect2;

		bool found = false, foundKey = false;

		valueToBeRemoved = make_pair(val1, val2);

		for (auto p : vect)

		{

			if (p.first == val1)

			{
				foundKey = true;
				for (auto elem : p.second)
					if (elem == val2)
					{
						found = true;

						

						if (p.second.size() == 1)

							break;

						vector<T2> newSecondValue;

						for (auto elem : p.second)

						{

							if (elem != val2)

								newSecondValue.push_back(elem);

						}

						p.second = newSecondValue;
						break;
					}
				
				continue;
			}

			if (p.first == val1)

			{

				foundKey = true;

			}

			vect2.push_back(p);

		}

		if (!found)

		{

			if (!foundKey)

			{

				runtime_error e("Key does not exist!");

				throw e;

			}

			else

			{

				runtime_error e("Given value does not exist for given key!");

				throw e;

			}

		}

		vect = vect2;

	}



	int sizeForKey(T1 key)

	{

		for (auto p : vect)

			if (p.first == key)

				return p.second.size();

		return 0;

	}

};



int main()

{

	MultiDictionary<int, string> d1{};

	d1.add(1, "a").add(2, "b").add(1, "c").add(3, "d");

	d1.print(std::cout); // prints 1 a; 2 b; 1 c; 3 d

	try {

		d1.erase(4, "w");

		assert(false);

	}

	catch (std::runtime_error& e) {

		try {

			assert(strcmp(e.what(), "Key does not exist!") == 0);

			d1.erase(2, "w");

			assert(false);

		}

		catch (std::runtime_error& e) {

			assert(strcmp(e.what(), "Given value does not exist for given key!") == 0);

		}

	}



	d1.erase(1, "a");

	d1.print(std::cout); // prints 2 b; 1 c; 3 d 

	MultiDictionary<string, Person> d2{};

	Person p1{ "Bianca", 20 }; Person p2{ "Andrei", 21 };

	d2.add("a", p1).add("a", p2);

	d2.print(std::cout); // prints a Bianca is 20 years old; a Andrei is 21 years old;.



	assert(d2.sizeForKey("a") == 2);

	assert(d2.sizeForKey("b") == 0);

	return 0;

}