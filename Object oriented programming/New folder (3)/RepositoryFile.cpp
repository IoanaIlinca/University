#include "RepositoryFile.h"

vector<GuardianStatue> RepoFile::read_from_file(string path)
{
	ifstream FileIn(path);
	vector<GuardianStatue> Statues;
	GuardianStatue statueRead;
	if (!FileIn.is_open())ofstream FileIn(path,ios::out);
	while (FileIn >> statueRead) {
		Statues.push_back(statueRead);

	}
	FileIn.close();
	return Statues;
}

void RepoFile::write_to_file(string path,vector<GuardianStatue> statues)
{
	ofstream FileOut(path, ios::out);	
	
	for (auto statue : statues) {
		FileOut << statue;
	}
	FileOut.close();
}

bool RepoFile::exists(GuardianStatue statueSearched)
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	int ok = 0;
	for (auto statue : Statues) {
		if (statue == statueSearched) {
			ok = 1;}}
	if (ok == 1)return true;
	else return false;

}

void RepoFile::add_repo(GuardianStatue statue)
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	if (this->exists(statue) == true)throw std::exception();

	else
	{

		Statues.push_back(statue);
	}
	this->write_to_file(this->path, Statues);
}



void RepoFile::update_repo(GuardianStatue statueUpdate)
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	if (this->exists(statueUpdate) == false)throw std::exception();

	else {
		for (GuardianStatue& statue:Statues) {
			if (statue == statueUpdate)
				statue = statueUpdate;
		}
	}
	this->write_to_file(this->path, Statues);
}

void RepoFile::delete_repo(GuardianStatue statue)
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	if (this->exists(statue) == false)throw std::exception();

	else
	{

		vector<GuardianStatue>::iterator searchedStatue = find(Statues.begin(), Statues.end(), statue);
		int position = distance(Statues.begin(), searchedStatue);
		Statues.erase(Statues.begin() + position);

	}
	this->write_to_file(this->path, Statues);
}

GuardianStatue RepoFile::search_repo(GuardianStatue statueSearch)
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	if (this->exists(statueSearch) == false)throw std::exception();

	else
	{
		for (GuardianStatue& statue : Statues)
		{
			if (statue == statueSearch)
				return statue;}}}


int RepoFile::GetSizeRepo()
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	return Statues.size();
}

vector<GuardianStatue> RepoFile::GetStatues()
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	return Statues;
}

void RepoFile::next_repo()
{
	
	if (this->currentIndex == this->GetSizeRepo()-1)this->currentIndex = 0;
	else {
		this->currentIndex++;
	}
}

GuardianStatue RepoFile::get_current()
{
	vector<GuardianStatue> statues = this->GetStatues();
	return statues.at(this->currentIndex);

}
