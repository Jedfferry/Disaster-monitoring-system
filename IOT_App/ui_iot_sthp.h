/********************************************************************************
** Form generated from reading UI file 'iot_sthp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOT_STHP_H
#define UI_IOT_STHP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_IOT_STHP
{
public:
    QLabel *label;
    QPushButton *back;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit1_x;
    QLineEdit *lineEdit1_y;
    QLineEdit *lineEdit1_z;
    QDial *dial_1;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QCustomPlot *customPlot;
    QLabel *label_5;
    QLineEdit *lineEdit_water;
    QFrame *frame;

    void setupUi(QWidget *IOT_STHP)
    {
        if (IOT_STHP->objectName().isEmpty())
            IOT_STHP->setObjectName(QStringLiteral("IOT_STHP"));
        IOT_STHP->resize(800, 480);
        QFont font;
        font.setPointSize(12);
        IOT_STHP->setFont(font);
        label = new QLabel(IOT_STHP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 271, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(15);
        label->setFont(font1);
        back = new QPushButton(IOT_STHP);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(680, 20, 75, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(10);
        back->setFont(font2);
        groupBox = new QGroupBox(IOT_STHP);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 150, 271, 231));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(9);
        groupBox->setFont(font3);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 31, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 40, 31, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 40, 31, 16));
        lineEdit1_x = new QLineEdit(groupBox);
        lineEdit1_x->setObjectName(QStringLiteral("lineEdit1_x"));
        lineEdit1_x->setGeometry(QRect(40, 40, 41, 20));
        lineEdit1_y = new QLineEdit(groupBox);
        lineEdit1_y->setObjectName(QStringLiteral("lineEdit1_y"));
        lineEdit1_y->setGeometry(QRect(130, 40, 41, 20));
        lineEdit1_z = new QLineEdit(groupBox);
        lineEdit1_z->setObjectName(QStringLiteral("lineEdit1_z"));
        lineEdit1_z->setGeometry(QRect(220, 40, 41, 20));
        dial_1 = new QDial(groupBox);
        dial_1->setObjectName(QStringLiteral("dial_1"));
        dial_1->setGeometry(QRect(70, 90, 131, 121));
        dial_1->setMaximum(360);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 190, 21, 16));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 190, 41, 16));
        groupBox_2 = new QGroupBox(IOT_STHP);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 100, 501, 381));
        QFont font4;
        font4.setPointSize(8);
        groupBox_2->setFont(font4);
        customPlot = new QCustomPlot(groupBox_2);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 30, 481, 341));
        label_5 = new QLabel(IOT_STHP);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 100, 51, 21));
        QFont font5;
        font5.setPointSize(9);
        label_5->setFont(font5);
        lineEdit_water = new QLineEdit(IOT_STHP);
        lineEdit_water->setObjectName(QStringLiteral("lineEdit_water"));
        lineEdit_water->setGeometry(QRect(220, 100, 51, 20));
        lineEdit_water->setFont(font5);
        frame = new QFrame(IOT_STHP);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 801, 481));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/img/b1.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        label->raise();
        back->raise();
        groupBox->raise();
        groupBox_2->raise();
        label_5->raise();
        lineEdit_water->raise();

        retranslateUi(IOT_STHP);

        QMetaObject::connectSlotsByName(IOT_STHP);
    } // setupUi

    void retranslateUi(QWidget *IOT_STHP)
    {
        IOT_STHP->setWindowTitle(QApplication::translate("IOT_STHP", "Form", 0));
        label->setText(QApplication::translate("IOT_STHP", "\345\261\261\344\275\223\346\273\221\345\235\241\347\233\221\346\265\213", 0));
        back->setText(QApplication::translate("IOT_STHP", "\350\277\224\345\233\236", 0));
        groupBox->setTitle(QApplication::translate("IOT_STHP", "\347\233\221\346\265\213\347\202\271", 0));
        label_2->setText(QApplication::translate("IOT_STHP", "X\357\274\232", 0));
        label_3->setText(QApplication::translate("IOT_STHP", "Y\357\274\232", 0));
        label_4->setText(QApplication::translate("IOT_STHP", "Z\357\274\232", 0));
        label_8->setText(QApplication::translate("IOT_STHP", "0\302\260", 0));
        label_9->setText(QApplication::translate("IOT_STHP", "360\302\260", 0));
        groupBox_2->setTitle(QApplication::translate("IOT_STHP", "\345\234\260\344\270\213\346\260\264\344\275\215", 0));
        label_5->setText(QApplication::translate("IOT_STHP", "\346\260\264\344\275\215\345\200\274\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class IOT_STHP: public Ui_IOT_STHP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOT_STHP_H
