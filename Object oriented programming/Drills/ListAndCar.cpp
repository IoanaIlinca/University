#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdexcept>
using namespace std;

class Car {
private:
    string brand;
    int cost;
public:
    Car(string b, int c) : brand{b}, cost{c} {}
    bool operator <(const Car& c) const {
         if(cost < c.cost) {
            return true;
         }
         return false;
      }
    friend ostream &operator<<( ostream &output, const Car& c ) {
         output << c.brand << " " << c.cost;
         return output;
      }
};


template <typename T1, typename T2>
class List {
private:
    vector<pair<T1, T2>> lis;
public:
    List() {}
    void add(T1 a, T2 b)
    {
        lis.push_back(make_pair(a, b));
    }
    void sortByFirstComponent()
    {
        runtime_error ex("List is empty!");
        if (lis.size() == 0)
            throw ex;

        sort(lis.begin(), lis.end(), [](const pair<T1, T2>& a, const pair<T1, T2>& b) -> bool
            {
                return a.first < b.first;
            });
    }
    void sortBySecondComponent()
    {
        runtime_error ex("List is empty!");
        if (lis.size() == 0)
            throw ex;

        sort(lis.begin(), lis.end(), [](const pair<T1, T2>& a, const pair<T1, T2>& b) -> bool
            {
                return a.second < b.second;
            });
    }
    void printReverse(std::ostream& out)
    {
        for(int i = lis.size() - 1; i >= 0; i--)
        {
            out << lis[i].first << " -> " << lis[i].second << "; ";
        }
    }
};


int main()
{
    List<Car, int> list1;
     try {
      list1.sortByFirstComponent();
      assert(false);
     }
     catch (runtime_error& e) { assert(strcmp(e.what(), "List is empty!") == 0);	}

     list1.add(Car{ "Audi", 20 }, 8);
     list1.add(Car{ "Volkswagen", 10 }, 9);
     list1.add(Car{ "Bentley", 300 }, 10);

     list1.sortByFirstComponent();
     list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Audi 20 -> 8; Volkswagen 10 -> 9
     list1.sortBySecondComponent();
     list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Volkswagen 10 -> 9; Audi 20 -> 8;
}
