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



