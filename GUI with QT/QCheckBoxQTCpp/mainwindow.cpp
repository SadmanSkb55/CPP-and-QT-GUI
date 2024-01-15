#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox_3->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked()){
        QMessageBox::information(this,"Checked","Checked!!!");
    }else
        QMessageBox::information(this,"UnChecked","UnChecked!!!");
}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1){
        QMessageBox::information(this,"Checked","Checked!!!");
    }else
        QMessageBox::information(this,"UnChecked","UnChecked!!!");
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked()){
        QMessageBox::information(this,"Are you dumb?","Yes");
    }
    else if(ui->radioButton_2->isChecked()){
        QMessageBox::information(this,"Are you dumb?","No");
    }
    else if(ui->radioButton_3->isChecked()){
        QMessageBox::information(this,"Are you dumb?","Idk");
    }
    else
       QMessageBox::information(this,"UnChecked","No Answer!!!");
}

