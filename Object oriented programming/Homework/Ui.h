#pragma once
#pragma once
#include "Service.h"

class Ui
{
private:
	//Service service;
	Service service;


public:
	Ui();
	~Ui();
	void UiPath(string& path);
	//void UiPathB(string& path);
	void UiAddClient(string command);
	void UiAddDwelling(string command);
	//void UiDelete(string command);
	//void UiUpdate(string command);
	void UiList();
	void UiList(string parameter);
	//void UiMyList();
	//void UiSave(string id);
	//void UiNext(string command);
	//void UiListB(string command);
	//bool UiModeA(bool exit);
	//bool UiModeB(bool exit);

};

void Menu();