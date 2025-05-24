#include "Footer.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QPalette>

Footer::Footer(QWidget *parent)
    : QWidget(parent), m_wordCountLabel(new QLabel("Words: 0")), m_charCountLabel(new QLabel("Characters: 0")), m_layout(new QHBoxLayout(this))
{
    // Set up layout
    m_layout->addWidget(m_wordCountLabel);
    m_layout->addWidget(m_charCountLabel);
    
    // Style the footer background, font, text color, and layout spacing
    setStyleSheet(""
                  "background-color: #2f4f4f;"  // Dark teal background
                  "padding: 5px;"                // Padding around the footer
                  "border-top: 2px solid #8b4513;" // Brown border at the top
                  "color: white;"                // White text color
                  "font: bold 12pt Arial;"       // Bold Arial font, size 12pt
                  "QLabel {"
                  "    margin-right: 15px;"        // Space between the two labels
                  "}");

    // Ensure both labels have the same font and color
    m_wordCountLabel->setStyleSheet("color: white; font: bold 12pt Arial;");
    m_charCountLabel->setStyleSheet("color: white; font: bold 12pt Arial;");
}

Footer::~Footer()
{
    delete m_wordCountLabel;
    delete m_charCountLabel;
    delete m_layout;
}

void Footer::setWordCount(int count)
{
    m_wordCountLabel->setText("Words: " + QString::number(count));
}

void Footer::setCharacterCount(int count)
{
    m_charCountLabel->setText("Characters: " + QString::number(count));
}
