#include "iot_ysbt.h"
#include "ui_iot_ysbt.h"

IOT_YSBT::IOT_YSBT(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IOT_YSBT)
{
    ui->setupUi(this);


    TimerData = new QTimer();
    connect(TimerData,SIGNAL(timeout()),this,SLOT(showData()));

    TimerData->start(500);


}

IOT_YSBT::~IOT_YSBT()
{

    TimerData->stop();
    box->close();

    delete ui;
}

void IOT_YSBT::showData()
{
    bool ok;
    ui->lineEdit1_x->setText(all_data::YSBT_1_X);
    ui->lineEdit1_y->setText(all_data::YSBT_1_Y);
    ui->lineEdit1_z->setText(all_data::YSBT_1_Z);
    ui->dial_1->setValue(all_data::YSBT_1_X.toInt(&ok,10));
    ui->dial_2->setValue(all_data::YSBT_1_Y.toInt(&ok,10));
    ui->dial_3->setValue(all_data::YSBT_1_Z.toInt(&ok,10));

    //ui->lineEdit2_x->setText(all_data::YSBT_2_X);
    //ui->lineEdit2_y->setText(all_data::YSBT_2_Y);
    //ui->lineEdit2_z->setText(all_data::YSBT_2_Z);
    //ui->dial_2->setValue(all_data::YSBT_2_X.toInt(&ok,10));

    if(all_data::YSBT_1_X.toInt(&ok,10)>alarm_data::YSBT_1_X_Alarm.toInt(&ok,10)||
            all_data::YSBT_2_X.toInt(&ok,10)>alarm_data::YSBT_2_X_Alarm.toInt(&ok,10))
        this->Alarm_MessageBox();
}

void IOT_YSBT::Alarm_MessageBox()
{
    box = new QMessageBox;
   // QTimer::singleShot(1500, box, SLOT(close()));

    box->setWindowTitle(tr("警告"));
    box->setIcon(QMessageBox::Warning);
   // box->setIconPixmap("xxx.png");
    box->setText(tr("岩石崩塌即将发生！！！"));
    QPushButton *yesBtn = box->addButton(tr("是(&Y)"), QMessageBox::YesRole);
    QPushButton *cancel = box->addButton(tr("取消"), QMessageBox::RejectRole);
    box->show();
    if((!(QMessageBox::YesRole))||(!(QMessageBox::YesRole)))
    {
        QTimer::singleShot(000, box, SLOT(close()));
    }
}

void IOT_YSBT::on_back_clicked()
{
    int a=0;
    all_data::YSBT_1_X = QString::number(a,10);   //转成字符串
    all_data::YSBT_1_Y = QString::number(a,10);   //转成字符串
    all_data::YSBT_1_Z = QString::number(a,10);   //转成字符串

    all_data::YSBT_2_X = QString::number(a,10);   //转成字符串
    all_data::YSBT_2_Y = QString::number(a,10);   //转成字符串
    all_data::YSBT_2_Z = QString::number(a,10);   //转成字符串
    TimerData->stop();
    this->close();
}
