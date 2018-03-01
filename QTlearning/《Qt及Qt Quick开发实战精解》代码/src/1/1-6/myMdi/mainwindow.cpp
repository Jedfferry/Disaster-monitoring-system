#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"
#include <QMdiSubWindow>
#include <QFileDialog>
#include <QSignalMapper>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this); // �������������
    actionSeparator->setSeparator(true); // ���������ü����
    updateMenus();                       // ���²˵�
    connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow*)),this,
            SLOT(updateMenus()));  // ���л����ʱ���²˵�

    windowMapper = new QSignalMapper(this); // �����ź�ӳ����
    connect(windowMapper, SIGNAL(mapped(QWidget*)), // ӳ�������·����ź�
            this, SLOT(setActiveSubWindow(QWidget*))); // ���û����
    updateWindowMenu();

    // ���´��ڲ˵����������õ����ڲ˵���Ҫ��ʾ��ʱ����´��ڲ˵�
    connect(ui->menuW,SIGNAL(aboutToShow()),this,SLOT(updateWindowMenu()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()  // �½��ļ��˵�
{
    MdiChild *child = createMdiChild(); // ����MdiChild
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
    actionSeparator->setVisible(hasMdiChild);   // ���ü�����Ƿ���ʾ

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
        if (existing) {       // ����Ѿ����ڣ��򽫶�Ӧ���Ӵ�������Ϊ�����
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

void MainWindow::updateWindowMenu() // ���´��ڲ˵�
{
    ui->menuW->clear(); // ����ղ˵���Ȼ������Ӹ����˵�����
    ui->menuW->addAction(ui->actionClose);
    ui->menuW->addAction(ui->actionCloseAll);
    ui->menuW->addSeparator();
    ui->menuW->addAction(ui->actionTile);
    ui->menuW->addAction(ui->actionCascade);
    ui->menuW->addSeparator();
    ui->menuW->addAction(ui->actionNext);
    ui->menuW->addAction(ui->actionPrevious);
    ui->menuW->addAction(actionSeparator);

    QList<QMdiSubWindow *> windows = ui->mdiArea->subWindowList();
    actionSeparator->setVisible(!windows.isEmpty());

    // ����л���ڣ�����ʾ�����
    for (int i = 0; i < windows.size(); ++i) { // ���������Ӵ���
        MdiChild *child = qobject_cast<MdiChild *>(windows.at(i)->widget());

        QString text;
        if (i < 9) { // ���������С��9�������ñ��Ϊ��ݼ�
            text = tr("&%1 %2").arg(i + 1)
                               .arg(child->userFriendlyCurrentFile());
        } else {
            text = tr("%1 %2").arg(i + 1)
                              .arg(child->userFriendlyCurrentFile());
        }
        QAction *action  = ui->menuW->addAction(text); // ��Ӷ������˵�
        action->setCheckable(true); // ���ö�������ѡ��

        // ���õ�ǰ����ڶ���Ϊѡ��״̬
        action ->setChecked(child == activeMdiChild());

        // ���������Ĵ����źŵ��ź�ӳ������map()�ۺ����ϣ���������ᷢ��mapped()�ź�
        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));

        // ����������Ӧ�Ĵ��ڲ�������ӳ�䣬�ڷ���mapped()�ź�ʱ�ͻ���������ڲ���Ϊ����
        windowMapper->setMapping(action, windows.at(i));

    }
}

/********************1.3.3С�ڶ�������Щ��������˲���ʡ��****************************************/

void MainWindow::on_actionSave_triggered() // ����˵�
{
    if(activeMdiChild() && activeMdiChild()->save())
        ui->statusBar->showMessage(tr("�ļ�����ɹ�"),2000);
}

void MainWindow::on_actionSaveAs_triggered()  // ���Ϊ�˵�
{
    if(activeMdiChild() && activeMdiChild()->saveAs())
        ui->statusBar->showMessage(tr("�ļ�����ɹ�"),2000);
}

void MainWindow::on_actionUndo_triggered() // �����˵�
{
    if(activeMdiChild()) activeMdiChild()->undo();
}

void MainWindow::on_actionRedo_triggered() // �ָ��˵�
{
    if(activeMdiChild()) activeMdiChild()->redo();
}

void MainWindow::on_actionCut_triggered() // ���в˵�
{
    if(activeMdiChild()) activeMdiChild()->cut();
}

void MainWindow::on_actionCopy_triggered() // ���Ʋ˵�
{
    if(activeMdiChild()) activeMdiChild()->copy();
}

void MainWindow::on_actionPaste_triggered() // ճ���˵�
{
    if(activeMdiChild()) activeMdiChild()->paste();
}

void MainWindow::on_actionClose_triggered() // �رղ˵�
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actionCloseAll_triggered() // �ر����д��ڲ˵�
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_actionTile_triggered() // ƽ�̲˵�
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actionCascade_triggered() // ����˵�
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actionNext_triggered() // ��һ���˵�
{
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_actionPrevious_triggered() // ǰһ���˵�
{
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::on_actionAbout_triggered() // ���ڲ˵�
{
    QMessageBox::about(this,tr("���ڱ����"),tr("��ӭ�������ǵ���վ��www.yafeilinux.com"));
}

void MainWindow::on_actionAboutQt_triggered() // ����Qt�˵�
{
    qApp->aboutQt(); // �����qApp��QApplication�����ȫ��ָ�룬
                     // ���д����൱��QApplication::aboutQt();
}

/***************1.3.3С�ڶ�������Щ��������˲���ʡ��*********************************************/
