#pragma once
#include "Service.h"

class Ui
{
private:
	//Service service;
	ServiceB serviceB;
	

public:
	Ui();
	~Ui();
	void UiPath(string& path);
	void UiPathB(string& path);
	void UiAdd(string command);
	void UiDelete(string command);
	void UiUpdate(string command);
	void UiList();
	void UiMyList();
	void UiSave(string id);
	void UiNext(string command);
	void UiListB(string command);
	bool UiModeA(bool exit);
	bool UiModeB(bool exit);
	
};

void Menu();