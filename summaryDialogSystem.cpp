/****************************************************************************
**
** Copyright (C) 2007~2016 Colin Willcocks.
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
#include <QFile>
#include "summaryDialogSystem.h"
#include "Preferences.h"
#include "SysxIO.h"
#include "MidiTable.h"
#include "globalVariables.h"

summaryDialogSystem::summaryDialogSystem(QWidget *parent)
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
    
    if(sysxIO->deviceReady())
    {
        emit setStatusMessage(tr("Opening Page..."));
        emit setStatusSymbol(3);
        QString replyMsg;
        if (sysxIO->isConnected())
        {
            sysxIO->setDeviceReady(false); // Reserve the device for interaction.
            QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
            QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(systemReply(QString)));
            emit setStatusProgress(100);
            emit setStatusSymbol(2);
            emit setStatusProgress(0);
            emit setStatusMessage(tr("Request System data"));
            sysxIO->sendSysx(systemRequest); // GR-55 System area data Request.
        }
        else
        {
            QString snork = tr("Ensure connection is active and retry<br>");
            snork.append(tr("System data not transfered, current settings are to be used<br>"));
            QMessageBox *msgBox = new QMessageBox();
            msgBox->setWindowTitle(deviceType + tr(" midi connection not found!!"));
            msgBox->setIcon(QMessageBox::Information);
            msgBox->setText(snork);
            msgBox->show();
            QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
            emit setStatusMessage(tr("Not Connected"));
            emit setStatusSymbol(0);
        };
    };
}

void summaryDialogSystem::do_the_list()
{
    /*********************************************************************/
    /************** The System List **************************************/
    /*********************************************************************/
    //MidiTable *midiTable = MidiTable::Instance();
    text = "<b>ROLAND " + deviceType + " System/Global Summary</b>    ";
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString();
    text.append(dateTimeString);
    
    text.append("<br><br><b><u>**********Current patch***********</b></u><br>");
    address1= "01";
    address2= "00";
    start = 0;
    finish = 1;
    makeList();

    text.append("<br><br><b><u>**********System and Midi settings**********</b></u><br>");
    address1= "02";
    address2= "00";
    start = 0;
    finish = 32;
    makeList();

    text.append("<br><br><b><u>**********System Pedal and GK control**********</b></u><br>");
    address1= "02";
    address2= "02";
    start = 0;
    finish = 127;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 1**********</b></u><br>");
    address1= "02";
    address2= "04";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode set 2**********</b></u><br>");
    address1= "02";
    address2= "05";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 3**********</b></u><br>");
    address1= "02";
    address2= "06";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 4**********</b></u><br>");
    address1= "02";
    address2= "07";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 5**********</b></u><br>");
    address1= "02";
    address2= "08";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 6**********</b></u><br>");
    address1= "02";
    address2= "09";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 7**********</b></u><br>");
    address1= "02";
    address2= "0A";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 8**********</b></u><br>");
    address1= "02";
    address2= "0B";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 9**********</b></u><br>");
    address1= "02";
    address2= "0C";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Guitar Mode GK set 10**********</b></u><br>");
    address1= "02";
    address2= "0D";
    start = 0;
    finish = 35;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 1**********</b></u><br>");
    address1= "02";
    address2= "04";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 2**********</b></u><br>");
    address1= "02";
    address2= "05";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 3**********</b></u><br>");
    address1= "02";
    address2= "06";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 4**********</b></u><br>");
    address1= "02";
    address2= "07";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 5**********</b></u><br>");
    address1= "02";
    address2= "08";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 6**********</b></u><br>");
    address1= "02";
    address2= "09";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 7**********</b></u><br>");
    address1= "02";
    address2= "0A";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 8**********</b></u><br>");
    address1= "02";
    address2= "0B";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 9**********</b></u><br>");
    address1= "02";
    address2= "0C";
    start = 35;
    finish = 71;
    makeList();

    text.append("<br><br><b><u>**********Bass Mode GK set 10**********</b></u><br>");
    address1= "02";
    address2= "0D";
    start = 35;
    finish = 71;
    makeList();

    /*
  text.append("<br><br><b><u>********** MIDI ***********</b></u><br>");
  address1= "02";
  address2= "00";
  start = 0;
  finish = 14;
  makeList();
  
  text.append("<br><br><b><u>********** MIDI MAPPING ***********</b></u><br><br>");
  address1= "02";
  address2= "01";
  finish = 127;
  makeMidiMapList();
  address1= "02";
  address2= "02";
  finish = 127;
  makeMidiMapList();
  address1= "02";
  address2= "03";
  finish = 127;
  makeMidiMapList();
  address1= "02";
  address2= "04";
  finish = 127;
  makeMidiMapList();
  address1= "02";
  address2= "05";
  finish = 127;
  makeMidiMapList();
  address1= "02";
  address2= "06";
  finish = 127;
  makeMidiMapList();
  address1= "02";
  address2= "07";
  finish = 127;
  makeMidiMapList();
  address1= "02";
  address2= "08";
  finish = 72;
  makeMidiMapList();
  
  */




    textDialog->setText(text);
    textDialog->show();

    QPushButton *cancelButton = new QPushButton(tr("Close"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    cancelButton->setWhatsThis(tr("Will close the currently open Dialog page."));
    //cancelButton->hide();

    QPushButton *printButton = new QPushButton(tr("Print"));
    connect(printButton, SIGNAL(clicked()), this, SLOT(printFile()));
    printButton->setWhatsThis(tr("Will Print the current Dialog to the prefered printer<br>printed text will be simular to the screen layout."));
    //printButton->hide();

    QPushButton *saveAsButton = new QPushButton(tr("Save As"));
    connect(saveAsButton, SIGNAL(clicked()), this, SLOT(saveAs()));
    saveAsButton->setWhatsThis(tr("Will save the current dialog page to file in a *.txt format."));
    //saveAsButton->hide();

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

    setWindowTitle(deviceType + tr(" System and Global List Summary"));
}

void summaryDialogSystem::systemReply(QString replyMsg)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(systemReply(QString)));
    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.

    if(sysxIO->noError())
    {
        if(replyMsg.size()/2 == 1173)  // data format from the GR-55
        {
            /* TRANSLATE SYSX MESSAGE FORMAT to 128 byte data blocks */
            QString part1 = replyMsg.mid(0, 412); //from 0, copy system data upto 02000200 byte 128
            part1.append("7FF7");
            QString part2 = replyMsg.mid(412, 1934);
            part2.prepend("F041100000531202000300");
            replyMsg = "";
            replyMsg.append(part1).append(part2);
            QString reBuild = "";       // Add correct checksum to patch strings
            QString sysxEOF = "";
            QString hex = "";
            int msgLength = replyMsg.length()/2;
            for(int i=0;i<msgLength*2;++i)
            {
                hex.append(replyMsg.mid(i*2, 2));
                sysxEOF = (replyMsg.mid((i*2)+4, 2));
                if (sysxEOF == "F7")
                {
                    int dataSize = 0; bool ok;
                    for(int h=checksumOffset;h<hex.size()-1;++h)
                    { dataSize += hex.mid(h*2, 2).toInt(&ok, 16); };
                    QString base = "80";                       // checksum calculate.
                    unsigned int sum = dataSize % base.toInt(&ok, 16);
                    if(sum!=0) { sum = base.toInt(&ok, 16) - sum; };
                    QString checksum = QString::number(sum, 16).toUpper();
                    if(checksum.length()<2) {checksum.prepend("0");};
                    hex.append(checksum);
                    hex.append("F7");
                    reBuild.append(hex);

                    hex = "";
                    sysxEOF = "";
                    i=i+2;
                };
            };
            replyMsg = reBuild.simplified().toUpper().remove("0X").remove(" ");
            QString area = "System";
            sysxIO->setFileSource(area, replyMsg);		// Set the source to the data received.
            //sysxIO->setFileSource(area, sysxMsg.getSystemSource());
            sysxIO->setFileName(tr("System Data from ") + deviceType);	// Set the file name to GR-55B system for the display.
            sysxIO->setDevice(true);				// Patch received from the device so this is set to true.
            sysxIO->setSyncStatus(true);			// We can't be more in sync than right now! :)
            do_the_list();
        }
        else
        {
            QMessageBox *msgBox = new QMessageBox();
            msgBox->setWindowTitle(deviceType + tr(" FloorBoard connection Error !!"));
            msgBox->setIcon(QMessageBox::Warning);
            msgBox->setTextFormat(Qt::RichText);
            QString msgText;
            msgText.append("<font size='+1'><b>");
            msgText.append(tr("The ROLAND ") + deviceType + tr(" System data was not transfered !!."));
            msgText.append("<b></font><br>");
            msgBox->setText(msgText);
            msgBox->show();
            QTimer::singleShot(3000, msgBox, SLOT(deleteLater()));
        };
    };
    emit setStatusMessage(tr("Ready"));
}

