#include "Service.h"
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

Service::Service()
{
	ReadFromFile();
}

void Service::AddQuestion(string text, string user)
{
	Question q(repoQuestions.GetQuestions().size() + 1, text, user);
	repoQuestions.RepoAdd(q);
}

void Service::AddAnswer(int idQuestion, string text, string user)
{
	Answer ans(repoAnswers.GetAnswers().size() + 1, idQuestion, user, text, 0);
	repoAnswers.RepoAdd(ans);
}

void Service::ReadFromFile()
{
		string line;
		vector<string> splitted;
		ifstream fin("Questions.txt");
		while (getline(fin, line))
		{
			splitted = tokenize(line, ";");
			int id;
			string text, nameOfAsker;
			try {
				id = stoi(splitted[0]);
			}
			catch (exception ex) {

			}
			text = splitted[1];
			nameOfAsker = splitted[2];
			Question q(id, text, nameOfAsker);
			repoQuestions.RepoAdd(q);
			
		}

		fin.close();
		fin.open("Answers.txt");
		while (getline(fin, line))
		{
			splitted = tokenize(line, ";");
			int id, idOfQuestion, votes;
			string user, answer;
			try {
				id = stoi(splitted[0]);
			}
			catch (exception ex) {

			}
			try {
				idOfQuestion = stoi(splitted[1]);
			}
			catch (exception ex) {
				idOfQuestion = repoQuestions.GetIdOfQuestion(splitted[1]);
			}
			
			user = splitted[2];
			answer = splitted[3];

			try {
				votes = stoi(splitted[4]);
			}
			catch (exception ex) {

			}
			Answer a(id, idOfQuestion, user, answer, votes);
			repoAnswers.RepoAdd(a);

		}
		fin.close();
		fin.open("Users.txt");
		while (getline(fin, line))
		{
			repoUsers.RepoAdd(line);

		}
}

vector<string> Service::tokenize(string inputString, string separator)
{
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
			inputString.erase(0, endOfWord + separator.size() + 1);
			//inputString.erase(remove_if(inputString.begin(), inputString.end(), isspace), inputString.end());
			//cout << tokens.back()<<'\n';
		}
		tokens.push_back(inputString);
		return tokens;
	}
}



vector<Question> Service::GetSortedQuestions()
{
	map<int, int> QAndNoOfAns;
	for (auto q : repoQuestions.GetQuestions())
	{
		QAndNoOfAns[q.GetId()] = 0;
	}
	for (auto ans : repoAnswers.GetAnswers())
	{
		QAndNoOfAns[ans.GetIdOfQuestion()]++;
	}
	vector<pair<int, int>> vect;
	for (auto q : QAndNoOfAns)
	{
		vect.push_back(make_pair(q.second, q.first));
	}
	sort(vect.begin(), vect.end(), std::greater<pair<int, int>>());
	vector<Question> final;
	for (auto q : vect)
	{
		final.push_back(repoQuestions.GetQuestionById(q.second));
	}
	return final;
}

vector<string> Service::GetUsers()
{
	return repoUsers.GetUsers();
}

vector<Answer> Service::GetAnswers()
{
	return repoAnswers.GetAnswers();
}

vector<Answer> Service::GetAnswersForQuestion(Question q)
{
	vector<Answer> final;
	for (auto ans : repoAnswers.GetAnswers())
	{
		if (ans.GetIdOfQuestion() == q.GetId())
			final.push_back(ans);
	}
	return final;
}
