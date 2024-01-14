#ifndef AFTERLOGIN_H
#define AFTERLOGIN_H

#include <QDialog>

namespace Ui {
class AfterLogin;
}

class AfterLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AfterLogin(QWidget *parent = nullptr);
    ~AfterLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AfterLogin *ui;
};

#endif // AFTERLOGIN_H
