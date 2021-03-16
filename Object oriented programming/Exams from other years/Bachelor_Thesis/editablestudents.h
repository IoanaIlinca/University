#ifndef EDITABLESTUDENTS_H
#define EDITABLESTUDENTS_H

#include <QMainWindow>
#include "service.h"
namespace Ui {
class editableStudents;
}

class editableStudents : public QMainWindow
{
    Q_OBJECT

public:
    explicit editableStudents(Service& s, vector<string> v, QWidget *parent = nullptr);
    ~editableStudents();

private:
    Ui::editableStudents *ui;
    Service& serv;
    vector<string> vect;

    void init();
    void ConnectSignalsAndSlots();
    void Save();
    void Cancel();
};

#endif // EDITABLESTUDENTS_H
