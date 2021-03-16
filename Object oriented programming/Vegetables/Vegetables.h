#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Vegetables.h"

class Vegetables : public QMainWindow
{
    Q_OBJECT

public:
    Vegetables(QWidget *parent = Q_NULLPTR);

private:
    Ui::VegetablesClass ui;
};
