#ifndef FOOTER_H
#define FOOTER_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class Footer : public QWidget
{
    Q_OBJECT

public:
    Footer(QWidget *parent = nullptr);
    ~Footer();

    void setWordCount(int count);
    void setCharacterCount(int count);

private:
    QLabel *m_wordCountLabel;
    QLabel *m_charCountLabel;
    QHBoxLayout *m_layout;
};

#endif // FOOTER_H