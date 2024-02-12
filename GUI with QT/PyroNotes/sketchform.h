#ifndef SKETCHFORM_H
#define SKETCHFORM_H

#include <QMainWindow>

namespace Ui {
class SketchForm;
}

class SketchForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit SketchForm(QWidget *parent = nullptr);
    ~SketchForm();

private slots:
    void on_actionPen_Color_triggered();

    void on_actionPen_Width_triggered();

    void on_actionClear_triggered();

private:
    Ui::SketchForm *ui;
};

#endif // SKETCHFORM_H
