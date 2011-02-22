/****************************************************************************
**
** Copyright (C) 2007~2011 Colin Willcocks.
** Copyright (C) 2005~2007 Uco Mesdag. 
** All rights reserved.
** This file is part of "GR-55B FloorBoard".
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

#include "customTargetListMenu.h"
#include "MidiTable.h"
#include "SysxIO.h"

customTargetListMenu::customTargetListMenu(QWidget *parent,
                                           QString hex1, QString hex2, QString hex3, QString hexMsb,
                                           QString hexLsb, QString direction)
                                               : QWidget(parent)
{
    this->controlListComboBox = new customComboBox(this);
    this->controlListComboBox->setObjectName("smallcombo");
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->hexMsb = hexMsb;
    this->hexLsb = hexLsb;
    if (!direction.contains("System")) {this->area = "Structure"; }
    else {this->area = direction; };

    MidiTable *midiTable = MidiTable::Instance();
    Midi items;
    QString hex0 = area;
    if (!area.contains("System")){
	items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);
    } else {
	hex0.remove("System");
        items = midiTable->getMidiMap("System", hex0, hex1, hex2, hex3);
    };

    setComboBox();

    if(direction == "left")
    {

    }
    else if(direction == "right")
    {

    }
    else if(direction == "top")
    {

    }
    else if(direction == "bottom")
    {
        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        mainLayout->addStretch(0);
        mainLayout->addWidget(this->controlListComboBox, 0, Qt::AlignCenter);

        this->setLayout(mainLayout);
        this->setFixedHeight(15);

    }
    else
    {
        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        mainLayout->addStretch(0);
        mainLayout->addWidget(this->controlListComboBox, 0, Qt::AlignCenter);

        this->setLayout(mainLayout);
        this->setFixedHeight(15);

    };

    //QObject::connect(this->parent(), SIGNAL( updateDisplayTarget(QString) ), this, SLOT( dialogUpdateSignal(QString) ));

    QObject::connect(this, SIGNAL( updateSignal() ), this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this->controlListComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(valueChanged(int)));

    QObject::connect(this->controlListComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(currentIndexChanged(int)));

    QObject::connect(this->parent(), SIGNAL(updateSignal()), this, SLOT(comboUpdateSignal()));

    QObject::connect(this, SIGNAL( updateTarget(QString, QString, QString) ),
                     this->parent(), SIGNAL( updateTarget(QString, QString, QString) ));
}

void customTargetListMenu::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DeBugGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

	QRectF target(0.0, 0.0, this->width(), this->height());
	QRectF source(0.0, 0.0, this->width(), this->height());

	QPainter painter(this);
	painter.drawPixmap(target, image, source);*/
}

void customTargetListMenu::setComboBox()
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;

    MidiTable *midiTable = MidiTable::Instance();
    Midi items;
    Midi item_0;
    Midi item_1;
    Midi item_2;
    Midi item_3;
    Midi item_4;
    item_0 = midiTable->getMidiMap("Tables", "00", "00", "00", "00");
    item_1 = midiTable->getMidiMap("Tables", "00", "00", "00", "01");
    item_2 = midiTable->getMidiMap("Tables", "00", "00", "00", "02");
    item_3 = midiTable->getMidiMap("Tables", "00", "00", "00", "03");
    item_4 = midiTable->getMidiMap("Tables", "00", "00", "00", "04");
    items = item_0;

    QString longestItem = "";
    int itemcount;
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
        this->controlListComboBox->addItem(item);
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
        this->controlListComboBox->addItem(item);
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
        this->controlListComboBox->addItem(item);
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
        this->controlListComboBox->addItem(item);
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
        this->controlListComboBox->addItem(item);
    };

    itemTotal = itemTotal + itemcount;
    this->controlListComboBox->setFixedWidth(200);
    this->controlListComboBox->setFixedHeight(17);
    this->controlListComboBox->setEditable(false);
    this->controlListComboBox->setFrame(false);
    this->controlListComboBox->setMaxVisibleItems(itemTotal);
}

