#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QMainWindow>
#include <QTimer>
#include <QDialog>

namespace Ui {
class SplashScreen;
}

class SplashScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent = nullptr);
    ~SplashScreen();

private slots:
    void showMainWindow();

private:
    Ui::SplashScreen *ui;
    QTimer *timer;
};

#endif // SPLASHSCREEN_H
