#include <QtWidgets>
#include "ui_sketchform.h"
#include "sketchform.h"
#include "sketchfcompanion.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QColor>


SketchForm::SketchForm(NoteWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::SketchForm)
{
    ui->setupUi(this);

    sketchFCompanion = new SketchFCompanion(this);
    setCentralWidget(sketchFCompanion);
   // resize(500, 500);
}

SketchForm::~SketchForm()
{
    delete ui;
}

void SketchForm::on_actionPen_Color_triggered()
{
   // bool ok;
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    //if(ok){
    if (color.isValid())
        sketchFCompanion->setPenColor(color);
    else
        sketchFCompanion->setPenColor(Qt::blue);
   // }
}

void SketchForm::on_actionPen_Width_triggered()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width:"),
                                        sketchFCompanion->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        sketchFCompanion->setPenWidth(newWidth);
}

void SketchForm::on_actionClear_triggered()
{
    sketchFCompanion->clearImage();
}

void SketchForm::on_actionEraser_triggered()
{
    // Ask the user for the size of the eraser
    bool ok;
    int eraserSize = QInputDialog::getInt(this, tr("Eraser Size"),
                                          tr("Select eraser size:"),
                                          sketchFCompanion->penWidth(),
                                          1, 50, 1, &ok);
    if (!ok)
        return; // User canceled

    // Set the pen color to white (or background color) for erasing
    sketchFCompanion->setPenColor(Qt::white); // Assuming you want to erase to white

    // Set the pen width to the selected eraser size
    sketchFCompanion->setPenWidth(eraserSize);
}


void SketchForm::on_actionPen_triggered()
{
    sketchFCompanion->setPenColor(Qt::black);
}

