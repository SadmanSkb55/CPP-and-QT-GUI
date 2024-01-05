#include "secondframe.h"
#include "ui_secondframe.h"

Secondframe::Secondframe(QWidget *parent,QString message)
    : QDialog(parent)
    , ui(new Ui::Secondframe)
{
    ui->setupUi(this);
    ui->label->setText(message);

    connect(this,&Secondframe::finished,this,[this](){
        emit dataAvailable("Closing");
    });

}

Secondframe::~Secondframe()
{
    delete ui;
}
void Secondframe::on_pushButton_clicked(){
    close();
}
