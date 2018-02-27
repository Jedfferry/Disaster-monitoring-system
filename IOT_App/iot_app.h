#ifndef IOT_APP_H
#define IOT_APP_H

#include <QWidget>

#include "iot_nsl.h"
#include "iot_ysbt.h"
#include "iot_yjsz.h"
#include "iot_sthp.h"

#include "posix_qextserialport.h" //串口头文件
#include <QtWidgets/QMessageBox>
#include <QTimer>
#include <QFile>
#include <QtDebug>

#define _TTY_POSIX_
#define TIME_OUT 10  //延时，TIME_OUT是串口读写延时
#define TIME_INTERVAL 200 //读取定时器时间隔，200ms


namespace Ui {
class IOT_App;
}

class IOT_App : public QWidget
{
    Q_OBJECT

public:
    explicit IOT_App(QWidget *parent = 0);
    ~IOT_App();

    IOT_NSL *w_nsl;
    IOT_YSBT *w_ysbt;
    IOT_YJSZ *w_yjsz;
    IOT_STHP *w_sthp;


private slots:
    void on_pushButton_NSL_clicked();

    void on_pushButton_YSBT_clicked();

    void on_pushButton_YJSZ_clicked();

    void on_pushButton_STHP_clicked();

    void readComData();  //定时读取串口数据

private:
    Ui::IOT_App *ui;

    void startInit();  //初始化

    int timerdly;

    Posix_QextSerialPort *mydataCom;   //定义读取数据的端口

    QTimer *readTimer;    //定义一个读取定时器

    int humdata;    //湿度数据
    int predata;    //降雨量数据

    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;

    int xx;
    int yy;
    int zz;
    int water;


};

#endif // IOT_APP_H
