#ifndef WIDGETINTERFACE_H
#define WIDGETINTERFACE_H

#include <QObject>

class QWidget;

class WidgetInterface
{
public:
    virtual ~WidgetInterface() = default;
    virtual QWidget* createWidget(QWidget* parent = nullptr) = 0;
};

#define WidgetInterface_iid "Welcome to pay attention to the public number"

Q_DECLARE_INTERFACE(WidgetInterface, WidgetInterface_iid)

#endif // WIDGETINTERFACE_H
