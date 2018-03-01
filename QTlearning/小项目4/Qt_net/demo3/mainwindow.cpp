#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QFile>
#include <QtextStream>
#include <QDebug>
#include <QHostAddress>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    tcpSocket = new QTcpSocket( this );

    ui->lineEdit_IP->setText("192.168.1.216");
    ui->lineEdit_Port->setText("5084");
    ui->textEdit_Send->setText("Hello World!");

    connect( tcpSocket, SIGNAL(error(int)), this, SLOT(errMsg(int)) );
    connect( ui->pushButton_Send, SIGNAL(clicked()), this, SLOT(on_pushButton_Send_clicked(bool)) );
    connect( ui->pushButton_Connect, SIGNAL(clicked()), this, SLOT(on_pushButton_Connect_clicked(bool)) );
    connect( tcpSocket, SIGNAL(readyRead()), this, SLOT(recvMsg()) );

    QStatusBar* bar = ui->statusBar;          //获取状态栏
    fstLabel = new QLabel;                    //新建标签
    fstLabel->setMinimumSize(150,20);         //设置标签最小尺寸
    fstLabel->setFrameShape(QFrame::Panel);   //设置标签形状
    fstLabel->setFrameShadow(QFrame::Sunken); //设置标签阴影

    secLabel = new QLabel;
    secLabel->setFrameShape(QFrame::Panel);
    secLabel->setFrameShadow(QFrame::Sunken);
    secLabel->setText(tr("GEC"));
    fstLabel->setText(tr("状态信息"));

    bar->addPermanentWidget(fstLabel);
    bar->addPermanentWidget(secLabel);

    ui->pushButton_Connect->setEnabled(true);
    ui->pushButton_Close->setEnabled(false);
    ui->pushButton_Send->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recvMsg()
{

    QByteArray new_data;
    new_data += tcpSocket->readAll();
    ui->textEdit_Recv->insertPlainText(QString(new_data));

    fstLabel->setText(tr("接收成功"));
}

void MainWindow::errMsg( int errNo )
{
   qWarning( "this is err %d!", errNo );
   fstLabel->setText(tr("连接错误"));
}



void MainWindow::on_pushButton_Connect_clicked()
{
    QString port;
    int port_Int;

    port = ui->lineEdit_Port->text();
    port_Int = port.toInt();

    tcpSocket->connectToHost(QHostAddress(ui->lineEdit_IP->text()),port_Int,QIODevice::ReadWrite);

    if (!tcpSocket->waitForConnected(2))
    {
        tcpSocket->disconnectFromHost();
        return;
    }

    SocketStatus = true;
    ui->pushButton_Connect->setEnabled(false);
    ui->pushButton_Close->setEnabled(true);
    ui->pushButton_Send->setEnabled(true);
    fstLabel->setText(tr("连接成功"));
}

void MainWindow::on_pushButton_Close_clicked()
{
    tcpSocket->disconnectFromHost();
    SocketStatus = false;
    ui->pushButton_Connect->setEnabled(true);
    ui->pushButton_Close->setEnabled(false);
    ui->pushButton_Send->setEnabled(false);
    fstLabel->setText(tr("关闭连接"));
}

void MainWindow::on_pushButton_Send_clicked()
{
    QTextStream out(tcpSocket);
    QString context = ui->textEdit_Send->text();
    out << context << endl;

    //tcpSocket->write();

    fstLabel->setText(tr("发送成功"));
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->textEdit_Recv->clear();
    fstLabel->setText(tr("清除接收区"));
}
