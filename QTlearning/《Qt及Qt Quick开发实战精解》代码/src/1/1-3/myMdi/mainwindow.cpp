#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"
#include <QMdiSubWindow>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this); //�������������
    actionSeparator->setSeparator(true); //���������ü����
    updateMenus();                       //���²˵�
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(updateMenus()));           //���л����ʱ���²˵�
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()  //�½��ļ��˵�
{
    MdiChild *child = createMdiChild();    //����MdiChild
    child->newFile();                      //�½��ļ�
    child->show();                         //��ʾ�Ӵ���
}

MdiChild * MainWindow::createMdiChild() //�����Ӵ��ڲ���
{
    MdiChild *child = new MdiChild; //����MdiChild����
    ui->mdiArea->addSubWindow(child); //����ĵ���������Ӵ��ڣ�childΪ���Ĳ���
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCut,
            SLOT(setEnabled(bool)));

    // ����QTextEdit����Ƿ���Ը����ź����ü��и��ƶ����Ƿ����
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCopy,
            SLOT(setEnabled(bool)));

    // ����QTextDocument����Ƿ���Գ����ָ��ź����ó����ָ������Ƿ����
    connect(child->document(),SIGNAL(undoAvailable(bool)),
            ui->actionUndo,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(redoAvailable(bool)),
            ui->actionRedo,SLOT(setEnabled(bool)));

    return child;
}

void MainWindow::updateMenus() //���²˵�
{
    bool hasMdiChild = (activeMdiChild() != 0); //�Ƿ��л����
    ui->actionSave->setEnabled(hasMdiChild);    //���ø��������Ƿ����
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);
    actionSeparator->setVisible(hasMdiChild);   //���ü�����Ƿ���ʾ

    bool hasSelection = (activeMdiChild()
                         && activeMdiChild()->textCursor().hasSelection());

    // �л�������б�ѡ����ı������и��Ʋſ���
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);

    // �л�������ĵ��г�������
    ui->actionUndo->setEnabled(activeMdiChild()
                          && activeMdiChild()->document()->isUndoAvailable());

    // �л�������ĵ��лָ�����
    ui->actionRedo->setEnabled(activeMdiChild()
                          && activeMdiChild()->document()->isRedoAvailable());
}

MdiChild * MainWindow::activeMdiChild() //�����
{
    // ����л���ڣ������ڵ����Ĳ���ת��ΪMdiChild����
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0; // û�л���ڣ�ֱ�ӷ���0
}
