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

#include "customControlTarget.h"
#include "MidiTable.h"
#include "SysxIO.h"

customControlTarget::customControlTarget(QWidget *parent,
                                         QString hex1, QString hex2, QString hex3,
                                         QString background, QString direction, int lenght)
                                             : QWidget(parent)
{

    this->displayCombo = new customTargetListMenu(this, hex1, hex2, hex3, hexMsb, hexLsb);
    this->displayMin = new QLineEdit(this);
    this->displayMax = new QLineEdit(this);
    this->label = new customControlLabel(this);
    this->labelMin = new customControlLabel(this);
    this->labelMax = new customControlLabel(this);
    this->hex1 = hex1;
    this->hex2 = hex2;
    this->hex3 = hex3;
    this->hex4 = hex4;
    this->hex5 = hex5;
    this->hexMsb = hexMsb;
    this->hexLsb = hexLsb;
    this->hexTarget = hexTarget;
    this->hexTemp1 = hexTemp1;
    this->hexTemp2 = hexTemp2;

    bool ok;
    this->hexMin = QString::number((hex3.toInt(&ok, 16) + 3), 16).toUpper();             // go forward 3 to select target Min address
    if(this->hexMin.length() < 2) this->hexMin.prepend("0");                             // prepend with "0" if single digit.

    this->hexMax = QString::number((hex3.toInt(&ok, 16) + 6), 16).toUpper();             // go forward 6 to select target Max address
    if(this->hexMax.length() < 2){ this->hexMax.prepend("0"); };                         // prepend with "0" if single digit.

    this->hex3_msb = QString::number((hex3.toInt(&ok, 16) + 1), 16).toUpper();           // go forward 1 to select target MSB address
    if(this->hex3_msb.length() < 2) this->hex3_msb.prepend("0");                         // prepend with "0" if single digit.

    this->hex3_lsb = QString::number((hex3.toInt(&ok, 16) + 2), 16).toUpper();           // go forward 2 to select target LSB address
    if(this->hex3_lsb.length() < 2) this->hex3_lsb.prepend("0");                         // prepend with "0" if single digit.
    

    SysxIO *sysxIO = SysxIO::Instance();
    int value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3);        // read target value as integer from sysx.
    QString valueHex = QString::number(value, 16).toUpper();                                    // convert to hex qstring.
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3_msb);        // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3_lsb);        // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());


    MidiTable *midiTable = MidiTable::Instance();
    QString valueStr = midiTable->getValue("Tables", "00", "00", "00", valueHex);               // lookup the target values

    int maxRange = 256;
    value = valueStr.toInt(&ok, 16);
    int dif = value/maxRange;
    QString valueHex1 = QString::number(dif, 16).toUpper();
    if(valueHex1.length() < 2) valueHex1.prepend("0");
    QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
    if(valueHex2.length() < 2) valueHex2.prepend("0");
    this->hex4 = valueHex1;
    this->hex5 = valueHex2;                                                                     //convert valueStr to 7bit hex4, hex5
    Midi items = midiTable->getMidiMap("Tables", "00", "00", "00", hex4, hex5);
    this->hexMsb = items.desc;
    this->hexLsb = items.customdesc;

    this->knobTarget = new customKnobTarget(this, hex1, hex2, hex3, hexMsb, hexLsb, "target");  // create knob with target address

    this->label->setText("TARGET");
    this->label->setAlignment(Qt::AlignCenter);

    this->knobMin = new customKnobTarget(this, hex1, hex2, hexMin, hexMsb, hexLsb, "min");      // create knob with target address
    this->displayMin->setObjectName("editdisplay");
    this->displayMin->setFixedWidth(lenght);
    this->displayMin->setFixedHeight(15);
    this->displayMin->setAlignment(Qt::AlignCenter);
    this->displayMin->setDisabled(true);
    this->labelMin->setText("MINIMUM");
    this->labelMin->setAlignment(Qt::AlignCenter);

    this->knobMax = new customKnobTarget(this, hex1, hex2, hexMax, hexMsb, hexLsb, "max");      // create knob with target address
    this->displayMax->setObjectName("editdisplay");
    this->displayMax->setFixedWidth(lenght);
    this->displayMax->setFixedHeight(15);
    this->displayMax->setAlignment(Qt::AlignCenter);
    this->displayMax->setDisabled(true);
    this->labelMax->setText("MAXIMUM");
    this->labelMax->setAlignment(Qt::AlignCenter);

    QVBoxLayout *targetLayout = new QVBoxLayout;
    targetLayout->setMargin(0);
    targetLayout->setSpacing(0);
    targetLayout->addWidget(this->label, 0, Qt::AlignCenter);
    targetLayout->addWidget(this->knobTarget, 0, Qt::AlignCenter);
    targetLayout->addWidget(this->displayCombo, 0, Qt::AlignCenter);
    targetLayout->addStretch(0);

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
    mainLayout->addLayout(targetLayout);
    mainLayout->addLayout(minLayout);
    mainLayout->addLayout(maxLayout);
    mainLayout->addStretch(0);

    this->setLayout(mainLayout);
    this->setFixedHeight(this->knobTarget->height() + 13 + 12);
    this->setFixedHeight(this->knobMin->height() + 13 + 12);
    this->setFixedHeight(this->knobMax->height() + 13 + 12);

    QObject::connect(this->parent(), SIGNAL( dialogUpdateSignal() ),
                     this, SLOT( dialogUpdateSignal() ));

    QObject::connect(this, SIGNAL( updateSignal() ),
                     this->parent(), SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplayTarget(QString) ),
                     this, SIGNAL( updateSignal() ));

    QObject::connect(this, SIGNAL( updateDisplayMin(QString) ),
                     this->displayMin, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateDisplayMax(QString) ),
                     this->displayMax, SLOT( setText(QString) ));

    QObject::connect(this, SIGNAL( updateTarget(QString, QString, QString) ),
                     this, SLOT( knobSignal(QString, QString, QString) ));

    QObject::connect(this, SIGNAL( updateTarget(QString, QString, QString) ),
                     this, SIGNAL( updateHex(QString, QString, QString) ));

};

