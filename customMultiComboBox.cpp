/****************************************************************************
**
** Copyright (C) 2007~2015 Colin Willcocks.
** All rights reserved.
** This file is part of "GT-100 Fx FloorBoard".
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

#include "customMultiComboBox.h"
#include "customControlMidiTable.h"
#include "MidiTable.h"
#include "SysxIO.h"
#include "globalVariables.h"

customMultiComboBox::customMultiComboBox(QWidget *parent,
                                         QString hex1, QString hex2, QString hex3,
                                         QString direction)
    : QWidget(parent)
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->area = "MidiT";
    pc_index = 0;
    direction = "nul";

    setComboBoxList();
    makeList();

    QObject::connect(this, SIGNAL( updateSignal() ), this->parent(), SIGNAL( updateSignal() ));
}

void customMultiComboBox::makeList()
{
    // strings of row lists initialised for PC labels 1~128
    QString bankList;
    QString pcList;
    QString pcList_01;
    QString pcList_02;
    QString pcList_03;
    QString pcList_04;
    QString pcList_05;
    QString pcList_06;
    QString pcList_07;
    QString pcList_08;
    // create 16 label items per row to display 128 Patch Change items per Bank
    for(int x=1; x<129; ++x)
    {
        QString num = QString::number(x, 10).toUpper();
        if(num.length() < 2) {num.prepend("00"); }
        else if(num.length() < 3) {num.prepend("0"); };
        pcList.append("PC:"+num+" ");
        if(x<17)        {pcList_01.append("  PC:"+num+"     "); };
        if(x>16 && x<33){pcList_02.append("  PC:"+num+"     "); };
        if(x>32 && x<49){pcList_03.append("  PC:"+num+"     "); };
        if(x>48 && x<65){pcList_04.append("  PC:"+num+"     "); };
        if(x>64 && x<81){pcList_05.append("  PC:"+num+"     "); };
        if(x>80 && x<97){pcList_06.append("  PC:"+num+"     "); };
        if(x>96 && x<113){pcList_07.append("  PC:"+num+"     "); };
        if(x>112 && x<129){pcList_08.append("  PC:"+num+"     "); };
    };
    for(int b=0; b<65; ++b)
    {
        QString num = QString::number(b, 10).toUpper();
        if(num.length() < 2) {num.prepend("0"); }
        bankList.append("Bank:"+num+" ");
    };
    display_01 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_02 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_03 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_04 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_05 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_06 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_07 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_08 = new customControlMidiTable(this, hex1, hex2 ,hex3, area, "label");
    display_09 = new customControlMidiTable(this, hex1, hex2 ,hex3, "Bank", bankList);
    display_10 = new customControlMidiTable(this, hex1, hex2 ,hex3, "Program Change", pcList);
    display_11 = new customControlMidiTable(this, hex1, hex2 ,hex3, "GR-55 Patch", comboList);

    QVBoxLayout *oneLayout = new QVBoxLayout;
    oneLayout->setMargin(0);
    oneLayout->setSpacing(10);
    oneLayout->addStretch(0);
    oneLayout->addWidget(display_01, 0, Qt::AlignCenter);
    oneLayout->addWidget(display_02, 0, Qt::AlignCenter);
    oneLayout->addWidget(display_03, 0, Qt::AlignCenter);
    oneLayout->addWidget(display_04, 0, Qt::AlignCenter);
    oneLayout->addWidget(display_05, 0, Qt::AlignCenter);
    oneLayout->addWidget(display_06, 0, Qt::AlignCenter);
    oneLayout->addWidget(display_07, 0, Qt::AlignCenter);
    oneLayout->addWidget(display_08, 0, Qt::AlignCenter);

    QHBoxLayout *twoLayout = new QHBoxLayout;
    twoLayout->setMargin(0);
    twoLayout->setSpacing(10);
    twoLayout->addStretch(10);
    twoLayout->addWidget(display_09, 0, Qt::AlignCenter);
    twoLayout->addWidget(display_10, 0, Qt::AlignCenter);
    twoLayout->addWidget(display_11, 0, Qt::AlignCenter);

    QVBoxLayout *mLayout = new QVBoxLayout;
    mLayout->setMargin(0);
    mLayout->setSpacing(10);
    mLayout->addStretch(0);
    mLayout->addLayout(oneLayout);
    mLayout->addLayout(twoLayout);
    this->setLayout(mLayout);

    display_01->label->setText(pcList_01);
    display_02->label->setText(pcList_02);
    display_03->label->setText(pcList_03);
    display_04->label->setText(pcList_04);
    display_05->label->setText(pcList_05);
    display_06->label->setText(pcList_06);
    display_07->label->setText(pcList_07);
    display_08->label->setText(pcList_08);

    displayUpdate();

    QObject::connect(this, SIGNAL( updateSignal() ), this->parent(), SIGNAL( updateSignal() ));
}

void customMultiComboBox::setComboBoxList()
{
    MidiTable *midiTable = MidiTable::Instance();
    Midi item_0;
    Midi item_1;
    Midi item_2;
    Midi item_3;
    Midi item_4;
    item_0 = midiTable->getMidiMap("MPT", "00", "00", "00", "00");
    item_1 = midiTable->getMidiMap("MPT", "00", "00", "00", "01");
    item_2 = midiTable->getMidiMap("MPT", "00", "00", "00", "02");
    item_3 = midiTable->getMidiMap("MPT", "00", "00", "00", "03");
    item_4 = midiTable->getMidiMap("MPT", "00", "00", "00", "04");

    itemcount = 0;
    int itemSize = item_0.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        this->comboList.append(item_0.level.at(itemcount).name+" ");
    };

    itemSize = item_1.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        this->comboList.append(item_1.level.at(itemcount).name+" ");
    };

    itemSize = item_2.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        this->comboList.append(item_2.level.at(itemcount).name+" ");
    };

    itemSize = item_3.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        this->comboList.append(item_3.level.at(itemcount).name+" ");
    };

    itemSize = item_4.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        this->comboList.append(item_4.level.at(itemcount).name+" ");
    };
}

void customMultiComboBox::valueChanged(int index)
{
    // when GR-55 patch combo is changed
    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    int dif = index/128;
    QString valueHex1 = QString::number(dif, 16).toUpper();
    if(valueHex1.length() < 2) valueHex1.prepend("0");
    QString valueHex2 = QString::number(index - (dif * 128), 16).toUpper();
    if(valueHex2.length() < 2) valueHex2.prepend("0");  // index converted to 2 byte QString.
    QString valueHex3 = "0";
    valueHex3.append(valueHex2.mid(1,1));
    valueHex2.remove(1,1);
    valueHex2.prepend("0");    // convert to a 3 byte '0' separated string.

    int hex_2 = QString(this->hex2).toInt(&ok, 16);
    int hex_3 = QString(this->hex3).toInt(&ok, 16);
    hex_3 = hex_3 + (display_10->controlMidiComboBox->currentIndex()*3);  //MPT patch x 3
    if(hex_3 > 127) {hex_3 = hex_3 - 128; hex_2 = hex_2 + 1; };
    if(hex_3 > 127) {hex_3 = hex_3 - 128; hex_2 = hex_2 + 1; };
    if(hex_3 > 127) {hex_3 = hex_3 - 128; hex_2 = hex_2 + 1; };
    hex_2 = hex_2 + display_09->controlMidiComboBox->currentIndex();  //MPT bank
    QString hex_02 = QString::number(hex_2, 16).toUpper();
    if(hex_02.length() < 2) {hex_02.prepend("0"); }
    QString hex_03 = QString::number(hex_3, 16).toUpper();
    if(hex_03.length() < 2) {hex_03.prepend("0"); }

    QString sysxMsg = "F0411000005312";
    sysxMsg.append("02"+hex1+hex_02+hex_03+valueHex1+valueHex2+valueHex3);
    int dataSize = 0;
    for(int h=checksumOffset;h<sysxMsg.size()-1;++h)
    { dataSize += sysxMsg.mid(h*2, 2).toInt(&ok, 16); };
    QString base = "80";                                   // checksum calculate.
    unsigned int sum = dataSize % base.toInt(&ok, 16);
    if(sum!=0) { sum = base.toInt(&ok, 16) - sum; };
    QString checksum = QString::number(sum, 16).toUpper();
    if(checksum.length()<2) {checksum.prepend("0");};
    sysxMsg.append(checksum);
    sysxMsg.append("F7");
    if(sysxIO->isConnected() && sysxIO->deviceReady() )
    {
        sysxIO->setDeviceReady(false);

        emit sysxIO->setStatusSymbol(2);
        emit sysxIO->setStatusMessage(tr("Sending"));

        QObject::connect(sysxIO, SIGNAL(sysxReply(QString)),
                         sysxIO, SLOT(resetDevice(QString)));

        sysxIO->sendSysx(sysxMsg);
    }
    else if(sysxIO->isConnected())
    {
        sysxIO->sendSpooler.append(sysxMsg);
    };

    displayUpdate();
    emit updateSignal();
}

void customMultiComboBox::dialogUpdateSignal()
{

}

void customMultiComboBox::displayUpdate()
{
    QString patchList_01;
    QString patchList_02;
    QString patchList_03;
    QString patchList_04;
    QString patchList_05;
    QString patchList_06;
    QString patchList_07;
    QString patchList_08;
    QStringList list = comboList.split(" ");
    bool ok;
    QList <QString> items;
    items = getMPTitems();  // get the data block from the GR-55 system MPT area

    for(int x=1; x<129; ++x) // list of 128 patches on the page
    {
        QString num;
        if(items.size()==382)
        {
            QString v = items.at(x-1);
            int index = v.toInt(&ok, 16);                   //work in progress
            num = list.at(index);
            num.prepend("__");
        } else {
            num="_no_data_";
        };
        if(x<17)        {patchList_01.append(num); };
        if(x>16 && x<33){patchList_02.append(num); };
        if(x>32 && x<49){patchList_03.append(num); };
        if(x>48 && x<65){patchList_04.append(num); };
        if(x>64 && x<81){patchList_05.append(num); };
        if(x>80 && x<97){patchList_06.append(num); };
        if(x>96 && x<113){patchList_07.append(num); };
        if(x>112 && x<129){patchList_08.append(num); };
    };
    display_01->display->setText(patchList_01);
    display_02->display->setText(patchList_02);
    display_03->display->setText(patchList_03);
    display_04->display->setText(patchList_04);
    display_05->display->setText(patchList_05);
    display_06->display->setText(patchList_06);
    display_07->display->setText(patchList_07);
    display_08->display->setText(patchList_08);

}

void customMultiComboBox::changedIndex(int index)
{
    index++;
    // when bank combo is changed
    displayUpdate();
}

QList<QString> customMultiComboBox::getMPTitems()
{
    MPT_items.clear();
    //create a sudo list of MPT items for testing
    for(int x=0; x<382; ++x)
    {
        QString num = QString::number(x, 16).toUpper();
        if(num.length()<3) {num.prepend("0");};
        if(num.length()<3) {num.prepend("0");};
        MPT_items.append(num);
    };
    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    sysxIO->setStatusProgress(100);
    if (sysxIO->isConnected() && sysxIO->deviceReady())
    {
        sysxIO->setStatusSymbol(2);
        sysxIO->setStatusMessage(tr("Request MPT data"));
        sysxIO->setDeviceReady(false); // Reserve the device for interaction.
        QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)));
        QObject::connect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(MPTReply(QString)));
        int bank = (this->hex2.toInt(&ok, 16)*128)+this->hex3.toInt(&ok, 16)+
                (display_09->controlMidiComboBox->currentIndex()*4);   // get bank combo value
        QString hex_02 = QString::number(bank/128, 16).toUpper();
        if(hex_02.length()<2) {hex_02.prepend("0"); };
        int msb = bank/128;
        int lsb = bank-(msb*128);
        QString hex_03 = QString::number(lsb, 16).toUpper();
        if(hex_03.length()<2) {hex_03.prepend("0"); };
        QString MPTrequest = "F041100000531102"+hex_02+hex_03+"0000000300";
        int dataSize = 0; bool ok;
        for(int h=checksumOffset;h<MPTrequest.size()-1;++h)
        { dataSize += MPTrequest.mid(h*2, 2).toInt(&ok, 16); };
        QString base = "80";                                   // checksum calculate.
        unsigned int sum = dataSize % base.toInt(&ok, 16);
        if(sum!=0) { sum = base.toInt(&ok, 16) - sum; };
        QString checksum = QString::number(sum, 16).toUpper();
        if(checksum.length()<2) {checksum.prepend("0");};
        MPTrequest.append(checksum);
        MPTrequest.append("F7");
        sysxIO->sendSysx(MPTrequest); // GR-55 System MPT bank data Request.
        sysxIO->setStatusProgress(0);
    };
    //return MPT_items;
}

QList<QString> customMultiComboBox::MPTReply(QString replyMsg)
{
    QString test;
    QList <QString> items;
    SysxIO *sysxIO = SysxIO::Instance();
    QObject::disconnect(sysxIO, SIGNAL(sysxReply(QString)), this, SLOT(MPTReply(QString)));
    sysxIO->setDeviceReady(true); // Free the device after finishing interaction.
        if(sysxIO->noError() && replyMsg.size()/2 == 397)  // data format from the GR-55 MPT
        {
            replyMsg = replyMsg.mid(22, 764).simplified().toUpper(); //copy data bits only
            for (int x=0; x<397; ++x)
            {
                items.append(replyMsg.mid(x*2, 2));
                test.append(replyMsg.mid(x*2, 2)+" ");
            };
        } else
        { items = MPT_items; };
    sysxIO->setStatusMessage(tr("Ready"));
    bool ok;
    int MPT_MSB = (replyMsg.mid(16, 2).toInt(&ok, 16)-this->hex2.toInt(&ok, 16))*128;
    int MPT_LSB = (replyMsg.mid(18, 2).toInt(&ok, 16));
    this->MPT_index = MPT_MSB+MPT_LSB;
    return items;
}

