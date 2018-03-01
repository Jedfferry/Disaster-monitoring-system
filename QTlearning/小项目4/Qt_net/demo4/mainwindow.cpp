
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QFile>
#include <QtextStream>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer(this);

    QStatusBar* bar = ui->statusBar;          //获取状态栏
    fstLabel = new QLabel;                    //新建标签
    fstLabel->setMinimumSize(150,20);         //设置标签最小尺寸
    fstLabel->setFrameShape(QFrame::Panel);   //设置标签形状
    fstLabel->setFrameShadow(QFrame::Sunken); //设置标签阴影

    secLabel = new QLabel;
    secLabel->setFrameShape(QFrame::Panel);
    secLabel->setFrameShadow(QFrame::Sunken);
    secLabel->setText(tr("GEC"));
    secLabel->setOpenExternalLinks(true);
    fstLabel->setText(tr("状态信息"));

    bar->addPermanentWidget(fstLabel);
    bar->addPermanentWidget(secLabel);

    ui->pushButton_Start->setEnabled(true);
    ui->pushButton_Stop->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::acceptConnection()
{
    tcpSocket = new QTcpSocket;
    tcpSocket = tcpServer->nextPendingConnection();                //使TCPsocket=当前访问者
    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(recv_Msg()));//连接槽当有数据时进入
    connect(tcpSocket, SIGNAL(disconnected()),this, SLOT(clear_socket()));
}


void MainWindow::clear_socket()
{
    qDebug()<< "clear_socket";
    tcpSocket->close();
}

void MainWindow::recv_Msg()
{
    QString Recv;
    Recv += tcpSocket->readAll();
    ui->textEdit_Recv->moveCursor(QTextCursor::End);
    ui->textEdit_Recv->insertPlainText(Recv);
    fstLabel->setText(tr("接收成功"));
    tcpSocket->write(Recv.toLatin1());
}

void MainWindow::on_pushButton_Start_clicked()
{
    ui->pushButton_Start->setEnabled(false);
    ui->pushButton_Stop->setEnabled(true);

    tcpServer->listen(QHostAddress::Any,5084);

    connect(tcpServer, SIGNAL(newConnection()),this, SLOT(acceptConnection()));
    fstLabel->setText(tr("监听端口:%1").arg("5084"));
}

void MainWindow::on_pushButton_Stop_clicked()
{
    tcpServer->close();
    ui->pushButton_Start->setEnabled(true);
    ui->pushButton_Stop->setEnabled(false);
    fstLabel->setText(tr("停止监听"));
}
