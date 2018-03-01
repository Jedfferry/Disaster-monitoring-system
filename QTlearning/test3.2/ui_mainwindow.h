/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *opt1;
    QLabel *label;
    QLineEdit *opt2;
    QLabel *label_2;
    QLineEdit *value;
    QPushButton *pushButton;
    QLCDNumber *lcdNumber;
    QLabel *date_label;
    QLabel *time_label;
    QPushButton *start;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setStyleSheet(QStringLiteral("QMainWindow {border-image: url(:/button.JPG)};"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        opt1 = new QLineEdit(centralWidget);
        opt1->setObjectName(QStringLiteral("opt1"));
        opt1->setEnabled(true);
        opt1->setGeometry(QRect(20, 40, 81, 31));
        QFont font;
        font.setPointSize(18);
        opt1->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(113, 40, 61, 21));
        opt2 = new QLineEdit(centralWidget);
        opt2->setObjectName(QStringLiteral("opt2"));
        opt2->setGeometry(QRect(140, 40, 81, 31));
        opt2->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 40, 54, 31));
        value = new QLineEdit(centralWidget);
        value->setObjectName(QStringLiteral("value"));
        value->setGeometry(QRect(270, 40, 81, 31));
        value->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(274, 100, 71, 31));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/button.JPG);"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 90, 111, 41));
        lcdNumber->setStyleSheet(QStringLiteral(""));
        date_label = new QLabel(centralWidget);
        date_label->setObjectName(QStringLiteral("date_label"));
        date_label->setGeometry(QRect(30, 160, 341, 31));
        date_label->setFont(font);
        time_label = new QLabel(centralWidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(30, 210, 341, 31));
        time_label->setFont(font);
        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(160, 100, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">+</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">=</span></p></body></html>", 0));
        pushButton->setText(QString());
        date_label->setText(QApplication::translate("MainWindow", "0:0", 0));
        time_label->setText(QApplication::translate("MainWindow", "00:00", 0));
        start->setText(QApplication::translate("MainWindow", "start", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
