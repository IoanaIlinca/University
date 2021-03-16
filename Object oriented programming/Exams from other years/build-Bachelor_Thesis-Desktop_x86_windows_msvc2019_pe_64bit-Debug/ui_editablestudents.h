/********************************************************************************
** Form generated from reading UI file 'editablestudents.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITABLESTUDENTS_H
#define UI_EDITABLESTUDENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editableStudents
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *idlabel;
    QLabel *nameLabel;
    QLineEdit *emailLineEdit;
    QLabel *yearLabel;
    QLineEdit *titleLineEdit;
    QLabel *coordinatorLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *savePushButton;
    QPushButton *cancelPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *editableStudents)
    {
        if (editableStudents->objectName().isEmpty())
            editableStudents->setObjectName(QString::fromUtf8("editableStudents"));
        editableStudents->resize(362, 269);
        centralwidget = new QWidget(editableStudents);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        idlabel = new QLabel(centralwidget);
        idlabel->setObjectName(QString::fromUtf8("idlabel"));

        verticalLayout->addWidget(idlabel);

        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        emailLineEdit = new QLineEdit(centralwidget);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));

        verticalLayout->addWidget(emailLineEdit);

        yearLabel = new QLabel(centralwidget);
        yearLabel->setObjectName(QString::fromUtf8("yearLabel"));

        verticalLayout->addWidget(yearLabel);

        titleLineEdit = new QLineEdit(centralwidget);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));

        verticalLayout->addWidget(titleLineEdit);

        coordinatorLabel = new QLabel(centralwidget);
        coordinatorLabel->setObjectName(QString::fromUtf8("coordinatorLabel"));

        verticalLayout->addWidget(coordinatorLabel);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        savePushButton = new QPushButton(centralwidget);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));

        horizontalLayout->addWidget(savePushButton);

        cancelPushButton = new QPushButton(centralwidget);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout->addWidget(cancelPushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        editableStudents->setCentralWidget(centralwidget);
        menubar = new QMenuBar(editableStudents);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 362, 26));
        editableStudents->setMenuBar(menubar);
        statusbar = new QStatusBar(editableStudents);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        editableStudents->setStatusBar(statusbar);

        retranslateUi(editableStudents);

        QMetaObject::connectSlotsByName(editableStudents);
    } // setupUi

    void retranslateUi(QMainWindow *editableStudents)
    {
        editableStudents->setWindowTitle(QCoreApplication::translate("editableStudents", "MainWindow", nullptr));
        idlabel->setText(QCoreApplication::translate("editableStudents", "Id", nullptr));
        nameLabel->setText(QCoreApplication::translate("editableStudents", "TextLabel", nullptr));
        yearLabel->setText(QCoreApplication::translate("editableStudents", "TextLabel", nullptr));
        coordinatorLabel->setText(QCoreApplication::translate("editableStudents", "TextLabel", nullptr));
        savePushButton->setText(QCoreApplication::translate("editableStudents", "Save", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("editableStudents", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editableStudents: public Ui_editableStudents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITABLESTUDENTS_H
