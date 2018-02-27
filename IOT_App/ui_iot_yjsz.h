/********************************************************************************
** Form generated from reading UI file 'iot_yjsz.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOT_YJSZ_H
#define UI_IOT_YJSZ_H

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

QT_BEGIN_NAMESPACE

class Ui_IOT_YJSZ
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lineEdit_hum;
    QPushButton *pushButton_hum;
    QLineEdit *lineEdit_pre;
    QPushButton *pushButton_pre;
    QLabel *label_3;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_1_x;
    QPushButton *pushButton_1_x;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_1_y;
    QLineEdit *lineEdit_1_y;
    QLabel *label_6;
    QPushButton *pushButton_1_z;
    QLineEdit *lineEdit_1_z;
    QGroupBox *groupBox_3;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_x;
    QLineEdit *lineEdit_z;
    QLineEdit *lineEdit_x;
    QPushButton *pushButton_z;
    QLabel *label_12;
    QLineEdit *lineEdit_y;
    QPushButton *pushButton_y;
    QLabel *label_13;
    QLineEdit *lineEdit_water;
    QPushButton *pushButton_water;
    QPushButton *back;
    QPushButton *pushButton0;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton6;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QPushButton *pushButton_dian;
    QPushButton *pushButton_C;
    QFrame *frame;

    void setupUi(QWidget *IOT_YJSZ)
    {
        if (IOT_YJSZ->objectName().isEmpty())
            IOT_YJSZ->setObjectName(QStringLiteral("IOT_YJSZ"));
        IOT_YJSZ->resize(800, 480);
        groupBox = new QGroupBox(IOT_YJSZ);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 70, 241, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        groupBox->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 54, 21));
        lineEdit_hum = new QLineEdit(groupBox);
        lineEdit_hum->setObjectName(QStringLiteral("lineEdit_hum"));
        lineEdit_hum->setGeometry(QRect(80, 40, 81, 20));
        lineEdit_hum->setFocusPolicy(Qt::StrongFocus);
        pushButton_hum = new QPushButton(groupBox);
        pushButton_hum->setObjectName(QStringLiteral("pushButton_hum"));
        pushButton_hum->setGeometry(QRect(174, 40, 51, 23));
        lineEdit_pre = new QLineEdit(groupBox);
        lineEdit_pre->setObjectName(QStringLiteral("lineEdit_pre"));
        lineEdit_pre->setGeometry(QRect(80, 90, 81, 20));
        pushButton_pre = new QPushButton(groupBox);
        pushButton_pre->setObjectName(QStringLiteral("pushButton_pre"));
        pushButton_pre->setGeometry(QRect(174, 90, 51, 23));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 54, 21));
        label = new QLabel(IOT_YJSZ);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 141, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(16);
        label->setFont(font1);
        groupBox_2 = new QGroupBox(IOT_YJSZ);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 70, 241, 301));
        groupBox_2->setFont(font);
        lineEdit_1_x = new QLineEdit(groupBox_2);
        lineEdit_1_x->setObjectName(QStringLiteral("lineEdit_1_x"));
        lineEdit_1_x->setGeometry(QRect(80, 40, 81, 20));
        pushButton_1_x = new QPushButton(groupBox_2);
        pushButton_1_x->setObjectName(QStringLiteral("pushButton_1_x"));
        pushButton_1_x->setGeometry(QRect(174, 40, 51, 23));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(13, 40, 61, 21));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(13, 80, 61, 21));
        pushButton_1_y = new QPushButton(groupBox_2);
        pushButton_1_y->setObjectName(QStringLiteral("pushButton_1_y"));
        pushButton_1_y->setGeometry(QRect(174, 80, 51, 23));
        lineEdit_1_y = new QLineEdit(groupBox_2);
        lineEdit_1_y->setObjectName(QStringLiteral("lineEdit_1_y"));
        lineEdit_1_y->setGeometry(QRect(80, 80, 81, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(13, 120, 61, 21));
        pushButton_1_z = new QPushButton(groupBox_2);
        pushButton_1_z->setObjectName(QStringLiteral("pushButton_1_z"));
        pushButton_1_z->setGeometry(QRect(174, 120, 51, 23));
        lineEdit_1_z = new QLineEdit(groupBox_2);
        lineEdit_1_z->setObjectName(QStringLiteral("lineEdit_1_z"));
        lineEdit_1_z->setGeometry(QRect(80, 120, 81, 20));
        groupBox_3 = new QGroupBox(IOT_YJSZ);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(540, 70, 241, 301));
        groupBox_3->setFont(font);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(9, 40, 61, 21));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(9, 120, 61, 21));
        pushButton_x = new QPushButton(groupBox_3);
        pushButton_x->setObjectName(QStringLiteral("pushButton_x"));
        pushButton_x->setGeometry(QRect(170, 40, 51, 23));
        lineEdit_z = new QLineEdit(groupBox_3);
        lineEdit_z->setObjectName(QStringLiteral("lineEdit_z"));
        lineEdit_z->setGeometry(QRect(76, 120, 81, 20));
        lineEdit_x = new QLineEdit(groupBox_3);
        lineEdit_x->setObjectName(QStringLiteral("lineEdit_x"));
        lineEdit_x->setGeometry(QRect(76, 40, 81, 20));
        pushButton_z = new QPushButton(groupBox_3);
        pushButton_z->setObjectName(QStringLiteral("pushButton_z"));
        pushButton_z->setGeometry(QRect(170, 120, 51, 23));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(9, 80, 61, 21));
        lineEdit_y = new QLineEdit(groupBox_3);
        lineEdit_y->setObjectName(QStringLiteral("lineEdit_y"));
        lineEdit_y->setGeometry(QRect(76, 80, 81, 20));
        pushButton_y = new QPushButton(groupBox_3);
        pushButton_y->setObjectName(QStringLiteral("pushButton_y"));
        pushButton_y->setGeometry(QRect(170, 80, 51, 23));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 160, 54, 21));
        lineEdit_water = new QLineEdit(groupBox_3);
        lineEdit_water->setObjectName(QStringLiteral("lineEdit_water"));
        lineEdit_water->setGeometry(QRect(70, 160, 81, 20));
        pushButton_water = new QPushButton(groupBox_3);
        pushButton_water->setObjectName(QStringLiteral("pushButton_water"));
        pushButton_water->setGeometry(QRect(170, 160, 51, 23));
        back = new QPushButton(IOT_YJSZ);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(690, 20, 75, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(10);
        back->setFont(font2);
        pushButton0 = new QPushButton(IOT_YJSZ);
        pushButton0->setObjectName(QStringLiteral("pushButton0"));
        pushButton0->setGeometry(QRect(40, 410, 50, 50));
        pushButton0->setFont(font);
        pushButton1 = new QPushButton(IOT_YJSZ);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(100, 410, 50, 50));
        pushButton1->setFont(font);
        pushButton2 = new QPushButton(IOT_YJSZ);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(160, 410, 50, 50));
        pushButton2->setFont(font);
        pushButton3 = new QPushButton(IOT_YJSZ);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));
        pushButton3->setGeometry(QRect(220, 410, 50, 50));
        pushButton3->setFont(font);
        pushButton4 = new QPushButton(IOT_YJSZ);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));
        pushButton4->setGeometry(QRect(280, 410, 50, 50));
        pushButton4->setFont(font);
        pushButton5 = new QPushButton(IOT_YJSZ);
        pushButton5->setObjectName(QStringLiteral("pushButton5"));
        pushButton5->setGeometry(QRect(340, 410, 50, 50));
        pushButton5->setFont(font);
        pushButton6 = new QPushButton(IOT_YJSZ);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));
        pushButton6->setGeometry(QRect(400, 410, 50, 50));
        pushButton6->setFont(font);
        pushButton7 = new QPushButton(IOT_YJSZ);
        pushButton7->setObjectName(QStringLiteral("pushButton7"));
        pushButton7->setGeometry(QRect(460, 410, 50, 50));
        pushButton7->setFont(font);
        pushButton8 = new QPushButton(IOT_YJSZ);
        pushButton8->setObjectName(QStringLiteral("pushButton8"));
        pushButton8->setGeometry(QRect(520, 410, 50, 50));
        pushButton8->setFont(font);
        pushButton9 = new QPushButton(IOT_YJSZ);
        pushButton9->setObjectName(QStringLiteral("pushButton9"));
        pushButton9->setGeometry(QRect(580, 410, 50, 50));
        pushButton9->setFont(font);
        pushButton_dian = new QPushButton(IOT_YJSZ);
        pushButton_dian->setObjectName(QStringLiteral("pushButton_dian"));
        pushButton_dian->setGeometry(QRect(640, 410, 50, 50));
        pushButton_dian->setFont(font);
        pushButton_C = new QPushButton(IOT_YJSZ);
        pushButton_C->setObjectName(QStringLiteral("pushButton_C"));
        pushButton_C->setGeometry(QRect(700, 410, 50, 50));
        pushButton_C->setFont(font);
        frame = new QFrame(IOT_YJSZ);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 801, 481));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/img/b1.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        groupBox->raise();
        label->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        back->raise();
        pushButton0->raise();
        pushButton1->raise();
        pushButton2->raise();
        pushButton3->raise();
        pushButton4->raise();
        pushButton5->raise();
        pushButton6->raise();
        pushButton7->raise();
        pushButton8->raise();
        pushButton9->raise();
        pushButton_dian->raise();
        pushButton_C->raise();
        QWidget::setTabOrder(back, lineEdit_hum);
        QWidget::setTabOrder(lineEdit_hum, pushButton_hum);
        QWidget::setTabOrder(pushButton_hum, lineEdit_pre);
        QWidget::setTabOrder(lineEdit_pre, pushButton_pre);
        QWidget::setTabOrder(pushButton_pre, lineEdit_1_x);
        QWidget::setTabOrder(lineEdit_1_x, pushButton_1_x);
        QWidget::setTabOrder(pushButton_1_x, lineEdit_1_y);
        QWidget::setTabOrder(lineEdit_1_y, pushButton_1_y);
        QWidget::setTabOrder(pushButton_1_y, lineEdit_1_z);
        QWidget::setTabOrder(lineEdit_1_z, pushButton_1_z);
        QWidget::setTabOrder(pushButton_1_z, lineEdit_x);
        QWidget::setTabOrder(lineEdit_x, pushButton_x);
        QWidget::setTabOrder(pushButton_x, lineEdit_y);
        QWidget::setTabOrder(lineEdit_y, pushButton_y);
        QWidget::setTabOrder(pushButton_y, lineEdit_z);
        QWidget::setTabOrder(lineEdit_z, pushButton_z);
        QWidget::setTabOrder(pushButton_z, lineEdit_water);
        QWidget::setTabOrder(lineEdit_water, pushButton_water);
        QWidget::setTabOrder(pushButton_water, pushButton0);
        QWidget::setTabOrder(pushButton0, pushButton1);
        QWidget::setTabOrder(pushButton1, pushButton2);
        QWidget::setTabOrder(pushButton2, pushButton3);
        QWidget::setTabOrder(pushButton3, pushButton4);
        QWidget::setTabOrder(pushButton4, pushButton5);
        QWidget::setTabOrder(pushButton5, pushButton6);
        QWidget::setTabOrder(pushButton6, pushButton7);
        QWidget::setTabOrder(pushButton7, pushButton8);
        QWidget::setTabOrder(pushButton8, pushButton9);
        QWidget::setTabOrder(pushButton9, pushButton_dian);
        QWidget::setTabOrder(pushButton_dian, pushButton_C);

        retranslateUi(IOT_YJSZ);

        QMetaObject::connectSlotsByName(IOT_YJSZ);
    } // setupUi

    void retranslateUi(QWidget *IOT_YJSZ)
    {
        IOT_YJSZ->setWindowTitle(QApplication::translate("IOT_YJSZ", "Form", 0));
        groupBox->setTitle(QApplication::translate("IOT_YJSZ", "\346\263\245\347\237\263\346\265\201\351\242\204\350\255\246\345\200\274\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("IOT_YJSZ", "\346\271\277  \345\272\246\357\274\232", 0));
        pushButton_hum->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        pushButton_pre->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        label_3->setText(QApplication::translate("IOT_YJSZ", "\351\231\215\351\233\250\351\207\217\357\274\232", 0));
        label->setText(QApplication::translate("IOT_YJSZ", "\351\242\204\350\255\246\350\256\276\347\275\256", 0));
        groupBox_2->setTitle(QApplication::translate("IOT_YJSZ", "\345\262\251\347\237\263\345\264\251\345\241\214\350\255\246\345\200\274\350\256\276\347\275\256", 0));
        pushButton_1_x->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        label_4->setText(QApplication::translate("IOT_YJSZ", "\347\233\221\346\265\213\347\202\271X\350\275\264\357\274\232", 0));
        label_5->setText(QApplication::translate("IOT_YJSZ", "\347\233\221\346\265\213\347\202\271Y\350\275\264\357\274\232", 0));
        pushButton_1_y->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        label_6->setText(QApplication::translate("IOT_YJSZ", "\347\233\221\346\265\213\347\202\271Z\350\275\264\357\274\232", 0));
        pushButton_1_z->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        groupBox_3->setTitle(QApplication::translate("IOT_YJSZ", "\345\261\261\344\275\223\346\273\221\345\235\241\351\242\204\350\255\246\345\200\274\350\256\276\347\275\256", 0));
        label_10->setText(QApplication::translate("IOT_YJSZ", "\347\233\221\346\265\213\347\202\271X\350\275\264\357\274\232", 0));
        label_11->setText(QApplication::translate("IOT_YJSZ", "\347\233\221\346\265\213\347\202\271Z\350\275\264\357\274\232", 0));
        pushButton_x->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        pushButton_z->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        label_12->setText(QApplication::translate("IOT_YJSZ", "\347\233\221\346\265\213\347\202\271Y\350\275\264\357\274\232", 0));
        pushButton_y->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        label_13->setText(QApplication::translate("IOT_YJSZ", "\345\234\260\344\270\213\346\260\264\344\275\215\357\274\232", 0));
        lineEdit_water->setText(QString());
        pushButton_water->setText(QApplication::translate("IOT_YJSZ", "\347\241\256\350\256\244", 0));
        back->setText(QApplication::translate("IOT_YJSZ", "\350\277\224\345\233\236", 0));
        pushButton0->setText(QApplication::translate("IOT_YJSZ", "0", 0));
        pushButton1->setText(QApplication::translate("IOT_YJSZ", "1", 0));
        pushButton2->setText(QApplication::translate("IOT_YJSZ", "2", 0));
        pushButton3->setText(QApplication::translate("IOT_YJSZ", "3", 0));
        pushButton4->setText(QApplication::translate("IOT_YJSZ", "4", 0));
        pushButton5->setText(QApplication::translate("IOT_YJSZ", "5", 0));
        pushButton6->setText(QApplication::translate("IOT_YJSZ", "6", 0));
        pushButton7->setText(QApplication::translate("IOT_YJSZ", "7", 0));
        pushButton8->setText(QApplication::translate("IOT_YJSZ", "8", 0));
        pushButton9->setText(QApplication::translate("IOT_YJSZ", "9", 0));
        pushButton_dian->setText(QApplication::translate("IOT_YJSZ", ".", 0));
        pushButton_C->setText(QApplication::translate("IOT_YJSZ", "C", 0));
    } // retranslateUi

};

namespace Ui {
    class IOT_YJSZ: public Ui_IOT_YJSZ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOT_YJSZ_H
