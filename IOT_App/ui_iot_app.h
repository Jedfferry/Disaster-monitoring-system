/********************************************************************************
** Form generated from reading UI file 'iot_app.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOT_APP_H
#define UI_IOT_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IOT_App
{
public:
    QLabel *label;
    QPushButton *pushButton_NSL;
    QPushButton *pushButton_YSBT;
    QPushButton *pushButton_STHP;
    QPushButton *pushButton_YJSZ;
    QListWidget *Qw_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *Qw_2;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *frame;

    void setupUi(QWidget *IOT_App)
    {
        if (IOT_App->objectName().isEmpty())
            IOT_App->setObjectName(QStringLiteral("IOT_App"));
        IOT_App->resize(800, 480);
        label = new QLabel(IOT_App);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 681, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(20);
        label->setFont(font);
        pushButton_NSL = new QPushButton(IOT_App);
        pushButton_NSL->setObjectName(QStringLiteral("pushButton_NSL"));
        pushButton_NSL->setGeometry(QRect(60, 130, 111, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(15);
        pushButton_NSL->setFont(font1);
        pushButton_YSBT = new QPushButton(IOT_App);
        pushButton_YSBT->setObjectName(QStringLiteral("pushButton_YSBT"));
        pushButton_YSBT->setGeometry(QRect(250, 130, 111, 61));
        pushButton_YSBT->setFont(font1);
        pushButton_STHP = new QPushButton(IOT_App);
        pushButton_STHP->setObjectName(QStringLiteral("pushButton_STHP"));
        pushButton_STHP->setGeometry(QRect(430, 130, 111, 61));
        pushButton_STHP->setFont(font1);
        pushButton_YJSZ = new QPushButton(IOT_App);
        pushButton_YJSZ->setObjectName(QStringLiteral("pushButton_YJSZ"));
        pushButton_YJSZ->setGeometry(QRect(610, 130, 111, 61));
        pushButton_YJSZ->setFont(font1);
        Qw_3 = new QListWidget(IOT_App);
        Qw_3->setObjectName(QStringLiteral("Qw_3"));
        Qw_3->setGeometry(QRect(550, 230, 191, 192));
        Qw_3->setStyleSheet(QStringLiteral("border-image: url(:/img/2.jpg);"));
        label_4 = new QLabel(IOT_App);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 220, 171, 61));
        label_4->setFont(font);
        label_5 = new QLabel(IOT_App);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 290, 91, 61));
        label_5->setFont(font);
        Qw_2 = new QListWidget(IOT_App);
        Qw_2->setObjectName(QStringLiteral("Qw_2"));
        Qw_2->setGeometry(QRect(300, 230, 191, 192));
        Qw_2->setStyleSheet(QStringLiteral("border-image: url(:/img/1.jpg);"));
        label_7 = new QLabel(IOT_App);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 360, 101, 61));
        label_7->setFont(font);
        label_3 = new QLabel(IOT_App);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 290, 111, 61));
        label_3->setFont(font);
        label_6 = new QLabel(IOT_App);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 360, 101, 61));
        label_6->setFont(font);
        label_2 = new QLabel(IOT_App);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 440, 131, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_8 = new QLabel(IOT_App);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(620, 440, 111, 21));
        label_8->setFont(font2);
        label_9 = new QLabel(IOT_App);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 440, 111, 21));
        label_9->setFont(font2);
        frame = new QFrame(IOT_App);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 801, 481));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/img/b1.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        label->raise();
        pushButton_NSL->raise();
        pushButton_YSBT->raise();
        pushButton_STHP->raise();
        pushButton_YJSZ->raise();
        Qw_3->raise();
        label_4->raise();
        label_5->raise();
        Qw_2->raise();
        label_7->raise();
        label_3->raise();
        label_6->raise();
        label_2->raise();
        label_8->raise();
        label_9->raise();

        retranslateUi(IOT_App);

        QMetaObject::connectSlotsByName(IOT_App);
    } // setupUi

    void retranslateUi(QWidget *IOT_App)
    {
        IOT_App->setWindowTitle(QApplication::translate("IOT_App", "IOT_App", 0));
        label->setText(QApplication::translate("IOT_App", "\345\237\272\344\272\216\347\211\251\350\201\224\347\275\221\347\232\204\345\234\260\350\264\250\347\201\276\345\256\263\347\233\221\346\265\213\347\263\273\347\273\237", 0));
        pushButton_NSL->setText(QApplication::translate("IOT_App", "\346\263\245\347\237\263\346\265\201", 0));
        pushButton_YSBT->setText(QApplication::translate("IOT_App", "\345\262\251\347\237\263\345\264\251\345\241\214", 0));
        pushButton_STHP->setText(QApplication::translate("IOT_App", "\345\261\261\344\275\223\346\273\221\345\235\241", 0));
        pushButton_YJSZ->setText(QApplication::translate("IOT_App", "\351\242\204\350\255\246\350\256\276\347\275\256", 0));
        label_4->setText(QApplication::translate("IOT_App", "\345\233\242\351\230\237\344\273\213\347\273\215", 0));
        label_5->setText(QApplication::translate("IOT_App", "\345\210\230\347\203\250", 0));
        label_7->setText(QApplication::translate("IOT_App", "\350\256\241\345\274\200\346\200\200", 0));
        label_3->setText(QApplication::translate("IOT_App", "\350\216\253\344\272\221\346\230\216", 0));
        label_6->setText(QApplication::translate("IOT_App", "\351\231\210\345\277\227\350\264\244", 0));
        label_2->setText(QApplication::translate("IOT_App", "\350\216\253\344\272\221\346\230\216", 0));
        label_8->setText(QApplication::translate("IOT_App", "\350\256\241\345\274\200\346\200\200", 0));
        label_9->setText(QApplication::translate("IOT_App", "\347\225\214\351\235\242\350\256\276\350\256\241", 0));
    } // retranslateUi

};

namespace Ui {
    class IOT_App: public Ui_IOT_App {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOT_APP_H
