#pragma once
#include <qabstractitemmodel.h>
#include "Service.h"

class listViewQuestionsModel : public QAbstractListModel
{
private:
	Service& serv;

public:
	listViewQuestionsModel(Service& s) : serv{ s } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex& index);
	bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
};

