#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// �½��ļ��˵�
void MainWindow::on_actionNew_triggered()
{
    // ����MdiChild
    MdiChild *child = new MdiChild;
    // ���ĵ���������Ӵ���
    ui->mdiArea->addSubWindow(child);
    // �½��ļ�
    child->newFile();
    // ��ʾ�Ӵ���
    child->show();
}
