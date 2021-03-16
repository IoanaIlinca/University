#include "Proj59_gui.h"
#include <qmessagebox.h>
#include <qinputdialog.h>
using namespace std;


Proj59_gui::Proj59_gui(ServiceB& s, MyListViewModel* model, QWidget* parent)
	: QMainWindow(parent), serv{ s }, model{model}
{
	ui.setupUi(this);
	//ui.modesStackedWidget->setCurrentIndex(1);
	ui.myListView->setModel(this->model);
	ui.myWidget->hide();
	this->populateList();
	this->connectSignalsAndSlots();
}


void Proj59_gui::populateList()
{
	this->ui.evidenceListWidget->clear();

	vector<PieceOfEvidence> Evi = this->serv.GetEvidence();
	for (PieceOfEvidence& p : Evi)
		this->ui.evidenceListWidget->addItem(QString::fromStdString(p.GetId()) + ", " + QString::fromStdString((p.GetMeasurement())) + ", " + QString::fromStdString(to_string(p.GetImageClarityLevel())) + ", " + QString::fromStdString(to_string(p.GetQuantity())) + ", " + QString::fromStdString(p.GetPhotograph()));
}

void Proj59_gui::populateMylist()
{
	//this->ui.myListView->setModel(this->model);
	/*
	this->ui.myListView->clear();

	vector<PieceOfEvidence> mylist = this->serv.GetMyList();
	for (PieceOfEvidence& p : mylist)
		this->ui.myListView->addItem(QString::fromStdString(p.GetId()) + ", " + QString::fromStdString((p.GetMeasurement())) + ", " + QString::fromStdString(to_string(p.GetImageClarityLevel())) + ", " + QString::fromStdString(to_string(p.GetQuantity())) + ", " + QString::fromStdString(p.GetPhotograph()));
	*/
}

void Proj59_gui::connectSignalsAndSlots()
{
	QObject::connect(this->ui.evidenceListWidget, &QListWidget::itemSelectionChanged, [this]()
		{
			int selectedIndex = this->getSelectedIndex();

			if (selectedIndex < 0)
				return 0;

			PieceOfEvidence p = this->serv.GetEvidence()[selectedIndex];
			this->ui.idLineEdit->setText(QString::fromStdString(p.GetId()));
			this->ui.measurementLineEdit->setText(QString::fromStdString(p.GetMeasurement()));
			this->ui.imageClarityLevelLineEdit->setText(QString::fromStdString(to_string(p.GetImageClarityLevel())));
			this->ui.quantityLineEdit->setText(QString::fromStdString(to_string(p.GetQuantity())));
			this->ui.photographLineEdit->setText(QString::fromStdString(p.GetPhotograph()));
		}
	);
	this->undoShortcut->setKey(Qt::CTRL + Qt::Key_Z);
	this->redoShortcut->setKey(Qt::CTRL + Qt::Key_Y);
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &Proj59_gui::AddPiece);
	QObject::connect(this->ui.updateButton, &QPushButton::clicked, this, &Proj59_gui::UpdatePiece);
	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &Proj59_gui::DeletePiece);
	QObject::connect(this->ui.undoButton, &QPushButton::clicked, this, &Proj59_gui::Undo);
	QObject::connect(this->ui.undoButtonMyList, &QPushButton::clicked, this, &Proj59_gui::UndoB);
	QObject::connect(this->ui.redoButton, &QPushButton::clicked, this, &Proj59_gui::Redo);
	QObject::connect(this->ui.redoButtonMyList, &QPushButton::clicked, this, &Proj59_gui::RedoB);
	QObject::connect(this->ui.modeAButton, &QPushButton::clicked, this, &Proj59_gui::ModeA);
	QObject::connect(this->ui.modeBButton, &QPushButton::clicked, this, &Proj59_gui::ModeB);
	QObject::connect(this->ui.nextButton, &QPushButton::clicked, this, &Proj59_gui::Next);
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &Proj59_gui::Save);
	QObject::connect(this->ui.filterButton, &QPushButton::clicked, this, &Proj59_gui::Filter);
	QObject::connect(this->ui.doneButton, &QPushButton::clicked, this, &Proj59_gui::Done);
	QObject::connect(this->ui.listButton, &QPushButton::clicked, this, &Proj59_gui::List);
	QObject::connect(this->undoShortcut, &QShortcut::activated, this, &Proj59_gui::Undo);
	QObject::connect(this->redoShortcut, &QShortcut::activated, this, &Proj59_gui::Redo);
}

int Proj59_gui::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = this->ui.evidenceListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->ui.idLineEdit->clear();
		this->ui.measurementLineEdit->clear();
		this->ui.imageClarityLevelLineEdit->clear();
		this->ui.quantityLineEdit->clear();
		this->ui.photographLineEdit->clear();
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

