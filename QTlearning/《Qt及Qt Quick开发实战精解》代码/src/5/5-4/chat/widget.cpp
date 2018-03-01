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

#include <QColorDialog>

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

    connect(ui->messageTextEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),
            this, SLOT(currentFormatChanged(const QTextCharFormat)));
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



// ����������
void Widget::on_fontComboBox_currentFontChanged(QFont f)
{
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}


// ���������С
void Widget::on_sizeComboBox_currentIndexChanged(QString size)
{
    ui->messageTextEdit->setFontPointSize(size.toDouble());
    ui->messageTextEdit->setFocus();
}

// �Ӵ�
void Widget::on_boldToolBtn_clicked(bool checked)
{
    if(checked)
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    ui->messageTextEdit->setFocus();
}

// ��б
void Widget::on_italicToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontItalic(checked);
    ui->messageTextEdit->setFocus();
}

// �»���
void Widget::on_underlineToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontUnderline(checked);
    ui->messageTextEdit->setFocus();
}

// ��ɫ
void Widget::on_colorToolBtn_clicked()
{
    color = QColorDialog::getColor(color, this);
    if (color.isValid()) {
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();
    }
}

void Widget::currentFormatChanged(const QTextCharFormat &format)
{
    ui->fontComboBox->setCurrentFont(format.font());

    // ��������С����(��Ϊ������С������Ϊ9)��ʹ��12
    if (format.fontPointSize() < 9) {
        ui->sizeComboBox->setCurrentIndex(3);
    } else {
        ui->sizeComboBox->setCurrentIndex( ui->sizeComboBox
                                          ->findText(QString::number(format.fontPointSize())));
    }
    ui->boldToolBtn->setChecked(format.font().bold());
    ui->italicToolBtn->setChecked(format.font().italic());
    ui->underlineToolBtn->setChecked(format.font().underline());
    color = format.foreground().color();
}

// ���������¼
void Widget::on_saveToolBtn_clicked()
{
    if (ui->messageBrowser->document()->isEmpty()) {
        QMessageBox::warning(0, tr("����"), tr("�����¼Ϊ�գ��޷����棡"), QMessageBox::Ok);
    } else {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("���������¼"), tr("�����¼"), tr("�ı�(*.txt);;All File(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}

// ���������¼
bool Widget::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("�����ļ�"),
                             tr("�޷������ļ� %1:\n %2").arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << ui->messageBrowser->toPlainText();

    return true;
}

// ��������¼
void Widget::on_clearToolBtn_clicked()
{
    ui->messageBrowser->clear();
}

// �˳���ť
void Widget::on_exitButton_clicked()
{
    close();
}

// �ر��¼�
void Widget::closeEvent(QCloseEvent *e)
{
    sendMessage(ParticipantLeft);
    QWidget::closeEvent(e);
}
