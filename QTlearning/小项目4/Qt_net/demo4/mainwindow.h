#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
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

private slots:
    void on_pushButton_Start_clicked();
    void on_pushButton_Stop_clicked();
    void recv_Msg();
    void acceptConnection();
    void clear_socket();


private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QLabel*fstLabel;
    QLabel*secLabel;
    QTcpSocket *tcpSocket;

};

#endif // MAINWINDOW_H