void customTargetListMenu::valueChanged(int index)
{
    QString valueHex = QString::number(index, 16).toUpper();
    if(valueHex.length() < 3) { valueHex.prepend("00"); }
    else if(valueHex.length() < 2) { valueHex.prepend("0"); };
    QList<QString> valueString;
    QString lsb = valueHex.at(0);
    lsb.prepend("0");
    valueString.append(lsb);
    lsb = valueHex.at(1);
    lsb.prepend("0");
    valueString.append(lsb);
    lsb = valueHex.at(2);
    lsb.prepend("0");
    valueString.append(lsb);

    SysxIO *sysxIO = SysxIO::Instance();
    sysxIO->setFileSource(this->area, hex1, hex2, hex3, valueString);

    bool ok;
    QString hex3_msb = QString::number((hex3.toInt(&ok, 16) + 1), 16).toUpper();                // go forward 1 to select target MSB address
    if(hex3_msb.length() < 2) hex3_msb.prepend("0");                                            // prepend with "0" if single digit.

    QString hex3_lsb = QString::number((hex3.toInt(&ok, 16) + 2), 16).toUpper();                // go forward 2 to select target LSB address
    if(hex3_lsb.length() < 2) hex3_lsb.prepend("0");                                            // prepend with "0" if single digit.

    int value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3);        // read target value as integer from sysx.
    valueHex = QString::number(value, 16).toUpper();                                            // convert to hex qstring.
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, hex3_msb);              // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, hex3_lsb);              // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    //emit updateDisplay(valueStr);
    MidiTable *midiTable = MidiTable::Instance();

    QString valueStr = midiTable->getValue("Structure", hex1, hex2, hex3, valueHex);            // lookup the target values
    //bool ok;
    int maxRange = QString("7F").toInt(&ok, 16) + 1;
    value = valueHex.toInt(&ok, 16);
    int dif = value/maxRange;
    QString valueHex1 = QString::number(dif, 16).toUpper();
    if(valueHex1.length() < 2) valueHex1.prepend("0");
    QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
    if(valueHex2.length() < 2) valueHex2.prepend("0");
    QString hex4 = valueHex1;
    QString hex5 = valueHex2;
    //convert valueStr to 7-bit hex4, hex5
    Midi items = midiTable->getMidiMap("Tables", "00", "00", "00", hex4, hex5);
    this->hexMsb = items.desc;
    this->hexLsb = items.customdesc;

    emit updateTarget(hexMsb, hex2, hexLsb);                                                    // hexMsb & hexLsb are lookup address for label value
    emit updateTarget(hexMsb, hex2, hexLsb);
    //emit updateSignal();

}

void customTargetListMenu::dialogUpdateSignal(QString valueStr)
{
    bool ok;
    //SysxIO *sysxIO = SysxIO::Instance();
    int index = valueStr.toInt(&ok, 16);
    //int index = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex3);
    this->controlListComboBox->setCurrentIndex(index);
    //emit updateSignal();
    this->valueChanged(index);
}

void customTargetListMenu::comboUpdateSignal()
{
    bool ok;
    SysxIO *sysxIO = SysxIO::Instance();
    QString hex3_msb = QString::number((hex3.toInt(&ok, 16) + 1), 16).toUpper();                // go forward 1 to select target MSB address
    if(hex3_msb.length() < 2) hex3_msb.prepend("0");                                            // prepend with "0" if single digit.

    QString hex3_lsb = QString::number((hex3.toInt(&ok, 16) + 2), 16).toUpper();                // go forward 2 to select target LSB address
    if(hex3_lsb.length() < 2) hex3_lsb.prepend("0");                                            // prepend with "0" if single digit.

    int value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3);        // read target value as integer from sysx.
    QString valueHex = QString::number(value, 16).toUpper();                                            // convert to hex qstring.
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, hex3_msb);              // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, hex3_lsb);              // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());

    int index = valueHex.toInt(&ok, 16);
    //int index = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex3);
    this->controlListComboBox->setCurrentIndex(index);


}

