#include "notewindow.h"
#include "ui_notewindow.h"
#include "form.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include<QPrinter>
#include<QPrintDialog>
#include<QDialog>
#include<QDebug>
#include <QTextDocument>


NoteWindow::NoteWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NoteWindow)
{
    ui->setupUi(this);

    setWindowTitle("Pyro Notes");
    setWindowIcon(QIcon(":/Image/Image/Logo 1.jpg"));

    Form *form1 = new Form();
    ui->Home->layout()->addWidget(form1);
    Form *form2 = new Form();
    ui->tab_2->layout()->addWidget(form2);
}

NoteWindow::~NoteWindow()
{
    delete ui;
}

void NoteWindow::on_actionNew_Tab_triggered()
{
    ui->tabWidget->addTab(new Form(),QString("Tab %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}


void NoteWindow::on_actionNew_triggered()
{
    file_path = " "; // Assuming you're resetting the file_path

    int currentIndex = ui->tabWidget->currentIndex();

    // Access the widget at the current tab index
    QWidget* currentTabWidget = ui->tabWidget->widget(currentIndex);

    // Check if the widget is of type Form
    Form* currentForm = qobject_cast<Form*>(currentTabWidget);

    // If it's a Form widget, set the text of its textEdit
    if (currentForm)
    {
        currentForm->setTextEditContent(" "); // Assuming you have a function in Form to set the text
    }
}


void NoteWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open The File");
    file_path = file_name;

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(this, "File", "File is not open");
            return;
        }

        QTextStream in(&file);
        QString text = in.readAll();

        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextEditContent(text);
           // qDebug() << "Loaded text:" << text;
        }

        file.close();
    }
}


void NoteWindow::on_actionSave_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save File");
    file_path = file_name;

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::information(this, "File", "File is not open");
            return;
        }

        QTextStream out(&file);

        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            QString text = currentForm->getTextEditContent();
            out << text;
            qDebug() << "Saved text:" << text;
        }

        file.flush();
        file.close();
    }
}


void NoteWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save As");
    file_path = file_name;

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::information(this, "File", "File is not open");
            return;
        }

        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            QString text = currentForm->getTextEditContent();
            QTextStream out(&file);
            out << text;
            file.flush();
            file.close();
            qDebug() << "Saved text:" << text;
        }
    }
}


void NoteWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Choose Printer");
    QPrintDialog dialog(&printer, this);

    if(dialog.exec() == QDialog::Accepted)
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            QTextDocument document;
            document.setPlainText(currentForm->getTextEditContent());

            QPrintDialog printDialog(&printer, this);
            if (printDialog.exec() == QDialog::Accepted)
            {
                document.print(&printer);
            }
        }
    }
}


void NoteWindow::on_actionCut_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->cutText();
    }
}

void NoteWindow::on_actionCopy_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->copyText();
    }
}

void NoteWindow::on_actionPaste_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->pasteText();
    }
}

void NoteWindow::on_actionRedo_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->redoText();
    }
}

void NoteWindow::on_actionUndo_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->undoText();
    }
}



void NoteWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);

    if (ok)
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setFontTextEdit(font);
        }
    }
    else
    {
        return;
    }
}


void NoteWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if (color.isValid())
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextColor(color);
        }
    }
}

void NoteWindow::on_actionHighlighter_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if (color.isValid())
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextHighlightColor(color);
        }
    }
}

void NoteWindow::on_actionBackground_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if (color.isValid())
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextBackgroundColor(color);
        }
    }
}


void NoteWindow::on_actionAbout_PyroNote_triggered()
{
    QString About="Author : Okita\n";
    About+="Date: 25 Jan 2024\n";
    About+="Pyro Notes\n";
    About+="You can write and read with it\n";
    QMessageBox::about(this,"About PyroNotes",About);
}

