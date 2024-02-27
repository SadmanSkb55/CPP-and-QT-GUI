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
#include <QStandardItemModel> // Include QStandardItemModel for handling the model

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

}


void DBMaster::on_actionExport_As_XLS_triggered()
{

}



//table manager


void DBMaster::on_actionAdd_New_table_triggered()
{

}


void DBMaster::on_actionDelete_Table_triggered()
{

}


void DBMaster::on_actionUpdate_Table_triggered()
{

}



//record manager

void DBMaster::on_actionAdd_New_Record_triggered()
{

}


void DBMaster::on_actionDelete_Record_triggered()
{

}


void DBMaster::on_actionUpdate_Record_triggered()
{

}



