#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <QObject>
#include <QString>

class DocumentManager : public QObject
{
    Q_OBJECT

public:
    DocumentManager(QObject *parent = nullptr);
    ~DocumentManager();

    QString getCurrentFilePath() const;
    void newDocument();
    void openDocument(const QString &filePath);
    void saveDocument(const QString &filePath, const QString &text);

private:
    QString m_currentFilePath;

signals:
    void documentOpened(const QString &filePath, const QString &text);
    void documentSaved(const QString &filePath);
    void newDocumentCreated();
};

#endif // DOCUMENTMANAGER_H