void summaryDialogSystem::cancel()
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(patchName(QString)),
                        this, SLOT(updatePatchNames(QString)));
    sysxIO->setDeviceReady(true);
    emit setStatusSymbol(1);
    emit setStatusMessage(tr("Ready"));
    this->close();
}

void summaryDialogSystem::printFile()
{
//#ifdef  Q_PROCESSOR_ARM
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

void summaryDialogSystem::saveAs()
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
        text.remove("<b>");
        text.remove("</b>");
        text.remove("<u>");
        text.remove("</u>");
        QString newLine;
        newLine.append((char)13);
        newLine.append((char)10);
        text.replace("<br>", newLine);

        unsigned int size = text.size();

        for (unsigned int x=0; x<size; x++)
        {
            QString str(text.at(x));
            out.append(str);
        };

        if (file.open(QIODevice::WriteOnly))
        {
            file.write(out);
        };

    };
}

void summaryDialogSystem::makeList()
{
    SysxIO *sysxIO = SysxIO::Instance();
    MidiTable *midiTable = MidiTable::Instance();
    for(int i=start;i<finish;i++ )
    {
        QString pos = QString::number(i, 16).toUpper();
        if(pos.size()<2){ pos.prepend("0"); };
        QString pretxt =  midiTable->getMidiMap("System", address1, address2, pos).desc;
        QString txt =  midiTable->getMidiMap("System", address1, address2, pos).customdesc;
        if(!txt.isEmpty() && txt != "")
        {
            int value = sysxIO->getSourceValue("System", address1, address2, pos);
            QString valueHex = QString::number(value, 16).toUpper();
            if(valueHex.length() < 2) {valueHex.prepend("0"); };
            if (txt != "#")
            {
                text.append("<br>");
                text.append("[");
                if(!pretxt.isEmpty() && txt != "") { text.append(pretxt + " "); };
                text.append(txt);
                text.append("] = ");
            };
            text.append(midiTable->getValue("System", address1, address2, pos, valueHex) );
        };
    };
}

void summaryDialogSystem::makeMidiMapList()
{
    SysxIO *sysxIO = SysxIO::Instance();
    MidiTable *midiTable = MidiTable::Instance();
    int row = 1;
    bool ok;
    QList <QString> sysxData = sysxIO->getFileSource("System", address1, address2);
    for(int i=0;i<finish;i++ )
    {
        QString pos = QString::number(i, 16).toUpper();
        if(pos.size()<2){ pos.prepend("0"); };
        QString txt =  midiTable->getMidiMap("System", "02", address2, pos).customdesc;
        if(!txt.isEmpty())
        {
            int value1 = sysxData.at(sysxDataOffset + i).toInt(&ok, 16);;
            int value2 = sysxData.at(sysxDataOffset + i + 1).toInt(&ok, 16);;
            int value = (value1*128) + value2;
            QString valueHex = QString::number(value, 16).toUpper();
            if(valueHex.length() < 2) {valueHex.prepend("0"); };

            text.append("[");
            text.append(txt);
            text.append("] = ");
            text.append(midiTable->getValue("System", "02", "01", "00", valueHex) );
            text.append(".    .");
            ++row;
            if (row >= 5) {row = 1; text.append("<br>"); };
        };
        ++i;
    };
}



