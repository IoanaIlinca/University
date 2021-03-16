#include "searchwindowmodel.h"

int searchWindowModel::rowCount(const QModelIndex &parent) const
{
    return this->serv.search(text).size();
}

QVariant searchWindowModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    Star st = this->serv.search(text)[row];
    if (role == Qt::DisplayRole)
       {
            return QString::fromStdString((st.getName())) + ", " + QString::fromStdString(st.getConstellation()) + ", " + QString::fromStdString(to_string(st.getRightAscension())); + ", " +  QString::fromStdString(to_string(st.getDiameter())); + ", " +  QString::fromStdString(to_string(st.getDiameter()));
    }
    return QVariant();
}

bool searchWindowModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, rowCount(), rowCount());

    endInsertRows();
    return true;
}
