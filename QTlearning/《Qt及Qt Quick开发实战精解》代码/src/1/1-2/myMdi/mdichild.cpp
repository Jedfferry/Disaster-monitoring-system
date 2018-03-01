#include "mdichild.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include <QApplication>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPushButton>

MdiChild::MdiChild(QWidget *parent) :
    QTextEdit(parent)
{
    // �����������Ӵ��ڹر�ʱ���������Ķ���
    setAttribute(Qt::WA_DeleteOnClose);

    // ��ʼisUntitledΪtrue
    isUntitled = true;
}

// �½��ļ�����
void MdiChild::newFile()
{
    // ���ô��ڱ�ţ���Ϊ���һֱ�����棬������Ҫʹ�þ�̬����
    static int sequenceNumber = 1;

    // �½����ĵ�û�б������
    isUntitled = true;

    // ����ǰ�ļ�����Ϊδ�����ĵ��ӱ�ţ������ʹ���ټ�1
    curFile = tr("δ�����ĵ�%1.txt").arg(sequenceNumber++);

    // ���ô��ڱ��⣬ʹ��[*]�������ĵ������ĺ����ļ����ƺ���ʾ��*����
    setWindowTitle(curFile + "[*]" + tr(" - ���ĵ��༭��"));

    // ���ĵ�������ʱ����contentsChanged()�źţ�
    // ִ�����ǵ�documentWasModified()�ۺ���
    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

}

// �ĵ�������ʱ��������ʾ����״̬��־
void MdiChild::documentWasModified()
{
    // �����ĵ���isModified()�����ķ���ֵ���ж����Ǳ༭�������Ƿ񱻸�����
    // ����������ˣ���Ҫ��������[*]�ŵĵط���ʾ��*���ţ��������ǻ��ڴ��ڱ�������ʾ
    setWindowModified(document()->isModified());
}

// �����ļ�
bool MdiChild::loadFile(const QString &fileName)
{
    // �½�QFile����
    QFile file(fileName);

    // ֻ����ʽ���ļ�����������ʾ��������false
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("���ĵ��༭��"),
                             tr("�޷���ȡ�ļ� %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }

    // �½��ı�������
    QTextStream in(&file);

    // �������״̬Ϊ�ȴ�״̬
    QApplication::setOverrideCursor(Qt::WaitCursor);

    // ��ȡ�ļ���ȫ���ı����ݣ�����ӵ��༭����
    setPlainText(in.readAll());

    // �ָ����״̬
    QApplication::restoreOverrideCursor();

    // ���õ�ǰ�ļ�
    setCurrentFile(fileName);

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    return true;
}

// ���õ�ǰ�ļ�
void MdiChild::setCurrentFile(const QString &fileName)
{
    // canonicalFilePath()���Գ�ȥ·���еķ������ӣ���.���͡�..���ȷ���
    curFile = QFileInfo(fileName).canonicalFilePath();

    // �ļ��Ѿ����������
    isUntitled = false;

    // �ĵ�û�б����Ĺ�
    document()->setModified(false);

    // ���ڲ���ʾ�����ı�־
    setWindowModified(false);

    // ���ô��ڱ��⣬userFriendlyCurrentFile()�����ļ���
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

// ��ȡ�ļ���
QString MdiChild::userFriendlyCurrentFile()
{
    return QFileInfo(curFile).fileName(); // ���ļ�·������ȡ�ļ���
}

// �������
bool MdiChild::save()
{
    if (isUntitled) { // ����ļ�δ�����������ִ�����Ϊ����
        return saveAs();
    } else {
        return saveFile(curFile); //����ֱ�ӱ����ļ�
    }
}

// ���Ϊ����
bool MdiChild::saveAs()
{
    // ��ȡ�ļ�·�������Ϊ�գ��򷵻�false
    QString fileName = QFileDialog::getSaveFileName(this, tr("���Ϊ"),curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName); // ���򱣴��ļ�
}

// �����ļ�
bool MdiChild::saveFile(const QString &fileName)
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

// �Ƿ���Ҫ����
bool MdiChild::maybeSave()
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
        if (box.clickedButton() == yesBtn)  // ����û�ѡ���ǣ��򷵻ر�������Ľ��
            return save();
        else if (box.clickedButton() == cancelBtn) // ���ѡ��ȡ�����򷵻�false
            return false;
    }
    return true; // ����ĵ�û�и��Ĺ�����ֱ�ӷ���true
}



