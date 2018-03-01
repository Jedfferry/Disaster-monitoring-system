#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
