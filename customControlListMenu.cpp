/****************************************************************************
**
** Copyright (C) 2007~2012 Colin Willcocks.
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

#include "customControlListMenu.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlListMenu::customControlListMenu(QWidget *parent,
                                             QString hex1, QString hex2, QString hex3, QString direction)
                                                 : QWidget(parent)
{
    this->direction = direction;
    this->label = new customControlLabel(this);
    this->controlListComboBox = new customComboBox(this);

    if(direction.contains("Tables") || direction.contains("large"))
    {
        this->controlListComboBox->setObjectName("largecombo");
    }
    else
    {
        this->controlListComboBox->setObjectName("smallcombo");
    };
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    if (direction.contains("System")) {this->area = "System"; }
    else if (direction.contains("Tables")) {this->area = "Tables"; }
    else {this->area = "Structure"; };

    MidiTable *midiTable = MidiTable::Instance();
    Midi items;

    items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);

    QString labeltxt = items.customdesc;

    this->label->setUpperCase(true);
    this->label->setText(labeltxt);

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
        this->label->setAlignment(Qt::AlignLeft);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        mainLayout->addStretch(0);
        mainLayout->addWidget(this->label, 0, Qt::AlignLeft);
        mainLayout->addWidget(this->controlListComboBox, 0, Qt::AlignLeft);

        this->setLayout(mainLayout);
    }
    else
    {
        this->label->setAlignment(Qt::AlignCenter);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->setMargin(0);
        mainLayout->setSpacing(0);
        mainLayout->addStretch(0);
        mainLayout->addWidget(this->label, 0, Qt::AlignCenter);
        mainLayout->addWidget(this->controlListComboBox, 0, Qt::AlignCenter);

        this->setLayout(mainLayout);
    };
    if(midiTable->isData(this->area, hex1, hex2, hex3))
        { 
          this->setFixedHeight(12 + 20);
        } 
      else if(direction.contains("Tables") || direction.contains("large"))
        { 
          this->setFixedHeight(12 + 25); 
        }
      else
        { 
          this->setFixedHeight(12 + 16); 
        };


    QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ), this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this, SIGNAL( updateSignal() ), this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this->controlListComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(valueChanged(int)));

    QObject::connect(this->controlListComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(currentIndexChanged(int)));

    //QObject::connect(this->controlListComboBox, SIGNAL(highlighted(int)), this, SLOT(valueChanged(int)));

    //QObject::connect(this->controlListComboBox, SIGNAL(highlighted(int)), this, SIGNAL(currentIndexChanged(int)));

    if(this->direction.contains("Tables"))
    {
        QObject::connect(this->controlListComboBox, SIGNAL(activated(int)), this->parent(), SLOT(select_patch()));
    };
}

void customControlListMenu::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DeBugGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

        QRectF target(0.0, 0.0, this->width(), this->height());
        QRectF source(0.0, 0.0, this->width(), this->height());

        QPainter painter(this);
        painter.drawPixmap(target, image, source);*/
}

