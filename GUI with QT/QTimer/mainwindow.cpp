#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    //qDebug()<<"On";
    QTime time=QTime::currentTime();
    QDate date = QDate::currentDate();
    QString timetext=time.toString("hh : mm : ss");
    if((time.second()%2)==0){
        timetext[3]=' ';
        timetext[8]=' ';
    }
    ui->label->setText(timetext);
     QString datetext = date.toString("yyyy-MM-dd");
    ui->label_2->setText(datetext);

}
