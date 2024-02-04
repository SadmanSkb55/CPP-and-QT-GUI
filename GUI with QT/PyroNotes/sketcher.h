#ifndef SKETCHER_H
#define SKETCHER_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QMouseEvent>  // Include QMouseEvent for the correct type

namespace Ui {
class Sketcher;
}

class Sketcher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sketcher(QWidget *parent = nullptr);
    ~Sketcher();

protected:
    // Replace QGraphicsSceneMouseEvent with QMouseEvent
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_actionClear_triggered();

private:
    Ui::Sketcher *ui;
    QGraphicsScene *scene;
    QGraphicsLineItem *currentLine;
};

#endif // SKETCHER_H
