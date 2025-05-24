#include "DocumentManager.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include<QDebug>

DocumentManager::DocumentManager(QObject *parent)
    : QObject(parent), m_currentFilePath("")
{
}

DocumentManager::~DocumentManager()
{
}

QString DocumentManager::getCurrentFilePath() const
{
    return m_currentFilePath;
}

void DocumentManager::newDocument()
{
    m_currentFilePath.clear();
    emit newDocumentCreated();
}

void DocumentManager::openDocument(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent = in.readAll();  // Read the entire content
        emit documentOpened(filePath, fileContent);  // Emit the signal with file content
        file.close();
    } else {
        qWarning() << "Failed to open file:" << filePath;
    }
}

void DocumentManager::saveDocument(const QString &filePath, const QString &text)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;  // Save the actual text content
        file.close();

        m_currentFilePath = filePath;
        emit documentSaved(filePath);  // Emit a signal that the document has been saved
    } else {
        QMessageBox::critical(nullptr, "Error", "Could not save the file!");
    }
}
