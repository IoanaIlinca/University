#ifndef TEACHERWINDOMODEL_H
#define TEACHERWINDOMODEL_H
#include <qabstractitemmodel.h>
#include "service.h"

class teacherWindoModel  : public QAbstractListModel
{
private:
    Service& serv;
    Astronomer astronomer;
    bool AllStars;
    //string& user;

public:

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
public:
    teacherWindoModel(Service& s, Astronomer t, bool AllS) : serv{ s }, astronomer{ t }, AllStars{ AllS } {}
};

#endif // TEACHERWINDOMODEL_H
