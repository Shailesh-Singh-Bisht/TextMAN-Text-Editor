#include "AppController.h"
#include "DocumentManager.h"
#include "MainWindow.h"
#include <QApplication>

AppController::AppController(QApplication* app)
    : m_app(app), m_mainWindow(nullptr), m_documentManager(nullptr)
{
}

AppController::~AppController()
{
    delete m_mainWindow;
    delete m_documentManager;
}

void AppController::initialize()
{
    // Initialize MainWindow and DocumentManager
    m_mainWindow = new MainWindow();
    m_documentManager = new DocumentManager();

    // Connect signals and slots between MainWindow and DocumentManager
    QObject::connect(m_mainWindow, &MainWindow::newDocumentRequested, m_documentManager, &DocumentManager::newDocument);
    QObject::connect(m_mainWindow, &MainWindow::openDocumentRequested, m_documentManager, &DocumentManager::openDocument);
    QObject::connect(m_mainWindow, &MainWindow::saveDocumentRequested, m_documentManager, &DocumentManager::saveDocument);

    QObject::connect(m_documentManager, &DocumentManager::documentOpened, m_mainWindow, &MainWindow::setDocumentText);
    QObject::connect(m_documentManager, &DocumentManager::documentSaved, m_mainWindow, &MainWindow::setDocumentText);

    // Show the main window
    m_mainWindow->show();
}
