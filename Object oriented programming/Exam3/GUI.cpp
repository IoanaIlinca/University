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


GUI::GUI(Service<Person>& s) : serv{ s }
{
	this->initGUI();
	this->populateList();
	this->connectSignalsAndSlots();
}

void GUI::initGUI()
{
	this->evidenceListWidget = new QListWidget{};
	this->veggieListWidget = new QListWidget{};
	this->vegetablesInFamilyListWidget = new QListWidget{};
	this->vegetableLineEdit = new QLineEdit{};
	this->partsLineEdit = new QLineEdit{};
	this->traitsButton = new QPushButton{ "Show traits" };
	this->searchButton = new QPushButton{ "Search" };
	//this->partsLabel = new QLabel{};

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	mainLayout->addWidget(this->evidenceListWidget);
	mainLayout->addWidget(this->vegetablesInFamilyListWidget);
	this->vegetablesInFamilyListWidget->hide();
	

	QFormLayout* evidenceDetailsLayout = new QFormLayout{};
	evidenceDetailsLayout->addRow("Name for traits: ", this->vegetableLineEdit);
	evidenceDetailsLayout->addRow("Name or category for searching: ", this->partsLineEdit);
	

	mainLayout->addLayout(evidenceDetailsLayout);

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->searchButton, 0, 0);
	buttonsLayout->addWidget(this->traitsButton, 0, 1);

	mainLayout->addLayout(buttonsLayout);
	mainLayout->addWidget(this->veggieListWidget);
	this->veggieListWidget->hide();

	//QFormLayout* secondLayout = new QFormLayout{};
	
	//mainLayout->addLayout(secondLayout);
	//this->partsLineEdit->hide();
}

void GUI::populateList()
{
	this->evidenceListWidget->clear();

	vector<Person> veggies = this->serv.GetElements();
	for (auto& p : veggies)
	{
		this->evidenceListWidget->addItem(QString::fromStdString(p.GetFamily()) + ", " + QString::fromStdString(p.GetName()));
		
	}
		
}

void GUI::populateListVeggies(vector<Person> veggiesFromFamily)
{
	this->vegetablesInFamilyListWidget->clear();

	for (auto& p : veggiesFromFamily)
	{
		string final = "";
		for (auto part : p.GetParts())
		{
			final += ", ";
			final += part;
		}
		this->vegetablesInFamilyListWidget->addItem(QString::fromStdString(p.GetName()) + QString::fromStdString(final));
	}
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(this->evidenceListWidget, &QListWidget::itemSelectionChanged, [this]()
		{
			int selectedIndex = this->getSelectedIndex();

			if (selectedIndex < 0)
			{
				this->vegetablesInFamilyListWidget->hide();
				return;
			}
				
			/*
			string family = this->serv.GetFamilies()[selectedIndex];
			vector<Person> veggiesFromFamily, elements = this->serv.GetElements();

			for (auto veggie : elements)
			{
				if (veggie.GetFamily() == family)
					veggiesFromFamily.push_back(veggie);
			}
			this->veggieListWidget->hide();
			this->vegetablesInFamilyListWidget->show();
			populateListVeggies(veggiesFromFamily);*/
			
		}
	);

	QObject::connect(this->traitsButton, &QPushButton::clicked, this, &GUI::Traits);
	QObject::connect(this->searchButton, &QPushButton::clicked, this, &GUI::Search);
	QObject::connect(this->partsLineEdit, &QLineEdit::textChanged, this, &GUI::Search);
	//QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::DeletePiece);


	return;
}

int GUI::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = this->evidenceListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}
void GUI::Search()
{
	this->evidenceListWidget->clear();

	

	string input = this->partsLineEdit->text().toStdString();
	for (auto p : serv.GetSelected(input))
	{
		this->evidenceListWidget->addItem(QString::fromStdString(p.GetFamily()) + ", " + QString::fromStdString(p.GetName()));
	}
}
void GUI::Traits()
{
	string veggieName = this->vegetableLineEdit->text().toStdString();
	string veggieFamily = "";
	list<string> veggieParts;
	int indexHighlight = -1;
	for (auto veggie : serv.GetElements())
	{
		if (veggie.GetName() == veggieName)
		{
			veggieFamily = veggie.GetFamily();
			veggieParts = veggie.GetParts();
			break;
		}
			
	}
	

	this->veggieListWidget->clear();
	this->veggieListWidget->show();
	this->partsLineEdit->clear();
	this->partsLineEdit->show();
	string parts = "";
	for (string part : veggieParts)
	{
		this->veggieListWidget->addItem(QString::fromStdString(part));
		if (parts != "")
			parts += ", " + part;
		else
			parts += part;
		
	}
	//this->partsLineEdit->setText(QString::fromStdString(parts));
		
}
/*
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
}*/


