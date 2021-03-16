#include "RepositoryCsv.h"

void RepoCsv::add_repo(GuardianStatue statue)
{
	vector<GuardianStatue> Statues = this->read_from_file(this->path);

	Statues.push_back(statue);
	this->write_to_file(this->path, Statues);
}


vector<GuardianStatue> RepoCsv::read_from_file(string path)
{
	ifstream FileIn(path);
	vector<GuardianStatue> Statues;
	GuardianStatue statueRead;
	if (!FileIn.is_open())ofstream FileIn(path, ios::out);
	while (FileIn >> statueRead) {
		Statues.push_back(statueRead);

	}
	FileIn.close();
	return Statues;
}

void RepoCsv::write_to_file(string path, vector<GuardianStatue> statues)
{
	ofstream FileOut(path, ios::out);

	for (auto statue : statues) {
		FileOut << statue;
	}
	FileOut.close();
}

void RepoCsv::open()
{
	ShellExecuteA(NULL, NULL, "notepad.exe", this->path.c_str(), NULL, SW_SHOWMAXIMIZED);
}
