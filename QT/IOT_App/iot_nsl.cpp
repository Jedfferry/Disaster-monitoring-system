#include "iot_nsl.h"
#include "ui_iot_nsl.h"

#include <QPainter>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QLabel>


IOT_NSL::IOT_NSL(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IOT_NSL)
{
    ui->setupUi(this);

    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);

    this->InitForm();

    this->InitPlot();

    this->InitPre();

    this->InitAlarm();

    count1 = 0;
    count2 = 0;
    count3 = 0;



}

IOT_NSL::~IOT_NSL()
{
    box->close();
    alarmTimer->stop();
    preTimer->stop();
    dataTimer->stop();

    delete ui;
}

void IOT_NSL::InitForm()
{
    dataTimer = new QTimer(this);//绘制曲线定时器对象
    connect(dataTimer,SIGNAL(timeout()),this,SLOT(realtimeDataSlot()));

    preTimer = new QTimer(this);//初始化动态曲线定时器
    connect(preTimer, SIGNAL(timeout()), this, SLOT(loadPre()));

    //初始化动态柱状图定时器
    alarmTimer = new QTimer(this);
    connect(alarmTimer, SIGNAL(timeout()), this, SLOT(UpdateAlarm()));

}

void IOT_NSL::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
    customPlot->addGraph();//blue line
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setBrush(QColor(240,255,200));
    customPlot->graph(0)->setAntialiasedFill(false);
    customPlot->yAxis->setLabel("湿度值(单位:%)");


    customPlot->addGraph();//red line
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(0)->setChannelFillGraph(customPlot->graph(1));

    customPlot->addGraph();//blue dot
    customPlot->graph(2)->setPen(QPen(Qt::blue));
    customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(2)->setScatterStyle(QCPScatterStyle::ssDisc);

    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setTickStep(1);

    customPlot->axisRect()->setupFullAxesBox();

    connect(customPlot->xAxis,SIGNAL(rangeChanged(QCPRange)),customPlot->xAxis2,SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis,SIGNAL(rangeChanged(QCPRange)),customPlot->yAxis2,SLOT(setRange(QCPRange)));


}

void IOT_NSL::realtimeDataSlot()
{
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    static double lastPointKey = 0;
    if(key-lastPointKey > 0.01)
    {
        bool ok;

        ui->hum_lineEdit->setText(all_data::NSL_hum_data);//显示数据

        if(all_data::NSL_hum_data.toInt(&ok,10)>alarm_data::NSL_hum_Alarm.toInt(&ok,10))
            count1++;

        //add data to lines
        ui->customPlot->graph(0)->addData(key,all_data::NSL_hum_data.toInt(&ok,10));//加数据
        ui->customPlot->graph(1)->addData(key,all_data::NSL_hum_data.toInt(&ok,10)-10);
        //set data to lines
        ui->customPlot->graph(2)->clearData();
        ui->customPlot->graph(2)->addData(key,all_data::NSL_hum_data.toInt(&ok,10));

        //
        ui->customPlot->graph(0)->removeDataBefore(key-6);
        ui->customPlot->graph(1)->removeDataBefore(key-6);
        //
        ui->customPlot->graph(0)->rescaleValueAxis();
        ui->customPlot->graph(1)->rescaleValueAxis(true);

        lastPointKey = key;
    }
    ui->customPlot->xAxis->setRange(key+0.5,6,Qt::AlignRight);
    ui->customPlot->replot();
}



void IOT_NSL::InitPlot()
{
    ui->customPlot_2->yAxis->setLabel("降雨量(单位:mm)");     //设置纵坐标名称
    ui->warning_NSL->yAxis->setLabel("报警数量统计图");

    ui->customPlot_2->yAxis->setRange(0, 100);   //设置纵坐标范围
    ui->warning_NSL->yAxis->setRange(0, 20);

    setupRealtimeDataDemo(ui->customPlot);
    ui->customPlot_2->replot();
    ui->warning_NSL->replot();
}

void IOT_NSL::InitPre()
{
    ui->customPlot_2->addGraph();
    ui->customPlot_2->graph(0)->setName("降雨量(单位:mm)");
    ui->customPlot_2->graph(0)->setPen(QPen(QColor(246,98,0), 1));
    ui->customPlot_2->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));

    //设置动态曲线的横坐标格式及范围
    ui->customPlot_2->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->customPlot_2->xAxis->setDateTimeFormat("HH:mm:ss");
    ui->customPlot_2->xAxis->setAutoTickStep(false);
    ui->customPlot_2->xAxis->setTickStep(1);
    ui->customPlot_2->xAxis->setRange(0, 6, Qt::AlignRight);
}

