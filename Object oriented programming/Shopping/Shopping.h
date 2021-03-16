#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Shopping.h"

class Shopping : public QMainWindow
{
    Q_OBJECT

public:
    Shopping(QWidget *parent = Q_NULLPTR);

private:
    Ui::ShoppingClass ui;
};
