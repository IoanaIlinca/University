#pragma once
#include <vector>
#include "Question.h"
#include "Answer.h"
using namespace std;

class RepoQuestion
{
private:
	vector<Question> vect;

public:
	void RepoAdd(Question q);

	int GetIdOfQuestion(string q);

	Question GetQuestionById(int id);

	//vector<Question> GetSortedQuestions();

	vector<Question> GetQuestions();
};

class RepoAnswer
{
private:
	vector<Answer> vect;

public:
	void RepoAdd(Answer a);

	vector<Answer> GetAnswers();
};

class RepoUser
{
private:
	vector<string> vect;

public:
	void RepoAdd(string name);

	vector<string> GetUsers();
};