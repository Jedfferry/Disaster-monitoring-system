#include "iot_yjsz.h"
#include "ui_iot_yjsz.h"

#include <QPalette>
#include <QMessageBox>

#include <QLineEdit>

#include <QPainter>
#include <QDesktopWidget>
#include <QScreen>
#include <QMetaEnum>
#include <QLabel>
IOT_YJSZ::IOT_YJSZ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IOT_YJSZ)
{
    ui->setupUi(this);

    ui->lineEdit_hum->setText(alarm_data::NSL_hum_Alarm);
    ui->lineEdit_pre->setText(alarm_data::NSL_pre_Alarm);
    ui->lineEdit_1_x->setText(alarm_data::YSBT_1_X_Alarm);
    ui->lineEdit_1_y->setText(alarm_data::YSBT_1_Y_Alarm);
    ui->lineEdit_1_z->setText(alarm_data::YSBT_1_Z_Alarm);
   // ui->lineEdit_2_x->setText(alarm_data::YSBT_2_X_Alarm);
   // ui->lineEdit_2_y->setText(alarm_data::YSBT_2_Y_Alarm);
   // ui->lineEdit_2_z->setText(alarm_data::YSBT_2_Z_Alarm);
    ui->lineEdit_x->setText(alarm_data::STHP_X_Alarm);
    ui->lineEdit_y->setText(alarm_data::STHP_Y_Alarm);
    ui->lineEdit_z->setText(alarm_data::STHP_Z_Alarm);
    ui->lineEdit_water->setText(alarm_data::STHP_water);


    ui->lineEdit_hum->installEventFilter(this);  //在窗体上为lineEdit_hum安装过滤器
    ui->lineEdit_pre->installEventFilter(this);  //在窗体上为lineEdit_pre安装过滤器
    ui->lineEdit_1_x->installEventFilter(this);
    ui->lineEdit_1_y->installEventFilter(this);
    ui->lineEdit_1_z->installEventFilter(this);
   // ui->lineEdit_2_x->installEventFilter(this);
  //  ui->lineEdit_2_y->installEventFilter(this);
   // ui->lineEdit_2_z->installEventFilter(this);
    ui->lineEdit_x->installEventFilter(this);
    ui->lineEdit_y->installEventFilter(this);
    ui->lineEdit_z->installEventFilter(this);
    ui->lineEdit_water->installEventFilter(this);
}

IOT_YJSZ::~IOT_YJSZ()
{
    delete ui;

}

bool IOT_YJSZ::eventFilter(QObject *watched, QEvent *event)
{

     if (watched==ui->lineEdit_hum)         //首先判断控件(这里指 lineEdit_hum)
     {
          if (event->type()==QEvent::FocusIn)     //然后再判断控件的具体事件 (这里指获得焦点事件)
          {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              qDebug()<<"yes hum";
              ui->lineEdit_hum->setPalette(p);
              flag = 1;
          }
          else if (event->type()==QEvent::FocusOut)    // 这里指 lineEdit_hum 控件的失去焦点事件
          {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              qDebug()<<"NO hum";
              ui->lineEdit_hum->setPalette(p);
           }
     }
     if (watched==ui->lineEdit_pre)           //这里来处理 lineEdit_pre , 和处理lineEdit_hum 是一样的
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_pre->setPalette(p);
              flag = 2;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_pre->setPalette(p);
         }
     }
     if (watched==ui->lineEdit_1_x)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_1_x->setPalette(p);
              flag = 3;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_1_x->setPalette(p);
         }
     }
     if (watched==ui->lineEdit_1_y)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_1_y->setPalette(p);
              flag = 4;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_1_y->setPalette(p);
         }
     }

     if (watched==ui->lineEdit_1_z)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_1_z->setPalette(p);
              flag = 5;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_1_z->setPalette(p);
         }
     }
    /* if (watched==ui->lineEdit_2_x)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_2_x->setPalette(p);
              flag = 6;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_2_x->setPalette(p);
         }
     }
     if (watched==ui->lineEdit_2_y)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_2_y->setPalette(p);
              flag = 7;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_2_y->setPalette(p);
         }
     }
     if (watched==ui->lineEdit_2_z)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_2_z->setPalette(p);
              flag = 8;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_2_z->setPalette(p);
         }
     }*/
     if (watched==ui->lineEdit_x)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_x->setPalette(p);
              flag = 9;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_x->setPalette(p);
         }
     }
     if (watched==ui->lineEdit_y)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_y->setPalette(p);
              flag = 10;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_y->setPalette(p);
         }
     }
     if (watched==ui->lineEdit_z)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_z->setPalette(p);
              flag = 11;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_z->setPalette(p);
         }
     }
     if (watched==ui->lineEdit_water)
     {
          if (event->type()==QEvent::FocusIn)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::green);
              ui->lineEdit_water->setPalette(p);
              flag = 12;
          }
         else if (event->type()==QEvent::FocusOut)
         {
              QPalette p=QPalette();
              p.setColor(QPalette::Base,Qt::white);
              ui->lineEdit_water->setPalette(p);
         }
     }
 return QWidget::eventFilter(watched,event);     // 最后将事件交给上层对话框
}


void IOT_YJSZ::on_back_clicked()
{
    this->close();
}

