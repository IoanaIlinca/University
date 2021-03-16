/*
#include "UI.h"
#include<cstring>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "Validator.h"
#include<exception>
template <class T>
void UI <T>::listGuardianStatues()
{
	vector<GuardianStatue> guardianStatues = this->service->Get_Statues();
	for (GuardianStatue i : guardianStatues) {
		std::cout << i.toString() << "\n";
	}
}
template <class T>
void UI <T>::UI_add(std::stringstream& parameters)

{
	std::string currentParameter;
	getline(parameters, currentParameter, ',');
	std::string PowerWordName{ currentParameter };
	getline(parameters, currentParameter, ',');
	currentParameter.erase(0, 1);
	std::string Material{ currentParameter };
	getline(parameters, currentParameter, ',');
	int age = stoi(currentParameter);
	getline(parameters, currentParameter, '\n');
	currentParameter.erase(0, 1);
	std::string CorporealForm{ currentParameter };
	this->service->addGuardainStatue(PowerWordName, Material, age, CorporealForm);
}
template <class T>
void UI <T>::UI_update(std::stringstream& parameters)
{
	std::string currentParameter;
	getline(parameters, currentParameter, ',');
	
	std::string PowerWordName{ currentParameter };
	getline(parameters, currentParameter, ',');
	currentParameter.erase(0, 1);
	std::string NewMaterial{ currentParameter };
	getline(parameters, currentParameter, ',');

	int NewAge = stoi(currentParameter);
	getline(parameters, currentParameter, '\n');
	currentParameter.erase(0, 1);
	std::string NewCorporealForm{ currentParameter };
	this->service->updateGuardianStatue(PowerWordName, NewMaterial, NewAge, NewCorporealForm);
}
template <class T>
void UI <T>::UI_delete(std::stringstream& parameters)
{
	std::string currentParameter;
	getline(parameters, currentParameter, ',');
	std::string PowerWordName{ currentParameter };
	this->service->deleteGuardianStatue(PowerWordName);
}
template <class T>
inline void UI <T>::UI_next()
{
	GuardianStatue currentStatue = this->service->Next();
	std::cout << currentStatue.toString();
}
template <class T>
void UI <T>::UI_save(std::stringstream& parameters)
{
	std::string currentParameter;
	getline(parameters, currentParameter, ',');
	std::string PowerWordName{ currentParameter };
	this->service->saveGuardianStatue(PowerWordName);
}
template <class T>
void UI <T>::UI_open()
{
	this->service->open();
}




template <class T>
void UI <T>::UI_list_for_material(std::stringstream& parameters)
{
	std::string currentParameter;
	getline(parameters, currentParameter, ',');
	
	
	std::string Material{ currentParameter };
	getline(parameters, currentParameter, ',');
	int age=stoi(currentParameter );
	vector<GuardianStatue> guardianStatues = this->service->Get_Statues();
	for (int i = 0; i < this->service->GetNumberStatues(); i++) {
		if (guardianStatues[i].GetMaterial().compare(Material)==0) {
			if (guardianStatues[i].GetAge() < age) {
				std::cout << this->service->Get_Statues()[i].toString() << "\n";
			}
		}
		

	}
}


template <class T>
void UI <T>::run()
{
	std::string inputString, command;
	while (true) {
		try {
			getline(std::cin, inputString);

			if (inputString.compare("exit") == 0) {
				return;
			}
			if (inputString.compare("list") == 0) {
				this->listGuardianStatues();
			}
			std::stringstream parameterStream{ inputString };


			getline(parameterStream, command, ' ');

			if (command.compare("add") == 0) {
				this->UI_add(parameterStream);
				continue;
			}
			if (command.compare("update") == 0) {
				this->UI_update(parameterStream);
				continue;
			}
			if (command.compare("delete") == 0) {
				this->UI_delete(parameterStream);
				continue;
			}
			if (command.compare("mode") == 0) {
				std::string currentParameter;
				getline(parameterStream, currentParameter, ',');
				std::string ModeType{ currentParameter };
				if (ModeType.compare("B") == 0) {
					this->runModeB();
					return;
				}
			}

		}
		catch (ValidationException & Exception) {
			std::cout << Exception.what() << std::endl;
		}
		catch (std::exception&) {
			std::cout << "No!" << std::endl;
		}
		
	}
}
template <class T>
void UI <T>::runModeB()
{
	std::string inputString, command;
	while (true) {
		try {
			getline(std::cin, inputString);

			if (inputString.compare("exit") == 0) {
				return;
			}
			if (inputString.compare("mylist") == 0) {
				this->UI_open();
			}
			if (inputString.compare("next") == 0) {
				this->UI_next();
			}
			std::stringstream parameterStream{ inputString };
			getline(parameterStream, command, ' ');
			if (command.compare("save") == 0) {
				this->UI_save(parameterStream);
				continue;
			}
			if (command.compare("list") == 0) {
				this->UI_list_for_material(parameterStream);
				continue;
			}
			if (command.compare("mode") == 0) {
				std::string currentParameter;
				getline(parameterStream, currentParameter, ',');
				std::string ModeType{ currentParameter };
				if (ModeType.compare("A") == 0) {
					this->run();
					return;
				}
			}
		}
		catch (ValidationException & Exception) {
			std::cout << Exception.what() << std::endl;
		}
		catch (std::exception&) {
			std::cout << "No!" << std::endl;
		}
		
	}
}
*/