/********************************************************************************
** Form generated from reading UI file 'MyListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLISTWIDGET_H
#define UI_MYLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myListView
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *myListableView;

    void setupUi(QWidget *myListView)
    {
        if (myListView->objectName().isEmpty())
            myListView->setObjectName(QString::fromUtf8("myListView"));
        myListView->resize(403, 299);
        verticalLayout = new QVBoxLayout(myListView);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        myListableView = new QTableView(myListView);
        myListableView->setObjectName(QString::fromUtf8("myListableView"));

        verticalLayout->addWidget(myListableView);


        retranslateUi(myListView);

        QMetaObject::connectSlotsByName(myListView);
    } // setupUi

    void retranslateUi(QWidget *myListView)
    {
        myListView->setWindowTitle(QCoreApplication::translate("myListView", "myListView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myListView: public Ui_myListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLISTWIDGET_H
