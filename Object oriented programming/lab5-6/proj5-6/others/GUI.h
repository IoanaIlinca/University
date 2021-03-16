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
	
	// Graphical elements
	QListWidget* evidenceListWidget;
	QLineEdit* idLineEdit, *measurementLineEdit, *photographLineEdit, *quantityLineEdit, *imageClarityLevelLineEdit;
	QPushButton* addButton, * deleteButton, * updateButton, * undoButton, * redoButton;		

	void initGUI();
	void populateList();
	void connectSignalsAndSlots();

	int getSelectedIndex() const;
	void AddPiece();
	void UpdatePiece();
	void DeletePiece();
	void UndoPiece();
	void RedoPiece();


public:
	GUI(Service& s);
};