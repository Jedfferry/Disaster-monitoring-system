#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_BTN1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void MainWindow::on_BTN_DEL_clicked()
{
  ui->lineEdit->setText("");
}

void MainWindow::on_BTN2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::on_BTN3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::on_BTN4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::on_BTN5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void MainWindow::on_BTN6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void MainWindow::on_BTN7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void MainWindow::on_BTN8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void MainWindow::on_BTN_ENTER_clicked()
{

}


 bool MainWindow::event(QEvent * e)
{
    //qDebug("event()");
    //qDebug() << "type:"  << e->type();
    return QWidget::event(e);
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
     qDebug("keyPressEvent()");
     //qDebug() << "key:"  << event->key();
     if(event->key() == Qt::Key_1)
     {
/*
         QMouseEvent *Mouse1 = new QMouseEvent(QEvent::MouseButtonPress,QPoint(0,0),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
         QApplication::postEvent(ui->BTN1,Mouse1);
         QMouseEvent *Mouse2= new QMouseEvent(QEvent::MouseButtonRelease,QPoint(0,0),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
         QApplication::postEvent(ui->BTN1,Mouse2);
*/
          QKeyEvent *key1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_Space,Qt::NoModifier,"1",false,1);
          QApplication::postEvent(ui->BTN1,key1);
          QKeyEvent *key2= new QKeyEvent(QEvent::KeyRelease,Qt::Key_Space,Qt::NoModifier,"1",false,1);
          QApplication::postEvent(ui->BTN1,key2);
     }
     else if(event->key() == Qt::Key_2 )
     {

            QKeyEvent *key3 = new QKeyEvent(QEvent::KeyPress,Qt::Key_Space,Qt::NoModifier,"2",false,1);
            QApplication::postEvent(ui->BTN2,key3);
            QKeyEvent *key4= new QKeyEvent(QEvent::KeyRelease,Qt::Key_Space,Qt::NoModifier,"2",false,1);
            QApplication::postEvent(ui->BTN2,key4);

      }

     return QWidget::keyReleaseEvent(event);

}

