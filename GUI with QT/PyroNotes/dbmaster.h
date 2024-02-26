#ifndef DBMASTER_H
#define DBMASTER_H

#include <QMainWindow>

namespace Ui {
class DBMaster;
}

class DBMaster : public QMainWindow
{
    Q_OBJECT

public:
    explicit DBMaster(QWidget *parent = nullptr);
    ~DBMaster();

private slots:
    void on_actionOpen_triggered();

    void on_actionAdd_New_Row_triggered();

    void on_actionSave_triggered();

    void on_actionExport_As_CSV_triggered();

    void on_actionExport_As_XLS_triggered();

    void on_actionAdd_New_table_triggered();

    void on_actionDelete_Table_triggered();

    void on_actionUpdate_Table_triggered();

    void on_actionDelete_Record_triggered();

    void on_actionUpdate_Record_triggered();

    void on_actionNew_Database_triggered();

    void on_actionAdd_New_Record_triggered();

private:
    Ui::DBMaster *ui;
     QString currentDatabaseName;
};

#endif // DBMASTER_H
