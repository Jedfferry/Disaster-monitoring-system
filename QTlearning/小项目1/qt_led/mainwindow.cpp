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
    if(LED1_S)
    {
        ::ioctl(led_fd,LED1,LED_ON);
        LED1_S = true;
    }
    else
    {
        ::ioctl(led_fd,LED1,LED_OFF);
        LED1_S = false;
    }
}

void MainWindow::on_LED2_BTN_clicked()
{
    if(LED2_S)
    {
        ::ioctl(led_fd,LED2,LED_ON);
    }
    else
    {
        ::ioctl(led_fd,LED2,LED_OFF);
    }
}

void MainWindow::on_LED3_BTN_clicked()
{
    if(LED3_S)
    {
        ::ioctl(led_fd,LED3,LED_ON);
    }
    else
    {
        ::ioctl(led_fd,LED3,LED_OFF);
    }
}

void MainWindow::on_LED4_BTN_clicked()
{
    if(LED4_S)
    {
        ::ioctl(led_fd,LED4,LED_ON);
    }
    else
    {
        ::ioctl(led_fd,LED4,LED_OFF);
    }
}

void MainWindow::on_LEDALL_BTN_clicked()
{



}
