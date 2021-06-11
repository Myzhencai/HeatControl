/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/APPO/Desktop/HeatContolApplication/mainmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainMenu_t {
    QByteArrayData data[83];
    char stringdata0[1323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainMenu_t qt_meta_stringdata_MainMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainMenu"
QT_MOC_LITERAL(1, 9, 16), // "LivePageCodeMode"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 25), // "SendAllModeinRunningFalse"
QT_MOC_LITERAL(4, 53, 29), // "SendDefualtModeinRunningFalse"
QT_MOC_LITERAL(5, 83, 12), // "ForbidenOpen"
QT_MOC_LITERAL(6, 96, 19), // "TCPLivePageCodeMode"
QT_MOC_LITERAL(7, 116, 28), // "TCPSendAllModeinRunningFalse"
QT_MOC_LITERAL(8, 145, 15), // "TCPForbidenOpen"
QT_MOC_LITERAL(9, 161, 32), // "TCPSendDefualtModeinRunningFalse"
QT_MOC_LITERAL(10, 194, 21), // "on_bgGroupFan_toggled"
QT_MOC_LITERAL(11, 216, 2), // "id"
QT_MOC_LITERAL(12, 219, 5), // "value"
QT_MOC_LITERAL(13, 225, 14), // "FanStatusCheck"
QT_MOC_LITERAL(14, 240, 16), // "FanCreatWithJson"
QT_MOC_LITERAL(15, 257, 5), // "FanID"
QT_MOC_LITERAL(16, 263, 11), // "ContectType"
QT_MOC_LITERAL(17, 275, 7), // "MaxElec"
QT_MOC_LITERAL(18, 283, 7), // "FanDucy"
QT_MOC_LITERAL(19, 291, 15), // "SetElecMaxValue"
QT_MOC_LITERAL(20, 307, 6), // "value1"
QT_MOC_LITERAL(21, 314, 12), // "SetDucyValue"
QT_MOC_LITERAL(22, 327, 22), // "on_bgGroupPump_toggled"
QT_MOC_LITERAL(23, 350, 17), // "PumpCreatWithJson"
QT_MOC_LITERAL(24, 368, 6), // "PumpID"
QT_MOC_LITERAL(25, 375, 9), // "ElecValue"
QT_MOC_LITERAL(26, 385, 15), // "PumpStatusCheck"
QT_MOC_LITERAL(27, 401, 12), // "SetPumpValue"
QT_MOC_LITERAL(28, 414, 21), // "on_bgGroupTEC_toggled"
QT_MOC_LITERAL(29, 436, 14), // "TECStatusCheck"
QT_MOC_LITERAL(30, 451, 16), // "TECCreatWithJson"
QT_MOC_LITERAL(31, 468, 5), // "TECID"
QT_MOC_LITERAL(32, 474, 8), // "ColdTemp"
QT_MOC_LITERAL(33, 483, 15), // "SetTECColdValue"
QT_MOC_LITERAL(34, 499, 15), // "SetTECHeatValue"
QT_MOC_LITERAL(35, 515, 22), // "on_bgGroupElec_toggled"
QT_MOC_LITERAL(36, 538, 15), // "ElecStatusCheck"
QT_MOC_LITERAL(37, 554, 12), // "SetElecValue"
QT_MOC_LITERAL(38, 567, 17), // "ElecCreatWithJson"
QT_MOC_LITERAL(39, 585, 6), // "ElecID"
QT_MOC_LITERAL(40, 592, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(41, 614, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(42, 645, 4), // "arg1"
QT_MOC_LITERAL(43, 650, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(44, 674, 14), // "SetFanstepComp"
QT_MOC_LITERAL(45, 689, 2), // "Id"
QT_MOC_LITERAL(46, 692, 4), // "step"
QT_MOC_LITERAL(47, 697, 13), // "SetFanminComp"
QT_MOC_LITERAL(48, 711, 3), // "min"
QT_MOC_LITERAL(49, 715, 13), // "SetFanmaxComp"
QT_MOC_LITERAL(50, 729, 3), // "max"
QT_MOC_LITERAL(51, 733, 15), // "SetPumpstepComp"
QT_MOC_LITERAL(52, 749, 14), // "SetPumpminComp"
QT_MOC_LITERAL(53, 764, 14), // "SetPumpmaxComp"
QT_MOC_LITERAL(54, 779, 14), // "SetTECstepComp"
QT_MOC_LITERAL(55, 794, 13), // "SetTECminComp"
QT_MOC_LITERAL(56, 808, 13), // "SetTECmaxComp"
QT_MOC_LITERAL(57, 822, 15), // "SetElecstepComp"
QT_MOC_LITERAL(58, 838, 14), // "SetElecminComp"
QT_MOC_LITERAL(59, 853, 14), // "SetElecmaxComp"
QT_MOC_LITERAL(60, 868, 17), // "SelfTestWithValue"
QT_MOC_LITERAL(61, 886, 14), // "SetTestRunTime"
QT_MOC_LITERAL(62, 901, 9), // "ClearMenu"
QT_MOC_LITERAL(63, 911, 12), // "SetUsefulTel"
QT_MOC_LITERAL(64, 924, 13), // "SetUsefulTwen"
QT_MOC_LITERAL(65, 938, 25), // "sendAllPageConfigwithUart"
QT_MOC_LITERAL(66, 964, 31), // "sendAllPageConfigwithTCPNetWork"
QT_MOC_LITERAL(67, 996, 28), // "RecieveRealtimeValuewithUart"
QT_MOC_LITERAL(68, 1025, 34), // "RecieveRealtimeValuewithTCPNe..."
QT_MOC_LITERAL(69, 1060, 24), // "DefaultModeRealTimeValue"
QT_MOC_LITERAL(70, 1085, 34), // "TCPNetWorkDefaultModeRealTime..."
QT_MOC_LITERAL(71, 1120, 19), // "RealTimeFanSpeedSet"
QT_MOC_LITERAL(72, 1140, 5), // "FanId"
QT_MOC_LITERAL(73, 1146, 5), // "Speed"
QT_MOC_LITERAL(74, 1152, 24), // "RealTimeNtcTempratureSet"
QT_MOC_LITERAL(75, 1177, 5), // "TECId"
QT_MOC_LITERAL(76, 1183, 11), // "Temperature"
QT_MOC_LITERAL(77, 1195, 18), // "RealTimeTECDutySet"
QT_MOC_LITERAL(78, 1214, 4), // "Duty"
QT_MOC_LITERAL(79, 1219, 29), // "TCPNetWorkRealTimeFanSpeedSet"
QT_MOC_LITERAL(80, 1249, 27), // "TCPRealTimeNtcTempratureSet"
QT_MOC_LITERAL(81, 1277, 21), // "TCPRealTimeTECDutySet"
QT_MOC_LITERAL(82, 1299, 23) // "on_pushButton_2_clicked"

    },
    "MainMenu\0LivePageCodeMode\0\0"
    "SendAllModeinRunningFalse\0"
    "SendDefualtModeinRunningFalse\0"
    "ForbidenOpen\0TCPLivePageCodeMode\0"
    "TCPSendAllModeinRunningFalse\0"
    "TCPForbidenOpen\0TCPSendDefualtModeinRunningFalse\0"
    "on_bgGroupFan_toggled\0id\0value\0"
    "FanStatusCheck\0FanCreatWithJson\0FanID\0"
    "ContectType\0MaxElec\0FanDucy\0SetElecMaxValue\0"
    "value1\0SetDucyValue\0on_bgGroupPump_toggled\0"
    "PumpCreatWithJson\0PumpID\0ElecValue\0"
    "PumpStatusCheck\0SetPumpValue\0"
    "on_bgGroupTEC_toggled\0TECStatusCheck\0"
    "TECCreatWithJson\0TECID\0ColdTemp\0"
    "SetTECColdValue\0SetTECHeatValue\0"
    "on_bgGroupElec_toggled\0ElecStatusCheck\0"
    "SetElecValue\0ElecCreatWithJson\0ElecID\0"
    "on_pushButton_clicked\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "on_pushButton_3_clicked\0SetFanstepComp\0"
    "Id\0step\0SetFanminComp\0min\0SetFanmaxComp\0"
    "max\0SetPumpstepComp\0SetPumpminComp\0"
    "SetPumpmaxComp\0SetTECstepComp\0"
    "SetTECminComp\0SetTECmaxComp\0SetElecstepComp\0"
    "SetElecminComp\0SetElecmaxComp\0"
    "SelfTestWithValue\0SetTestRunTime\0"
    "ClearMenu\0SetUsefulTel\0SetUsefulTwen\0"
    "sendAllPageConfigwithUart\0"
    "sendAllPageConfigwithTCPNetWork\0"
    "RecieveRealtimeValuewithUart\0"
    "RecieveRealtimeValuewithTCPNetWork\0"
    "DefaultModeRealTimeValue\0"
    "TCPNetWorkDefaultModeRealTimeValue\0"
    "RealTimeFanSpeedSet\0FanId\0Speed\0"
    "RealTimeNtcTempratureSet\0TECId\0"
    "Temperature\0RealTimeTECDutySet\0Duty\0"
    "TCPNetWorkRealTimeFanSpeedSet\0"
    "TCPRealTimeNtcTempratureSet\0"
    "TCPRealTimeTECDutySet\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      59,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  309,    2, 0x06 /* Public */,
       3,    0,  310,    2, 0x06 /* Public */,
       4,    0,  311,    2, 0x06 /* Public */,
       5,    0,  312,    2, 0x06 /* Public */,
       6,    0,  313,    2, 0x06 /* Public */,
       7,    0,  314,    2, 0x06 /* Public */,
       8,    0,  315,    2, 0x06 /* Public */,
       9,    0,  316,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,  317,    2, 0x08 /* Private */,
      13,    0,  322,    2, 0x08 /* Private */,
      14,    4,  323,    2, 0x08 /* Private */,
      19,    2,  332,    2, 0x08 /* Private */,
      21,    2,  337,    2, 0x08 /* Private */,
      22,    2,  342,    2, 0x08 /* Private */,
      23,    2,  347,    2, 0x08 /* Private */,
      26,    0,  352,    2, 0x08 /* Private */,
      27,    2,  353,    2, 0x08 /* Private */,
      28,    2,  358,    2, 0x08 /* Private */,
      29,    0,  363,    2, 0x08 /* Private */,
      30,    2,  364,    2, 0x08 /* Private */,
      33,    2,  369,    2, 0x08 /* Private */,
      34,    2,  374,    2, 0x08 /* Private */,
      35,    2,  379,    2, 0x08 /* Private */,
      36,    0,  384,    2, 0x08 /* Private */,
      37,    2,  385,    2, 0x08 /* Private */,
      38,    2,  390,    2, 0x08 /* Private */,
      40,    0,  395,    2, 0x08 /* Private */,
      41,    1,  396,    2, 0x08 /* Private */,
      43,    0,  399,    2, 0x08 /* Private */,
      44,    2,  400,    2, 0x08 /* Private */,
      47,    2,  405,    2, 0x08 /* Private */,
      49,    2,  410,    2, 0x08 /* Private */,
      51,    2,  415,    2, 0x08 /* Private */,
      52,    2,  420,    2, 0x08 /* Private */,
      53,    2,  425,    2, 0x08 /* Private */,
      54,    2,  430,    2, 0x08 /* Private */,
      55,    2,  435,    2, 0x08 /* Private */,
      56,    2,  440,    2, 0x08 /* Private */,
      57,    2,  445,    2, 0x08 /* Private */,
      58,    2,  450,    2, 0x08 /* Private */,
      59,    2,  455,    2, 0x08 /* Private */,
      60,    1,  460,    2, 0x08 /* Private */,
      61,    1,  463,    2, 0x08 /* Private */,
      62,    0,  466,    2, 0x08 /* Private */,
      63,    0,  467,    2, 0x08 /* Private */,
      64,    0,  468,    2, 0x08 /* Private */,
      65,    0,  469,    2, 0x08 /* Private */,
      66,    0,  470,    2, 0x08 /* Private */,
      67,    1,  471,    2, 0x08 /* Private */,
      68,    1,  474,    2, 0x08 /* Private */,
      69,    0,  477,    2, 0x08 /* Private */,
      70,    0,  478,    2, 0x08 /* Private */,
      71,    2,  479,    2, 0x08 /* Private */,
      74,    2,  484,    2, 0x08 /* Private */,
      77,    2,  489,    2, 0x08 /* Private */,
      79,    2,  494,    2, 0x08 /* Private */,
      80,    2,  499,    2, 0x08 /* Private */,
      81,    2,  504,    2, 0x08 /* Private */,
      82,    0,  509,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   31,   32,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   39,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   50,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   50,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   50,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   45,   50,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   72,   73,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   75,   76,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   75,   78,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   72,   73,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   75,   76,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   75,   78,
    QMetaType::Void,

       0        // eod
};

void MainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainMenu *_t = static_cast<MainMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LivePageCodeMode(); break;
        case 1: _t->SendAllModeinRunningFalse(); break;
        case 2: _t->SendDefualtModeinRunningFalse(); break;
        case 3: _t->ForbidenOpen(); break;
        case 4: _t->TCPLivePageCodeMode(); break;
        case 5: _t->TCPSendAllModeinRunningFalse(); break;
        case 6: _t->TCPForbidenOpen(); break;
        case 7: _t->TCPSendDefualtModeinRunningFalse(); break;
        case 8: _t->on_bgGroupFan_toggled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->FanStatusCheck(); break;
        case 10: _t->FanCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 11: _t->SetElecMaxValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->SetDucyValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->on_bgGroupPump_toggled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->PumpCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->PumpStatusCheck(); break;
        case 16: _t->SetPumpValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->on_bgGroupTEC_toggled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->TECStatusCheck(); break;
        case 19: _t->TECCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->SetTECColdValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->SetTECHeatValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->on_bgGroupElec_toggled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->ElecStatusCheck(); break;
        case 24: _t->SetElecValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->ElecCreatWithJson((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->on_pushButton_clicked(); break;
        case 27: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->on_pushButton_3_clicked(); break;
        case 29: _t->SetFanstepComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 30: _t->SetFanminComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: _t->SetFanmaxComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: _t->SetPumpstepComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: _t->SetPumpminComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->SetPumpmaxComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->SetTECstepComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->SetTECminComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 37: _t->SetTECmaxComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 38: _t->SetElecstepComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->SetElecminComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 40: _t->SetElecmaxComp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: _t->SelfTestWithValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->SetTestRunTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->ClearMenu(); break;
        case 44: _t->SetUsefulTel(); break;
        case 45: _t->SetUsefulTwen(); break;
        case 46: _t->sendAllPageConfigwithUart(); break;
        case 47: _t->sendAllPageConfigwithTCPNetWork(); break;
        case 48: _t->RecieveRealtimeValuewithUart((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->RecieveRealtimeValuewithTCPNetWork((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->DefaultModeRealTimeValue(); break;
        case 51: _t->TCPNetWorkDefaultModeRealTimeValue(); break;
        case 52: _t->RealTimeFanSpeedSet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 53: _t->RealTimeNtcTempratureSet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 54: _t->RealTimeTECDutySet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 55: _t->TCPNetWorkRealTimeFanSpeedSet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 56: _t->TCPRealTimeNtcTempratureSet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 57: _t->TCPRealTimeTECDutySet((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 58: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::LivePageCodeMode)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::SendAllModeinRunningFalse)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::SendDefualtModeinRunningFalse)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::ForbidenOpen)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::TCPLivePageCodeMode)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::TCPSendAllModeinRunningFalse)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::TCPForbidenOpen)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenu::TCPSendDefualtModeinRunningFalse)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject MainMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainMenu.data,
      qt_meta_data_MainMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 59)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 59;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 59)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 59;
    }
    return _id;
}

// SIGNAL 0
void MainMenu::LivePageCodeMode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainMenu::SendAllModeinRunningFalse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainMenu::SendDefualtModeinRunningFalse()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainMenu::ForbidenOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainMenu::TCPLivePageCodeMode()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainMenu::TCPSendAllModeinRunningFalse()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainMenu::TCPForbidenOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainMenu::TCPSendDefualtModeinRunningFalse()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
