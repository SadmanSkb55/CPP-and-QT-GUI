#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>
#include <QTableWidget>
#include<QHeaderView>



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

    void on_actionDelete_Row_triggered();

    void on_actionDelete_Column_triggered();

    void onCellClicked(int row, int column);

    void onRowClicked(int row);

    void onColumnClicked(int column);


    void on_actionAscending_triggered();

    void on_actionDescending_triggered();

    void on_actionAddition_triggered();

    void on_actionSubstraction_triggered();

    void on_actionMultiplication_triggered();

    void on_actionDivision_triggered();

    void performArithmeticOperation(QChar op);


private:
    Ui::Table *ui;
    QTableWidget *tableWidget;
};

#endif // TABLE_H
