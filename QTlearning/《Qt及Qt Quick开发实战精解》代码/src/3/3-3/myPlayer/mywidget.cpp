#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QToolBar>
#include <QVBoxLayout>
#include <QTime>
#include <QMessageBox>
#include <QFileInfo>
// ��3-3����ӵĴ���
#include "myplaylist.h"
#include <QFileDialog>
#include <QDesktopServices>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    initPlayer();
}

MyWidget::~MyWidget()
{
    delete ui;
}

// ��ʼ��������
void MyWidget::initPlayer()
{
    // ������������⡢ͼ��ʹ�С
    setWindowTitle(tr("MyPlayer���ֲ�����"));
    setWindowIcon(QIcon(":/images/icon.png"));
    setMinimumSize(320, 160);
    setMaximumSize(320, 160);

    // ����ý��ͼ
    mediaObject = new Phonon::MediaObject(this);
    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(mediaObject, audioOutput);

    // ����ý������tick()�ź������²���ʱ�����ʾ
    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(updateTime(qint64)));

    // ����������ǩ��������ʾһЩ��Ϣ
    topLabel = new QLabel(tr("<a href = \" http://www.yafeilinux.com \"> www.yafeilinux.com </a>"));
    topLabel->setTextFormat(Qt::RichText);
    topLabel->setOpenExternalLinks(true);
    topLabel->setAlignment(Qt::AlignCenter);

    // �������Ʋ��Ž��ȵĻ���
    Phonon::SeekSlider *seekSlider = new Phonon::SeekSlider(mediaObject, this);

    // �������������б�ͼ�ꡢ��ʾʱ���ǩ��������ͼ��Ĺ�����
    QToolBar *widgetBar = new QToolBar(this);
    // ��ʾ����ʱ��ı�ǩ
    timeLabel = new QLabel(tr("00:00 / 00:00"), this);
    timeLabel->setToolTip(tr("��ǰʱ�� / ��ʱ��"));
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    // ����ͼ�꣬���ڿ����Ƿ���ʾ�����б�
    QAction *PLAction = new QAction(tr("PL"), this);
    PLAction->setShortcut(QKeySequence("F4"));
    PLAction->setToolTip(tr("�����б�(F4)"));
    connect(PLAction, SIGNAL(triggered()), this, SLOT(setPlaylistShown()));
    // ����ͼ�꣬���ڿ����Ƿ���ʾ������
    QAction *LRCAction = new QAction(tr("LRC"), this);
    LRCAction->setShortcut(QKeySequence("F2"));
    LRCAction->setToolTip(tr("������(F2)"));
    connect(LRCAction, SIGNAL(triggered()), this, SLOT(setLrcShown()));
    // ��ӵ�������
    widgetBar->addAction(PLAction);
    widgetBar->addSeparator();
    widgetBar->addWidget(timeLabel);
    widgetBar->addSeparator();
    widgetBar->addAction(LRCAction);

    // �������ſ��ƶ���������
    QToolBar *toolBar = new QToolBar(this);
    // ���Ŷ���
    playAction = new QAction(this);
    playAction->setIcon(QIcon(":/images/play.png"));
    playAction->setText(tr("����(F5)"));
    playAction->setShortcut(QKeySequence(tr("F5")));
    connect(playAction, SIGNAL(triggered()), this, SLOT(setPaused()));
    // ֹͣ����
    stopAction = new QAction(this);
    stopAction->setIcon(QIcon(":/images/stop.png"));
    stopAction->setText(tr("ֹͣ(F6)"));
    stopAction->setShortcut(QKeySequence(tr("F6")));
    connect(stopAction, SIGNAL(triggered()), mediaObject, SLOT(stop()));
    // ��ת����һ�׶���
    skipBackwardAction = new QAction(this);
    skipBackwardAction->setIcon(QIcon(":/images/skipBackward.png"));
    skipBackwardAction->setText(tr("��һ��(Ctrl+Left)"));
    skipBackwardAction->setShortcut(QKeySequence(tr("Ctrl+Left")));
    connect(skipBackwardAction, SIGNAL(triggered()), this, SLOT(skipBackward()));
    // ��ת����һ�׶���
    skipForwardAction = new QAction(this);
    skipForwardAction->setIcon(QIcon(":/images/skipForward.png"));
    skipForwardAction->setText(tr("��һ��(Ctrl+Right)"));
    skipForwardAction->setShortcut(QKeySequence(tr("Ctrl+Right")));
    connect(skipForwardAction, SIGNAL(triggered()), this, SLOT(skipForward()));
    // ���ļ�����
    QAction *openAction = new QAction(this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setText(tr("�����ļ�(Ctrl+O)"));
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    // �������Ʋ���
    Phonon::VolumeSlider *volumeSlider = new Phonon::VolumeSlider(audioOutput, this);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    // ��ӵ�������
    toolBar->addAction(playAction);
    toolBar->addSeparator();
    toolBar->addAction(stopAction);
    toolBar->addSeparator();
    toolBar->addAction(skipBackwardAction);
    toolBar->addSeparator();
    toolBar->addAction(skipForwardAction);
    toolBar->addSeparator();
    toolBar->addWidget(volumeSlider);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    // ���������沼�ֹ�����
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(topLabel);
    mainLayout->addWidget(seekSlider);
    mainLayout->addWidget(widgetBar);
    mainLayout->addWidget(toolBar);
    setLayout(mainLayout);

    // ��3-2����ӵĴ���
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State, Phonon::State)),
            this, SLOT(stateChanged(Phonon::State, Phonon::State)));

    // ��������3-3����ӵĴ���

    // ���������б�
    playlist = new MyPlaylist(this);
    connect(playlist, SIGNAL(cellClicked(int, int)), this, SLOT(tableClicked(int)));
    connect(playlist, SIGNAL(playlistClean()), this, SLOT(clearSources()));

    // ������������ý�����Ϣ��Ԫ��Ϣ������
    metaInformationResolver = new Phonon::MediaObject(this);
    // ��Ҫ��AudioOutput���Ӻ����ʹ��metaInformationResolver����ȡ��������ʱ��
    Phonon::AudioOutput *metaInformationAudioOutput =
            new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(metaInformationResolver, metaInformationAudioOutput);
    connect(metaInformationResolver, SIGNAL(stateChanged(Phonon::State, Phonon::State)),
            this, SLOT(metaStateChanged(Phonon::State, Phonon::State)));

    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(sourceChanged(Phonon::MediaSource)));
    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));

    // ��ʼ������ͼ���״̬
    playAction->setEnabled(false);
    stopAction->setEnabled(false);
    skipBackwardAction->setEnabled(false);
    skipForwardAction->setEnabled(false);
    topLabel->setFocus();

}

