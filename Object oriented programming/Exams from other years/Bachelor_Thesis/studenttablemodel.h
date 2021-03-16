#ifndef STUDENTTABLEMODEL_H
#define STUDENTTABLEMODEL_H
#include <QAbstractTableModel>
#include "service.h"

class studentTableModel : public QAbstractTableModel
{
private:
    Service& serv;
    string name;
public:
    studentTableModel(Service& s, string n): serv{s}, name{n} {}

    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // STUDENTTABLEMODEL_H