void customControlTarget::paintEvent(QPaintEvent *)
{
    /*DRAWS RED BACKGROUND FOR DEBUGGING PURPOSE */
    /*QPixmap image(":images/dragbar.png");

        QRectF target(0.0, 0.0, this->width(), this->height());
        QRectF source(0.0, 0.0, this->width(), this->height());

        QPainter painter(this);
        painter.drawPixmap(target, image, source);*/
};

void customControlTarget::knobSignal(QString hexMsb, QString hex2, QString hexLsb)
{
    SysxIO *sysxIO = SysxIO::Instance();
    int value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3);        // read target value as integer from sysx.
    QString valueHex = QString::number(value, 16).toUpper();                                    // convert to hex qstring.
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3_msb);        // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3_lsb);        // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    bool ok;
    value = valueHex.toInt(&ok, 16);
    this->knobTarget->setValue(value);                                                          // set the target knob position..

    this->hexMsb = hexMsb;
    this->hexLsb = hexLsb;
    value = 0;
    this->knobMin->setValue(value);                                                             // sets knob initial position
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    MidiTable *midiTable = MidiTable::Instance();
    QString valueStr = midiTable->getValue("Structure", hexMsb, hex2, hexLsb, valueHex);
    emit updateDisplayMin(valueStr);                                                            // initial value only is displayed under knob
    ////////////////////////////////////
    value = midiTable->getRange("Structure", hexMsb, hex2, hexLsb);
    this->knobMax->setValue(value);                                                             // sets knob initial position
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    valueStr = midiTable->getValue("Structure", hexMsb, hex2, hexLsb, valueHex);
    emit updateDisplayMax(valueStr);                                                            // initial value only is displayed under knob
};

void customControlTarget::dialogUpdateSignal()
{

    SysxIO *sysxIO = SysxIO::Instance();
    QString area;
    int value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3);      // read target value as integer from sysx.
    QString valueHex = QString::number(value, 16).toUpper();                                  // convert to hex qstring.
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3_msb);      // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    value = sysxIO->getSourceValue("Structure", this->hex1, this->hex2, this->hex3_lsb);      // read target value as integer from sysx.
    valueHex.append(QString::number(value, 16).toUpper());
    bool ok;
    value = valueHex.toInt(&ok, 16);
    this->knobTarget->setValue(value);                                                        // initial value only is displayed under knob
    if(valueHex.length() < 2) { valueHex.prepend("00"); }
    else if(valueHex.length() < 3) { valueHex.prepend("0"); };

    MidiTable *midiTable = MidiTable::Instance();
    QString valueStr = midiTable->getValue("Structure", hex1, hex2, hex3, valueHex);          // lookup the target values
    emit updateDisplayTarget(valueStr);
    int maxRange = 256;
    value = valueHex.toInt(&ok, 16);
    int dif = value/maxRange;
    QString valueHex1 = QString::number(dif, 16).toUpper();
    if(valueHex1.length() < 2) valueHex1.prepend("0");
    QString valueHex2 = QString::number(value - (dif * maxRange), 16).toUpper();
    if(valueHex2.length() < 2) valueHex2.prepend("0");
    this->hex4 = valueHex1;
    this->hex5 = valueHex2;                                                                   //convert valueStr to 7bit hex4, hex5
    Midi items = midiTable->getMidiMap("Tables", "00", "00", "00", hex4, hex5);
    this->hexMsb = items.desc;
    this->hexLsb = items.customdesc;
    emit updateHex(hexMsb, hex2, hexLsb);

    //////////////////////////
    value = sysxIO->getSourceValue(area, this->hex1, this->hex2, this->hexMin);
    this->knobMin->setValue(value);                                                        // sets knob initial position
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    valueStr = midiTable->getValue("Structure", hexMsb, hex2, hexLsb, valueHex);
    emit updateDisplayMin(valueStr);                                                       // initial value only is displayed under knob
    ////////////////////////////////////
    value = sysxIO->getSourceValue(area, this->hex1, this->hex2, this->hexMax);
    this->knobMax->setValue(value);                                                        // sets knob initial position
    valueHex = QString::number(value, 16).toUpper();
    if(valueHex.length() < 2) valueHex.prepend("0");
    valueStr = midiTable->getValue("Structure", hexMsb, hex2, hexLsb, valueHex);           // initial value only is displayed under knob
    emit updateDisplayMax(valueStr);       

};

