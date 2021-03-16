#include "teacherwindomodel.h"


int teacherWindoModel::rowCount(const QModelIndex &parent) const
{
    if (AllStars == true)
        return this->serv.getStars().size();
    else
        return this->serv.getStarsForConstellation(astronomer.getConstelation()).size();
}

int teacherWindoModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant teacherWindoModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();
    Star st;
    if (AllStars == true)
        st = this->serv.getStars()[row];
    else
        st = this->serv.getStarsForConstellation(astronomer.getConstelation())[row];

    if (role == Qt::DisplayRole)
        {
            switch(column)
            {
            case 0:
                return QString::fromStdString((st.getName()));
            case 1:
                return QString::fromStdString(st.getConstellation());
            case 2:
                return QString::fromStdString(to_string(st.getRightAscension()));
            case 3:
                return QString::fromStdString(to_string(st.getDiameter()));
            case 4:
                return QString::fromStdString(to_string(st.getDiameter()));

            default:
                break;
            }

    }
    return QVariant();
}

bool teacherWindoModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, rowCount(), rowCount());

    endInsertRows();
    return true;
}

