#ifndef SKETCHER_H
#define SKETCHER_H

#include <QMainWindow>

namespace Ui {
class Sketcher;
}

class Sketcher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sketcher(QWidget *parent = nullptr);
    ~Sketcher();

private:
    Ui::Sketcher *ui;
};

#endif // SKETCHER_H
