#include "MainWindow.h"
#include "ui/MenuBar.h"
#include "ui/ToolBar.h"
#include "ui/TextArea.h"
#include "ui/Footer.h"
#include "DocumentManager.h" // Include DocumentManager
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCursor>
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_menuBar(new MenuBar(this)), m_toolBar(new ToolBar(this)),
      m_textArea(new TextArea(this)), m_footer(new Footer(this)), m_centralLayout(new QVBoxLayout()), m_centralWidget(new QWidget(this)),
      m_documentManager(new DocumentManager(this)) // Initialize DocumentManager
{
    setupUI();
    setupConnections(); // Initialize connections
}

MainWindow::~MainWindow()
{
    delete m_menuBar;
    delete m_toolBar;
    delete m_textArea;
    delete m_footer;
    delete m_centralLayout;
    delete m_centralWidget;
    delete m_documentManager; // Clean up DocumentManager
}

void MainWindow::setupUI()
{
    // Set up main layout and central widget
    m_centralWidget->setLayout(m_centralLayout);
    setCentralWidget(m_centralWidget);

    // Get the available screen geometry
    QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();

    // Calculate a more appropriate window size (80% of screen size)
    int width = static_cast<int>(screenGeometry.width() * 0.8);
    int height = static_cast<int>(screenGeometry.height() * 0.8);

    // Set minimum size and resize window
    this->setMinimumSize(800, 600);
    this->resize(width, height);

    // Center the window on screen
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            screenGeometry));

    // Ensure window has proper window flags
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint |
                         Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    setMenuBar(m_menuBar);
    addToolBar(m_toolBar);
    m_centralLayout->addWidget(m_textArea);
    m_centralLayout->addWidget(m_footer);

    // Apply styles to main window elements
    setStyleSheet(""
                  "QMainWindow {"
                  "    background-color: #f5f5f5;" // Light gray background for the main window
                  "    color: #333333;"            // Dark text color for the main window
                  "}"
                  "QMenuBar {"
                  "    background-color: #3e3e3e;" // Dark background for the menu bar
                  "    color: white;"              // White text color in menu bar
                  "}"
                  "QMenuBar::item:selected {"
                  "    background-color: #4f4f4f;" // Slightly lighter background on hover
                  "}"
                  "QToolBar {"
                  "    background-color: #2f4f4f;" // Dark teal background for the toolbar
                  "    border: none;"              // No border for a clean look
                  "}"
                  "QTextEdit {"
                  "    background-color: white;"        // White background for the text area
                  "    border: 1px solid #dcdcdc;"      // Light border for text area
                  "    font-family: Arial, sans-serif;" // Set font for text
                  "    font-size: 12pt;"                // Font size for text area
                  "    color: #333333;"                 // Dark text color for better readability
                  "}"
                  "QFooter {"
                  "    background-color: #2f4f4f;" // Dark teal footer
                  "    color: white;"              // White text color in the footer
                  "    font: bold 12pt Arial;"     // Bold text for the footer
                  "}"
                  "QLabel {"
                  "    font: bold 12pt Arial;" // Same font as footer
                  "    color: white;"          // White text color for labels
                  "}");

    // Style the individual components if necessary
    m_toolBar->setFloatable(false);
    m_toolBar->setMovable(false);
    m_menuBar->setNativeMenuBar(false);

    // Connect menu actions to DocumentManager
    connect(m_menuBar, &MenuBar::newDocumentRequested, m_documentManager, &DocumentManager::newDocument);
    connect(m_menuBar, &MenuBar::openDocumentRequested, m_documentManager, &DocumentManager::openDocument);
    connect(m_menuBar, &MenuBar::saveDocumentRequested, m_documentManager, [this](const QString &filePath)
            {
        QString content = m_textArea->toPlainText();  // ✅ Real content
        m_documentManager->saveDocument(filePath, content); });

    // Toolbar actions for text formatting
    connect(m_toolBar, &ToolBar::boldClicked, this, [this]()
            {
        QTextCharFormat fmt;
        fmt.setFontWeight(m_textArea->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
        m_textArea->mergeCurrentCharFormat(fmt); });

    connect(m_toolBar, &ToolBar::italicClicked, this, [this]()
            {
        QTextCharFormat fmt;
        fmt.setFontItalic(!m_textArea->fontItalic());
        m_textArea->mergeCurrentCharFormat(fmt); });

    connect(m_toolBar, &ToolBar::underlineClicked, this, [this]()
            {
        QTextCharFormat fmt;
        fmt.setFontUnderline(!m_textArea->fontUnderline());
        m_textArea->mergeCurrentCharFormat(fmt); });

    // Connect text changes for live updates
    connect(m_textArea, &QTextEdit::textChanged, this, [this]()
            {
        QString text = m_textArea->toPlainText();
        setWordCount(text.split(QRegularExpression("\\s+"), QString::SkipEmptyParts).count());
        setCharacterCount(text.length()); });
}

void MainWindow::setupConnections()
{
    // Connect DocumentManager signals to MainWindow slots
    connect(m_documentManager, &DocumentManager::newDocumentCreated, this, &MainWindow::onNewDocumentCreated);
    connect(m_documentManager, &DocumentManager::documentOpened, this, &MainWindow::onDocumentOpened);
    connect(m_documentManager, &DocumentManager::documentSaved, this, &MainWindow::onDocumentSaved);
}

void MainWindow::setDocumentText(const QString &text)
{
    m_textArea->setPlainText(text);
}

void MainWindow::setWordCount(int count)
{
    m_footer->setWordCount(count);
}

void MainWindow::setCharacterCount(int count)
{
    m_footer->setCharacterCount(count);
}

// Slot to handle opening a document
void MainWindow::onOpenDocumentRequested(const QString &filePath)
{
    m_documentManager->openDocument(filePath); // Pass the request to DocumentManager
}

// Slot to handle saving a document
void MainWindow::onSaveDocumentRequested(const QString &filePath, const QString &text)
{
    m_documentManager->saveDocument(filePath, text); // Pass the request to DocumentManager
}

// Slot when a new document is created (from DocumentManager)
void MainWindow::onNewDocumentCreated()
{
    m_textArea->clear();  // Clear the text area for a new document
    setWordCount(0);      // Reset word count
    setCharacterCount(0); // Reset character count
}

// Slot when a document is opened (from DocumentManager)
void MainWindow::onDocumentOpened(const QString &filePath, const QString &text)
{
    m_textArea->clear();
    if (!text.isEmpty())
    {
        // Clear any existing text (including the placeholder)
        m_textArea->setPlainText(text); // Set the loaded text
    }
    else
    {
        m_textArea->setPlainText("Your text is shown here..."); // Default placeholder text if empty
    }

    setWordCount(text.split(QRegularExpression("\\s+"), QString::SkipEmptyParts).count());
    setCharacterCount(text.length());
}

// Slot when a document is saved (from DocumentManager)
void MainWindow::onDocumentSaved(const QString &filePath)
{
    qDebug() << "Document saved to" << filePath; // Log or update UI after save
}
