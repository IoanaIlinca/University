#include "studenttablemodel.h"



int studentTableModel::columnCount(const QModelIndex &parent) const
{
    return 6;
}

int studentTableModel::rowCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant studentTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();
    Student st = serv.search(name)[0];

    if(role == Qt::DisplayRole)
    {
        switch(column)
        {
            case 0:
                return QString::fromStdString((st.getId()));
            case 1:
                return QString::fromStdString(st.getName());
            case 2:
                return QString::fromStdString(st.getEmail());
            case 3:
               return QString::fromStdString(to_string(st.getYear()));
            case 4:
                return QString::fromStdString(st.getTitle());
            case 5:
                return QString::fromStdString(st.getCoordinator());
            default:
                break;

        }


    }
    return QVariant();
}

bool studentTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
   // beginInsertRows(parent, rowCount(), columnCount());

   // endInsertRows();
    return true;
}

bool studentTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

Qt::ItemFlags studentTableModel::flags(const QModelIndex &index) const
{
    //int column = index.column();
   // if(column == 2 || column == 4)
   return Qt::ItemIsEditable;
  //  return Qt::NoItemFlags;
}