int Proj59_gui::getSelectedIndexMylist() const
{
	QModelIndexList selectedIndexes = this->ui.myListView->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		return -1;
	}

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void Proj59_gui::AddPiece()
{
	string id = this->ui.idLineEdit->text().toStdString(), measurement = this->ui.measurementLineEdit->text().toStdString(), photograph = this->ui.photographLineEdit->text().toStdString();
	int quantity;
	double imageClarityLevel;
	try
	{
		quantity = stoi(this->ui.quantityLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		quantity = 0;
	}
	try
	{
		imageClarityLevel = stod(this->ui.imageClarityLevelLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		imageClarityLevel = 0.0;
	}

	string message = serv.ServiceAdd(id, measurement, imageClarityLevel, quantity, photograph);
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}


	this->populateList();
	int lastElement = this->serv.GetEvidence().size() - 1;
	this->ui.evidenceListWidget->setCurrentRow(lastElement);
}

void Proj59_gui::UpdatePiece()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No piece was selected");
		return;
	}
	string id = this->ui.idLineEdit->text().toStdString(), measurement = this->ui.measurementLineEdit->text().toStdString(), photograph = this->ui.photographLineEdit->text().toStdString();
	int quantity;
	double imageClarityLevel;
	try
	{
		quantity = stoi(this->ui.quantityLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		quantity = 0;
	}
	try
	{
		imageClarityLevel = stod(this->ui.imageClarityLevelLineEdit->text().toStdString());
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
	this->ui.evidenceListWidget->setCurrentRow(selectedIndex);
}

void Proj59_gui::DeletePiece()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No piece was selected");
		return;
	}
	string id = this->ui.idLineEdit->text().toStdString();

	string message = this->serv.ServiceDelete(id);
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	this->populateList();
	int lastElement = this->serv.GetEvidence().size() - 1;
	this->ui.evidenceListWidget->setCurrentRow(lastElement);
}

void Proj59_gui::ModeA()
{
	ui.modesStackedWidget->setCurrentIndex(1);
}

void Proj59_gui::ModeB()
{
	ui.modesStackedWidget->setCurrentIndex(0);
}

void Proj59_gui::Next()
{
	QStringList items;
	string measurements = "";
	vector<PieceOfEvidence> Evi = serv.GetEvidence();
	items << tr("None");
	for (auto p : Evi)
	{
		if (measurements.find(p.GetMeasurement()) == string::npos)
			items << tr(p.GetMeasurement().c_str());
		measurements += p.GetMeasurement();
	}
		

	bool ok;
	QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
		tr("Measurement:"), items, 0, false, &ok);
	if (ok && !item.isEmpty() && item != "None")
	{
		PieceOfEvidence piece = serv.Next(item.toStdString());
		for (int i = 0; i < Evi.size(); ++i)
			if (piece == Evi[i])
				this->ui.evidenceListWidget->setCurrentRow(i);
		return;
	}
		
	if (ok && (item.isEmpty() || item == "None"))
	{
		int selectedIndex = this->getSelectedIndex();
		if (selectedIndex == Evi.size() - 1)
			selectedIndex = -1;
		this->ui.evidenceListWidget->setCurrentRow(selectedIndex + 1);
	}
}

void Proj59_gui::Save()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No piece was selected");
		return;
	}
	string id = this->ui.idLineEdit->text().toStdString();
	//QModelIndex topLeft = createIndex(0, 0);
	emit model->dataChanged(QModelIndex(), QModelIndex());
	//QModelIndexList selectedIndexes = this->ui.evidenceListWidget->selectionModel()->selectedIndexes();
	serv.SaveIdToMyList(id);
	this->populateMylist();
	int lastElement = serv.GetSizeMyList() - 1;
	//this->ui.myListView->setCurrentRow(lastElement);
}



void Proj59_gui::Filter()
{
	bool checked;
	string measurement = this->ui.filterMeasurementLineEdit->text().toStdString();
	int quantity;
	try
	{
		quantity = stoi(this->ui.filterQuantityLineEdit->text().toStdString());
	}
	catch (exception ex)
	{
		QMessageBox::critical(this, "Error", QString::fromStdString("Quantity must be a positive integer!"));
		Done();
		return;
	}
	this->ui.evidenceListWidget->clear();
	vector<PieceOfEvidence> elements = serv.GetElements(measurement, quantity);
	for (PieceOfEvidence& p : elements)
		this->ui.evidenceListWidget->addItem(QString::fromStdString(p.GetId()) + ", " + QString::fromStdString((p.GetMeasurement())) + ", " + QString::fromStdString(to_string(p.GetImageClarityLevel())) + ", " + QString::fromStdString(to_string(p.GetQuantity())) + ", " + QString::fromStdString(p.GetPhotograph()));
}

void Proj59_gui::Done()
{
	ui.myWidget->hide();
	populateList();
}

void Proj59_gui::List()
{
	ui.myWidget->show();
}

void Proj59_gui::Undo()
{
	string message = this->serv.Undo();
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	this->populateList();
}

void Proj59_gui::UndoB()
{
	string message = this->serv.UndoB();
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	emit model->dataChanged(QModelIndex(), QModelIndex());
}

void Proj59_gui::Redo()
{
	string message = this->serv.Redo();;
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	//this->serv.Redo();
	this->populateList();
}

void Proj59_gui::RedoB()
{
	string message = this->serv.RedoB();;
	if (message != "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
		return;
	}
	//this->serv.Redo();
	emit model->dataChanged(QModelIndex(), QModelIndex());
}
