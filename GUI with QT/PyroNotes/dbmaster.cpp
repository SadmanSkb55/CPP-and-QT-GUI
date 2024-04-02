#include "dbmaster.h"
#include "ui_dbmaster.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardItemModel>
//#include <QXlsx>
//#include <QAxObject>

DBMaster::DBMaster(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMaster)
{
    ui->setupUi(this);
    tableView = ui->tableView; // Change to tableView
    model = new QStandardItemModel(this);
   // model->setEditable(true);    // Change to model
    tableView->setModel(model);
}

DBMaster::~DBMaster()
{
    delete ui;
}

void DBMaster::populateTableWidget() {
    // Clear existing contents
    model->clear(); // Change to model

    // Fetch data from the database and populate the table
    QSqlQuery query("SELECT * FROM users");
    int rowCount = 0;
    while (query.next()) {
        QList<QStandardItem*> row;
        for (int i = 0; i < query.record().count(); ++i) {
            row.append(new QStandardItem(query.value(i).toString()));
        }
        model->appendRow(row); // Change to model
        ++rowCount;
    }
}

// Implement other slots and methods


void DBMaster::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Database", QString(), "SQLite Database (*.db)");
    if (!fileName.isEmpty()) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(fileName);
        if (!db.open()) {
            QMessageBox::critical(this, "Error", "Failed to open database:\n" + db.lastError().text());
        } else {
            QMessageBox::information(this, "Success", "Database opened successfully!");
            currentDatabaseName = fileName;
            populateTableWidget(); // Populate the table widget with data from the database
        }
    }
}

void DBMaster::on_actionNew_Database_triggered()
{
    QString dbName = QFileDialog::getSaveFileName(this, "New Database", QString(), "SQLite Database (*.db)");
    if (!dbName.isEmpty()) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);
        if (!db.open()) {
            QMessageBox::critical(this, "Error", "Failed to create database:\n" + db.lastError().text());
        } else {
            QMessageBox::information(this, "Success", "New database created successfully!");

            // Prompt the user to input table schema
            bool ok;
            QString schema = QInputDialog::getText(this, tr("Create New Table"),
                                                   tr("Enter table schema (column1 type1, column2 type2, ...)"),
                                                   QLineEdit::Normal, QString(), &ok);
            if (ok && !schema.isEmpty()) {
                // Execute SQL command to create the table
                QSqlQuery query(db);
                QString createTableQuery = "CREATE TABLE IF NOT EXISTS tableName (" + schema + ")";
                if (query.exec(createTableQuery)) {
                    QMessageBox::information(this, "Success", "Table created successfully!");
                    currentDatabaseName = dbName;
                    populateTableWidget(); // Populate the table widget with data from the database
                } else {
                    QMessageBox::critical(this, "Error", "Failed to create table:\n" + query.lastError().text());
                }
            }
        }
    }
}


void DBMaster::on_actionSave_triggered()
{
    if (currentDatabaseName.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No database is currently open.");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Save Database", currentDatabaseName, "SQLite Database (*.db)");
    if (!fileName.isEmpty()) {
        if (QFile::copy(currentDatabaseName, fileName)) {
            QMessageBox::information(this, "Success", "Database saved successfully!");
            currentDatabaseName = fileName;
        } else {
            QMessageBox::critical(this, "Error", "Failed to save database.");
        }
    }
}



void DBMaster::on_actionExport_As_CSV_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export as CSV", QString(), "CSV Files (*.csv)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            QStringList headers;
            // Write headers
            for (int col = 0; col < tableView->model()->columnCount(); ++col) {
                headers << tableView->model()->headerData(col, Qt::Horizontal).toString();
            }
            stream << headers.join(",") << "\n";
            // Write data
            for (int row = 0; row < tableView->model()->rowCount(); ++row) {
                QStringList rowData;
                for (int col = 0; col < tableView->model()->columnCount(); ++col) {
                    rowData << tableView->model()->data(tableView->model()->index(row, col)).toString();
                }
                stream << rowData.join(",") << "\n";
            }
            QMessageBox::information(this, "Success", "Data exported as CSV successfully!");
            file.close();
        } else {
            QMessageBox::critical(this, "Error", "Failed to open file for writing.");
        }
    }
}


