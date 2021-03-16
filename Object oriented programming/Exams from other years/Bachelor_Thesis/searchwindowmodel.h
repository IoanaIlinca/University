#ifndef SEARCHWINDOWMODEL_H
#define SEARCHWINDOWMODEL_H
#include <qabstractitemmodel.h>
#include "service.h"

class searchWindowModel : public QAbstractListModel
{
private:
    Service& serv;
    string text;
public:
    searchWindowModel(Service& s, string t) : serv{s}, text{t} {}
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
};

#endif // SEARCHWINDOWMODEL_H
