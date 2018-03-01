#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QByteArray Send_Check(QString tmp, bool hex);



private slots:
    void on_pushButton_Connect_clicked();
    void on_pushButton_Close_clicked();
    void on_pushButton_Send_clicked();
    void on_pushButton_Clear_clicked();
    void recvMsg();
    void errMsg( int errNo );



private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;

    QLabel*fstLabel;
    QLabel*secLabel;
    bool SocketStatus;



};

#endif // MAINWINDOW_H
