/****************************************************************************
** Meta object code from reading C++ file 'heatcontrolmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/APPO/Desktop/HeatContolApplication/heatcontrolmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'heatcontrolmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HeatControlMenu_t {
    QByteArrayData data[19];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HeatControlMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HeatControlMenu_t qt_meta_stringdata_HeatControlMenu = {
    {
QT_MOC_LITERAL(0, 0, 15), // "HeatControlMenu"
QT_MOC_LITERAL(1, 16, 12), // "SendToConfig"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "SendElecMaxValue"
QT_MOC_LITERAL(4, 47, 13), // "SendDucyValue"
QT_MOC_LITERAL(5, 61, 13), // "SendPumpValue"
QT_MOC_LITERAL(6, 75, 13), // "SendElecValue"
QT_MOC_LITERAL(7, 89, 16), // "SendTECColdValue"
QT_MOC_LITERAL(8, 106, 16), // "SendTECHeatValue"
QT_MOC_LITERAL(9, 123, 13), // "SendValueComp"
QT_MOC_LITERAL(10, 137, 22), // "FanJsonFanIDandElecMax"
QT_MOC_LITERAL(11, 160, 5), // "value"
QT_MOC_LITERAL(12, 166, 6), // "value1"
QT_MOC_LITERAL(13, 173, 19), // "FanJsonFanIDandDucy"
QT_MOC_LITERAL(14, 193, 20), // "PumpJsonFanIDandElec"
QT_MOC_LITERAL(15, 214, 19), // "TECJsonFanIDandElec"
QT_MOC_LITERAL(16, 234, 23), // "TECJsonFanIDandElecHeat"
QT_MOC_LITERAL(17, 258, 20), // "ElecJsonFanIDandElec"
QT_MOC_LITERAL(18, 279, 18) // "SendFanControlCode"

    },
    "HeatControlMenu\0SendToConfig\0\0"
    "SendElecMaxValue\0SendDucyValue\0"
    "SendPumpValue\0SendElecValue\0"
    "SendTECColdValue\0SendTECHeatValue\0"
    "SendValueComp\0FanJsonFanIDandElecMax\0"
    "value\0value1\0FanJsonFanIDandDucy\0"
    "PumpJsonFanIDandElec\0TECJsonFanIDandElec\0"
    "TECJsonFanIDandElecHeat\0ElecJsonFanIDandElec\0"
    "SendFanControlCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HeatControlMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    2,   92,    2, 0x06 /* Public */,
       4,    2,   97,    2, 0x06 /* Public */,
       5,    2,  102,    2, 0x06 /* Public */,
       6,    2,  107,    2, 0x06 /* Public */,
       7,    2,  112,    2, 0x06 /* Public */,
       8,    2,  117,    2, 0x06 /* Public */,
       9,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,  125,    2, 0x0a /* Public */,
      13,    2,  130,    2, 0x0a /* Public */,
      14,    2,  135,    2, 0x0a /* Public */,
      15,    2,  140,    2, 0x0a /* Public */,
      16,    2,  145,    2, 0x0a /* Public */,
      17,    2,  150,    2, 0x0a /* Public */,
      18,    2,  155,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void HeatControlMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HeatControlMenu *_t = static_cast<HeatControlMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendToConfig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SendElecMaxValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->SendDucyValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->SendPumpValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->SendElecValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->SendTECColdValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->SendTECHeatValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->SendValueComp((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->FanJsonFanIDandElecMax((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->FanJsonFanIDandDucy((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->PumpJsonFanIDandElec((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->TECJsonFanIDandElec((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->TECJsonFanIDandElecHeat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->ElecJsonFanIDandElec((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->SendFanControlCode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (HeatControlMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendToConfig)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (HeatControlMenu::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendElecMaxValue)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (HeatControlMenu::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendDucyValue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (HeatControlMenu::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendPumpValue)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (HeatControlMenu::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendElecValue)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (HeatControlMenu::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendTECColdValue)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (HeatControlMenu::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendTECHeatValue)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (HeatControlMenu::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeatControlMenu::SendValueComp)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject HeatControlMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HeatControlMenu.data,
      qt_meta_data_HeatControlMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HeatControlMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeatControlMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HeatControlMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HeatControlMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void HeatControlMenu::SendToConfig(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HeatControlMenu::SendElecMaxValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HeatControlMenu::SendDucyValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HeatControlMenu::SendPumpValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HeatControlMenu::SendElecValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void HeatControlMenu::SendTECColdValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void HeatControlMenu::SendTECHeatValue(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void HeatControlMenu::SendValueComp(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
