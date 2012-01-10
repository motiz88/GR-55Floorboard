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

#include "customControlRange.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlRange::customControlRange(QWidget *parent,
                                       QString hex1, QString hex2, QString hex3,
                                       QString area)
                                           : QWidget(parent)
{
    this->displayMin = new QLineEdit(this);
    this->labelMin = new customControlLabel(this);
    this->displayMax = new QLineEdit(this);
    this->labelMax = new customControlLabel(this);
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->area = area;

    MidiTable *midiTable = MidiTable::Instance();
    if (this->area != "System") {this->area = "Structure";};

    Midi items = midiTable->getMidiMap(this->area, hex1, hex2, hex3);

    bool ok;
    QString hexTemp;
    this->hexMin = hex3;
    hexTemp = QString::number((hex3.toInt(&ok, 16) + 1), 16).toUpper();    // go forward 2 to select range Max address
    if(hexTemp.length() < 2) hexTemp.prepend("0");                         // prepend with "0" if single digit.
    this->hexMax = hexTemp;

    this->labelMin->setText("Act Rng LO");
    this->labelMin->setUpperCase(true);
    this->knobMin = new customKnobRange(this, this->area, hex1, hex2, this->hexMin, this->hexMax, "Min");
    this->displayMin->setObjectName("editdisplay");
    this->displayMin->setFixedWidth(45);
    this->displayMin->setFixedHeight(13);
    this->displayMin->setAlignment(Qt::AlignCenter);
    this->displayMin->setDisabled(true);


    this->labelMax->setText("Act Rng HI");
    this->labelMax->setUpperCase(true);
    this->knobMax = new customKnobRange(this, this->area, hex1, hex2, this->hexMin, this->hexMax, "Max");
    this->displayMax->setObjectName("editdisplay");
    this->displayMax->setFixedWidth(45);
    this->displayMax->setFixedHeight(13);
    this->displayMax->setAlignment(Qt::AlignCenter);
    this->displayMax->setDisabled(true);


    QVBoxLayout *minLayout = new QVBoxLayout;
    minLayout->setMargin(0);
    minLayout->setSpacing(0);
    minLayout->addWidget(this->labelMin, 0, Qt::AlignCenter);
    minLayout->addWidget(this->knobMin, 0, Qt::AlignCenter);
    minLayout->addWidget(this->displayMin, 0, Qt::AlignCenter);
    minLayout->addStretch(0);

    QVBoxLayout *maxLayout = new QVBoxLayout;
    maxLayout->setMargin(0);
    maxLayout->setSpacing(0);
    maxLayout->addWidget(this->labelMax, 0, Qt::AlignCenter);
    maxLayout->addWidget(this->knobMax, 0, Qt::AlignCenter);
    maxLayout->addWidget(this->displayMax, 0, Qt::AlignCenter);
    maxLayout->addStretch(0);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addLayout(minLayout);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(maxLayout);
    mainLayout->addStretch(0);

    this->setLayout(mainLayout);
    this->setFixedHeight(this->knobMin->height() + 13 + 12);
    this->setFixedHeight(this->knobMax->height() + 13 + 12);





    QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this, SIGNAL( updateSignal() ),
                     this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplayMin(QString) ),
                     this->displayMin, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplayMax(QString) ),
                     this->displayMax, SLOT( setText(QString) ));
};

void customControlRange::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

        QRectF target(0.0, 0.0, this->width(), this->height());
        QRectF source(0.0, 0.0, this->width(), this->height());

        QPainter painter(this);
        painter.drawPixmap(target, image, source);*/
};

void customControlRange::dialogUpdateSignal()
{
    SysxIO *sysxIO = SysxIO::Instance();
    QString valueStr;
    QString valueHex;
    int value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hexMin);
    this->knobMin->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    MidiTable *midiTable = MidiTable::Instance();
    valueStr = midiTable->getValue(this->area, hex1, hex2, this->hexMin, valueHex);
    emit updateDisplayMin(valueStr);

    value = sysxIO->getSourceValue(this->area, this->hex1, this->hex2, this->hexMax);
    this->knobMax->setValue(value);
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    valueStr = midiTable->getValue(this->area, hex1, hex2, this->hexMax, valueHex);
    emit updateDisplayMax(valueStr);
};
