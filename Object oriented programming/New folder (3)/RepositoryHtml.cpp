#include "RepositoryHtml.h"
#include<iostream>
#include<fstream>
using namespace std;

vector<GuardianStatue> RepoHtml::read_from_file(string path)
{
	cout << path;
	path = "abc.html";
	string powerWordName, CorporealForm, Material;
	int age=-1;
	bool ok = false, fileNotEmpty = false;
	vector<GuardianStatue> statues;
	ifstream FileIn("maria.html", ios::in);
	string stringToBeRead;
	
	//if (!FileIn.is_open())ofstream FileOut(path, ios::out);
	//FileIn.open(path, ios::in);
	cout << "i am in read " << FileIn.is_open() << '\n';
	//getline(FileIn, stringToBeRead);
	//cout << "\n***\n" << stringToBeRead;
	while (getline(FileIn, stringToBeRead))
		{//fileLocation C:\Users\MADA\source\repos\LAB6OOP\LAB6OOP\File.txt
		//mylistLocation C:\Users\MADA\source\repos\LAB6OOP\LAB6OOP\abc.html
		cout << stringToBeRead << "\n";
		fileNotEmpty = true;
		if (stringToBeRead.find("<!--")==0) 
		{
			
			cout << stringToBeRead << "\n";
			
			if(stringToBeRead.find("1")==4){
				cout << "\n@@" << stringToBeRead[4] << "@@\n";
				stringToBeRead.erase(0, 8);
				powerWordName = stringToBeRead;
				
			}
			if (stringToBeRead.find("2") == 4) {
				cout << "\n@@" << stringToBeRead[4] << "@@\n";
				stringToBeRead.erase(0, 8);
				Material = stringToBeRead;
				
			}
			if (stringToBeRead.find("3") == 4) {
				cout << "\n@@" << stringToBeRead[4] << "@@\n";
				stringToBeRead.erase(0, 8);
				cout << stringToBeRead << '\n';
				age = stoi(stringToBeRead);
				
			}
			if (stringToBeRead.find("4") == 4) {
				cout << "\n@@"  <<stringToBeRead[4] << "@@\n";
				stringToBeRead.erase(0, 8);
				CorporealForm = stringToBeRead;
				
				ok = true;
			}
			

		}
		if (ok==true) {
			
			ok = false;
			GuardianStatue statue{ powerWordName,Material,age,CorporealForm };
			statues.push_back(statue);
		}
		cout << "I am here";
	}
	FileIn.close();

	for (auto statue : statues) {
		std::cout << statue;
	}

	return statues;

}

void RepoHtml::write_to_file(string path, vector<GuardianStatue> statues)
{
	path = "E:\\Faculta\\sem 2\\oop\\New folder(3)\\abc.html";
	ofstream FileOut("E:\\Faculta\\sem 2\\oop\\New folder(3)\\maria.html", ios::out);
	cout << "i am in write " << FileOut.is_open() << '\n';
	FileOut << "<!DOCTYPE html>" << "\n";
	FileOut << "<html>" << "\n";
	FileOut << "<head>" << "\n";
	FileOut << "<title>Statues</title>" << "\n";
	FileOut << "</head>" << "\n";
	FileOut << "<body>" << "\n";
	FileOut << "<table border='1'>";
	for (auto statue : statues) {
		FileOut << "<tr>" << "\n";
		cout << statue;
		FileOut << "<td>" <<"\n<!--1-->"<< statue.GetPowerWordName() << "\n</td>" << "\n";
		FileOut << "<td>\n<!--2-->" << statue.GetMaterial() << "\n</td>" << "\n";
		FileOut << "<td>\n<!--3-->" << statue.GetAge() << "\n</td>" << "\n";
		FileOut << "<td>\n<!--4-->" << statue.GetCorporealForm() << "\n</td>" << "\n";
		FileOut << "</tr>" << "\n";
	}
	FileOut << "</table>" << "\n";
	FileOut << "</body>" << "\n";
	FileOut << "</html>" << "\n";
}

void RepoHtml::add_repo(GuardianStatue statue)
{
	
	vector<GuardianStatue> Statues = this->read_from_file(this->path);
	cout << "**";
	for (auto statue : Statues) {
		std::cout << statue << endl;
	}
	Statues.push_back(statue);
	//this->write_to_file(this->path, Statues);
	path = "E:\\Faculta\\sem 2\\oop\\New folder(3)\\maria.html";
	ofstream FileOut;
	FileOut.open("maria.html", ios::out);
	cout << "i am in write " << FileOut.is_open() << '\n';
	FileOut << "<!DOCTYPE html>" << "\n";
	FileOut << "<html>" << "\n";
	FileOut << "<head>" << "\n";
	FileOut << "<title>Statues</title>" << "\n";
	FileOut << "</head>" << "\n";
	FileOut << "<body>" << "\n";
	FileOut << "<table border='1'>";
	for (auto statue : Statues) {
		FileOut << "<tr>" << "\n";
		cout << statue;
		FileOut << "<td>" << "\n<!--1-->" << statue.GetPowerWordName() << "\n</td>" << "\n";
		FileOut << "<td>\n<!--2-->" << statue.GetMaterial() << "\n</td>" << "\n";
		FileOut << "<td>\n<!--3-->" << statue.GetAge() << "\n</td>" << "\n";
		FileOut << "<td>\n<!--4-->" << statue.GetCorporealForm() << "\n</td>" << "\n";
		FileOut << "</tr>" << "\n";
	}
	FileOut << "</table>" << "\n";
	FileOut << "</body>" << "\n";
	FileOut << "</html>" << "\n";

	FileOut.close();
}

void RepoHtml::open()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->path.c_str(), NULL, SW_SHOWMAXIMIZED);
}