void IOT_YJSZ::on_pushButton0_clicked()
{
    switch (flag) {
    case 1:
        str = ui->lineEdit_hum->text();
        str += "0";
        ui->lineEdit_hum->setText(str);
        break;
    case 2:
        str = ui->lineEdit_pre->text();
        str += "0";
        ui->lineEdit_pre->setText(str);
        break;
    case 3:
        str = ui->lineEdit_1_x->text();
        str += "0";
        ui->lineEdit_1_x->setText(str);
        break;
    case 4:
        str = ui->lineEdit_1_y->text();
        str += "0";
        ui->lineEdit_1_y->setText(str);
        break;
    case 5:
        str = ui->lineEdit_1_z->text();
        str += "0";
        ui->lineEdit_1_z->setText(str);
        break;
    /*case 6:
        str = ui->lineEdit_2_x->text();
        str += "0";
        ui->lineEdit_2_x->setText(str);
        break;
    case 7:
        str = ui->lineEdit_2_y->text();
        str += "0";
        ui->lineEdit_2_y->setText(str);
        break;
    case 8:
        str = ui->lineEdit_2_z->text();
        str += "0";
        ui->lineEdit_2_z->setText(str);
        break;*/
    case 9:
        str = ui->lineEdit_x->text();
        str += "0";
        ui->lineEdit_x->setText(str);
        break;
    case 10:
        str = ui->lineEdit_y->text();
        str += "0";
        ui->lineEdit_y->setText(str);
        break;
    case 11:
        str = ui->lineEdit_z->text();
        str += "0";
        ui->lineEdit_z->setText(str);
        break;
    case 12:
        str = ui->lineEdit_water->text();
        str += "0";
        ui->lineEdit_water->setText(str);
        break;
    default:
        break;
    }

    switch (flag) {
    case 1:
        ui->lineEdit_hum->setFocus();
        break;
    case 2:
        ui->lineEdit_pre->setFocus();
        break;
    case 3:
        ui->lineEdit_1_x->setFocus();
        break;
    case 4:
        ui->lineEdit_1_y->setFocus();
        break;
    case 5:
        ui->lineEdit_1_z->setFocus();
        break;
    /*case 6:
        ui->lineEdit_2_x->setFocus();
        break;
    case 7:
        ui->lineEdit_2_y->setFocus();
        break;
    case 8:
        ui->lineEdit_2_z->setFocus();
        break;*/
    case 9:
        ui->lineEdit_x->setFocus();
        break;
    case 10:
        ui->lineEdit_y->setFocus();
        break;
    case 11:
        ui->lineEdit_z->setFocus();
        break;
    case 12:
        ui->lineEdit_water  ->setFocus();
        break;
    default:
        break;
    }
}


void IOT_YJSZ::on_pushButton1_clicked()
{
    switch (flag) {
    case 1:
        str = ui->lineEdit_hum->text();
        str += "1";
        ui->lineEdit_hum->setText(str);
        break;
    case 2:
        str = ui->lineEdit_pre->text();
        str += "1";
        ui->lineEdit_pre->setText(str);
        break;
    case 3:
        str = ui->lineEdit_1_x->text();
        str += "1";
        ui->lineEdit_1_x->setText(str);
        break;
    case 4:
        str = ui->lineEdit_1_y->text();
        str += "1";
        ui->lineEdit_1_y->setText(str);
        break;
    case 5:
        str = ui->lineEdit_1_z->text();
        str += "1";
        ui->lineEdit_1_z->setText(str);
        break;
    /*case 6:
        str = ui->lineEdit_2_x->text();
        str += "1";
        ui->lineEdit_2_x->setText(str);
        break;
    case 7:
        str = ui->lineEdit_2_y->text();
        str += "1";
        ui->lineEdit_2_y->setText(str);
        break;
    case 8:
        str = ui->lineEdit_2_z->text();
        str += "1";
        ui->lineEdit_2_z->setText(str);
        break;*/
    case 9:
        str = ui->lineEdit_x->text();
        str += "1";
        ui->lineEdit_x->setText(str);
        break;
    case 10:
        str = ui->lineEdit_y->text();
        str += "1";
        ui->lineEdit_y->setText(str);
        break;
    case 11:
        str = ui->lineEdit_z->text();
        str += "1";
        ui->lineEdit_z->setText(str);
        break;
    case 12:
        str = ui->lineEdit_water->text();
        str += "1";
        ui->lineEdit_water->setText(str);
        break;
    default:
        break;
    }

    switch (flag) {
    case 1:
        ui->lineEdit_hum->setFocus();
        break;
    case 2:
        ui->lineEdit_pre->setFocus();
        break;
    case 3:
        ui->lineEdit_1_x->setFocus();
        break;
    case 4:
        ui->lineEdit_1_y->setFocus();
        break;
    case 5:
        ui->lineEdit_1_z->setFocus();
        break;
   /* case 6:
        ui->lineEdit_2_x->setFocus();
        break;
    case 7:
        ui->lineEdit_2_y->setFocus();
        break;
    case 8:
        ui->lineEdit_2_z->setFocus();
        break;*/
    case 9:
        ui->lineEdit_x->setFocus();
        break;
    case 10:
        ui->lineEdit_y->setFocus();
        break;
    case 11:
        ui->lineEdit_z->setFocus();
        break;
    case 12:
        ui->lineEdit_water  ->setFocus();
        break;
    default:
        break;
    }
}

