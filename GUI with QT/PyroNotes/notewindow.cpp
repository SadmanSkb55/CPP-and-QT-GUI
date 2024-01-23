#include "notewindow.h"
#include "ui_notewindow.h"
#include "form.h"

NoteWindow::NoteWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NoteWindow)
{
    ui->setupUi(this);

    setWindowTitle("Pyro Notes");
    setWindowIcon(QIcon(":/Image/Image/Logo 1.jpg"));

    Form *form1 = new Form();
    ui->Home->layout()->addWidget(form1);
    Form *form2 = new Form();
    ui->tab_2->layout()->addWidget(form2);
}

NoteWindow::~NoteWindow()
{
    delete ui;
}

void NoteWindow::on_actionNew_Tab_triggered()
{
    ui->tabWidget->addTab(new Form(),QString("Tab %0").arg(ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

