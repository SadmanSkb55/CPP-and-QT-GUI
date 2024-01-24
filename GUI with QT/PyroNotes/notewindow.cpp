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


void NoteWindow::on_actionNew_triggered()
{

}


void NoteWindow::on_actionOpen_triggered()
{

}


void NoteWindow::on_actionSave_triggered()
{

}


void NoteWindow::on_actionSave_As_triggered()
{

}


void NoteWindow::on_actionPrint_triggered()
{

}


void NoteWindow::on_actionCut_triggered()
{

}


void NoteWindow::on_actionCopy_triggered()
{

}


void NoteWindow::on_actionPaste_triggered()
{

}


void NoteWindow::on_actionUndo_triggered()
{

}


void NoteWindow::on_actionRedo_triggered()
{

}


void NoteWindow::on_actionFont_triggered()
{

}


void NoteWindow::on_actionColor_triggered()
{

}


void NoteWindow::on_actionHighlighter_triggered()
{

}


void NoteWindow::on_actionBackground_Color_triggered()
{

}


void NoteWindow::on_actionAbout_PyroNote_triggered()
{

}

