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
    QVBoxLayout *verticalLayout;
    QTableView *myStudentsTableView;
    QListView *searchListView;
    QCheckBox *starsFromMyConstellationCheckBox;
    QFormLayout *formLayout;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QLabel *addStarLabel;
    QFormLayout *formLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *RaLabel;
    QLineEdit *rightAscensionLineEdit;
    QLabel *label_3;
    QLineEdit *declinationLineEdit;
    QLabel *label_4;
    QLineEdit *diameterLineEdit;
    QPushButton *addStudentPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TeacherWindow)
    {
        if (TeacherWindow->objectName().isEmpty())
            TeacherWindow->setObjectName(QString::fromUtf8("TeacherWindow"));
        TeacherWindow->resize(631, 710);
        centralwidget = new QWidget(TeacherWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
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

        addStarLabel = new QLabel(centralwidget);
        addStarLabel->setObjectName(QString::fromUtf8("addStarLabel"));

        verticalLayout->addWidget(addStarLabel);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(centralwidget);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        RaLabel = new QLabel(centralwidget);
        RaLabel->setObjectName(QString::fromUtf8("RaLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, RaLabel);

        rightAscensionLineEdit = new QLineEdit(centralwidget);
        rightAscensionLineEdit->setObjectName(QString::fromUtf8("rightAscensionLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, rightAscensionLineEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        declinationLineEdit = new QLineEdit(centralwidget);
        declinationLineEdit->setObjectName(QString::fromUtf8("declinationLineEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, declinationLineEdit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        diameterLineEdit = new QLineEdit(centralwidget);
        diameterLineEdit->setObjectName(QString::fromUtf8("diameterLineEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, diameterLineEdit);


        verticalLayout->addLayout(formLayout_2);

        addStudentPushButton = new QPushButton(centralwidget);
        addStudentPushButton->setObjectName(QString::fromUtf8("addStudentPushButton"));
        addStudentPushButton->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(addStudentPushButton);

        TeacherWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TeacherWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 631, 26));
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
        addStarLabel->setText(QCoreApplication::translate("TeacherWindow", "Add star:", nullptr));
        nameLabel->setText(QCoreApplication::translate("TeacherWindow", "Name", nullptr));
        RaLabel->setText(QCoreApplication::translate("TeacherWindow", "Right Ascension", nullptr));
        label_3->setText(QCoreApplication::translate("TeacherWindow", "Declination", nullptr));
        label_4->setText(QCoreApplication::translate("TeacherWindow", "Diameter", nullptr));
        addStudentPushButton->setText(QCoreApplication::translate("TeacherWindow", "Add star", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
