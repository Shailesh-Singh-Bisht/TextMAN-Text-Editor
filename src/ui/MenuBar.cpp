#include "MenuBar.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
{
    setupMenu();
    setStyleSheet(""
                  "QMenuBar {"
                  "    background-color: #333333;"  // Dark background color for the menu bar
                  "    color: #FFFFFF;"            // White text color
                  "    spacing: 3px;"              // Add some spacing between menu items
                  "}"
                  "QMenuBar::item {"
                  "    background: transparent;"
                  "    padding: 4px 10px;"         // Add padding around menu items
                  "    border: none;"              // Remove any borders
                  "}"
                  "QMenuBar::item:selected {"
                  "    background-color: #4f4f4f;"  // Lighter background on hover
                  "}"
                  "QMenu {"
                  "    background-color: #333333;"  // Dark background for the menu items
                  "    color: white;"              // White text color for menu items
                  "    border: 1px solid #555555;" // Add a subtle border to the dropdown
                  "}"
                  "QMenu::item:selected {"
                  "    background-color: #555555;"  // Light gray when menu item is selected
                  "}"
                  "QAction {"
                  "    color: white;"              // White text color for actions
                  "    background-color: transparent;" // Transparent background for actions
                  "}"
                  "QAction:hover {"
                  "    background-color: #666666;"  // Hover effect for actions
                  "}"
                  );
}

MenuBar::~MenuBar() {}

void MenuBar::setupMenu()
{
    m_fileMenu = new QMenu("File", this);

    m_newAction = new QAction("New", this);
    m_openAction = new QAction("Open", this);
    m_saveAction = new QAction("Save", this);

    m_fileMenu->addAction(m_newAction);
    m_fileMenu->addAction(m_openAction);
    m_fileMenu->addAction(m_saveAction);

    this->addMenu(m_fileMenu);

    // Connect actions to slots (no parameters expected from triggered signal)
    connect(m_newAction, &QAction::triggered, this, &MenuBar::onNewDocument);
    connect(m_openAction, &QAction::triggered, this, &MenuBar::onOpenDocument);
    connect(m_saveAction, &QAction::triggered, this, &MenuBar::onSaveDocument);
}

void MenuBar::onNewDocument()
{
    // Emitting signal to create a new document (you can define your logic)
    emit newDocumentRequested();
}

void MenuBar::onOpenDocument()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Document", QString(), "*.txt");
    if (!filePath.isEmpty()) {
        // Emit the signal with the file path
        emit openDocumentRequested(filePath);
    }
}

void MenuBar::onSaveDocument()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Document", QString(), "*.txt");
    if (!filePath.isEmpty()) {
        emit saveDocumentRequested(filePath);
    }
}
