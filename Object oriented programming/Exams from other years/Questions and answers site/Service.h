#pragma once
#include "Repo.h" 

class Service
{
private:
	RepoAnswer repoAnswers;
	RepoQuestion repoQuestions;
	RepoUser repoUsers;

public:
	Service();

	void AddQuestion(string text, string user);
	void AddAnswer(int idQuestion, string text, string user);

	void ReadFromFile();
	
	vector<string> tokenize(string inputString, string separator);

	//int GetNumberOfAnswers(Question q);

	vector<Question> GetSortedQuestions();

	vector<string> GetUsers();
	vector<Answer> GetAnswers();
	vector<Answer> GetAnswersForQuestion(Question q);

};

