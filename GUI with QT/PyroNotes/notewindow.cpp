#include "notewindow.h"
#include "ui_notewindow.h"
#include "form.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include<QPrinter>
#include<QPrintDialog>
#include<QDialog>
#include<QDebug>
#include <QTextDocument>
#include <QInputDialog>
#include <QTextToSpeech>
#include<QThread>
#include <QDesktopServices>
#include <QUrl>
#include <QInputDialog>
// #include <QNetworkAccessManager>
// #include <QNetworkRequest>
// #include <QNetworkReply>
#include <QUrlQuery>
// #include <QJsonDocument>
// #include <QJsonObject>
// #include <QJsonValue>
// #include <QJsonArray>
// #include "form.h"
// #include "notewindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "table.h"
#include "sketchform.h"


//class Form;

NoteWindow::NoteWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NoteWindow),
     networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    setWindowTitle("Pyro Notes");
    setWindowIcon(QIcon(":/Image/Image/Logo 1.jpg"));

   connect(ui->actionInsert_Sketch_Form, &QAction::triggered, this, &NoteWindow::on_actionInsert_Sketch_Form_triggered);

    Form *form1 = new Form();
    ui->Home->layout()->addWidget(form1);
    Form *form2 = new Form();
    ui->tab_2->layout()->addWidget(form2);

    networkManager = new QNetworkAccessManager(this);
}

NoteWindow::~NoteWindow()
{
    delete ui;
}

void NoteWindow::on_actionNew_Tab_triggered()
{
    ui->tabWidget->addTab(new Form(),QString("Tab %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}


void NoteWindow::on_actionNew_triggered()
{
    file_path = " "; // Assuming you're resetting the file_path

    int currentIndex = ui->tabWidget->currentIndex();
    QWidget* currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form* currentForm = qobject_cast<Form*>(currentTabWidget);
    if (currentForm)
    {
        currentForm->setTextEditContent(" ");
    }
}


void NoteWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open The File");
    file_path = file_name;

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(this, "File", "File is not open");
            return;
        }

        QTextStream in(&file);
        QString text = in.readAll();

        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextEditContent(text);
           // qDebug() << "Loaded text:" << text;
        }

        file.close();
    }
}


void NoteWindow::on_actionSave_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save File");
    file_path = file_name;

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::information(this, "File", "File is not open");
            return;
        }

        QTextStream out(&file);

        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            QString text = currentForm->getTextEditContent();
            out << text;
            qDebug() << "Saved text:" << text;
        }

        file.flush();
        file.close();
    }
}


void NoteWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save As");
    file_path = file_name;

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::information(this, "File", "File is not open");
            return;
        }

        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            QString text = currentForm->getTextEditContent();
            QTextStream out(&file);
            out << text;
            file.flush();
            file.close();
            qDebug() << "Saved text:" << text;
        }
    }
}


void NoteWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Choose Printer");
    QPrintDialog dialog(&printer, this);

    if(dialog.exec() == QDialog::Accepted)
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            QTextDocument document;
            document.setPlainText(currentForm->getTextEditContent());

            QPrintDialog printDialog(&printer, this);
            if (printDialog.exec() == QDialog::Accepted)
            {
                document.print(&printer);
            }
        }
    }
}


void NoteWindow::on_actionCut_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->cutText();
    }
}

void NoteWindow::on_actionCopy_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->copyText();
    }
}

void NoteWindow::on_actionPaste_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->pasteText();
    }
}

void NoteWindow::on_actionRedo_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->redoText();
    }
}

void NoteWindow::on_actionUndo_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        currentForm->undoText();
    }
}



void NoteWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);

    if (ok)
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setFontTextEdit(font);
        }
    }
    else
    {
        return;
    }
}


void NoteWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if (color.isValid())
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextColor(color);
        }
    }
}

void NoteWindow::on_actionHighlighter_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if (color.isValid())
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextHighlightColor(color);
        }
    }
}

