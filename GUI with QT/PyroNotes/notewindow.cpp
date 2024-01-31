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



//class Form;

NoteWindow::NoteWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NoteWindow),
     networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    setWindowTitle("Pyro Notes");
    setWindowIcon(QIcon(":/Image/Image/Logo 1.jpg"));

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

    // Access the widget at the current tab index
    QWidget* currentTabWidget = ui->tabWidget->widget(currentIndex);

    // Check if the widget is of type Form
    Form* currentForm = qobject_cast<Form*>(currentTabWidget);

    // If it's a Form widget, set the text of its textEdit
    if (currentForm)
    {
        currentForm->setTextEditContent(" "); // Assuming you have a function in Form to set the text
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
           // textToSpeech.setEngine("sapi"); // Uncomment this line if necessary

            // Check available voices
            QList<QVoice> voices = textToSpeech.availableVoices();
            qDebug() << "Available Voices:";
            for (const QVoice &voice : voices)
                qDebug() << " - " << voice.name();

            // Set a voice if needed (optional)
            if (!voices.isEmpty())
            {
                textToSpeech.setVoice(voices.first());
                qDebug() << "Selected Voice:" << voices.first().name();
            }
            else
            {
                qDebug() << "No available voices.";
            }

            // Set the text to be spoken
            textToSpeech.say(textToRead);

            // Check for errors
            QTextToSpeech::State state = textToSpeech.state();
            if (state == QTextToSpeech::Error)
            {
                qDebug() << "Error in TextToSpeech:" << textToSpeech.errorString();
            }
            else
            {
                qDebug() << "Text to Speech initiated.";
                // You can add additional logic here if needed
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
        // Handle the case when the URL can't be opened
        qDebug() << "Could not open URL: " << url;
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
            // User canceled or entered an empty email address
            return;
        }

        QString subject = QInputDialog::getText(this, "Enter Subject", "Enter the email subject:");
        if (subject.isEmpty())
        {
            // User canceled or entered an empty subject
            return;
        }

        QString body = currentForm->getTextEditContent();

        // Check if the body is empty
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

        // Open the default email client
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

        // Check if the text to translate is not empty
        if (!textToTranslate.isEmpty())
        {
            // Use Google Translate URL
            QUrl googleTranslateUrl("https://translate.google.com");

            // Set up the query parameters
            QUrlQuery query;
            query.addQueryItem("text", textToTranslate);

            googleTranslateUrl.setQuery(query);

            // Open the default web browser with the Google Translate URL
            QDesktopServices::openUrl(googleTranslateUrl);
        }
    }
}


void NoteWindow::on_actionSpeech_to_Text_triggered()
{

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
    // Set up the API endpoint and request URL
    QString apiUrl = "https://api.openai.com/v1/chat/completions";
    QNetworkRequest request{ QUrl(apiUrl) };

    // Set up the request headers
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Authorization", "Bearer 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");

    // Construct the request data
    QByteArray requestData = QString("{\"prompt\": \"%1\"}").arg(prompt).toUtf8();

    // Send the request
    QNetworkReply *reply = networkManager->post(request, requestData);

    // Connect the signal for handling the response
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError)
        {
            // Parse and use the generated text from the reply
            QString generatedText = QString(reply->readAll());
            qDebug() << "Generated Text:" << generatedText;

            // Display the generated text or use it as needed
            if (currentForm)
            {
                currentForm->setTextEditContent(generatedText);
            }
        }
        else
        {
            // Handle quota exceeded error
            if (reply->errorString().contains("exceeded your current quota"))
            {
                qDebug() << "Error: Exceeded API quota. Please check your plan and billing details.";
               // qDebug() << "API Key:" << "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";  // Replace with your actual API key
                qDebug() << "Request URL:" << apiUrl;
                qDebug() << "Request Data:" << requestData;
                qDebug() << "Response Error Code:" << reply->error();
                qDebug() << "Response Error Description:" << reply->errorString();

            }
            else
            {
                // Log other errors
                qDebug() << "Error in text generation. Error Code:" << reply->error();
                qDebug() << "Error Description:" << reply->errorString();
              //  qDebug() << "API Key:" << "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";  // Replace with your actual API key
                qDebug() << "Request URL:" << apiUrl;
                qDebug() << "Request Data:" << requestData;
                qDebug() << "Response Error Code:" << reply->error();
                qDebug() << "Response Error Description:" << reply->errorString();

            }
        }

        // Clean up the reply object
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
            // Add more cases for other file types if needed

            // Open PowerShell with the constructed command
            openPowerShell(powerShellCommand);
        }
    }
}

void NoteWindow::openPowerShell(const QString &command)
{
    // Command to open PowerShell
    QString powerShellCommand = "powershell.exe";

    // Arguments to pass to PowerShell
    QStringList arguments;
    arguments << "-Command" << command;

    // Create a QProcess instance
    QProcess *powerShellProcess = new QProcess(this);

    // Start PowerShell with arguments
    powerShellProcess->start(powerShellCommand, arguments);

    // Check if the process started successfully
    if (!powerShellProcess->waitForStarted())
    {
        qDebug() << "Error starting PowerShell process:" << powerShellProcess->errorString();
        return;
    }

    // Wait for the process to finish (optional)
    powerShellProcess->waitForFinished();

    // Read the output if needed
    QByteArray output = powerShellProcess->readAllStandardOutput();
    QByteArray errorOutput = powerShellProcess->readAllStandardError();

    qDebug() << "PowerShell Output:" << output;
    qDebug() << "PowerShell Error Output:" << errorOutput;

    // Close the process
    powerShellProcess->close();
}
