#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "secondwindow.h"  no need header cause we want to access main window without closing second,ssp header will be summoned at mainwindow.h

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
    // SecondWindow sw;
    // sw.setModal(true);
    // sw.exec();        By This Way,You Can not accecss main window without closing second one
    //lets do this:
    secondWindow =new SecondWindow(this);//object creation as secondwindow.h is summoned at mainW.h "this" for mainwindow
    secondWindow->show();
}

