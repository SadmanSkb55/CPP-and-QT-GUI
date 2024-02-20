#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE"); // Corrected driver name
    mydb.setDatabaseName("D:/SQLite/database.db"); // Corrected path using forward slashes or escaped backslashes
    if(!mydb.open())
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
    if(!mydb.isOpen()){
                ui->label->setText("Failed to connect to the database");
        return;
    }
    QSqlQuery query;
    if(query.exec("SELECT *FROM Users where username='"+uname+"' and password='"+pass+"'")){
        int count;
        while(query.next()){
            count++;
        }
        if(count==1){
            ui->label->setText("Matched!!");
        }
        if(count>1){
            ui->label->setText("Duplicate!!");
        }
        if(count<1){
            ui->label->setText("Incorrect!!");
        }

    }
}

