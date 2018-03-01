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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *BTN1;
    QPushButton *BTN2;
    QPushButton *BTN3;
    QPushButton *BTN4;
    QPushButton *BTN5;
    QPushButton *BTN6;
    QPushButton *BTN7;
    QPushButton *BTN8;
    QPushButton *BTN_DEL;
    QPushButton *BTN_ENTER;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 50, 671, 61));
        QFont font;
        font.setFamily(QStringLiteral("Arial Narrow"));
        font.setPointSize(28);
        lineEdit->setFont(font);
        lineEdit->setFocusPolicy(Qt::NoFocus);
        BTN1 = new QPushButton(centralWidget);
        BTN1->setObjectName(QStringLiteral("BTN1"));
        BTN1->setGeometry(QRect(50, 170, 75, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(28);
        BTN1->setFont(font1);
        BTN1->setFocusPolicy(Qt::NoFocus);
        BTN2 = new QPushButton(centralWidget);
        BTN2->setObjectName(QStringLiteral("BTN2"));
        BTN2->setGeometry(QRect(140, 170, 75, 61));
        BTN2->setFont(font1);
        BTN2->setFocusPolicy(Qt::NoFocus);
        BTN3 = new QPushButton(centralWidget);
        BTN3->setObjectName(QStringLiteral("BTN3"));
        BTN3->setGeometry(QRect(230, 170, 75, 61));
        BTN3->setFont(font1);
        BTN3->setFocusPolicy(Qt::NoFocus);
        BTN4 = new QPushButton(centralWidget);
        BTN4->setObjectName(QStringLiteral("BTN4"));
        BTN4->setGeometry(QRect(320, 170, 75, 61));
        BTN4->setFont(font1);
        BTN4->setFocusPolicy(Qt::NoFocus);
        BTN5 = new QPushButton(centralWidget);
        BTN5->setObjectName(QStringLiteral("BTN5"));
        BTN5->setGeometry(QRect(410, 170, 75, 61));
        BTN5->setFont(font1);
        BTN5->setFocusPolicy(Qt::NoFocus);
        BTN6 = new QPushButton(centralWidget);
        BTN6->setObjectName(QStringLiteral("BTN6"));
        BTN6->setGeometry(QRect(500, 170, 75, 61));
        BTN6->setFont(font1);
        BTN6->setFocusPolicy(Qt::NoFocus);
        BTN7 = new QPushButton(centralWidget);
        BTN7->setObjectName(QStringLiteral("BTN7"));
        BTN7->setGeometry(QRect(590, 170, 75, 61));
        BTN7->setFont(font1);
        BTN7->setFocusPolicy(Qt::NoFocus);
        BTN8 = new QPushButton(centralWidget);
        BTN8->setObjectName(QStringLiteral("BTN8"));
        BTN8->setGeometry(QRect(680, 170, 75, 61));
        BTN8->setFont(font1);
        BTN8->setFocusPolicy(Qt::NoFocus);
        BTN_DEL = new QPushButton(centralWidget);
        BTN_DEL->setObjectName(QStringLiteral("BTN_DEL"));
        BTN_DEL->setGeometry(QRect(100, 250, 75, 61));
        BTN_DEL->setFont(font1);
        BTN_DEL->setFocusPolicy(Qt::NoFocus);
        BTN_ENTER = new QPushButton(centralWidget);
        BTN_ENTER->setObjectName(QStringLiteral("BTN_ENTER"));
        BTN_ENTER->setGeometry(QRect(640, 250, 75, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(20);
        BTN_ENTER->setFont(font2);
        BTN_ENTER->setFocusPolicy(Qt::NoFocus);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lineEdit->setText(QString());
        BTN1->setText(QApplication::translate("MainWindow", "1", 0));
        BTN2->setText(QApplication::translate("MainWindow", "2", 0));
        BTN3->setText(QApplication::translate("MainWindow", "3", 0));
        BTN4->setText(QApplication::translate("MainWindow", "4", 0));
        BTN5->setText(QApplication::translate("MainWindow", "5", 0));
        BTN6->setText(QApplication::translate("MainWindow", "6", 0));
        BTN7->setText(QApplication::translate("MainWindow", "7", 0));
        BTN8->setText(QApplication::translate("MainWindow", "8", 0));
        BTN_DEL->setText(QApplication::translate("MainWindow", "del", 0));
        BTN_ENTER->setText(QApplication::translate("MainWindow", "Enter", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
