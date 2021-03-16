#include "GUI.h"
#include <qformlayout.h>
#include <qlayout.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
#include <QtCharts/qbarset.h>
#include <vector>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE
//#include <iostream>
//using namespace std;
using namespace QtCharts;

void GUI::initGUI()
{
	this->evidenceListWidget = new QListWidget{};
	this->idLineEdit = new QLineEdit{};
	this->imageClarityLevelLineEdit = new QLineEdit{};
	this->measurementLineEdit = new QLineEdit{};
	this->photographLineEdit = new QLineEdit{};
	this->quantityLineEdit = new QLineEdit{};
	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };

	mainLayout->addWidget(this->evidenceListWidget);

	QFormLayout* evidenceDetailsLayout = new QFormLayout{};
	evidenceDetailsLayout->addRow("Id", this->idLineEdit);
	evidenceDetailsLayout->addRow("Measurement", this->measurementLineEdit);
	evidenceDetailsLayout->addRow("Image clarity level", this->imageClarityLevelLineEdit);
	evidenceDetailsLayout->addRow("Quantity", this->quantityLineEdit);
	evidenceDetailsLayout->addRow("Photograph", this->photographLineEdit);

	mainLayout->addLayout(evidenceDetailsLayout);

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->addButton, 0, 0);
	buttonsLayout->addWidget(this->deleteButton, 0, 1);
	buttonsLayout->addWidget(this->updateButton, 0, 2);
	buttonsLayout->addWidget(this->undoButton, 0, 3);
	buttonsLayout->addWidget(this->redoButton, 0, 4);

	mainLayout->addLayout(buttonsLayout);
		/*
	QBarSet* set0 = 
	QtCharts::QBarSet* set1 = new QtCharts::QBarSet("John");
	QtCharts::QBarSet* set2 = new QtCharts::QBarSet("Axel");
	QtCharts::QBarSet* set3 = new QtCharts::QBarSet("Mary");
	QtCharts::QBarSet* set4 = new QtCharts::QBarSet("Samantha");

	*set0 << 1 << 2 << 3 << 4 << 5 << 6;
	*set1 << 5 << 0 << 0 << 4 << 0 << 7;
	*set2 << 3 << 5 << 8 << 13 << 8 << 5;
	*set3 << 5 << 6 << 7 << 3 << 4 << 5;
	*set4 << 9 << 7 << 5 << 3 << 1 << 2;*/
}

void GUI::populateList()
{
	this->evidenceListWidget->clear();

	vector<PieceOfEvidence> Evi = this->serv.GetEvidence();
	for (PieceOfEvidence& p : Evi)
		this->evidenceListWidget->addItem(QString::fromStdString(p.GetId()) + ", " + QString::fromStdString((p.GetMeasurement())) + ", " + QString::fromStdString(to_string(p.GetImageClarityLevel())) + ", " + QString::fromStdString(to_string(p.GetQuantity())) + ", " + QString::fromStdString(p.GetPhotograph()));
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(this->evidenceListWidget, &QListWidget::itemSelectionChanged, [this]()
		{
			int selectedIndex = this->getSelectedIndex();

			if (selectedIndex < 0)
				return 0;

			PieceOfEvidence p = this->serv.GetEvidence()[selectedIndex];
			this->idLineEdit->setText(QString::fromStdString(p.GetId()));
			this->measurementLineEdit->setText(QString::fromStdString(p.GetMeasurement()));
			this->imageClarityLevelLineEdit->setText(QString::fromStdString(to_string(p.GetImageClarityLevel())));
			this->quantityLineEdit->setText(QString::fromStdString(to_string(p.GetQuantity())));
			this->photographLineEdit->setText(QString::fromStdString(p.GetPhotograph()));
		}
	);

	QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::AddPiece);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::UpdatePiece);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::DeletePiece);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &GUI::UndoPiece);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &GUI::RedoPiece);
}

int GUI::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = this->evidenceListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->idLineEdit->clear();
		this->measurementLineEdit->clear();
		this->imageClarityLevelLineEdit->clear();
		this->quantityLineEdit->clear();
		this->photographLineEdit->clear();
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void GUI::AddPiece()
{
	string id = this->idLineEdit->text().toStdString(), measurement = this->measurementLineEdit->text().toStdString(), photograph = this->photographLineEdit->text().toStdString();
	int quantity;
	double imageClarityLevel;
	try 
	{
		quantity = stoi(this->quantityLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		quantity = 0;
	}
	try
	{
		imageClarityLevel = stod(this->imageClarityLevelLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		imageClarityLevel = 0.0;
	}
	
	string message = this->serv.ServiceAdd(id, measurement, imageClarityLevel, quantity, photograph);
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
		
	
	this->populateList();
	int lastElement = this->serv.GetEvidence().size() - 1;
	this->evidenceListWidget->setCurrentRow(lastElement);
}

void GUI::UpdatePiece()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No piece was selected");
		return;
	}
	string id = this->idLineEdit->text().toStdString(), measurement = this->measurementLineEdit->text().toStdString(), photograph = this->photographLineEdit->text().toStdString();
	int quantity;
	double imageClarityLevel;
	try
	{
		quantity = stoi(this->quantityLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		quantity = 0;
	}
	try
	{
		imageClarityLevel = stod(this->imageClarityLevelLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		imageClarityLevel = 0.0;
	}
	string message = this->serv.ServiceUpdate(id, measurement, imageClarityLevel, quantity, photograph);
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
		
	//this->serv.ServiceUpdate(id, measurement, imageClarityLevel, quantity, photograph);
	this->populateList();
	this->evidenceListWidget->setCurrentRow(selectedIndex);
}

void GUI::DeletePiece()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No piece was selected");
		return;
	}
	string id = this->idLineEdit->text().toStdString();
	
	string message = this->serv.ServiceDelete(id);
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	this->populateList();
	int lastElement = this->serv.GetEvidence().size() - 1;
	this->evidenceListWidget->setCurrentRow(lastElement);
}

void GUI::UndoPiece()
{
	
	string message = this->serv.Undo();;
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	this->populateList();
	//int index = this->getSelectedIndex();
	//this->evidenceListWidget->setCurrentRow(index);
}

void GUI::RedoPiece()
{
	string message = this->serv.Redo();;
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	//this->serv.Redo();
	this->populateList();
	//int index = this->getSelectedIndex();
	//this->evidenceListWidget->setCurrentRow(index);
}

GUI::GUI(Service& s) : serv { s }
{
	this->initGUI();
	this->populateList();
	this->connectSignalsAndSlots();
}
