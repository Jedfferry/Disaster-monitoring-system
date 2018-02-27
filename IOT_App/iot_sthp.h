#ifndef IOT_STHP_H
#define IOT_STHP_H

#include <QWidget>
#include <QTimer>

#include "all_data.h"

#include "qcustomplot.h"   //画曲线的头文件

namespace Ui {
class IOT_STHP;
}

class IOT_STHP : public QWidget
{
    Q_OBJECT

public:
    explicit IOT_STHP(QWidget *parent = 0);
    ~IOT_STHP();

private slots:

    void on_back_clicked();

    void showData();

    void loadWater();     //水位曲线图

private:
    Ui::IOT_STHP *ui;

    QTimer *TimerData;

    QTimer *waterTimer;       //定义一个绘制水位曲线定时器
    double waterKey;

    void InitForm();     //new定时器
    void InitPlot();    //初始化画图
    void InitWater();     //初始化水位图

    QMessageBox *box;//定义一个QMessageBox对象
    void Alarm_MessageBox();


};

#endif // IOT_STHP_H
