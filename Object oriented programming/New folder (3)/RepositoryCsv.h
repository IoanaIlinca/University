#pragma once
#include"domain.h"
#include"RepositoryFile.h"
#include<vector>
#include<fstream>
#include "Windows.h"
#include<vector>
#include<exception>
#include<algorithm>
using namespace std;

class RepoCsv : virtual public RepoFile {

public:
	RepoCsv(string path) :RepoFile{ path } {}
	void add_repo(GuardianStatue statue);
	vector<GuardianStatue> read_from_file(string path);
	void write_to_file(string path, vector<GuardianStatue> statues);
	void open();
};