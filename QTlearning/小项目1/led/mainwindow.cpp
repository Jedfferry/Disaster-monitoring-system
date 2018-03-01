#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LED1_S = false;
    LED2_S = false;
    LED3_S = false;
    LED4_S = false;
    LEDALL_S = false;

    Lthread = new LED_Thread;

    led_fd = ::open("/dev/led",O_RDWR);
    if(led_fd == -1)
    {
        qDebug(" open LED Failed!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    ::close(led_fd);
}

void MainWindow::on_LED1_BTN_clicked()
{
    if(!LED1_S)
    {
        ::ioctl(led_fd,LED1,LED_ON);
        LED1_S = true;
        ui->LED1_BTN->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
    }
    else
    {
        ::ioctl(led_fd,LED1,LED_OFF);
        LED1_S = false;
        ui->LED1_BTN->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    }
}

void MainWindow::on_LED2_BTN_clicked()
{
    if(!LED2_S)
    {
        ::ioctl(led_fd,LED2,LED_ON);
        LED2_S = true;
        ui->LED2_BTN->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
    }
    else
    {
        ::ioctl(led_fd,LED2,LED_OFF);
        LED2_S = false;
        ui->LED2_BTN->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    }
}

void MainWindow::on_LED3_BTN_clicked()
{
    if(!LED3_S)
    {
        ::ioctl(led_fd,LED3,LED_ON);
        LED3_S = true;
        ui->LED3_BTN->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
    }
    else
    {
        ::ioctl(led_fd,LED3,LED_OFF);
        LED3_S = false;
        ui->LED3_BTN->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    }
}

void MainWindow::on_LED4_BTN_clicked()
{
    if(!LED4_S)
    {
        ::ioctl(led_fd,LED4,LED_ON);
        LED4_S = true;
        ui->LED4_BTN->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
    }
    else
    {
        ::ioctl(led_fd,LED4,LED_OFF);
        LED4_S = false;
        ui->LED4_BTN->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    }
}

void MainWindow::on_LEDALL_BTN_clicked()
{
    if(!LEDALL_S)
    {
      LEDALL_S = true;
      Lthread->state = 1;
      Lthread ->start();
      ui->LEDALL_BTN->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
    }
    else
    {
         LEDALL_S = false;
         Lthread->state = 0;
         ui->LEDALL_BTN->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    }

}


void LED_Thread::run()
{
    while(state)
    {
       // goto hurse LED
       qDebug("hurse LED");
       sleep(1);

    }

}
