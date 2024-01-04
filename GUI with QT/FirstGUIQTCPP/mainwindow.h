#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_btnAdd_clicked();
    void on_btnSubs_clicked();
    void on_btnMul_clicked();
    void on_btnDiv_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
