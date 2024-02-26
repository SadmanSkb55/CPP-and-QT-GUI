#include "dbmaster.h"
#include "ui_dbmaster.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

DBMaster::DBMaster(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMaster)
{
    ui->setupUi(this);
}

DBMaster::~DBMaster()
{
    delete ui;
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
            currentDatabaseName = dbName;
        }
    }
}

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



