#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QMainWindow>

namespace Ui {
class NoteWindow;
}

class NoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = nullptr);
    ~NoteWindow();

private slots:
    void on_actionNew_Tab_triggered();

private:
    Ui::NoteWindow *ui;
};

#endif // NOTEWINDOW_H
