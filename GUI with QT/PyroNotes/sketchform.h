#ifndef SKETCHFORM_H
#define SKETCHFORM_H

#include "ui_sketchform.h"
#include <QList>
#include <QMainWindow>
#include "notewindow.h"

class SketchFCompanion;

class SketchForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit SketchForm(NoteWindow *parent = nullptr);
    ~SketchForm();
        //SketchForm();

private slots:
    void on_actionPen_Color_triggered();

    void on_actionPen_Width_triggered();

    void on_actionClear_triggered();
    void on_actionEraser_triggered();

    void on_actionPen_triggered();

private:
    Ui::SketchForm *ui;
    SketchFCompanion *sketchFCompanion;
};

#endif
