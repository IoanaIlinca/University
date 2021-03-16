#include "UsersWindow.h"
#include <qmessagebox.h>
#include <qinputdialog.h>
#include <qitemdelegate.h>
#include <qcommonstyle.h>
#include <qstylepainter.h>



UsersWindow::UsersWindow(Service& s, listViewQuestionsModel* model, QWidget* parent)
	: QWidget(parent), serv{s}, model{model}
{
	ui.setupUi(this);
	
	Question* q = new Question(1, "ana", "mere");
	modelAns = new listViewAnswerModel{ serv, *q };
	emit modelAns->dataChanged(QModelIndex(), QModelIndex());
	ui.listViewAnswers->setModel(modelAns);
	ui.listViewQuestions->setModel(this->model);
	ui.listViewQuestions->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.listViewAnswers->hide();
	this->connectSignalsAndSlots();
}

UsersWindow::~UsersWindow()
{
}

void UsersWindow::connectSignalsAndSlots()
{
	QEvent* eve = new QEvent{ QEvent::MouseButtonPress };
	if (this->event(eve))
		emit modelAns->dataChanged(QModelIndex(), QModelIndex());
	QObject::connect(this->ui.listViewQuestions, &QListView::clicked, this, &UsersWindow::DisplayAnswers);
	QObject::connect(this->ui.pushButtonAskQuestion, &QPushButton::clicked, this, &UsersWindow::AskQuestion);
	QObject::connect(this->ui.pushButtonAnswer, &QPushButton::clicked, this, &UsersWindow::AnswerQuestion);
}

void UsersWindow::AskQuestion()
{
	string questionText = this->ui.lineEditAskQuestion->text().toStdString();
	if (questionText == "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString("You must write a question!"));
		return;
	}
	this->serv.AddQuestion(questionText, this->windowTitle().toStdString());
	emit model->dataChanged(QModelIndex(), QModelIndex());
}

void UsersWindow::AnswerQuestion()
{
	string answerText = this->ui.lineEditAnswer->text().toStdString();
	if (answerText == "")
	{
		QMessageBox::critical(this, "Error", QString::fromStdString("You must write an answe!"));
		return;
	}
	string str = this->ui.listViewQuestions->selectionModel()->currentIndex().data().toString().toStdString();
	vector<string> vect = serv.tokenize(str, ";");
	this->serv.AddAnswer(stoi(vect[0]), answerText, this->windowTitle().toStdString());
	emit modelAns->dataChanged(QModelIndex(), QModelIndex());
}



void UsersWindow::DisplayAnswers()
{
	ui.listViewAnswers->show();
	//Question q;
	string str = this->ui.listViewQuestions->selectionModel()->currentIndex().data().toString().toStdString();
	vector<string> vect = serv.tokenize(str, ";");
	Question* q = new Question{ stoi(vect[0]), vect[1], vect[2] };
	modelAns = new listViewAnswerModel{ serv, *q };
	ui.listViewAnswers->setModel(modelAns);
	/*ui.listViewAnswers->setSelectionMode(QAbstractItemView::MultiSelection);
	ui.listViewAnswers->selectAll();
	ui.listViewAnswers.sele
	ui.listViewAnswers->setStyleSheet("QListView::item:selected{background-color: yellow;}");
	
	ui.listViewAnswers->selectionModel()->Deselect;*/
}
