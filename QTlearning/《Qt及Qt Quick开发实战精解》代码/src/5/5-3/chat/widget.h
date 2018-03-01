#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QUdpSocket;

class TcpServer;

namespace Ui {
class Widget;
}

// ö�ٱ�����־��Ϣ�����ͣ��ֱ�Ϊ��Ϣ�����û����룬�û��˳����ļ������ܾ������ļ�
enum MessageType{Message, NewParticipant, ParticipantLeft, FileName, Refuse};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void newParticipant(QString userName,
                        QString localHostName, QString ipAddress);
    void participantLeft(QString userName,
                         QString localHostName, QString time);
    void sendMessage(MessageType type, QString serverAddress="");

    QString getIP();
    QString getUserName();
    QString getMessage();


    void hasPendingFile(QString userName, QString serverAddress,
                        QString clientAddress, QString fileName);

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;

    QString fileName;
    TcpServer *server;

private slots:
    void processPendingDatagrams();

    void on_sendButton_clicked();

    void getFileName(QString);
    void on_sendToolBtn_clicked();
};

#endif // WIDGET_H
