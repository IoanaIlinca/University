#include "Ui.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Ui::UiList()
{
	cout << serviceB.GetRepository();
}

void Ui::UiMyList()
{
	cout << serviceB;
}

void Ui::UiPath(string& path)
{
	serviceB.ServicePath(path);
}

void Ui::UiPathB(string& path)
{
	while (path.find(".txt") == std::string::npos && path.find(".html") == std::string::npos && path.find(".csv") == std::string::npos)
	{
		cout << "Wrong file type!\nEnter path:\n>>";
		getline(cin, path);
	}
	serviceB.ServicePathB(path);
}

void Ui::UiNext(string command)
{
	if (command == "")
		cout << serviceB.Next();
	else
	{
		PieceOfEvidence piece = serviceB.Next(command);
		if (piece.GetId() == "-1")
			cout << "No element with such measurement\n";
		else
			cout << piece;
	}
}



void Ui::UiSave(string id)
{
	if (id == "")
	{
		cout << "Not enough arguments!\n";
		return;
	}

	bool result = serviceB.SaveIdToMyList(id);
	if (result == false)
		cout << "Id does not exist!\n";


}

void Ui::UiListB(string command)
{
	string measurement = "";
	int quantity = 0;

	if (command == "") // it doesn't contain anything
	{
		cout << "Not enough arguments!\n";
		return;
	}

	int currentComma = 0, lastComma = 0;

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after measurement
	{
		cout << "Not enough arguments!\n";
		return;
	}
	measurement = command.substr(0, currentComma);
	command.erase(0, currentComma + 2);

	currentComma = command.find(",");

	if (currentComma != string::npos) 
	{
		cout << "Too many arguments!\n";
		return;
	}
	try
	{
		quantity = stoi(command.substr(0, currentComma));
	}
	catch (exception ex)
	{
		cout << "Wrong type, quantity must be integer\n";
		return;
	}
	vector<PieceOfEvidence> result = serviceB.GetElements(measurement, quantity);
	if (result.size() == 0)
		cout << "No elements with their measurement equal to " << measurement << " and quantity at least " << quantity << '\n';
	else
		for (auto piece : result)
			cout << piece;
}

void Ui::UiAdd(string command)
{
	if (command == "") // it doesn't contain anything
	{
		cout << "Not enough arguments!\n";
		return;
	}
	string id = "0", measurement = "0", photograph = "0";
	double imageClarityLevel = 0;
	int quantity = 0;

	int currentComma = 0, lastComma = 0;

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments!\n";
		return;
	}
	id = command.substr(0, currentComma);
	command.erase(0, currentComma + 2);
	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments!\n";
		return;
	}
	measurement = command.substr(0, currentComma);
	command.erase(0, currentComma + 2);

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments!\n";
		return;
	}
	try
	{
		imageClarityLevel = stod(command.substr(0, currentComma));
	}
	catch (exception ex)
	{
		cout << "Wrong type, image clarity must be double\n";
		return;
	}
	
	command.erase(0, currentComma + 2);
	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments 2!\n";
		return;
	}
	try 
	{
		quantity = stoi(command.substr(0, currentComma));
	}
	catch (exception ex)
	{
		cout << "Wrong type, quantity must be integer\n";
		return;
	}

	command.erase(0, currentComma + 2);

	currentComma = command.find(",");

	if (currentComma != string::npos) // it finishes after id
	{
		cout << "Too many arguments!\n";
		return;
	}
	photograph = command;
	//command.erase(0, currentComma + 2);

	cout << serviceB.ServiceAdd(id, measurement, imageClarityLevel, quantity, photograph);
}

void Ui::UiDelete(string command)
{
	if (command == "")
	{
		cout << "Not enough arguments!\n";
		return;
	}

	bool result = serviceB.ServiceDelete(command);
	if (result == false)
		cout << "Id does not exist!\n";

}

void Ui::UiUpdate(string command)
{
	if (command == "") // it doesn't contain anything
	{
		cout << "Not enough arguments!\n";
		return;
	}
	string id = "0", measurement = "0", photograph = "0";
	double imageClarityLevel = 0;
	int quantity = 0;

	int currentComma = 0, lastComma = 0;

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments!\n";
		return;
	}
	id = command.substr(0, currentComma);
	command.erase(0, currentComma + 2);
	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments!\n";
		return;
	}
	measurement = command.substr(0, currentComma);
	command.erase(0, currentComma + 2);

	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments!\n";
		return;
	}
	try
	{
		imageClarityLevel = stod(command.substr(0, currentComma));
	}
	catch (exception ex)
	{
		cout << "Wrong type, image clarity must be double\n";
		return;
	}

	command.erase(0, currentComma + 2);
	currentComma = command.find(",");

	if (currentComma == string::npos) // it finishes after id
	{
		cout << "Not enough arguments!\n";
		return;
	}
	try
	{
		quantity = stoi(command.substr(0, currentComma));
	}
	catch (exception ex)
	{
		cout << "Wrong type, quantity must be integer\n";
		return;
	}

	command.erase(0, currentComma + 2);

	currentComma = command.find(",");

	if (currentComma != string::npos) // it finishes after id
	{
		cout << "Too many arguments!\n";
		return;
	}
	photograph = command;
	//command.erase(0, currentComma + 2);

	cout << serviceB.ServiceUpdate(id, measurement, imageClarityLevel, quantity, photograph);
}