void NoteWindow::on_actionBackground_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if (color.isValid())
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setTextBackgroundColor(color);
        }
    }
}


void NoteWindow::on_actionAbout_PyroNote_triggered()
{
    QString About="Author : Okita\n";
    About+="Date: 25 Jan 2024\n";
    About+="Pyro Notes\n";
    About+="You can write and read with it\n";
    QMessageBox::about(this,"About PyroNotes",About);
}


void NoteWindow::on_actionFind_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        QString searchText = QInputDialog::getText(this, "Find", "Enter text to find:");

        if (!searchText.isEmpty())
        {
            currentForm->findAndHighlightText(searchText);
        }
    }
}

void NoteWindow::on_actionReplace_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        QString searchText = QInputDialog::getText(this, "Find", "Enter text to find:");
        QString replaceText = QInputDialog::getText(this, "Replace", "Enter text to replace:");

        if (!searchText.isEmpty())
        {
            currentForm->findAndReplaceText(searchText, replaceText);
        }
    }
}

void NoteWindow::on_actionZoom_triggered()
{
    bool ok;
    int zoomFactor = QInputDialog::getInt(this, "Zoom", "Enter zoom factor:", 100, 10, 500, 10, &ok);

    if (ok)
    {
        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            currentForm->setZoomFactor(zoomFactor);
        }
    }
}


void NoteWindow::on_actionText_To_Speech_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        QString textToRead = currentForm->getTextEditContent();

        if (!textToRead.isEmpty())
        {
            QTextToSpeech textToSpeech;

            QList<QVoice> voices = textToSpeech.availableVoices();
            // qDebug() << "Available Voices:";
            // for (const QVoice &voice : voices)
            //     qDebug() << " - " << voice.name();

            QString voiceInfo = "Available Voices:\n";
            for (const QVoice &voice : voices)
                voiceInfo += " - " + voice.name() + "\n";

            QMessageBox::information(this, "Available Voices", voiceInfo);

            // Set a voice if needed (optional)
            if (!voices.isEmpty())
            {
                textToSpeech.setVoice(voices.first());
                //qDebug() << "Selected Voice:" << voices.first().name();
                QString selectedVoiceInfo = "Selected Voice: " + voices.first().name();
                QMessageBox::information(this, "Selected Voice", selectedVoiceInfo);

            }
            else
            {
               // qDebug() << "No available voices.";
                QMessageBox::warning(this, "TextToSpeech", "No available voices.");
               QString message = "Do You Want to Continue through website?";
               QMessageBox::StandardButton reply = QMessageBox::question(this, "Speech", message, QMessageBox::Yes | QMessageBox::No);

               if (reply == QMessageBox::Yes)
               {
                   // Open the specified website
                   QDesktopServices::openUrl(QUrl("https://ttsreader.com/player/"));
               }
                return;
            }

            // Set the text to be spoken
            textToSpeech.say(textToRead);

            // Check for errors
            QTextToSpeech::State state = textToSpeech.state();
            if (state == QTextToSpeech::Error)
            {
                //qDebug() << "Error in TextToSpeech:" << textToSpeech.errorString();
                QMessageBox::critical(this, "TextToSpeech Error", "Error in TextToSpeech:\n" + textToSpeech.errorString());
                QString message = "Do You Want to Continue through website?";
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Speech", message, QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::Yes)
                {
                    // Open the specified website
                    QDesktopServices::openUrl(QUrl("https://ttsreader.com/player/"));
                }
            }
            else
            {
                //qDebug() << "Text to Speech initiated.";
               QMessageBox::information(this,"Speech","Speech Initiated:::DO NOT CLOSE IT UNTILL ALL COVERS UP");
                QString message = "Text to Speech initiated. Do you hear it?";
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Speech", message, QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::No)
                {
                    // Open the specified website
                    QDesktopServices::openUrl(QUrl("https://ttsreader.com/player/"));
                }
            }
        }
    }
    // QTextToSpeech textToSpeech;
    // textToSpeech.say("Hello, this is a test.");
    // qDebug()<<"Executed";
}

