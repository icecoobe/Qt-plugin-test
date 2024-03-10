#include "dynamicwidgetplugin.h"

#include "form.h"

DynamicWidgetPlugin::DynamicWidgetPlugin()
{
}

QWidget* DynamicWidgetPlugin::createWidget(QWidget *parent)
{
    return new Form(parent);
}