// ����timeLabel��ǩ��ʾ�Ĳ���ʱ��
void MyWidget::updateTime(qint64 time)
{
    qint64 totalTimeValue = mediaObject->totalTime();
    QTime totalTime(0, (totalTimeValue / 60000) % 60, (totalTimeValue / 1000) % 60);
    QTime currentTime(0, (time / 60000) % 60, (time / 1000) % 60);
    QString str = currentTime.toString("mm:ss") + " / " + totalTime.toString("mm:ss");
    timeLabel->setText(str);
}

// ���Ż�����ͣ
void MyWidget::setPaused()
{
    // �����ǰ���ڲ���״̬����ô��ͣ����;���򣬿�ʼ����
    if (mediaObject->state() == Phonon::PlayingState)
        mediaObject->pause();
    else
        mediaObject->play();
}

// ������һ�ף���skipBackwardAction�����Ĵ����źŹ���
void MyWidget::skipBackward()
{
    int index = sources.indexOf(mediaObject->currentSource());
    mediaObject->setCurrentSource(sources.at(index - 1));
    mediaObject->play();
}

// ������һ�ף���skipForwardAction�����Ĵ����źŹ���
void MyWidget::skipForward()
{
    int index = sources.indexOf(mediaObject->currentSource());
    mediaObject->setCurrentSource(sources.at(index + 1));
    mediaObject->play();
}

// ���ļ�����openAction�����Ĵ����źŹ���
void MyWidget::openFile()
{
    // ��ϵͳ����Ŀ¼�򿪶�������ļ�
    QStringList list = QFileDialog::getOpenFileNames(this, tr("�������ļ�"),
                      QDesktopServices::storageLocation(QDesktopServices::MusicLocation));
    if (list.isEmpty())
        return;
    // ��ȡ��ǰý��Դ�б�Ĵ�С
    int index = sources.size();
    // ���򿪵������ļ���ӵ�ý��Դ�б��
    foreach (QString string, list) {
        Phonon::MediaSource source(string);
        sources.append(source);
    }
    // ���ý��Դ�б�Ϊ�գ����¼���ĵ�һ��ý��Դ��Ϊ��ǰý��Դ��
    // ��ʱ�ᷢ��stateChanged()�źţ��Ӷ�����metaStateChanged()��������ý��Դ�Ľ���
    if (!sources.isEmpty())
        metaInformationResolver->setCurrentSource(sources.at(index));
}

