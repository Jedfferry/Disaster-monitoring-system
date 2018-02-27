#ifndef IOT_YJSZ_H
#define IOT_YJSZ_H

#include <QWidget>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QMessageBox>
#include "all_data.h"
#include <QTimer>
namespace Ui {
class IOT_YJSZ;
}

class IOT_YJSZ : public QWidget
{
    Q_OBJECT

public:
    explicit IOT_YJSZ(QWidget *parent = 0);
    ~IOT_YJSZ();

private slots:
    bool eventFilter(QObject *,QEvent *);    //事件过滤器

    void on_back_clicked();

    void on_pushButton0_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton_dian_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_hum_clicked();

    void on_pushButton_pre_clicked();

    void on_pushButton_1_x_clicked();

    void on_pushButton_1_y_clicked();

    void on_pushButton_1_z_clicked();

   // void on_pushButton_2_x_clicked();

   // void on_pushButton_2_y_clicked();

   // void on_pushButton_2_z_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_y_clicked();

    void on_pushButton_z_clicked();

    void on_pushButton_water_clicked();

    void Save_MessageBox();

private:
    Ui::IOT_YJSZ *ui;

    QString str;

    int flag;

    QMessageBox *box;//定义一个QMessageBox对象
};


#endif // IOT_YJSZ_H
