#include "listViewAnswerModel.h"

int listViewAnswerModel::rowCount(const QModelIndex& parent) const
{
	return this->serv.GetAnswersForQuestion(question).size();
}

QVariant listViewAnswerModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	Answer ans = this->serv.GetAnswersForQuestion(question)[row];

	if (role == Qt::DisplayRole)
	{
		this->flags(index).setFlag(Qt::ItemFlag::ItemIsEditable, true);
		return QString::fromStdString(to_string(ans.GetId())) + ", " + QString::fromStdString(ans.GetUser()) + ", " + QString::fromStdString(ans.GetAnswer()) + ", " + QString::fromStdString(to_string(ans.GetVotes()));
	}

	return QVariant();
}

bool listViewAnswerModel::insertRows(int row, int count, const QModelIndex& parent)
{
	beginInsertRows(parent, rowCount(), rowCount());

	endInsertRows();
	return true;
}
