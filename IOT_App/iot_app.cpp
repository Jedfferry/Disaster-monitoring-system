#include "iot_app.h"
#include "ui_iot_app.h"

#include "all_data.h"


IOT_App::IOT_App(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IOT_App)
{
    ui->setupUi(this);

    startInit();    //初始化串口

}

IOT_App::~IOT_App()
{
    readTimer->stop();


    delete ui;
}

void IOT_App::startInit()
{
    mydataCom = new Posix_QextSerialPort(all_data::portName,QextSerialBase::Polling);//Polling 查询方式
    if(mydataCom->open(QIODevice::ReadWrite))   //读写打开
    {
        qDebug("open s3c2410_serial1 success\n");
    }
    else
    {
        qDebug("open s3c2410_serial1 failed\n");
    }

    mydataCom->setBaudRate((BaudRateType)BAUD115200);   //设置波特率
    mydataCom->setDataBits((DataBitsType)DATA_8);   //设置数据位
    mydataCom->setParity((ParityType)PAR_NONE);   //设置效验位
    mydataCom->setStopBits((StopBitsType)STOP_1);   //设置停止位
    mydataCom->setFlowControl((FLOW_OFF));  //设置数据流控制
    mydataCom->setTimeout(TIME_OUT); //设置延迟

    timerdly = TIME_INTERVAL;    //初始化读取定时器计时间隔

    readTimer = new QTimer(this);
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readComData()));//定时读取串口数据

    readTimer->start(TIME_INTERVAL);
}

