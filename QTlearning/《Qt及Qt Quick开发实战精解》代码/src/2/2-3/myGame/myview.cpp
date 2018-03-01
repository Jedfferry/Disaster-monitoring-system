#include "myview.h"
#include "mybox.h"
#include <QIcon>

// ��2-2����ӵĴ���
#include <QPropertyAnimation>
#include <QGraphicsBlurEffect>
#include <QTimer>

// ��Ϸ�ĳ�ʼ�ٶ�
static const qreal INITSPEED = 500;

MyView::MyView(QWidget *parent) :
    QGraphicsView(parent)
{
    initView();
}

// ��ʼ����Ϸ����
void MyView::initView()
{
    // ʹ�ÿ������Ⱦ
    setRenderHint(QPainter::Antialiasing);
    // ���û��汳�����������Լӿ���Ⱦ�ٶ�
    setCacheMode(CacheBackground);
    setWindowTitle(tr("MyBox������Ϸ"));
    setWindowIcon(QIcon(":/images/icon.png"));
    setMinimumSize(810, 510);
    setMaximumSize(810, 510);

    // ���ó���
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(5, 5, 800, 500);
    scene->setBackgroundBrush(QPixmap(":/images/background.png"));
    setScene(scene);

    // ������ƶ�����������߽���
    topLine = scene->addLine(197, 47, 403, 47);
    bottomLine = scene->addLine(197,453,403,453);
    leftLine = scene->addLine(197,47,197,453);
    rightLine = scene->addLine(403,47,403,453);


    // ��ǰ���������ʾ������
    boxGroup = new BoxGroup;
    connect(boxGroup, SIGNAL(needNewBox()), this, SLOT(clearFullRows()));
    connect(boxGroup, SIGNAL(gameFinished()), this, SLOT(gameOver()));
    scene->addItem(boxGroup);
    nextBoxGroup = new BoxGroup;
    scene->addItem(nextBoxGroup);


    // ��2-3����ӵĴ���

    // �÷��ı�
    gameScoreText = new QGraphicsTextItem(0, scene);
    gameScoreText->setFont(QFont("Times", 20, QFont::Bold));
    gameScoreText->setPos(650, 350);

    // �����ı�
    gameLevelText = new QGraphicsTextItem(0, scene);
    gameLevelText->setFont(QFont("Times", 30, QFont::Bold));
    gameLevelText->setPos(20, 150);


    startGame();

}

// ��ʼ��Ϸ
void MyView::startGame()
{
    initGame();
}

// ��ʼ����Ϸ
void MyView::initGame()
{
    boxGroup->createBox(QPointF(300, 70));
    boxGroup->setFocus();
    boxGroup->startTimer(INITSPEED);
    gameSpeed = INITSPEED;
    nextBoxGroup->createBox(QPointF(500, 70));

    // ��2-3����ӵĴ���
    scene()->setBackgroundBrush(QPixmap(":/images/background01.png"));
    gameScoreText->setHtml(tr("<font color=red>0</font>"));
    gameLevelText->setHtml(tr("<font color=white>��<br>һ<br>Ļ</font>"));
}

// �������
void MyView::clearFullRows()
{
    // ��ȡ��һ�з���ϴ�ľ����а���������С����
    for (int y = 429; y > 50; y -= 20) {
        QList<QGraphicsItem *> list = scene()->items(199, y, 202, 22, Qt::ContainsItemShape);
        // �����������
        if (list.count() == 10) {
            foreach (QGraphicsItem *item, list) {
                OneBox *box = (OneBox*) item;

                // ��2-2����ӵĴ���
                QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
                box->setGraphicsEffect(blurEffect);
                QPropertyAnimation *animation = new QPropertyAnimation(box, "scale");
                animation->setEasingCurve(QEasingCurve::OutBounce);
                animation->setDuration(250);
                animation->setStartValue(4);
                animation->setEndValue(0.25);
                animation->start(QAbstractAnimation::DeleteWhenStopped);
                connect(animation, SIGNAL(finished()), box, SLOT(deleteLater()));
            }
            // �������е�λ��
            rows << y;
        }
    }
    // ��������У�������������ĸ����ٳ����µķ�����
    // ���û�����У���ֱ�ӳ����µķ�����
    if(rows.count() > 0) {

        // ��2-2����ӵĴ���
        QTimer::singleShot(400, this, SLOT(moveBox()));

    } else {
        boxGroup->createBox(QPointF(300, 70), nextBoxGroup->getCurrentShape());
        // ��ղ�������ʾ�������е�����С����
        nextBoxGroup->clearBoxGroup(true);
        nextBoxGroup->createBox(QPointF(500, 70));
    }
}

// �����������������С����
void MyView::moveBox()
{
    // ��λ����ϵ����п�ʼ
    for (int i = rows.count(); i > 0;  --i) {
        int row = rows.at(i - 1);
        foreach (QGraphicsItem *item, scene()->items(199, 49, 202, row - 47, Qt::ContainsItemShape)) {
            item->moveBy(0, 20);
        }
    }
    // ���·���
    updateScore(rows.count());
    // �������б����Ϊ0
    rows.clear();
    // �������������Ժ��ٳ����µķ�����
    boxGroup->createBox(QPointF(300, 70), nextBoxGroup->getCurrentShape());
    nextBoxGroup->clearBoxGroup(true);
    nextBoxGroup->createBox(QPointF(500, 70));
}

// ���·���
void MyView::updateScore(const int fullRowNum)
{
    int score = fullRowNum * 100;
    int currentScore = gameScoreText->toPlainText().toInt();
    currentScore += score;
    // ��ʾ��ǰ����
    gameScoreText->setHtml(tr("<font color=red>%1</font>").arg(currentScore));
    // �жϼ���
    if (currentScore < 500) {
        // ��һ��,ʲô��������
    } else if (currentScore < 1000) { // �ڶ���
         gameLevelText->setHtml(tr("<font color=white>��<br>��<br>Ļ</font>"));
         scene()->setBackgroundBrush(QPixmap(":/images/background02.png"));
         gameSpeed = 300;
         boxGroup->stopTimer();
         boxGroup->startTimer(gameSpeed);
    } else {
        // �����һ�����������
    }
}

void MyView::gameOver()
{
    // ��Ϸ����
}






