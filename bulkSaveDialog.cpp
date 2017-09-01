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
#include <QDataStream>
#include <QByteArray>
#include <QMessageBox>
#include "bulkSaveDialog.h"
#include "Preferences.h"
#include "globalVariables.h"


bulkSaveDialog::bulkSaveDialog()
{ 
    QLabel *startRangeLabel = new QLabel(tr("Start Patch."));
    QLabel *finishRangeLabel = new QLabel(tr("Finish Patch."));

    this->g5lButton = new QRadioButton(tr("*.g5l - Librarian compatable file - (G5L)"), this );
    this->syxButton = new QRadioButton(tr("*.syx - System Exclusive file - (SYX)"), this );
    this->midButton = new QRadioButton(tr("*.mid - Standard Midi file - (SMF)"), this );
    this->g5lButton->setChecked(true);
    
    QCheckBox *systemCheckBox = new QCheckBox(tr("Save System Data"));
    this->startRangeComboBox = new QComboBox(this);
    this->finishRangeComboBox = new QComboBox(this);

    this->systemCheckBox = systemCheckBox;

    for(int x=0; x<297; x++)
    {
        this->startRangeComboBox->addItem("Patch "+QString::number( x+1 ,10)+"    USER: "+QString::number((x/3)+1 ,10)+"-"+QString::number((x%3)+1 ,10)+"  ");
        this->finishRangeComboBox->addItem("Patch "+QString::number( x+1 ,10)+"    USER: "+QString::number((x/3)+1 ,10)+"-"+QString::number((x%3)+1 ,10)+"  ");
    };
    this->finishRangeComboBox->setCurrentIndex(296);

    QVBoxLayout *rangeLabelLayout = new QVBoxLayout;
    rangeLabelLayout->addSpacing(12);
    rangeLabelLayout->addWidget(startRangeLabel);
    rangeLabelLayout->addWidget(finishRangeLabel);

    QVBoxLayout *rangeBoxLayout = new QVBoxLayout;
    //rangeBoxLayout->addWidget(systemCheckBox);
    rangeBoxLayout->addSpacing(12);
    rangeBoxLayout->addWidget(startRangeComboBox);
    rangeBoxLayout->addSpacing(12);
    rangeBoxLayout->addWidget(finishRangeComboBox);

    QHBoxLayout *dataRangeLayout = new QHBoxLayout;
    dataRangeLayout->addSpacing(20);
    dataRangeLayout->addLayout(rangeLabelLayout);
    //dataRangeLayout->addSpacing(12);
    dataRangeLayout->addLayout(rangeBoxLayout);
    dataRangeLayout->addSpacing(20);

    QGroupBox *patchRangeGroup = new QGroupBox(tr("Set range of Patch data to save"));
    patchRangeGroup->setLayout(dataRangeLayout);

    this->startButton = new QPushButton(this);
    this->startButton->setText(tr("Start"));
    connect(startButton, SIGNAL(clicked()), this, SLOT(backup()));

    this->completedButton = new QPushButton(this);
    this->completedButton->setText(tr("DATA TRANSFER COMPLETED"));
    this->completedButton->hide();
    connect(completedButton, SIGNAL(clicked()), this, SLOT(DialogClose()));

    this->cancelButton = new QPushButton(this);
    this->cancelButton->setText(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(DialogClose()));

    this->progressLabel = new QLabel(this);
    this->progressLabel->setText(tr("Full Backup may take up to 2 minutes"));
    this->bytesLabel = new QLabel(this);
    this->bytesLabel->setText("");

    this->progressBar = new QProgressBar(this);
    this->progressBar->setTextVisible(false);
    this->progressBar->setRange(0, 100);
    this->progressBar->setValue(0);

    QVBoxLayout *fileFormatLayout = new QVBoxLayout;
    fileFormatLayout->addStretch(1);
    fileFormatLayout->addSpacing(6);
    fileFormatLayout->addWidget(g5lButton);
    fileFormatLayout->addStretch(1);
    fileFormatLayout->addSpacing(6);
    fileFormatLayout->addWidget(syxButton);
    fileFormatLayout->addStretch(1);
    fileFormatLayout->addSpacing(6);
    fileFormatLayout->addWidget(midButton);
    fileFormatLayout->addSpacing(6);
    QGroupBox *fileFormatGroup = new QGroupBox(tr("Select File format to save"));
    fileFormatGroup->setLayout(fileFormatLayout);

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
    mainLayout->addWidget(fileFormatGroup);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout, Qt::AlignCenter);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(patchRangeGroup, Qt::AlignCenter);
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

    setWindowTitle(tr("Bulk File Backup"));

    QObject::connect(this->startRangeComboBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( comboChanged() ));
    QObject::connect(this->finishRangeComboBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( comboChanged() ));
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::connect(this, SIGNAL(setStatusSymbol(int)), sysxIO, SIGNAL(setStatusSymbol(int)));
    QObject::connect(this, SIGNAL(setStatusProgress(int)), sysxIO, SIGNAL(setStatusProgress(int)));
    QObject::connect(this, SIGNAL(setStatusMessage(QString)), sysxIO, SIGNAL(setStatusMessage(QString)));

}

