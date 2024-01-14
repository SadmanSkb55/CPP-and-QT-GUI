#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>
#include<QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //  QPixmap pix("D:\\QTGUICPP\\QTCPPProjects\\LoginFormQTCpp\\toothless.jpg");
   //  int w=ui->label_pic->width();
   // int h=ui->label_pic->height();
   //  ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

   QMovie* movie = new QMovie("D:\\QTGUICPP\\QTCPPProjects\\LoginFormQTCpp\\toothlessgif.gif");
   ui->label_pic->setMovie(movie);
   // Start the GIF animation
   movie->start();
   // Set the size of the label to fit the GIF
   int w = movie->frameRect().width();
   int h = movie->frameRect().height();
   ui->label_pic->setFixedSize(w, h);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString pass=ui->lineEdit_2->text();

    if(user=="Admin" && pass=="Admin"){
        QMessageBox::information(this,"Welcome","User Authenticated");
        hide();
        afterlogin=new AfterLogin(this);
        afterlogin->show();
        afterlogin->exec();

    }else
        QMessageBox::warning(this,"False Information","Enter Correct username and password");
}

