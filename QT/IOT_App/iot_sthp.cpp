#include "iot_sthp.h"
#include "ui_iot_sthp.h"


IOT_STHP::IOT_STHP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IOT_STHP)
{
    ui->setupUi(this);

    this->InitForm();

    this->InitPlot();

    this->InitWater();

    TimerData->start(500);
    waterTimer->start(500);

}

IOT_STHP::~IOT_STHP()
{
    waterTimer->stop();
    TimerData->stop();
    delete ui;
}

void IOT_STHP::InitForm()
{
    TimerData = new QTimer();
    connect(TimerData,SIGNAL(timeout()),this,SLOT(showData()));

    waterTimer = new QTimer(this);//绘制曲线定时器对象
    connect(waterTimer,SIGNAL(timeout()),this,SLOT(loadWater()));

}

void IOT_STHP::InitPlot()
{
    ui->customPlot->yAxis->setLabel("地下水位(单位:cm)");     //设置纵坐标名称

    ui->customPlot->yAxis->setRange(0, 100);   //设置纵坐标范围

    ui->customPlot->replot();
}

void IOT_STHP::InitWater()
{
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setName("地下水位(单位:cm)");
    ui->customPlot->graph(0)->setPen(QPen(QColor(46,98,99), 1));
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));

    //设置动态曲线的横坐标格式及范围
    ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->customPlot->xAxis->setDateTimeFormat("HH:mm:ss");
    ui->customPlot->xAxis->setAutoTickStep(false);
    ui->customPlot->xAxis->setTickStep(1);
    ui->customPlot->xAxis->setRange(0, 6, Qt::AlignRight);
}

void IOT_STHP::loadWater()
{
    bool ok;
    ui->lineEdit_water->setText(all_data::STHP_water);//显示数据
    waterKey = QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
    //duoble plot2_value = qrand() % 100;
    ui->customPlot->graph(0)->addData(waterKey, all_data::STHP_water.toInt(&ok,10));
    ui->customPlot->graph(0)->removeDataBefore(waterKey - 6);
    ui->customPlot->xAxis->setRange(waterKey + 0.5 , 6 , Qt::AlignRight);
    ui->customPlot->replot();
}

void IOT_STHP::showData()
{
    bool ok;
    ui->lineEdit1_x->setText(all_data::STHP_X);
    ui->lineEdit1_y->setText(all_data::STHP_Y);
    ui->lineEdit1_z->setText(all_data::STHP_Z);
    ui->dial_1->setValue(all_data::STHP_water.toInt(&ok,10));

    //if(all_data::STHP_X.toInt(&ok,10)>alarm_data::STHP_X_Alarm.toInt(&ok,10)||
            //all_data::STHP_water.toInt(&ok,10)>alarm_data::STHP_water.toInt(&ok,10))
    if(all_data::STHP_water.toInt(&ok,10)>alarm_data::STHP_water.toInt(&ok,10))//这里是当前湿度值大于水位设定值就报警
        this->Alarm_MessageBox();


}

void IOT_STHP::Alarm_MessageBox()
{
    box = new QMessageBox;
    //QTimer::singleShot(1500, box, SLOT(close()));

    box->setWindowTitle(tr("警告"));
    box->setIcon(QMessageBox::Warning);
    box->setText(tr("山体滑坡即将发生！！！"));
    QPushButton *yesBtn = box->addButton(tr("是(&Y)"), QMessageBox::YesRole);
    QPushButton *cancel = box->addButton(tr("取消"), QMessageBox::RejectRole);
    box->show();
    if(QMessageBox::YesRole||QMessageBox::YesRole)
    {
        QTimer::singleShot(000, box, SLOT(close()));
    }
}

void IOT_STHP::on_back_clicked()
{
    int a=0;
    all_data::STHP_X = QString::number(a,10);   //转成字符串
    all_data::STHP_Y = QString::number(a,10);   //转成字符串
    all_data::STHP_Z = QString::number(a,10);   //转成字符串

    all_data::STHP_water = QString::number(a,10);   //转成字符串

    waterTimer->stop();
    TimerData->stop();
    this->close();
}
