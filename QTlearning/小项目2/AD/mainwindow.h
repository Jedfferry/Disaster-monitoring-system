#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QThread>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>


namespace Ui {
class MainWindow;
}


class ADC_Thread : public QThread
{
    Q_OBJECT

signals:

    void put_value(int data);

public:
    ~ADC_Thread();
    void run();
    int adc_fd;

};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ADC_Thread *AThread;
    int pwm_fd;

private slots:
    void on_dial_valueChanged(int value);
    void on_pushButton_clicked();
    void get_value(int data);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