void IOT_YJSZ::on_pushButton2_clicked()
{
    switch (flag) {
    case 1:
        str = ui->lineEdit_hum->text();
        str += "2";
        ui->lineEdit_hum->setText(str);
        break;
    case 2:
        str = ui->lineEdit_pre->text();
        str += "2";
        ui->lineEdit_pre->setText(str);
        break;
    case 3:
        str = ui->lineEdit_1_x->text();
        str += "2";
        ui->lineEdit_1_x->setText(str);
        break;
    case 4:
        str = ui->lineEdit_1_y->text();
        str += "2";
        ui->lineEdit_1_y->setText(str);
        break;
    case 5:
        str = ui->lineEdit_1_z->text();
        str += "2";
        ui->lineEdit_1_z->setText(str);
        break;
   /* case 6:
        str = ui->lineEdit_2_x->text();
        str += "2";
        ui->lineEdit_2_x->setText(str);
        break;
    case 7:
        str = ui->lineEdit_2_y->text();
        str += "2";
        ui->lineEdit_2_y->setText(str);
        break;
    case 8:
        str = ui->lineEdit_2_z->text();
        str += "2";
        ui->lineEdit_2_z->setText(str);
        break;*/
    case 9:
        str = ui->lineEdit_x->text();
        str += "2";
        ui->lineEdit_x->setText(str);
        break;
    case 10:
        str = ui->lineEdit_y->text();
        str += "2";
        ui->lineEdit_y->setText(str);
        break;
    case 11:
        str = ui->lineEdit_z->text();
        str += "2";
        ui->lineEdit_z->setText(str);
        break;
    case 12:
        str = ui->lineEdit_water->text();
        str += "2";
        ui->lineEdit_water->setText(str);
        break;
    default:
        break;
    }

    switch (flag) {
    case 1:
        ui->lineEdit_hum->setFocus();
        break;
    case 2:
        ui->lineEdit_pre->setFocus();
        break;
    case 3:
        ui->lineEdit_1_x->setFocus();
        break;
    case 4:
        ui->lineEdit_1_y->setFocus();
        break;
    case 5:
        ui->lineEdit_1_z->setFocus();
        break;
   /* case 6:
        ui->lineEdit_2_x->setFocus();
        break;
    case 7:
        ui->lineEdit_2_y->setFocus();
        break;
    case 8:
        ui->lineEdit_2_z->setFocus();
        break;*/
    case 9:
        ui->lineEdit_x->setFocus();
        break;
    case 10:
        ui->lineEdit_y->setFocus();
        break;
    case 11:
        ui->lineEdit_z->setFocus();
        break;
    case 12:
        ui->lineEdit_water  ->setFocus();
        break;
    default:
        break;
    }
}

void IOT_YJSZ::on_pushButton3_clicked()
{
    switch (flag) {
    case 1:
        str = ui->lineEdit_hum->text();
        str += "3";
        ui->lineEdit_hum->setText(str);
        break;
    case 2:
        str = ui->lineEdit_pre->text();
        str += "3";
        ui->lineEdit_pre->setText(str);
        break;
    case 3:
        str = ui->lineEdit_1_x->text();
        str += "3";
        ui->lineEdit_1_x->setText(str);
        break;
    case 4:
        str = ui->lineEdit_1_y->text();
        str += "3";
        ui->lineEdit_1_y->setText(str);
        break;
    case 5:
        str = ui->lineEdit_1_z->text();
        str += "3";
        ui->lineEdit_1_z->setText(str);
        break;
  /*  case 6:
        str = ui->lineEdit_2_x->text();
        str += "3";
        ui->lineEdit_2_x->setText(str);
        break;
    case 7:
        str = ui->lineEdit_2_y->text();
        str += "3";
        ui->lineEdit_2_y->setText(str);
        break;
    case 8:
        str = ui->lineEdit_2_z->text();
        str += "3";
        ui->lineEdit_2_z->setText(str);
        break;*/
    case 9:
        str = ui->lineEdit_x->text();
        str += "3";
        ui->lineEdit_x->setText(str);
        break;
    case 10:
        str = ui->lineEdit_y->text();
        str += "3";
        ui->lineEdit_y->setText(str);
        break;
    case 11:
        str = ui->lineEdit_z->text();
        str += "3";
        ui->lineEdit_z->setText(str);
        break;
    case 12:
        str = ui->lineEdit_water->text();
        str += "3";
        ui->lineEdit_water->setText(str);
        break;
    default:
        break;
    }

    switch (flag) {
    case 1:
        ui->lineEdit_hum->setFocus();
        break;
    case 2:
        ui->lineEdit_pre->setFocus();
        break;
    case 3:
        ui->lineEdit_1_x->setFocus();
        break;
    case 4:
        ui->lineEdit_1_y->setFocus();
        break;
    case 5:
        ui->lineEdit_1_z->setFocus();
        break;
   /* case 6:
        ui->lineEdit_2_x->setFocus();
        break;
    case 7:
        ui->lineEdit_2_y->setFocus();
        break;
    case 8:
        ui->lineEdit_2_z->setFocus();
        break;*/
    case 9:
        ui->lineEdit_x->setFocus();
        break;
    case 10:
        ui->lineEdit_y->setFocus();
        break;
    case 11:
        ui->lineEdit_z->setFocus();
        break;
    case 12:
        ui->lineEdit_water  ->setFocus();
        break;
    default:
        break;
    }
}

