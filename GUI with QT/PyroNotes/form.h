#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    void setTextEditContent(const QString& content);
    QString getTextEditContent() const;
    void cutText();
    void copyText();
    void pasteText();
    void redoText();
    void undoText();
    void setFontTextEdit(const QFont &font);

private:
    Ui::Form *ui;
};

#endif // FORM_H
