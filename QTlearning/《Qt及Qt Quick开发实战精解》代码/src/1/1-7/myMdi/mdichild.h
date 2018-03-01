#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>

class MdiChild : public QTextEdit
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);
    void newFile(); // �½�����
    bool loadFile(const QString &fileName); // �����ļ�
    bool save();  // �������
    bool saveAs();  // ���Ϊ����
    bool saveFile(const QString &fileName); // �����ļ�
    QString userFriendlyCurrentFile(); // ��ȡ�ļ���
    QString currentFile(){return curFile;} // ���ص�ǰ�ļ�·��
protected:
    void closeEvent(QCloseEvent *event); // �ر��¼�
    void contextMenuEvent(QContextMenuEvent *e); // �Ҽ��˵��¼�
private slots:
    void documentWasModified();  // �ĵ�������ʱ����ʾ����״̬��־
private:
    bool maybeSave();  // �Ƿ���Ҫ����
    void setCurrentFile(const QString &fileName); // ���õ�ǰ�ļ�
    QString curFile;  // ���浱ǰ�ļ�·��
    bool isUntitled;  // ��Ϊ��ǰ�ļ��Ƿ񱻱��浽Ӳ���ϵı�־
};

#endif // MDICHILD_H
