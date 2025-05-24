#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QFontComboBox>
#include <QComboBox>
#include <QPushButton>
#include <QColorDialog>
#include <QTextEdit>

class ToolBar : public QToolBar
{
    Q_OBJECT

public:
    ToolBar(QWidget *parent = nullptr);
    ~ToolBar();

    void setupToolbar();

private:
    QFontComboBox *m_fontComboBox;
    QComboBox *m_fontSizeComboBox;
    QPushButton *m_textColorButton;
    QPushButton *m_boldButton;
    QPushButton *m_italicButton;
    QPushButton *m_underlineButton;
    QComboBox *m_alignmentComboBox;

private slots:
    void chooseTextColor();
    void toggleBold();
    void toggleItalic();
    void toggleUnderline();
    void fontSizeChanged(int size);
    void alignmentChanged(int alignment);
     void fontChanged(const QFont &font); 

signals:
    void boldClicked();   // Added signal for bold button
    void italicClicked(); // Added signal for italic button
    void underlineClicked();
    void fontChangedSignal(const QFont &font);
    void fontSizeChangedSignal(int size);
    void textColorChanged(const QColor &color);
    void fontWeightChanged(int weight);
    void fontStyleChanged(bool italic, bool underline);
    void alignmentChangedSignal(int alignment);
};

#endif // TOOLBAR_H
