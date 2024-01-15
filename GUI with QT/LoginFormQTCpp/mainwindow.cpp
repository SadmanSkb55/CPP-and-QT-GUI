#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>
#include<QMovie>
#include<QTimer>
#include<QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->addPermanentWidget(ui->label_3,1);
    ui->statusbar->addPermanentWidget(ui->progressBar,1);

    //this code is for image:::::
   //  QPixmap pix("D:\\QTGUICPP\\QTCPPProjects\\LoginFormQTCpp\\toothless.jpg");
   //  int w=ui->label_pic->width();
   // int h=ui->label_pic->height();
   //  ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    //for gif,QMovie
   QMovie* movie = new QMovie(":/resources/Img/toothlessgif.gif");
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
        ui->statusbar->showMessage("Verification Complete",5000);
        ui->label_3->setText("Yatta!!!");
         simulateLoading();
        QMessageBox::information(this,"Welcome","User Authenticated");
        hide();
        // QMessageBox msgBox;
        // msgBox.setIconPixmap(QPixmap(":/resources/Img/Ryan.jpg"));
        // msgBox.setTextFormat(Qt::RichText);
        // msgBox.setText("Now go to the next page :)");
        // msgBox.exec();
        afterlogin=new AfterLogin(this);
        afterlogin->show();
        afterlogin->exec();

    }else{
         ui->statusbar->showMessage("Verification Failed",5000);
        ui->label_3->setText("Snapped!!!");
        QMessageBox::warning(this,"False Information","Enter Correct username and password");
    }
}
void MainWindow::simulateLoading()
{
    int duration = 5000; // milliseconds
    int interval = 50;   // milliseconds
    int steps = duration / interval;
    int progress = 0;
    for (int i = 0; i <= steps; ++i) {
        ui->progressBar->setValue(progress);
        progress += 100 / steps;
        QCoreApplication::processEvents();
        QThread::sleep(interval / 1000); // Sleep for 'interval' seconds
    }
    ui->progressBar->setValue(100);
}

