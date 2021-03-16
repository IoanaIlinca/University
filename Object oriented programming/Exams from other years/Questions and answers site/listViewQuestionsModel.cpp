#include "listViewQuestionsModel.h"

int listViewQuestionsModel::rowCount(const QModelIndex& parent) const
{
	return this->serv.GetSortedQuestions().size();
}

QVariant listViewQuestionsModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	Question q = this->serv.GetSortedQuestions()[row];

	if (role == Qt::DisplayRole)
	{
		QVariant* item = new QVariant(QString::fromStdString(to_string(q.GetId())) + "; " + QString::fromStdString(q.GetText()) + "; " + QString::fromStdString(q.GetNameOfAsker()));
		return *item;
	}

	return QVariant();
}


bool listViewQuestionsModel::insertRows(int row, int count, const QModelIndex& parent)
{
	beginInsertRows(parent, rowCount(), rowCount());

	endInsertRows();
	return true;
}
