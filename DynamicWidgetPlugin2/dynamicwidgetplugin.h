#ifndef DYNAMICWIDGETPLUGIN_H
#define DYNAMICWIDGETPLUGIN_H

//#include "DynamicWidgetPlugin_global.h"

#include "interfaces/WidgetInterface.h"

class DynamicWidgetPlugin : public QObject, public WidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "DynamicWidgetPlugin/1.0.0" FILE "metadata.json")
    Q_INTERFACES(WidgetInterface)

public:
    DynamicWidgetPlugin();
    QWidget* createWidget(QWidget *parent);
};

#endif // DYNAMICWIDGETPLUGIN_H
