#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>

#include "tcpserver.h"
#include "tcpclient.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    port = 45454;
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);

    server = new TcpServer(this);
    connect(server, SIGNAL(sendFileName(QString)), this, SLOT(getFileName(QString)));
}

Widget::~Widget()
{
    delete ui;
}

// ʹ��UDP�㲥������Ϣ
void Widget::sendMessage(MessageType type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();
    out << type << getUserName() << localHostName;

    switch(type)
    {
    case Message :
        if (ui->messageTextEdit->toPlainText() == "") {
            QMessageBox::warning(0,tr("����"),tr("�������ݲ���Ϊ��"),QMessageBox::Ok);
            return;
        }
        out << address << getMessage();
        ui->messageBrowser->verticalScrollBar()
                ->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;

    case NewParticipant :
        out << address;
        break;

    case ParticipantLeft :
        break;

    case FileName : {
        int row = ui->userTableWidget->currentRow();
        QString clientAddress = ui->userTableWidget->item(row, 2)->text();
        out << address << clientAddress << fileName;
        break;
    }

    case Refuse :
        out << serverAddress;
        break;
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
}

// ����UDP��Ϣ
void Widget::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram, QIODevice::ReadOnly);
        int messageType;
        in >> messageType;
        QString userName,localHostName,ipAddress,message;
        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");

        switch(messageType)
        {
        case Message:
            in >> userName >> localHostName >> ipAddress >> message;
            ui->messageBrowser->setTextColor(Qt::blue);
            ui->messageBrowser->setCurrentFont(QFont("Times New Roman",12));
            ui->messageBrowser->append("[ " +userName+" ] "+ time);
            ui->messageBrowser->append(message);
            break;

        case NewParticipant:
            in >>userName >>localHostName >>ipAddress;
            newParticipant(userName,localHostName,ipAddress);
            break;

        case ParticipantLeft:
            in >>userName >>localHostName;
            participantLeft(userName,localHostName,time);
            break;

        case FileName: {
            in >> userName >> localHostName >> ipAddress;
            QString clientAddress, fileName;
            in >> clientAddress >> fileName;
            hasPendingFile(userName, ipAddress, clientAddress, fileName);
            break;
        }

        case Refuse: {
            in >> userName >> localHostName;
            QString serverAddress;
            in >> serverAddress;
            QString ipAddress = getIP();

            if(ipAddress == serverAddress)
            {
                server->refused();
            }
            break;
        }
        }
    }
}

// �������û�����
void Widget::newParticipant(QString userName, QString localHostName, QString ipAddress)
{
    bool isEmpty = ui->userTableWidget->findItems(localHostName, Qt::MatchExactly).isEmpty();
    if (isEmpty) {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

        ui->userTableWidget->insertRow(0);
        ui->userTableWidget->setItem(0,0,user);
        ui->userTableWidget->setItem(0,1,host);
        ui->userTableWidget->setItem(0,2,ip);
        ui->messageBrowser->setTextColor(Qt::gray);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
        ui->messageBrowser->append(tr("%1 ���ߣ�").arg(userName));
        ui->userNumLabel->setText(tr("����������%1").arg(ui->userTableWidget->rowCount()));

        sendMessage(NewParticipant);
    }
}

// �����û��뿪
void Widget::participantLeft(QString userName, QString localHostName, QString time)
{
    int rowNum = ui->userTableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
    ui->messageBrowser->append(tr("%1 �� %2 �뿪��").arg(userName).arg(time));
    ui->userNumLabel->setText(tr("����������%1").arg(ui->userTableWidget->rowCount()));
}

// ��ȡip��ַ
QString Widget::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}

// ��ȡ�û���
QString Widget::getUserName()
{
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables) {
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2) {
                return stringList.at(1);
                break;
            }
        }
    }
    return "unknown";
}

// ���Ҫ���͵���Ϣ
QString Widget::getMessage()
{
    QString msg = ui->messageTextEdit->toHtml();

    ui->messageTextEdit->clear();
    ui->messageTextEdit->setFocus();
    return msg;
}


// ������Ϣ
void Widget::on_sendButton_clicked()
{
    sendMessage(Message);
}




// ��ȡҪ���͵��ļ���
void Widget::getFileName(QString name)
{
    fileName = name;
    sendMessage(FileName);
}

// �����ļ���ť
void Widget::on_sendToolBtn_clicked()
{
    if(ui->userTableWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(0, tr("ѡ���û�"),
                       tr("���ȴ��û��б�ѡ��Ҫ���͵��û���"), QMessageBox::Ok);
        return;
    }
    server->show();
    server->initServer();
}

// �Ƿ�����ļ�
void Widget::hasPendingFile(QString userName, QString serverAddress,
                            QString clientAddress, QString fileName)
{
    QString ipAddress = getIP();
    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this,tr("�����ļ�"),
                                           tr("����%1(%2)���ļ���%3,�Ƿ���գ�")
                                           .arg(userName).arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes,QMessageBox::No);
        if (btn == QMessageBox::Yes) {
            QString name = QFileDialog::getSaveFileName(0,tr("�����ļ�"),fileName);
            if(!name.isEmpty())
            {
                TcpClient *client = new TcpClient(this);
                client->setFileName(name);
                client->setHostAddress(QHostAddress(serverAddress));
                client->show();
            }
        } else {
            sendMessage(Refuse, serverAddress);
        }
    }
}