void NoteWindow::on_actionOpen_Browser_triggered()
{
    openWebPage("https://www.google.com");
}

void NoteWindow::openWebPage(const QString &url)
{
    QUrl webpage(url);

    if (!QDesktopServices::openUrl(webpage))
    {
        QMessageBox::critical(this, "Error", "Could not open Browser:" + url);
       // qDebug() << "Could not open URL: " << url;
    }
}



void NoteWindow::on_actionSend_this_by_Mail_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        QString recipient = QInputDialog::getText(this, "Enter Recipient", "Enter the recipient's email address:");
        if (recipient.isEmpty())
        {
            return;
        }

        QString subject = QInputDialog::getText(this, "Enter Subject", "Enter the email subject:");
        if (subject.isEmpty())
        {
            return;
        }

        QString body = currentForm->getTextEditContent();
        if (body.isEmpty())
        {
            QMessageBox::warning(this, "Empty Content", "Cannot send an empty email.");
            return;
        }

        // Construct a mailto URL
        QString mailtoUrl = QString("mailto:%1?subject=%2&body=%3")
                                .arg(recipient)
                                .arg(QUrl::toPercentEncoding(subject))
                                .arg(QUrl::toPercentEncoding(body));
        QDesktopServices::openUrl(QUrl(mailtoUrl));
    }
}

void NoteWindow::on_actionTranslator_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);

    if (currentForm)
    {
        QString textToTranslate = currentForm->getTextEditContent();
        if (!textToTranslate.isEmpty())
        {
            QUrl googleTranslateUrl("https://translate.google.com");
            QUrlQuery query;
            query.addQueryItem("text", textToTranslate);
            googleTranslateUrl.setQuery(query);
            QDesktopServices::openUrl(googleTranslateUrl);
        }
    }
}


void NoteWindow::on_actionSpeech_to_Text_triggered()
{
    QMessageBox::information(this, "Speech to Text", "Click OK to access the speech-to-text service.We are currnetly not providing on Application Speech to text service.Sorry");
    QUrl speechToTextUrl("https://speechnotes.co/dictate/");
    QDesktopServices::openUrl(speechToTextUrl);
}



void NoteWindow::on_actionText_Generator_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
    Form *currentForm = qobject_cast<Form *>(currentTabWidget);
    if (currentForm)
    {
        QString prompt = QInputDialog::getText(this, "Text Generator", "Enter a prompt:");
        if (!prompt.isEmpty())
        {
            generateText(prompt, currentForm); // Pass currentForm to the function
        }
    }
}

void NoteWindow::generateText(const QString &prompt, Form *currentForm)
{
    QString apiUrl = "https://api.openai.com/v1/chat/completions";
    QNetworkRequest request{ QUrl(apiUrl) };
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Authorization", "Bearer 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");
    QByteArray requestData = QString("{\"prompt\": \"%1\"}").arg(prompt).toUtf8();
    QNetworkReply *reply = networkManager->post(request, requestData);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            QString generatedText = QString(reply->readAll());
            qDebug() << "Generated Text:" << generatedText;
            if (currentForm)
            {
                currentForm->setTextEditContent(generatedText);
            }
        }
        else
        {
            if (reply->errorString().contains("exceeded your current quota"))
            {
                QString errorMessage = "Error: Exceeded API quota. Please check your plan and billing details.\n\n"
                                       "Request URL: " + apiUrl + "\n"
                                                  "Request Data: " + requestData + "\n"
                                                       "Response Error Code: " + QString::number(reply->error()) + "\n"
                                                                           "Response Error Description: " + reply->errorString();
                QMessageBox::critical(this, "API Quota Exceeded", errorMessage);
                QString message = "Do you want to continue at website?";
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Text Generator", message, QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::Yes)
                {
                    QDesktopServices::openUrl(QUrl("https://chat.openai.com/"));
                }
            }
            else
            {
                QString errorMessage = "Error in text generation. Error Code: " + QString::number(reply->error()) + "\n"
                                                                                                                    "Error Description: " + reply->errorString() + "\n"
                                                                "Request URL: " + apiUrl + "\n"
                                                  "Request Data: " + requestData + "\n"
                                                       "Response Error Code: " + QString::number(reply->error()) + "\n"
                                                                           "Response Error Description: " + reply->errorString();
                QMessageBox::critical(this, "Text Generation Error", errorMessage);
                QString message = "Do you want to continue at website?";
                QMessageBox::StandardButton reply = QMessageBox::question(this, "Text Generator", message, QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::Yes)
                {
                    QDesktopServices::openUrl(QUrl("https://chat.openai.com/"));
                }
            }

        }
        reply->deleteLater();
    });

}



