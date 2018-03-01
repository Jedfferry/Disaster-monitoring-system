#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
class BoxGroup;
// ��2-5����ӵĴ���
#include <phonon>

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = 0);

// ��2-4����ӵĴ���
protected:
    void keyPressEvent(QKeyEvent *event);

public slots:
    void startGame();
    void clearFullRows();
    void moveBox();
    void gameOver();

    // ��2-4����ӵĴ���
    void restartGame();
    void finishGame();
    void pauseGame();
    void returnGame();

    // ��2-5����ӵĴ���
    void aboutToFinish();

private:
    BoxGroup *boxGroup;
    BoxGroup *nextBoxGroup;
    QGraphicsLineItem *topLine;
    QGraphicsLineItem *bottomLine;
    QGraphicsLineItem *leftLine;
    QGraphicsLineItem *rightLine;
    qreal gameSpeed;
    QList<int> rows;
    void initView();
    void initGame();
    void updateScore(const int fullRowNum = 0);

    // ��2-3����ӵĴ���
    QGraphicsTextItem *gameScoreText;
    QGraphicsTextItem *gameLevelText;

    // ��2-4����ӵĴ���

    // �������
    QGraphicsWidget *maskWidget;

    // ���ְ�ť
    QGraphicsWidget *startButton;
    QGraphicsWidget *finishButton;
    QGraphicsWidget *restartButton;
    QGraphicsWidget *pauseButton;
    QGraphicsWidget *optionButton;
    QGraphicsWidget *returnButton;
    QGraphicsWidget *helpButton;
    QGraphicsWidget *exitButton;
    QGraphicsWidget *showMenuButton;

    // �����ı�
    QGraphicsTextItem *gameWelcomeText;
    QGraphicsTextItem *gamePausedText;
    QGraphicsTextItem *gameOverText;

    // ��2-5����ӵĴ���
    Phonon::MediaObject *backgroundMusic;
    Phonon::MediaObject *clearRowSound;
};

#endif // MYVIEW_H
