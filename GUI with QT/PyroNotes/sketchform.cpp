#include "sketchform.h"
#include "ui_sketchform.h"

SketchForm::SketchForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SketchForm)
{
    ui->setupUi(this);
}

SketchForm::~SketchForm()
{
    delete ui;
}

void SketchForm::on_actionPen_Color_triggered()
{

}


void SketchForm::on_actionPen_Width_triggered()
{

}


void SketchForm::on_actionClear_triggered()
{

}