void customControlListMenu::setComboBox()
{
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    QString longestItem = "";
    int itemcount;
    MidiTable *midiTable = MidiTable::Instance();
    if(midiTable->isData(this->area, hex1, hex2, hex3))
    {
        // QApplication::beep();
        MidiTable *midiTable = MidiTable::Instance();
        Midi items;
        Midi item_0;
        Midi item_1;
        Midi item_2;
        Midi item_3;
        Midi item_4;
        Midi item_5;
        Midi item_6;
        Midi item_7;
        item_0 = midiTable->getMidiMap("Structure", "20", "00", "01", "00");
        item_1 = midiTable->getMidiMap("Structure", "20", "00", "01", "01");
        item_2 = midiTable->getMidiMap("Structure", "20", "00", "01", "02");
        item_3 = midiTable->getMidiMap("Structure", "20", "00", "01", "03");
        item_4 = midiTable->getMidiMap("Structure", "20", "00", "01", "04");
        item_5 = midiTable->getMidiMap("Structure", "20", "00", "01", "05");
        item_6 = midiTable->getMidiMap("Structure", "20", "00", "01", "06");
        item_7 = midiTable->getMidiMap("Structure", "20", "00", "01", "07");

        items = item_0;
        int itemSize = items.level.size();
        int itemTotal = 0;
        for(itemcount=0;itemcount<itemSize;itemcount++ )
        {
            QString item;
            QString desc = items.level.at(itemcount).name;
            if(!desc.isEmpty())
            {
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
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
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
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
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
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
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
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
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
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
        items = item_5;
        itemSize = items.level.size();
        for(itemcount=0;itemcount<itemSize;itemcount++ )
        {
            QString item;
            QString desc = items.level.at(itemcount).name;
            if(!desc.isEmpty())
            {
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
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
        items = item_6;
        itemSize = items.level.size();
        for(itemcount=0;itemcount<itemSize;itemcount++ )
        {
            QString item;
            QString desc = items.level.at(itemcount).name;
            if(!desc.isEmpty())
            {
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
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
        items = item_7;
        itemSize = items.level.size();
        for(itemcount=0;itemcount<itemSize;itemcount++ )
        {
            QString item;
            QString desc = items.level.at(itemcount).name;
            if(!desc.isEmpty())
            {
                desc.prepend("[" + items.level.at(itemcount).customdesc + "]  ");
                item = desc;
            }
            else
            {
                item = "Out of Range";
            };
            if(longestItem.size() < item.size()) longestItem = item;
            this->controlListComboBox->addItem(item);
        };
        this->controlListComboBox->setFixedHeight(18);
        this->controlListComboBox->setMaxVisibleItems(910);
    }
    else
    {
        Midi items;
        items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);


        for(itemcount=0;itemcount<items.level.size();itemcount++ )
        {
            QString item;
            QString desc = items.level.at(itemcount).desc;
            QString customdesc = items.level.at(itemcount).customdesc;
            if(!customdesc.isEmpty())
            {
                item = customdesc;
            }
            else
            {
                item = desc;
            };
            if(longestItem.size() < item.size()) longestItem = item;
            this->controlListComboBox->addItem(item);
        };
        this->controlListComboBox->setFixedHeight(16);
        this->controlListComboBox->setMaxVisibleItems(itemcount);
    };
    int maxWidth = QFontMetrics( this->font() ).width( longestItem );
    if(maxWidth < 20) { maxWidth = 20; };
      if(this->direction.contains("Tables") || this->direction.contains("large"))
    {
        this->controlListComboBox->setFixedWidth(maxWidth + 70);
        this->controlListComboBox->setFixedHeight(25);
    }
    else
    {
        this->controlListComboBox->setFixedWidth(maxWidth + 25);
        this->controlListComboBox->setFixedHeight(16);
    };

    this->controlListComboBox->setEditable(false);
    this->controlListComboBox->setFrame(false);

}

void customControlListMenu::valueChanged(int index)
{
if(!this->direction.contains("Tables"))
    {
    QList<QString> hexData;
    if(index>895) {hexData.append("56"); index = index-896; } else { hexData.append("58");}
    QString valueHex = QString::number(index, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");

    SysxIO *sysxIO = SysxIO::Instance();
    MidiTable *midiTable = MidiTable::Instance();
    bool ok;
    if(midiTable->isData(this->area, hex1, hex2, hex3))
    {
        int maxRange = QString("7F").toInt(&ok, 16) + 1;
        int value = valueHex.toInt(&ok, 16);
        int dif = value/maxRange;
        QString valueHex1 = QString::number(dif, 16).toUpper();
        if(valueHex1.length() < 2) valueHex1.prepend("0");
        QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
        if(valueHex2.length() < 2) valueHex2.prepend("0");
        hexData.append(valueHex1);
        hexData.append(valueHex2);
        sysxIO->setFileSource(this->area, hex1, hex2, "00", hexData);
    }
    else
    {
        sysxIO->setFileSource(this->area, hex1, hex2, hex3, valueHex);
    };

    //emit updateDisplay(valueStr);
    emit updateSignal();
    };
}

void customControlListMenu::dialogUpdateSignal()
{
   if(!this->direction.contains("Tables"))
    {
    SysxIO *sysxIO = SysxIO::Instance();
    MidiTable *midiTable = MidiTable::Instance();
    int index = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hex3);
    if(midiTable->isData(this->area, hex1, hex2, hex3))
    {
        int pcm_check = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, "00" );
        if (pcm_check == 86) {index = index + 896; };
    };
    this->controlListComboBox->setCurrentIndex(index);
    this->valueChanged(index);
    };
}

 void customControlListMenu::set_index(int index)
{
    this->controlListComboBox->setCurrentIndex(index);
}

