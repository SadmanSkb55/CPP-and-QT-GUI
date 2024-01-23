#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   //setStyleSheet("QMainWindow::title {background-color: black; border: 1px solid black;}");
    setWindowTitle("Pyro Notes");
    setWindowIcon(QIcon(":/Image/Image/Logo 1.jpg"));

    setFixedSize(640,400);
    QMovie* movie = new QMovie(":/Image/Image/Gunna.gif");
    ui->label_pic->setMovie(movie);
    movie->start();
    ui->label_pic->setFixedSize(561, 251);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    notewin=new NoteWindow(this);
    notewin->show();
    hide();
}

