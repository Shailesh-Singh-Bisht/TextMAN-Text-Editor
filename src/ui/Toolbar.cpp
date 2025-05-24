#include "ToolBar.h"
#include <QTextCursor>
#include <QTextCharFormat>
#include <QApplication>

ToolBar::ToolBar(QWidget *parent)
    : QToolBar(parent),
      m_fontComboBox(new QFontComboBox(this)),
      m_fontSizeComboBox(new QComboBox(this)),
      m_textColorButton(new QPushButton("Text Color", this)),
      m_boldButton(new QPushButton("B", this)),
      m_italicButton(new QPushButton("I", this)),
      m_underlineButton(new QPushButton("U", this)),
      m_alignmentComboBox(new QComboBox(this))
{
    setupToolbar();
}

ToolBar::~ToolBar()
{
    // Qt parent-child system handles cleanup; explicit deletes are not needed
}

void ToolBar::setupToolbar()
{
    addWidget(m_fontComboBox);
    m_fontSizeComboBox->addItems({"8", "10", "12", "14", "16", "18", "20", "22", "24"});
    addWidget(m_fontSizeComboBox);
    addWidget(m_textColorButton);
    addWidget(m_boldButton);
    addWidget(m_italicButton);
    addWidget(m_underlineButton);
    m_alignmentComboBox->addItems({"Left", "Center", "Right"});
    addWidget(m_alignmentComboBox);

    // Connect signals to respective slots
    connect(m_fontComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(fontChanged(QFont)));
    connect(m_fontSizeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(fontSizeChanged(int)));
    connect(m_textColorButton, SIGNAL(clicked()), this, SLOT(chooseTextColor()));
    connect(m_boldButton, SIGNAL(clicked()), this, SIGNAL(boldClicked())); // Emit signal
    connect(m_italicButton, SIGNAL(clicked()), this, SIGNAL(italicClicked())); // Emit signal
    connect(m_underlineButton, SIGNAL(clicked()), this, SIGNAL(underlineClicked())); // Emit signal
    connect(m_alignmentComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(alignmentChanged(int)));

    // Add custom styling to the toolbar
    setStyleSheet(""
                  "QToolBar {"
                  "    background-color: #2c3e50;"  // Dark background for the toolbar
                  "    border: none;"                // No border
                  "    spacing: 5px;"                // Space between widgets
                  "    padding: 5px;"                // Padding inside the toolbar
                  "}"
                  "QFontComboBox, QComboBox, QPushButton {"
                  "    background-color: #34495e;"   // Dark gray background for comboboxes and buttons
                  "    color: white;"                 // White text color
                  "    border: 1px solid #7f8c8d;"    // Border for comboboxes and buttons
                  "    border-radius: 3px;"           // Rounded corners
                  "    padding: 5px;"                 // Padding inside the comboboxes and buttons
                  "}"
                  "QPushButton:hover {"
                  "    background-color: #16a085;"    // Green background on hover for buttons
                  "}"
                  "QPushButton:pressed {"
                  "    background-color: #1abc9c;"    // Darker green when pressed
                  "}"
                  "QComboBox:hover, QFontComboBox:hover {"
                  "    background-color: #16a085;"    // Green background on hover for combo boxes
                  "}"
                  "QComboBox:editable {"
                  "    color: white;"                 // White text for editable combo boxes
                  "}"
                  "QComboBox:!editable {"
                  "    color: white;"                 // White text for non-editable combo boxes
                  "}"
                  "QComboBox:focus, QFontComboBox:focus {"
                  "    border: 2px solid #1abc9c;"     // Green border on focus
                  "}"
                  "QComboBox QAbstractItemView, QFontComboBox QAbstractItemView {"
                  "    background-color: #34495e;"    // Dark gray background for drop-downs
                  "    color: white;"                 // White text color for drop-down items
                  "}"
                  "QComboBox QAbstractItemView::item:selected {"
                  "    background-color: #16a085;"    // Green background for selected items
                  "}"
                  );
}

void ToolBar::chooseTextColor()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QTextEdit *editor = this->parent()->findChild<QTextEdit *>();
        if (editor) {
            QTextCursor cursor = editor->textCursor();
            QTextCharFormat format = cursor.charFormat();
            format.setForeground(color);
            cursor.setCharFormat(format);
            editor->setTextCursor(cursor);
        }
        emit textColorChanged(color);
    }
}

void ToolBar::toggleBold()
{
    QTextEdit *editor = this->parent()->findChild<QTextEdit *>();
    if (editor) {
        QTextCursor cursor = editor->textCursor();
        QTextCharFormat format = cursor.charFormat();
        format.setFontWeight(format.fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
        cursor.setCharFormat(format);
        editor->setTextCursor(cursor);
        emit fontWeightChanged(format.fontWeight());
    }
}

void ToolBar::toggleItalic()
{
    QTextEdit *editor = this->parent()->findChild<QTextEdit *>();
    if (editor) {
        QTextCursor cursor = editor->textCursor();
        QTextCharFormat format = cursor.charFormat();
        format.setFontItalic(!format.fontItalic());
        cursor.setCharFormat(format);
        editor->setTextCursor(cursor);
        emit fontStyleChanged(format.fontItalic(), format.fontUnderline());
    }
}

void ToolBar::toggleUnderline()
{
    QTextEdit *editor = this->parent()->findChild<QTextEdit *>();
    if (editor) {
        QTextCursor cursor = editor->textCursor();
        QTextCharFormat format = cursor.charFormat();
        format.setFontUnderline(!format.fontUnderline());
        cursor.setCharFormat(format);
        editor->setTextCursor(cursor);
        emit fontStyleChanged(format.fontItalic(), format.fontUnderline());
    }
}

void ToolBar::fontSizeChanged(int index)
{
    int size = m_fontSizeComboBox->itemText(index).toInt();  // Get the font size as integer from the combo box
    QTextEdit *editor = this->parent()->findChild<QTextEdit *>();
    if (editor) {
        QTextCursor cursor = editor->textCursor();
        QTextCharFormat format = cursor.charFormat();
        format.setFontPointSize(size);  // Set the font size
        cursor.setCharFormat(format);
        editor->setTextCursor(cursor);
    }
    emit fontSizeChangedSignal(size);  // Emit the font size signal
}

void ToolBar::alignmentChanged(int index)
{
    QTextEdit *editor = this->parent()->findChild<QTextEdit *>();
    if (editor) {
        QTextCursor cursor = editor->textCursor();
        QTextBlockFormat format = cursor.blockFormat();
        switch (index) {
            case 0: // Left alignment
                format.setAlignment(Qt::AlignLeft);
                break;
            case 1: // Center alignment
                format.setAlignment(Qt::AlignCenter);
                break;
            case 2: // Right alignment
                format.setAlignment(Qt::AlignRight);
                break;
        }
        cursor.setBlockFormat(format);
        editor->setTextCursor(cursor);
    }
    emit alignmentChangedSignal(index);
}

void ToolBar::fontChanged(const QFont &font)
{
    QTextEdit *editor = this->parent()->findChild<QTextEdit *>();
    if (editor) {
        QTextCursor cursor = editor->textCursor();
        QTextCharFormat format = cursor.charFormat();
        format.setFont(font);
        cursor.setCharFormat(format);
        editor->setTextCursor(cursor);
    }
}
