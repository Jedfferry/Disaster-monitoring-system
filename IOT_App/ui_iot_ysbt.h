/********************************************************************************
** Form generated from reading UI file 'iot_ysbt.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOT_YSBT_H
#define UI_IOT_YSBT_H

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

QT_BEGIN_NAMESPACE

class Ui_IOT_YSBT
{
public:
    QLabel *label;
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
    QDial *dial_2;
    QDial *dial_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *back;
    QFrame *frame;

    void setupUi(QWidget *IOT_YSBT)
    {
        if (IOT_YSBT->objectName().isEmpty())
            IOT_YSBT->setObjectName(QStringLiteral("IOT_YSBT"));
        IOT_YSBT->resize(800, 480);
        label = new QLabel(IOT_YSBT);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 241, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(14);
        label->setFont(font);
        groupBox = new QGroupBox(IOT_YSBT);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 150, 751, 221));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        groupBox->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 60, 31, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 110, 31, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 160, 31, 16));
        lineEdit1_x = new QLineEdit(groupBox);
        lineEdit1_x->setObjectName(QStringLiteral("lineEdit1_x"));
        lineEdit1_x->setGeometry(QRect(90, 60, 61, 20));
        lineEdit1_y = new QLineEdit(groupBox);
        lineEdit1_y->setObjectName(QStringLiteral("lineEdit1_y"));
        lineEdit1_y->setGeometry(QRect(90, 110, 61, 20));
        lineEdit1_z = new QLineEdit(groupBox);
        lineEdit1_z->setObjectName(QStringLiteral("lineEdit1_z"));
        lineEdit1_z->setGeometry(QRect(90, 160, 61, 20));
        dial_1 = new QDial(groupBox);
        dial_1->setObjectName(QStringLiteral("dial_1"));
        dial_1->setGeometry(QRect(190, 50, 131, 121));
        dial_1->setMaximum(360);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 150, 21, 16));
        label_8->setFont(font1);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(290, 150, 41, 16));
        label_9->setFont(font1);
        dial_2 = new QDial(groupBox);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setGeometry(QRect(380, 50, 131, 121));
        dial_2->setMaximum(360);
        dial_3 = new QDial(groupBox);
        dial_3->setObjectName(QStringLiteral("dial_3"));
        dial_3->setGeometry(QRect(570, 40, 131, 121));
        dial_3->setMaximum(360);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(400, 150, 21, 16));
        label_10->setFont(font1);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(580, 140, 21, 16));
        label_11->setFont(font1);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(480, 150, 41, 16));
        label_12->setFont(font1);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(670, 140, 41, 16));
        label_13->setFont(font1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 180, 31, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(430, 180, 31, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(630, 180, 31, 16));
        back = new QPushButton(IOT_YSBT);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(680, 30, 75, 31));
        back->setFont(font1);
        frame = new QFrame(IOT_YSBT);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 801, 481));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/img/b1.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox->raise();
        groupBox->raise();
        groupBox->raise();
        frame->raise();
        label->raise();
        groupBox->raise();
        back->raise();

        retranslateUi(IOT_YSBT);

        QMetaObject::connectSlotsByName(IOT_YSBT);
    } // setupUi

    void retranslateUi(QWidget *IOT_YSBT)
    {
        IOT_YSBT->setWindowTitle(QApplication::translate("IOT_YSBT", "Form", 0));
        label->setText(QApplication::translate("IOT_YSBT", "\345\262\251\347\237\263\345\264\251\345\241\214\347\233\221\346\265\213", 0));
        groupBox->setTitle(QApplication::translate("IOT_YSBT", "\346\243\200\346\265\213\347\202\271", 0));
        label_2->setText(QApplication::translate("IOT_YSBT", "X\357\274\232", 0));
        label_3->setText(QApplication::translate("IOT_YSBT", "Y\357\274\232", 0));
        label_4->setText(QApplication::translate("IOT_YSBT", "Z\357\274\232", 0));
        label_8->setText(QApplication::translate("IOT_YSBT", "0\302\260", 0));
        label_9->setText(QApplication::translate("IOT_YSBT", "360\302\260", 0));
        label_10->setText(QApplication::translate("IOT_YSBT", "0\302\260", 0));
        label_11->setText(QApplication::translate("IOT_YSBT", "0\302\260", 0));
        label_12->setText(QApplication::translate("IOT_YSBT", "360\302\260", 0));
        label_13->setText(QApplication::translate("IOT_YSBT", "360\302\260", 0));
        label_5->setText(QApplication::translate("IOT_YSBT", "X\350\275\264", 0));
        label_6->setText(QApplication::translate("IOT_YSBT", "Y\350\275\264", 0));
        label_7->setText(QApplication::translate("IOT_YSBT", "Z\350\275\264", 0));
        back->setText(QApplication::translate("IOT_YSBT", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class IOT_YSBT: public Ui_IOT_YSBT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOT_YSBT_H
