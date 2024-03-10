QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../interfaces/WidgetInterface.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += ..

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR = ../bin

LIBS += -L../bin
LIBS += -lStaticWidgetPlugin

#win32: LIBS += -L$$PWD/../../build-plugin_demo-Desktop_x86_windows_msvc2022_pe_64bit-Debug/bin/ -lStaticWidgetPlugin

#INCLUDEPATH += $$PWD/../../build-plugin_demo-Desktop_x86_windows_msvc2022_pe_64bit-Debug/bin
#DEPENDPATH += $$PWD/../../build-plugin_demo-Desktop_x86_windows_msvc2022_pe_64bit-Debug/bin

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../build-plugin_demo-Desktop_x86_windows_msvc2022_pe_64bit-Debug/bin/StaticWidgetPlugin.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/../../build-plugin_demo-Desktop_x86_windows_msvc2022_pe_64bit-Debug/bin/libStaticWidgetPlugin.a
