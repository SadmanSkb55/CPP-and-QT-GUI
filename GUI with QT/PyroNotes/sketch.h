// sketch.h
#ifndef SKETCH_H
#define SKETCH_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class Sketch;
}

class Sketch : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sketch(QWidget *parent = nullptr);
    ~Sketch();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Sketch *ui;
    QGraphicsScene *scene;
    QGraphicsView *graphicsView;
    QGraphicsLineItem *currentLine;
};

#endif // SKETCH_H
