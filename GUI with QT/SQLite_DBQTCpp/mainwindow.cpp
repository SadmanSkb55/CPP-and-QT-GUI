#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLDB");
    mydb.setDatabaseName("D:\SQLite\database.db");
    if(!mydb.open())
        ui->label->setText("Failed to connect DataBase");
    else
     ui->label->setText("connected to the database");

}

MainWindow::~MainWindow()
{
    delete ui;
}
