#pragma once
#include <string>
using namespace std;

class Question {
private:
	int id;
	string text, nameOfAsker;

public:
	Question(int ID, string TEXT, string NAME) : id{ ID }, text{ TEXT }, nameOfAsker{ NAME } {}

	int GetId();

	string GetText();

	string GetNameOfAsker();
};
