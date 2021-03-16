#include "editablestudents.h"
#include "ui_editablestudents.h"

editableStudents::editableStudents(Service& s, vector<string> v, QWidget *parent) :
    QMainWindow(parent), serv(s), vect(v),
    ui(new Ui::editableStudents)
{
    ui->setupUi(this);
    init();
    ConnectSignalsAndSlots();
}

editableStudents::~editableStudents()
{
    delete ui;
}

void editableStudents::init()
{
    this->ui->idlabel->setText(QString::fromStdString(vect[0]));
    this->ui->nameLabel->setText(QString::fromStdString(vect[1]));
    this->ui->emailLineEdit->setText(QString::fromStdString(vect[2]));
    this->ui->yearLabel->setText(QString::fromStdString(vect[3]));
    this->ui->titleLineEdit->setText(QString::fromStdString(vect[4]));
    this->ui->coordinatorLabel->setText(QString::fromStdString(vect[5]));
}

void editableStudents::ConnectSignalsAndSlots()
{
    connect(this->ui->savePushButton, &QPushButton::clicked, this, &editableStudents::Save);
    connect(this->ui->cancelPushButton, &QPushButton::clicked, this, &editableStudents::Cancel);
}

void editableStudents::Save()
{
    string email = this->ui->emailLineEdit->text().toStdString();
    string title = this->ui->titleLineEdit->text().toStdString();
    //serv.UpdateStudent(vect[0], vect[1], email, stoi(vect[3]), title, vect[5]);
    this->close();
}

void editableStudents::Cancel()
{
    this->close();
}
