#include "myview.h"
#include "mybox.h"
#include <QIcon>

// ��2-2����ӵĴ���
#include <QPropertyAnimation>
#include <QGraphicsBlurEffect>
#include <QTimer>

// ��2-4����ӵĴ���
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <QLabel>
#include <QFileInfo>

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



    /*****************������2-4����ӵĴ��룬���ִ���������ʡ����*************/

    // ���ó�ʼΪ����״̬
    topLine->hide();
    bottomLine->hide();
    leftLine->hide();
    rightLine->hide();
    gameScoreText->hide();
    gameLevelText->hide();

    // ��ɫ����
    QWidget *mask = new QWidget;
    mask->setAutoFillBackground(true);
    mask->setPalette(QPalette(QColor(0, 0, 0, 80)));
    mask->resize(900, 600);
    maskWidget = scene->addWidget(mask);
    maskWidget->setPos(-50, -50);
    // ������ZֵΪ1���������Դ���ZֵΪ0��ͼ��������
    maskWidget->setZValue(1);

    // ѡ�����
    QWidget *option = new QWidget;
    QPushButton *optionCloseButton = new QPushButton(tr("��   ��"), option);
    QPalette palette;
    palette.setColor(QPalette::ButtonText, Qt::black);
    optionCloseButton->setPalette(palette);
    optionCloseButton->move(120, 300);
    connect(optionCloseButton, SIGNAL(clicked()), option, SLOT(hide()));
    option->setAutoFillBackground(true);
    option->setPalette(QPalette(QColor(0, 0, 0, 180)));
    option->resize(300, 400);
    QGraphicsWidget *optionWidget = scene->addWidget(option);
    optionWidget->setPos(250, 50);
    optionWidget->setZValue(3);
    optionWidget->hide();

    // �������
    QWidget *help = new QWidget;
    QPushButton *helpCloseButton = new QPushButton(tr("��   ��"), help);
    helpCloseButton->setPalette(palette);
    helpCloseButton->move(120, 300);
    connect(helpCloseButton, SIGNAL(clicked()), help, SLOT(hide()));
    help->setAutoFillBackground(true);
    help->setPalette(QPalette(QColor(0, 0, 0, 180)));
    help->resize(300, 400);
    QGraphicsWidget *helpWidget = scene->addWidget(help);
    helpWidget->setPos(250, 50);
    helpWidget->setZValue(3);
    helpWidget->hide();

    QLabel *helpLabel = new QLabel(help);
    helpLabel->setText(tr("<h1><font color=white>yafeilinux��Ʒ"
                          "<br>www.yafeilinux.com</font></h1>"));
    helpLabel->setAlignment(Qt::AlignCenter);
    helpLabel->move(30, 150);


    // ��Ϸ��ӭ�ı�
    gameWelcomeText = new QGraphicsTextItem(0, scene);
    gameWelcomeText->setHtml(tr("<font color=white>MyBox������Ϸ</font>"));
    gameWelcomeText->setFont(QFont("Times", 30, QFont::Bold));
    gameWelcomeText->setPos(250, 100);
    gameWelcomeText->setZValue(2);

    // ��Ϸ��ͣ�ı�
    gamePausedText = new QGraphicsTextItem(0, scene);
    gamePausedText->setHtml(tr("<font color=white>��Ϸ��ͣ�У�</font>"));
    gamePausedText->setFont(QFont("Times", 30, QFont::Bold));
    gamePausedText->setPos(300, 100);
    gamePausedText->setZValue(2);
    gamePausedText->hide();

    // ��Ϸ�����ı�
    gameOverText = new QGraphicsTextItem(0, scene);
    gameOverText->setHtml(tr("<font color=white>��Ϸ������</font>"));
    gameOverText->setFont(QFont("Times", 30, QFont::Bold));
    gameOverText->setPos(320, 100);
    gameOverText->setZValue(2);
    gameOverText->hide();


    // ��Ϸ��ʹ�õİ�ť

    QPushButton *button1 = new QPushButton(tr("��    ʼ"));
    QPushButton *button2 = new QPushButton(tr("ѡ    ��"));
    QPushButton *button3 = new QPushButton(tr("��    ��"));
    QPushButton *button4 = new QPushButton(tr("��    ��"));
    QPushButton *button5 = new QPushButton(tr("���¿�ʼ"));
    QPushButton *button6 = new QPushButton(tr("��    ͣ"));
    QPushButton *button7 = new QPushButton(tr("�� �� ��"));
    QPushButton *button8 = new QPushButton(tr("������Ϸ"));
    QPushButton *button9 = new QPushButton(tr("������Ϸ"));


    connect(button1, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(button2, SIGNAL(clicked()), option, SLOT(show()));
    connect(button3, SIGNAL(clicked()), help, SLOT(show()));
    connect(button4, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(button5, SIGNAL(clicked()), this, SLOT(restartGame()));
    connect(button6, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(button7, SIGNAL(clicked()), this, SLOT(finishGame()));
    connect(button8, SIGNAL(clicked()), this, SLOT(returnGame()));
    connect(button9, SIGNAL(clicked()), this, SLOT(finishGame()));

    startButton = scene->addWidget(button1);
    optionButton = scene->addWidget(button2);
    helpButton = scene->addWidget(button3);
    exitButton = scene->addWidget(button4);
    restartButton = scene->addWidget(button5);
    pauseButton = scene->addWidget(button6);
    showMenuButton = scene->addWidget(button7);
    returnButton = scene->addWidget(button8);
    finishButton = scene->addWidget(button9);

    startButton->setPos(370, 200);
    optionButton->setPos(370, 250);
    helpButton->setPos(370, 300);
    exitButton->setPos(370, 350);
    restartButton->setPos(600, 150);
    pauseButton->setPos(600, 200);
    showMenuButton->setPos(600, 250);
    returnButton->setPos(370, 200);
    finishButton->setPos(370, 250);

    startButton->setZValue(2);
    optionButton->setZValue(2);
    helpButton->setZValue(2);
    exitButton->setZValue(2);
    restartButton->setZValue(2);
    returnButton->setZValue(2);
    finishButton->setZValue(2);

    restartButton->hide();
    finishButton->hide();
    pauseButton->hide();
    showMenuButton->hide();
    returnButton->hide();

    /*****************������2-4����ӵĴ��룬���ִ���������ʡ����*************/
}

// ��ʼ��Ϸ
void MyView::startGame()
{
    // ��2-4����ӵĴ���
    gameWelcomeText->hide();
    startButton->hide();
    optionButton->hide();
    helpButton->hide();
    exitButton->hide();
    maskWidget->hide();

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

    // ��2-4����ӵĴ���
    restartButton->show();
    pauseButton->show();
    showMenuButton->show();
    gameScoreText->show();
    gameLevelText->show();
    topLine->show();
    bottomLine->show();
    leftLine->show();
    rightLine->show();
    // ������ǰ�������˵�ʱ������boxGroup
    boxGroup->show();

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

// ��Ϸ����
void MyView::gameOver()
{
    pauseButton->hide();
    showMenuButton->hide();
    maskWidget->show();
    gameOverText->show();
    restartButton->setPos(370, 200);
    finishButton->show();
}

// ���¿�ʼ��Ϸ
void MyView::restartGame()
{
    maskWidget->hide();
    gameOverText->hide();
    finishButton->hide();
    restartButton->setPos(600, 150);

    // ������ʾ������͵�ǰ�����ƶ������е�����С����
    nextBoxGroup->clearBoxGroup(true);
    boxGroup->clearBoxGroup();
    boxGroup->hide();
    foreach (QGraphicsItem *item, scene()->items(199, 49, 202, 402, Qt::ContainsItemShape)) {
        // �ȴӳ������Ƴ�С���飬��Ϊʹ��deleteLater()���ڷ������¼�ѭ���������
        // С����ģ�Ϊ���ڳ����µķ�����ʱ��������ײ��������Ҫ�ȴӳ������Ƴ�С����
        scene()->removeItem(item);
        OneBox *box = (OneBox*) item;
        box->deleteLater();
    }

    initGame();
}

// ������ǰ��Ϸ
void MyView::finishGame()
{
    gameOverText->hide();
    finishButton->hide();
    restartButton->setPos(600, 150);
    restartButton->hide();
    pauseButton->hide();
    showMenuButton->hide();
    gameScoreText->hide();
    gameLevelText->hide();

    topLine->hide();
    bottomLine->hide();
    leftLine->hide();
    rightLine->hide();

    nextBoxGroup->clearBoxGroup(true);
    boxGroup->clearBoxGroup();
    boxGroup->hide();

    foreach (QGraphicsItem *item, scene()->items(199, 49, 202, 402, Qt::ContainsItemShape)) {
        OneBox *box = (OneBox*) item;
        box->deleteLater();
    }

    // �������ڽ�����Ϸʱ���¡����˵�����ť
    maskWidget->show();
    gameWelcomeText->show();
    startButton->show();
    optionButton->show();
    helpButton->show();
    exitButton->show();
    scene()->setBackgroundBrush(QPixmap(":/images/background.png"));
}

// ��ͣ��Ϸ
void MyView::pauseGame()
{
    boxGroup->stopTimer();
    restartButton->hide();
    pauseButton->hide();
    showMenuButton->hide();
    maskWidget->show();
    gamePausedText->show();
    returnButton->show();
}


// ������Ϸ��������ͣ״̬ʱ
void MyView::returnGame()
{
    returnButton->hide();
    gamePausedText->hide();
    maskWidget->hide();
    restartButton->show();
    pauseButton->show();
    showMenuButton->show();
    boxGroup->startTimer(gameSpeed);
}

// ������ڽ�����Ϸ�������̰���ʱ���Ƿ������ý���
void MyView::keyPressEvent(QKeyEvent *event)
{
    if (pauseButton->isVisible())
        boxGroup->setFocus();
    else
        boxGroup->clearFocus();
    QGraphicsView::keyPressEvent(event);
}






