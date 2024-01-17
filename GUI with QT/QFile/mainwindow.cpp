#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>

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

void MainWindow::on_pushButton_clicked()//write
{
    QFile file("D:\\QTGUICPP\\QTCPPProjects\\QFile\\TextA.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"File","File is not open");
    }
    QTextStream out(&file);
    QString text=ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_pushButton_2_clicked()//read
{
    QString filter="All File(*.*);;Text File(*.txt);;XML File(*.xml)";
     QString fileName=QFileDialog::getOpenFileName(this,"Open A File",QDir::homePath(),filter);
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"File","File is not open");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->plainTextEdit->setPlainText(text);
   // file.flush();
    file.close();
}