void IOT_NSL::loadPre()
{
    bool ok;
    ui->pre_lineEdit->setText(all_data::NSL_pre_data);//显示数据
    pre_key = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    //plot2_value = qrand() % 100;
    ui->customPlot_2->graph(0)->addData(pre_key, all_data::NSL_pre_data.toInt(&ok,10));
    ui->customPlot_2->graph(0)->removeDataBefore(pre_key - 6);
    ui->customPlot_2->xAxis->setRange(pre_key + 0.5 , 6 , Qt::AlignRight);
    ui->customPlot_2->replot();

    if(all_data::NSL_pre_data.toInt(&ok,10)>alarm_data::NSL_pre_Alarm.toInt(&ok,10))
        count2++;

    if(all_data::NSL_pre_data.toInt(&ok,10)>alarm_data::NSL_pre_Alarm.toInt(&ok,10)||all_data::NSL_hum_data.toInt(&ok,10)>alarm_data::NSL_hum_Alarm.toInt(&ok,10))
        this->Alarm_MessageBox();
}

void IOT_NSL::InitAlarm()
{
    maxValue = 0;
    //初始化横坐标名称
    alarmLabels << "1"<< "2"<<"3";

    //初始化纵坐标值/柱状对象
    for (int i = 0; i < 3; i++) {
        alarmValues.append(0);
        alarmKeys.append(i + 1);
        QCPBars *bar = new QCPBars(ui->warning_NSL->xAxis, ui->warning_NSL->yAxis);
        bar->setName(alarmLabels[i]);
        ui->warning_NSL->addPlottable(bar);
        alarmBar.append(bar);
    }

    //设置柱状图形颜色
    QPen pen;
    pen.setWidthF(2);
    pen.setColor(QColor(238,0,0));
    alarmBar[0]->setPen(pen);
    alarmBar[0]->setBrush(QColor(238,0,0,200));
    pen.setColor(QColor(236,110,0));
    alarmBar[1]->setPen(pen);
    alarmBar[1]->setBrush(QColor(236,110,0,200));
    pen.setColor(QColor(222,110,0));
    alarmBar[2]->setPen(pen);
    alarmBar[2]->setBrush(QColor(55,110,0,200));


    //设置横坐标
    ui->warning_NSL->xAxis->setAutoTicks(false);
    ui->warning_NSL->xAxis->setAutoTickLabels(false);
    ui->warning_NSL->xAxis->setSubTickCount(0);
    ui->warning_NSL->xAxis->grid()->setVisible(false);
    ui->warning_NSL->xAxis->setRange(0,3+1);

    //横坐标赋值
    ui->warning_NSL->xAxis->setTickVector(alarmKeys);
    ui->warning_NSL->xAxis->setTickVectorLabels(alarmLabels);

    ui->warning_NSL->axisRect()->setupFullAxesBox();

    //connect(ui->warning_NSL->xAxis,SIGNAL(rangeChanged(QCPRange)),ui->warning_NSL->xAxis2,SLOT(setRange(QCPRange)));
    //connect(ui->warning_NSL->yAxis,SIGNAL(rangeChanged(QCPRange)),ui->warning_NSL->yAxis2,SLOT(setRange(QCPRange)));

}



void IOT_NSL::UpdateAlarm()
{
    alarmValues.clear();

    alarmValues.append(count1);
    alarmBar[0]->clearData();
    alarmBar[0]->addData(1, alarmValues[0]);

    alarmValues.append(count2);
    alarmBar[1]->clearData();
    alarmBar[1]->addData(2, alarmValues[1]);

    alarmValues.append(count3);
    alarmBar[2]->clearData();
    alarmBar[2]->addData(3, alarmValues[2]);

    //pre_key = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    if(count1>count2)
        ui->warning_NSL->yAxis->setRange(0, count1);
    else
        ui->warning_NSL->yAxis->setRange(0, count2);

    /*
    for (int i = 0; i < 3; i++) {
        double value = qrand() % (20-1);
        alarmValues.append(value);
        alarmBar[i]->clearData();
        alarmBar[i]->addData(i + 1, alarmValues[i]);
    }
    */
    ui->warning_NSL->replot();


}



void IOT_NSL::Alarm_MessageBox()
{
    box = new QMessageBox;
    QTimer::singleShot(1500, box, SLOT(close()));

    count3++;

    box->setWindowTitle(tr("警告"));
    box->setIcon(QMessageBox::Warning);
    box->setText(tr("泥石流即将发生！！！"));
    QPushButton *yesBtn = box->addButton(tr("是(&Y)"), QMessageBox::YesRole);
    QPushButton *cancel = box->addButton(tr("取消"), QMessageBox::RejectRole);
    box->show();
    if(QMessageBox::YesRole||QMessageBox::YesRole)
    {
        QTimer::singleShot(000, box, SLOT(close()));
    }
}
void IOT_NSL::on_startButton_clicked()
{

    dataTimer->start(0);
    preTimer->start(0);
    alarmTimer->start(0);
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

void IOT_NSL::on_stopButton_clicked()
{
    alarmTimer->stop();
    dataTimer->stop();
    preTimer->stop();
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}

void IOT_NSL::on_back_clicked()
{
    int a=0;
    all_data::NSL_hum_data = QString::number(a,10);   //转成字符串
    all_data::NSL_pre_data = QString::number(a,10);   //转成字符串
    alarmTimer->stop();
    preTimer->stop();
    dataTimer->stop();
    this->close();

}
