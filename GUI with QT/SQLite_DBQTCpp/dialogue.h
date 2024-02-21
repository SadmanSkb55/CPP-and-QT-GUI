#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Dialogue;
}

class Dialogue : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow m;
    explicit Dialogue(QWidget *parent = nullptr);
    ~Dialogue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogue *ui;
};

#endif // DIALOGUE_H
