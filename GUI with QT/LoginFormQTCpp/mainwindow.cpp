#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

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
    QString user=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();

    if(user=="Admin" && pass=="Admin"){
        QMessageBox::information(this,"Welcome","User Authenticated");
        hide();
        afterlogin=new AfterLogin(this);
        afterlogin->show();
        afterlogin->exec();

    }else
        QMessageBox::warning(this,"False Information","Enter Correct username and password");
}

