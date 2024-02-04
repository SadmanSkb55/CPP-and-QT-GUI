#include "table.h"
#include "ui_table.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>

Table::Table(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Table)
{
    ui->setupUi(this);

    QStringList vLabels;
    ui->tableWidget->setVerticalHeaderLabels(vLabels);

    QStringList hLabels;
    ui->tableWidget->setHorizontalHeaderLabels(hLabels);

    connect(ui->tableWidget->verticalHeader(), &QHeaderView::sectionClicked, this, &Table::onRowClicked);

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


void Table::onRowClicked(int row)
{
    QString newLabel = QInputDialog::getText(this, "Edit Row Label", "Enter new label:");

    if (!newLabel.isEmpty())
    {
        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(newLabel));
    }
}


void Table::onColumnClicked(int column)
{
    QString newLabel = QInputDialog::getText(this, "Edit Column Label", "Enter new label:");

    if (!newLabel.isEmpty())
    {
        ui->tableWidget->setHorizontalHeaderItem(column, new QTableWidgetItem(newLabel));
    }
}


void Table::on_actionAscending_triggered()
{
    int columnToSort = ui->tableWidget->currentColumn();
    ui->tableWidget->sortItems(columnToSort, Qt::AscendingOrder);
}


void Table::on_actionDescending_triggered()
{
    int columnToSort = ui->tableWidget->currentColumn();
    ui->tableWidget->sortItems(columnToSort, Qt::DescendingOrder);
}


void Table::performArithmeticOperation(QChar op)
{
    QTableWidgetItem* item1 = ui->tableWidget->currentItem();
    QTableWidgetItem* item2 = ui->tableWidget->item(ui->tableWidget->currentRow(), ui->tableWidget->currentColumn() + 1);

    if (!item1 || !item2) {
        QMessageBox::warning(this, "Warning", "Please select two adjacent cells for the operation.");
        return;
    }

    double value1 = item1->text().toDouble();
    double value2 = item2->text().toDouble();
    double result;

    switch (op.toLatin1()) {
    case '+':
        result = value1 + value2;
        break;
    case '-':
        result = value1 - value2;
        break;
    case '*':
        result = value1 * value2;
        break;
    case '/':
        if (value2 != 0) {
            result = value1 / value2;
        } else {
            QMessageBox::warning(this, "Warning", "Division by zero is not allowed.");
            return;
        }
        break;
    default:
        return;
    }

    ui->tableWidget->setItem(ui->tableWidget->currentRow(), ui->tableWidget->currentColumn() + 2,
                             new QTableWidgetItem(QString::number(result)));
}

void Table::on_actionAddition_triggered()
{
    performArithmeticOperation('+');
}

void Table::on_actionSubstraction_triggered()
{
    performArithmeticOperation('-');
}

void Table::on_actionMultiplication_triggered()
{
    performArithmeticOperation('*');
}

void Table::on_actionDivision_triggered()
{
    performArithmeticOperation('/');
}