void IOT_App::readComData()
{

    bool ok;
    QByteArray temp = mydataCom->readAll();   //读取串口数据
    QString str = temp.toHex();     //转成十六进制

    if(!temp.isEmpty())
    {
        if(str.mid(4,4)=="0101")    //湿度数据
        {
            QString humdata_temp = str.mid(8,1);
            if(humdata_temp == "a")
                humdata = 10;
            else if(humdata_temp == "b")
                humdata = 11;
            else if(humdata_temp == "c")
                humdata = 12;
            else if(humdata_temp == "d")
                humdata = 13;
            else if(humdata_temp == "e")
                humdata = 14;
            else if(humdata_temp == "f")
                humdata = 15;
            else
                humdata = humdata_temp.toInt(&ok,10);  //转成十进制

            humdata *= 16;

            humdata_temp = str.mid(9,1);
            if(humdata_temp == "a")
                humdata += 10;
            else if(humdata_temp == "b")
                humdata += 11;
            else if(humdata_temp == "c")
                humdata += 12;
            else if(humdata_temp == "d")
                humdata += 13;
            else if(humdata_temp == "e")
                humdata += 14;
            else if(humdata_temp == "f")
                humdata += 15;
            else
                humdata  += humdata_temp.toInt(&ok,10);

            all_data::NSL_hum_data = QString::number(humdata,10);   //转成字符串
            qDebug()<<temp.toHex();
        }
        if(str.mid(4,4)=="0102")    //降雨量
        {
            QString predata_temp = str.mid(8,1);
            if(predata_temp == "a")
                predata = 10;
            else if(predata_temp == "b")
                predata = 11;
            else if(predata_temp == "c")
                predata = 12;
            else if(predata_temp == "d")
                predata = 13;
            else if(predata_temp == "e")
                predata = 14;
            else if(predata_temp == "f")
                predata = 15;
            else
                predata = predata_temp.toInt(&ok,10);  //转成十进制

            predata *= 16;

            predata_temp = str.mid(9,1);
            if(predata_temp == "a")
                predata += 10;
            else if(predata_temp == "b")
                predata += 11;
            else if(predata_temp == "c")
                predata += 12;
            else if(predata_temp == "d")
                predata += 13;
            else if(predata_temp == "e")
                predata += 14;
            else if(predata_temp == "f")
                predata += 15;
            else
                predata  += predata_temp.toInt(&ok,10);

            all_data::NSL_pre_data = QString::number(predata,10);   //转成字符串
            qDebug()<<temp.toHex();
        }
        if(str.mid(4,4)=="0201")    //倾斜角点一
        {
            QString data_temp = str.mid(8,1);
            if(data_temp == "a")
                x1 = 10;
            else if(data_temp == "b")
                x1 = 11;
            else if(data_temp == "c")
                x1 = 12;
            else if(data_temp == "d")
                x1 = 13;
            else if(data_temp == "e")
                x1 = 14;
            else if(data_temp == "f")
                x1 = 15;
            else
                x1 = data_temp.toInt(&ok,10);  //转成十进制

            x1 *= 16;

            data_temp = str.mid(9,1);
            if(data_temp == "a")
                x1 += 10;
            else if(data_temp == "b")
                x1 += 11;
            else if(data_temp == "c")
                x1 += 12;
            else if(data_temp == "d")
                x1 += 13;
            else if(data_temp == "e")
                x1 += 14;
            else if(data_temp == "f")
                x1 += 15;
            else
                x1  += data_temp.toInt(&ok,10);
            if(x1>200)
                x1=x1*1.41;
            all_data::YSBT_1_X = QString::number(x1,10);   //转成字符串

            data_temp = str.mid(10,1);
            if(data_temp == "a")
                y1 = 10;
            else if(data_temp == "b")
                y1 = 11;
            else if(data_temp == "c")
                y1 = 12;
            else if(data_temp == "d")
                y1 = 13;
            else if(data_temp == "e")
                y1 = 14;
            else if(data_temp == "f")
                y1 = 15;
            else
                y1 = data_temp.toInt(&ok,10);  //转成十进制

            y1 *= 16;

            data_temp = str.mid(11,1);
            if(data_temp == "a")
                y1 += 10;
            else if(data_temp == "b")
                y1 += 11;
            else if(data_temp == "c")
                y1 += 12;
            else if(data_temp == "d")
                y1 += 13;
            else if(data_temp == "e")
                y1 += 14;
            else if(data_temp == "f")
                y1 += 15;
            else
                y1  += data_temp.toInt(&ok,10);
            if(y1>200)
             y1=y1*1.41;
            all_data::YSBT_1_Y = QString::number(y1,10);   //转成字符串


            data_temp = str.mid(12,1);
            if(data_temp == "a")
                z1 = 10;
            else if(data_temp == "b")
                z1 = 11;
            else if(data_temp == "c")
                z1 = 12;
            else if(data_temp == "d")
                z1 = 13;
            else if(data_temp == "e")
                z1 = 14;
            else if(data_temp == "f")
                z1 = 15;
            else
                z1 = data_temp.toInt(&ok,10);  //转成十进制

            z1 *= 16;

            data_temp = str.mid(13,1);
            if(data_temp == "a")
                z1 += 10;
            else if(data_temp == "b")
                z1 += 11;
            else if(data_temp == "c")
                z1 += 12;
            else if(data_temp == "d")
                z1 += 13;
            else if(data_temp == "e")
                z1 += 14;
            else if(data_temp == "f")
                z1 += 15;
            else
                z1  += data_temp.toInt(&ok,10);
            if(y1>200)
                z1=z1*1.41;
            all_data::YSBT_1_Z = QString::number(z1,10);   //转成字符串


            qDebug()<<temp.toHex();
        }

        if(str.mid(4,4)=="0201")    //倾斜角点二
        {
            QString data_temp = str.mid(8,1);
            if(data_temp == "a")
                x2 = 10;
            else if(data_temp == "b")
                x2 = 11;
            else if(data_temp == "c")
                x2 = 12;
            else if(data_temp == "d")
                x2 = 13;
            else if(data_temp == "e")
                x2 = 14;
            else if(data_temp == "f")
                x2 = 15;
            else
                x2 = data_temp.toInt(&ok,10);  //转成十进制

            x2 *= 16;

            data_temp = str.mid(9,1);
            if(data_temp == "a")
                x2 += 10;
            else if(data_temp == "b")
                x2 += 11;
            else if(data_temp == "c")
                x2 += 12;
            else if(data_temp == "d")
                x2 += 13;
            else if(data_temp == "e")
                x2 += 14;
            else if(data_temp == "f")
                x2 += 15;
            else
                x2  += data_temp.toInt(&ok,10);

            all_data::YSBT_2_X = QString::number(x2,10);   //转成字符串

            data_temp = str.mid(10,1);
            if(data_temp == "a")
                y2 = 10;
            else if(data_temp == "b")
                y2 = 11;
            else if(data_temp == "c")
                y2 = 12;
            else if(data_temp == "d")
                y2 = 13;
            else if(data_temp == "e")
                y2 = 14;
            else if(data_temp == "f")
                y2 = 15;
            else
                y2 = data_temp.toInt(&ok,10);  //转成十进制

            y2 *= 16;

            data_temp = str.mid(11,1);
            if(data_temp == "a")
                y2 += 10;
            else if(data_temp == "b")
                y2 += 11;
            else if(data_temp == "c")
                y2 += 12;
            else if(data_temp == "d")
                y2 += 13;
            else if(data_temp == "e")
                y2 += 14;
            else if(data_temp == "f")
                y2 += 15;
            else
                y2  += data_temp.toInt(&ok,10);

            all_data::YSBT_2_Y = QString::number(y2,10);   //转成字符串


            data_temp = str.mid(12,1);
            if(data_temp == "a")
                z2 = 10;
            else if(data_temp == "b")
                z2 = 11;
            else if(data_temp == "c")
                z2 = 12;
            else if(data_temp == "d")
                z2 = 13;
            else if(data_temp == "e")
                z2 = 14;
            else if(data_temp == "f")
                z2 = 15;
            else
                z2 = data_temp.toInt(&ok,10);  //转成十进制

            z2 *= 16;

            data_temp = str.mid(13,1);
            if(data_temp == "a")
                z2 += 10;
            else if(data_temp == "b")
                z2 += 11;
            else if(data_temp == "c")
                z2 += 12;
            else if(data_temp == "d")
                z2 += 13;
            else if(data_temp == "e")
                z2 += 14;
            else if(data_temp == "f")
                z2 += 15;
            else
                z2  += data_temp.toInt(&ok,10);

            all_data::YSBT_2_Z = QString::number(z2,10);   //转成字符串

            qDebug()<<temp.toHex();
        }

        if(str.mid(4,4)=="0201")    //山体滑坡倾斜角   用0202的数据   if(str.mid(4,4)=="0301")
        {
            QString data_temp = str.mid(8,1);
            if(data_temp == "a")
                xx = 10;
            else if(data_temp == "b")
                xx = 11;
            else if(data_temp == "c")
                xx = 12;
            else if(data_temp == "d")
                xx = 13;
            else if(data_temp == "e")
                xx = 14;
            else if(data_temp == "f")
                xx = 15;
            else
                xx = data_temp.toInt(&ok,10);  //转成十进制

            xx *= 16;

            data_temp = str.mid(9,1);
            if(data_temp == "a")
                xx += 10;
            else if(data_temp == "b")
                xx += 11;
            else if(data_temp == "c")
                xx += 12;
            else if(data_temp == "d")
                xx += 13;
            else if(data_temp == "e")
                xx += 14;
            else if(data_temp == "f")
                xx += 15;
            else
                xx  += data_temp.toInt(&ok,10);
            if(xx>200)
                xx=xx*1.41;
            all_data::STHP_X = QString::number(xx,10);   //转成字符串

            data_temp = str.mid(10,1);
            if(data_temp == "a")
                yy = 10;
            else if(data_temp == "b")
                yy = 11;
            else if(data_temp == "c")
                yy = 12;
            else if(data_temp == "d")
                yy = 13;
            else if(data_temp == "e")
                yy = 14;
            else if(data_temp == "f")
                yy = 15;
            else
                yy = data_temp.toInt(&ok,10);  //转成十进制

            yy *= 16;

            data_temp = str.mid(11,1);
            if(data_temp == "a")
                yy += 10;
            else if(data_temp == "b")
                yy += 11;
            else if(data_temp == "c")
                yy += 12;
            else if(data_temp == "d")
                yy += 13;
            else if(data_temp == "e")
                yy += 14;
            else if(data_temp == "f")
                yy += 15;
            else
                yy  += data_temp.toInt(&ok,10);
            if(yy>200)
                yy=yy*1.41;
            all_data::STHP_Y = QString::number(yy,10);   //转成字符串

            data_temp = str.mid(12,1);
            if(data_temp == "a")
                zz = 10;
            else if(data_temp == "b")
                zz = 11;
            else if(data_temp == "c")
                zz = 12;
            else if(data_temp == "d")
                zz = 13;
            else if(data_temp == "e")
                zz = 14;
            else if(data_temp == "f")
                z2 = 15;
            else
                zz = data_temp.toInt(&ok,10);  //转成十进制

            zz *= 16;

            data_temp = str.mid(13,1);
            if(data_temp == "a")
                zz += 10;
            else if(data_temp == "b")
                zz += 11;
            else if(data_temp == "c")
                zz += 12;
            else if(data_temp == "d")
                zz += 13;
            else if(data_temp == "e")
                zz += 14;
            else if(data_temp == "f")
                zz += 15;
            else
                zz  += data_temp.toInt(&ok,10);
            if(zz>200)
                zz=zz*1.41;
            all_data::STHP_Z = QString::number(zz,10);   //转成字符串

            qDebug()<<temp.toHex();
        }

        if(str.mid(4,4)=="0302")    //水位  烧错了应该是 0302
        {
            QString data_temp = str.mid(8,1);
            if(data_temp == "a")
                water = 10;
            else if(data_temp == "b")
                water = 11;
            else if(data_temp == "c")
                water = 12;
            else if(data_temp == "d")
                water = 13;
            else if(data_temp == "e")
                water = 14;
            else if(data_temp == "f")
                water = 15;
            else
                water = data_temp.toInt(&ok,10);  //转成十进制

            water *= 16;

            data_temp = str.mid(9,1);
            if(data_temp == "a")
                water += 10;
            else if(data_temp == "b")
                water += 11;
            else if(data_temp == "c")
                water += 12;
            else if(data_temp == "d")
                water += 13;
            else if(data_temp == "e")
                water += 14;
            else if(data_temp == "f")
                water += 15;
            else
                water  += data_temp.toInt(&ok,10);
            if(water>10)
                water=water-10;
            water=water/3;
            all_data::STHP_water = QString::number(water,10);   //转成字符串
            qDebug()<<temp.toHex();
        }
    }

}

void IOT_App::on_pushButton_NSL_clicked()
{
    w_nsl = new IOT_NSL();
    w_nsl->show();
}

void IOT_App::on_pushButton_YSBT_clicked()
{
    w_ysbt = new IOT_YSBT();
    w_ysbt->show();
}

void IOT_App::on_pushButton_YJSZ_clicked()
{
    w_yjsz = new IOT_YJSZ();
    w_yjsz->show();
}


void IOT_App::on_pushButton_STHP_clicked()
{
    w_sthp = new IOT_STHP();
    w_sthp->show();
}


