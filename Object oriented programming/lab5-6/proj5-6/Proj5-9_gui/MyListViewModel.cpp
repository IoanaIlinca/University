#include "MyListViewModel.h"

int MyListViewModel::rowCount(const QModelIndex& parent) const
{
	return this->repo.ReadFromFile().size();
}

QVariant MyListViewModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	PieceOfEvidence p = this->repo.ReadFromFile()[row];

	if (role == Qt::DisplayRole)
	{
		return QString::fromStdString(p.GetId()) + ", " + QString::fromStdString((p.GetMeasurement())) + ", " + QString::fromStdString(to_string(p.GetImageClarityLevel())) + ", " + QString::fromStdString(to_string(p.GetQuantity())) + ", " + QString::fromStdString(p.GetPhotograph());
	}

	return QVariant();
}

bool MyListViewModel::insertRows(int row, int count, const QModelIndex& parent)
{
	beginInsertRows(parent, rowCount(), rowCount());

	endInsertRows();
	return true;
}

