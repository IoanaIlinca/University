#include "Repo.h"

void RepoQuestion::RepoAdd(Question q)
{
	vect.push_back(q);
}

int RepoQuestion::GetIdOfQuestion(string q)
{
	for (auto i : vect)
	{
		if (i.GetText() == q)
			return i.GetId();
	}
	return -1;
}

Question RepoQuestion::GetQuestionById(int id)
{
	for (auto q : vect)
		if (q.GetId() == id)
			return q;
	return Question(-1, "", "");
}


vector<Question> RepoQuestion::GetQuestions()
{
	return vect;
}

void RepoAnswer::RepoAdd(Answer a)
{
	vect.push_back(a);
}

vector<Answer> RepoAnswer::GetAnswers()
{
	return vect;
}

void RepoUser::RepoAdd(string name)
{
	vect.push_back(name);
}

vector<string> RepoUser::GetUsers()
{
	return vect;
}
