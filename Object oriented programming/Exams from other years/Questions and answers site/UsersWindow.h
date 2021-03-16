#pragma once

#include <QWidget>
#include "ui_UsersWindow.h"
#include "Service.h"
#include "listViewQuestionsModel.h"
#include "listViewAnswerModel.h"

class UsersWindow : public QWidget
{
	Q_OBJECT

public:
	UsersWindow(Service& s, listViewQuestionsModel* model, QWidget *parent = Q_NULLPTR);
	~UsersWindow();

private:
	Service& serv;
	Ui::UsersWindow ui;
	listViewQuestionsModel* model;
	listViewAnswerModel* modelAns;

	void connectSignalsAndSlots();
	void AskQuestion();
	void AnswerQuestion();
	void DisplayAnswers();
};
