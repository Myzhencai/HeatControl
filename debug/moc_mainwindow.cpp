/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/APPO/Desktop/HeatContolApplication/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata0[565];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "makeUartClientClose"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "makeUartClientOpen"
QT_MOC_LITERAL(4, 51, 30), // "RecieveRealtimeValuewithTcpNet"
QT_MOC_LITERAL(5, 82, 25), // "TCPSendSingleCodeWithUart"
QT_MOC_LITERAL(6, 108, 31), // "TCPSingleCoceModeisRunningFalse"
QT_MOC_LITERAL(7, 140, 21), // "TCPLiveSingleCoceMode"
QT_MOC_LITERAL(8, 162, 23), // "TCPSendPageCodeWithUart"
QT_MOC_LITERAL(9, 186, 22), // "TCPRealTimeFanSpeedSet"
QT_MOC_LITERAL(10, 209, 27), // "TCPRealTimeNtcTempratureSet"
QT_MOC_LITERAL(11, 237, 21), // "TCPRealTimeTECDutySet"
QT_MOC_LITERAL(12, 259, 11), // "onConnected"
QT_MOC_LITERAL(13, 271, 14), // "onDisconnected"
QT_MOC_LITERAL(14, 286, 19), // "onSocketStateChange"
QT_MOC_LITERAL(15, 306, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(16, 335, 11), // "socketState"
QT_MOC_LITERAL(17, 347, 17), // "onSocketReadyRead"
QT_MOC_LITERAL(18, 365, 23), // "on_actConnect_triggered"
QT_MOC_LITERAL(19, 389, 26), // "on_actDisconnect_triggered"
QT_MOC_LITERAL(20, 416, 21), // "on_actClear_triggered"
QT_MOC_LITERAL(21, 438, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(22, 457, 18), // "makeTcpClientClose"
QT_MOC_LITERAL(23, 476, 17), // "makeTcpClientOpen"
QT_MOC_LITERAL(24, 494, 15), // "TCPForbidenOpen"
QT_MOC_LITERAL(25, 510, 30), // "TCPSingleCoceModeRealTimeValue"
QT_MOC_LITERAL(26, 541, 23) // "on_actSendAll_triggered"

    },
    "MainWindow\0makeUartClientClose\0\0"
    "makeUartClientOpen\0RecieveRealtimeValuewithTcpNet\0"
    "TCPSendSingleCodeWithUart\0"
    "TCPSingleCoceModeisRunningFalse\0"
    "TCPLiveSingleCoceMode\0TCPSendPageCodeWithUart\0"
    "TCPRealTimeFanSpeedSet\0"
    "TCPRealTimeNtcTempratureSet\0"
    "TCPRealTimeTECDutySet\0onConnected\0"
    "onDisconnected\0onSocketStateChange\0"
    "QAbstractSocket::SocketState\0socketState\0"
    "onSocketReadyRead\0on_actConnect_triggered\0"
    "on_actDisconnect_triggered\0"
    "on_actClear_triggered\0on_btnSend_clicked\0"
    "makeTcpClientClose\0makeTcpClientOpen\0"
    "TCPForbidenOpen\0TCPSingleCoceModeRealTimeValue\0"
    "on_actSendAll_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,
       3,    1,  132,    2, 0x06 /* Public */,
       4,    1,  135,    2, 0x06 /* Public */,
       5,    0,  138,    2, 0x06 /* Public */,
       6,    0,  139,    2, 0x06 /* Public */,
       7,    0,  140,    2, 0x06 /* Public */,
       8,    0,  141,    2, 0x06 /* Public */,
       9,    2,  142,    2, 0x06 /* Public */,
      10,    2,  147,    2, 0x06 /* Public */,
      11,    2,  152,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  157,    2, 0x08 /* Private */,
      13,    0,  158,    2, 0x08 /* Private */,
      14,    1,  159,    2, 0x08 /* Private */,
      17,    0,  162,    2, 0x08 /* Private */,
      18,    0,  163,    2, 0x08 /* Private */,
      19,    0,  164,    2, 0x08 /* Private */,
      20,    0,  165,    2, 0x08 /* Private */,
      21,    0,  166,    2, 0x08 /* Private */,
      22,    1,  167,    2, 0x08 /* Private */,
      23,    1,  170,    2, 0x08 /* Private */,
      24,    0,  173,    2, 0x08 /* Private */,
      25,    0,  174,    2, 0x08 /* Private */,
      26,    0,  175,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->makeUartClientClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->makeUartClientOpen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->RecieveRealtimeValuewithTcpNet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->TCPSendSingleCodeWithUart(); break;
        case 4: _t->TCPSingleCoceModeisRunningFalse(); break;
        case 5: _t->TCPLiveSingleCoceMode(); break;
        case 6: _t->TCPSendPageCodeWithUart(); break;
        case 7: _t->TCPRealTimeFanSpeedSet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->TCPRealTimeNtcTempratureSet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->TCPRealTimeTECDutySet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->onConnected(); break;
        case 11: _t->onDisconnected(); break;
        case 12: _t->onSocketStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 13: _t->onSocketReadyRead(); break;
        case 14: _t->on_actConnect_triggered(); break;
        case 15: _t->on_actDisconnect_triggered(); break;
        case 16: _t->on_actClear_triggered(); break;
        case 17: _t->on_btnSend_clicked(); break;
        case 18: _t->makeTcpClientClose((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->makeTcpClientOpen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->TCPForbidenOpen(); break;
        case 21: _t->TCPSingleCoceModeRealTimeValue(); break;
        case 22: _t->on_actSendAll_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::makeUartClientClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::makeUartClientOpen)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::RecieveRealtimeValuewithTcpNet)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCPSendSingleCodeWithUart)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCPSingleCoceModeisRunningFalse)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCPLiveSingleCoceMode)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCPSendPageCodeWithUart)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCPRealTimeFanSpeedSet)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCPRealTimeNtcTempratureSet)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::TCPRealTimeTECDutySet)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::makeUartClientClose(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::makeUartClientOpen(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::RecieveRealtimeValuewithTcpNet(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::TCPSendSingleCodeWithUart()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::TCPSingleCoceModeisRunningFalse()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::TCPLiveSingleCoceMode()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::TCPSendPageCodeWithUart()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::TCPRealTimeFanSpeedSet(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::TCPRealTimeNtcTempratureSet(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::TCPRealTimeTECDutySet(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
