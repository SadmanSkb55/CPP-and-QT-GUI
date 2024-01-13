#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDebug>

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

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::about(this,"You Wished to Click","AIyooo,you clicked meeee!!!");
    QMessageBox::aboutQt(this,"About QT-6");
    QMessageBox::critical(this,"Critical","Its 3rd!!!");
    QMessageBox::information(this,"Information","No information");
    QMessageBox::question(this,"You have Question?","We dont");
    QMessageBox::warning(this,"Warning","Dont Click Again");
    QMessageBox::StandardButton reply=QMessageBox::question(this,"You have Question?","   ",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::No){
        QApplication::quit();
        qDebug()<<"No is clickedddd,yayyyyyy";
    }
    else{
        QMessageBox::warning(this,"F*** off","F*** offff!!!!!");
    }

}