void NoteWindow::on_actionRun_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save As");
    file_path = file_name;

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::information(this, "File", "File is not open");
            return;
        }

        int currentIndex = ui->tabWidget->currentIndex();
        QWidget *currentTabWidget = ui->tabWidget->widget(currentIndex);
        Form *currentForm = qobject_cast<Form *>(currentTabWidget);

        if (currentForm)
        {
            QString text = currentForm->getTextEditContent();
            QTextStream out(&file);
            out << text;
            file.flush();
            file.close();
            qDebug() << "Saved text:" << text;

            // Determine the file extension
            QFileInfo fileInfo(file_name);
            QString fileExtension = fileInfo.suffix().toLower();

            // Construct PowerShell command based on file type
            QString powerShellCommand;
            if (fileExtension == "py")
            {
                powerShellCommand = QString("python .\\%1").arg(fileInfo.fileName());
            }

            openPowerShell(powerShellCommand);
        }
    }
}

void NoteWindow::openPowerShell(const QString &command)
{
    QString powerShellCommand = "powershell.exe";
    QStringList arguments;
    arguments << "-Command" << command;
    QProcess *powerShellProcess = new QProcess(this);
    powerShellProcess->start(powerShellCommand, arguments);
    if (!powerShellProcess->waitForStarted())
    {
        QString errorMessage = "Error starting PowerShell process:\n" + powerShellProcess->errorString();
        QMessageBox::critical(this, "PowerShell Error", errorMessage);
        return;
    }
    powerShellProcess->waitForFinished();
    QByteArray output = powerShellProcess->readAllStandardOutput();
    QByteArray errorOutput = powerShellProcess->readAllStandardError();

    // Display the PowerShell output
    if (!output.isEmpty())
    {
        QMessageBox::information(this, "PowerShell Output", "PowerShell Output:\n" + output);
    }

    // Display the PowerShell error output
    if (!errorOutput.isEmpty())
    {
        QMessageBox::warning(this, "PowerShell Error Output", "PowerShell Error Output:\n" + errorOutput);
    }

    powerShellProcess->close();
}


void NoteWindow::on_actionInsert_Table_triggered()
{
    Table *newTable = new Table(this);
    ui->tabWidget->addTab(newTable, QString("Tab %0(Table)").arg(ui->tabWidget->count() + 1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void NoteWindow::on_actionOpen_Lucidchart_triggered()
{
    QDesktopServices::openUrl(QUrl("https://www.lucidchart.com/"));
}

void NoteWindow::on_actionOpen_Google_Sheets_triggered()
{
    QDesktopServices::openUrl(QUrl("https://sheets.google.com/"));
}


void NoteWindow::on_actionInsert_Sketch_Form_triggered()
{
    SketchForm *newSketchForm = new SketchForm(this);
    ui->tabWidget->addTab(newSketchForm, QString("Tab %0(MemoryForm)").arg(ui->tabWidget->count() + 1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}


