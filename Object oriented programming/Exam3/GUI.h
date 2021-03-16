#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QtCharts/qbarset.h>
#include "service.h"
using namespace QtCharts;


class GUI : public QWidget
{
private:
	Service<Person>& serv;
	// Graphical elements
	QListWidget* evidenceListWidget;
	QListWidget* vegetablesInFamilyListWidget;
	QListWidget* veggieListWidget;
	QLineEdit* vegetableLineEdit;
	QLineEdit* partsLineEdit;
	//QLabel* partsLabel;
	QPushButton* searchButton;	
	QPushButton* traitsButton;	

	void initGUI();
	void populateList();
	void populateListVeggies(vector<Person> veggiesFromFamily);
	void connectSignalsAndSlots();

	int getSelectedIndex() const;
	void Search();
	void Traits();
	//void AddPiece();
	//void UpdatePiece();
	//void DeletePiece();


public:
	GUI(Service<Person>& s);
};