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
    void setTextColor(const QColor &color);
    void setTextHighlightColor(const QColor &color);
    void setTextBackgroundColor(const QColor &color);
    void findAndHighlightText(const QString &searchText);
    void findAndReplaceText(const QString &searchText, const QString &replaceText);

private:
    Ui::Form *ui;
};

#endif // FORM_H
