#pragma once
#include <string>
using namespace std;

class Answer
{
private:
	int id, idOfQuestion, votes;
	string user, answer;

public:
	Answer(int ID, int IDOFQUESTION, string USER, string ANSWER, int VOTES) : id{ ID }, idOfQuestion{ IDOFQUESTION }, user{ USER }, answer{ ANSWER }, votes{ VOTES } {}

	int GetId();

	int GetIdOfQuestion();

	int GetVotes();

	string GetUser();

	string GetAnswer();
};

