#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QDateTime *datetime;
    QTimer *timer;
    int state;
    newForm *w;

signals:

    void my_signal();


private slots:

       void signal_test();
       void processOneThing();
       void on_pushButton_clicked();
       void back_slot();
       void on_start_clicked();


       void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
