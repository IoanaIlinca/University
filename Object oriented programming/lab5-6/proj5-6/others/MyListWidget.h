#pragma once

#include <QWidget>
#include "ui_MyListWidget.h"

class myListView : public QWidget
{
	Q_OBJECT

public:
	myListView(QWidget *parent = Q_NULLPTR);
	~myListView();

private:
	Ui::myListView ui;
};
