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
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include "bulkEditDialog.h"
#include "Preferences.h"
#include "globalVariables.h"
#include "SysxIO.h"


bulkEditDialog::bulkEditDialog(int partStart, int partLength, QString partHex1, QString partHex3)
{ 
    this->partialStart = partStart;
    this->partialLength = partLength;
    this->hex1 = partHex1;
    this->hex3 = partHex3;
    failed = true;
    QLabel *startListLabel = new QLabel(tr("Starting from"));
    this->startPatchCombo = new QComboBox(this);
    QLabel *finishListLabel = new QLabel(tr("Finishing at"));
    this->finishPatchCombo = new QComboBox(this);

    QVBoxLayout *comboBoxLayout = new QVBoxLayout;
    comboBoxLayout->addWidget(startListLabel);
    comboBoxLayout->addWidget(startPatchCombo);
    comboBoxLayout->addStretch(1);
    comboBoxLayout->addSpacing(12);
    comboBoxLayout->addWidget(finishListLabel);
    comboBoxLayout->addWidget(finishPatchCombo);

    QGroupBox *patchListGroup = new QGroupBox(tr("Set the Range of Patch data to modify"));
    patchListGroup->setLayout(comboBoxLayout);

    this->startButton = new QPushButton(this);
    this->startButton->setText(tr("Start"));
    connect(startButton, SIGNAL(clicked()), this, SLOT(sendData()));

    this->completedButton = new QPushButton(this);
    this->completedButton->setText(tr("DATA TRANSFER COMPLETED"));
    this->completedButton->hide();
    connect(completedButton, SIGNAL(clicked()), this, SLOT(close()));

    this->cancelButton = new QPushButton(this);
    this->cancelButton->setText(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

    this->progressLabel = new QLabel(this);
    this->progressLabel->setText(tr("WARNING!!: Existing Patch data will be over-written"));
    this->bytesLabel = new QLabel(this);
    this->bytesLabel->setText("");

    this->progressBar = new QProgressBar(this);
    this->progressBar->setTextVisible(false);
    this->progressBar->setRange(0, 100);
    this->progressBar->setValue(0);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addSpacing(40);
    buttonsLayout->addWidget(startButton);
    buttonsLayout->addStretch(1);
    buttonsLayout->addSpacing(20);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addSpacing(40);

    QHBoxLayout *progressBarLayout = new QHBoxLayout;
    progressBarLayout->addWidget(progressBar);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(patchListGroup, Qt::AlignCenter);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout, Qt::AlignCenter);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(progressLabel, Qt::AlignCenter);

    mainLayout->addWidget(bytesLabel, Qt::AlignCenter);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(completedButton);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(progressBarLayout, Qt::AlignCenter);
    setLayout(mainLayout);

    setWindowTitle(tr("Bulk Patch Modifier"));

    SysxIO *sysxIO = SysxIO::Instance();
    QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
    QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
    QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));
    QObject::connect(this, SIGNAL(setdeBugStatusMessage(QString)), sysxIO, SIGNAL(setStatusdBugMessage(QString)));

    Preferences *preferences = Preferences::Instance();
    bool ok;
    this->start = (preferences->getPreferences("Midi", "BulkStart", "patch").toInt(&ok, 10))-1;
    this->finish = (preferences->getPreferences("Midi", "BulkFinish", "patch").toInt(&ok, 10))-1;
    int p = 1;
    for (int b=0;b<297;++b)
    {
        QString text = QString::number((b/3)+1, 10).toUpper();
        if(text.size() < 2){ text.prepend("0"); };
        text.prepend("U");
        text.append(":");
        text.append(QString::number(p, 10).toUpper());
        p++;
        if (p>3) {p=1;};
        patchList.append(text);
    };
    this->startPatchCombo->addItems(patchList);            // add patch names to the combobox lists.
    this->finishPatchCombo->addItems(patchList);
    this->startPatchCombo->setCurrentIndex(this->start);
    this->finishPatchCombo->setCurrentIndex(this->finish);

    failed = false;
    if (failed == true)
    { this->startButton->hide(); };

    QObject::connect(startPatchCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(comboValueChanged(int)));
    QObject::connect(finishPatchCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(comboValueChanged(int)));

    prepareData();
}

bulkEditDialog::~bulkEditDialog()
{
}

void bulkEditDialog::comboValueChanged(int value)
{
    Preferences *preferences = Preferences::Instance();
    this->start = this->startPatchCombo->currentIndex();
    this->finish = this->finishPatchCombo->currentIndex();
    if(start>295){start=295; };
    if(finish<1){finish=1; };
    if(start>finish){start = finish-1; };
    if(finish<start){finish = start+1; };
    if(start<0){start=0; };
    if(finish>296){finish=296; };

    this->startPatchCombo->setCurrentIndex(this->start);
    this->finishPatchCombo->setCurrentIndex(this->finish);
    QString startIndex = QString::number(this->start+1, 10).toUpper();
    preferences->setPreferences("Midi", "BulkStart", "patch", startIndex);
    QString finishIndex = QString::number(this->finish+1, 10).toUpper();
    preferences->setPreferences("Midi", "BulkFinish", "patch", finishIndex);
}

