#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    file_path=" ";
    ui->textEdit->setText(" ");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open The File");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"File","File is not open");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"File","File is not open");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"Open The File");
    QFile file(file_name);
     file_path=file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"File","File is not open");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString About="Author : Okita\n";
    About+="Date: 17 Jan 2024\n";
    About+="Notepad\n";
    About+="You can write and read with it\n";
    QMessageBox::about(this,"About Notepad",About);
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok){
        ui->textEdit->setFont(font);
    }else return;
}


void MainWindow::on_actionColor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }
}


void MainWindow::on_actionBackground_Color_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);
    }
}


void MainWindow::on_actionBackground_Edit_Color_Text_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose Color");
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));
    }
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Choose Printer");
    QPrintDialog dialogue(&printer,this);
    if(dialogue.exec()==QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}

