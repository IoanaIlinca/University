#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include <qmessagebox.h>
#include "editablestudents.h"

TeacherWindow::TeacherWindow(Service& s, teacherWindoModel* m, Astronomer a, QWidget *parent) :
    ui(new Ui::TeacherWindow), QMainWindow(parent), serv(s), model(m), astronomer{ a }
{
    ui->setupUi(this);
    ui->myStudentsTableView->setModel(model);
    ui->searchListView->setSelectionMode(QAbstractItemView::SingleSelection);
    searchModel = new searchWindowModel(serv, ";");
    ui->searchListView->setModel(searchModel);
    ConnectSignalsAndSlots();
    InitFunction();
}

TeacherWindow::~TeacherWindow()
{
    this->serv.WriteToFile();
    delete ui;
}

void TeacherWindow::InitFunction()
{
    ui->myStudentsTableView->setModel(model);
}

void TeacherWindow::ConnectSignalsAndSlots()
{
    QObject::connect(this->ui->searchLineEdit, &QLineEdit::textChanged, this, &TeacherWindow::Search);
    QObject::connect(this->ui->addStudentPushButton, &QPushButton::clicked, this, &TeacherWindow::AddStudent);
    //QObject::connect(this->ui->myStudentsTableView, &QListView::clicked, this, &TeacherWindow::EditStudent);
    QObject::connect(this->ui->starsFromMyConstellationCheckBox, &QCheckBox::clicked, this, &TeacherWindow::StarsFromMyConstellation);
    //QObject::connect(this->ui->starsFromMyConstellationCheckBox, &QCheckBox::checkState() this, &TeacherWindow::AllStars);
}

void TeacherWindow::Search()
{
    string input = this->ui->searchLineEdit->text().toStdString();
    searchModel =  new searchWindowModel(serv, input);
    ui->searchListView->setModel(searchModel);
    emit searchModel->dataChanged(QModelIndex(), QModelIndex());
}

void TeacherWindow::AddStudent()
{
    string name = this->ui->nameLineEdit->text().toStdString();
    string constelation = astronomer.getConstelation();
    int rightAscension, declination;
    double diameter;
    try {
        rightAscension = stoi(this->ui->rightAscensionLineEdit->text().toStdString());
    }
    catch (exception ex)
    {
        QMessageBox::critical(this, "Error", QString::fromStdString("right ascension must be an integer!"));
        return;
    }
    try {
        declination = stoi(this->ui->declinationLineEdit->text().toStdString());
    }
    catch (exception ex)
    {
        QMessageBox::critical(this, "Error", QString::fromStdString("declination must be an integer!"));
        return;
    }
    try {
        diameter = stod(this->ui->diameterLineEdit->text().toStdString());
    }
    catch (exception ex)
    {
        QMessageBox::critical(this, "Error", QString::fromStdString("diameter must be a positive number!"));
        return;
    }
    string messages = this->serv.AddStar(name, constelation, rightAscension, declination, diameter);
    if (messages != "")
    {
        QMessageBox::critical(this, "Error", QString::fromStdString(messages));
        return;
    }
    this->model = new teacherWindoModel(serv, astronomer, currentState);
    ui->myStudentsTableView->setModel(model);
    emit model->dataChanged(QModelIndex(), QModelIndex());
    
    
}

void TeacherWindow::EditStudent()
{
    string str = this->ui->myStudentsTableView->selectionModel()->currentIndex().data().toString().toStdString();
    vector<string> vect = serv.tokenize(str, ",");
    QMainWindow* newWindow = new QMainWindow(this);
    newWindow->setWindowTitle(QString::fromStdString(vect[1]));
    newWindow->show();
    //emit searchModel->dataChanged(QModelIndex(), QModelIndex());
   // emit model->dataChanged(QModelIndex(), QModelIndex());
}



void TeacherWindow::StarsFromMyConstellation()
{
    this->model = new teacherWindoModel(serv, astronomer, false);
    currentState = false;
    ui->myStudentsTableView->setModel(this->model);
    //emit model->dataChanged(QModelIndex(), QModelIndex());
}

void TeacherWindow::AllStars()
{
    this->model = new teacherWindoModel(serv, astronomer, true);
    currentState = true;
    ui->myStudentsTableView->setModel(model);
    //emit model->dataChanged(QModelIndex(), QModelIndex());
}
