/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag.
** All rights reserved.
** This file is part of "GR-55 FloorBoard".
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#include <QtWidgets>
#include <QWhatsThis>
//#include <QWebPage>
#include "mainWindow.h"
#include "Preferences.h"
#include "preferencesDialog.h"
#include "statusBarWidget.h"
#include "SysxIO.h"
#include "bulkSaveDialog.h"
#include "bulkLoadDialog.h"
#include "summaryDialog.h"
#include "summaryDialogPatchList.h"
#include "summaryDialogSystem.h"
#include "globalVariables.h"


mainWindow::mainWindow()
{
    Preferences *preferences = Preferences::Instance();
    bool ok;
    /*int current_version = preferences->getPreferences("General", "Application", "version").toInt(&ok, 10);
    QDate date = QDate::currentDate();
    text = date.toString("yyyyMMdd");
    QString site_file;
    QUrl site("http://sourceforge.net/projects/grfloorboard/files/GR-55/readme.txt");           // Read the default GR-55 G5L file .
    site_file = site.hasQuery();
    if (site_file.isEmpty() ) { QApplication::beep(); };

    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle("Web site read version number");
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setText(site_file);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
    msgBox->deleteLater();*/
#ifdef Q_PROCESSOR_ARM
    this->setMinimumSize(1210, 691);
#endif

    floorBoard *fxsBoard = new floorBoard(this);
    fxsBoard->scroll(600, 300);

    QString setting = preferences->getPreferences("Scheme", "Style", "select");
    int choice = setting.toInt(&ok, 16);
    QString style;
    if(choice == 3) {style = "motif"; }
    else if(choice == 2) {style = "cleanlooks"; }
    else if(choice == 1) {style = "plastique"; }
    else {style = ""; };

    setting = preferences->getPreferences("Scheme", "Colour", "select");
    choice = setting.toInt(&ok, 16);
    QString colour;
    if(choice == 4) {colour = ":qss/white.qss"; }
    else if(choice == 3) {colour = ":qss/green.qss"; }
    else if(choice == 2) {colour = ":qss/blue.qss"; }
    else if(choice == 1) {colour = ":qss/black.qss"; }
    else {colour = ":qss/black.qss"; };
    /* Loads the stylesheet for the current platform if present */
    QApplication::setStyle(QStyleFactory::create(style));
    if(QFile(colour).exists())
    {
        QFile file(colour);
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        fxsBoard->setStyleSheet(styleSheet);
    };

    setWindowTitle(deviceType + tr(" FloorBoard"));
    createActions();
    createMenus();
    createStatusBar();
    setCentralWidget(fxsBoard);
    statusBar()->setWhatsThis("StatusBar<br>midi activity is displayed here<br>and some status messages are displayed.");

    QObject::connect(fxsBoard, SIGNAL( sizeChanged(QSize, QSize) ),
                     this, SLOT( updateSize(QSize, QSize) ) );
}

mainWindow::~mainWindow()
{
    Preferences *preferences = Preferences::Instance();
    if(preferences->getPreferences("Window", "Restore", "window")=="true")
    {
        QString posx, width;
        if(preferences->getPreferences("Window", "Restore", "sidepanel")=="true" &&
           preferences->getPreferences("Window", "Collapsed", "bool")=="true")
        {
            width = QString::number(this->geometry().width(), 10);
            posx = QString::number(this->geometry().x()-8, 10);
        }
        else
        {
            bool ok;
            width = preferences->getPreferences("Window", "Size", "minwidth");
            posx = QString::number(this->geometry().x()+((this->geometry().width()-width.toInt(&ok,10))/2), 10);
        };
        preferences->setPreferences("Window", "Position", "x", posx);
        preferences->setPreferences("Window", "Position", "y", QString::number(this->geometry().y()-30, 10));
        preferences->setPreferences("Window", "Size", "width", width);
        preferences->setPreferences("Window", "Size", "height", QString::number(this->geometry().height(), 10));
    }
    else
    {
        preferences->setPreferences("Window", "Position", "x", "");
        preferences->setPreferences("Window", "Position", "y", "");
        preferences->setPreferences("Window", "Size", "width", "");
        preferences->setPreferences("Window", "Size", "height", "");
    };
    preferences->savePreferences();
}