void DBMaster::on_actionExport_As_XLS_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export as Excel", QString(), "Excel Files (*.xlsx)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            // Write XMLSS headers
            stream << "<?xml version=\"1.0\"?>\n";
            stream << "<?mso-application progid=\"Excel.Sheet\"?>\n";
            stream << "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n";
            stream << "  xmlns:o=\"urn:schemas-microsoft-com:office:office\"\n";
            stream << "  xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n";
            stream << "  xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n";
            stream << "  xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n";

            // Write Worksheet
            stream << "  <Worksheet ss:Name=\"Sheet1\">\n";
            stream << "    <Table>\n";

            // Write headers
            stream << "      <Row>\n";
            for (int col = 0; col < tableView->model()->columnCount(); ++col) {
                stream << "        <Cell><Data ss:Type=\"String\">" << tableView->model()->headerData(col, Qt::Horizontal).toString() << "</Data></Cell>\n";
            }
            stream << "      </Row>\n";

            // Write data
            for (int row = 0; row < tableView->model()->rowCount(); ++row) {
                stream << "      <Row>\n";
                for (int col = 0; col < tableView->model()->columnCount(); ++col) {
                    stream << "        <Cell><Data ss:Type=\"String\">" << tableView->model()->data(tableView->model()->index(row, col)).toString() << "</Data></Cell>\n";
                }
                stream << "      </Row>\n";
            }

            // End Worksheet
            stream << "    </Table>\n";
            stream << "  </Worksheet>\n";

            // End Workbook
            stream << "</Workbook>\n";

            QMessageBox::information(this, "Success", "Data exported as Excel successfully!");
            file.close();
        } else {
            QMessageBox::critical(this, "Error", "Failed to open file for writing.");
        }
    }
}




//table manager


void DBMaster::on_actionAdd_New_table_triggered()
{
    QString tableName = QInputDialog::getText(this, tr("Create New Table"),
                                              tr("Enter table name:"), QLineEdit::Normal);
    if (!tableName.isEmpty()) {
        bool ok;
        QString schema = QInputDialog::getText(this, tr("Create New Table"),
                                               tr("Enter table schema (column1 type1, column2 type2, ...)"),
                                               QLineEdit::Normal, QString(), &ok);
        if (ok && !schema.isEmpty()) {
            QSqlQuery query;
            QString createTableQuery = "CREATE TABLE IF NOT EXISTS " + tableName + " (" + schema + ")";
            if (query.exec(createTableQuery)) {
                QMessageBox::information(this, "Success", "Table created successfully!");
            } else {
                QMessageBox::critical(this, "Error", "Failed to create table:\n" + query.lastError().text());
            }
        }
    }
}



void DBMaster::on_actionDelete_Table_triggered()
{
    QString tableName = QInputDialog::getText(this, tr("Delete Table"),
                                              tr("Enter table name to delete:"), QLineEdit::Normal);
    if (!tableName.isEmpty()) {
        int ret = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete table '" + tableName + "'?",
                                        QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes) {
            QSqlQuery query;
            QString dropTableQuery = "DROP TABLE IF EXISTS " + tableName;
            if (query.exec(dropTableQuery)) {
                QMessageBox::information(this, "Success", "Table deleted successfully!");
            } else {
                QMessageBox::critical(this, "Error", "Failed to delete table:\n" + query.lastError().text());
            }
        }
    }
}



void DBMaster::on_actionUpdate_Table_triggered()
{
    QString tableName = QInputDialog::getText(this, tr("Update Table"),
                                              tr("Enter table name to update:"), QLineEdit::Normal);
    if (!tableName.isEmpty()) {
        bool ok;
        QString newSchema = QInputDialog::getText(this, tr("Update Table"),
                                                  tr("Enter new table schema (column1 type1, column2 type2, ...)"),
                                                  QLineEdit::Normal, QString(), &ok);
        if (ok && !newSchema.isEmpty()) {
            QSqlQuery query;
            QString updateTableQuery = "ALTER TABLE " + tableName + " RENAME TO " + tableName + "_temp";
            if (query.exec(updateTableQuery)) {
                QString createTableQuery = "CREATE TABLE IF NOT EXISTS " + tableName + " (" + newSchema + ")";
                if (query.exec(createTableQuery)) {
                    QString copyDataQuery = "INSERT INTO " + tableName + " SELECT * FROM " + tableName + "_temp";
                    if (query.exec(copyDataQuery)) {
                        QString dropTempTableQuery = "DROP TABLE IF EXISTS " + tableName + "_temp";
                        if (query.exec(dropTempTableQuery)) {
                            QMessageBox::information(this, "Success", "Table updated successfully!");
                        } else {
                            QMessageBox::critical(this, "Error", "Failed to drop temporary table:\n" + query.lastError().text());
                        }
                    } else {
                        QMessageBox::critical(this, "Error", "Failed to copy data to new table:\n" + query.lastError().text());
                    }
                } else {
                    QMessageBox::critical(this, "Error", "Failed to create new table:\n" + query.lastError().text());
                }
            } else {
                QMessageBox::critical(this, "Error", "Failed to rename table:\n" + query.lastError().text());
            }
        }
    }
}




