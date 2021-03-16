#include "Ui.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Ui::UiList()
{
	vector<shared_ptr<Client>> vect = service.GetClients();
	for (auto i : vect)
	{
		i->Display(cout);
		cout << '\n';
	}
		
	vector<Dwelling> dw = service.GetDwellings();
	for (auto i : dw)
		i.Display(cout);
}

void Ui::UiList(string parameter)
{
	vector<Dwelling> dw = service.GetDwellings(parameter);
	vector<shared_ptr<Client>> clients = service.GetClients();
	vector<shared_ptr<Client>> final;
	for (auto i : clients)
	{
		for (auto j : dw)
			if (i->isInterested(j))
				final.push_back(i);
	}

	for (auto i : final)
	{
		i->Display(cout);
		cout << '\n';
	}
		
		
}


void Ui::UiPath(string& path)
{
	ofstream fout(path, ios::out);
	vector<shared_ptr<Client>> vect = service.GetClients();
	for (auto i : vect)
	{
		i->Display(fout);
		fout << i->TotalIncome() << '\n';
		//fout << '\n';
	}

	//vector<Dwelling> dw = service.GetDwellings();
	//for (auto i : dw)
		//i.Display(fout);
	fout.close();
}

void Ui::UiAddDwelling(string command)
{
	if (command == "") // it doesn't contain anything
	{
		cout << "Not enough arguments!\n";
		return;
	}
	string type;
	double price;
	bool isProfitable;

	int currentComma = 0, lastComma = 0;

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after type
	{
		cout << "Not enough arguments!\n";
		return;
	}
	type = command.substr(0, currentComma);
	command.erase(0, currentComma + 2);
	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after price
	{
		cout << "Not enough arguments!\n";
		return;
	}
	price = stod(command.substr(0, currentComma));
	command.erase(0, currentComma + 2);

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		string chestie = (command.substr(0, currentComma));
		if (chestie == "true")
			isProfitable = true;
		else
			isProfitable = false;
		service.AddDwelling(type, price, isProfitable);
		return;
	}
}


void Ui::UiAddClient(string command)
{
	//cout << "I am in add Client";
	if (command == "") // it doesn't contain anything
	{
		cout << "Not enough arguments!\n";
		return;
	}
	string name;
	double salary;
	double investments;

	int currentComma = 0, lastComma = 0;

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after name
	{
		cout << "Not enough arguments!\n";
		return;
	}
	name = command.substr(0, currentComma);
	command.erase(0, currentComma + 2);
	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after salary
	{
		salary = stod(command.substr(0, currentComma));
		service.Add(name, salary);
		return;
	}
	salary = stod(command.substr(0, currentComma));
	command.erase(0, currentComma + 2);

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		investments = stod(command.substr(0, currentComma));
		service.Add(name, salary, investments);
		return;
	}
	
}



void Menu()
{
	Ui menu;
	
	string command;
	string path = "";
	cout << ">>";
	getline(cin, command);
	while (true)
	{
		if (command.substr(0, 9) == "addClient")
		{
			command.erase(0, 10);
			menu.UiAddClient(command);
		}
		else 
		{
			if (command.substr(0, 11) == "addDwelling")
			{
				command.erase(0, 12);
				menu.UiAddDwelling(command);
			}
			else
			{
			if (command.substr(0, 4) == "list")
			{
				command.erase(0, 5);
				//if (path == "")
				//{
					if (command == "")
						menu.UiList();
					else
						menu.UiList(command);
				//}
				//else
					//menu.UiPath(path);
			}
			else
			{
				if (command.substr(0, 12) == "fileLocation")
				{
					command.erase(0, 13);
					//path = command;
					menu.UiPath(command);
				}
				else
				{

					if (command == "exit")
						return;
					else
						cout << "Invalid command!\n";

				}

		}

		}
		}
		
		cout << ">>";
		getline(cin, command);
	}


}

Ui::Ui()
{

}

Ui::~Ui()
{

}
