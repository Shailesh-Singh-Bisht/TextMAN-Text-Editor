#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <QTextEdit>

class TextArea : public QTextEdit
{
    Q_OBJECT

public:
    TextArea(QWidget *parent = nullptr);
    ~TextArea();

signals:
    void textChanged(const QString &text);

private slots:
     void onTextChanged();
};

#endif // TEXTAREA_H