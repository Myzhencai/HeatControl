/****************************************************************************
** Meta object code from reading C++ file 'realtimevaluefromuart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/APPO/Desktop/HeatContolApplication/realtimevaluefromuart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'realtimevaluefromuart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RealtimeValueFromUart_t {
    QByteArrayData data[13];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RealtimeValueFromUart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RealtimeValueFromUart_t qt_meta_stringdata_RealtimeValueFromUart = {
    {
QT_MOC_LITERAL(0, 0, 21), // "RealtimeValueFromUart"
QT_MOC_LITERAL(1, 22, 27), // "SingleCoceModeRealTimeValue"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 24), // "DefaultModeRealTimeValue"
QT_MOC_LITERAL(4, 76, 25), // "PageCodeModeRealTimeValue"
QT_MOC_LITERAL(5, 102, 17), // "SetSingleCoceMode"
QT_MOC_LITERAL(6, 120, 15), // "SetPageCodeMode"
QT_MOC_LITERAL(7, 136, 4), // "stop"
QT_MOC_LITERAL(8, 141, 18), // "LiveSingleCoceMode"
QT_MOC_LITERAL(9, 160, 16), // "LivePageCodeMode"
QT_MOC_LITERAL(10, 177, 28), // "SingleCoceModeisRunningFalse"
QT_MOC_LITERAL(11, 206, 25), // "SendAllModeinRunningFalse"
QT_MOC_LITERAL(12, 232, 29) // "SendDefualtModeinRunningFalse"

    },
    "RealtimeValueFromUart\0SingleCoceModeRealTimeValue\0"
    "\0DefaultModeRealTimeValue\0"
    "PageCodeModeRealTimeValue\0SetSingleCoceMode\0"
    "SetPageCodeMode\0stop\0LiveSingleCoceMode\0"
    "LivePageCodeMode\0SingleCoceModeisRunningFalse\0"
    "SendAllModeinRunningFalse\0"
    "SendDefualtModeinRunningFalse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RealtimeValueFromUart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RealtimeValueFromUart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RealtimeValueFromUart *_t = static_cast<RealtimeValueFromUart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SingleCoceModeRealTimeValue(); break;
        case 1: _t->DefaultModeRealTimeValue(); break;
        case 2: _t->PageCodeModeRealTimeValue(); break;
        case 3: _t->SetSingleCoceMode(); break;
        case 4: _t->SetPageCodeMode(); break;
        case 5: _t->stop(); break;
        case 6: _t->LiveSingleCoceMode(); break;
        case 7: _t->LivePageCodeMode(); break;
        case 8: _t->SingleCoceModeisRunningFalse(); break;
        case 9: _t->SendAllModeinRunningFalse(); break;
        case 10: _t->SendDefualtModeinRunningFalse(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RealtimeValueFromUart::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RealtimeValueFromUart::SingleCoceModeRealTimeValue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RealtimeValueFromUart::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RealtimeValueFromUart::DefaultModeRealTimeValue)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RealtimeValueFromUart::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RealtimeValueFromUart::PageCodeModeRealTimeValue)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RealtimeValueFromUart::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RealtimeValueFromUart.data,
      qt_meta_data_RealtimeValueFromUart,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RealtimeValueFromUart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RealtimeValueFromUart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RealtimeValueFromUart.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RealtimeValueFromUart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void RealtimeValueFromUart::SingleCoceModeRealTimeValue()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RealtimeValueFromUart::DefaultModeRealTimeValue()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RealtimeValueFromUart::PageCodeModeRealTimeValue()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
