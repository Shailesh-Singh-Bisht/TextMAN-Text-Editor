#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QMainWindow>
#include "DocumentManager.h"
#include "ui/MainWindow.h"

class AppController : public QObject
{
    Q_OBJECT

public:
    AppController(QApplication* app);
    ~AppController();

    void initialize();

private:
    QApplication* m_app;
    MainWindow* m_mainWindow;
    DocumentManager* m_documentManager;

private slots:
    // void handleNewDocument();
    // void handleOpenDocument();
    // void handleSaveDocument();
};

#endif // APPCONTROLLER_H