bulkSaveDialog::~bulkSaveDialog()
{
}

void bulkSaveDialog::comboChanged()
{
    if(this->startRangeComboBox->currentIndex()>this->finishRangeComboBox->currentIndex())
    { this->finishRangeComboBox->setCurrentIndex(this->startRangeComboBox->currentIndex()); };

    if(this->finishRangeComboBox->currentIndex()<this->startRangeComboBox->currentIndex())
    { this->startRangeComboBox->setCurrentIndex(this->finishRangeComboBox->currentIndex()); };
}

void bulkSaveDialog::backup()
{
    this->startButton->hide();
    //this->cancelButton->hide();
    this->patch_start = this->startRangeComboBox->currentIndex();
    this->patch_finish = this->finishRangeComboBox->currentIndex();
    this->patch_range = this->patch_finish-this->patch_start+1;
    this->bank = (patch_start/3)+1;
    this->patch = (patch_start%3)+1;
    bulk.clear();
    this->progress = 0;
    this->patch_count = 0;
    range = 100/(this->patch_range/3);
    requestPatch(bank, patch);
}

void bulkSaveDialog::requestPatch(int bank, int patch) 
{	
    SysxIO *sysxIO = SysxIO::Instance();
    if(sysxIO->isConnected() && sysxIO->deviceReady() && bank<100 )
    {
        SysxIO *sysxIO = SysxIO::Instance();
        QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));
        QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));
        sysxIO->requestPatch(bank, patch);
    };
}

