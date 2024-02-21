#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include<QDebug>
#include<QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     QSqlDatabase mydb ;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
     bool connOpen(){
         mydb = QSqlDatabase::addDatabase("QSQLITE"); // Corrected driver name
         mydb.setDatabaseName("D:/SQLite/database.db"); // Corrected path using forward slashes or escaped backslashes
         if(!mydb.open()){
             qDebug()<<"Failed to connect to the database";
             return false;
         }
         else{
             qDebug()<<"Connected to the database";
             return true;
         }
     }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
