#pragma once
#include <QtWidgets/QMainWindow>
#include <QShortcut>
#include "ui_Proj59_gui.h"
#include "Service.h"
#include "MyListViewModel.h"

class Proj59_gui : public QMainWindow
{
	Q_OBJECT

public:
	//Proj59_gui(ServiceB<RepoBMemory>& s, int i, QWidget* parent = Q_NULLPTR);
	Proj59_gui(ServiceB& s, MyListViewModel* model, QWidget* parent = Q_NULLPTR);

private:
	//template <typename T>
	//ServiceB<RepoBMemory>& serv;
	ServiceB& serv;
	Ui::Proj59_guiClass ui;
	MyListViewModel* model;
	QShortcut* undoShortcut = new QShortcut(this);
	QShortcut* redoShortcut = new QShortcut(this);


	void populateList();
	void populateMylist();
	void connectSignalsAndSlots();
	int getSelectedIndex() const;
	int getSelectedIndexMylist() const;
	void AddPiece();
	void UpdatePiece();
	void DeletePiece();
	void ModeA();
	void ModeB();
	void Next();
	void Save();
	void Filter();
	void Done();
	void List();
	void Undo();
	void UndoB();
	void Redo();
	void RedoB();

};

