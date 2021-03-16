#pragma once
#include"domain.h"
#include<vector>
#include<fstream>
#include "Windows.h"
#include<vector>
#include<exception>
#include<algorithm>
using namespace std;

class RepoFile
{
		
	public:
		string path;
		int currentIndex;
		RepoFile(string path) :path(path),currentIndex(0) {}
		virtual vector<GuardianStatue> read_from_file(string path);
		virtual void write_to_file(string path, vector<GuardianStatue> statues);
		bool exists(GuardianStatue statue);
		virtual void add_repo(GuardianStatue statue);
		void update_repo(GuardianStatue statue);
		void delete_repo(GuardianStatue statue);
		GuardianStatue search_repo(GuardianStatue statue);
		int GetSizeRepo();
		vector<GuardianStatue> GetStatues();
		void next_repo();
		virtual void open() { ShellExecuteA(NULL, NULL, "notepad.exe", this->path.c_str(), NULL, SW_SHOWMAXIMIZED); };
		GuardianStatue get_current();
	};