void IOT_YJSZ::on_pushButton4_clicked()
{
    switch (flag) {
    case 1:
        str = ui->lineEdit_hum->text();
        str += "4";
        ui->lineEdit_hum->setText(str);
        break;
    case 2:
        str = ui->lineEdit_pre->text();
        str += "4";
        ui->lineEdit_pre->setText(str);
        break;
    case 3:
        str = ui->lineEdit_1_x->text();
        str += "4";
        ui->lineEdit_1_x->setText(str);
        break;
    case 4:
        str = ui->lineEdit_1_y->text();
        str += "4";
        ui->lineEdit_1_y->setText(str);
        break;
    case 5:
        str = ui->lineEdit_1_z->text();
        str += "4";
        ui->lineEdit_1_z->setText(str);
        break;
    /*case 6:
        str = ui->lineEdit_2_x->text();
        str += "4";
        ui->lineEdit_2_x->setText(str);
        break;
    case 7:
        str = ui->lineEdit_2_y->text();
        str += "4";
        ui->lineEdit_2_y->setText(str);
        break;
    case 8:
        str = ui->lineEdit_2_z->text();
        str += "4";
        ui->lineEdit_2_z->setText(str);
        break;*/
    case 9:
        str = ui->lineEdit_x->text();
        str += "4";
        ui->lineEdit_x->setText(str);
        break;
    case 10:
        str = ui->lineEdit_y->text();
        str += "4";
        ui->lineEdit_y->setText(str);
        break;
    case 11:
        str = ui->lineEdit_z->text();
        str += "4";
        ui->lineEdit_z->setText(str);
        break;
    case 12:
        str = ui->lineEdit_water->text();
        str += "4";
        ui->lineEdit_water->setText(str);
        break;
    default:
        break;
    }

    switch (flag) {
    case 1:
        ui->lineEdit_hum->setFocus();
        break;
    case 2:
        ui->lineEdit_pre->setFocus();
        break;
    case 3:
        ui->lineEdit_1_x->setFocus();
        break;
    case 4:
        ui->lineEdit_1_y->setFocus();
        break;
    case 5:
        ui->lineEdit_1_z->setFocus();
        break;
   /* case 6:
        ui->lineEdit_2_x->setFocus();
        break;
    case 7:
        ui->lineEdit_2_y->setFocus();
        break;
    case 8:
        ui->lineEdit_2_z->setFocus();
        break;*/
    case 9:
        ui->lineEdit_x->setFocus();
        break;
    case 10:
        ui->lineEdit_y->setFocus();
        break;
    case 11:
        ui->lineEdit_z->setFocus();
        break;
    case 12:
        ui->lineEdit_water  ->setFocus();
        break;
    default:
        break;
    }
}

void IOT_YJSZ::on_pushButton5_clicked()
{
    switch (flag) {
        case 1:
            str = ui->lineEdit_hum->text();
            str += "5";
            ui->lineEdit_hum->setText(str);
            break;
        case 2:
            str = ui->lineEdit_pre->text();
            str += "5";
            ui->lineEdit_pre->setText(str);
            break;
        case 3:
            str = ui->lineEdit_1_x->text();
            str += "5";
            ui->lineEdit_1_x->setText(str);
            break;
        case 4:
            str = ui->lineEdit_1_y->text();
            str += "5";
            ui->lineEdit_1_y->setText(str);
            break;
        case 5:
            str = ui->lineEdit_1_z->text();
            str += "5";
            ui->lineEdit_1_z->setText(str);
            break;
       /* case 6:
            str = ui->lineEdit_2_x->text();
            str += "5";
            ui->lineEdit_2_x->setText(str);
            break;
        case 7:
            str = ui->lineEdit_2_y->text();
            str += "5";
            ui->lineEdit_2_y->setText(str);
            break;
        case 8:
            str = ui->lineEdit_2_z->text();
            str += "5";
            ui->lineEdit_2_z->setText(str);
            break;*/
        case 9:
            str = ui->lineEdit_x->text();
            str += "5";
            ui->lineEdit_x->setText(str);
            break;
        case 10:
            str = ui->lineEdit_y->text();
            str += "5";
            ui->lineEdit_y->setText(str);
            break;
        case 11:
            str = ui->lineEdit_z->text();
            str += "";
            ui->lineEdit_z->setText(str);
            break;
        case 12:
            str = ui->lineEdit_water->text();
            str += "5";
            ui->lineEdit_water->setText(str);
            break;
        default:
            break;
        }

        switch (flag) {
        case 1:
            ui->lineEdit_hum->setFocus();
            break;
        case 2:
            ui->lineEdit_pre->setFocus();
            break;
        case 3:
            ui->lineEdit_1_x->setFocus();
            break;
        case 4:
            ui->lineEdit_1_y->setFocus();
            break;
        case 5:
            ui->lineEdit_1_z->setFocus();
            break;
       /* case 6:
            ui->lineEdit_2_x->setFocus();
            break;
        case 7:
            ui->lineEdit_2_y->setFocus();
            break;
        case 8:
            ui->lineEdit_2_z->setFocus();
            break;*/
        case 9:
            ui->lineEdit_x->setFocus();
            break;
        case 10:
            ui->lineEdit_y->setFocus();
            break;
        case 11:
            ui->lineEdit_z->setFocus();
            break;
        case 12:
            ui->lineEdit_water  ->setFocus();
            break;
        default:
            break;
        }
}

