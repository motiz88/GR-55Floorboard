/****************************************************************************
**
** Copyright (C) 2007~2013 Colin Willcocks.
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

customMultiComboBox::customMultiComboBox(QWidget *parent,
                                         QString hex1, QString hex2, QString hex3,
                                         QString direction)
    : QWidget(parent)
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->direction = direction;
    if (direction.contains("System")) {this->area = "System"; }
    else {this->area = "Structure"; };
    pc_index = 0;

    setComboBoxList();
    makeList();

    QObject::connect(this, SIGNAL( updateSignal() ), this->parent(), SIGNAL( updateSignal() ));
}

void customMultiComboBox::makeList()
{
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
    display_01 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
    display_02 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
    display_03 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
    display_04 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
    display_05 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
    display_06 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
    display_07 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
    display_08 = new customControlMidiTable(this, hex1, hex2 ,hex3, direction, "label");
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
    twoLayout->setSpacing(0);
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

    SysxIO *sysxIO = SysxIO::Instance();
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
    int hex_2 = QString(hex2).toInt(&ok, 16);
    int hex_3 = QString(hex3).toInt(&ok, 16);
    for(int x=1; x<129; ++x)
    {
        if(hex_3 > 127) {hex_3 = hex_3 - 128; hex_2 = hex_2 + 1; };
        QString hex_02 = QString::number(hex_2, 16).toUpper();
        if(hex_02.length() < 2) {hex_02.prepend("0"); }
        QString hex_03 = QString::number(hex_3, 16).toUpper();
        if(hex_03.length() < 2) {hex_03.prepend("0"); }
        int index = 0;//sysxIO->getSourceValue("MidiT", hex1, hex_02, hex_03);
        QString num = list.at(index);
        if(x<17)        {patchList_01.append("   "+num+"  "); };
        if(x>16 && x<33){patchList_02.append("   "+num+"  "); };
        if(x>32 && x<49){patchList_03.append("   "+num+"  "); };
        if(x>48 && x<65){patchList_04.append("   "+num+"  "); };
        if(x>64 && x<81){patchList_05.append("   "+num+"  "); };
        if(x>80 && x<97){patchList_06.append("   "+num+"  "); };
        if(x>96 && x<113){patchList_07.append("   "+num+"  "); };
        if(x>112 && x<129){patchList_08.append("   "+num+"  "); };
        hex_3 = hex_3 + 2;
    };
    display_01->display->setText(patchList_01);
    display_02->display->setText(patchList_02);
    display_03->display->setText(patchList_03);
    display_04->display->setText(patchList_04);
    display_05->display->setText(patchList_05);
    display_06->display->setText(patchList_06);
    display_07->display->setText(patchList_07);
    display_08->display->setText(patchList_08);


    QObject::connect(this, SIGNAL( updateSignal() ), this->parent(), SIGNAL( updateSignal() ));
}

//void customMultiComboBox::paintEvent(QPaintEvent *)
//{
/*DRAWS RED BACKGROUND FOR DeBugGING PURPOSE */
/*QPixmap image(":images/dragbar.png");

        QRectF target(0.0, 0.0, this->width(), this->height());
        QRectF source(0.0, 0.0, this->width(), this->height());

        QPainter painter(this);
        painter.drawPixmap(target, image, source);*/
//}

void customMultiComboBox::setComboBoxList()
{
    MidiTable *midiTable = MidiTable::Instance();
    Midi items;
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
    items = item_0;

    QString longestItem = "";
    itemcount = 0;
    int itemSize = items.level.size();
    int itemTotal = 0;
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        QString item;
        QString desc = items.level.at(itemcount).name;
        if(!desc.isEmpty())
        {
            item = desc;
        }
        else
        {
            item = "Out of Range";
        };
        if(longestItem.size() < item.size()) longestItem = item;
        this->comboList.append(item);
        this->comboList.append(" ");
    };

    itemTotal = itemTotal + itemcount;
    items = item_1;
    itemSize = items.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        QString item;
        QString desc = items.level.at(itemcount).name;
        if(!desc.isEmpty())
        {
            item = desc;
        }
        else
        {
            item = "Out of Range";
        };
        if(longestItem.size() < item.size()) longestItem = item;
        this->comboList.append(item);
        this->comboList.append(" ");
    };

    itemTotal = itemTotal + itemcount;
    items = item_2;
    itemSize = items.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        QString item;
        QString desc = items.level.at(itemcount).name;
        if(!desc.isEmpty())
        {
            item = desc;
        }
        else
        {
            item = "Out of Range";
        };
        if(longestItem.size() < item.size()) longestItem = item;
        this->comboList.append(item);
        this->comboList.append(" ");
    };

    itemTotal = itemTotal + itemcount;
    items = item_3;
    itemSize = items.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        QString item;
        QString desc = items.level.at(itemcount).name;
        if(!desc.isEmpty())
        {
            item = desc;
        }
        else
        {
            item = "Out of Range";
        };
        if(longestItem.size() < item.size()) longestItem = item;
        this->comboList.append(item);
        this->comboList.append(" ");
    };
    itemTotal = itemTotal + itemcount;
    items = item_4;
    itemSize = items.level.size();
    for(itemcount=0;itemcount<itemSize;itemcount++ )
    {
        QString item;
        QString desc = items.level.at(itemcount).name;
        if(!desc.isEmpty())
        {
            item = desc;
        }
        else
        {
            item = "Out of Range";
        };
        if(longestItem.size() < item.size()) longestItem = item;
        this->comboList.append(item);
        this->comboList.append(" ");
    };
    itemTotal = itemTotal + itemcount;

}

