#pragma once
#include"domain.h"
#include<vector>
#include<fstream>
#include<vector>
#include<exception>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include "RepositoryFile.h"
using namespace std;

class RepoHtml : virtual public RepoFile {

public:
	RepoHtml(string path) :RepoFile{ path } {}
	vector<GuardianStatue> read_from_file(string path);
	void write_to_file(string path, vector<GuardianStatue> statues);
	void add_repo(GuardianStatue statue) ;
	void open();
};