//record manager

void DBMaster::on_actionAdd_New_Record_triggered()
{
    // Assuming you have a method to retrieve column names from your model
    QStringList columnNames = getColumnNames(); // Implement this method according to your model

    // Prompt the user to enter data for each column
    QStringList rowData;
    for (const QString& columnName : columnNames) {
        QString data = QInputDialog::getText(this, tr("Enter Data"),
                                             tr("Enter data for column '%1':").arg(columnName), QLineEdit::Normal);
        rowData.append(data);
    }

    // Insert the new record into the database
    QSqlQuery query;
    QString insertQuery = "INSERT INTO your_table_name (column1, column2, ...) VALUES (:val1, :val2, ...)";
    query.prepare(insertQuery);
    for (int i = 0; i < rowData.size(); ++i) {
        query.bindValue(":val" + QString::number(i + 1), rowData.at(i));
    }
    if (query.exec()) {
        QMessageBox::information(this, "Success", "New record added successfully!");
        populateTableWidget(); // Update the table view to reflect the changes
    } else {
        QMessageBox::critical(this, "Error", "Failed to add new record:\n" + query.lastError().text());
    }
}


void DBMaster::on_actionDelete_Record_triggered()
{
    // Assuming you have a method to retrieve the primary key or a unique identifier for each record
    QString recordId = getSelectedRecordId(); // Implement this method according to your model

    int ret = QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this record?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        QSqlQuery query;
        QString deleteQuery = "DELETE FROM your_table_name WHERE primary_key_column = :id";
        query.prepare(deleteQuery);
        query.bindValue(":id", recordId);
        if (query.exec()) {
            QMessageBox::information(this, "Success", "Record deleted successfully!");
            populateTableWidget(); // Update the table view to reflect the changes
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete record:\n" + query.lastError().text());
        }
    }
}


void DBMaster::on_actionUpdate_Record_triggered()
{
    // Assuming you have a method to retrieve the primary key or a unique identifier for each record
    QString recordId = getSelectedRecordId(); // Implement this method according to your model

    // Prompt the user to input new data for the selected record
    QStringList newData;
    // You can implement this part similar to how you prompt for new data in the Add New Record function

    // Update the record in the database
    QSqlQuery query;
    QString updateQuery = "UPDATE your_table_name SET column1 = :val1, column2 = :val2, ... WHERE primary_key_column = :id";
    query.prepare(updateQuery);
    for (int i = 0; i < newData.size(); ++i) {
        query.bindValue(":val" + QString::number(i + 1), newData.at(i));
    }
    query.bindValue(":id", recordId);
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Record updated successfully!");
        populateTableWidget(); // Update the table view to reflect the changes
    } else {
        QMessageBox::critical(this, "Error", "Failed to update record:\n" + query.lastError().text());
    }
}



QStringList DBMaster::getColumnNames() {
    QStringList columnNames;
    // Retrieve column names from your model
    // For example:
    for (int col = 0; col < model->columnCount(); ++col) {
        columnNames.append(model->headerData(col, Qt::Horizontal).toString());
    }
    return columnNames;
}

QString DBMaster::getSelectedRecordId() {
    // Assuming you have a way to determine the selected record's ID
    // For example, if you have a primary key column named 'id':
    QModelIndexList selectedIndexes = tableView->selectionModel()->selectedIndexes();
    if (!selectedIndexes.isEmpty()) {
        // Assuming 'id' is the first column
        QModelIndex idIndex = selectedIndexes.at(0).sibling(selectedIndexes.at(0).row(), 0);
        return model->data(idIndex).toString();
    } else {
        return QString(); // Return an empty string if no record is selected
    }
}





