#include "iot_app.h"
#include <QApplication>

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec * BianMa = QTextCodec::codecForName ( "GBK" );

    QFont font;
    font.setPointSize(7);//实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);

    a.setFont(font);

    IOT_App w;
    w.show();

    return a.exec();
}
