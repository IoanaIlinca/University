#pragma once
#include <qabstractitemmodel.h>
#include "Service.h"

class listViewAnswerModel : public QAbstractListModel
{
private:
	Service& serv;
	Question question;
	//string& user;

public:
	listViewAnswerModel(Service& s, Question q/*, string& user*/) : serv{ s }, question{ q }/*, user{ user }*/{};

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
};

