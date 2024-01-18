#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->tab->layout()->replaceWidget(ui->tab,new Form());

    // Form *form2 = new Form();
    // ui->tab_2->layout()->replaceWidget(ui->tab_2, form2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->addTab(new Form(),QString("Tab %0").arg(ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

