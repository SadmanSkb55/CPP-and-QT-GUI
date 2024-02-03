#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QTableWidget>


namespace Ui {
class Table;
}

class Table : public QMainWindow
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private slots:
    void on_actionAdd_Row_triggered();

    void on_actionAdd_Column_triggered();

private:
    Ui::Table *ui;
    QTableWidget *tableWidget;
};

#endif // TABLE_H
