#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextEdit>
#include "ui/MenuBar.h"
#include "ui/ToolBar.h"
#include "ui/TextArea.h"
#include "ui/Footer.h"
#include "DocumentManager.h"  // Include DocumentManager

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUI();

private:
    MenuBar *m_menuBar;
    ToolBar *m_toolBar;
    TextArea *m_textArea;
    Footer *m_footer;
    QVBoxLayout *m_centralLayout;
    QWidget *m_centralWidget;
    QTextEdit *m_textEdit;

    DocumentManager *m_documentManager;  // Declare DocumentManager pointer

    void setupConnections();

signals:
    void newDocumentRequested();
    void openDocumentRequested(const QString &filePath);
    void saveDocumentRequested(const QString &filePath, const QString &text);

public slots:
    void setDocumentText(const QString& text);
    void setWordCount(int count);
    void setCharacterCount(int count);

    // Document Manager related slots
    void onOpenDocumentRequested(const QString &filePath);
    void onSaveDocumentRequested(const QString &filePath, const QString &text);
    void onNewDocumentCreated();
    void onDocumentOpened(const QString &filePath, const QString &text);
    void onDocumentSaved(const QString &filePath);
};

#endif // MAINWINDOW_H
