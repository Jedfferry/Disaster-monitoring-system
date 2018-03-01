#include "myplaylist.h"
#include <QContextMenuEvent>
#include <QMenu>

MyPlaylist::MyPlaylist(QWidget *parent) :
    QTableWidget(parent)
{
    setWindowTitle(tr("�����б�"));
    // ���ô��ڱ�־����������һ��������������һ��ֻ���йرհ�ť�ı�����
    setWindowFlags(Qt::Window  | Qt::WindowTitleHint);
    // ���ó�ʼ��С�����������������
    resize(320, 400);
    setMaximumWidth(320);
    setMinimumWidth(320);
    // ����������Ŀ
    setRowCount(0);
    setColumnCount(3);
    // ���ñ�ͷ��ǩ
    QStringList list;
    list << tr("����") << tr("������") << tr("����");
    setHorizontalHeaderLabels(list);
    // ����ֻ��ѡ����
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    // ���ò���ʾ����
    setShowGrid(false);
}

// �����Ĳ˵��¼������������������Ҽ�ʱ����һ���˵�
void MyPlaylist::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(tr("����б�"), this, SLOT(clearPlaylist()));
    menu.exec(event->globalPos());
}

// ��ղ����б�
void MyPlaylist::clearPlaylist()
{
    while (rowCount())
        removeRow(0);
    // ���䲥���б�������ź�
    emit playlistClean();
}

// �ر��¼����������������������ʾ״̬����ʹ������
void MyPlaylist::closeEvent(QCloseEvent *event)
{
    if (isVisible()) {
        hide();
        event->ignore();
    }
}

