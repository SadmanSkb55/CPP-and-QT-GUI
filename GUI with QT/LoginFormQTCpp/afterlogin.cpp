#include "afterlogin.h"
#include "ui_afterlogin.h"
#include<QString>
#include<QMessageBox>
#include<regex>
#include<iostream>
#include <QRegularExpression>
#include<QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>


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
       // QMessageBox msgBox;
       // msgBox.setWindowTitle("Input Error");
       // msgBox.setIcon(QMessageBox::Warning);
       // msgBox.setWindowIcon(QIcon(":/resources/Img/Sisypus.jpg"));
       // msgBox.setTextFormat(Qt::RichText);
       // msgBox.setText("Please fill in all fields.");
       // msgBox.exec();
       // // Use a QDialog to prevent the program from closing immediately
       // QDialog dialog;
       // QVBoxLayout layout(&dialog);
       // layout.addWidget(&msgBox);
       // QDialogButtonBox buttonBox(QDialogButtonBox::Ok, Qt::Horizontal, &dialog);
       // layout.addWidget(&buttonBox);
       // QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));

       // if (dialog.exec() == QDialog::Accepted) {
       //     // Continue processing if QDialog is accepted
       //     // Otherwise, the user clicked Cancel or closed the dialog
       //     return;
       // }
      return;
    }

    if (!isValidPhoneNumber(pnum)) {
        QMessageBox::warning(this, "Input Error", "Invalid phone number.");
        // QMessageBox msgBox;
        // msgBox.setIconPixmap(QPixmap(":/resources/Img/Josh.jpg"));
        // msgBox.setTextFormat(Qt::RichText);
        // msgBox.setText("Invalid Phone Number");
        // msgBox.exec();
        return;
    }

    if (!isValidEmail(Email)) {
        QMessageBox::warning(this, "Input Error", "Invalid email address.");
        // QMessageBox msgBox;
        // msgBox.setIconPixmap(QPixmap(":/resources/Img/Josh.jpg"));
        // msgBox.setTextFormat(Qt::RichText);
        // msgBox.setText("Invalid Email Adress");
        // msgBox.exec();
        return;
    }

    QString message = "Name: " + name + "\n"
                      + "Phone Number: " + pnum + "\n"
                      + "Birthdate: " + Bdate + "\n"
                      + "Email: " + Email + "\n"
                      + "Address: " + Adds;

    QMessageBox::information(this, "Data", message);

}

