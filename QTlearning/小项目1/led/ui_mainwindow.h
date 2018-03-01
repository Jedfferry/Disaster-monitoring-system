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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *LED1_BTN;
    QPushButton *LED2_BTN;
    QPushButton *LED3_BTN;
    QPushButton *LED4_BTN;
    QPushButton *LEDALL_BTN;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QStringLiteral("QMainWindow {border-image: url(:/images/led.JPG)};"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LED1_BTN = new QPushButton(centralWidget);
        LED1_BTN->setObjectName(QStringLiteral("LED1_BTN"));
        LED1_BTN->setGeometry(QRect(50, 180, 75, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(18);
        LED1_BTN->setFont(font);
        LED1_BTN->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        LED2_BTN = new QPushButton(centralWidget);
        LED2_BTN->setObjectName(QStringLiteral("LED2_BTN"));
        LED2_BTN->setGeometry(QRect(170, 180, 75, 71));
        LED2_BTN->setFont(font);
        LED3_BTN = new QPushButton(centralWidget);
        LED3_BTN->setObjectName(QStringLiteral("LED3_BTN"));
        LED3_BTN->setGeometry(QRect(280, 180, 75, 71));
        LED3_BTN->setFont(font);
        LED4_BTN = new QPushButton(centralWidget);
        LED4_BTN->setObjectName(QStringLiteral("LED4_BTN"));
        LED4_BTN->setGeometry(QRect(390, 180, 75, 71));
        LED4_BTN->setFont(font);
        LEDALL_BTN = new QPushButton(centralWidget);
        LEDALL_BTN->setObjectName(QStringLiteral("LEDALL_BTN"));
        LEDALL_BTN->setGeometry(QRect(564, 180, 101, 71));
        LEDALL_BTN->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        LED1_BTN->setText(QApplication::translate("MainWindow", "LED1", 0));
        LED2_BTN->setText(QApplication::translate("MainWindow", "LED2", 0));
        LED3_BTN->setText(QApplication::translate("MainWindow", "LED3", 0));
        LED4_BTN->setText(QApplication::translate("MainWindow", "LED4", 0));
        LEDALL_BTN->setText(QApplication::translate("MainWindow", "start", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
