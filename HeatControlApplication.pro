#-------------------------------------------------
#
# Project created by QtCreator 2020-10-26T10:51:40
#
#-------------------------------------------------

QT       += core gui
QT += concurrent


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += c++11
lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -std=c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network

TARGET = HeatControlApplication
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainmenu.cpp \
    heatcontrolmenu.cpp \
    fanmenuqgroupbox.cpp \
    dialog.cpp \
    configfileport.cpp\
    QxtSpanSlider.cpp \
    selftest.cpp \
    newspinbox.cpp \
    newqthread.cpp \
    timecount.cpp \
    qdoublespinboxnew.cpp \
#    tcpclient.cpp \
#    configmainmenu.cpp \
#    controlmainmenu.cpp \
    welcompage.cpp \
    realtimevaluethread.cpp \
    realtimevaluefromuart.cpp \
    realtimevaluefortcp.cpp \
    mainwindow.cpp\
    newqdoublespinbox.cpp \
    newcofigmenu.cpp \
    newqgroupbox.cpp \
    savedatathread.cpp \
    mainwindowselftest.cpp \
    mynewqthreadforself.cpp \
    selftestrunthread.cpp \
    realtimegraphic.cpp \
   qcustomplot.cpp\
    axistag.cpp \
    showgraphic.cpp \
    newselftestpage.cpp


HEADERS += \
        mainmenu.h \
    mainwindow.h\
    heatcontrolmenu.h \
    fanmenuqgroupbox.h \
    dialog.h \
    configfileport.h\
    QxtSpanSlider.h\
    QxtSpanSlider_p.h \
    selftest.h \
    newspinbox.h \
    newqthread.h \
    timecount.h \
    qdoublespinboxnew.h \
#    tcpclient.h \
#    configmainmenu.h \
#    controlmainmenu.h \
    welcompage.h \
    realtimevaluethread.h \
    realtimevaluefromuart.h \
    realtimevaluefortcp.h \
    newqdoublespinbox.h \
    newcofigmenu.h \
    newqgroupbox.h \
    savedatathread.h \
    mainwindowselftest.h \
    mynewqthreadforself.h \
    selftestrunthread.h \
    realtimegraphic.h \
    qcustomplot.h\
   axistag.h \
    showgraphic.h \
    newselftestpage.h

UI_DIR=./UI
#/ui_welcompage.h\
#./UI/ui_timecount.h\
#./UI/ui_tcpclient.h\
#./UI/ui_mainwindow.h\
#./UI/ui_mainmenu.h\
#./UI/ui_dialog.h\
#./UI/ui_controlmainmenu.h\
#./UI/ui_configmainmenu.h


FORMS += \
        ./UI/mainmenu.ui \
    ./UI/mainwindow.ui\
    ./UI/dialog.ui \
    ./UI/timecount.ui \
#    ./UI/tcpclient.ui \
#    ./UI/configmainmenu.ui \
#    ./UI/controlmainmenu.ui \
    ./UI/welcompage.ui \
    ./UI/newcofigmenu.ui \
    mainwindowselftest.ui \
    realtimegraphic.ui \
    showgraphic.ui

#    ./UI/ui_welcompage.h\
#    ./UI/ui_timecount.h\
#    ./UI/ui_tcpclient.h\
#    ./UI/ui_mainwindow.h\
#    ./UI/ui_mainmenu.h\
#    ./UI/ui_dialog.h\
#    ./UI/ui_controlmainmenu.h\
#    ./UI/ui_configmainmenu.h


QT += serialport#添加串口支持

RESOURCES += \
    res.qrc


DISTFILES +=
