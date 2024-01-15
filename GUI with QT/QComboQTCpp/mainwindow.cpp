#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(" ");
    ui->comboBox->addItem(QIcon(":/img/Img/walking.png"),"Walking");
    ui->comboBox->addItem(QIcon(":/img/Img/running.png"),"Running");
    ui->comboBox->addItem(QIcon(":/img/Img/bicycle.png"),"With Bicycle");
    ui->comboBox->addItem(QIcon(":/img/Img/car.png"),"With Car");

    for (int i = 0; i <=5; ++i) {
        ui->comboBox_2->addItem(QString::number(i)+" disc");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"First Box",ui->comboBox->currentText());
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Second Box", QString::number(ui->comboBox_2->currentIndex()) + " " + ui->comboBox_2->currentText());

}