void bulkSaveDialog::updatePatch(QString replyMsg)
{
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));
    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.

    replyMsg = replyMsg.remove(" ").toUpper();       // TRANSLATE SYSX MESSAGE FORMAT to 128 byte data blocks
    if (replyMsg.size()/2 == patchReplySize)
    {
        bad_hits=0;
        QString header = "F0411000005312";
        QString footer ="00F7";
        QString addressMsb = replyMsg.mid(14,4);    //  copy patch address MSB.
        QString part1 = replyMsg.mid(22, 256);      //  copy 128 bytes of address 00 data .
        part1.prepend("0000").prepend(addressMsb).prepend(header).append(footer);   //add LSB + MSB address, header and footer.
        QString part2 = replyMsg.mid(278, 256);     // copy 114 bytes of address 01 data.
        part2.prepend("0100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part3 = replyMsg.mid(534, 156);     //  copy 78 bytes of address 02 data .
        part3.prepend("0200").prepend(addressMsb).prepend(header).append(footer);  //add LSB + MSB address, header and footer.
        QString part4 = replyMsg.mid(716, 256);    //  copy 128 bytes of address 03 data .
        part4.prepend("0300").prepend(addressMsb).prepend(header).append(footer);  //add LSB + MSB address, header and footer.
        QString part5 = replyMsg.mid(972, 256);    // copy 114 bytes of address 04 data.
        part5.prepend("0400").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part6 = replyMsg.mid(1228, 36);    // copy 18 bytes of address 05 data.
        part6.prepend("0500").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part7 = replyMsg.mid(1290, 60);    // copy 30 bytes of address 06 data.
        part7.prepend("0600").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part8 = replyMsg.mid(1376, 250);   //  copy 125 bytes of address 07 data .
        part8.prepend("0700").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part9 = replyMsg.mid(1652, 256);   //  copy 128 bytes of address 10 data .
        part9.prepend("1000").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part10 = replyMsg.mid(1908,172);   //  copy 86 bytes of address 11 data .
        part10.prepend("1100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part11 = replyMsg.mid(2106, 70);    //  copy 35 bytes of address 20 data .
        part11.prepend("2000").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part12 = replyMsg.mid(2202, 70);    //  copy 35 bytes of address 21 data .
        part12.prepend("2100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.
        QString part13 = replyMsg.mid(2298, 104);   //  copy 52 bytes of address 30 data .
        part13.prepend("3000").prepend(addressMsb).prepend(header).append(footer);  //add LSB + MSB address, header and footer.
        QString part14 = replyMsg.mid(2428, 104);   //  copy 52 bytes of address 31 data .
        part14.prepend("3100").prepend(addressMsb).prepend(header).append(footer); //add LSB + MSB address, header and footer.

        replyMsg = "";
        replyMsg.append(part1).append(part2).append(part3).append(part4).append(part5).append(part6).append(part7)
                .append(part8).append(part9).append(part10).append(part11).append(part12).append(part13).append(part14);

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
        replyMsg = reBuild.simplified().toUpper();
        bulk.append(replyMsg); 	                                           // add patch to the bulk string.
        ++this->patch_count;
    }
    else
    {
            QMessageBox *msgBox = new QMessageBox();
            msgBox->setWindowTitle(deviceType + tr(" FloorBoard"));
            msgBox->setIcon(QMessageBox::Critical);
            msgBox->setTextFormat(Qt::RichText);
            QString msgText;
            msgText.append("<font size='+1'><b>");
            msgText.append(tr("Received patch data is corrupted or incomplete"));
            msgText.append("<b></font><br>");
            msgText.append(tr("Retry events have failed to retrieve the correct data<br>"));
            msgText.append(tr ("Do you wish to save the patch data anyway? "));
            msgBox->setInformativeText(tr("Are you sure you want to continue?"));
            msgBox->setText(msgText);
            msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);

            if(msgBox->exec() == QMessageBox::No)
            {
                DialogClose();
            };
            msgBox->deleteLater();
    };
    ++patch;
    if(patch>3) {patch=1; bank=bank+1;};	                      // increment patch.
    progress=progress+range;
    bulkStatusProgress(this->progress);                         // advance the progressbar.
    int bf = (patch_finish+1) -2;
    if (bank >= bf)
    {                                                            // check if nearly finished.
        this->completedButton->show();
        this->progressLabel->setText(tr("Bulk data transfer completed!!"));
    };
    if (this->patch_count<this->patch_range)
    {
        bool ok;
        QString patchText;
        QString name = replyMsg.mid(24, 32);                       // get name from loaded patch.
        QList<QString> x;
        for (int b=0;b<16;b++)
        {
            x.append(name.mid(b*2, 2));
        };
        for (int b=0;b<16;b++)
        {
            QString hexStr = x.at(b);
            patchText.append( (char)(hexStr.toInt(&ok, 16)) );      // convert name to readable text characters.
        };
        
        QString patchNumber = QString::number(bank, 10).toUpper();
        if (patchNumber.size()<2) { patchNumber.prepend("0"); };
        patchNumber.prepend(tr("User Patch U"));
        patchNumber.append("-");
        patchNumber.append( QString::number(patch, 10).toUpper() );
        patchNumber.append("     ");
        patchNumber.append(patchText);
        patchText=patchNumber;
        this->progressLabel->setText(patchText);                        //display the patch number and name.

        patchNumber = tr("File build size = ");
        int size = (bulk.size()/2)+fullPatchSize;
        patchNumber.append(QString::number(size, 10).toUpper() );
        patchNumber.append(tr(" bytes"));
        this->bytesLabel->setText(patchNumber);                         //display the bulk data size.

        setStatusMessage(tr("Bulk Download"));
        requestPatch(bank, patch);                                   //request the next patch.
    } else {
        setStatusMessage(tr("Ready"));
        sysxIO->bulk = this->bulk;
        if (this->g5lButton->isChecked() ) { writeG5L(); };                      // format and write bulk patches.
        if (this->syxButton->isChecked() ) { writeSYX(); };
        if (this->midButton->isChecked() ) { writeSMF(); };
    };
}

void bulkSaveDialog::bulkStatusProgress(int value)
{
    value=value/3;
    if (value >100) {value = 100;};
    if (value<0) {value = 0; };
    this->progressBar->setValue(value);
}

void bulkSaveDialog::writeG5L()         // ************************************ G5L File Format***************************
{	
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("Save Bulk Data"),
                dir,
                tr("Librarian Backup File (*.g5l)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".g5l"))
        {
            fileName.append(".g5l");
        };

        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly))
        {
            bool ok;
            QByteArray out;
            int size = this->bulk.size()/2;
            int patchCount = size/patchSize;
            for (int x=0;x<size*2;x++)
            {
                QString hexStr = bulk.mid(x, 2);
                out.append( (char)(hexStr.toInt(&ok, 16)) );          // convert the bulk QString to a QByteArray.
                ++x;
            };
            QByteArray bulkFile;
            QByteArray G5L_default;
            QByteArray temp;
            QFile G5Lfile(":default.g5l");           // Read the default GR-55 G5L file .
            if (G5Lfile.open(QIODevice::ReadOnly))
            {	G5L_default = G5Lfile.readAll(); };
            bulkFile.append(G5L_default.mid(0, 160));
            int b = 0;
            for (int x=0;x<patchCount;x++)
            {
                int a = 172;          // distance from start of single *.g5l file to patch data start.
                G5L_default.replace(a, 128, out.mid(b+11, 128));          //address "00"
                G5L_default.replace(a+128, 114, out.mid(b+152, 114));     //address "01"
                G5L_default.replace(a+250, 14, out.mid(b+266, 14));       //address "01 B"
                G5L_default.replace(a+264, 78, out.mid(b+293, 78));       //address "02"
                G5L_default.replace(a+350, 128, out.mid(b+384, 128));     //address "03"
                G5L_default.replace(a+478, 72, out.mid(b+525, 72));       //address "04"
                G5L_default.replace(a+606, 18, out.mid(b+666, 18));       //address "05"
                G5L_default.replace(a+640, 30, out.mid(b+697, 30));       //address "06"
                G5L_default.replace(a+678, 125, out.mid(b+740, 125));     //address "07"
                G5L_default.replace(a+811, 128, out.mid(b+878, 128));     //address "10"
                G5L_default.replace(a+939, 86, out.mid(b+1019, 86));      //address "11"
                G5L_default.replace(a+1033, 35, out.mid(b+1118, 35));     //address "20"
                G5L_default.replace(a+1072, 35, out.mid(b+1166, 35));     //address "21"
                G5L_default.replace(a+1115, 52, out.mid(b+1214, 52));     //address "30"
                G5L_default.replace(a+1171, 52, out.mid(b+1279, 52));     //address "31"

                temp.clear();
                QString hexStr = "04";
                temp.append((char)(hexStr.toInt(&ok, 16)));
                hexStr = "D3";
                temp.append((char)(hexStr.toInt(&ok, 16)));
                G5L_default.replace(162, 2, temp);     // replace patch size index

                b=b+patchSize;                                  // increment point to next *.syx patch in bulk.
                bulkFile.append(G5L_default.mid(160, 1239)); // copy most of the patch + index except for 4 text chars on end.
            };
            QString hex = QString::number(patchCount, 16).toUpper();     // convert integer to QString.
            if (hex.length() < 2) { hex.prepend("00"); }
            QByteArray count;
            count.append( (char)(hex.toInt(&ok, 16)) );
            bulkFile.replace(35, 1, count);     //   insert the correct patch count into the G5L file.
            count.clear();
            if (patchCount > 256) {hex = "01"; count.append( (char)(hex.toInt(&ok, 16)) );
                bulkFile.replace(34, 1, count);  };   //   insert the correct patch count into the G5L file.
            file.write(bulkFile);
        };
    };
    close();      // close the dialog page after the file has been saved or cancelled.
}

