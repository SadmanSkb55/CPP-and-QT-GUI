#ifndef SKETCHFCOMPANION_H
#define SKETCHFCOMPANION_H

#include <QMainWindow>

namespace Ui {
class SketchFCompanion;
}

class SketchFCompanion : public QMainWindow
{
    Q_OBJECT

public:
    explicit SketchFCompanion(QWidget *parent = nullptr);
    ~SketchFCompanion();

private:
    Ui::SketchFCompanion *ui;
};

#endif // SKETCHFCOMPANION_H