// ��ʾ�������ز����б���PLAction�����Ĵ����źŹ���
void MyWidget::setPlaylistShown()
{
    if (playlist->isHidden()) {
        playlist->move(frameGeometry().bottomLeft());
        playlist->show();
    } else {
        playlist->hide();
    }
}

// ��ʾ�������������ʣ���LRCAction�����Ĵ����źŹ���
void MyWidget::setLrcShown()
{   
}

// ý�����״̬�����˸ı�
void MyWidget::stateChanged(Phonon::State newState, Phonon::State oldState)
{
    switch (newState)
    {
    case Phonon::ErrorState :
        if(mediaObject->errorType() == Phonon::FatalError) {
            QMessageBox::warning(this, tr("��������"),
                                 mediaObject->errorString());
        } else {
            QMessageBox::warning(this, tr("����"), mediaObject->errorString());
        }
        break;
    case Phonon::PlayingState :
        stopAction->setEnabled(true);
        playAction->setIcon(QIcon(":/images/pause.png"));
        playAction->setText(tr("��ͣ(F5)"));
        topLabel->setText(QFileInfo(mediaObject->
                                    currentSource().fileName()).baseName());
        break;
    case Phonon::StoppedState :
        stopAction->setEnabled(false);
        playAction->setIcon(QIcon(":/images/play.png"));
        playAction->setText(tr("����(F5)"));
        topLabel->setText(tr("<a href = \" http://www.yafeilinux.com \">"
                             "www.yafeilinux.com</a>"));
        timeLabel->setText(tr("00:00 / 00:00"));
        break;
    case Phonon::PausedState :
        stopAction->setEnabled(true);
        playAction->setIcon(QIcon(":/images/play.png"));
        playAction->setText(tr("����(F5)"));
        topLabel->setText(QFileInfo(mediaObject->
                                    currentSource().fileName()).baseName() + tr(" ����ͣ��"));
        break;
    case Phonon::BufferingState :
        break;
    default :
        ;
    }
}

// ����ý���ļ���Ԫ��Ϣ
void MyWidget::metaStateChanged(Phonon::State newState, Phonon::State oldState)
{
    // ����״̬�����ý��Դ�б��г�ȥ����ӵ�ý��Դ
    if(newState == Phonon::ErrorState) {
        QMessageBox::warning(this, tr("���ļ�ʱ����"), metaInformationResolver->errorString());
        while (!sources.isEmpty() &&
               !(sources.takeLast() == metaInformationResolver->currentSource()))
        {};
        return;
    }

    // ����Ȳ�����ֹͣ״̬Ҳ��������ͣ״̬����ֱ�ӷ���
    if(newState != Phonon::StoppedState && newState != Phonon::PausedState)
        return;

    // ���ý��Դ���ʹ�����ֱ�ӷ���
    if(metaInformationResolver->currentSource().type() == Phonon::MediaSource::Invalid)
        return;

    // ��ȡý����Ϣ
    QMap<QString, QString> metaData = metaInformationResolver->metaData();
    // ��ȡ���⣬���Ϊ�գ���ʹ���ļ���
    QString title = metaData.value("TITLE");
    if (title == "") {
        QString str = metaInformationResolver->currentSource().fileName();
        title = QFileInfo(str).baseName();
    }
    QTableWidgetItem *titleItem = new QTableWidgetItem(title);
    // ����������ɱ༭
    titleItem->setFlags(titleItem->flags() ^ Qt::ItemIsEditable);
    // ��ȡ��������Ϣ
    QTableWidgetItem *artistItem = new QTableWidgetItem(metaData.value("ARTIST"));
    artistItem->setFlags(artistItem->flags() ^ Qt::ItemIsEditable);
    // ��ȡ��ʱ����Ϣ
    qint64 totalTime = metaInformationResolver->totalTime();
    QTime time(0, (totalTime / 60000) % 60, (totalTime / 1000) % 60);
    QTableWidgetItem *timeItem = new QTableWidgetItem(time.toString("mm:ss"));

    // ���뵽�����б�
    int currentRow = playlist->rowCount();
    playlist->insertRow(currentRow);
    playlist->setItem(currentRow, 0, titleItem);
    playlist->setItem(currentRow, 1, artistItem);
    playlist->setItem(currentRow, 2, timeItem);

    // �����ӵ�ý��Դ��û�н����꣬��ô����������һ��ý��Դ
    int index = sources.indexOf(metaInformationResolver->currentSource()) + 1;
    if (sources.size() > index) {
        metaInformationResolver->setCurrentSource(sources.at(index));
    } else { // �������ý��Դ���Ѿ��������
        // ��������б���û��ѡ�е���
        if (playlist->selectedItems().isEmpty()) {
            // �������û�в��Ÿ��������õ�һ��ý��ԴΪý�����ĵ�ǰý��Դ
            //����Ϊ�������ڲ��Ÿ���ʱ����˲����б�Ȼ����������µ��б�
            if (mediaObject->state() != Phonon::PlayingState &&
                    mediaObject->state() != Phonon::PausedState) {
                mediaObject->setCurrentSource(sources.at(0));
            } else {
                //������ڲ��Ÿ�������ѡ�в����б�ĵ�һ����Ŀ,������ͼ��״̬
                playlist->selectRow(0);
                changeActionState();
            }
        } else {
            // ��������б�����ѡ�е��У���ôֱ�Ӹ���ͼ��״̬
            changeActionState();
        }
    }
}

