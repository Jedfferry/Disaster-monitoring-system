/********************************************************************************
** Form generated from reading UI file 'iot_nsl.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOT_NSL_H
#define UI_IOT_NSL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_IOT_NSL
{
public:
    QPushButton *startButton;
    QPushButton *stopButton;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *hum_lineEdit;
    QGroupBox *groupBox;
    QCustomPlot *customPlot;
    QPushButton *back;
    QGroupBox *groupBox_2;
    QCustomPlot *customPlot_2;
    QLineEdit *pre_lineEdit;
    QLabel *label_4;
    QCustomPlot *warning_NSL;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *frame;

    void setupUi(QWidget *IOT_NSL)
    {
        if (IOT_NSL->objectName().isEmpty())
            IOT_NSL->setObjectName(QStringLiteral("IOT_NSL"));
        IOT_NSL->resize(800, 480);
        startButton = new QPushButton(IOT_NSL);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(480, 20, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        startButton->setFont(font);
        stopButton = new QPushButton(IOT_NSL);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(590, 20, 71, 31));
        label = new QLabel(IOT_NSL);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 221, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(14);
        label->setFont(font1);
        label_3 = new QLabel(IOT_NSL);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 31, 21));
        label_3->setFont(font);
        hum_lineEdit = new QLineEdit(IOT_NSL);
        hum_lineEdit->setObjectName(QStringLiteral("hum_lineEdit"));
        hum_lineEdit->setGeometry(QRect(10, 150, 41, 31));
        groupBox = new QGroupBox(IOT_NSL);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 50, 511, 211));
        groupBox->setFont(font);
        customPlot = new QCustomPlot(groupBox);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 20, 491, 181));
        QFont font2;
        font2.setPointSize(7);
        customPlot->setFont(font2);
        back = new QPushButton(IOT_NSL);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(690, 20, 71, 31));
        back->setFont(font);
        groupBox_2 = new QGroupBox(IOT_NSL);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(60, 270, 511, 211));
        groupBox_2->setFont(font);
        customPlot_2 = new QCustomPlot(groupBox_2);
        customPlot_2->setObjectName(QStringLiteral("customPlot_2"));
        customPlot_2->setGeometry(QRect(10, 20, 491, 171));
        pre_lineEdit = new QLineEdit(IOT_NSL);
        pre_lineEdit->setObjectName(QStringLiteral("pre_lineEdit"));
        pre_lineEdit->setGeometry(QRect(10, 370, 41, 31));
        label_4 = new QLabel(IOT_NSL);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 340, 41, 21));
        label_4->setFont(font);
        warning_NSL = new QCustomPlot(IOT_NSL);
        warning_NSL->setObjectName(QStringLiteral("warning_NSL"));
        warning_NSL->setGeometry(QRect(580, 90, 211, 231));
        label_2 = new QLabel(IOT_NSL);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(610, 340, 191, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(10);
        label_2->setFont(font3);
        label_5 = new QLabel(IOT_NSL);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(610, 380, 191, 31));
        label_5->setFont(font3);
        label_6 = new QLabel(IOT_NSL);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(610, 420, 151, 31));
        label_6->setFont(font3);
        frame = new QFrame(IOT_NSL);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 801, 481));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/img/b1.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        startButton->raise();
        stopButton->raise();
        label->raise();
        label_3->raise();
        hum_lineEdit->raise();
        groupBox->raise();
        back->raise();
        groupBox_2->raise();
        pre_lineEdit->raise();
        label_4->raise();
        warning_NSL->raise();
        label_2->raise();
        label_5->raise();
        label_6->raise();

        retranslateUi(IOT_NSL);

        QMetaObject::connectSlotsByName(IOT_NSL);
    } // setupUi

    void retranslateUi(QWidget *IOT_NSL)
    {
        IOT_NSL->setWindowTitle(QApplication::translate("IOT_NSL", "Form", 0));
        startButton->setText(QApplication::translate("IOT_NSL", "\345\274\200\345\247\213\347\233\221\346\265\213", 0));
        stopButton->setText(QApplication::translate("IOT_NSL", "\345\201\234\346\255\242\347\233\221\346\265\213", 0));
        label->setText(QApplication::translate("IOT_NSL", "\346\263\245\347\237\263\346\265\201\347\233\221\346\265\213", 0));
        label_3->setText(QApplication::translate("IOT_NSL", "\346\271\277\345\272\246", 0));
        groupBox->setTitle(QApplication::translate("IOT_NSL", "\346\271\277\345\272\246\345\256\236\346\227\266\346\225\260\346\215\256", 0));
        back->setText(QApplication::translate("IOT_NSL", "\350\277\224\345\233\236", 0));
        groupBox_2->setTitle(QApplication::translate("IOT_NSL", "\351\231\215\351\233\250\351\207\217\345\256\236\346\227\266\346\225\260\346\215\256", 0));
        label_4->setText(QApplication::translate("IOT_NSL", "\351\231\215\351\233\250\351\207\217", 0));
        label_2->setText(QApplication::translate("IOT_NSL", "1:\346\271\277\345\272\246\350\266\205\350\277\207\351\231\220\345\200\274\346\254\241\346\225\260", 0));
        label_5->setText(QApplication::translate("IOT_NSL", "2:\351\231\215\351\233\250\351\207\217\350\266\205\350\277\207\351\231\220\345\200\274\346\254\241\346\225\260", 0));
        label_6->setText(QApplication::translate("IOT_NSL", "3:\351\242\204\350\255\246\346\254\241\346\225\260\346\254\241\346\225\260", 0));
    } // retranslateUi

};

namespace Ui {
    class IOT_NSL: public Ui_IOT_NSL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOT_NSL_H
