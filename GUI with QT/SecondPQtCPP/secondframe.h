#ifndef SECONDFRAME_H
#define SECONDFRAME_H

#include <QDialog>

namespace Ui {
class Secondframe;
}

class Secondframe : public QDialog
{
    Q_OBJECT

public:
    explicit Secondframe(QWidget *parent = nullptr);
    Secondframe(QWidget *parent=nullptr,QString message="default");
    ~Secondframe();

signals:
    void dataAvailable(const QString &data);

public slots:
    void on_pushButton_clicked();

private:
    Ui::Secondframe *ui;
};

#endif // SECONDFRAME_H
