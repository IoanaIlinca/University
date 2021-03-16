#pragma once
#include "Repo.h"
#include <memory>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string_view>
using namespace std;

template <class T>
class Service {
private:
	shared_ptr<Repo<T>> repository;

public:
	Service(Repo<T> rep) : repository{ rep } {}

	Service();

	void ServiceAdd(T element);

	/* Gets an element of type T and passes it to repo to delete it */
	void ServiceDelete(T element);

	vector<T> GetElements();

	vector<T> GetCategory(string category);

	void ReadFromFile();

	vector<string> tokenize(string inputString, string separator);
};

template<class T>
inline Service<T>::Service()
{
	repository = std::make_shared<Repo<T>>();
	ReadFromFile();
}

template<class T>
inline void Service<T>::ServiceAdd(T element)
{
	repository->RepoAdd((element));
	return;
}

template<class T>
inline void Service<T>::ServiceDelete(T element)
{
	repository->RepoDelete(element);
}

template<class T>
inline vector<T> Service<T>::GetElements()
{
	vector<T> sortedElements = repository->GetElements();
	return sortedElements;
}

template<class T>
inline vector<T> Service<T>::GetCategory(string category)
{
	vector<T> final;
	vector<T> elements = GetElements();
	string families = "";
	//veggies.push_back(veggie);
	for (T& p : elements)
	{
		if (p.GetFamily() == category)
			final.push_back(p);

	}
	return final;
}

template<class T>
inline void Service<T>::ReadFromFile()
{
	string file = "shopping.txt", line;
	vector<string> splitted;
	ifstream fin("shopping.txt");
	while (getline(fin, line))
	{
		splitted = tokenize(line, "|");
		T element(splitted[0], splitted[1], stoi(splitted[2]));
		ServiceAdd(element);
		//assert(splitted[0] == "Potato");
	}

	fin.close();
}

template<class T>
inline vector<string> Service<T>::tokenize(string inputString, string separator)
{
	string currentWord;
	vector<string> tokens{};
	int endOfWord = 0;
	while (inputString.find_first_of(separator) != string::npos) {
		endOfWord = inputString.find_first_of(separator);
		currentWord = inputString.substr(0, endOfWord);
		while (currentWord.substr(1) == " ")
			currentWord.erase(0, 1);
		while (currentWord.substr(currentWord.size() - 1, 1) == " ")
			currentWord.pop_back();
		tokens.push_back(currentWord);
		inputString.erase(0, endOfWord + separator.size());
		inputString.erase(remove_if(inputString.begin(), inputString.end(), isspace), inputString.end());
		//cout << tokens.back()<<'\n';
	}
	tokens.push_back(inputString);
	return tokens;
}