void IOT_YJSZ::on_pushButton6_clicked()
{
    switch (flag) {
        case 1:
            str = ui->lineEdit_hum->text();
            str += "6";
            ui->lineEdit_hum->setText(str);
            break;
        case 2:
            str = ui->lineEdit_pre->text();
            str += "6";
            ui->lineEdit_pre->setText(str);
            break;
        case 3:
            str = ui->lineEdit_1_x->text();
            str += "6";
            ui->lineEdit_1_x->setText(str);
            break;
        case 4:
            str = ui->lineEdit_1_y->text();
            str += "6";
            ui->lineEdit_1_y->setText(str);
            break;
        case 5:
            str = ui->lineEdit_1_z->text();
            str += "6";
            ui->lineEdit_1_z->setText(str);
            break;
       /* case 6:
            str = ui->lineEdit_2_x->text();
            str += "6";
            ui->lineEdit_2_x->setText(str);
            break;
        case 7:
            str = ui->lineEdit_2_y->text();
            str += "6";
            ui->lineEdit_2_y->setText(str);
            break;
        case 8:
            str = ui->lineEdit_2_z->text();
            str += "6";
            ui->lineEdit_2_z->setText(str);
            break;*/
        case 9:
            str = ui->lineEdit_x->text();
            str += "6";
            ui->lineEdit_x->setText(str);
            break;
        case 10:
            str = ui->lineEdit_y->text();
            str += "6";
            ui->lineEdit_y->setText(str);
            break;
        case 11:
            str = ui->lineEdit_z->text();
            str += "6";
            ui->lineEdit_z->setText(str);
            break;
        case 12:
            str = ui->lineEdit_water->text();
            str += "6";
            ui->lineEdit_water->setText(str);
            break;
        default:
            break;
        }

        switch (flag) {
        case 1:
            ui->lineEdit_hum->setFocus();
            break;
        case 2:
            ui->lineEdit_pre->setFocus();
            break;
        case 3:
            ui->lineEdit_1_x->setFocus();
            break;
        case 4:
            ui->lineEdit_1_y->setFocus();
            break;
        case 5:
            ui->lineEdit_1_z->setFocus();
            break;
        /*case 6:
            ui->lineEdit_2_x->setFocus();
            break;
        case 7:
            ui->lineEdit_2_y->setFocus();
            break;
        case 8:
            ui->lineEdit_2_z->setFocus();
            break;*/
        case 9:
            ui->lineEdit_x->setFocus();
            break;
        case 10:
            ui->lineEdit_y->setFocus();
            break;
        case 11:
            ui->lineEdit_z->setFocus();
            break;
        case 12:
            ui->lineEdit_water  ->setFocus();
            break;
        default:
            break;
        }
}

void IOT_YJSZ::on_pushButton7_clicked()
{
    switch (flag) {
        case 1:
            str = ui->lineEdit_hum->text();
            str += "7";
            ui->lineEdit_hum->setText(str);
            break;
        case 2:
            str = ui->lineEdit_pre->text();
            str += "7";
            ui->lineEdit_pre->setText(str);
            break;
        case 3:
            str = ui->lineEdit_1_x->text();
            str += "7";
            ui->lineEdit_1_x->setText(str);
            break;
        case 4:
            str = ui->lineEdit_1_y->text();
            str += "7";
            ui->lineEdit_1_y->setText(str);
            break;
        case 5:
            str = ui->lineEdit_1_z->text();
            str += "7";
            ui->lineEdit_1_z->setText(str);
            break;
       /*case 6:
            str = ui->lineEdit_2_x->text();
            str += "7";
            ui->lineEdit_2_x->setText(str);
            break;
        case 7:
            str = ui->lineEdit_2_y->text();
            str += "7";
            ui->lineEdit_2_y->setText(str);
            break;
        case 8:
            str = ui->lineEdit_2_z->text();
            str += "7";
            ui->lineEdit_2_z->setText(str);
            break;*/
        case 9:
            str = ui->lineEdit_x->text();
            str += "7";
            ui->lineEdit_x->setText(str);
            break;
        case 10:
            str = ui->lineEdit_y->text();
            str += "7";
            ui->lineEdit_y->setText(str);
            break;
        case 11:
            str = ui->lineEdit_z->text();
            str += "7";
            ui->lineEdit_z->setText(str);
            break;
        case 12:
            str = ui->lineEdit_water->text();
            str += "7";
            ui->lineEdit_water->setText(str);
            break;
        default:
            break;
        }

        switch (flag) {
        case 1:
            ui->lineEdit_hum->setFocus();
            break;
        case 2:
            ui->lineEdit_pre->setFocus();
            break;
        case 3:
            ui->lineEdit_1_x->setFocus();
            break;
        case 4:
            ui->lineEdit_1_y->setFocus();
            break;
        case 5:
            ui->lineEdit_1_z->setFocus();
            break;
        /*case 6:
            ui->lineEdit_2_x->setFocus();
            break;
        case 7:
            ui->lineEdit_2_y->setFocus();
            break;
        case 8:
            ui->lineEdit_2_z->setFocus();
            break;*/
        case 9:
            ui->lineEdit_x->setFocus();
            break;
        case 10:
            ui->lineEdit_y->setFocus();
            break;
        case 11:
            ui->lineEdit_z->setFocus();
            break;
        case 12:
            ui->lineEdit_water  ->setFocus();
            break;
        default:
            break;
        }
}

