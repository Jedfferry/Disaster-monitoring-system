/********************************************************************************
** Form generated from reading UI file 'newform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFORM_H
#define UI_NEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newForm
{
public:
    QWidget *centralwidget;
    QTimeEdit *timeEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *newForm)
    {
        if (newForm->objectName().isEmpty())
            newForm->setObjectName(QStringLiteral("newForm"));
        newForm->resize(500, 300);
        centralwidget = new QWidget(newForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(140, 40, 181, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 200, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 200, 75, 23));
        newForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(newForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 19));
        newForm->setMenuBar(menubar);
        statusbar = new QStatusBar(newForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        newForm->setStatusBar(statusbar);

        retranslateUi(newForm);

        QMetaObject::connectSlotsByName(newForm);
    } // setupUi

    void retranslateUi(QMainWindow *newForm)
    {
        newForm->setWindowTitle(QApplication::translate("newForm", "MainWindow", 0));
        pushButton->setText(QApplication::translate("newForm", "back", 0));
        pushButton_2->setText(QApplication::translate("newForm", "next", 0));
    } // retranslateUi

};

namespace Ui {
    class newForm: public Ui_newForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFORM_H
