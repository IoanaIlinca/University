/********************************************************************************
** Form generated from reading UI file 'teacherwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWINDOW_H
#define UI_TEACHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *myStudentsTableView;
    QListView *searchListView;
    QCheckBox *starsFromMyConstellationCheckBox;
    QFormLayout *formLayout;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QPushButton *addStudentPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TeacherWindow)
    {
        if (TeacherWindow->objectName().isEmpty())
            TeacherWindow->setObjectName(QString::fromUtf8("TeacherWindow"));
        TeacherWindow->resize(585, 637);
        centralwidget = new QWidget(TeacherWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        myStudentsTableView = new QTableView(centralwidget);
        myStudentsTableView->setObjectName(QString::fromUtf8("myStudentsTableView"));

        verticalLayout->addWidget(myStudentsTableView);

        searchListView = new QListView(centralwidget);
        searchListView->setObjectName(QString::fromUtf8("searchListView"));

        verticalLayout->addWidget(searchListView);

        starsFromMyConstellationCheckBox = new QCheckBox(centralwidget);
        starsFromMyConstellationCheckBox->setObjectName(QString::fromUtf8("starsFromMyConstellationCheckBox"));

        verticalLayout->addWidget(starsFromMyConstellationCheckBox);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        searchLabel = new QLabel(centralwidget);
        searchLabel->setObjectName(QString::fromUtf8("searchLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, searchLabel);

        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, searchLineEdit);


        verticalLayout->addLayout(formLayout);

        addStudentPushButton = new QPushButton(centralwidget);
        addStudentPushButton->setObjectName(QString::fromUtf8("addStudentPushButton"));
        addStudentPushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(addStudentPushButton);


        verticalLayout_2->addLayout(verticalLayout);

        TeacherWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TeacherWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 585, 26));
        TeacherWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TeacherWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TeacherWindow->setStatusBar(statusbar);

        retranslateUi(TeacherWindow);

        QMetaObject::connectSlotsByName(TeacherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherWindow)
    {
        TeacherWindow->setWindowTitle(QCoreApplication::translate("TeacherWindow", "MainWindow", nullptr));
        starsFromMyConstellationCheckBox->setText(QCoreApplication::translate("TeacherWindow", "Stars From My Constellation", nullptr));
        searchLabel->setText(QCoreApplication::translate("TeacherWindow", "Search:", nullptr));
        addStudentPushButton->setText(QCoreApplication::translate("TeacherWindow", "Add student", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
