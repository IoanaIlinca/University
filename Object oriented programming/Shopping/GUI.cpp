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


GUI::GUI(Service<People>& s) : serv{ s }
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
	this->filterButton = new QPushButton{ "Filter" };
	this->deleteButton = new QPushButton{ "Delete" };

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	mainLayout->addWidget(this->evidenceListWidget);
	mainLayout->addWidget(this->vegetablesInFamilyListWidget);
	this->vegetablesInFamilyListWidget->hide();
	//this->evidenceListWidget->setStyleSheet("WidgetItem:pressed{ background - color: #444444; }");
	//this->evidenceListWidget->setStyleSheet("font-weight: bold");
	

	QFormLayout* evidenceDetailsLayout = new QFormLayout{};
	evidenceDetailsLayout->addRow("Category", this->vegetableLineEdit);

	mainLayout->addLayout(evidenceDetailsLayout);

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->deleteButton, 0, 0);
	buttonsLayout->addWidget(this->filterButton, 0, 1);
	

	mainLayout->addLayout(buttonsLayout);
	mainLayout->addWidget(this->veggieListWidget);
	this->veggieListWidget->hide();
}

void GUI::populateList()
{
	this->evidenceListWidget->clear();

	vector<People> veggies = this->serv.GetElements();
	for (auto& p : veggies)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.GetFamily()) + ", " + QString::fromStdString(p.GetName()) + QString::fromStdString(to_string(p.GetQuantity())));
		
		//"QListWidget::item { border-bottom: 1px solid black; }"
		//this->evidenceListWidget->itemWidget(item)->setStyleSheet("font-weight: bold");
		if (p.GetFamily() == "cat2")
		{
			QFont* font = new QFont();
			font->setBold(true);
			item->setFont(*font);
		}
		
		this->evidenceListWidget->addItem(item);
		
	}
		
}

void GUI::populateListCategory(vector<People> veggiesFromFamily)
{
	this->evidenceListWidget->clear();

	for (auto& p : veggiesFromFamily)
	{
		this->evidenceListWidget->addItem(QString::fromStdString(p.GetFamily()) + ", " + QString::fromStdString(p.GetName()) + QString::fromStdString(to_string(p.GetQuantity())));
		
	}
}

void GUI::connectSignalsAndSlots()
{
	QObject::connect(this->evidenceListWidget, &QListWidget::itemSelectionChanged, [this]()
		{
			int selectedIndex = this->getSelectedIndex();

			if (selectedIndex < 0)
			{
				return;
			}
			
			
		}
	);

	QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::Filter);
	//QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::UpdatePiece);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::Delete);


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

void GUI::Filter()
{
	string veggieName = this->vegetableLineEdit->text().toStdString();
	vector<People> vect = this->serv.GetCategory(veggieName);
	this->populateListCategory(vect);
	/*
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
	int i = 0;
	for (auto fam : serv.GetFamilies())
	{
		if (fam == veggieFamily)
		{
			indexHighlight = i;
			break;
		}
		i++;
	}
	if (indexHighlight == -1)
	{
		QMessageBox::critical(this, "Error", "No such People");
		return;
	}
		

	if (this->evidenceListWidget->count() > 0) {
		this->evidenceListWidget->item(indexHighlight)->setSelected(true);
		this->vegetablesInFamilyListWidget->hide();
	}
	this->evidenceListWidget->setFocus();

	this->veggieListWidget->clear();
	this->veggieListWidget->show();
	for (string part : veggieParts)
		this->veggieListWidget->addItem(QString::fromStdString(part));*/
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
*/
void GUI::Delete()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No piece was selected");
		return;
	}
	People veggie = serv.GetElements()[selectedIndex];

	this->serv.ServiceDelete(veggie);
	
	
	this->populateList();
	//int lastElement = this->serv.GetElements().size() - 1;
	//this->evidenceListWidget->setCurrentRow(lastElement);
}


