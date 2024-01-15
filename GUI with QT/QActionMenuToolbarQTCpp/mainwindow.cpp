#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    QMessageBox::information(this,"New File","You clicked new file");
}


void MainWindow::on_actionOpen_triggered()
{
         QMessageBox::information(this,"Open File","You clicked open file");
}


void MainWindow::on_actionEdit_triggered()
{
 QMessageBox::information(this,"Edit File","You clicked edit file");
}


void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you want to exit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qApp->quit();
    } else {
       QMessageBox::information(this,"Exit","Okay,Stay");
    }
}

