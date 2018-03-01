#include "mylrc.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QMenu>

MyLrc::MyLrc(QWidget *parent) :
    QLabel(parent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    // ���ñ���͸��
    setAttribute(Qt::WA_TranslucentBackground);
    setText(tr("MyPlayer���ֲ����� --- yafeilinux��Ʒ"));
    // �̶�������С
    setMaximumSize(800, 60);
    setMinimumSize(800, 60);

    // ��ʵ����Խ������
    linearGradient.setStart(0, 10);
    linearGradient.setFinalStop(0, 40);
    linearGradient.setColorAt(0.1, QColor(14, 179, 255));
    linearGradient.setColorAt(0.5, QColor(114, 232, 255));
    linearGradient.setColorAt(0.9, QColor(14, 179, 255));
    // ���ֵ����Խ������
    maskLinearGradient.setStart(0, 10);
    maskLinearGradient.setFinalStop(0, 40);
    maskLinearGradient.setColorAt(0.1, QColor(222, 54, 4));
    maskLinearGradient.setColorAt(0.5, QColor(255, 72, 16));
    maskLinearGradient.setColorAt(0.9, QColor(222, 54, 4));
    // ��������
    font.setFamily("Times New Roman");
    font.setBold(true);
    font.setPointSize(30);
    // ���ö�ʱ��
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    lrcMaskWidth = 0;
    lrcMaskWidthInterval = 0;
}

void MyLrc::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setFont(font);
    // �Ȼ��Ƶײ����֣���Ϊ��Ӱ��������ʹ��ʾЧ�������������Ҹ����ʸ�
    painter.setPen(QColor(0, 0, 0, 200));
    painter.drawText(1, 1, 800, 60, Qt::AlignLeft, text());
    // ����������ƽ�������
    painter.setPen(QPen(linearGradient, 0));
    painter.drawText(0, 0, 800, 60, Qt::AlignLeft, text());

    // ���ø������
    painter.setPen(QPen(maskLinearGradient, 0));
    painter.drawText(0, 0, lrcMaskWidth, 60, Qt::AlignLeft, text());
}

// �������֣���Ҫָ����ǰ��ʿ�ʼ�����֮���ʱ����
void MyLrc::startLrcMask(qint64 intervalTime)
{
    // ��������ÿ��30�������һ�����ֵĿ�ȣ���Ϊ�������̫Ƶ��
    // ������CPUռ���ʣ������ʱ����̫���򶯻�Ч���Ͳ�������
    qreal count = intervalTime / 30;
    // ��ȡ����ÿ����Ҫ���ӵĿ�ȣ������800�ǲ����Ĺ̶����
    lrcMaskWidthInterval = 800 / count;
    lrcMaskWidth = 0;
    timer->start(30);
}

// ֹͣ����
void MyLrc::stopLrcMask()
{
    timer->stop();
    lrcMaskWidth = 0;
    update();
}

// ��������¼�������ʵ���˲������϶�
void MyLrc::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        offset = event->globalPos() - frameGeometry().topLeft();
}
void MyLrc::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
     setCursor(Qt::PointingHandCursor);
     move(event->globalPos() - offset);
    }
}

// ʵ���Ҽ��˵������ز���
void MyLrc::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(tr("����"), this, SLOT(hide()));
    menu.exec(event->globalPos());
}

// ��ʱ�����ʱ�������ֵĿ�ȣ���������ʾ
void MyLrc::timeout()
{
    lrcMaskWidth += lrcMaskWidthInterval;
    update();
}
