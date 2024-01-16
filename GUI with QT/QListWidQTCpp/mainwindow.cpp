#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *item=new QListWidgetItem(QIcon(":/img/Img/walking.png"),"walk");
    ui->listWidget->addItem(item);
    QListWidgetItem *item2=new QListWidgetItem(QIcon(":/img/Img/running.png"),"run");
    ui->listWidget->addItem(item2);
    QListWidgetItem *item3=new QListWidgetItem(QIcon(":/img/Img/bicycle.png"),"cycle");
    ui->listWidget->addItem(item3);
    QListWidgetItem *item4=new QListWidgetItem(QIcon(":/img/Img/car.png"),"car");
    ui->listWidget->addItem(item4);
   // ui->listWidget->addItems("add","ffghj");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->currentItem()->setBackground(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::white);
    QMessageBox::information(this,"Touched",ui->listWidget->currentItem()->text());
}

