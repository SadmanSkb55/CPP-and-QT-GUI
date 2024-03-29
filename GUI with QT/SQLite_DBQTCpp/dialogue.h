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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_listView_activated(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Dialogue *ui;
};

#endif // DIALOGUE_H
