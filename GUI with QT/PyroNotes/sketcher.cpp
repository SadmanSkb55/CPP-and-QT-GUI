#include "sketcher.h"
#include "ui_sketcher.h"
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QMouseEvent>

Sketcher::Sketcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sketcher)
{
    ui->setupUi(this);

    // Create a QGraphicsScene and set it as the scene for the view
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    // Initialize currentLine to nullptr
    currentLine = nullptr;
}

Sketcher::~Sketcher()
{
    delete ui;
}

void Sketcher::mousePressEvent(QMouseEvent *event)
{
    currentLine = new QGraphicsLineItem();
    currentLine->setPen(QPen(Qt::black, 2));
    currentLine->setLine(QLineF(event->pos(), event->pos()));
    scene->addItem(currentLine);
}

void Sketcher::mouseMoveEvent(QMouseEvent *event)
{
    if (currentLine)
    {
        QLineF newLine = currentLine->line();
        newLine.setP2(event->pos());
        if (newLine.length() > 1.0)
        {
            currentLine->setLine(newLine);
        }
    }
}

void Sketcher::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    currentLine = nullptr;
}

void Sketcher::on_actionClear_triggered()
{
    scene->clear();
}