void customMultiComboBox::valueChanged(int index)
{
    QString valueHex = QString::number(index, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");

    SysxIO *sysxIO = SysxIO::Instance();
    bool ok;
    int maxRange = 128;
    int value = valueHex.toInt(&ok, 16);
    int dif = value/maxRange;
    QString valueHex1 = QString::number(dif, 16).toUpper();
    if(valueHex1.length() < 2) valueHex1.prepend("0");
    QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
    if(valueHex2.length() < 2) valueHex2.prepend("0");

    int hex_2 = QString(this->hex2).toInt(&ok, 16);
    int hex_3 = QString(this->hex3).toInt(&ok, 16);
    hex_3 = hex_3 + pc_index;
    if(hex_3 > 127) {hex_3 = hex_3 - 128; hex_2 = hex_2 + 1; };
    QString hex_02 = QString::number(hex_2, 16).toUpper();
    if(hex_02.length() < 2) {hex_02.prepend("0"); }
    QString hex_03 = QString::number(hex_3, 16).toUpper();
    if(hex_03.length() < 2) {hex_03.prepend("0"); }

    //sysxIO->setFileSource("System", hex1, hex_02, hex_03, valueHex1, valueHex2);

    QString patchList_01;
    QString patchList_02;
    QString patchList_03;
    QString patchList_04;
    QString patchList_05;
    QString patchList_06;
    QString patchList_07;
    QString patchList_08;
    QStringList list = comboList.split(" ");
    hex_2 = QString(this->hex2).toInt(&ok, 16);
    hex_3 = QString(this->hex3).toInt(&ok, 16);
    for(int x=1; x<129; ++x)
    {
        if(hex_3 > 127) {hex_3 = hex_3 - 128; hex_2 = hex_2 + 1; };
        QString hex_02 = QString::number(hex_2, 16).toUpper();
        if(hex_02.length() < 2) {hex_02.prepend("0"); }
        QString hex_03 = QString::number(hex_3, 16).toUpper();
        if(hex_03.length() < 2) {hex_03.prepend("0"); }
        int index = 0;//sysxIO->getSourceValue("MidiT", hex1, hex_02, hex_03);
        QString num = list.at(index);
        if(x<17)        {patchList_01.append("   "+num+"  "); };
        if(x>16 && x<33){patchList_02.append("   "+num+"  "); };
        if(x>32 && x<49){patchList_03.append("   "+num+"  "); };
        if(x>48 && x<65){patchList_04.append("   "+num+"  "); };
        if(x>64 && x<81){patchList_05.append("   "+num+"  "); };
        if(x>80 && x<97){patchList_06.append("   "+num+"  "); };
        if(x>96 && x<113){patchList_07.append("   "+num+"  "); };
        if(x>112 && x<129){patchList_08.append("   "+num+"  "); };
        hex_3 = hex_3 + 2;
    };
    display_01->display->setText(patchList_01);
    display_02->display->setText(patchList_02);
    display_03->display->setText(patchList_03);
    display_04->display->setText(patchList_04);
    display_05->display->setText(patchList_05);
    display_06->display->setText(patchList_06);
    display_07->display->setText(patchList_07);
    display_08->display->setText(patchList_08);

    emit updateSignal();
}

void customMultiComboBox::dialogUpdateSignal()
{

}

void customMultiComboBox::changedIndex(int index)
{
    pc_index = index*2;
    bool ok;
    SysxIO *sysxIO = SysxIO::Instance();
    int hex_2 = QString(this->hex2).toInt(&ok, 16);
    int hex_3 = QString(this->hex3).toInt(&ok, 16);
    hex_3 = hex_3 + pc_index;
    if(hex_3 > 127) {hex_3 = hex_3 - 128; hex_2 = hex_2 + 1; };
    QString hex_02 = QString::number(hex_2, 16).toUpper();
    if(hex_02.length() < 2) {hex_02.prepend("0"); }
    QString hex_03 = QString::number(hex_3, 16).toUpper();
    if(hex_03.length() < 2) {hex_03.prepend("0"); }
    int indice = 1;//sysxIO->getSourceValue("MidiT", hex1, hex_02, hex_03);
    display_10->controlMidiComboBox->setCurrentIndex(indice);

}




