#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class MdiChild;
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
    void on_actionNew_triggered(); //�½��ļ��˵�
    void updateMenus();           //���²˵�
    MdiChild *createMdiChild(); //�����Ӵ���

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator;    //�ָ���
    MdiChild *activeMdiChild(); //�����
};

#endif // MAINWINDOW_H
