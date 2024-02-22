#include "dialogue.h"
#include "ui_dialogue.h"
#include <QMessageBox>

Dialogue::Dialogue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dialogue)
{
    ui->setupUi(this);
    MainWindow m;
    if(!m.connOpen())
        ui->statuslabel->setText("Failed to connect to the database");
    else
        ui->statuslabel->setText("Connected to the database");
}

Dialogue::~Dialogue()
{
    delete ui;
}

void Dialogue::on_pushButton_clicked()
{
    MainWindow m;

    QString ID,Name,Email,Number;

    ID=ui->ID->text();
    Name=ui->Name->text();
    Email=ui->Email->text();
    Number=ui->Number->text();

    if(!m.connOpen()){
        ui->label->setText("Failed to connect to the database");
        return;
    }

    m.connOpen();
    QSqlQuery query;
    query.prepare("Insert into Users (ID,Name,Email,Number) values ('"+ID+"','"+Name+"','"+Email+"','"+Number+"')");

    if(query.exec()){
        QMessageBox::critical(this,tr("Saved"),tr("Saved!!!!"));
        m.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),query.lastError().text());
    }
}


void Dialogue::on_pushButton_2_clicked()
{
    MainWindow m;

    QString ID,Name,Email,Number;

    ID=ui->ID->text();
    Name=ui->Name->text();
    Email=ui->Email->text();
    Number=ui->Number->text();

    if(!m.connOpen()){
        ui->label->setText("Failed to connect to the database");
        return;
    }

    m.connOpen();
    QSqlQuery query;
    query.prepare("update users set ID='"+ID+"',Name='"+Name+"',Email='"+Email+"',Number='"+Number+"' where ID='"+ID+"'");

    if(query.exec()){
        QMessageBox::critical(this,tr("Edit"),tr("Edited!!!!"));
        m.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),query.lastError().text());
    }
}


void Dialogue::on_pushButton_3_clicked()
{
    MainWindow m;

    QString ID,Name,Email,Number;

    ID=ui->ID->text();
    Name=ui->Name->text();
    Email=ui->Email->text();
    Number=ui->Number->text();

    if(!m.connOpen()){
        ui->label->setText("Failed to connect to the database");
        return;
    }

    m.connOpen();
    QSqlQuery query;
    query.prepare("Delete from users where ID='"+ID+"'");

    if(query.exec()){
        QMessageBox::critical(this,tr("Delete"),tr("Deleted!!!!"));
        m.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),query.lastError().text());
    }
}

