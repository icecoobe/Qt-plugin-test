#include "staticwidgetplugin.h"

#include "groupbox.h"

StaticWidgetPlugin::StaticWidgetPlugin()
{
}

QWidget *StaticWidgetPlugin::createWidget(QWidget *parent)
{
    return new GroupBox(parent);
}
