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

private:
    Ui::DBMaster *ui;
};

#endif // DBMASTER_H
