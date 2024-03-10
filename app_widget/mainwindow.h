#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include "interfaces/WidgetInterface.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    WidgetInterface* m_plugin {nullptr};
    WidgetInterface* staticPlugin_ = nullptr;

    bool loadStaticPlugin();
};
#endif // MAINWINDOW_H
