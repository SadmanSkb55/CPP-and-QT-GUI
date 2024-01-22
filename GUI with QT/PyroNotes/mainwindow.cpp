#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(640,400);
    QMovie* movie = new QMovie(":/Image/Image/Gunna.gif");
    ui->label_pic->setMovie(movie);
    movie->start();
    // int w = movie->frameRect().width();
    // int h = movie->frameRect().height();
    ui->label_pic->setFixedSize(561, 251);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    secwin=new SecondWindow(this);
    secwin->show();
    hide();
}

