#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogue.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!connOpen())
        ui->label->setText("Failed to connect to the database");
    else
        ui->label->setText("Connected to the database");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString pass,uname;
    uname=ui->lineEdit->text();
    pass=ui->lineEdit_2->text();
    if(!connOpen()){
                ui->label->setText("Failed to connect to the database");
        return;
    }

    connOpen();
    QSqlQuery query;
    query.prepare("SELECT *FROM Users where username='"+uname+"' and password='"+pass+"'");
    if(query.exec()){
        int count;
        while(query.next()){
            count++;
        }
        if(count==1){
            ui->label->setText("Matched!!");
            connClose();
            this->hide();
            Dialogue *d = new Dialogue(this);
            d->show();

        }
        if(count>1){
            ui->label->setText("Duplicate!!");
        }
        if(count<1){
            ui->label->setText("Incorrect!!");
        }

    }
}

