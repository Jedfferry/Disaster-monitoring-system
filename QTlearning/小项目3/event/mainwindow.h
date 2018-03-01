#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool event(QEvent * e);
    void keyPressEvent(QKeyEvent * event);

private slots:

    void on_BTN1_clicked();
    void on_BTN_DEL_clicked();
    void on_BTN2_clicked();
    void on_BTN3_clicked();
    void on_BTN4_clicked();
    void on_BTN5_clicked();
    void on_BTN6_clicked();
    void on_BTN7_clicked();
    void on_BTN8_clicked();
    void on_BTN_ENTER_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
