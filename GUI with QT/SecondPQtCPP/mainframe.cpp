#include "mainframe.h"
#include "ui_mainframe.h"
#include "secondframe.h"

MainFrame::MainFrame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainFrame)
{
    ui->setupUi(this);
}

MainFrame::~MainFrame()
{
    delete ui;
}
void MainFrame::on_pushButton_clicked()
{
   Secondframe* mySecondframe = new Secondframe(this, "How you doing der?");
    mySecondframe->show();
   connect(mySecondframe, &Secondframe::dataAvailable, this, &MainFrame::onDataAvailable);

}
void MainFrame::onDataAvailable(const QString &data)
{
    ui->label->setText(data);
}