void IOT_YJSZ::on_pushButton8_clicked()
{
    switch (flag) {
        case 1:
            str = ui->lineEdit_hum->text();
            str += "8";
            ui->lineEdit_hum->setText(str);
            break;
        case 2:
            str = ui->lineEdit_pre->text();
            str += "8";
            ui->lineEdit_pre->setText(str);
            break;
        case 3:
            str = ui->lineEdit_1_x->text();
            str += "8";
            ui->lineEdit_1_x->setText(str);
            break;
        case 4:
            str = ui->lineEdit_1_y->text();
            str += "8";
            ui->lineEdit_1_y->setText(str);
            break;
        case 5:
            str = ui->lineEdit_1_z->text();
            str += "8";
            ui->lineEdit_1_z->setText(str);
            break;
       /* case 6:
            str = ui->lineEdit_2_x->text();
            str += "8";
            ui->lineEdit_2_x->setText(str);
            break;
        case 7:
            str = ui->lineEdit_2_y->text();
            str += "8";
            ui->lineEdit_2_y->setText(str);
            break;
        case 8:
            str = ui->lineEdit_2_z->text();
            str += "8";
            ui->lineEdit_2_z->setText(str);
            break;*/
        case 9:
            str = ui->lineEdit_x->text();
            str += "8";
            ui->lineEdit_x->setText(str);
            break;
        case 10:
            str = ui->lineEdit_y->text();
            str += "8";
            ui->lineEdit_y->setText(str);
            break;
        case 11:
            str = ui->lineEdit_z->text();
            str += "8";
            ui->lineEdit_z->setText(str);
            break;
        case 12:
            str = ui->lineEdit_water->text();
            str += "8";
            ui->lineEdit_water->setText(str);
            break;
        default:
            break;
        }

        switch (flag) {
        case 1:
            ui->lineEdit_hum->setFocus();
            break;
        case 2:
            ui->lineEdit_pre->setFocus();
            break;
        case 3:
            ui->lineEdit_1_x->setFocus();
            break;
        case 4:
            ui->lineEdit_1_y->setFocus();
            break;
        case 5:
            ui->lineEdit_1_z->setFocus();
            break;
        /*case 6:
            ui->lineEdit_2_x->setFocus();
            break;
        case 7:
            ui->lineEdit_2_y->setFocus();
            break;
        case 8:
            ui->lineEdit_2_z->setFocus();
            break;*/
        case 9:
            ui->lineEdit_x->setFocus();
            break;
        case 10:
            ui->lineEdit_y->setFocus();
            break;
        case 11:
            ui->lineEdit_z->setFocus();
            break;
        case 12:
            ui->lineEdit_water  ->setFocus();
            break;
        default:
            break;
        }
}

void IOT_YJSZ::on_pushButton9_clicked()
{
    switch (flag) {
        case 1:
            str = ui->lineEdit_hum->text();
            str += "9";
            ui->lineEdit_hum->setText(str);
            break;
        case 2:
            str = ui->lineEdit_pre->text();
            str += "9";
            ui->lineEdit_pre->setText(str);
            break;
        case 3:
            str = ui->lineEdit_1_x->text();
            str += "9";
            ui->lineEdit_1_x->setText(str);
            break;
        case 4:
            str = ui->lineEdit_1_y->text();
            str += "9";
            ui->lineEdit_1_y->setText(str);
            break;
        case 5:
            str = ui->lineEdit_1_z->text();
            str += "9";
            ui->lineEdit_1_z->setText(str);
            break;
       /* case 6:
            str = ui->lineEdit_2_x->text();
            str += "9";
            ui->lineEdit_2_x->setText(str);
            break;
        case 7:
            str = ui->lineEdit_2_y->text();
            str += "9";
            ui->lineEdit_2_y->setText(str);
            break;
        case 8:
            str = ui->lineEdit_2_z->text();
            str += "9";
            ui->lineEdit_2_z->setText(str);
            break;*/
        case 9:
            str = ui->lineEdit_x->text();
            str += "9";
            ui->lineEdit_x->setText(str);
            break;
        case 10:
            str = ui->lineEdit_y->text();
            str += "9";
            ui->lineEdit_y->setText(str);
            break;
        case 11:
            str = ui->lineEdit_z->text();
            str += "9";
            ui->lineEdit_z->setText(str);
            break;
        case 12:
            str = ui->lineEdit_water->text();
            str += "9";
            ui->lineEdit_water->setText(str);
            break;
        default:
            break;
        }

        switch (flag) {
        case 1:
            ui->lineEdit_hum->setFocus();
            break;
        case 2:
            ui->lineEdit_pre->setFocus();
            break;
        case 3:
            ui->lineEdit_1_x->setFocus();
            break;
        case 4:
            ui->lineEdit_1_y->setFocus();
            break;
        case 5:
            ui->lineEdit_1_z->setFocus();
            break;
        /*case 6:
            ui->lineEdit_2_x->setFocus();
            break;
        case 7:
            ui->lineEdit_2_y->setFocus();
            break;
        case 8:
            ui->lineEdit_2_z->setFocus();
            break;*/
        case 9:
            ui->lineEdit_x->setFocus();
            break;
        case 10:
            ui->lineEdit_y->setFocus();
            break;
        case 11:
            ui->lineEdit_z->setFocus();
            break;
        case 12:
            ui->lineEdit_water  ->setFocus();
            break;
        default:
            break;
        }
}

