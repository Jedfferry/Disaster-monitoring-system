/****************************************************************************
** Meta object code from reading C++ file 'iot_nsl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "iot_nsl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iot_nsl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IOT_NSL_t {
    QByteArrayData data[8];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IOT_NSL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IOT_NSL_t qt_meta_stringdata_IOT_NSL = {
    {
QT_MOC_LITERAL(0, 0, 7), // "IOT_NSL"
QT_MOC_LITERAL(1, 8, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(4, 54, 15), // "on_back_clicked"
QT_MOC_LITERAL(5, 70, 16), // "realtimeDataSlot"
QT_MOC_LITERAL(6, 87, 7), // "loadPre"
QT_MOC_LITERAL(7, 95, 11) // "UpdateAlarm"

    },
    "IOT_NSL\0on_startButton_clicked\0\0"
    "on_stopButton_clicked\0on_back_clicked\0"
    "realtimeDataSlot\0loadPre\0UpdateAlarm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IOT_NSL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IOT_NSL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IOT_NSL *_t = static_cast<IOT_NSL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_startButton_clicked(); break;
        case 1: _t->on_stopButton_clicked(); break;
        case 2: _t->on_back_clicked(); break;
        case 3: _t->realtimeDataSlot(); break;
        case 4: _t->loadPre(); break;
        case 5: _t->UpdateAlarm(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject IOT_NSL::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IOT_NSL.data,
      qt_meta_data_IOT_NSL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IOT_NSL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IOT_NSL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IOT_NSL.stringdata0))
        return static_cast<void*>(const_cast< IOT_NSL*>(this));
    return QWidget::qt_metacast(_clname);
}

int IOT_NSL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
