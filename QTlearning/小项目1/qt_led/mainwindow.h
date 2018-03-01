#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13

#define LED_ON 0
#define LED_OFF 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int led_fd;
    bool LED1_S;
    bool LED2_S;
    bool LED3_S;
    bool LED4_S;


private slots:
    void on_LED1_BTN_clicked();

    void on_LED2_BTN_clicked();

    void on_LED3_BTN_clicked();

    void on_LED4_BTN_clicked();

    void on_LEDALL_BTN_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