bool Ui::UiModeA(bool exit)
{
	if (exit == false)
		return false;
	cout << "add id, measurement, imageClarityLevel, quantity, photograph(e.g.add 12sd23, 23X12X10, 0.2452, 13, DSC13241.jpg)\n";
	cout << "update id, newMeasurement, newImageClarityLevel, newQuantity, newPhotograph(e.g.update 12sd23, 12X12X12, 0.341, 3, DCS13267.jpg)\n";
	cout << "delete id(e.g. delete 12sd23)\n";
	cout << "undo\n";
	cout << "redo\n";
	cout << "list\n";
	cout << "exit\n";
	string command;
	cout << ">>";
	getline(cin, command);
	while (true)
	{
		if (command.substr(0, 3) == "add")
		{
			command.erase(0, 4);
			UiAdd(command);
		}
		else
		{
			if (command.substr(0, 6) == "update")
			{
				command.erase(0, 7);
				UiUpdate(command);
			}
			else
			{
				if (command.substr(0, 6) == "delete")
				{
					command.erase(0, 7);
					UiDelete(command);
				}
				else
				{
					if (command.substr(0, 4) == "list")
					{
						UiList();
					}
					else
					{
						if (command == "mode B")
							return UiModeB(true);
						else
						{
							if (command == "undo")
							{
								serviceB.Undo();
							}
							else
							{
								if (command == "redo")
								{
									serviceB.Redo();
								}
								else
								{
									if (command == "exit")
										return false;
									else
										cout << "Invalid command!\n";
								}
								
							}
							
						}
					}

				}

			}

		}
		cout << ">>";
		getline(cin, command);
	}
	return false;
}

bool Ui::UiModeB(bool exit)
{
	if (exit == false)
		return false;
	cout << "next\n";
	cout << "save id (e.g. save 12sd23)\n";
	cout << "list measurement, quantity (e.g. list 23X12X10, 2)\n";
	cout << "mylist\n";
	cout << "exit\n";
	string command;
	cout << ">>";
	getline(cin, command);
	while (true)
	{
		if (command.substr(0, 4) == "next")
		{
			command.erase(0, 5);
			UiNext(command);
		}
		else
		{
			if (command.substr(0, 4) == "save")
			{
				command.erase(0, 5);
				UiSave(command);
			}
			else
			{
				if (command.substr(0, 4) == "list")
				{
					command.erase(0, 5);
					UiListB(command);
				}
				else
				{
					if (command.substr(0, 6) == "mylist")
					{
						UiMyList();
					}
					else
					{
						if (command == "mode A")
							return UiModeA(true);
						else
						{
							if (command == "exit")
								return false;
							else
								cout << "Invalid command!\n";
						}
						
					}
				}

			}

		}
		cout << ">>";
		getline(cin, command);
	}
	return false;
}

void Menu()
{
	Ui menu;
	string path;
	cout << "Enter a file path, exactly as it is in the computer:\n";
	cout << ">>";
	getline(cin, path);
	//path.erase(0, 13);
	//cout << path;

	menu.UiPath(path);

	cout << "Enter a file path for myList, exactly as it is in the computer:\n";
	cout << ">>";
	getline(cin, path);

	menu.UiPathB(path);

	cout << "Pick a mode: mode A/mode B\n";
	
	
	string mode;
	cout << ">>";
	getline(cin, mode);
	bool ok = true;
	while (ok)
	{
		if (mode == "mode A")
		{
			ok = menu.UiModeA(true);
			//return;
		}
		if (mode == "mode B")
		{
			ok = menu.UiModeB(true);
			//return;
		}
		if (mode == "exit")
			break;
		if (mode != "mode A" && mode != "mode B")
		{
			cout << "Incorrect!\n";
			cout << "Pick a mode: mode A/mode B\n>>";
			getline(cin, mode);
		}
		
			
	}
	
		
}

Ui::Ui()
{

}

Ui::~Ui() 
{

}
