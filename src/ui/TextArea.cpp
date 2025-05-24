#include "TextArea.h"
#include <QTextCursor>
#include <QTextBlockFormat>
#include <QTextCharFormat>

TextArea::TextArea(QWidget *parent)
    : QTextEdit(parent)
{
    connect(this, &QTextEdit::textChanged, this, &TextArea::onTextChanged);
}

TextArea::~TextArea()
{
}

void TextArea::onTextChanged()
{
    QString text = toPlainText();
    
    // Calculate word count
    int wordCount = text.split(QRegExp("\\s+"), QString::SkipEmptyParts).count();
    
    // Emit signal with word count as a QString
    emit textChanged(QString::number(wordCount));
    
    // Calculate character count
    int charCount = text.length();
    
    // Emit signal with character count as a QString
    emit textChanged(QString::number(charCount));
}
