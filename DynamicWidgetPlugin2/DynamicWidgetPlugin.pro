QT += widgets

TEMPLATE = lib
#DEFINES += DYNAMICWIDGETPLUGIN_LIBRARY

CONFIG += c++17 plugin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dynamicwidgetplugin.cpp \
    form.cpp

HEADERS += \
    ../interfaces/WidgetInterface.h \
    dynamicwidgetplugin.h \
    form.h

INCLUDEPATH += ..

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

# debugging
message($$_PRO_FILE_PWD_)
message($$_PRO_FILE_)
message($$PWD)
#message($$DESTDIR)
message($$TARGET)

FORMS += \
    form.ui

DISTFILES += \
    metadata.json

DESTDIR = ../bin
TARGET = DynamicWidgetPlugin2
