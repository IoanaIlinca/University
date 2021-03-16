#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>
#include "service.h"
#include "teacherwindomodel.h"
#include "searchwindowmodel.h"
#include "chart.h"

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT
    friend class Chart;
public:
    explicit TeacherWindow(Service& s, teacherWindoModel* m, Astronomer a, QWidget *parent = nullptr);
    ~TeacherWindow();

private:
    Ui::TeacherWindow *ui;
    Service& serv;
    teacherWindoModel* model;
    searchWindowModel* searchModel;
    Astronomer astronomer;
    bool currentState = true;

    Chart *chart;


    void InitFunction();
    void ConnectSignalsAndSlots();
    void Search();
    void AddStudent();

    void EditStudent();
    void StarsFromMyConstellation();
    void AllStars();
};

#endif // TEACHERWINDOW_H
