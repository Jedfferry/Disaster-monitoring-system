#ifndef IOT_YSBT_H
#define IOT_YSBT_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>

#include "all_data.h"

namespace Ui {
class IOT_YSBT;
}

class IOT_YSBT : public QWidget
{
    Q_OBJECT

public:
    explicit IOT_YSBT(QWidget *parent = 0);
    ~IOT_YSBT();

private slots:
    void on_back_clicked();

    void showData();

private:
    Ui::IOT_YSBT *ui;

    int a,b,c;

    QTimer *TimerData;

    void Alarm_MessageBox();

    QMessageBox *box;//定义一个QMessageBox对象
};

#endif // IOT_YSBT_H
