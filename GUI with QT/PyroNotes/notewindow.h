#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QMainWindow>
#include <QTextToSpeech>
#include <QNetworkReply>
//#include "form.h"
namespace Ui {
class NoteWindow;
}

class NoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = nullptr);
    ~NoteWindow();
    void sendEmail(const QString& recipient, const QString& subject, const QString& body);

private slots:
    void on_actionNew_Tab_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionHighlighter_triggered();

    void on_actionBackground_Color_triggered();

    void on_actionAbout_PyroNote_triggered();

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionZoom_triggered();

    void on_actionText_To_Speech_triggered();

    void on_actionOpen_Browser_triggered();

    void on_actionSend_this_by_Mail_triggered();

    void on_actionTranslator_triggered();

    //void onTranslationReplyFinished(QNetworkReply *reply);

   // void onTranslationReplyFinished(QNetworkReply *reply, Form *currentForm);

private:
    Ui::NoteWindow *ui;
    QString file_path;
    QTextToSpeech textToSpeech;
    void openWebPage(const QString &url);
};

#endif // NOTEWINDOW_H
