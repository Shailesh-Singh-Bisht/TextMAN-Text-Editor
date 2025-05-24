#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    MenuBar(QWidget *parent = nullptr);
    ~MenuBar();

    void setupMenu();

private:
    QMenu *m_fileMenu;
    QAction *m_newAction;
    QAction *m_openAction;
    QAction *m_saveAction;

signals:
    void newDocumentRequested();
    void openDocumentRequested(const QString &filePath);
    void saveDocumentRequested(const QString &filePath);

private slots:
    // No parameters as triggered signal doesn't pass any.
    void onNewDocument();
    void onOpenDocument();
    void onSaveDocument();
};

#endif 