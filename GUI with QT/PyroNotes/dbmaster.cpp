#include "dbmaster.h"
#include "ui_dbmaster.h"

DBMaster::DBMaster(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DBMaster)
{
    ui->setupUi(this);
}

DBMaster::~DBMaster()
{
    delete ui;
}

void DBMaster::on_actionOpen_triggered()
{

}


void DBMaster::on_actionSave_triggered()
{

}


void DBMaster::on_actionExport_As_CSV_triggered()
{

}


void DBMaster::on_actionExport_As_XLS_triggered()
{

}


void DBMaster::on_actionAdd_New_table_triggered()
{

}


void DBMaster::on_actionAdd_New_Row_triggered()
{

}


void DBMaster::on_actionDelete_Table_triggered()
{

}


void DBMaster::on_actionUpdate_Table_triggered()
{

}


void DBMaster::on_actionDelete_Record_triggered()
{

}


void DBMaster::on_actionUpdate_Record_triggered()
{

}

