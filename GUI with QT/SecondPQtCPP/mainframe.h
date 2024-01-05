#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainFrame;
}
QT_END_NAMESPACE

class MainFrame : public QMainWindow
{
    Q_OBJECT

public:
    MainFrame(QWidget *parent = nullptr);
    ~MainFrame();

public slots:
    void on_pushButton_clicked();
    void onDataAvailable(const QString &data);

private:
    Ui::MainFrame *ui;
};
#endif // MAINFRAME_H
