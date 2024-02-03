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

