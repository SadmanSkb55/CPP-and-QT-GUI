#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTableWidget>
#include<QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tablewidgetdisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::tablewidgetdisplay() {
    QTableWidget* table = new QTableWidget(this);
    table->setRowCount(4);
    table->setColumnCount(4);

    QStringList hLabels;
    hLabels << "Name" << "ID" << "Address" << "Gender";
    table->setHorizontalHeaderLabels(hLabels);

    for (int i = 0;i < table->columnCount(); i++) {
        QTableWidgetItem *item;
        for (int j = 0;j < table->rowCount(); j++) {
            item=new QTableWidgetItem;
            if(j==0){
                item->setText("Name "+QString::number(i));
            }
            if(j==1){
                item->setText("ID " +QString::number(i));
            }
            if(j==2){
                item->setText("Adress "+QString::number(i));
            }
            if(j==3){
                item->setText("Gender "+QString::number(i));
            }
            table->setItem(i,j,item);
        }
    }

    table->setAlternatingRowColors(true);



    this->setCentralWidget(table);
}