// ����ý��Դ�б����ݺ͵�ǰý��Դ��λ�����ı�������ͼ���״̬
void MyWidget::changeActionState()
{
    // ���ý��Դ�б�Ϊ��
    if (sources.count() == 0) {
        // ���û���ڲ��Ÿ������򲥷ź�ֹͣ��ť��������
        //����Ϊ���ܸ������ڲ���ʱ����˲����б�
        if (mediaObject->state() != Phonon::PlayingState &&
                mediaObject->state() != Phonon::PausedState) {
            playAction->setEnabled(false);
            stopAction->setEnabled(false);
        }
        skipBackwardAction->setEnabled(false);
        skipForwardAction->setEnabled(false);
    } else { // ���ý��Դ�б�Ϊ��
        playAction->setEnabled(true);
        stopAction->setEnabled(true);
        // ���ý��Դ�б�ֻ��һ��
        if (sources.count() == 1) {
            skipBackwardAction->setEnabled(false);
            skipForwardAction->setEnabled(false);
        } else { // ���ý��Դ�б��ж���
            skipBackwardAction->setEnabled(true);
            skipForwardAction->setEnabled(true);
            int index = playlist->currentRow();
            // ��������б�ǰѡ�е���Ϊ��һ��
            if (index == 0)
                skipBackwardAction->setEnabled(false);
            // ��������б�ǰѡ�е���Ϊ���һ��
            if (index + 1 == sources.count())
                skipForwardAction->setEnabled(false);
        }
    }
}

// ��ý��Դ�ı�ʱ���ڲ����б���ѡ����Ӧ���в�����ͼ���״̬
void MyWidget::sourceChanged(const Phonon::MediaSource &source)
{
    int index = sources.indexOf(source);
    playlist->selectRow(index);
    changeActionState();
}

// ��ǰý��Դ���Ž�Ҫ����ʱ��������б��е�ǰý��Դ�ĺ��滹��ý��Դ��
// ��ô������ӵ����Ŷ����У�����ֹͣ����
void MyWidget::aboutToFinish()
{
    int index = sources.indexOf(mediaObject->currentSource()) + 1;
    if (sources.size() > index) {
        mediaObject->enqueue(sources.at(index));
        // ��ת���������
        mediaObject->seek(mediaObject->totalTime());
    } else {
        mediaObject->stop();
    }
}

// ���������б�
void MyWidget::tableClicked(int row)
{
    // ���Ȼ�ȡý�����ǰ��״̬��Ȼ��ֹͣ���Ų���ղ��Ŷ���
    bool wasPlaying = mediaObject->state() == Phonon::PlayingState;
    mediaObject->stop();
    mediaObject->clearQueue();

    // ��������Ĳ����б��е��кŴ���ý��Դ�б�Ĵ�С����ֱ�ӷ���
    if(row >= sources.size())
        return;
    // ���õ������ж�Ӧ��ý��ԴΪý�����ĵ�ǰý��Դ
    mediaObject->setCurrentSource(sources.at(row));
    // �����ǰý������ڲ���״̬����ô��ʼ����ѡ�е���Ŀ
    if (wasPlaying)
        mediaObject->play();
}

// ���ý��Դ�б����벥���б��playListClean()�źŹ���
void MyWidget::clearSources()
{
    sources.clear();
    // ���Ķ���ͼ��״̬
    changeActionState();
}