void bulkSaveDialog::writeSYX()        //********************************* SYX File Format *****************************
{	
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("Save Bulk Data"),
                dir,
                tr("System Exclusive Backup File (*.syx)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".syx"))
        {
            fileName.append(".syx");
        };

        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly))
        {
            bool ok;
            QByteArray out;
            int size = this->bulk.size()/2;
            //int patchCount = size/fullPatchSize;
            for (int x=0;x<size*2;x++)
            {
                QString hexStr = bulk.mid(x, 2);
                out.append( (char)(hexStr.toInt(&ok, 16)) );
                ++x;
            };
            file.write(out);
        };
    };
    close();
}

void bulkSaveDialog::writeSMF()    // **************************** SMF FILE FORMAT ***************************
{	
    Preferences *preferences = Preferences::Instance();
    QString dir = preferences->getPreferences("General", "Files", "dir");

    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("Save Bulk Data"),
                dir,
                tr("Standard Midi File (*.mid)"));
    if (!fileName.isEmpty())
    {
        if(!fileName.contains(".mid"))
        {
            fileName.append(".mid");
        };


        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly))
        {
            bool ok;
            QString out;
            QByteArray patches;
            int size = this->bulk.size()/2;
            int patchCount = size/patchSize;   //patchSize = 1333
            for (int x=0;x<size*2;x++)
            {
                QString hexStr = bulk.mid(x, 2);
                patches.append( (char)(hexStr.toInt(&ok, 16)) );          // convert the bulk QString to a QByteArray.
                ++x;
            };
            QByteArray bulkFile;
            QByteArray header;                        // TRANSLATION of GR-55 PATCHES, data read from GR55 syx patch **************
            QByteArray footer;                        // and used to replace GR55 patch SMF data*********************************
            QByteArray smf_build;
            QByteArray syx;
            QByteArray default_smf;
            QFile smffile(":default.mid");   // use a QByteArray of hex numbers from a lookup table.
            if (smffile.open(QIODevice::ReadOnly))
               { default_smf = smffile.readAll(); };
            header = default_smf.mid(0,22);
            footer = default_smf.mid(1342,4);
            int b = 0;
            for (int x=0;x<patchCount;x++)
            {
                syx.clear();
                syx.append( patches.mid(b, patchSize) );
                smf_build = default_smf;
                smf_build.replace(36, 128, syx.mid(11, 128));   //Address 00 00
                smf_build.replace(164, 114, syx.mid(152, 114)); //Address 00 00
                smf_build.replace(293, 14, syx.mid(266, 14));   //Address 01 72
                smf_build.replace(307, 78, syx.mid(293, 78));   //Address 01 72
                smf_build.replace(401, 128, syx.mid(384, 128)); //Address 03 00
                smf_build.replace(529, 114, syx.mid(525, 114)); //Address 03 00
                smf_build.replace(658, 14, syx.mid(639, 14));   //Address 04 72
                smf_build.replace(672, 18, syx.mid(666, 18));   //Address 04 72
                smf_build.replace(705, 30, syx.mid(697, 30));   //Address 06 00
                smf_build.replace(751, 125, syx.mid(740, 125)); //Address 07 00
                smf_build.replace(892, 128, syx.mid(878, 128)); //Address 10 00
                smf_build.replace(1020, 86, syx.mid(1019, 86)); //Address 11 00
                smf_build.replace(1121, 35, syx.mid(1118, 35)); //Address 20 00
                smf_build.replace(1171, 35, syx.mid(1166, 35)); //Address 21 00
                smf_build.replace(1221, 52, syx.mid(1214, 52)); //Address 30 00
                smf_build.replace(1288, 52, syx.mid(1279, 52)); //Address 31 00
                smf_build.replace(32, 2, syx.mid(7, 2));    //Replace patch Address 00 00
                smf_build.replace(289, 2, syx.mid(7, 2));   //Replace patch Address 01 72
                smf_build.replace(397, 2, syx.mid(7, 2));   //Replace patch Address 03 00
                smf_build.replace(654, 2, syx.mid(7, 2));   //Replace patch Address 04 72
                smf_build.replace(701, 2, syx.mid(7, 2));   //Replace patch Address 06 00
                smf_build.replace(747, 2, syx.mid(7, 2));   //Replace patch Address 07 00
                smf_build.replace(888, 2, syx.mid(7, 2));   //Replace patch Address 10 00
                smf_build.replace(1117, 2, syx.mid(7, 2));  //Replace patch Address 20 00
                smf_build.replace(1167, 2, syx.mid(7, 2));  //Replace patch Address 21 00
                smf_build.replace(1217, 2, syx.mid(7, 2));  //Replace patch Address 30 00
                smf_build.replace(1284, 2, syx.mid(7, 2));  //Replace patch Address 31 00

                smf_build.remove(1342, 4);      // remove file footer
                smf_build.remove(0, 22);  // remove File header

                QString sysxBuffer;
                QString checksum;
                int dataSize = 110; int offset = 0;
                for(int i=0;i<smf_build.size();i++)
                {
                    unsigned char byte = (char)smf_build[i];
                    unsigned int n = (int)byte;
                    QString hex = QString::number(n, 16).toUpper();
                    if (hex.length() < 2) hex.prepend("0");
                    sysxBuffer.append(hex);

                    unsigned char nextbyte = (char)smf_build[i+1];
                    unsigned int nextn = (int)nextbyte;
                    QString nexthex = QString::number(nextn, 16).toUpper();
                    if (nexthex.length() < 2) nexthex.prepend("0");

                    if(offset >= 9 && nexthex != "F7")   // smf offset is 8 bytes + previous byte
                    {
                        dataSize += n;
                    };
                    if(nexthex == "F7")
                    {
                        int sum = dataSize % 128;
                        if(sum!=0) { sum = 128 - sum; };
                        checksum = QString::number(sum, 16).toUpper();
                        if(checksum.length()<2) { checksum.prepend("0"); };
                    };

                    if(hex == "F7")
                    {
                        sysxBuffer.replace(sysxBuffer.size()-4, 2, checksum);
                        out.append(sysxBuffer);
                        sysxBuffer.clear();
                        dataSize = 110;
                        offset = 0;
                    };
                    offset++;
                };
                b=b+patchSize;
                QByteArray rebuild;
                    for (int k=0; k<out.size(); k++)
                    {
                        bool ok;
                        unsigned int n = out.mid(k, 2).toInt(&ok, 16);
                        rebuild[k/2] = (char)n;
                        ++k;
                    };
                out.clear();
                if(x>0 && x<patchCount-1) { rebuild.replace(0, 1, default_smf.mid(368, 1)); }; //add "08" marker between patches
                bulkFile.append(rebuild);      // append the bulk file.
            };
            bulkFile.prepend(header);   // add file header.
            bulkFile.append(footer);    // add file footer.
            QString file_size = QString::number((patchCount*1320)+4, 16).toUpper(); // calculate file size info
            if(file_size.size()==5) {file_size.prepend("0"); };
            if(file_size.size()==4) {file_size.prepend("00"); };
            if(file_size.size()==3) {file_size.prepend("000"); };
            QByteArray f_size;
            f_size[0] = (char)file_size.mid(0, 2).toInt(&ok, 16);
            f_size[1] = (char)file_size.mid(2, 2).toInt(&ok, 16);
            f_size[2] = (char)file_size.mid(4, 2).toInt(&ok, 16);

            bulkFile.replace(19, 3, f_size);   // replace 3 bytes of file size info
            file.write(bulkFile);
        };
        close();
    };
}

void bulkSaveDialog::DialogClose()
{
    bank = 100;
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(updatePatch(QString)));
    this->deleteLater();
    this->close();
}
