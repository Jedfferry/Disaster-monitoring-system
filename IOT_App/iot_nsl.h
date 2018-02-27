#ifndef IOT_NSL_H
#define IOT_NSL_H

#include <QWidget>

#include <QMessageBox>
#include <QTimer>
#include <QFile>
#include <QtDebug>

#include "qcustomplot.h"
#include "all_data.h"


namespace Ui {
class IOT_NSL;
}

class IOT_NSL : public QWidget
{
    Q_OBJECT

public:
    explicit IOT_NSL(QWidget *parent = 0);
    ~IOT_NSL();



private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_back_clicked();

    void realtimeDataSlot(); //画湿度曲线图

    void loadPre();     //画降雨量曲线图
    //void LoadAlarm();
    void UpdateAlarm(); //预警图

private:
    Ui::IOT_NSL *ui;

    //用于实时绘制湿度实时数据曲线图的横坐标和纵坐标的数值范围
    void setupRealtimeDataDemo(QCustomPlot *customPlot);
    QTimer *dataTimer;    //定义一个绘制湿度曲线定时器

    QTimer *preTimer;       //定义一个绘制降雨量曲线定时器

    QTimer *alarmTimer;    //定义一个绘制柱状图定时器

    double pre_key;
    //double plot2_value;

    QVector<double> alarmKeys;
    QVector<double> alarmValues;
    //QVector<double> plot5_currentValue;
    int maxValue;
    QVector<QString> alarmLabels;  //横坐标名称
    QVector<QCPBars *> alarmBar;

    void InitForm();     //new定时器
    void InitPlot();    //初始化画图
    void InitPre();     //初始化降雨量图
    void InitAlarm();   //初始化报警图

    void Alarm_MessageBox();

    QMessageBox *box;//定义一个QMessageBox对象

    int count1;
    int count2;
    int count3;


};

#endif // IOT_NSL_H
