#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdexcept>

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

double firstnum,secondnum,result;

void MainWindow::on_btnAdd_clicked()
{
    firstnum=ui->txtFN->text().toDouble();
    secondnum=ui->txtSN->text().toDouble();
    result=firstnum+secondnum;
    ui->txtRes->setText(QString::number(result));
}
void MainWindow::on_btnSubs_clicked()
{
    firstnum=ui->txtFN->text().toDouble();
    secondnum=ui->txtSN->text().toDouble();
    result=firstnum-secondnum;
    ui->txtRes->setText(QString::number(result));
}
void MainWindow::on_btnMul_clicked()
{
    firstnum=ui->txtFN->text().toDouble();
    secondnum=ui->txtSN->text().toDouble();
    result=firstnum*secondnum;
    ui->txtRes->setText(QString::number(result));
}
void MainWindow::on_btnDiv_clicked()
{
    firstnum=ui->txtFN->text().toDouble();
    secondnum=ui->txtSN->text().toDouble();
    try
    {
        if (secondnum==0)
        {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        result = firstnum / secondnum;
        ui->txtRes->setText(QString::number(result));
    }
    catch (const std::exception &e)
    {
        ui->txtRes->setText("Error: " + QString(e.what()));
    }
}
