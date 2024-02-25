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

void DBMaster::connectDatabase() {
    // Connect to the SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database: " + db.lastError().text());
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
        }
    }
}

void DBMaster::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Database As", QString(), "SQLite Database (*.db)");
    if (!fileName.isEmpty()) {
        QFile::copy("currentDatabase.db", fileName);
        QMessageBox::information(this, "Success", "Database saved successfully!");
    }
}

void DBMaster::on_actionExport_As_CSV_triggered() {
    // Export database as CSV
    QString fileName = QFileDialog::getSaveFileName(this, "Save as CSV", QDir::homePath(), "CSV Files (*.csv)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file for writing.");
        return;
    }

    QTextStream out(&file);

    // Retrieve data from the database
    QSqlQuery query("SELECT * FROM contacts");
    while (query.next()) {
        QString rowData;
        for (int i = 0; i < query.record().count(); ++i) {
            rowData += query.value(i).toString();
            if (i != query.record().count() - 1) {
                rowData += ",";
            }
        }
        out << rowData << endl;
    }

    file.close();
    QMessageBox::information(this, "Success", "Database exported as CSV successfully.");
}

void DBMaster::on_actionExport_As_XLS_triggered() {
    // Export database as XLS
    QString fileName = QFileDialog::getSaveFileName(this, "Save as XLS", QDir::homePath(), "XLS Files (*.xls)");
    if (fileName.isEmpty()) return;

    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    QAxObject *workbook = excel.querySubObject("Workbooks");
    workbook->dynamicCall("Add");
    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

    // Retrieve data from the database
    QSqlQuery query("SELECT * FROM contacts");
    int row = 1;
    while (query.next()) {
        for (int i = 0; i < query.record().count(); ++i) {
            worksheet->querySubObject("Cells(int,int)", row, i + 1)->dynamicCall("SetValue(const QVariant&)", query.value(i).toString());
        }
        ++row;
    }

    workbook->dynamicCall("SaveAs(const QString&)", fileName);
    workbook->dynamicCall("Close()");
    excel.dynamicCall("Quit()");

    QMessageBox::information(this, "Success", "Database exported as XLS successfully.");
}
void DBMaster::on_actionAdd_New_table_triggered()
{
    // Add a new table to the database, prompting the user for column names
    bool ok;
    QString tableName = QInputDialog::getText(this, tr("New Table"), tr("Enter new table name:"), QLineEdit::Normal, "", &ok);
    if (ok && !tableName.isEmpty()) {
        QStringList columnNames;
        while (true) {
            QString columnName = QInputDialog::getText(this, tr("New Table"), tr("Enter column name (leave blank to finish):"), QLineEdit::Normal, "", &ok);
            if (ok) {
                if (!columnName.isEmpty())
                    columnNames << columnName;
                else
                    break;
            } else {
                break;
            }
        }

        if (!columnNames.isEmpty()) {
            QString createTableQuery = "CREATE TABLE " + tableName + " (";
            for (const QString &columnName : columnNames) {
                createTableQuery += columnName + " TEXT, ";
            }
            createTableQuery.chop(2); // Remove last ", "
            createTableQuery += ")";

            QSqlQuery query;
            if (query.exec(createTableQuery)) {
                QMessageBox::information(this, tr("Success"), tr("Table created successfully!"));
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Failed to create table:\n%1").arg(query.lastError().text()));
            }
        } else {
            QMessageBox::warning(this, tr("Warning"), tr("No column names entered. Table creation aborted."));
        }
    }
}

void DBMaster::connectDatabase() {
    // Connect to the SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database: " + db.lastError().text());
    }
}

void DBMaster::on_actionAdd_New_Row_triggered() {
    // Add a new row to the selected table
    // Example: Inserting a new row into the "contacts" table
    QSqlQuery query;
    query.prepare("INSERT INTO contacts (name, email) VALUES (:name, :email)");
    query.bindValue(":name", "John Doe");
    query.bindValue(":email", "john@example.com");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to add new row: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "New row added successfully.");
    }
}

void DBMaster::on_actionDelete_Table_triggered() {
    // Delete the selected table
    QString tableName = "contacts"; // Example table name
    QSqlQuery query;
    query.prepare("DROP TABLE IF EXISTS " + tableName);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete table: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Table deleted successfully.");
    }
}

void DBMaster::on_actionUpdate_Table_triggered() {
    // Update the selected table with changes
    // Example: Adding a new column to the "contacts" table
    QSqlQuery query;
    query.prepare("ALTER TABLE contacts ADD COLUMN age INTEGER");

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to update table: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Table updated successfully.");
    }
}

void DBMaster::on_actionDelete_Record_triggered() {
    // Delete the selected record from the table
    // Example: Deleting a record with ID 1 from the "contacts" table
    QSqlQuery query;
    query.prepare("DELETE FROM contacts WHERE id = :id");
    query.bindValue(":id", 1);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete record: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Record deleted successfully.");
    }
}

void DBMaster::on_actionUpdate_Record_triggered() {
    // Update the selected record in the table
    // Example: Updating the email of the record with ID 1 in the "contacts" table
    QSqlQuery query;
    query.prepare("UPDATE contacts SET email = :email WHERE id = :id");
    query.bindValue(":email", "new_email@example.com");
    query.bindValue(":id", 1);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to update record: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Record updated successfully.");
    }
}
