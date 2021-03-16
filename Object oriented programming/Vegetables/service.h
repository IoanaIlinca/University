#pragma once
#include "Repo.h"
#include <memory>
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

	vector<T> GetElements();

	vector<string> GetFamilies();

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
inline vector<T> Service<T>::GetElements()
{
	vector<T> sortedElements = repository->GetElements();
	std::sort(sortedElements.begin(), sortedElements.end(), [](T element1, T element2) {
		return element1.GetFamily() < element2.GetFamily();
		});
	return sortedElements;
}

template<class T>
inline vector<string> Service<T>::GetFamilies()
{
	vector<string> final;
	vector<T> elements = GetElements();
	string families = "";
	//veggies.push_back(veggie);
	for (T& p : elements)
	{
		if (families.find(p.GetFamily()) == string::npos)
		{
			final.push_back(p.GetFamily());
			families += p.GetFamily();
		}

	}
	return final;
}

template<class T>
inline void Service<T>::ReadFromFile()
{
	string file = "legume.txt", line;
	vector<string> splitted;
	ifstream fin("legume.txt");
	while (getline(fin, line))
	{
		splitted = tokenize(line, "|");
		list<string> parts;
		vector<string> splittedParts = tokenize(splitted[2], ",");
		for (string str : splittedParts)
			parts.push_back(str);
		T element(splitted[0], splitted[1], parts);
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
