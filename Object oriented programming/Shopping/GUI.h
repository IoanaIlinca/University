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
	Service<People>& serv;
	// Graphical elements
	QListWidget* evidenceListWidget;
	QListWidget* vegetablesInFamilyListWidget;
	QListWidget* veggieListWidget;
	QLineEdit* vegetableLineEdit;
	QPushButton* filterButton;	
	QPushButton* deleteButton;	

	void initGUI();
	void populateList();
	void populateListCategory(vector<People> veggiesFromFamily);
	void connectSignalsAndSlots();

	int getSelectedIndex() const;
	void Filter();
	//void AddPiece();
	//void UpdatePiece();
	void Delete();


public:
	GUI(Service<People>& s);
};