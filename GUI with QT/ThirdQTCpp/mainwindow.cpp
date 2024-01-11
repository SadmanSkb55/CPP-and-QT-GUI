#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QStandardPaths>
#include<filesystem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), file(path), path(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\todofile.txt")
{
    ui->setupUi(this);

    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::on_btnAdd_clicked);

    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QListWidgetItem *item = new QListWidgetItem(line);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEnabled | Qt::ItemIsEditable);
    }

    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream out(&file);

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out<<ui->listWidget->item(i)->text()<<"\n";
    }
    file.close();
}

void MainWindow::on_btnAdd_clicked()
{
    QString taskText = ui->txtTask->text();
    QListWidgetItem* item = new QListWidgetItem(taskText);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEnabled | Qt::ItemIsEditable);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
}


void MainWindow::on_btnRemove_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (item)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
    else
    {
        QMessageBox::information(this, "No Item Selected", "Please select an item to remove.");
    }
}


void MainWindow::on_btnRemoveAll_clicked()
{
    ui->listWidget->clear();
}

