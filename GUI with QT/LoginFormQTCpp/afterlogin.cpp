#include "afterlogin.h"
#include "ui_afterlogin.h"
#include<QString>
#include<QMessageBox>
#include<regex>
#include<iostream>
#include <QRegularExpression>

using namespace std;

AfterLogin::AfterLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AfterLogin)
{
    ui->setupUi(this);
}

AfterLogin::~AfterLogin()
{
    delete ui;
}

bool isValidPhoneNumber(const QString &phoneNumber) {
    QRegularExpression phoneRegex("\\d{3}-\\d{3}-\\d{4}");
    return phoneRegex.match(phoneNumber).hasMatch();
}

bool isValidEmail(const QString &email) {
    QRegularExpression emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    return emailRegex.match(email).hasMatch();
}

void AfterLogin::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QString pnum=ui->lineEdit_2->text();
    QString Bdate=ui->lineEdit_3->text();
    QString Email=ui->lineEdit_4->text();
    QString Adds=ui->lineEdit_5->text();

    if (name.isEmpty() || pnum.isEmpty() || Bdate.isEmpty() || Email.isEmpty() || Adds.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    if (!isValidPhoneNumber(pnum)) {
        QMessageBox::warning(this, "Input Error", "Invalid phone number.");
        return;
    }

    if (!isValidEmail(Email)) {
        QMessageBox::warning(this, "Input Error", "Invalid email address.");
        return;
    }

    QString message = "Name: " + name + "\n"
                      + "Phone Number: " + pnum + "\n"
                      + "Birthdate: " + Bdate + "\n"
                      + "Email: " + Email + "\n"
                      + "Address: " + Adds;

    QMessageBox::information(this, "Data", message);

}

