#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"
#include <QMdiSubWindow>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this); // �������������
    actionSeparator->setSeparator(true); // ���������ü����
    updateMenus();   // ���²˵�
    connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow*)),this,
            SLOT(updateMenus()));  // ���л����ʱ���²˵�
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()  // �½��ļ��˵�
{
    MdiChild *child = createMdiChild();   // ����MdiChild
    child->newFile(); // �½��ļ�
    child->show();    // ��ʾ�Ӵ���
}

MdiChild * MainWindow::createMdiChild() // �����Ӵ��ڲ���
{
    MdiChild *child = new MdiChild;   // ����MdiChild����
    ui->mdiArea->addSubWindow(child); // ����ĵ���������Ӵ��ڣ�childΪ���Ĳ���

    // ����QTextEdit����Ƿ���Ը����ź����ü��и��ƶ����Ƿ����
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCut,
            SLOT(setEnabled(bool)));
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCopy,
            SLOT(setEnabled(bool)));

    // ����QTextDocument����Ƿ���Գ����ָ��ź����ó����ָ������Ƿ����
    connect(child->document(),SIGNAL(undoAvailable(bool)),
            ui->actionUndo,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(redoAvailable(bool)),
            ui->actionRedo,SLOT(setEnabled(bool)));

    return child;
}

void MainWindow::updateMenus() // ���²˵�
{
    bool hasMdiChild = (activeMdiChild() != 0); // �Ƿ��л����
    ui->actionSave->setEnabled(hasMdiChild);    // ���ø��������Ƿ����
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);
    actionSeparator->setVisible(hasMdiChild);  // ���ü�����Ƿ���ʾ

    bool hasSelection = (activeMdiChild()
                         && activeMdiChild()->textCursor().hasSelection());

    // �л�������б�ѡ����ı������и��Ʋſ���
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);

    ui->actionUndo->setEnabled(activeMdiChild() // �л�������ĵ��г�������
                          && activeMdiChild()->document()->isUndoAvailable());
    ui->actionRedo->setEnabled(activeMdiChild() // �л�������ĵ��лָ�����
                          && activeMdiChild()->document()->isRedoAvailable());
}

MdiChild * MainWindow::activeMdiChild() // �����
{
    // ����л���ڣ������ڵ����Ĳ���ת��ΪMdiChild����
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0; // û�л���ڣ�ֱ�ӷ���0
}

void MainWindow::on_actionOpen_triggered() // ���ļ��˵�
{
    QString fileName = QFileDialog::getOpenFileName(this); // ��ȡ�ļ�·��
    if (!fileName.isEmpty()) { // ���·����Ϊ�գ���鿴���ļ��Ƿ��Ѿ���
        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing) { // ����Ѿ����ڣ��򽫶�Ӧ���Ӵ�������Ϊ�����
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }

        MdiChild *child = createMdiChild(); // ���û�д򿪣����½��Ӵ���
        if (child->loadFile(fileName)) {
            ui->statusBar->showMessage(tr("���ļ��ɹ�"), 2000);
            child->show();
        } else {
            child->close();
        }
    }
}

QMdiSubWindow * MainWindow::findMdiChild(const QString &fileName) // �����Ӵ���
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    // ����foreach�������Ӵ����б�������ļ�·����Ҫ���ҵ�·����ͬ���򷵻ظô���
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath)
            return window;
    }
    return 0;
}

void MainWindow::setActiveSubWindow(QWidget *window) // ���û�Ӵ���
{
    if (!window) // ��������˴��ڲ�������������Ϊ�����
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}


