#pragma once
#include "domain.h"
#include <vector>
#include <memory>
using namespace std;

template<class T>
class Repo {
private:
	vector<shared_ptr<T>> elements;

public:
	Repo() {}

	Repo(vector<shared_ptr<T>> el) : elements{ el } {}

	void RepoAdd(T element);

	vector<T> GetElements();
};

template<class T>
inline void Repo<T>::RepoAdd(T element)
{
	shared_ptr<T> ptr = std::make_shared<T>(element);
	elements.push_back(ptr);
}

template<class T>
inline vector<T> Repo<T>::GetElements()
{
	vector<T> vect;
	for (auto i : elements)
		vect.push_back(*i);
	return vect;
}
