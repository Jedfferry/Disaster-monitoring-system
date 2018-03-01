#include "mainwindow.h"
#include "ui_mainwindow.h"

#define  BUZZER_IOCTL_SET_FREQ 1
#define  BUZZER_IOCTL_STOP 0

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AThread = new ADC_Thread;
    AThread->start();

    pwm_fd = ::open("/dev/pwm",O_RDWR);
    if(pwm_fd == -1)
    {
        perror(" Open PWM");
    }


    connect(AThread,SIGNAL(put_value(int)),this,SLOT(get_value(int)));
}

MainWindow::~MainWindow()
{
    ::close(pwm_fd);
    delete ui;
    delete AThread;
}

void MainWindow::on_dial_valueChanged(int value)
{
    QString num;
    num.setNum(value);
    ui->label->setText(num);
}

void MainWindow::on_pushButton_clicked()
{

    ::ioctl(pwm_fd,BUZZER_IOCTL_STOP,0);
    ui->pushButton->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));


}


void MainWindow::get_value(int data)
{
    QString num;
    num.setNum(data);
    ui->dial->setValue(data);
    ui->label->setText(num);

    qDebug()<< " ADC :" <<data;

    if(data > 2430)
    {
        ::ioctl(pwm_fd,BUZZER_IOCTL_SET_FREQ,2);
        ui->pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

    }

}

void ADC_Thread::run()
{
    int data,ret;
    adc_fd = ::open("/dev/adc",O_RDONLY);
    if(adc_fd == -1)
    {
        perror(" Open ADC");
    }

    while(1)
    {
       ret = ::read(adc_fd,&data,sizeof(data));
       if(ret == -1)
       {
           perror(" Read Failed");
           continue;
       }
       emit put_value(data);
       sleep(1);
    }

}

ADC_Thread::~ADC_Thread()
{
    ::close(adc_fd);
}

