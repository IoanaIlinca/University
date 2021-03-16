#include"domain.h"
#include"Service.h"
#include"UI.h"
//#include"Tests.h"
#include"Validator.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include"RepositoryHtml.h"
#include<iostream>
using namespace std;
int main()
{
	//test_all();
	
	std::string mode;
	std::string command;
	//std::string path = "C:\Users\MADA\source\repos\LAB6OOP\LAB6OOP\File.txt";
	//std::string path = "fileLocation E:\Faculta\sem 2\oop\New folder (3)\File.txt
	//mylistLocation E:\Faculta\sem 2\oop\New folder (3)\abc.html
	
	try {
		getline(cin, command);
		if (command.find("fileLocation") == 0) {
			std::string currentParameter;
			currentParameter = command;
			currentParameter.erase(0, 13);
			cout << currentParameter;
			//getline(parameterStream, currentParameter);
			std::string path{ currentParameter };
			RepoFile Repository(path);
			ValidatorStatue Validator;
			getline(std::cin, command);
			if (command.find("mylistLocation") == 0) {
				std::string currentParameter;
				currentParameter = command;
				currentParameter.erase(0, 15);
				cout << currentParameter;
				std::string path{ currentParameter };
				
				if (path.find(".txt") != string::npos) {
					RepoFile Mylist(path);
					
					Service<RepoFile> service(&Repository,Validator,&Mylist);
					UI<RepoFile> ui(&service);
					ui.run();
					
				}
				if (path.find("csv") != string::npos) {
					RepoCsv Mylist(path);
					Service<RepoCsv> service(&Repository, Validator, &Mylist);
					UI<RepoCsv> ui(&service);
					ui.run();
				}
				if (path.find("html") != string::npos) {
					RepoHtml Mylist(path);
					Service<RepoHtml> service(&Repository, Validator, &Mylist);
					UI<RepoHtml> ui(&service);
					ui.run();
				}
			}
			
			
		}
		else {
			throw std::exception();
		}
	}
	catch (...) { std::cout << "Invalid command!"; };
	return 0;
}