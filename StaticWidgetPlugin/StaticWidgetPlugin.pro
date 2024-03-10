QT += widgets

TEMPLATE = lib
#CONFIG += staticlib static plugin
CONFIG += static plugin
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    groupbox.cpp \
    staticwidgetplugin.cpp

HEADERS += \
    ../interfaces/WidgetInterface.h \
    groupbox.h \
    staticwidgetplugin.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += ..
DESTDIR = ../bin

FORMS += \
    groupbox.ui

DISTFILES += \
    metadata.json

message("sss"+ $$TARGET)
