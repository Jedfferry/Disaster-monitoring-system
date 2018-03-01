#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QDate>
#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDateTime *datatime =   new QDateTime(QDateTime::currentDateTime());
    QString date;
    QString time;
    date = datatime->date().toString();
    time = datatime->time().toString();
    qDebug() << date.toLatin1();
    qDebug() << time.toLatin1();

    ui->date_label->setText(date);
    ui->time_label->setText(time);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(processOneThing()));
    timer->start(1000);

    connect(this,SIGNAL(my_signal()),this,SLOT(signal_test()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::signal_test()
{
    this->close();
}

void MainWindow::processOneThing()
{
    qDebug(" Time out!");


}

void MainWindow::on_pushButton_clicked()
{
    QString str1 =  ui->opt1->text();
    QString str2 =  ui->opt2->text();
    QString value;

    bool ok;
    int num1,num2;
    num1 = str1.toInt(&ok);
    num2 = str2.toInt(&ok);

    value.setNum(num1+num2);

    ui->value->setText(value);

    qDebug(value.toLatin1());
}
