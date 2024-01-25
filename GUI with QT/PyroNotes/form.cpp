#include "form.h"
#include "ui_form.h"
#include<QDebug>

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
void Form::setTextEditContent(const QString& content)
{
    //qDebug() << "Setting text content:" << content;
    ui->textEdit->setText(content);
    ui->textEdit->setVisible(true);
}
QString Form::getTextEditContent() const
{
    return ui->textEdit->toPlainText();
}
void Form::cutText()
{
    ui->textEdit->cut();
}

void Form::copyText()
{
    ui->textEdit->copy();
}

void Form::pasteText()
{
    ui->textEdit->paste();
}

void Form::redoText()
{
    ui->textEdit->redo();
}

void Form::undoText()
{
    ui->textEdit->undo();
}
void Form::setFontTextEdit(const QFont &font)
{
    ui->textEdit->setFont(font);
}
void Form::setTextColor(const QColor &color)
{
    ui->textEdit->setTextColor(color);
}

void Form::setTextHighlightColor(const QColor &color)
{
    ui->textEdit->setTextBackgroundColor(color);
}

void Form::setTextBackgroundColor(const QColor &color)
{
    ui->textEdit->setPalette(QPalette(color));
}
