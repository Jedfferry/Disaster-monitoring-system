#ifndef MYLRC_H
#define MYLRC_H

#include <QLabel>
class QTimer;

class MyLrc : public QLabel
{
    Q_OBJECT
public:
    explicit MyLrc(QWidget *parent = 0);
    void startLrcMask(qint64 intervalTime);
    void stopLrcMask();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void timeout();

private:
    QLinearGradient linearGradient;
    QLinearGradient maskLinearGradient;
    QFont font;
    QTimer *timer;
    qreal lrcMaskWidth;
    // ÿ�θ���������ӵĿ��
    qreal lrcMaskWidthInterval;
    QPoint offset;
};

#endif // MYLRC_H
