#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class MdiChild;
class QMdiSubWindow;
class QSignalMapper;
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
    void on_actionNew_triggered(); // �½��ļ��˵�
    void updateMenus();            // ���²˵�
    MdiChild *createMdiChild();    // �����Ӵ���
    void setActiveSubWindow(QWidget *window); // ���û�Ӵ���

    void on_actionOpen_triggered(); // ���ļ��˵�

    void updateWindowMenu(); // ���´��ڲ˵�

private:
    Ui::MainWindow *ui;
    QAction *actionSeparator; // �ָ���
    MdiChild *activeMdiChild(); // �����
    QMdiSubWindow *findMdiChild(const QString &fileName);// �����Ӵ���

    QSignalMapper *windowMapper; // �ź�ӳ����
};

#endif // MAINWINDOW_H
