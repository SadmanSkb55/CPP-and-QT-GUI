#include "sketcher.h"
#include "ui_sketcher.h"

Sketcher::Sketcher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Sketcher)
{
    ui->setupUi(this);
}

Sketcher::~Sketcher()
{
    delete ui;
}
