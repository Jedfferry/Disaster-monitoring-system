#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <Phonon>
class QLabel;
class MyPlaylist;
// ��3-4����ӵĴ���
class MyLrc;

namespace Ui {
    class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void updateTime(qint64 time);
    void setPaused();
    void skipBackward();
    void skipForward();
    void openFile();
    void setPlaylistShown();
    void setLrcShown();

    // ��3-2����ӵĴ���
    void stateChanged(Phonon::State newState, Phonon::State oldState);

    // ��3-3����ӵĴ���
    void sourceChanged(const Phonon::MediaSource &source);
    void aboutToFinish();
    void metaStateChanged(Phonon::State newState, Phonon::State oldState);
    void tableClicked(int row);
    void clearSources();

private:
    Ui::MyWidget *ui;
    void initPlayer();
    Phonon::MediaObject *mediaObject;
    QAction *playAction;
    QAction *stopAction;
    QAction *skipBackwardAction;
    QAction *skipForwardAction;
    QLabel *topLabel;
    QLabel *timeLabel;

    // ��3-3����ӵĴ���
    MyPlaylist *playlist;
    Phonon::MediaObject *metaInformationResolver;
    QList<Phonon::MediaSource> sources;
    void changeActionState();

    // ��3-4����ӵĴ���
    MyLrc *lrc;
    QMap<qint64, QString> lrcMap;
    void resolveLrc(const QString &sourceFileName);
};

#endif // MYWIDGET_H
