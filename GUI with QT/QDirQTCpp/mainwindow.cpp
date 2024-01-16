#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QDir dir("D:\\QTGUICPP\\QTCPPProjects\\QDirQTCpp\\TestFile");
    // if(dir.exists()){
    //     QMessageBox::information(this,"Directory","Exists!!!");
    // }else
    //     QMessageBox::information(this,"Directory","Not Exists!!!");
    QDir dir;
    foreach (QFileInfo var, dir.drives()) {
        ui->comboBox->addItem(var.absoluteFilePath());
    }
    QDir dir_2("D:\\QTGUICPP\\QTCPPProjects\\QDirQTCpp\\TestFile");
    foreach (QFileInfo var, dir_2.entryInfoList()) {
        if(var.isDir())
        ui->listWidget->addItem("DIR: "+var.absoluteFilePath());
        if(var.isFile())
            ui->listWidget->addItem("File: "+var.absoluteFilePath());
       // ui->listWidget->currentItem()->setBackground(Qt::red);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir("D:\\QTGUICPP\\QTCPPProjects\\QDirQTCpp\\TestFileX");
    if(dir.exists()){
        QMessageBox::information(this,"Directory","Directory Exists!!!");
    }else{
        QMessageBox::information(this,"Directory","Directory Created");
        dir.mkpath("D:\\QTGUICPP\\QTCPPProjects\\QDirQTCpp\\TestFileX");
    }
}

