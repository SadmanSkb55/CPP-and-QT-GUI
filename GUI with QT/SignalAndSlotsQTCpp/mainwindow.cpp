#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),ui->progressBar_2,SLOT(setValue(int)));
   // disconnect(ui->verticalSlider,SIGNAL(valueChanged(int)),ui->progressBar_2,SLOT(setValue(int))); works like break;

}

MainWindow::~MainWindow()
{
    delete ui;
}
