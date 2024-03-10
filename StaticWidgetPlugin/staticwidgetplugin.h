#ifndef STATICWIDGETPLUGIN_H
#define STATICWIDGETPLUGIN_H

#include "interfaces/WidgetInterface.h"

class StaticWidgetPlugin : public QObject, public WidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "StaticWidgetPlugin/1.0.0" FILE "metadata.json")
    Q_INTERFACES(WidgetInterface)

public:
    StaticWidgetPlugin();
    QWidget* createWidget(QWidget *parent) override;
};

#endif // STATICWIDGETPLUGIN_H
