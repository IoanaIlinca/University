#pragma once
#include <qabstractitemmodel.h>
#include "Repo.h"

class MyListViewModel : public QAbstractListModel
{
private:
	RepoB& repo;

public:
	MyListViewModel(RepoB& r) : repo{ r } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
};