void bulkEditDialog::sendData() 
{	 
    startButton->hide();
    //cancelButton->hide();
    progress = 0;
    patch = 1;
    range = (297)/((finish-start)+1);
    bank = (start+(patchPerBank-1));
    patch = bank/patchPerBank; patch = patch*patchPerBank; patch=bank-patch;
    patchRange = start;
    addrMSB = "20";
    steps=0;
    dataSent=0;
    sendSequence("");
}

void bulkEditDialog::sendPatch(QString data)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(sendSequence(QString)));
    data.append("F04110000053120F000001016FF7");   // key code to write data to GR-55 memory
    sysxIO->sendSysx(data);
}

void bulkEditDialog::sendSequence(QString value)
{ 
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(sendSequence(QString)));
    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
    /************* Replace the default address with the correct write address *****/
    QString q;
    QString address;
    QString msg = partialData;
    QString v;
    QString replyMsg;
    if (patchRange>=128 && addrMSB == "20") {patchRange=patchRange-128; addrMSB = "21"; }          // next address range when > 20 7F.
    else if (patchRange>=128 && addrMSB == "21") {patchRange=patchRange-128; addrMSB = "22"; };
    address = QString::number(patchRange, 16).toUpper();
    if (address.size()<2){ address.prepend("0"); };

    for (int g=0;g<msg.size()/2;g++)
    {
        v = msg.mid(g*2, 2);
        if (v == "F0") {msg.replace((g*2)+(sysxAddressOffset*2), 2, addrMSB); msg.replace((g*2)+((sysxAddressOffset*2)+2), 2, address); };   // replace the message address
    };
    replyMsg.append(msg);
    /************ Replace the checksum *********/
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
    msg = reBuild.simplified().toUpper();

    progress=progress+range;
    bulkStatusProgress(this->progress);                         // advance the progressbar.

    if (steps<((finish-start)+1) )
    {
        QString patchNumber;
        QString patchText = "'" + this->patchName + tr("' effect data pasted");
        int bf = (finish-start);
        if(steps>(bf-1))
        {
            this->completedButton->show();
            this->progressLabel->setText(tr("Bulk data transfer completed!!"));
            this->progress=297;
        } else {
        patchNumber = QString::number((bank/patchPerBank)+1, 10).toUpper();
        patchNumber.prepend(tr( "User Patch U" ));
        patchNumber.append("-");
        patchNumber.append( QString::number(patch, 10).toUpper() );
        patchNumber.append("     ");
        };
        patchNumber.append(patchText);
        patchText=patchNumber;
        this->progressLabel->setText(patchText);                        //display the patch number and name.

        patchNumber = tr("File transfer size = ");
        dataSent = dataSent+(msg.size()/2);
        patchNumber.append(QString::number(dataSent, 10).toUpper() );
        patchNumber.append(tr(" bytes"));
        this->bytesLabel->setText(patchNumber);                         //display the bulk data size.
        ++steps;
        ++patch;
        ++patchRange;
        if(patch>patchPerBank) {patch=1; bank=bank+patchPerBank;};	  // increment patch.
        sendPatch(msg);                                 //request the next patch.
        setStatusMessage(tr("Sending Data"));
    } else {
        QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(sendSequence(QString)));
        sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
        setStatusMessage(tr("Ready"));
        close();
    };
}


void bulkEditDialog::prepareData()
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString sysxMsg;
    QString hex;
    QList< QList<QString> > patchData = sysxIO->getFileSource().hex; // Get the loaded patch data.
    for(int i=0;i<patchData.size();++i)
    {
        QList<QString> data = patchData.at(i);
        for(int x=0;x<data.size();++x)
        {
            hex = data.at(x);
            if (hex.length() < 2) hex.prepend("0");
            sysxMsg.append(hex);
        };
    };
    if( partialStart>0 && partialLength>0)
    {
        this->patchName = sysxIO->getCurrentPatchName();
        QString temp = sysxMsg.mid(this->partialStart, this->partialLength);
        this->partialData = "F04110000053122000" + this->hex1 + this->hex3 + temp + "00F7";
    } else {
        QApplication::beep();
        QString size = QString::number(sysxMsg.size()/2, 10);
        sysxIO->emitStatusdBugMessage(tr("in-consistant patch data detected ") + size + tr("bytes: re-save or re-load file to correct"));
    };
}

void bulkEditDialog::bulkStatusProgress(int value)
{
    value=value/3;
    if (value >100) {value = 100;};
    if (value<0) {value = 0; };
    this->progressBar->setValue(value);
}

void bulkEditDialog::close()
{
    steps = 300;
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(sendSequence(QString)));
    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
    setStatusMessage(tr("Ready"));
    this->deleteLater();
}


