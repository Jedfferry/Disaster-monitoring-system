#include "mainwindow.h"
#include "newform.h"
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


    datetime =   new QDateTime(QDateTime::currentDateTime());
    QString date;
    QString time;
    date = datetime->date().toString();
    time = datetime->time().toString();
    qDebug() << date.toLatin1();
    qDebug() << time.toLatin1();



    ui->date_label->setText(date);
    ui->time_label->setText(time);

    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(processOneThing()));
    state = 0;

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
    ui->lcdNumber->display(datetime->currentDateTime().time().toString());

    ui->lcdNumber->move(ui->lcdNumber->geometry().x()+5,ui->lcdNumber->geometry().y()+5);
    ui->lcdNumber->resize(ui->lcdNumber->geometry().width()+5,ui->lcdNumber->geometry().height()+5);

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



void MainWindow::on_start_clicked()
{

    ui->opt1->setFocusPolicy(Qt::NoFocus);


        if(state == 0)
        {
        timer->start();
        ui->start->setText("stop");
        state = 1;
        }
        else
        {
        timer->stop();
        ui->start->setText("start");
        state = 0;
        }
}


void MainWindow::on_pushButton_2_clicked()
{
     w  = new newForm(this);
     connect(w,SIGNAL(back()),this,SLOT(back_slot()));
     w->show();
     this->hide();
}

void MainWindow::back_slot()
{
    w->hide();
    this->show();
}
