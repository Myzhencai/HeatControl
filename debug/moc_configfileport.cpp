/****************************************************************************
** Meta object code from reading C++ file 'configfileport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/APPO/Desktop/HeatContolApplication/configfileport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configfileport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfigFilePort_t {
    QByteArrayData data[16];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigFilePort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigFilePort_t qt_meta_stringdata_ConfigFilePort = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ConfigFilePort"
QT_MOC_LITERAL(1, 15, 16), // "FanCreatWithJson"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "PumpCreatWithJson"
QT_MOC_LITERAL(4, 51, 16), // "TECCreatWithJson"
QT_MOC_LITERAL(5, 68, 8), // "ClearAll"
QT_MOC_LITERAL(6, 77, 13), // "SetUsefulTwen"
QT_MOC_LITERAL(7, 91, 12), // "SetUsefulTel"
QT_MOC_LITERAL(8, 104, 17), // "ElecCreatWithJson"
QT_MOC_LITERAL(9, 122, 8), // "OpenFile"
QT_MOC_LITERAL(10, 131, 8), // "SaveFile"
QT_MOC_LITERAL(11, 140, 10), // "SaveFileAs"
QT_MOC_LITERAL(12, 151, 27), // "SetIsCurrentContentModefied"
QT_MOC_LITERAL(13, 179, 10), // "closeEvent"
QT_MOC_LITERAL(14, 190, 12), // "QCloseEvent*"
QT_MOC_LITERAL(15, 203, 5) // "event"

    },
    "ConfigFilePort\0FanCreatWithJson\0\0"
    "PumpCreatWithJson\0TECCreatWithJson\0"
    "ClearAll\0SetUsefulTwen\0SetUsefulTel\0"
    "ElecCreatWithJson\0OpenFile\0SaveFile\0"
    "SaveFileAs\0SetIsCurrentContentModefied\0"
    "closeEvent\0QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigFilePort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   74,    2, 0x06 /* Public */,
       3,    2,   83,    2, 0x06 /* Public */,
       4,    2,   88,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,
       6,    0,   94,    2, 0x06 /* Public */,
       7,    0,   95,    2, 0x06 /* Public */,
       8,    2,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void ConfigFilePort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigFilePort *_t = static_cast<ConfigFilePort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->FanCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->PumpCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->TECCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->ClearAll(); break;
        case 4: _t->SetUsefulTwen(); break;
        case 5: _t->SetUsefulTel(); break;
        case 6: _t->ElecCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->OpenFile(); break;
        case 8: _t->SaveFile(); break;
        case 9: _t->SaveFileAs(); break;
        case 10: _t->SetIsCurrentContentModefied(); break;
        case 11: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ConfigFilePort::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigFilePort::FanCreatWithJson)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ConfigFilePort::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigFilePort::PumpCreatWithJson)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ConfigFilePort::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigFilePort::TECCreatWithJson)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ConfigFilePort::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigFilePort::ClearAll)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ConfigFilePort::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigFilePort::SetUsefulTwen)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ConfigFilePort::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigFilePort::SetUsefulTel)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ConfigFilePort::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigFilePort::ElecCreatWithJson)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject ConfigFilePort::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ConfigFilePort.data,
      qt_meta_data_ConfigFilePort,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConfigFilePort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigFilePort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigFilePort.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ConfigFilePort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ConfigFilePort::FanCreatWithJson(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConfigFilePort::PumpCreatWithJson(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ConfigFilePort::TECCreatWithJson(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ConfigFilePort::ClearAll()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ConfigFilePort::SetUsefulTwen()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ConfigFilePort::SetUsefulTel()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ConfigFilePort::ElecCreatWithJson(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
