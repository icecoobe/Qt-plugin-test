#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPluginLoader>
#include <QDir>
#include <QHBoxLayout>

#include "interfaces/WidgetInterface.h"

#include <QtPlugin>
Q_IMPORT_PLUGIN(StaticWidgetPlugin)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto layout = new QHBoxLayout();
    ui->centralwidget->setLayout(layout);
    QDir pluginsDir = QApplication::applicationDirPath() + "\\plugins";// = QDir.current();
    foreach(QString fileName, pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if(plugin)
        {
            qDebug() << plugin->metaObject()->className();
            m_plugin = qobject_cast<WidgetInterface *>(plugin);
            if(m_plugin)
            {
                layout->addWidget(m_plugin->createWidget());
            }
        }

        qDebug() << pluginLoader.metaData()["IID"].toString();
        foreach(QString key, pluginLoader.metaData().keys())
        {
            qDebug() << key;
        }
    }

    loadStaticPlugin();
    if (staticPlugin_)
    {
        layout->addWidget(staticPlugin_->createWidget());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loadStaticPlugin()
{
    bool ret = false;
    for(int index = 0; index < QPluginLoader::staticInstances().size(); index++)
    {
        QObject *pStaticPlugin = QPluginLoader::staticInstances().at(index);
        staticPlugin_ = qobject_cast<WidgetInterface *>(pStaticPlugin);
        if (staticPlugin_)
        {
            qDebug() << __FILE__ << __LINE__ << "Succeed to load StaticInterface:" << pStaticPlugin->metaObject()->className();
            ret = true;
        }
    }
    if(!ret)
    {
        qDebug() << __FILE__ << __LINE__ << "Failed to load StaticInterface";
        return false;
    }
    return true;
}
