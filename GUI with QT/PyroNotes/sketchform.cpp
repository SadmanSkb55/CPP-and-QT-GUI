#include <QtWidgets>
#include "ui_sketchform.h"
#include "sketchform.h"
#include "sketchfcompanion.h"

SketchForm::SketchForm(NoteWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::SketchForm)
{
    ui->setupUi(this);
    sketchFCompanion = new SketchFCompanion;
    setCentralWidget(sketchFCompanion);
    resize(500, 500);
}



void SketchForm::on_actionPen_Color_triggered()
{
    QColor newColor = QColorDialog::getColor(sketchFCompanion->penColor());
    if (newColor.isValid())
        sketchFCompanion->setPenColor(newColor);
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
