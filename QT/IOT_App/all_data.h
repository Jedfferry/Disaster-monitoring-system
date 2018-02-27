#ifndef ALL_DATA
#define ALL_DATA

#include <QWidget>

class all_data      //读取串口数据保存
{
public:
    static QString portName;    //串口名
    static QString NSL_hum_data;    //湿度
    static QString NSL_pre_data;    //降雨量

    static QString YSBT_1_X;
    static QString YSBT_1_Y;
    static QString YSBT_1_Z;
    static QString YSBT_2_X;
    static QString YSBT_2_Y;
    static QString YSBT_2_Z;

    static QString STHP_X;
    static QString STHP_Y;
    static QString STHP_Z;
    static QString STHP_water;


};

class alarm_data    //预警值全局变量
{
public:
    static QString NSL_hum_Alarm;  //湿度预警值
    static QString NSL_pre_Alarm;  //降雨量预警值

    static QString YSBT_1_X_Alarm;
    static QString YSBT_1_Y_Alarm;
    static QString YSBT_1_Z_Alarm;
    static QString YSBT_2_X_Alarm;
    static QString YSBT_2_Y_Alarm;
    static QString YSBT_2_Z_Alarm;

    static QString STHP_X_Alarm;
    static QString STHP_Y_Alarm;
    static QString STHP_Z_Alarm;
    static QString STHP_water;

};
class NSL_alarm         //没用
{
public:
    static QString NSL_hum_conut;
    static QString NSL_pre_count;
    static QString NSL_alarm_total;
};


#endif // ALL_DATA

