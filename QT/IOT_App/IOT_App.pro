#-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T22:56:57
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IOT_App
TEMPLATE = app


SOURCES += main.cpp\
        iot_app.cpp \
    iot_nsl.cpp \
    posix_qextserialport.cpp \
    qextserialbase.cpp \
    qcustomplot.cpp \
    iot_ysbt.cpp \
    iot_yjsz.cpp \
    iot_sthp.cpp \
    all_data.cpp

HEADERS  += iot_app.h \
    iot_nsl.h \
    posix_qextserialport.h \
    qextserialbase.h \
    qcustomplot.h \
    iot_ysbt.h \
    iot_yjsz.h \
    iot_sthp.h \
    all_data.h

FORMS    += iot_app.ui \
    iot_nsl.ui \
    iot_ysbt.ui \
    iot_yjsz.ui \
    iot_sthp.ui

DISTFILES += \
    IOT_App.pro.user

RESOURCES += \
    img.qrc