void IOT_YJSZ::on_pushButton_dian_clicked()
{
    switch (flag) {
        case 1:
            str = ui->lineEdit_hum->text();
            str += ".";
            ui->lineEdit_hum->setText(str);
            break;
        case 2:
            str = ui->lineEdit_pre->text();
            str += ".";
            ui->lineEdit_pre->setText(str);
            break;
        case 3:
            str = ui->lineEdit_1_x->text();
            str += ".";
            ui->lineEdit_1_x->setText(str);
            break;
        case 4:
            str = ui->lineEdit_1_y->text();
            str += ".";
            ui->lineEdit_1_y->setText(str);
            break;
        case 5:
            str = ui->lineEdit_1_z->text();
            str += ".";
            ui->lineEdit_1_z->setText(str);
            break;
       /* case 6:
            str = ui->lineEdit_2_x->text();
            str += ".";
            ui->lineEdit_2_x->setText(str);
            break;
        case 7:
            str = ui->lineEdit_2_y->text();
            str += ".";
            ui->lineEdit_2_y->setText(str);
            break;
        case 8:
            str = ui->lineEdit_2_z->text();
            str += ".";
            ui->lineEdit_2_z->setText(str);
            break;*/
        case 9:
            str = ui->lineEdit_x->text();
            str += ".";
            ui->lineEdit_x->setText(str);
            break;
        case 10:
            str = ui->lineEdit_y->text();
            str += ".";
            ui->lineEdit_y->setText(str);
            break;
        case 11:
            str = ui->lineEdit_z->text();
            str += ".";
            ui->lineEdit_z->setText(str);
            break;
        case 12:
            str = ui->lineEdit_water->text();
            str += ".";
            ui->lineEdit_water->setText(str);
            break;
        default:
            break;
        }

        switch (flag) {
        case 1:
            ui->lineEdit_hum->setFocus();
            break;
        case 2:
            ui->lineEdit_pre->setFocus();
            break;
        case 3:
            ui->lineEdit_1_x->setFocus();
            break;
        case 4:
            ui->lineEdit_1_y->setFocus();
            break;
        case 5:
            ui->lineEdit_1_z->setFocus();
            break;
        /*case 6:
            ui->lineEdit_2_x->setFocus();
            break;
        case 7:
            ui->lineEdit_2_y->setFocus();
            break;
        case 8:
            ui->lineEdit_2_z->setFocus();
            break;*/
        case 9:
            ui->lineEdit_x->setFocus();
            break;
        case 10:
            ui->lineEdit_y->setFocus();
            break;
        case 11:
            ui->lineEdit_z->setFocus();
            break;
        case 12:
            ui->lineEdit_water  ->setFocus();
            break;
        default:
            break;
        }
}