void mainWindow::updateSize(QSize floorSize, QSize oldFloorSize)
{
    this->setFixedWidth(floorSize.width());
    int x = this->geometry().x() - ((floorSize.width() - oldFloorSize.width()) / 2);
    int y = this->geometry().y();
    this->setGeometry(x, y, floorSize.width(), this->geometry().height());
}

void mainWindow::createActions()
{
    openAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Load Patch File... (*.g5l, *.mid, *.syx)"), this);
    openAct->setShortcut(tr("Ctrl+O"));
    openAct->setStatusTip(tr("Open an existing file"));
    openAct->setWhatsThis(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon(":/images/filesave.png"), tr("&Save Patch...       (*.syx)"), this);
    saveAct->setShortcut(tr("Ctrl+S"));
    saveAct->setStatusTip(tr("Save the document to disk"));
    saveAct->setWhatsThis(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(QIcon(":/images/filesave.png"), tr("&Export &SYX Patch...  (*.syx)"), this);
    saveAsAct->setShortcut(tr("Ctrl+Shift+S"));
    saveAsAct->setStatusTip(tr("Export as a System Exclusive File"));
    saveAsAct->setWhatsThis(tr("Export as a System Exclusive File"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exportSMFAct = new QAction(QIcon(":/images/filesave.png"), tr("&Export &SMF Patch... (*.mid)"), this);
    exportSMFAct->setShortcut(tr("Ctrl+Shift+E"));
    exportSMFAct->setStatusTip(tr("Export as a Standard Midi File"));
    exportSMFAct->setWhatsThis(tr("Export as a Standard Midi File"));
    connect(exportSMFAct, SIGNAL(triggered()), this, SLOT(exportSMF()));

    saveG5LAct = new QAction(QIcon(":/images/filesave.png"), tr("Save As G5L Patch... (*.g5l)"), this);
    saveG5LAct->setShortcut(tr("Ctrl+Shift+G"));
    saveG5LAct->setStatusTip(tr("Export as a ROLAND Librarian File"));
    saveG5LAct->setWhatsThis(tr("Export as a ROLAND Librarian File"));
    connect(saveG5LAct, SIGNAL(triggered()), this, SLOT(saveG5L()));

    systemLoadAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Load System and Global Data..."), this);
    systemLoadAct->setShortcut(tr("Ctrl+L"));
    systemLoadAct->setStatusTip(tr("Load System Data to GR-55"));
    systemLoadAct->setWhatsThis(tr("Load System Data to GR-55"));
    connect(systemLoadAct, SIGNAL(triggered()), this, SLOT(systemLoad()));

    systemSaveAct = new QAction(QIcon(":/images/filesave.png"), tr("Save System and Global Data to File..."), this);
    systemSaveAct->setShortcut(tr("Ctrl+D"));
    systemSaveAct->setStatusTip(tr("Save System Data to File"));
    systemSaveAct->setWhatsThis(tr("Save System Data to File"));
    connect(systemSaveAct, SIGNAL(triggered()), this, SLOT(systemSave()));

    bulkLoadAct = new QAction(QIcon(":/images/fileopen.png"), tr("&Load Bulk Patch File to GR-55..."), this);
    bulkLoadAct->setShortcut(tr("Ctrl+B"));
    bulkLoadAct->setStatusTip(tr("Load Bulk Patch Data to GR-55"));
    bulkLoadAct->setWhatsThis(tr("Load Bulk Patch Data to GR-55"));
    connect(bulkLoadAct, SIGNAL(triggered()), this, SLOT(bulkLoad()));

    bulkSaveAct = new QAction(QIcon(":/images/filesave.png"), tr("Save Bulk GR-55 Patches to File..."), this);
    bulkSaveAct->setShortcut(tr("Ctrl+G"));
    bulkSaveAct->setStatusTip(tr("Save Bulk Patch Data to File"));
    bulkSaveAct->setWhatsThis(tr("Save Bulk Patch Data to File"));
    connect(bulkSaveAct, SIGNAL(triggered()), this, SLOT(bulkSave()));

    exitAct = new QAction(QIcon(":/images/exit.png"),tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    exitAct->setWhatsThis(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    settingsAct = new QAction(QIcon(":/images/preferences.png"), tr("&Preferences"), this);
    settingsAct->setShortcut(tr("Ctrl+P"));
    settingsAct->setStatusTip(tr("GR-55FloorBoard Preferences<br>Select midi device, language,splash, directories"));
    settingsAct->setWhatsThis(tr("GR-55FloorBoard Preferences<br>Select midi device, language,splash, directories"));
    connect(settingsAct, SIGNAL(triggered()), this, SLOT(settings()));

    guitarModeAct = new QAction(QIcon(":/images/guitar_icon.png"), tr("&Change Patch to Guitar Mode"), this);
    guitarModeAct->setShortcut(tr("Shift+G"));
    guitarModeAct->setStatusTip(tr("Force to Guitar Mode Force editor to Guitar mode modeling to edit/convert Bass mode patches"));
    guitarModeAct->setWhatsThis(tr("Force to Guitar Mode<br>Force editor to Guitar mode modeling to edit/convert Bass mode patches"));
    connect(guitarModeAct, SIGNAL(triggered()), this, SLOT(guitarMode()));

    bassModeAct = new QAction(QIcon(":/images/bass_icon.png"), tr("&Change Patch to Bass Mode"), this);
    bassModeAct->setShortcut(tr("Shift+B"));
    bassModeAct->setStatusTip(tr("Force to Bass Mode Force editor to Bass Mode modeling to edit/convert Guitar mode patches"));
    bassModeAct->setWhatsThis(tr("Force to Bass Mode<br>Force editor to Bass Mode modeling to edit/convert Guitar mode patches"));
    connect(bassModeAct, SIGNAL(triggered()), this, SLOT(bassMode()));


    uploadAct = new QAction(QIcon(":/images/upload.png"), tr("Upload patch to V-Guitar Forums"), this);
    uploadAct->setStatusTip(tr("Upload any saved patch file to a shared patch library via the internet."));
    uploadAct->setWhatsThis(tr("Upload any saved patch file to a shared patch library<br>via the internet."));
    connect(uploadAct, SIGNAL(triggered()), this, SLOT(upload()));

    summaryAct = new QAction(QIcon(":/images/copy.png"), tr("Patch Text Summary"), this);
    summaryAct->setStatusTip(tr("Display the current patch parameters in a readable text format, which can be printed or saved to file."));
    summaryAct->setWhatsThis(tr("Display the current patch parameters<br>in a readable text format, which<br>can be printed or saved to file."));
    connect(summaryAct, SIGNAL(triggered()), this, SLOT(summaryPage()));

    summarySystemAct = new QAction(QIcon(":/images/copy.png"), tr("System/Global Text Summary"), this);
    summarySystemAct->setStatusTip(tr("Display the current System and Global parameters in a readable text format, which can be printed or saved to file."));
    summarySystemAct->setWhatsThis(tr("Display the current System and Global parameters<br>in a readable text format, which<br>can be printed or saved to file."));
    connect(summarySystemAct, SIGNAL(triggered()), this, SLOT(summarySystemPage()));

    summaryPatchListAct = new QAction(QIcon(":/images/copy.png"), tr("GR-55 Patch List Summary"), this);
    summaryPatchListAct->setStatusTip(tr("Display the GR-55 patch listing names in a readable text format, which can be printed or saved to file."));
    summaryPatchListAct->setWhatsThis(tr("Display the GR-55 patch listing names<br>in a readable text format, which<br>can be printed or saved to file."));
    connect(summaryPatchListAct, SIGNAL(triggered()), this, SLOT(summaryPatchList()));

    helpAct = new QAction(QIcon(":/images/help.png"), tr("GR-55 FloorBoard &Help"), this);
    helpAct->setShortcut(tr("Ctrl+F1"));
    helpAct->setStatusTip(tr("Help page to assist with GR-55 FloorBoard functions."));
    helpAct->setWhatsThis(tr("Help page to assist with GR-55 FloorBoard functions."));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

    whatsThisAct = new QAction(QIcon(":/images/help.png"), tr("Whats This? description of items under the mouse cursor"), this);
    whatsThisAct->setShortcut(tr("F1"));
    whatsThisAct->setWhatsThis(tr("Whats This? description of items under the mouse cursor"));
    whatsThisAct->setStatusTip(tr("Whats This? description of items under the mouse cursor"));
    connect(whatsThisAct, SIGNAL(triggered()), this, SLOT(whatsThis()));

    homepageAct = new QAction(QIcon(":/images/GR-55FloorBoard.png"), tr("GR-55 FloorBoard &Webpage"), this);
    homepageAct->setStatusTip(tr("download Webpage for GR-55FloorBoard find if the latest version is available."));
    homepageAct->setWhatsThis(tr("download Webpage for GR-55FloorBoard<br>find if the latest version is available."));
    connect(homepageAct, SIGNAL(triggered()), this, SLOT(homepage()));

    donationAct = new QAction(QIcon(":/images/donate.png"), tr("Donate if you appreciate this software"), this);
    donationAct->setStatusTip(tr("Even though the software is free, a donation is very much appreciated for my un-paid efforts to provide this software."));
    donationAct->setWhatsThis(tr("Even though the software is free,<br>a donation is very much appreciated<br>for my un-paid efforts to provide this software."));
    connect(donationAct, SIGNAL(triggered()), this, SLOT(donate()));

    manualAct = new QAction(QIcon(":/images/manual.png"), tr("Owner's Manual"), this);
    manualAct->setStatusTip(tr("download the Owner's Manual"));
    manualAct->setWhatsThis(tr("download the Owner's Manual"));
    connect(manualAct, SIGNAL(triggered()), this, SLOT(manual()));

    licenseAct = new QAction(QIcon(":/images/licence.png"), tr("&License"), this);
    licenseAct->setStatusTip(tr("licence agreement which you have accepted by installing this software."));
    licenseAct->setWhatsThis(tr("licence agreement which you<br>have accepted by installing this software."));
    connect(licenseAct, SIGNAL(triggered()), this, SLOT(license()));

    aboutAct = new QAction(QIcon(":/images/GR-55FloorBoard.png"), tr("&About GR-55FloorBoard"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    aboutAct->setWhatsThis(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(QIcon(":/images/qt-logo.png"),tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    aboutQtAct->setWhatsThis(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void mainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(saveG5LAct);
    fileMenu->addAction(exportSMFAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(bulkLoadAct);
    fileMenu->addAction(bulkSaveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(systemLoadAct);
    fileMenu->addAction(systemSaveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    fileMenu->setWhatsThis(tr("File Saving and Loading,<br> and application Exit."));

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(uploadAct);
    fileMenu->addSeparator();
    toolsMenu->addAction(summaryAct);
    toolsMenu->addAction(summarySystemAct);
    toolsMenu->addAction(summaryPatchListAct);

    settingsMenu = menuBar()->addMenu(tr("&Settings"));
    settingsMenu->addAction(settingsAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAct);
    helpMenu->addAction(whatsThisAct);
    helpMenu->addAction(homepageAct);
    helpMenu->addSeparator();
    helpMenu->addAction(donationAct);
    helpMenu->addSeparator();
    helpMenu->addAction(manualAct);
    helpMenu->addAction(licenseAct);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    modeMenu = menuBar()->addMenu(tr("&Mode"));
    modeMenu->addAction(guitarModeAct);
    modeMenu->addAction(bassModeAct);
}

void mainWindow::createStatusBar()
{
    SysxIO *sysxIO = SysxIO::Instance();

    statusBarWidget *statusInfo = new statusBarWidget(this);
    statusInfo->setStatusSymbol(0);
    statusInfo->setStatusMessage(tr("Not connected"));

    QObject::connect(sysxIO, SIGNAL(setStatusSymbol(int)), statusInfo, SLOT(setStatusSymbol(int)));
    QObject::connect(sysxIO, SIGNAL(setStatusProgress(int)), statusInfo, SLOT(setStatusProgress(int)));
    QObject::connect(sysxIO, SIGNAL(setStatusMessage(QString)), statusInfo, SLOT(setStatusMessage(QString)));
    QObject::connect(sysxIO, SIGNAL(setStatusdBugMessage(QString)), statusInfo, SLOT(setStatusdBugMessage(QString)));

    statusBar()->addWidget(statusInfo);
    statusBar()->setSizeGripEnabled(false);
}

/* FILE MENU */
void mainWindow::open()
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("Choose a file"),
            dir,
            tr("for GR-55   (*.syx *.mid *.g5l)"));
    if (!fileName.isEmpty())
    {
        file.setFile(fileName);
        if(file.readFile())
        {
            // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, file.getFileSource());
            sysxIO->setFileName(fileName);
            sysxIO->setSyncStatus(false);
            sysxIO->setDevice(false);
            emit updateSignal();
            if(sysxIO->isConnected())
            {sysxIO->writeToBuffer();};
        };
    };
}

void mainWindow::save()
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    SysxIO *sysxIO = SysxIO::Instance();
    file.setFile(sysxIO->getFileName());

    if(file.getFileName().isEmpty())
    {
        QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("Export *.syx"),
                dir,
                tr("System Exclusive (*.syx)"));
        if (!fileName.isEmpty())
        {
            if(!fileName.contains(".syx"))
            {
                fileName.append(".syx");
            };
            file.writeFile(fileName);

            file.setFile(fileName);
            if(file.readFile())
            {
                // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
                SysxIO *sysxIO = SysxIO::Instance();
                QString area = "Structure";
                sysxIO->setFileSource(area, file.getFileSource());
                emit updateSignal();
            };
        };
    }
    else
    {
        file.writeFile(file.getFileName());
    };
}

void mainWindow::saveAs()
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
            this,
            tr("Export *.syx"),
            dir,
            tr("System Exclusive (*.syx)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".syx"))
        {
            fileName.append(".syx");
        };
        file.writeFile(fileName);

        file.setFile(fileName);
        if(file.readFile())
        {
            // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, file.getFileSource());
            emit updateSignal();
        };
    };
}

void mainWindow::importSMF()
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("Choose a file"),
            dir,
            tr("Standard Midi File (*.mid)"));
    if (!fileName.isEmpty())
    {
        file.setFile(fileName);
        if(file.readFile())
        {
            // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, file.getFileSource());
            sysxIO->setFileName(fileName);
            sysxIO->setSyncStatus(false);
            sysxIO->setDevice(false);
            emit updateSignal();
            if(sysxIO->isConnected())
            {sysxIO->writeToBuffer(); };
        };
    };
}

void mainWindow::exportSMF()
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
            this,
            tr("Export SMF"),
            dir,
            tr("Standard Midi File (*.mid)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".mid"))
        {
            fileName.append(".mid");
        };
        file.writeSMF(fileName);

        file.setFile(fileName);
        if(file.readFile())
        {
            // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, file.getFileSource());

            emit updateSignal();
        };
    };
}

void mainWindow::openG5L()
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("Choose a file"),
            dir,
            tr("ROLAND Librarian File (*.g5l)"));
    if (!fileName.isEmpty())
    {
        file.setFile(fileName);
        if(file.readFile())
        {
            // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, file.getFileSource());
            sysxIO->setFileName(fileName);
            sysxIO->setSyncStatus(false);
            sysxIO->setDevice(false);

            emit updateSignal();
            if(sysxIO->isConnected())
            {sysxIO->writeToBuffer(); };
        };
    };
}

void mainWindow::saveG5L()
{
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
            this,
            tr("Save Patch *.g5l"),
            dir,
            tr("ROLAND Librarian File (*.g5l)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".g5l"))
        {
            fileName.append(".g5l");
        };
        file.writeG5L(fileName);

        file.setFile(fileName);
        if(file.readFile())
        {
            // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
            SysxIO *sysxIO = SysxIO::Instance();
            QString area = "Structure";
            sysxIO->setFileSource(area, file.getFileSource());

            emit updateSignal();
        };
    };
}

void mainWindow::systemLoad()
{
    SysxIO *sysxIO = SysxIO::Instance();
    if (sysxIO->isConnected())
    {
        Preferences *preferences = Preferences::Instance();
        QString dir = preferences->getPreferences("General", "Files", "dir");

        QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("Choose a file"),
                dir,
                deviceType + tr(" System Data File (*.GR55_system_syx)"));
        if (!fileName.isEmpty())
        {
            file.setFile(fileName);
            if(file.readFile())
            {
                // DO SOMETHING AFTER READING THE FILE (UPDATE THE GUI)
                SysxIO *sysxIO = SysxIO::Instance();
                QString area = "System";
                sysxIO->setFileSource(area, file.getSystemSource());
                sysxIO->setFileName(fileName);
                emit updateSignal();
                QMessageBox *msgBox = new QMessageBox();
                msgBox->setWindowTitle(deviceType + tr(" FloorBoard"));
                msgBox->setIcon(QMessageBox::Warning);
                msgBox->setTextFormat(Qt::RichText);
                QString msgText;
                msgText.append("<font size='+1'><b>");
                msgText.append(tr("You have chosen to load a SYSTEM DATA file."));
                msgText.append("<b></font><br>");
                msgText.append(tr("This will overwrite the SYSTEM DATA currently stored in the ")+ deviceType);
                msgText.append(tr ("<br> and can't be undone.<br>"));
                msgText.append(tr("Select 'NO' to only update the Editor - Select 'YES' to update the GR-55 System<br>"));

                msgBox->setInformativeText(tr("Are you sure you want to write to the ")+ deviceType);
                msgBox->setText(msgText);
                msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

                if(msgBox->exec() == QMessageBox::Yes)
                {	// Accepted to overwrite system data.
                    sysxIO->systemWrite();
                };
                msgBox->deleteLater();
            };
        };
    }
    else
    {
        QString snork = tr("Ensure connection is active and retry");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    };
}

void mainWindow::systemSave()
{
    SysxIO *sysxIO = SysxIO::Instance();
    if (sysxIO->isConnected())
    {
        sysxIO->systemDataRequest();

        Preferences *preferences = Preferences::Instance();
        QString dir = preferences->getPreferences("General", "Files", "dir");

        QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("Save System Data"),
                dir,
                tr("System Exclusive File (*.GR55_system_syx)"));
        if (!fileName.isEmpty())
        {
            if(!fileName.contains(".GR55_system_syx"))
            {
                fileName.append(".GR55_system_syx");
            };

            file.writeSystemFile(fileName);

            file.setFile(fileName);
            if(file.readFile())
            {
                SysxIO *sysxIO = SysxIO::Instance();
                QString area = "System";
                sysxIO->setFileSource(area, file.getSystemSource());
                emit updateSignal();
            };
        };
    }
    else
    {
        QString snork = tr("Ensure connection is active and retry<br>");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    };
}

void mainWindow::bulkLoad()
{
    SysxIO *sysxIO = SysxIO::Instance();
    if (sysxIO->isConnected())
    {
        bulkLoadDialog *loadDialog = new bulkLoadDialog();
        loadDialog->exec();
        loadDialog->deleteLater();
    }
    else
    {
        QString snork = tr("Ensure connection is active and retry");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    };
}

void mainWindow::bulkSave()
{

    SysxIO *sysxIO = SysxIO::Instance();
    if (sysxIO->isConnected())
    {
        bulkSaveDialog *bulkDialog = new bulkSaveDialog();
        bulkDialog->exec();
        bulkDialog->deleteLater();
    }
    else
    {
        QString snork = tr("Ensure connection is active and retry");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(deviceType + tr(" not connected !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    };
}

/* TOOLS MENU */
void mainWindow::settings()
{
    preferencesDialog *dialog = new preferencesDialog();
    if (dialog->exec())
    {
        Preferences *preferences = Preferences::Instance();

        QString dir = dialog->generalSettings->dirEdit->text();
        QString sidepanel = (dialog->windowSettings->sidepanelCheckBox->checkState())?QString("true"):QString("false");
        QString window = (dialog->windowSettings->windowCheckBox->checkState())?QString("true"):QString("false");
        QString singleWindow = (dialog->windowSettings->singleWindowCheckBox->checkState())?QString("true"):QString("false");
        QString widgetHelp = (dialog->windowSettings->widgetsCheckBox->checkState())?QString("true"):QString("false");
        QString splash = (dialog->windowSettings->splashCheckBox->checkState())?QString("true"):QString("false");
        QString dBug = (dialog->midiSettings->dBugCheckBox->checkState())?QString("true"):QString("false");
        QString midiIn = QString::number(dialog->midiSettings->midiInCombo->currentIndex() - 1, 10); // -1 because there is a default entry at index 0
        QString midiOut = QString::number(dialog->midiSettings->midiOutCombo->currentIndex() - 1, 10);
        QString midiTxChSet =QString::number(dialog->midiSettings->midiTxChSpinBox->value());
        QString receiveTimeout =QString::number(dialog->midiSettings->midiDelaySpinBox->value());
        QString lang;
        if (dialog->languageSettings->chineseButton->isChecked() ) {lang="6"; }
        else if (dialog->languageSettings->japaneseButton->isChecked() ) {lang="5"; }
        else if (dialog->languageSettings->spanishButton->isChecked() ) {lang="4"; }
        else if (dialog->languageSettings->portugueseButton->isChecked() ) {lang="3"; }
        else if (dialog->languageSettings->germanButton->isChecked() ) {lang="2"; }
        else if (dialog->languageSettings->frenchButton->isChecked() ) {lang="1"; }
        else {lang="0"; };
        preferences->setPreferences("Language", "Locale", "select", lang);
        QString choice;
        if (dialog->styleSettings->motifButton->isChecked() ) {choice="3"; }
        else if (dialog->styleSettings->cdeButton->isChecked() ) {choice="2"; }
        else if (dialog->styleSettings->plastiqueButton->isChecked() ) {choice="1"; }
        else {choice="0"; };
        preferences->setPreferences("Scheme", "Style", "select", choice);
        if (dialog->styleSettings->whiteButton->isChecked() ) {choice="4"; }
        else if (dialog->styleSettings->greenButton->isChecked() ) {choice="3"; }
        else if (dialog->styleSettings->aquaButton->isChecked() ) {choice="2"; }
        else if (dialog->styleSettings->blackButton->isChecked() ) {choice="1"; }
        else {choice="0"; };
        preferences->setPreferences("Scheme", "Colour", "select", choice);

        if(midiIn=="-1") { midiIn = ""; };
        if(midiOut=="-1") {	midiOut = ""; };

        preferences->setPreferences("General", "Files", "dir", dir);
        preferences->setPreferences("Midi", "MidiIn", "device", midiIn);
        preferences->setPreferences("Midi", "MidiOut", "device", midiOut);
        preferences->setPreferences("Midi", "DBug", "bool", dBug);
        preferences->setPreferences("Midi", "TxCh", "set", midiTxChSet);
        preferences->setPreferences("Midi", "Delay", "set", receiveTimeout);
        preferences->setPreferences("Window", "Restore", "sidepanel", sidepanel);
        preferences->setPreferences("Window", "Restore", "window", window);
        preferences->setPreferences("Window", "Single", "bool", singleWindow);
        preferences->setPreferences("Window", "Widgets", "bool", widgetHelp);
        preferences->setPreferences("Window", "Splash", "bool", splash);
        preferences->savePreferences();
    };
    dialog->deleteLater();
}

void mainWindow::guitarMode()
{
    SysxIO *sysxIO = SysxIO::Instance();
    int mode_check = sysxIO->getSourceValue("Structure", "00", "00", "00");     //check for guitar mode
    if(mode_check > 0)
    {
        sysxIO->setFileSource("Structure", "00", "00", "00", "00");
        emit updateSignal();
        QString snork = tr("Ensure GR-55 mode matches the patch mode or else Modeling and Assigns realtime control will not work correctly");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(tr("Patch Mode changed !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    } else {
        QString snork = tr("Patch is already set to Guitar Mode, Patch Mode change not required");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(tr("Patch Mode change not required !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    };

}

void mainWindow::bassMode()
{
    SysxIO *sysxIO = SysxIO::Instance();
    int mode_check = sysxIO->getSourceValue("Structure", "00", "00", "00");     //check for guitar mode
    if(mode_check < 1)
    {
        sysxIO->setFileSource("Structure", "00", "00", "00", "01");
        emit updateSignal();
        QString snork = tr("Ensure GR-55 mode matches the patch mode or else Modeling and Assigns realtime control will not work correctly");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(tr("Patch Mode changed !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    } else {
        QString snork = tr("Patch is already set to Bass Mode, Patch Mode change is not required");
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setWindowTitle(tr("Patch Mode change not required !!"));
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setText(snork);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
    };
}

/* HELP MENU */
void mainWindow::help()
{
    QDesktopServices::openUrl(QUrl("file:help/help.html"));
}

void mainWindow::whatsThis()
{
    QWhatsThis::enterWhatsThisMode();
}


void mainWindow::upload()
{
    Preferences *preferences = Preferences::Instance();
    QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Upload", "url") ));
}

void mainWindow::summaryPage()
{
    summaryDialog *summary = new summaryDialog();
    summary->setMinimumWidth(800);
    summary->setMinimumHeight(650);
    summary->show();
}

void mainWindow::summarySystemPage()
{
    summaryDialogSystem *summarySystem = new summaryDialogSystem();
    summarySystem->setMinimumWidth(800);
    summarySystem->setMinimumHeight(650);
    summarySystem->show();
}

void mainWindow::summaryPatchList()
{
    summaryDialogPatchList *summaryPatchList = new summaryDialogPatchList();
    summaryPatchList->setMinimumWidth(800);
    summaryPatchList->setMinimumHeight(650);
    summaryPatchList->show();
}

void mainWindow::homepage()
{
    Preferences *preferences = Preferences::Instance();
    QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Webpage", "url") ));
}

void mainWindow::donate()
{
    QDesktopServices::openUrl(QUrl( "https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=YTT3NR4L7TTX8" ));
}

void mainWindow::manual()
{
    Preferences *preferences = Preferences::Instance();
    QDesktopServices::openUrl(QUrl( preferences->getPreferences("General", "Manual", "url") ));
}

void mainWindow::license()
{
    QDesktopServices::openUrl(QUrl("file:license.txt"));
}

void mainWindow::about()
{
    Preferences *preferences = Preferences::Instance();
    QString version = preferences->getPreferences("General", "Application", "version");
    QDate date = QDate::currentDate();
    QString dateText = date.toString("yyyy");

    QFile file(":about");
    if(file.open(QIODevice::ReadOnly))
    {
        QMessageBox::about(this, deviceType + tr(" FloorBoard - About"),
                           deviceType + tr(" FloorBoard - ") + tr("version") + " " + version + "<br>"
                           + tr("© Copyright ") + dateText + "<br>"
                           + file.readAll());
    };
}

void mainWindow::closeEvent(QCloseEvent* ce)
{
    Preferences *preferences = Preferences::Instance();
    preferences->savePreferences();
    ce->accept();
    emit closed();
}
