#include "mdichild.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include <QApplication>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPushButton>
#include <QMenu>
MdiChild::MdiChild(QWidget *parent) :
    QTextEdit(parent)
{
    setAttribute(Qt::WA_DeleteOnClose); // �����������Ӵ��ڹر�ʱ���������Ķ���
    isUntitled = true;  // ��ʼisUntitledΪtrue
}


void MdiChild::newFile() // �½��ļ�����
{
    static int sequenceNumber = 1;
    // ���ô��ڱ�ţ���Ϊ���һֱ�����棬������Ҫʹ�þ�̬����

    isUntitled = true; // �½����ĵ�û�б������

    // ����ǰ�ļ�����Ϊδ�����ĵ��ӱ�ţ������ʹ���ټ�1
    curFile = tr("δ�����ĵ�%1.txt").arg(sequenceNumber++);


    // ���ô��ڱ��⣬ʹ��[*]�������ĵ������ĺ����ļ����ƺ���ʾ��*����
    setWindowTitle(curFile + "[*]" + tr(" - ���ĵ��༭��"));

    // ���ĵ�������ʱ����contentsChanged()�źţ�
    // ִ�����ǵ�documentWasModified()�ۺ���
    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

}

void MdiChild::documentWasModified() //�ĵ�������ʱ��������ʾ����״̬��־
{
    // �����ĵ���isModified()�����ķ���ֵ���ж����Ǳ༭�������Ƿ񱻸�����
    // ����������ˣ���Ҫ��������[*]�ŵĵط���ʾ��*���ţ��������ǻ��ڴ��ڱ�������ʾ
    setWindowModified(document()->isModified());
}

bool MdiChild::loadFile(const QString &fileName) // �����ļ�
{
    QFile file(fileName); // �½�QFile����
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("���ĵ��༭��"),
                             tr("�޷���ȡ�ļ� %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return false; // ֻ����ʽ���ļ�����������ʾ��������false
    }

    QTextStream in(&file); // �½��ı�������
    QApplication::setOverrideCursor(Qt::WaitCursor); // �������״̬Ϊ�ȴ�״̬
    setPlainText(in.readAll());  // ��ȡ�ļ���ȫ���ı����ݣ�����ӵ��༭����
    QApplication::restoreOverrideCursor(); // �ָ����״̬

    setCurrentFile(fileName); // ���õ�ǰ�ļ�

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    return true;
}

void MdiChild::setCurrentFile(const QString &fileName) // ���õ�ǰ�ļ�
{
    // canonicalFilePath()���Գ�ȥ·���еķ������ӣ���.���͡�..���ȷ���
    curFile = QFileInfo(fileName).canonicalFilePath();

    isUntitled = false; // �ļ��Ѿ����������
    document()->setModified(false); // �ĵ�û�б����Ĺ�
    setWindowModified(false); // ���ڲ���ʾ�����ı�־

    // ���ô��ڱ��⣬userFriendlyCurrentFile()�����ļ���
    setWindowTitle(userFriendlyCurrentFile() + "[*]");

}

QString MdiChild::userFriendlyCurrentFile() // ��ȡ�ļ���
{
    return QFileInfo(curFile).fileName(); // ���ļ�·������ȡ�ļ���
}

bool MdiChild::save() // �������
{
    if (isUntitled) { // ����ļ�δ�����������ִ�����Ϊ����
        return saveAs();
    } else {
        return saveFile(curFile); // ����ֱ�ӱ����ļ�
    }
}

bool MdiChild::saveAs() // ���Ϊ����
{
    // ��ȡ�ļ�·�������Ϊ�գ��򷵻�false
    QString fileName = QFileDialog::getSaveFileName(this, tr("���Ϊ"),curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName); // ���򱣴��ļ�
}

bool MdiChild::saveFile(const QString &fileName) // �����ļ�
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("���ĵ��༭��"),
                             tr("�޷�д���ļ� %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText(); // �Դ��ı��ļ�д��
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}


void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) { // ���maybeSave()��������true����رմ���
        event->accept();
    } else {   // ������Ը��¼�
        event->ignore();
    }
}


bool MdiChild::maybeSave()  // �Ƿ���Ҫ����
{
    if (document()->isModified()) { // ����ĵ������Ĺ�
        QMessageBox box;
        box.setWindowTitle(tr("���ĵ��༭��"));
        box.setText(tr("�Ƿ񱣴�ԡ�%1���ĸ��ģ�")
                    .arg(userFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);

        // ��Ӱ�ť��QMessageBox::YesRole���Ա��������ť����Ϊ
        QPushButton *yesBtn = box.addButton(tr("��(&Y)"),QMessageBox::YesRole);

        box.addButton(tr("��(&N)"),QMessageBox::NoRole);
        QPushButton *cancelBtn = box.addButton(tr("ȡ��"),
                                               QMessageBox::RejectRole);
        box.exec(); // �����Ի������û�ѡ���Ƿ񱣴��޸ģ�����ȡ���رղ���
        if (box.clickedButton() == yesBtn)// ����û�ѡ���ǣ��򷵻ر�������Ľ��
            return save();
        else if (box.clickedButton() == cancelBtn) // ���ѡ��ȡ�����򷵻�false
            return false;
    }
    return true; // ����ĵ�û�и��Ĺ�����ֱ�ӷ���true
}

void MdiChild::contextMenuEvent(QContextMenuEvent *e) // �Ҽ��˵��¼�
{
    QMenu *menu = new QMenu; // �����˵�������������Ӷ���
    QAction *undo = menu->addAction(tr("����(&U)"),this,
                                    SLOT(undo()),QKeySequence::Undo);
    undo->setEnabled(document()->isUndoAvailable());
    QAction *redo = menu->addAction(tr("�ָ�(&R)"),this,
                                    SLOT(redo()),QKeySequence::Redo);
    redo->setEnabled(document()->isRedoAvailable());
    menu->addSeparator();
    QAction *cut = menu->addAction(tr("����(&T)"),this,
                                   SLOT(cut()),QKeySequence::Cut);
    cut->setEnabled(textCursor().hasSelection());
    QAction *copy = menu->addAction(tr("����(&C)"),this,
                                    SLOT(copy()),QKeySequence::Copy);
    copy->setEnabled(textCursor().hasSelection());
    menu->addAction(tr("ճ��(&P)"),this,SLOT(paste()),QKeySequence::Paste);
    QAction *clear = menu->addAction(tr("���"),this,SLOT(clear()));
    clear->setEnabled(!document()->isEmpty());
    menu->addSeparator();
    QAction *select = menu->addAction(tr("ȫѡ"),this,
                                SLOT(selectAll()),QKeySequence::SelectAll);
    select->setEnabled(!document()->isEmpty());
    menu->exec(e->globalPos()); // ��ȡ����λ�ã�Ȼ�������λ����ʾ�˵�
    delete menu; // �����������˵�
}



