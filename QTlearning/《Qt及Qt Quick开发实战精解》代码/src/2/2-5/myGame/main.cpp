#include <QApplication>
#include "myview.h"
#include <QTextCodec>
#include <QTime>
// ��2-5����ӵĴ���
#include <QSplashScreen>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    // ����������ĳ�ʼֵ
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));


    // ��2-5����ӵĴ���
    QPixmap pix(":/images/logo.png");
    QSplashScreen splash(pix);
    splash.resize(pix.size());
    splash.show();
    app.processEvents();

    MyView view;
    view.show();

    // ��2-5����ӵĴ���
    splash.finish(&view);

    return app.exec();
}
