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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_IP;
    QLineEdit *lineEdit_Port;
    QLineEdit *textEdit_Send;
    QPushButton *pushButton_Connect;
    QPushButton *pushButton_Close;
    QPushButton *pushButton_Send;
    QTextEdit *textEdit_Recv;
    QCheckBox *checkBox_Newline;
    QTextEdit *textEdit_Send_2;
    QPushButton *pushButton_Clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 311);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_IP = new QLineEdit(centralWidget);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));
        lineEdit_IP->setGeometry(QRect(170, 10, 181, 31));
        lineEdit_Port = new QLineEdit(centralWidget);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));
        lineEdit_Port->setGeometry(QRect(170, 50, 181, 31));
        textEdit_Send = new QLineEdit(centralWidget);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(170, 90, 181, 31));
        pushButton_Connect = new QPushButton(centralWidget);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setGeometry(QRect(30, 230, 75, 23));
        pushButton_Close = new QPushButton(centralWidget);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(120, 230, 75, 23));
        pushButton_Send = new QPushButton(centralWidget);
        pushButton_Send->setObjectName(QStringLiteral("pushButton_Send"));
        pushButton_Send->setGeometry(QRect(210, 230, 75, 23));
        textEdit_Recv = new QTextEdit(centralWidget);
        textEdit_Recv->setObjectName(QStringLiteral("textEdit_Recv"));
        textEdit_Recv->setGeometry(QRect(30, 143, 321, 31));
        checkBox_Newline = new QCheckBox(centralWidget);
        checkBox_Newline->setObjectName(QStringLiteral("checkBox_Newline"));
        checkBox_Newline->setGeometry(QRect(30, 120, 71, 16));
        textEdit_Send_2 = new QTextEdit(centralWidget);
        textEdit_Send_2->setObjectName(QStringLiteral("textEdit_Send_2"));
        textEdit_Send_2->setGeometry(QRect(30, 180, 321, 31));
        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(300, 230, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
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
        pushButton_Connect->setText(QApplication::translate("MainWindow", "connect", 0));
        pushButton_Close->setText(QApplication::translate("MainWindow", "close", 0));
        pushButton_Send->setText(QApplication::translate("MainWindow", "send", 0));
        checkBox_Newline->setText(QApplication::translate("MainWindow", "New_line", 0));
        pushButton_Clear->setText(QApplication::translate("MainWindow", "clean", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
