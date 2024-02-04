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
    // Create a new QGraphicsLineItem on mouse press
    currentLine = new QGraphicsLineItem();
    currentLine->setPen(QPen(Qt::black, 10));  // Set line color to black with a line width of 2
    currentLine->setLine(QLineF(event->pos(), event->pos())); // Use pos() instead of scenePos()
    scene->addItem(currentLine);
}

void Sketcher::mouseMoveEvent(QMouseEvent *event)
{
    // Update the line while the mouse is moving
    if (currentLine)
    {
        QLineF newLine = currentLine->line();
        newLine.setP2(event->pos());  // Use pos() instead of scenePos()
        currentLine->setLine(newLine);
        currentLine->setLine(QLineF(currentLine->line().p1(), event->pos()));
    }
}

void Sketcher::mouseReleaseEvent(QMouseEvent *event)
{
    // Reset currentLine to nullptr on mouse release
    Q_UNUSED(event);
    currentLine = nullptr;
}

void Sketcher::on_actionClear_triggered()
{
    // Clear the entire scene
    scene->clear();
}