void IOT_YJSZ::on_pushButton_C_clicked()
{
    switch (flag) {
        case 1:
            str = ui->lineEdit_hum->text();
            str = str.left(str.length()-1);
            ui->lineEdit_hum->setText(str);
            break;
        case 2:
            str = ui->lineEdit_pre->text();
            str = str.left(str.length()-1);
            ui->lineEdit_pre->setText(str);
        break;
            break;
        case 3:
            str = ui->lineEdit_1_x->text();
            str = str.left(str.length()-1);
            ui->lineEdit_1_x->setText(str);
            break;
        case 4:
            str = ui->lineEdit_1_y->text();
            str = str.left(str.length()-1);
            ui->lineEdit_1_y->setText(str);
            break;
        case 5:
            str = ui->lineEdit_1_z->text();
            str = str.left(str.length()-1);
            ui->lineEdit_1_z->setText(str);
            break;
        /*case 6:
            str = ui->lineEdit_2_x->text();
            str = str.left(str.length()-1);
            ui->lineEdit_2_x->setText(str);
            break;
        case 7:
            str = ui->lineEdit_2_y->text();
            str = str.left(str.length()-1);
            ui->lineEdit_2_y->setText(str);
            break;
        case 8:
            str = ui->lineEdit_2_z->text();
            str = str.left(str.length()-1);
            ui->lineEdit_2_z->setText(str);
            break;*/
        case 9:
            str = ui->lineEdit_x->text();
            str = str.left(str.length()-1);
            ui->lineEdit_x->setText(str);
            break;
        case 10:
            str = ui->lineEdit_y->text();
            str = str.left(str.length()-1);
            ui->lineEdit_y->setText(str);
            break;
        case 11:
            str = ui->lineEdit_z->text();
            str = str.left(str.length()-1);
            ui->lineEdit_z->setText(str);
            break;
        case 12:
            str = ui->lineEdit_water->text();
            str = str.left(str.length()-1);
            ui->lineEdit_water->setText(str);
            break;
        default:
            break;
        }

        switch (flag) {
        case 1:
            ui->lineEdit_hum->setFocus();
            break;
        case 2:
            ui->lineEdit_pre->setFocus();
            break;
        case 3:
            ui->lineEdit_1_x->setFocus();
            break;
        case 4:
            ui->lineEdit_1_y->setFocus();
            break;
        case 5:
            ui->lineEdit_1_z->setFocus();
            break;
        /*case 6:
            ui->lineEdit_2_x->setFocus();
            break;
        case 7:
            ui->lineEdit_2_y->setFocus();
            break;
        case 8:
            ui->lineEdit_2_z->setFocus();
            break;*/
        case 9:
            ui->lineEdit_x->setFocus();
            break;
        case 10:
            ui->lineEdit_y->setFocus();
            break;
        case 11:
            ui->lineEdit_z->setFocus();
            break;
        case 12:
            ui->lineEdit_water  ->setFocus();
            break;
        default:
            break;
        }
}
void IOT_YJSZ::Save_MessageBox()
{
    box = new QMessageBox;
    QTimer::singleShot(1500, box, SLOT(close()));

    box->setWindowTitle(tr("提示"));
    box->setIcon(QMessageBox::Warning);
    box->setText(tr("保存成功！"));
    QPushButton *yesBtn = box->addButton(tr("确认(&Y)"), QMessageBox::YesRole);
    QPushButton *cancel = box->addButton(tr("取消"), QMessageBox::RejectRole);
    box->show();
}

void IOT_YJSZ::on_pushButton_hum_clicked()
{
    alarm_data::NSL_hum_Alarm = ui->lineEdit_hum->text();
    ui->lineEdit_hum->setText(alarm_data::NSL_hum_Alarm);
    this->Save_MessageBox();
}

void IOT_YJSZ::on_pushButton_pre_clicked()
{
    alarm_data::NSL_pre_Alarm = ui->lineEdit_pre->text();
    ui->lineEdit_pre->setText(alarm_data::NSL_pre_Alarm);
    this->Save_MessageBox();
}

void IOT_YJSZ::on_pushButton_1_x_clicked()
{
    alarm_data::YSBT_1_X_Alarm = ui->lineEdit_1_x->text();
    ui->lineEdit_1_x->setText(alarm_data::YSBT_1_X_Alarm);
    this->Save_MessageBox();
}

void IOT_YJSZ::on_pushButton_1_y_clicked()
{
    alarm_data::YSBT_1_Y_Alarm = ui->lineEdit_1_y->text();
    ui->lineEdit_1_y->setText(alarm_data::YSBT_1_Y_Alarm);
    this->Save_MessageBox();
}

void IOT_YJSZ::on_pushButton_1_z_clicked()
{
    alarm_data::YSBT_1_Z_Alarm = ui->lineEdit_1_z->text();
    ui->lineEdit_1_z->setText(alarm_data::YSBT_1_Z_Alarm);
    this->Save_MessageBox();
}
/*
void IOT_YJSZ::on_pushButton_2_x_clicked()
{
    alarm_data::YSBT_2_X_Alarm = ui->lineEdit_2_x->text();
    ui->lineEdit_2_x->setText(alarm_data::YSBT_2_X_Alarm);
}

void IOT_YJSZ::on_pushButton_2_y_clicked()
{
    alarm_data::YSBT_2_Y_Alarm = ui->lineEdit_2_y->text();
    ui->lineEdit_2_y->setText(alarm_data::YSBT_2_Y_Alarm);
}

void IOT_YJSZ::on_pushButton_2_z_clicked()
{
    alarm_data::YSBT_2_Z_Alarm = ui->lineEdit_2_z->text();
    ui->lineEdit_2_z->setText(alarm_data::YSBT_2_Z_Alarm);
}*/


void IOT_YJSZ::on_pushButton_x_clicked()
{
    alarm_data::STHP_X_Alarm = ui->lineEdit_x->text();
    ui->lineEdit_x->setText(alarm_data::STHP_X_Alarm);
    this->Save_MessageBox();
}

void IOT_YJSZ::on_pushButton_y_clicked()
{
    alarm_data::STHP_Y_Alarm = ui->lineEdit_y->text();
    ui->lineEdit_y->setText(alarm_data::STHP_Y_Alarm);
    this->Save_MessageBox();
}

void IOT_YJSZ::on_pushButton_z_clicked()
{
    alarm_data::STHP_Z_Alarm = ui->lineEdit_z->text();
    ui->lineEdit_z->setText(alarm_data::STHP_Z_Alarm);
    this->Save_MessageBox();
}

void IOT_YJSZ::on_pushButton_water_clicked()
{
    alarm_data::STHP_water = ui->lineEdit_water->text();
    ui->lineEdit_water->setText(alarm_data::STHP_water);
    this->Save_MessageBox();
}
