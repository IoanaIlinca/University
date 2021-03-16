#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Questionsandanswerssite.h"
#include "Service.h"

class Questionsandanswerssite : public QMainWindow
{
    Q_OBJECT

public:
    Questionsandanswerssite(Service& s, QWidget* parent = Q_NULLPTR);

private:
    Service& serv;
    Ui::QuestionsandanswerssiteClass ui;
};
