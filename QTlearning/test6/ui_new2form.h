/********************************************************************************
** Form generated from reading UI file 'new2form.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW2FORM_H
#define UI_NEW2FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new2form
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *new2form)
    {
        if (new2form->objectName().isEmpty())
            new2form->setObjectName(QStringLiteral("new2form"));
        new2form->resize(400, 400);
        centralwidget = new QWidget(new2form);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 160, 181, 81));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/images/5_up.JPG);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 311, 41));
        new2form->setCentralWidget(centralwidget);
        menubar = new QMenuBar(new2form);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 19));
        new2form->setMenuBar(menubar);
        statusbar = new QStatusBar(new2form);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        new2form->setStatusBar(statusbar);

        retranslateUi(new2form);

        QMetaObject::connectSlotsByName(new2form);
    } // setupUi

    void retranslateUi(QMainWindow *new2form)
    {
        new2form->setWindowTitle(QApplication::translate("new2form", "MainWindow", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class new2form: public Ui_new2form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW2FORM_H
