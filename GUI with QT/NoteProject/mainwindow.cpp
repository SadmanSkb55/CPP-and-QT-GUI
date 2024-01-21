#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // setFixedSize(500,500);
    QMovie* movie = new QMovie(":/img/Image/Gunna.gif");
    ui->label_pic->setMovie(movie);
    movie->start();
    ui->label_pic->setFixedSize(871,371);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    secondWindow=new SecondWindow(this);
    secondWindow->show();
    secondWindow->exec();
     //close();
}

