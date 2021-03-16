#include"domain.h"
#include<string>
#include<stdlib.h>
#include<vector>
#include<sstream>
using namespace std;
GuardianStatue GuardianStatue::operator=(const GuardianStatue& otherStatue) {
	this->powerWordName = otherStatue.powerWordName;
	this->Material = otherStatue.Material;
	this->age = otherStatue.age;
	this->CorporealForm = otherStatue.CorporealForm;
	return *this;

}

GuardianStatue::GuardianStatue(const GuardianStatue& otherStatue)
{
	this->powerWordName = otherStatue.powerWordName;
	this->Material = otherStatue.Material;
	this->age = otherStatue.age;
	this->CorporealForm = otherStatue.CorporealForm;

}
bool GuardianStatue::operator==(const GuardianStatue& otherStatue) {
	if (this->powerWordName.compare(otherStatue.powerWordName) == 0)return true;
	else return false;
}
std::string GuardianStatue::toString() {
	std::string AgeString = std::to_string(this->age);

	return "PowerWordName: " + this->GetPowerWordName() + " " + "Material: " + this->GetMaterial() + " " + "Age: " + AgeString + " " + "Corporeal Form: " + this->GetCorporealForm();
}
vector<string> tokenize(string String, char delimiter)
{
	vector <string> result;
	stringstream StringStream(String);
	string token;
	while (getline(StringStream, token, delimiter))
		result.push_back(token);

	return result;
}
std::istream& operator>>(std::istream& InputStream, GuardianStatue& statue)
{
	string line;
	getline(InputStream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4) 
		return InputStream;
	statue.powerWordName = tokens[0];
	statue.Material = tokens[1];
	statue.age = stoi(tokens[2]);
	statue.CorporealForm = (tokens[3]);

	return InputStream;
}

std::ostream& operator<<(std::ostream& OutputStream, const GuardianStatue& statue)
{
	OutputStream << statue.powerWordName << "," << statue.Material << "," << statue.age <<","<<statue.CorporealForm<< "\n";
	return OutputStream;
}
