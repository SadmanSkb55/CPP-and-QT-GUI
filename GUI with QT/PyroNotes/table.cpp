#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Table)
{
    ui->setupUi(this);
}

Table::~Table()
{
    delete ui;
}

void Table::on_actionAdd_Row_triggered()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowCount + 1);
}

void Table::on_actionAdd_Column_triggered()
{
    int columnCount = ui->tableWidget->columnCount();
    ui->tableWidget->setColumnCount(columnCount + 1);
}


void Table::on_actionDelete_Row_triggered()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow >= 0) {
        ui->tableWidget->removeRow(currentRow);
    }
}

void Table::on_actionDelete_Column_triggered()
{
    int currentColumn = ui->tableWidget->currentColumn();
    if (currentColumn >= 0) {
        ui->tableWidget->removeColumn(currentColumn);
    }
}

void Table::onCellClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);
}

