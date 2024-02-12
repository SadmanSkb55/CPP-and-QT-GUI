#include "sketchfcompanion.h"
#include "ui_sketchfcompanion.h"

SketchFCompanion::SketchFCompanion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SketchFCompanion)
{
    ui->setupUi(this);
}

SketchFCompanion::~SketchFCompanion()
{
    delete ui;
}
