/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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
#include <QFile>
#include "summaryDialogPatchList.h"
#include "Preferences.h"
#include "SysxIO.h"
#include "MidiTable.h"
#include "globalVariables.h"

// Platform-dependent sleep routines.
#ifdef Q_OS_WIN
#include <windows.h>
#define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds )
#else // Unix variants & Mac
#include <unistd.h>
#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

summaryDialogPatchList::summaryDialogPatchList(QWidget *parent)
    : QWidget(parent)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
    QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
    QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));

    this->textDialog = new QTextEdit(parent);
    textDialog->setReadOnly(true);
    textDialog->setDocumentTitle(deviceType + tr(" Patch List"));
    textDialog->setMinimumHeight(600);
    this->bank = 1;
    this->patch = 1;
    
    QPushButton *cancelButton = new QPushButton(tr("Close"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    cancelButton->setWhatsThis(tr("Will close the currently open Dialog page."));

    QPushButton *printButton = new QPushButton(tr("Print"));
    connect(printButton, SIGNAL(clicked()), this, SLOT(printFile()));
    printButton->setWhatsThis(tr("Will Print the current Dialog to the prefered printer<br>printed text will be simular to the screen layout."));

    QPushButton *saveAsButton = new QPushButton(tr("Save As"));
    connect(saveAsButton, SIGNAL(clicked()), this, SLOT(saveAs()));
    saveAsButton->setWhatsThis(tr("Will save the current dialog page to file in a *.txt format."));

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(textDialog);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(printButton);
    buttonsLayout->addSpacing(12);
    buttonsLayout->addWidget(saveAsButton);
    buttonsLayout->addSpacing(12);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    setWindowTitle(deviceType + tr(" Patch List Summary"));

    if(sysxIO->deviceReady() && sysxIO->isConnected())
    {
        sysxIO->setDeviceReady(false);

        QObject::disconnect(sysxIO, SIGNAL(patchName(QString)),
                            this, SLOT(updatePatchNames(QString)));
        QObject::connect(sysxIO, SIGNAL(patchName(QString)),
                         this, SLOT(updatePatchNames(QString)));

        this->count = 0;
        this->updatePatchNames("");

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
    textDialog->setText(patchList);
    textDialog->show();
}

summaryDialogPatchList::~summaryDialogPatchList()
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(patchName(QString)),
                                this, SLOT(updatePatchNames(QString)));
    this->deleteLater();
}

void summaryDialogPatchList::updatePatchNames(QString name)
{		SysxIO *sysxIO = SysxIO::Instance();
        QString text;
            if(!name.isEmpty() && sysxIO->isConnected()) //  If not empty we can assume that we did receive a patch name.
            {
                text.append("<b>Constructing List ... Please Wait...</b>");
                for (int x=0; x<patch; ++x){ text.append(" > "); };
                text.append("<br>");
                QString b = QString::number(this->bank);
                if (b.size() < 2) { b.prepend("0"); };
                QString p = QString::number(this->patch);

                this->patchList.append("<br>[U"+b+":"+p+"] ");
                this->patchList.append(name);       // Set the patch name of the item in the list.
                text.append("<br>[U"+b+":"+p+"] ");
                text.append(name);       // Set the patch name of the item in the list.
                patch = patch + 1;
                count = count + 1;
                if (patch == 4)
                {
                    patch = 1;
                    bank = bank + 1;
                    this->patchList.append("<br>");
                };
                textDialog->setText(text);
            };

                int recount = 0;
                if(count < 297) // As long as we have items in the list we continue, duh! :)
                {
                    RESTART:
                    if(/*sysxIO->deviceReady() && */sysxIO->isConnected())
                    {
                        sysxIO->requestPatchName(bank, patch); // The patch name request.
                        emit setStatusSymbol(3);
                        emit setStatusMessage(tr("Reading names"));
                    }else{

                        if(recount<10)
                        {
                            SLEEP(100);
                            recount = recount + 1;
                            goto RESTART;
                        };
                    };
                }
                else {
                    SysxIO *sysxIO = SysxIO::Instance();
                    sysxIO->setDeviceReady(true);
                    emit setStatusSymbol(1);
                    emit setStatusMessage(tr("Ready"));
                    QDateTime dateTime = QDateTime::currentDateTime();
                    QString dateTimeString = dateTime.toString();
                    this->patchList.prepend(dateTimeString+"<br>");
                    this->patchList.prepend("ROLAND "+deviceType+" Patch List <br>");
                    textDialog->setText(this->patchList);
                };
}

void summaryDialogPatchList::cancel()
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(patchName(QString)),
                        this, SLOT(updatePatchNames(QString)));
    sysxIO->setDeviceReady(true);
    emit setStatusSymbol(1);
    emit setStatusMessage(tr("Ready"));
    this->deleteLater();
    this->close();
}

void summaryDialogPatchList::printFile()
{
//#ifdef Q_PROCESSOR_ARM
//#elif QT_NO_PRINTER

    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    //QPrintPreviewDialog *dialog = new QPrintPreviewDialog(&printer, this);
    dialog->setWindowTitle(tr("Print Document"));
    if (dialog->exec() != QDialog::Accepted) { return; }
    else { textDialog->print(&printer); };
    dialog->deleteLater();
//#endif
}

void summaryDialogPatchList::saveAs()
{

    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("Save As"),
                dir,
                tr("Text Document (*.txt)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".txt"))
        {
            fileName.append(".txt");
        };
        QFile file(fileName);

        QByteArray out;
        patchList.remove("<b>");
        patchList.remove("</b>");
        patchList.remove("<u>");
        patchList.remove("</u>");
        QString newLine;
        newLine.append((char)13);
        newLine.append((char)10);
        patchList.replace("<br>", newLine);

        unsigned int size = patchList.size();

        for (unsigned int x=0; x<size; x++)
        {

            QString str(patchList.at(x));
            //bool ok;
            //unsigned int n = str.toInt(&ok, 16);
            //out[count] = (char)n;
            out.append(str);

        };

        if (file.open(QIODevice::WriteOnly))
        {

            file.write(out);
        };

    };
}
