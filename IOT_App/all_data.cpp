
#include "all_data.h"   //初始化

QString all_data::portName = "/dev/s3c2410_serial1";    //串口名
QString all_data::NSL_hum_data = "0";    //湿度
QString all_data::NSL_pre_data = "0";    //降雨量

QString all_data::YSBT_1_X = "0";
QString all_data::YSBT_1_Y = "0";
QString all_data::YSBT_1_Z = "0";
QString all_data::YSBT_2_X = "0";
QString all_data::YSBT_2_Y = "0";
QString all_data::YSBT_2_Z = "0";

QString all_data::STHP_X = "0";
QString all_data::STHP_Y = "0";
QString all_data::STHP_Z = "0";
QString all_data::STHP_water = "0";


QString alarm_data::NSL_hum_Alarm = "100";  //湿度预警值
QString alarm_data::NSL_pre_Alarm = "100"; //降雨量预警值

QString alarm_data::YSBT_1_X_Alarm = "360";
QString alarm_data::YSBT_1_Y_Alarm = "360";
QString alarm_data::YSBT_1_Z_Alarm = "360";
QString alarm_data::YSBT_2_X_Alarm = "360";
QString alarm_data::YSBT_2_Y_Alarm = "360";
QString alarm_data::YSBT_2_Z_Alarm = "360";

QString alarm_data::STHP_X_Alarm = "360";
QString alarm_data::STHP_Y_Alarm = "360";
QString alarm_data::STHP_Z_Alarm = "360";
QString alarm_data::STHP_water = "100";


QString NSL_alarm::NSL_hum_conut = "0";
QString NSL_alarm::NSL_pre_count = "0";
QString NSL_alarm::NSL_alarm_total = "0";


